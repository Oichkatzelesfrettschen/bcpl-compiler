#pragma once
#include <stdbool.h>
#include "../oc.h"

/*
 * Minimal code generation context as described in CODEBASE_ANALYSIS.md.
 * This structure replaces scattered global variables with a single
 * container of state used by the refactored gencode() implementation.
 */
typedef struct ocode_context {
    bool readonly_mode;   /* flag used by conditional jumps */
    int  return_code;     /* pending comparison operator */
    struct {
        int stack_op1;
        int stack_op2;
        int stack_op3;
        int stack_ptr;
    } operand_stack;
} ocode_context_t;

/* Initialize all fields of the context to sensible defaults. */
static inline void ocode_context_init(ocode_context_t *ctx) {
    ctx->readonly_mode = false;
    ctx->return_code   = 0;
    ctx->operand_stack.stack_op1 = 0;
    ctx->operand_stack.stack_op2 = 0;
    ctx->operand_stack.stack_op3 = 0;
    ctx->operand_stack.stack_ptr = 0;
}

/* Single-step execution helper used by tests. */
void gencode_step(ocode_context_t *ctx, ocode_op op);
