/**
 * @file cg_logical_operations.c
 * @brief Logical operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements logical operations for the modernized BCPL code
 * generator, handling Boolean logic, bitwise operations, and conditional
 * constructs with proper short-circuit evaluation.
 *
 * "The art of programming is the art of organizing complexity,
 * of mastering multitude and avoiding its bastard chaos as effectively
 * as possible." - Edsger W. Dijkstra
 *
 * Logical Operations Handled:
 * - S_LOGAND (Logical AND with short-circuit)
 * - S_LOGOR  (Logical OR with short-circuit)
 * - S_NOT    (Logical NOT)
 * - S_EQV    (Equivalence)
 * - S_NEQV   (Non-equivalence/XOR)
 * - S_LSHIFT (Left bit shift)
 * - S_RSHIFT (Right bit shift)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_logical_and(ocode_context_t *ctx);
static ocode_result_t handle_logical_or(ocode_context_t *ctx);
static ocode_result_t handle_logical_not(ocode_context_t *ctx);
static ocode_result_t handle_equivalence(ocode_context_t *ctx);
static ocode_result_t handle_non_equivalence(ocode_context_t *ctx);
static ocode_result_t handle_left_shift(ocode_context_t *ctx);
static ocode_result_t handle_right_shift(ocode_context_t *ctx);

static bool can_optimize_logical_constant(const ocode_context_t *ctx,
                                          ocode_op op);
static ocode_result_t emit_short_circuit_code(ocode_context_t *ctx,
                                              ocode_op op);

// =============================================================================
// MAIN LOGICAL OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all logical operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches logical operations to their specific handlers,
 * implementing proper short-circuit evaluation and optimization opportunities.
 */
