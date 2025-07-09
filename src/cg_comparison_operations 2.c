/**
 * @file cg_comparison_operations.c
 * @brief Comparison operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements comparison operations for the modernized BCPL code
 * generator, handling all relational and equality comparisons with proper
 * type handling and optimization opportunities.
 *
 * "Simplicity is prerequisite for reliability." - Edsger W. Dijkstra
 *
 * Comparison Operations Handled:
 * - S_EQ (Equal)
 * - S_NE (Not Equal)
 * - S_LS (Less Than)
 * - S_GR (Greater Than)
 * - S_LE (Less Than or Equal)
 * - S_GE (Greater Than or Equal)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_equal(ocode_context_t *ctx);
static ocode_result_t handle_not_equal(ocode_context_t *ctx);
static ocode_result_t handle_less_than(ocode_context_t *ctx);
static ocode_result_t handle_greater_than(ocode_context_t *ctx);
static ocode_result_t handle_less_equal(ocode_context_t *ctx);
static ocode_result_t handle_greater_equal(ocode_context_t *ctx);

static void emit_comparison_instruction(ocode_context_t *ctx,
                                        const char *condition,
                                        const char *description);
static bool can_optimize_comparison(const ocode_context_t *ctx, ocode_op op);

// =============================================================================
// MAIN COMPARISON OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all comparison operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches comparison operations to their specific handlers,
 * ensuring consistent behavior and optimization opportunities across all
 * relational operators.
 */
ocode_result_t handle_comparison_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_comparison_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing comparison operation");
#endif

  // All comparison operations require two operands
  if (UNLIKELY(ctx->s < 2)) {
    report_context_error(ctx, "Stack underflow in comparison operation %d", op);
    return OCODE_RUNTIME_ERROR;
  }

  // Prepare operands for comparison
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_EQ:
    return handle_equal(ctx);

  case S_NE:
    return handle_not_equal(ctx);

  case S_LS:
    return handle_less_than(ctx);

  case S_GR:
    return handle_greater_than(ctx);

  case S_LE:
    return handle_less_equal(ctx);

  case S_GE:
    return handle_greater_equal(ctx);

  default:
    report_context_error(ctx, "Unknown comparison operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC COMPARISON OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle equality comparison (EQ)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Tests if two values are equal, producing 1 (true) or 0 (false).
 */
static ocode_result_t handle_equal(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_comparison(ctx, S_EQ)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_EQ)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_comparison_instruction(ctx, "EQ", "Equal");

  // Update stack pointer (two operands in, one result out)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle inequality comparison (NE)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Tests if two values are not equal, producing 1 (true) or 0 (false).
 */
static ocode_result_t handle_not_equal(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_comparison(ctx, S_NE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_NE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_comparison_instruction(ctx, "NE", "Not equal");

  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle less than comparison (LS)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Tests if first operand is less than second operand.
 */
static ocode_result_t handle_less_than(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_comparison(ctx, S_LS)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_LS)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_comparison_instruction(ctx, "LT", "Less than");

  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle greater than comparison (GR)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Tests if first operand is greater than second operand.
 */
static ocode_result_t handle_greater_than(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_comparison(ctx, S_GR)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_GR)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_comparison_instruction(ctx, "GT", "Greater than");

  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle less than or equal comparison (LE)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Tests if first operand is less than or equal to second operand.
 */
static ocode_result_t handle_less_equal(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_comparison(ctx, S_LE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_LE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_comparison_instruction(ctx, "LE", "Less than or equal");

  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle greater than or equal comparison (GE)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Tests if first operand is greater than or equal to second operand.
 */
static ocode_result_t handle_greater_equal(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  if (can_optimize_comparison(ctx, S_GE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }

  if (try_peephole_optimization(ctx, S_GE)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_comparison_instruction(ctx, "GE", "Greater than or equal");

  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Emit comparison instruction sequence
 * @param ctx Code generation context
 * @param condition Condition code (EQ, NE, LT, etc.)
 * @param description Human-readable description
 *
 * Generates the standard comparison sequence that compares two values
 * and sets the result register based on the condition.
 */
static void emit_comparison_instruction(ocode_context_t *ctx,
                                        const char *condition,
                                        const char *description) {
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "CMP\tR2, R1\t\t; Compare operands\n"
             "SET%s\tR1\t\t; Set result: %s",
             condition, description);
    ctx->output_handler(instruction);
  }
}

/**
 * @brief Check if comparison can be optimized
 * @param ctx Code generation context
 * @param op Comparison operation
 * @return true if optimization was applied
 *
 * This function implements constant folding and other optimizations
 * for comparison operations when operands are known at compile time.
 */
static bool can_optimize_comparison(const ocode_context_t *ctx, ocode_op op) {
  // Future implementation could check for:
  // - Constant operands (compile-time evaluation)
  // - Self-comparison (x == x, x < x, etc.)
  // - Range analysis results
  // - Previous comparison results

  // For now, no optimizations implemented
  return false;
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a comparison operation
 * @param op OCODE operation to check
 * @return true if op is a comparison operation
 */
bool is_comparison_operation(ocode_op op) {
  switch (op) {
  case S_EQ:
  case S_NE:
  case S_LS:
  case S_GR:
  case S_LE:
  case S_GE:
    return true;
  default:
    return false;
  }
}
