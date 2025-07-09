/**
 * @file cg_function_operations.c
 * @brief Function operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements function operations for the modernized BCPL code
 * generator, handling function calls, returns, and procedure management
 * with proper calling convention adherence and stack management.
 *
 * "The function of good software is to make the complex appear to be simple."
 *                                                        - Grady Booch
 *
 * Function Operations Handled:
 * - S_FNAP    (Function Application/Call)
 * - S_RETURN  (Return from function)
 * - S_RTAP    (Return from application)
 * - S_FNRN    (Function return with value)
 * - S_RTRN    (Return instruction)
 * - S_ENTRY   (Function entry point)
 * - S_ENDPROC (End of procedure)
 * - S_RES     (Result instruction)
 * - S_RESLAB  (Result with label)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_function_application(ocode_context_t *ctx);
static ocode_result_t handle_return(ocode_context_t *ctx);
static ocode_result_t handle_return_from_application(ocode_context_t *ctx);
static ocode_result_t handle_function_return_value(ocode_context_t *ctx);
static ocode_result_t handle_return_instruction(ocode_context_t *ctx);
static ocode_result_t handle_function_entry(ocode_context_t *ctx);
static ocode_result_t handle_end_procedure(ocode_context_t *ctx);
static ocode_result_t handle_result(ocode_context_t *ctx);
static ocode_result_t handle_result_with_label(ocode_context_t *ctx);

static void emit_function_prologue(ocode_context_t *ctx);
static void emit_function_epilogue(ocode_context_t *ctx);
static void emit_function_call_internal(ocode_context_t *ctx,
                                        const char *target);
static void save_caller_context(ocode_context_t *ctx);
static void restore_caller_context(ocode_context_t *ctx);

// =============================================================================
// MAIN FUNCTION OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all function operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches function operations to their specific handlers,
 * ensuring proper calling conventions and stack management throughout
 * the function call lifecycle.
 */