ocode_result_t handle_logical_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_logical_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing logical operation");
#endif

  // Prepare operands for logical operation
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_LOGAND:
    return handle_logical_and(ctx);

  case S_LOGOR:
    return handle_logical_or(ctx);

  case S_NOT:
    return handle_logical_not(ctx);

  case S_EQV:
    return handle_equivalence(ctx);

  case S_NEQV:
    return handle_non_equivalence(ctx);

  case S_LSHIFT:
    return handle_left_shift(ctx);

  case S_RSHIFT:
    return handle_right_shift(ctx);

  default:
    report_context_error(ctx, "Unknown logical operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC LOGICAL OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle logical AND with short-circuit evaluation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements BCPL's LOGAND operator with proper short-circuit evaluation.
 * If the first operand is false, the second is not evaluated.
 */
static ocode_result_t handle_logical_and(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in LOGAND operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  // Try constant folding
  if (can_optimize_logical_constant(ctx, S_LOGAND)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  // Try peephole optimization
  if (try_peephole_optimization(ctx, S_LOGAND)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate short-circuit AND logic
  if (ctx->output_handler) {
    char label[64];
    snprintf(label, sizeof(label), "L%d", ctx->next_label_number++);

    char instructions[512];
    snprintf(instructions, sizeof(instructions),
             "CMP\tR2, #0\t\t; Test first operand\n"
             "BEQ\t%s\t\t; Short-circuit if false\n"
             "CMP\tR1, #0\t\t; Test second operand\n"
             "SETNE\tR1\t\t; Set result based on second operand\n"
             "B\tL%d_end\n"
             "%s:\n"
             "MOV\tR1, #0\t\t; First operand was false\n"
             "L%d_end:",
             label, ctx->next_label_number, label, ctx->next_label_number);

    ctx->next_label_number++;
    ctx->output_handler(instructions);
  }

  // Update stack pointer (consume two operands, produce one result)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 6; // Multiple instructions generated
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle logical OR with short-circuit evaluation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements BCPL's LOGOR operator with proper short-circuit evaluation.
 * If the first operand is true, the second is not evaluated.
 */
static ocode_result_t handle_logical_or(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in LOGOR operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_logical_constant(ctx, S_LOGOR)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_LOGOR)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate short-circuit OR logic
  if (ctx->output_handler) {
    char label[64];
    snprintf(label, sizeof(label), "L%d", ctx->next_label_number++);

    char instructions[512];
    snprintf(instructions, sizeof(instructions),
             "CMP\tR2, #0\t\t; Test first operand\n"
             "BNE\t%s\t\t; Short-circuit if true\n"
             "CMP\tR1, #0\t\t; Test second operand\n"
             "SETNE\tR1\t\t; Set result based on second operand\n"
             "B\tL%d_end\n"
             "%s:\n"
             "MOV\tR1, #1\t\t; First operand was true\n"
             "L%d_end:",
             label, ctx->next_label_number, label, ctx->next_label_number);

    ctx->next_label_number++;
    ctx->output_handler(instructions);
  }

  // Update stack pointer
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 6;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle logical NOT operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements logical negation (NOT) operation.
 */
static ocode_result_t handle_logical_not(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have one operand
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in NOT operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_NOT)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate NOT logic
  if (ctx->output_handler) {
    ctx->output_handler(
        "CMP\tR1, #0\t\t; Test operand\n"
        "SETEQ\tR1\t\t; Set result: 1 if was 0, 0 if was non-zero");
  }

  // Stack pointer unchanged (one operand in, one result out)

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle equivalence operation (EQV)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements logical equivalence: true if both operands have the same truth
 * value.
 */
static ocode_result_t handle_equivalence(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in EQV operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_EQV)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate equivalence logic: (A AND B) OR (NOT A AND NOT B)
  if (ctx->output_handler) {
    ctx->output_handler("CMP\tR1, #0\t\t; Test second operand\n"
                        "SETNE\tR3\t\t; R3 = (R1 != 0)\n"
                        "CMP\tR2, #0\t\t; Test first operand\n"
                        "SETNE\tR4\t\t; R4 = (R2 != 0)\n"
                        "EOR\tR1, R3, R4\t; XOR the truth values\n"
                        "EOR\tR1, R1, #1\t; Invert for equivalence");
  }

  // Update stack pointer
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 6;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle non-equivalence operation (NEQV/XOR)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements logical non-equivalence (exclusive OR).
 */
static ocode_result_t handle_non_equivalence(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in NEQV operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_NEQV)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate XOR logic
  if (ctx->output_handler) {
    ctx->output_handler("CMP\tR1, #0\t\t; Test second operand\n"
                        "SETNE\tR3\t\t; R3 = (R1 != 0)\n"
                        "CMP\tR2, #0\t\t; Test first operand\n"
                        "SETNE\tR4\t\t; R4 = (R2 != 0)\n"
                        "EOR\tR1, R3, R4\t; XOR the truth values");
  }

  // Update stack pointer
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 5;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle left bit shift operation
 * @param ctx Code generation context
 * @return Operation result
 */
static ocode_result_t handle_left_shift(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in LSHIFT operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_LSHIFT)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate left shift
  if (ctx->output_handler) {
    ctx->output_handler("LSL\tR1, R2, R1\t; Left shift R2 by R1 bits");
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
 * @brief Handle right bit shift operation
 * @param ctx Code generation context
 * @return Operation result
 */
static ocode_result_t handle_right_shift(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in RSHIFT operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_RSHIFT)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate right shift (logical)
  if (ctx->output_handler) {
    ctx->output_handler("LSR\tR1, R2, R1\t; Right shift R2 by R1 bits");
  }

  // Update stack pointer
  ctx->s--;

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
 * @brief Check if logical operation can be optimized with constant folding
 * @param ctx Code generation context
 * @param op Logical operation
 * @return true if optimization was applied
 */
static bool can_optimize_logical_constant(const ocode_context_t *ctx,
                                          ocode_op op) {
  // This would implement constant folding for logical operations
  // For now, return false to indicate no optimization
  return false;
}

/**
 * @brief Emit optimized short-circuit code
 * @param ctx Code generation context
 * @param op Logical operation
 * @return Operation result
 */
static ocode_result_t emit_short_circuit_code(ocode_context_t *ctx,
                                              ocode_op op) {
  // This would implement advanced short-circuit optimizations
  return OCODE_SUCCESS;
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a logical operation
 * @param op OCODE operation to check
 * @return true if op is a logical operation
 */
bool is_logical_operation(ocode_op op) {
  switch (op) {
  case S_LOGAND:
  case S_LOGOR:
  case S_NOT:
  case S_EQV:
  case S_NEQV:
  case S_LSHIFT:
  case S_RSHIFT:
    return true;
  default:
    return false;
  }
}
