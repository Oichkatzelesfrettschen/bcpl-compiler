/**
 * @file cg_control_flow_operations.c
 * @brief Control flow operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements control flow operations for the modernized BCPL code
 * generator, handling jumps, branches, loops, and conditional execution with
 * proper basic block management and optimization opportunities.
 *
 * "The structure of a program should mirror the structure of the problem
 * it solves." - John Lions
 *
 * Control Flow Operations Handled:
 * - S_GOTO      (Unconditional jump)
 * - S_JUMP      (Computed jump)
 * - S_JT        (Jump if true)
 * - S_JF        (Jump if false)
 * - S_SWITCHON  (Switch statement)
 * - S_LAB       (Label definition)
 * - S_BLAB      (Branch label)
 * - S_ENDFOR    (End of for loop)
 * - S_COND      (Conditional expression)
 * - S_QUERY     (Query operator)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_goto(ocode_context_t *ctx);
static ocode_result_t handle_jump(ocode_context_t *ctx);
static ocode_result_t handle_jump_if_true(ocode_context_t *ctx);
static ocode_result_t handle_jump_if_false(ocode_context_t *ctx);
static ocode_result_t handle_switch_on(ocode_context_t *ctx);
static ocode_result_t handle_label(ocode_context_t *ctx);
static ocode_result_t handle_branch_label(ocode_context_t *ctx);
static ocode_result_t handle_end_for(ocode_context_t *ctx);
static ocode_result_t handle_conditional(ocode_context_t *ctx);
static ocode_result_t handle_query(ocode_context_t *ctx);

static void emit_jump_label(ocode_context_t *ctx, int32_t label_id);
static void emit_branch(ocode_context_t *ctx, const char *condition,
                        int32_t target);
static bool is_fall_through_optimization_possible(const ocode_context_t *ctx);

// =============================================================================
// MAIN CONTROL FLOW OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all control flow operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches control flow operations to their specific handlers,
 * maintaining proper basic block boundaries and optimization opportunities.
 */
