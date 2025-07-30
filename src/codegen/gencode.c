#include "context.h"
#include <stdio.h>

/* Forward declarations for operation handlers */
static void handle_load(ocode_context_t *ctx, ocode_op op);
static void handle_store(ocode_context_t *ctx, ocode_op op);
static void handle_arithmetic(ocode_context_t *ctx, ocode_op op);
static void handle_comparison(ocode_context_t *ctx, ocode_op op);
static void handle_memory(ocode_context_t *ctx, ocode_op op);
static void handle_control_flow(ocode_context_t *ctx, ocode_op op);
static void handle_function(ocode_context_t *ctx, ocode_op op);
static void handle_meta(ocode_context_t *ctx, ocode_op op);

/*
 * Simple dispatch table mapping OCODE operations to their handlers. Only
 * a small subset of the instruction set is needed for unit testing.
 */
static void (*const handlers[OPMAX + 1])(ocode_context_t *, ocode_op) = {
    [S_LN] = handle_load,
    [S_TRUE] = handle_load,
    [S_FALSE] = handle_load,
    [S_LP] = handle_load,
    [S_LG] = handle_load,
    [S_LL] = handle_load,
    [S_LLP] = handle_load,
    [S_LLG] = handle_load,
    [S_LLL] = handle_load,
    [S_LSTR] = handle_load,
    [S_QUERY] = handle_load,

    [S_SP] = handle_store,
    [S_SG] = handle_store,
    [S_SL] = handle_store,

    [S_MULT] = handle_arithmetic,
    [S_DIV] = handle_arithmetic,
    [S_REM] = handle_arithmetic,
    [S_PLUS] = handle_arithmetic,
    [S_MINUS] = handle_arithmetic,
    [S_NEG] = handle_arithmetic,
    [S_ABS] = handle_arithmetic,

    [S_EQ] = handle_comparison,
    [S_NE] = handle_comparison,

    [S_RV] = handle_memory,
    [S_GETBYTE] = handle_memory,
    [S_PUTBYTE] = handle_memory,
    [S_STIND] = handle_memory,

    [S_GOTO] = handle_control_flow,
    [S_JT] = handle_control_flow,
    [S_JF] = handle_control_flow,
    [S_JUMP] = handle_control_flow,
    [S_SWITCHON] = handle_control_flow,
    [S_ENDFOR] = handle_control_flow,

    [S_FNAP] = handle_function,
    [S_RTAP] = handle_function,
    [S_FNRN] = handle_function,
    [S_RTRN] = handle_function,

    [S_BLAB] = handle_meta,
    [S_LAB] = handle_meta,
    [S_DATALAB] = handle_meta,
    [S_ITEML] = handle_meta,
    [S_ITEMN] = handle_meta,
    [S_GLOBAL] = handle_meta,
};

void gencode_step(ocode_context_t *ctx, ocode_op op) {
    if (!ctx || op < 0 || op > OPMAX || !handlers[op]) {
        return; /* Invalid operation */
    }
    handlers[op](ctx, op);
}

/* --------------------------------------------------------------------- */
/* Handlers                                                             */
/* --------------------------------------------------------------------- */

static void handle_load(ocode_context_t *ctx, ocode_op op) {
    (void)op;
    ctx->operand_stack.stack_ptr++;
    ctx->operand_stack.stack_op1 = op;
}

static void handle_store(ocode_context_t *ctx, ocode_op op) {
    (void)op;
    if (ctx->operand_stack.stack_ptr > 0)
        ctx->operand_stack.stack_ptr--;
}

static void handle_arithmetic(ocode_context_t *ctx, ocode_op op) {
    (void)op;
    /* emulate binary operation consuming two operands and pushing one */
    if (ctx->operand_stack.stack_ptr >= 2)
        ctx->operand_stack.stack_ptr -= 1;
    ctx->operand_stack.stack_op2 = op;
}

static void handle_comparison(ocode_context_t *ctx, ocode_op op) {
    ctx->return_code = op;
    if (ctx->operand_stack.stack_ptr >= 2)
        ctx->operand_stack.stack_ptr -= 1;
}

static void handle_memory(ocode_context_t *ctx, ocode_op op) {
    (void)op;
    /* memory ops do not change stack in this simplified model */
}

static void handle_control_flow(ocode_context_t *ctx, ocode_op op) {
    ctx->readonly_mode = (op == S_JT || op == S_JF);
}

static void handle_function(ocode_context_t *ctx, ocode_op op) {
    (void)op;
    ctx->operand_stack.stack_ptr = 0; /* simplistic: calls clear the stack */
}

static void handle_meta(ocode_context_t *ctx, ocode_op op) {
    (void)op;
    /* meta operations have no effect in this stub */
}


