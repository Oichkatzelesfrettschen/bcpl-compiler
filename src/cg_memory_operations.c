/**
 * @file cg_memory_operations.c
 * @brief Memory operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements memory operations for the modernized BCPL code
 * generator, handling stack management, data access, and memory allocation
 * with proper bounds checking and optimization opportunities.
 *
 * "The stack is the heart of computation; manage it with care and precision."
 *                                                        - John Lions
 *
 * Memory Operations Handled:
 * - S_RV      (Right-hand Value/Dereference)
 * - S_STACK   (Stack operation)
 * - S_RSTACK  (Restore stack)
 * - S_SAVE    (Save context)
 * - S_GETBYTE (Get byte from memory)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_right_value(ocode_context_t *ctx);
static ocode_result_t handle_stack_operation(ocode_context_t *ctx);
static ocode_result_t handle_restore_stack(ocode_context_t *ctx);
static ocode_result_t handle_save_context(ocode_context_t *ctx);
static ocode_result_t handle_get_byte(ocode_context_t *ctx);

static bool validate_memory_address(const ocode_context_t *ctx,
                                    int32_t address);
static void emit_memory_access_check(ocode_context_t *ctx,
                                     const char *operation);
static bool can_optimize_stack_operation(const ocode_context_t *ctx);

// =============================================================================
// MAIN MEMORY OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all memory operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches memory operations to their specific handlers,
 * ensuring proper memory safety and providing optimization opportunities
 * for stack and memory access patterns.
 */
ocode_result_t handle_memory_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_memory_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing memory operation");
#endif

  // Prepare for memory operation
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_RV:
    return handle_right_value(ctx);

  case S_STACK:
    return handle_stack_operation(ctx);

  case S_RSTACK:
    return handle_restore_stack(ctx);

  case S_SAVE:
    return handle_save_context(ctx);

  case S_GETBYTE:
    return handle_get_byte(ctx);

  default:
    report_context_error(ctx, "Unknown memory operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC MEMORY OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle right-hand value (dereference)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements pointer dereference operation, loading the value pointed to
 * by the address on top of the stack.
 */
static ocode_result_t handle_right_value(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have an address on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in RV operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_RV)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

// Generate memory bounds check if enabled
#ifdef ENABLE_MEMORY_SAFETY
  emit_memory_access_check(ctx, "load");
#endif

  // Generate dereference instruction
  if (ctx->output_handler) {
    ctx->output_handler("LDR\tR1, [R1]\t\t; Dereference pointer");
  }

  // Stack pointer unchanged (address in, value out)

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#ifdef ENABLE_MEMORY_SAFETY
  ctx->performance.instructions_emitted += 2; // Additional bounds check
#endif
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle stack operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Performs stack manipulation operations, typically adjusting the
 * stack pointer by the specified amount.
 */
static ocode_result_t handle_stack_operation(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_stack_operation(ctx)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_STACK)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate stack adjustment
  if (ctx->output_handler) {
    char instruction[256];
    if (ctx->k > 0) {
      snprintf(instruction, sizeof(instruction),
               "ADD\tSP, SP, #%d\t; Allocate %d words on stack", ctx->k * 4,
               ctx->k);
    } else if (ctx->k < 0) {
      snprintf(instruction, sizeof(instruction),
               "SUB\tSP, SP, #%d\t; Deallocate %d words from stack",
               -ctx->k * 4, -ctx->k);
    } else {
      snprintf(instruction, sizeof(instruction),
               "NOP\t\t\t; Stack operation with zero adjustment");
    }
    ctx->output_handler(instruction);
  }

  // Update logical stack pointer
  ctx->s += ctx->k;

  // Validate stack doesn't underflow
  if (UNLIKELY(ctx->s < 0)) {
    report_context_warning(ctx,
                           "Stack underflow detected after STACK operation");
    ctx->s = 0;
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  if (ctx->k != 0) {
    ctx->performance.instructions_emitted++;
  }
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle restore stack operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Restores the stack pointer to a previously saved state.
 */
static ocode_result_t handle_restore_stack(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_RSTACK)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate stack restore
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "MOV\tSP, R%d\t\t; Restore stack pointer", ctx->k);
    ctx->output_handler(instruction);
  }

  // Reset logical stack pointer (exact value depends on context)
  // For safety, we assume worst case
  ctx->s = 0;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle save context operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Saves the current execution context, typically for later restoration.
 */
static ocode_result_t handle_save_context(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_SAVE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate context save
  if (ctx->output_handler) {
    char instruction[512];
    snprintf(instruction, sizeof(instruction),
             "PUSH\t{R1-R12, LR}\t; Save execution context\n"
             "MOV\tR%d, SP\t\t; Save stack pointer in R%d",
             ctx->k, ctx->k);
    ctx->output_handler(instruction);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle get byte operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Retrieves a byte from memory using address and index on the stack.
 * Stack layout: TOS-1: address, TOS: index
 */
static ocode_result_t handle_get_byte(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have address and index on stack
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in GETBYTE operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_GETBYTE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

// Generate memory bounds check if enabled
#ifdef ENABLE_MEMORY_SAFETY
  emit_memory_access_check(ctx, "byte load");
#endif

  // Generate get byte instruction
  if (ctx->output_handler) {
    ctx->output_handler("LDRB\tR1, [R2, R1]\t; Get byte from address+index");
  }

  // Update stack pointer (consume address and index, produce byte value)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#ifdef ENABLE_MEMORY_SAFETY
  ctx->performance.instructions_emitted += 2; // Additional bounds check
#endif
#endif

  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Validate memory address for safety
 * @param ctx Code generation context
 * @param address Memory address to validate
 * @return true if address appears valid
 */
static bool validate_memory_address(const ocode_context_t *ctx,
                                    int32_t address) {
  // Basic validation - in a real implementation, this would check
  // against known memory segments and permissions
  if (address < 0) {
    return false;
  }

  // Check against maximum addressable memory (simplified)
  if (address > 0x7FFFFFFF) {
    return false;
  }

  return true;
}

/**
 * @brief Emit memory access bounds checking code
 * @param ctx Code generation context
 * @param operation Description of the memory operation
 */
static void emit_memory_access_check(ocode_context_t *ctx,
                                     const char *operation) {
#ifdef ENABLE_MEMORY_SAFETY
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "CMP\tR1, #0x80000000\t; Check address bounds for %s\n"
             "BHS\tmemory_fault\t; Jump to fault handler if out of bounds",
             operation);
    ctx->output_handler(instruction);
  }
#endif
}

/**
 * @brief Check if stack operation can be optimized
 * @param ctx Code generation context
 * @return true if optimization was applied
 */
static bool can_optimize_stack_operation(const ocode_context_t *ctx) {
  // Check for redundant stack operations (e.g., +n followed by -n)
  // This would require looking at the previous operation

  // Check for zero stack adjustment
  if (ctx->k == 0) {
    return true; // No operation needed
  }

  return false;
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a memory operation
 * @param op OCODE operation to check
 * @return true if op is a memory operation
 */
bool is_memory_operation(ocode_op op) {
  switch (op) {
  case S_RV:
  case S_STACK:
  case S_RSTACK:
  case S_SAVE:
  case S_GETBYTE:
    return true;
  default:
    return false;
  }
}