ocode_result_t handle_function_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_function_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing function operation");
#endif

  // Prepare for function operation
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_FNAP:
    return handle_function_application(ctx);

  case S_RETURN:
    return handle_return(ctx);

  case S_RTAP:
    return handle_return_from_application(ctx);

  case S_FNRN:
    return handle_function_return_value(ctx);

  case S_RTRN:
    return handle_return_instruction(ctx);

  case S_ENTRY:
    return handle_function_entry(ctx);

  case S_ENDPROC:
    return handle_end_procedure(ctx);

  case S_RES:
    return handle_result(ctx);

  case S_RESLAB:
    return handle_result_with_label(ctx);

  default:
    report_context_error(ctx, "Unknown function operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC FUNCTION OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle function application (call)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements function calls with proper parameter passing and
 * calling convention adherence. Parameters are passed on the stack
 * in reverse order (last parameter pushed first).
 */
static ocode_result_t handle_function_application(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have at least a function address on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in FNAP operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_FNAP)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Save caller context
  save_caller_context(ctx);

  // Generate function call
  if (ctx->output_handler) {
    char instruction[512];
    snprintf(instruction, sizeof(instruction),
             "BL\tR1\t\t; Call function at address in R1\n"
             "; Function call with %d parameters",
             ctx->k);
    ctx->output_handler(instruction);
  }

  // Update stack pointer (function address consumed, result may be returned)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 3; // Including context save/restore
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle function return
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles normal function return without an explicit return value.
 */
static ocode_result_t handle_return(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_RETURN)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate function return
  emit_function_epilogue(ctx);

  if (ctx->output_handler) {
    ctx->output_handler("BX\tLR\t\t; Return to caller");
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2; // Including epilogue
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle return from function application
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles return from a function application, restoring caller context.
 */
static ocode_result_t handle_return_from_application(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Restore caller context
  restore_caller_context(ctx);

  if (ctx->output_handler) {
    ctx->output_handler("BX\tLR\t\t; Return from application");
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle function return with value
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles function return with an explicit return value on the stack.
 */
static ocode_result_t handle_function_return_value(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a return value on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in FNRN operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_FNRN)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Move return value to result register
  if (ctx->output_handler) {
    ctx->output_handler(
        "MOV\tR0, R1\t\t; Move return value to result register");
  }

  // Generate function epilogue and return
  emit_function_epilogue(ctx);

  if (ctx->output_handler) {
    ctx->output_handler("BX\tLR\t\t; Return with value");
  }

  // Update stack pointer (consuming return value)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 3;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle return instruction
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles generic return instruction.
 */
static ocode_result_t handle_return_instruction(ocode_context_t *ctx) {
  assert(ctx != NULL);

  emit_function_epilogue(ctx);

  if (ctx->output_handler) {
    ctx->output_handler("BX\tLR\t\t; Return instruction");
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle function entry point
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles function entry, setting up the stack frame and preserving
 * caller registers as needed.
 */
static ocode_result_t handle_function_entry(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Generate function prologue
  emit_function_prologue(ctx);

  // Initialize function-specific context
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "; Function entry: %d local variables", ctx->k);
    ctx->output_handler(instruction);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 3; // Prologue instructions
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle end of procedure
 * @param ctx Code generation context
 * @return Operation result
 *
 * Marks the end of a procedure definition.
 */
static ocode_result_t handle_end_procedure(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    ctx->output_handler("; End of procedure");
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle result instruction
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles result computation and storage.
 */
static ocode_result_t handle_result(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a result value on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in RES operation");
    return OCODE_RUNTIME_ERROR;
  }

  if (ctx->output_handler) {
    ctx->output_handler("MOV\tR0, R1\t\t; Store result");
  }

  // Result remains on stack for potential further use

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle result with label
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles result computation with associated label.
 */
static ocode_result_t handle_result_with_label(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a result value on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in RESLAB operation");
    return OCODE_RUNTIME_ERROR;
  }

  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "MOV\tR0, R1\t\t; Store result with label L%d", ctx->k);
    ctx->output_handler(instruction);
  }

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
 * @brief Emit function prologue
 * @param ctx Code generation context
 *
 * Generates the standard function entry sequence, saving registers
 * and setting up the stack frame.
 */
static void emit_function_prologue(ocode_context_t *ctx) {
  if (ctx->output_handler) {
    ctx->output_handler("PUSH\t{R4-R11, LR}\t; Save caller registers\n"
                        "MOV\tR11, SP\t\t; Set up frame pointer");
  }
}

/**
 * @brief Emit function epilogue
 * @param ctx Code generation context
 *
 * Generates the standard function exit sequence, restoring registers
 * and cleaning up the stack frame.
 */
static void emit_function_epilogue(ocode_context_t *ctx) {
  if (ctx->output_handler) {
    ctx->output_handler("MOV\tSP, R11\t\t; Restore stack pointer\n"
                        "POP\t{R4-R11, LR}\t; Restore caller registers");
  }
}

/**
 * @brief Emit function call sequence
 * @param ctx Code generation context
 * @param target Call target (function name or address)
 */
static void emit_function_call_internal(ocode_context_t *ctx,
                                        const char *target) {
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction), "BL\t%s\t\t; Call function",
             target);
    ctx->output_handler(instruction);
  }
}

/**
 * @brief Save caller context before function call
 * @param ctx Code generation context
 */
static void save_caller_context(ocode_context_t *ctx) {
  if (ctx->output_handler) {
    ctx->output_handler("PUSH\t{R1-R3}\t\t; Save caller context");
  }
}

/**
 * @brief Restore caller context after function call
 * @param ctx Code generation context
 */
static void restore_caller_context(ocode_context_t *ctx) {
  if (ctx->output_handler) {
    ctx->output_handler("POP\t{R1-R3}\t\t; Restore caller context");
  }
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a function operation
 * @param op OCODE operation to check
 * @return true if op is a function operation
 */
bool is_function_operation(ocode_op op) {
  switch (op) {
  case S_FNAP:
  case S_RETURN:
  case S_RTAP:
  case S_FNRN:
  case S_RTRN:
  case S_ENTRY:
  case S_ENDPROC:
  case S_RES:
  case S_RESLAB:
    return true;
  default:
    return false;
  }
}