ocode_result_t handle_control_flow_operations(ocode_context_t *ctx,
                                              ocode_op op) {
  assert(ctx != NULL);
  assert(is_control_flow_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing control flow operation");
#endif

  // Prepare for control flow operation
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_GOTO:
    return handle_goto(ctx);

  case S_JUMP:
    return handle_jump(ctx);

  case S_JT:
    return handle_jump_if_true(ctx);

  case S_JF:
    return handle_jump_if_false(ctx);

  case S_SWITCHON:
    return handle_switch_on(ctx);

  case S_LAB:
    return handle_label(ctx);

  case S_BLAB:
    return handle_branch_label(ctx);

  case S_ENDFOR:
    return handle_end_for(ctx);

  case S_COND:
    return handle_conditional(ctx);

  case S_QUERY:
    return handle_query(ctx);

  default:
    report_context_error(ctx, "Unknown control flow operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC CONTROL FLOW OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle unconditional goto
 * @param ctx Code generation context
 * @return Operation result
 *
 * Generates an unconditional jump to the specified label.
 */
static ocode_result_t handle_goto(ocode_context_t *ctx) {
  assert(ctx != NULL);

#ifdef ENABLE_OPTIMIZATIONS
  // Check if this goto can be optimized away (e.g., goto next instruction)
  if (try_peephole_optimization(ctx, S_GOTO)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate unconditional branch
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction), "B\tL%d\t\t; Unconditional goto",
             ctx->k);
    ctx->output_handler(instruction);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle computed jump
 * @param ctx Code generation context
 * @return Operation result
 *
 * Performs an indirect jump using the value on top of stack as the target.
 */
static ocode_result_t handle_jump(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a target address on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in JUMP operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_JUMP)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate indirect jump
  if (ctx->output_handler) {
    ctx->output_handler("BX\tR1\t\t; Computed jump to address in R1");
  }

  // Update stack pointer (consuming target address)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle conditional jump if true
 * @param ctx Code generation context
 * @return Operation result
 *
 * Jumps to the specified label if the top stack value is true (non-zero).
 */
static ocode_result_t handle_jump_if_true(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a condition on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in JT operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_JT)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_branch(ctx, "NE", ctx->k);

  // Update stack pointer (consuming condition)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle conditional jump if false
 * @param ctx Code generation context
 * @return Operation result
 *
 * Jumps to the specified label if the top stack value is false (zero).
 */
static ocode_result_t handle_jump_if_false(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a condition on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in JF operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_JF)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  emit_branch(ctx, "EQ", ctx->k);

  // Update stack pointer (consuming condition)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 2;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle switch statement
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements a multi-way branch based on the switch value.
 */
static ocode_result_t handle_switch_on(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have a switch value on stack
  if (UNLIKELY(ctx->s < 1)) {
    report_context_error(ctx, "Stack underflow in SWITCHON operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_SWITCHON)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate switch table jump
  if (ctx->output_handler) {
    char instruction[512];
    snprintf(instruction, sizeof(instruction),
             "CMP\tR1, #%d\t\t; Check switch bounds\n"
             "BHI\tL%d_default\t; Jump to default if out of bounds\n"
             "ADD\tPC, PC, R1, LSL #2\t; Jump table dispatch\n"
             "NOP\t\t\t; Jump table starts here",
             ctx->k, ctx->next_label_number++);
    ctx->output_handler(instruction);
  }

  // Update stack pointer (consuming switch value)
  ctx->s--;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 4;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle label definition
 * @param ctx Code generation context
 * @return Operation result
 *
 * Defines a label at the current instruction position.
 */
static ocode_result_t handle_label(ocode_context_t *ctx) {
  assert(ctx != NULL);

  emit_jump_label(ctx, ctx->k);

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
// Labels don't emit actual instructions
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle branch label
 * @param ctx Code generation context
 * @return Operation result
 *
 * Defines a branch target label.
 */
static ocode_result_t handle_branch_label(ocode_context_t *ctx) {
  assert(ctx != NULL);

  emit_jump_label(ctx, ctx->k);

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle end of for loop
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles the end of a for loop construct, typically generating
 * loop iteration and termination logic.
 */
static ocode_result_t handle_end_for(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // For loops typically need to check the condition and jump back
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "B\tL%d\t\t; Jump back to for loop condition", ctx->k);
    ctx->output_handler(instruction);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle conditional expression
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements the ternary conditional operator (condition ? true_value :
 * false_value).
 */
static ocode_result_t handle_conditional(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Validate we have condition, true_value, and false_value on stack
  if (UNLIKELY(ctx->s < 3)) {
    report_context_error(ctx, "Stack underflow in COND operation");
    return OCODE_RUNTIME_ERROR;
  }

#ifdef ENABLE_OPTIMIZATIONS
  if (try_peephole_optimization(ctx, S_COND)) {
    return OCODE_OPTIMIZATION_APPLIED;
  }
#endif

  // Generate conditional selection
  if (ctx->output_handler) {
    char instruction[512];
    snprintf(instruction, sizeof(instruction),
             "CMP\tR3, #0\t\t; Test condition\n"
             "MOVEQ\tR1, R1\t\t; Use false value if condition is 0\n"
             "MOVNE\tR1, R2\t\t; Use true value if condition is non-0");
    ctx->output_handler(instruction);
  }

  // Update stack pointer (consume 3 values, produce 1 result)
  ctx->s -= 2;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 3;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle query operator
 * @param ctx Code generation context
 * @return Operation result
 *
 * Implements the query operator used in conditional expressions.
 */
static ocode_result_t handle_query(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // The query operator is typically handled as part of conditional expressions
  // For now, treat it as a no-op that preserves the stack

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Emit a label definition
 * @param ctx Code generation context
 * @param label_id Label identifier
 */
static void emit_jump_label(ocode_context_t *ctx, int32_t label_id) {
  if (ctx->output_handler) {
    char label[128];
    snprintf(label, sizeof(label), "L%d:", label_id);
    ctx->output_handler(label);
  }
}

/**
 * @brief Emit a conditional branch instruction
 * @param ctx Code generation context
 * @param condition Branch condition (EQ, NE, etc.)
 * @param target Target label
 */
static void emit_branch(ocode_context_t *ctx, const char *condition,
                        int32_t target) {
  if (ctx->output_handler) {
    char instruction[256];
    snprintf(instruction, sizeof(instruction),
             "CMP\tR1, #0\t\t; Test condition\n"
             "B%s\tL%d\t\t; Branch if %s",
             condition, target, condition);
    ctx->output_handler(instruction);
  }
}

/**
 * @brief Check if fall-through optimization is possible
 * @param ctx Code generation context
 * @return true if optimization is possible
 */
static bool is_fall_through_optimization_possible(const ocode_context_t *ctx) {
  // This would analyze if a branch can be eliminated when the target
  // is the next instruction (fall-through case)
  return false;
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a control flow operation
 * @param op OCODE operation to check
 * @return true if op is a control flow operation
 */
bool is_control_flow_operation(ocode_op op) {
  switch (op) {
  case S_GOTO:
  case S_JUMP:
  case S_JT:
  case S_JF:
  case S_SWITCHON:
  case S_LAB:
  case S_BLAB:
  case S_ENDFOR:
  case S_COND:
  case S_QUERY:
    return true;
  default:
    return false;
  }
}
