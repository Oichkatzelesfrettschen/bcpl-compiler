#include <llvm-c/Core.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/Analysis.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * llcg - experimental BCPL backend generating LLVM IR.
 * This is a very small proof of concept that maps a tiny
 * subset of OCODE to LLVM.  It is intentionally incomplete
 * but demonstrates the interface used by the build system.
 */

static LLVMModuleRef module;
static LLVMBuilderRef builder;
static LLVMValueRef func;

static void init_module(void)
{
    LLVMInitializeAllTargets();
    LLVMInitializeAllTargetMCs();
    LLVMInitializeAllAsmPrinters();
    LLVMInitializeAllAsmParsers();
    module = LLVMModuleCreateWithName("bcpl_module");
    LLVMTypeRef fn_type = LLVMFunctionType(LLVMInt32Type(), NULL, 0, 0);
    func = LLVMAddFunction(module, "main", fn_type);
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(func, "entry");
    builder = LLVMCreateBuilder();
    LLVMPositionBuilderAtEnd(builder, entry);
}

static void finish_module(void)
{
    LLVMBuildRet(builder, LLVMConstInt(LLVMInt32Type(), 0, 0));
    LLVMDisposeBuilder(builder);
}

static void translate(FILE *in)
{
    char buf[256];
    while (fgets(buf, sizeof(buf), in)) {
        if (strncmp(buf, "S_MULT", 6) == 0) {
            /* placeholder: multiply top two stack values */
            /* real implementation would manipulate a stack of LLVM Values */
        }
        /* many opcodes are unimplemented and ignored */
    }
}

int main(void)
{
    init_module();
    translate(stdin);
    finish_module();
    char *ir = LLVMPrintModuleToString(module);
    fputs(ir, stdout);
    LLVMDisposeMessage(ir);
    LLVMDisposeModule(module);
    return 0;
}
