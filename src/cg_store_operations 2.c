/**
 * @file cg_store_operations.c
 * @brief Store operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements the store operations for the modernized BCPL code
 * generator, handling all memory store instructions with proper type safety
 * and error checking.
 *
 * "Good code is like good prose: every statement is clear and necessary."
 *                                                     - John Lions
 *
 * Store Operations Handled:
 * - S_SP    (Store to Parameter)
 * - S_SG    (Store to Global)
 * - S_SL    (Store to Local)
 * - S_STIND (Store Indirect)
 * - S_STORE (General Store)
 * - S_PUTBYTE (Store Byte)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_store_parameter(ocode_context_t *ctx,
                                             int32_t offset);
static ocode_result_t handle_store_global(ocode_context_t *ctx,
                                          int32_t address);
static ocode_result_t handle_store_local(ocode_context_t *ctx, int32_t offset);
static ocode_result_t handle_store_indirect(ocode_context_t *ctx);
static ocode_result_t handle_general_store(ocode_context_t *ctx);
static ocode_result_t handle_put_byte(ocode_context_t *ctx);

static bool validate_store_address(const ocode_context_t *ctx, int32_t address);
static bool validate_stack_depth_for_store(const ocode_context_t *ctx,
                                           int required_depth);

// =============================================================================
// MAIN STORE OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all store operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches store operations to their specific handlers,
 * following the Lions philosophy of clear, purposeful code structure.
 */
ocode_result_t handle_store_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_store_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing store operation");
#endif

  // Prepare for store operation
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_SP:
    return handle_store_parameter(ctx, ctx->k);

  case S_SG:
    return handle_store_global(ctx, ctx->k);

  case S_SL:
    return handle_store_local(ctx, ctx->k);

  case S_STIND:
    return handle_store_indirect(ctx);

  case S_STORE:
    return handle_general_store(ctx);

  case S_PUTBYTE:
    return handle_put_byte(ctx);

  default:
    report_context_error(ctx, "Unknown store operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC STORE OPERATION HANDLERS
// =============================================================================

/**
 * @brief Store value to parameter location
 * @param ctx Code generation context
 * @param offset Parameter offset (typically negative)
 * @return Operation result
 *
 * Stores the top stack value to a parameter location. Parameters are
 * accessed with negative offsets from the parameter base pointer.
 */
static ocode_result_t handle_store_parameter(ocode_context_t *ctx,
                                             int32_t offset) {
  assert(ctx != NULL);

  // Validate we have a value to store
  if (UNLIKELY(!validate_stack_depth_for_store(ctx, 1))) {
    report_context_error(ctx, "Stack underflow in SP operation");
    return OCODE_RUNTIME_ERROR;
  }

  // Validate parameter offset (should be negative or zero)
  if (UNLIKELY(offset > 0)) {
    report_context_warning(ctx, "Unusual positive parameter offset: %d",
                           offset);
  }

#ifdef ENABLE_OPTIMIZATIONS
  // Try optimization before code generation
  if (try_peephole_optimization(ctx, S_SP)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate store to parameter instruction
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "ST\tR1, P%d\t\t; Store to parameter %d", offset, offset);
    ctx->output_handler(instruction);
  }

  // Update stack pointer (consuming one value)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Store value to global variable
 * @param ctx Code generation context
 * @param address Global variable address
 * @return Operation result
 *
 * Stores the top stack value to a global variable location.
 */
static ocode_result_t handle_store_global(ocode_context_t *ctx,
                                          int32_t address) {
  assert(ctx != NULL);

  // Validate we have a value to store
  if (UNLIKELY(!validate_stack_depth_for_store(ctx, 1))) {
    report_context_error(ctx, "Stack underflow in SG operation");
    return OCODE_RUNTIME_ERROR;
  }

  // Validate global address
  if (UNLIKELY(!validate_store_address(ctx, address))) {
    report_context_error(ctx, "Invalid global address: %d", address);
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_SG)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate store to global instruction
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "ST\tR1, G%d\t\t; Store to global %d", address, address);
    ctx->output_handler(instruction);
  }

  // Update stack pointer
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Store value to local variable
 * @param ctx Code generation context
 * @param offset Local variable offset
 * @return Operation result
 *
 * Stores the top stack value to a local variable location.
 */
