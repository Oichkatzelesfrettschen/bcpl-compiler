#include <stdio.h>
#include <assert.h>
#include "../src/codegen/context.h"

#define TEST_ASSERT(cond, msg) \
    do { if(!(cond)) { printf("FAIL: %s\n", msg); return 1; } \
         else { printf("PASS: %s\n", msg); } } while(0)

int main(void) {
    ocode_context_t ctx;
    ocode_context_init(&ctx);

    gencode_step(&ctx, S_LN);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 1, "load handler" );

    gencode_step(&ctx, S_SP);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 0, "store handler" );

    ctx.operand_stack.stack_ptr = 2;
    gencode_step(&ctx, S_PLUS);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 1, "arithmetic handler" );

    ctx.operand_stack.stack_ptr = 2;
    gencode_step(&ctx, S_EQ);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 1 && ctx.return_code == S_EQ, "comparison handler" );

    gencode_step(&ctx, S_STIND);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 1, "memory handler" );

    gencode_step(&ctx, S_GOTO);
    TEST_ASSERT(ctx.readonly_mode == 0, "control flow handler" );

    ctx.operand_stack.stack_ptr = 3;
    gencode_step(&ctx, S_FNAP);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 0, "function handler" );

    gencode_step(&ctx, S_BLAB);
    TEST_ASSERT(ctx.operand_stack.stack_ptr == 0, "meta handler" );

    printf("All handler tests passed.\n");
    return 0;
}