static ocode_result_t handle_store_local(ocode_context_t *ctx, int32_t offset) {
  assert(ctx != NULL);

  // Validate we have a value to store
  if (UNLIKELY(!validate_stack_depth_for_store(ctx, 1))) {
    report_context_error(ctx, "Stack underflow in SL operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_SL)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate store to local instruction
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "ST\tR1, L%d\t\t; Store to local %d", offset, offset);
    ctx->output_handler(instruction);
  }

  // Update stack pointer
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Store value through pointer (indirect store)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Stores a value through a pointer. Expects stack layout:
 * TOS-1: address (pointer)
 * TOS:   value to store
 */
static ocode_result_t handle_store_indirect(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have both address and value on stack
  if (UNLIKELY(!validate_stack_depth_for_store(ctx, 2))) {
    report_context_error(ctx, "Stack underflow in STIND operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_STIND)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate indirect store instruction
  if (ctx->output_handler) {
    ctx->output_handler("ST\tR1, (R2)\t; Store indirect");
  }

  // Update stack pointer (consuming address and value)
  ctx->s -= 2;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle general store operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles the general STORE operation, which may have varying semantics
 * depending on the context.
 */
static ocode_result_t handle_general_store(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate minimum stack depth
  if (UNLIKELY(!validate_stack_depth_for_store(ctx, 1))) {
    report_context_error(ctx, "Stack underflow in STORE operation");
    return OCODE_RUNTIME_ERROR;
  }

  // The STORE operation often saves the current stack state
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "MOV\t[SP], R1\t\t; General store (stack=%d)", ctx->s);
    ctx->output_handler(instruction);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Store byte to string/array
 * @param ctx Code generation context
 * @return Operation result
 *
 * Stores a byte value to a string or byte array. Expects:
 * TOS-2: string/array address
 * TOS-1: index
 * TOS:   byte value
 */
static ocode_result_t handle_put_byte(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have address, index, and value on stack
  if (UNLIKELY(!validate_stack_depth_for_store(ctx, 3))) {
    report_context_error(ctx, "Stack underflow in PUTBYTE operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_PUTBYTE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate put byte instruction
  if (ctx->output_handler) {
    ctx->output_handler("PUTB\tR1, (R2+R3)\t; Put byte");
  }

  // Update stack pointer (consuming address, index, and value)
  ctx->s -= 3;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Validate that a store address is reasonable
 * @param ctx Code generation context
 * @param address Address to validate
 * @return true if address appears valid
 */
static bool validate_store_address(const ocode_context_t *ctx,
                                   int32_t address) {
  // Basic sanity checks for address ranges
  // These would need to be adjusted based on the target architecture
  if (address < 0 || address > 0x7FFFFFFF) {
    return false;
  }

  // Additional validation could check against known memory layout
  // For now, we accept all non-negative addresses
  return true;
}

/**
 * @brief Validate stack has sufficient depth for store operation
 * @param ctx Code generation context
 * @param required_depth Minimum required stack depth
 * @return true if stack is deep enough
 */
static bool validate_stack_depth_for_store(const ocode_context_t *ctx,
                                           int required_depth) {
  return ctx->s >= required_depth;
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a store operation
 * @param op OCODE operation to check
 * @return true if op is a store operation
 */
bool is_store_operation(ocode_op op) {
  switch (op) {
  case S_SP:
  case S_SG:
  case S_SL:
  case S_STIND:
  case S_STORE:
  case S_PUTBYTE:
    return true;
  default:
    return false;
  }
}
