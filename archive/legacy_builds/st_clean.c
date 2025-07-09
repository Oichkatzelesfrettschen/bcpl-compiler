/**
 * Generated C code from BCPL OCODE
 * Platform-agnostic BCPL runtime
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// BCPL runtime types
typedef int32_t bcpl_word_t;
typedef bcpl_word_t* bcpl_vector_t;

// Global BCPL context
static bcpl_word_t bcpl_globals[10000];
static bcpl_word_t bcpl_locals[1000];
static bcpl_word_t bcpl_stack[10000];
static int bcpl_stack_ptr = 0;
static int bcpl_argc = 0;
static char** bcpl_argv = NULL;

// BCPL runtime functions
static void bcpl_push(bcpl_word_t value) {
    if (bcpl_stack_ptr >= 10000) {
        fprintf(stderr, "BCPL stack overflow\n");
        exit(1);
    }
    bcpl_stack[bcpl_stack_ptr++] = value;
}

static bcpl_word_t bcpl_pop(void) {
    if (bcpl_stack_ptr <= 0) {
        fprintf(stderr, "BCPL stack underflow\n");
        exit(1);
    }
    return bcpl_stack[--bcpl_stack_ptr];
}

static void bcpl_store_global(int index, bcpl_word_t value) {
    if (index >= 0 && index < 10000) {
        bcpl_globals[index] = value;
    }
}

static bcpl_word_t bcpl_load_global(int index) {
    if (index >= 0 && index < 10000) {
        return bcpl_globals[index];
    }
    return 0;
}

static bcpl_word_t bcpl_load_indirect(bcpl_word_t addr) {
    // Simplified indirect load - in real BCPL this would access memory
    if (addr >= 0 && addr < 10000) {
        return bcpl_globals[addr];
    }
    return 0;
}

// BCPL I/O functions
static void bcpl_wrch(bcpl_word_t ch) {
    putchar(ch);
    fflush(stdout);
}

static bcpl_word_t bcpl_rdch(void) {
    return getchar();
}

static bcpl_word_t bcpl_rdline(void) {
    // Simplified readline - return address of input buffer
    static char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin)) {
        return (bcpl_word_t)(uintptr_t)buffer;
    }
    return 0;
}

// BCPL string functions
static void bcpl_writes(bcpl_word_t str_addr) {
    // In BCPL, strings are typically stored as length-prefixed
    // For simplicity, we'll treat this as a C string pointer
    char* str = (char*)(uintptr_t)str_addr;
    if (str) {
        printf("%s", str);
        fflush(stdout);
    }
}

// BCPL memory management
static bcpl_word_t bcpl_getvec(bcpl_word_t size) {
    // Allocate vector/array
    bcpl_word_t* vec = (bcpl_word_t*)malloc(size * sizeof(bcpl_word_t));
    if (vec) {
        memset(vec, 0, size * sizeof(bcpl_word_t));
        return (bcpl_word_t)(uintptr_t)vec;
    }
    return 0;
}

static void bcpl_freevec(bcpl_word_t vec_addr) {
    // Free vector/array
    void* vec = (void*)(uintptr_t)vec_addr;
    if (vec) {
        free(vec);
    }
}

static void bcpl_init(int argc, char* argv[]) {
    bcpl_argc = argc;
    bcpl_argv = argv;
    
    // Initialize BCPL runtime
    memset(bcpl_globals, 0, sizeof(bcpl_globals));
    memset(bcpl_locals, 0, sizeof(bcpl_locals));
    memset(bcpl_stack, 0, sizeof(bcpl_stack));
    bcpl_stack_ptr = 0;
}

// Main BCPL program entry point - forward declaration
static void bcpl_start(void);

static void bcpl_start(void) {
    // Generated from OCODE
    bcpl_word_t A = 0, B = 0, C = 0; // BCPL registers

    // FUNCTION_HEADER - 6 parameters
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 5
    L1:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(16); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(17); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    goto L11; // JUMP
    // UNKNOWN_47 47 - not implemented
    L47:
    // LOOP_START 101
    // UNKNOWN_118 118 - not implemented
    L118:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_115 115 - not implemented
    L115:
    // UNKNOWN_116 116 - not implemented
    L116:
    // LOOP_START 101
    // UNKNOWN_114 114 - not implemented
    L114:
    // UNKNOWN_114 114 - not implemented
    L114:
    bcpl_push(41); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[194] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    goto L9; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_80 80 - not implemented
    L80:
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_78 78 - not implemented
    L78:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_46 46 - not implemented
    L46:
    // UNKNOWN_1 1 - not implemented
    L1:
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(bcpl_load_indirect(55000)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[128] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_locals[282] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[127] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[110] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[111] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L4; // GOTO
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_28 28 - not implemented
    L28:
    goto L3; // GOTO
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L4; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    goto L3; // JUMP
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_84 84 - not implemented
    L84:
    bcpl_push(42); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_28 28 - not implemented
    L28:
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_28 28 - not implemented
    L28:
    if (bcpl_pop()) goto L5; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L7
    // LOOP_END L6
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    goto L9; // JUMP
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    goto L8; // GOTO
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(13); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_30 30 - not implemented
    L30:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_28 28 - not implemented
    L28:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L6; } // BRANCH_IF_LT
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L10; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L9; } // BRANCH_IF_NEQ
    goto L10; // GOTO
    goto L11; // CALL_FUNCTION (as GOTO)
    goto L9; // GOTO
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(80)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L12; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_29 29 - not implemented
    L29:
    goto L12; // GOTO
    bcpl_push(bcpl_load_indirect(84)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_29 29 - not implemented
    L29:
    goto L13; // GOTO
    bcpl_push(bcpl_load_indirect(67)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L14; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_29 29 - not implemented
    L29:
    goto L14; // GOTO
    bcpl_push(bcpl_load_indirect(77)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L15; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_29 29 - not implemented
    L29:
    goto L15; // GOTO
    bcpl_push(bcpl_load_indirect(78)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L16; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_29 29 - not implemented
    L29:
    goto L16; // GOTO
    bcpl_push(bcpl_load_indirect(83)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17; } // BRANCH_IF_NEQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[110] = bcpl_pop(); // STORE_LOCAL
    goto L17; // GOTO
    bcpl_push(bcpl_load_indirect(69)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L18; } // BRANCH_IF_NEQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[127] = bcpl_pop(); // STORE_LOCAL
    goto L18; // GOTO
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(70); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_30 30 - not implemented
    L30:
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(62); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    goto L19; // GOTO
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L20; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[282] = bcpl_pop(); // STORE_LOCAL
    goto L20; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[29]); // LOAD_LOCAL
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L8; // CALL_FUNCTION (as GOTO)
    goto L11; // GOTO
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    goto L5; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_30 30 - not implemented
    L30:
    bcpl_locals[114] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_locals[192] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[191] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[195] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(195); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_28 28 - not implemented
    L28:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21; } // BRANCH_IF_NEQ
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_locals[195] = bcpl_pop(); // STORE_LOCAL
    goto L21; // GOTO
    // LOOP_START L23
    // LOOP_END L22
    goto L24; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 4
    L22:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // FUNCTION_END 4
    // JUMP_IF_NOT_ZERO 45 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_globals[69]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[100] = bcpl_pop(); // STORE_LOCAL
    goto L25; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[168] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[169] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(110); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[71]); // LOAD_GLOBAL
    goto L4; // JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    bcpl_push(41); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // LOCAL_VAR allocation
    bcpl_locals[196] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[71]); // LOAD_GLOBAL
    bcpl_push(196); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L28; } // BRANCH_IF_NEQ
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_locals[196] = bcpl_pop(); // STORE_LOCAL
    goto L28; // GOTO
    goto L27; // CALL_FUNCTION (as GOTO)
    goto L26; // GOTO
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_locals[196] = bcpl_pop(); // STORE_LOCAL
    goto L27; // GOTO
    bcpl_push(bcpl_globals[71]); // LOAD_GLOBAL
    bcpl_push(150); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // LOCAL_VAR allocation
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[69]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29; } // BRANCH_IF_NEQ
    goto L30; // CALL_FUNCTION (as GOTO)
    goto L29; // GOTO
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    goto L14; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    goto L69; // GOTO
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_78 78 - not implemented
    L78:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(169); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(168); // LOAD_CONSTANT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    goto L8; // JUMP
    // UNKNOWN_65 65 - not implemented
    L65:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[69]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(152); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    goto L31; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L32; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    goto L32; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    if (bcpl_pop()) goto L33; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(195); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[69]); // LOAD_LOCAL
    bcpl_push(245); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    goto L33; // GOTO
    bcpl_push(bcpl_globals[69]); // LOAD_GLOBAL
    goto L25; // CALL_FUNCTION (as GOTO)
    goto L30; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    goto L24; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L23:
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(40); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    goto L18; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // FUNCTION_HEADER - 32 parameters
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L34; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    goto L34; // GOTO
    bcpl_pop(); // POP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    L1:
    // UNKNOWN_1 1 - not implemented
    L1:
    L1:
    // FUNCTION_HEADER - 4 parameters
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L49; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 8
    L1:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L84; } // BRANCH_IF_EQ
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L77; } // BRANCH_IF_LT
    // UNKNOWN_66 66 - not implemented
    L66:
    // FUNCTION_END 2
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[122] = bcpl_pop(); // STORE_LOCAL
    goto L3; // GOTO
    bcpl_push(127); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L4; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L4; // GOTO
    goto L5; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    goto L8; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[122] = bcpl_pop(); // STORE_LOCAL
    goto L9; // GOTO
    goto L10; // GOTO
    goto L11; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L9; // CONDITIONAL_JUMP
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L12; // GOTO
    goto L13; // GOTO
    goto L14; // GOTO
    goto L15; // GOTO
    goto L16; // GOTO
    goto L17; // GOTO
    goto L18; // GOTO
    goto L19; // GOTO
    goto L20; // GOTO
    goto L21; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L22; // GOTO
    goto L23; // GOTO
    goto L24; // GOTO
    goto L25; // GOTO
    goto L26; // GOTO
    goto L27; // GOTO
    goto L28; // GOTO
    goto L29; // GOTO
    goto L30; // GOTO
    goto L31; // GOTO
    goto L32; // GOTO
    goto L33; // GOTO
    goto L34; // GOTO
    goto L35; // GOTO
    goto L36; // GOTO
    goto L37; // GOTO
    goto L38; // GOTO
    goto L39; // GOTO
    goto L40; // GOTO
    goto L41; // GOTO
    goto L42; // GOTO
    goto L43; // GOTO
    goto L44; // GOTO
    goto L45; // GOTO
    goto L46; // GOTO
    goto L47; // GOTO
    goto L48; // GOTO
    goto L49; // GOTO
    goto L50; // GOTO
    goto L51; // GOTO
    goto L52; // GOTO
    goto L53; // GOTO
    goto L54; // GOTO
    goto L55; // GOTO
    goto L56; // GOTO
    goto L57; // GOTO
    goto L58; // GOTO
    goto L59; // GOTO
    goto L60; // GOTO
    goto L61; // GOTO
    goto L62; // GOTO
    goto L63; // GOTO
    goto L64; // GOTO
    goto L65; // GOTO
    goto L66; // GOTO
    goto L67; // GOTO
    goto L68; // GOTO
    goto L69; // GOTO
    goto L70; // GOTO
    goto L71; // GOTO
    goto L72; // GOTO
    goto L73; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(118); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(93)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L74; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(119); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L74; // GOTO
    return; // RETURN
    goto L75; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L76; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L76; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L76; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L78; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L77:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L78; // GOTO
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L77:
    goto L77; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(36)); // LOAD_INDIRECT
    bcpl_push(118); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L79; // GOTO
    goto L80; // GOTO
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L82; // GOTO
    goto L83; // GOTO
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L84; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L85; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(55)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L85; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L85; // GOTO
    bcpl_push(bcpl_load_indirect(66)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L86; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L86; // GOTO
    bcpl_push(bcpl_load_indirect(79)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L87; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L87; // GOTO
    bcpl_push(bcpl_load_indirect(88)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L88; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L88; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L89; // GOTO
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L90; // GOTO
    bcpl_push(bcpl_load_indirect(14)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L91; // GOTO
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L92; // GOTO
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L93; // GOTO
    bcpl_push(bcpl_load_indirect(7)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L94; // GOTO
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L95; // GOTO
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L96; // GOTO
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L97; // GOTO
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L98; // GOTO
    bcpl_push(bcpl_load_indirect(28)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L99; // GOTO
    bcpl_push(bcpl_load_indirect(11)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L100; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L101; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L101; // GOTO
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L102; } // BRANCH_IF_NEQ
    goto L103; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L104; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L103; } // BRANCH_IF_NEQ
    goto L104; // GOTO
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L102; // GOTO
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L105; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(12)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L105; // GOTO
    goto L106; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L107; } // BRANCH_IF_NEQ
    goto L108; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L108; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L109; } // BRANCH_IF_NEQ
    goto L110; // CALL_FUNCTION (as GOTO)
    goto L109; // GOTO
    goto L107; // GOTO
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L111; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    goto L111; // GOTO
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L112; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L112; // GOTO
    goto L106; // CALL_FUNCTION (as GOTO)
    goto L110; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L113; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L114; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(21)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L114; // GOTO
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L115; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L116; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L116; // GOTO
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L117; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(21)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L117; // GOTO
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L118; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L119; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(24)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L119; // GOTO
    bcpl_push(bcpl_load_indirect(60)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L120; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(31)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L120; // GOTO
    bcpl_push(bcpl_load_indirect(22)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L121; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L122; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(25)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L122; // GOTO
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L123; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L123; // GOTO
    bcpl_push(bcpl_load_indirect(23)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L124; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L125; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(37)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L125; // GOTO
    bcpl_push(bcpl_load_indirect(15)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L126; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L127; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(50)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L127; // GOTO
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L128; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L130; // CALL_FUNCTION (as GOTO)
    goto L129; // GOTO
    bcpl_push(bcpl_load_indirect(255)); // LOAD_INDIRECT
    bcpl_push(109); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L131; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L131; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(109); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(113); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L130; // GOTO
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L129; } // BRANCH_IF_NEQ
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[107] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L132; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(113); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[101] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(39)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L133; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L133; // GOTO
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L134; // GOTO
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L135; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(94)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L135; // GOTO
    goto L136; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L137; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L137; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[104] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L6; // CALL_FUNCTION (as GOTO)
    goto L5; // GOTO
    bcpl_push(117); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_93 93 - not implemented
    L93:
    L134:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L7:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    L8:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L10:
    // UNKNOWN_32 32 - not implemented
    L32:
    L11:
    // UNKNOWN_48 48 - not implemented
    L48:
    L12:
    // FUNCTION_HEADER - L13 parameters
    // UNKNOWN_50 50 - not implemented
    L50:
    L14:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L15]); // DUPLICATE
    // UNKNOWN_52 52 - not implemented
    L52:
    L16:
    // UNKNOWN_53 53 - not implemented
    L53:
    L17:
    // UNKNOWN_54 54 - not implemented
    L54:
    L18:
    // UNKNOWN_55 55 - not implemented
    L55:
    L19:
    // UNKNOWN_56 56 - not implemented
    L56:
    L20:
    // UNKNOWN_57 57 - not implemented
    L57:
    L21:
    return; // RETURN
    L22:
    // UNKNOWN_98 98 - not implemented
    L98:
    L23:
    // UNKNOWN_99 99 - not implemented
    L99:
    L24:
    // LOOP_START L25
    // LOOP_END L26
    // UNKNOWN_102 102 - not implemented
    L102:
    L27:
    // END_BLOCK
    L28:
    // UNKNOWN_104 104 - not implemented
    L104:
    L29:
    // UNKNOWN_105 105 - not implemented
    L105:
    L30:
    // UNKNOWN_106 106 - not implemented
    L106:
    L31:
    // UNKNOWN_107 107 - not implemented
    L107:
    L32:
    // UNKNOWN_108 108 - not implemented
    L108:
    L33:
    // UNKNOWN_109 109 - not implemented
    L109:
    L34:
    // UNKNOWN_110 110 - not implemented
    L110:
    L35:
    // UNKNOWN_111 111 - not implemented
    L111:
    L36:
    // UNKNOWN_112 112 - not implemented
    L112:
    L37:
    // UNKNOWN_113 113 - not implemented
    L113:
    L38:
    // UNKNOWN_114 114 - not implemented
    L114:
    L39:
    // UNKNOWN_115 115 - not implemented
    L115:
    L40:
    // UNKNOWN_116 116 - not implemented
    L116:
    L41:
    // UNKNOWN_117 117 - not implemented
    L117:
    L42:
    // UNKNOWN_118 118 - not implemented
    L118:
    L43:
    // UNKNOWN_119 119 - not implemented
    L119:
    L44:
    // UNKNOWN_120 120 - not implemented
    L120:
    L45:
    // UNKNOWN_121 121 - not implemented
    L121:
    L46:
    // UNKNOWN_122 122 - not implemented
    L122:
    L47:
    // UNKNOWN_65 65 - not implemented
    L65:
    L48:
    // UNKNOWN_66 66 - not implemented
    L66:
    L49:
    // UNKNOWN_67 67 - not implemented
    L67:
    L50:
    bcpl_pop(); // POP
    L51:
    // LOCAL_VAR allocation
    L52:
    // TEMP_VAR allocation
    L53:
    // UNKNOWN_71 71 - not implemented
    L71:
    L54:
    // UNKNOWN_72 72 - not implemented
    L72:
    L55:
    // UNKNOWN_73 73 - not implemented
    L73:
    L56:
    // UNKNOWN_74 74 - not implemented
    L74:
    L57:
    // UNKNOWN_75 75 - not implemented
    L75:
    L58:
    // STRING_CONSTANT definition
    L59:
    // UNKNOWN_77 77 - not implemented
    L77:
    L60:
    // UNKNOWN_78 78 - not implemented
    L78:
    L61:
    // PUSH_STRING - string handling
    L62:
    // UNKNOWN_80 80 - not implemented
    L80:
    L63:
    bcpl_locals[L64] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_82 82 - not implemented
    L82:
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    L66:
    // UNKNOWN_84 84 - not implemented
    L84:
    L67:
    goto L68; // CALL_FUNCTION (as GOTO)
    if (bcpl_pop()) goto L69; // CONDITIONAL_JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L70; } // BRANCH_IF_NEQ
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L71; } // BRANCH_IF_EQ
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L72; } // BRANCH_IF_LT
    goto L73; // GOTO
    // UNKNOWN_36 36 - not implemented
    L36:
    L75:
    bcpl_push(bcpl_globals[L79]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[L80]); // LOAD_LOCAL
    // UNKNOWN_93 93 - not implemented
    L93:
    L82:
    bcpl_push(L83); // LOAD_CONSTANT
    // UNKNOWN_35 35 - not implemented
    L35:
    L84:
    // UNKNOWN_63 63 - not implemented
    L63:
    L89:
    goto L90; // JUMP
    // JUMP_IF_ZERO 44 - not implemented
    L91:
    // UNKNOWN_59 59 - not implemented
    L59:
    L92:
    // UNKNOWN_64 64 - not implemented
    L64:
    L93:
    // UNKNOWN_38 38 - not implemented
    L38:
    L94:
    // UNKNOWN_124 124 - not implemented
    L124:
    L95:
    // UNKNOWN_61 61 - not implemented
    L61:
    L96:
    // UNKNOWN_33 33 - not implemented
    L33:
    L97:
    // UNKNOWN_37 37 - not implemented
    L37:
    L98:
    bcpl_push(bcpl_load_indirect(L99)); // LOAD_INDIRECT
    // UNKNOWN_47 47 - not implemented
    L47:
    L100:
    // UNKNOWN_126 126 - not implemented
    L126:
    L113:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    L115:
    // UNKNOWN_60 60 - not implemented
    L60:
    L118:
    // UNKNOWN_62 62 - not implemented
    L62:
    L121:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L124:
    // UNKNOWN_58 58 - not implemented
    L58:
    L126:
    // UNKNOWN_34 34 - not implemented
    L34:
    L128:
    // UNKNOWN_39 39 - not implemented
    L39:
    L132:
    // UNKNOWN_46 46 - not implemented
    L46:
    L136:
    goto L6; // GOTO
    goto L3; // CALL_FUNCTION (as GOTO)
    goto L81; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    L1:
    // UNKNOWN_120 120 - not implemented
    L120:
    L1:
    // FUNCTION_HEADER - 4 parameters
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L50; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L4
    // LOOP_END L3
    goto L5; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 10
    L1:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_75 75 - not implemented
    L75:
    goto L80; // CALL_FUNCTION (as GOTO)
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79; } // BRANCH_IF_NEQ
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(106); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(107); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    // UNKNOWN_13 13 - not implemented
    L13:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[116] = bcpl_pop(); // STORE_LOCAL
    goto L8; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(106); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L9; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L10; // CALL_FUNCTION (as GOTO)
    goto L9; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[116] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L10; // GOTO
    goto L8; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L11; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(107); // LOAD_CONSTANT
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L7; } // BRANCH_IF_NEQ
    goto L11; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L12; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[116] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L13; // CALL_FUNCTION (as GOTO)
    goto L14; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(106); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L13; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L14; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L12; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L98:
    L6:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L6; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 12
    L2:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L83; } // BRANCH_IF_LT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79; } // BRANCH_IF_NEQ
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 2
    // LOOP_START L15
    // UNKNOWN_102 102 - not implemented
    L102:
    bcpl_push(bcpl_locals[102]); // LOAD_LOCAL
    // UNKNOWN_19 19 - not implemented
    L19:
    // UNKNOWN_102 102 - not implemented
    L102:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L102; } // BRANCH_IF_LT
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_102 102 - not implemented
    L102:
    // LOOP_START 102
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_102 102 - not implemented
    L102:
    // LOOP_END 102
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_102 102 - not implemented
    L102:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_35 35 - not implemented
    L35:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_102 102 - not implemented
    L102:
    // LOCAL_VAR allocation
    // UNKNOWN_102 102 - not implemented
    L102:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_56 56 - not implemented
    L56:
    // UNKNOWN_102 102 - not implemented
    L102:
    bcpl_pop(); // POP
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_52 52 - not implemented
    L52:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_25 25 - not implemented
    L25:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_23 23 - not implemented
    L23:
    // UNKNOWN_102 102 - not implemented
    L102:
    // STRING_CONSTANT definition
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_57 57 - not implemented
    L57:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_98 98 - not implemented
    L98:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_74 74 - not implemented
    L74:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_7 7 - not implemented
    L7:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_24 24 - not implemented
    L24:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_22 22 - not implemented
    L22:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_34 34 - not implemented
    L34:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_33 33 - not implemented
    L33:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_31 31 - not implemented
    L31:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_75 75 - not implemented
    L75:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_21 21 - not implemented
    L21:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_30 30 - not implemented
    L30:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_36 36 - not implemented
    L36:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_48 48 - not implemented
    L48:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_53 53 - not implemented
    L53:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_13 13 - not implemented
    L13:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_102 102 - not implemented
    L102:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_61 61 - not implemented
    L61:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_62 62 - not implemented
    L62:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_63 63 - not implemented
    L63:
    // UNKNOWN_102 102 - not implemented
    L102:
    // TEMP_VAR allocation
    // UNKNOWN_102 102 - not implemented
    L102:
    // PUSH_STRING - string handling
    // UNKNOWN_102 102 - not implemented
    L102:
    // FUNCTION_HEADER - 102 parameters
    // UNKNOWN_99 99 - not implemented
    L99:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_55 55 - not implemented
    L55:
    // UNKNOWN_102 102 - not implemented
    L102:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_102 102 - not implemented
    L102:
    // LOOP_END 102
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_60 60 - not implemented
    L60:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_58 58 - not implemented
    L58:
    // UNKNOWN_102 102 - not implemented
    L102:
    // END_BLOCK
    // UNKNOWN_102 102 - not implemented
    L102:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_59 59 - not implemented
    L59:
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_47 47 - not implemented
    L47:
    L15:
    bcpl_locals[123] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L142; // JUMP
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_66 66 - not implemented
    L66:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_75 75 - not implemented
    L75:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_66 66 - not implemented
    L66:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L47; } // BRANCH_IF_LT
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    L47:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    goto L76; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // LOCAL_VAR allocation
    bcpl_locals[47] = bcpl_pop(); // STORE_LOCAL
    // LOCAL_VAR allocation
    bcpl_locals[86] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_47 47 - not implemented
    L47:
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_47 47 - not implemented
    L47:
    // TEMP_VAR allocation
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_71 71 - not implemented
    L71:
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_71 71 - not implemented
    L71:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_73 73 - not implemented
    L73:
    // TEMP_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    if (bcpl_pop()) goto L47; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    L71:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_47 47 - not implemented
    L47:
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_73 73 - not implemented
    L73:
    // TEMP_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_47 47 - not implemented
    L47:
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L171; // JUMP
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_73 73 - not implemented
    L73:
    // TEMP_VAR allocation
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_78 78 - not implemented
    L78:
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    bcpl_locals[86] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_47 47 - not implemented
    L47:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L76; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    goto L82; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_73 73 - not implemented
    L73:
    // TEMP_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    if (bcpl_pop()) goto L47; // CONDITIONAL_JUMP
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    L80:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    L80:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L72; } // BRANCH_IF_NEQ
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    L80:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    goto L78; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    goto L69; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_72 72 - not implemented
    L72:
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    goto L78; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // UNKNOWN_47 47 - not implemented
    L47:
    goto L78; // CALL_FUNCTION (as GOTO)
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_47 47 - not implemented
    L47:
    if (bcpl_pop()) goto L69; // CONDITIONAL_JUMP
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_47 47 - not implemented
    L47:
    if (bcpl_pop()) goto L65; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L72; } // BRANCH_IF_NEQ
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_36 36 - not implemented
    L36:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_47 47 - not implemented
    L47:
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_locals[134] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 1
    L3:
    bcpl_pop(); // POP
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L16; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(85); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19; } // BRANCH_IF_NEQ
    return; // RETURN
    goto L19; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_locals[107] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(123); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(123); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[123] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L18; // CALL_FUNCTION (as GOTO)
    goto L17; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L18; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L16; // CALL_FUNCTION (as GOTO)
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_125 125 - not implemented
    L125:
    L1:
    // UNKNOWN_121 121 - not implemented
    L121:
    L2:
    // FUNCTION_HEADER - 4 parameters
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L51; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L8
    // LOOP_END L7
    // LOOP_START L11
    // LOOP_END L10
    goto L12; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 3
    L1:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(13); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(110); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_21 21 - not implemented
    L21:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(196); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(111); // LOAD_CONSTANT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L14; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L5; // JUMP
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_52 52 - not implemented
    L52:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_locals[111] = bcpl_pop(); // STORE_LOCAL
    goto L14; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L13; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(132); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[132] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(132); // LOAD_CONSTANT
    // UNKNOWN_33 33 - not implemented
    L33:
    bcpl_push(100); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82; } // BRANCH_IF_NEQ
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_66 66 - not implemented
    L66:
    goto L70; // CALL_FUNCTION (as GOTO)
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L4; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_46 46 - not implemented
    L46:
    // UNKNOWN_46 46 - not implemented
    L46:
    // UNKNOWN_46 46 - not implemented
    L46:
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(132); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(132); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L15; // CALL_FUNCTION (as GOTO)
    goto L16; // GOTO
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_33 33 - not implemented
    L33:
    bcpl_push(100); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L17; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L17; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L15; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L16; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L3:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_71 71 - not implemented
    L71:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(92); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L18; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(65)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L20; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    if (bcpl_pop()) goto L19; // CONDITIONAL_JUMP
    goto L20; // GOTO
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    if (bcpl_pop()) goto L19; // CONDITIONAL_JUMP
    goto L21; // GOTO
    bcpl_push(bcpl_load_indirect(46)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L19; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(95)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L19; // CONDITIONAL_JUMP
    goto L22; // CALL_FUNCTION (as GOTO)
    goto L19; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(109); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L18; // CALL_FUNCTION (as GOTO)
    goto L22; // GOTO
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_locals[107] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L4:
    // UNKNOWN_80 80 - not implemented
    L80:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 2
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[114] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_30 30 - not implemented
    L30:
    bcpl_locals[114] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L23; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L23; // GOTO
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[104] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(42); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L24; } // BRANCH_IF_NEQ
    // LOOP_START L26
    // LOOP_END L25
    // JUMP_IF_NOT_ZERO 45 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L21; // JUMP
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_117 117 - not implemented
    L117:
    // UNKNOWN_115 115 - not implemented
    L115:
    // UNKNOWN_114 114 - not implemented
    L114:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_108 108 - not implemented
    L108:
    // UNKNOWN_111 111 - not implemented
    L111:
    // UNKNOWN_99 99 - not implemented
    L99:
    return; // RETURN
    // UNKNOWN_108 108 - not implemented
    L108:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_108 108 - not implemented
    L108:
    // UNKNOWN_105 105 - not implemented
    L105:
    // UNKNOWN_98 98 - not implemented
    L98:
    // UNKNOWN_47 47 - not implemented
    L47:
    // UNKNOWN_111 111 - not implemented
    L111:
    // UNKNOWN_98 98 - not implemented
    L98:
    // UNKNOWN_99 99 - not implemented
    L99:
    // UNKNOWN_112 112 - not implemented
    L112:
    // UNKNOWN_108 108 - not implemented
    L108:
    // UNKNOWN_47 47 - not implemented
    L47:
    goto L27; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 6
    L25:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_80 80 - not implemented
    L80:
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // FUNCTION_END 4
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    L120:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    L120:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L28; // CALL_FUNCTION (as GOTO)
    goto L29; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_120 120 - not implemented
    L120:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_121 121 - not implemented
    L121:
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L28; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L29; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_121 121 - not implemented
    L121:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L27; // GOTO
    bcpl_push(bcpl_globals[68]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    L120:
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    L120:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_load_indirect(255)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_121 121 - not implemented
    L121:
    bcpl_push(bcpl_globals[70]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 68]); // DUPLICATE
    bcpl_push(bcpl_globals[70]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(106); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 68]); // DUPLICATE
    bcpl_push(bcpl_globals[70]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(42); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_pop(); // POP
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    goto L30; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L24; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31; } // BRANCH_IF_NEQ
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[104] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(96)); // LOAD_INDIRECT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L32; // CALL_FUNCTION (as GOTO)
    goto L31; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L32; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L5:
    // TEMP_VAR allocation
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L6:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_78 78 - not implemented
    L78:
    goto L77; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_66 66 - not implemented
    L66:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[101] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L33; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L33; // GOTO
    goto L34; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L35; } // BRANCH_IF_NEQ
    return; // RETURN
    goto L35; // GOTO
    bcpl_push(101); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[101] = bcpl_pop(); // STORE_LOCAL
    goto L34; // CALL_FUNCTION (as GOTO)
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L7:
    if (bcpl_pop()) goto L65; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    goto L69; // CALL_FUNCTION (as GOTO)
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    // UNKNOWN_98 98 - not implemented
    L98:
    L36:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L37; // GOTO
    bcpl_push(bcpl_load_indirect(65)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(70)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(65)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_98 98 - not implemented
    L98:
    L38:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L39; // GOTO
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L41; // GOTO
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    goto L40; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L38:
    goto L38; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L36:
    goto L36; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L9:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // FUNCTION_END 2
    // LOOP_START L43
    // LOOP_END L42
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L42; } // BRANCH_IF_LT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L45; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L45; // GOTO
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L46; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L48; } // BRANCH_IF_NEQ
    goto L49; // GOTO
    goto L50; // GOTO
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L51; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    goto L51; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L50; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L50; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L50; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L52; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L52; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    // JUMP_IF_ZERO 44 - not implemented
    L43:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L48; // GOTO
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(84)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L53; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L53; // GOTO
    bcpl_push(bcpl_load_indirect(83)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L54; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L54; // GOTO
    bcpl_push(bcpl_load_indirect(78)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L55; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L55; // GOTO
    bcpl_push(bcpl_load_indirect(69)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L56; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(69)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L56; // GOTO
    bcpl_push(bcpl_load_indirect(66)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L57; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L57; // GOTO
    bcpl_push(bcpl_load_indirect(80)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(12)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L58; // GOTO
    bcpl_push(bcpl_load_indirect(67)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L59; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(13)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L59; // GOTO
    bcpl_push(bcpl_load_indirect(88)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L60; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 - not implemented
    L11:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L60; // GOTO
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L61; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L61; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(64)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 - not implemented
    L11:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(255)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L62; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L62; // GOTO
    goto L61; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L47; // CALL_FUNCTION (as GOTO)
    goto L46; // GOTO
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L63; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    goto L63; // GOTO
    goto L47; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L44:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L44; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 14
    L10:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_72 72 - not implemented
    L72:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L95; } // BRANCH_IF_EQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L65; // CALL_FUNCTION (as GOTO)
    goto L66; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L98:
    L67:
    goto L67; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L68; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    goto L68; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L65; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L66; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L64:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L64; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L12; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_7 7 - not implemented
    L7:
    // UNKNOWN_126 126 - not implemented
    L126:
    L1:
    // UNKNOWN_131 131 - not implemented
    L131:
    L2:
    // UNKNOWN_118 118 - not implemented
    L118:
    L3:
    // UNKNOWN_119 119 - not implemented
    L119:
    L4:
    // UNKNOWN_197 197 - not implemented
    L5:
    // UNKNOWN_112 112 - not implemented
    L112:
    L6:
    // UNKNOWN_113 113 - not implemented
    L113:
    L9:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_48 48 - not implemented
    L48:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L11
    // LOOP_END L10
    goto L12; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 6
    L1:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L86; } // BRANCH_IF_NEQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // FUNCTION_END 3
    bcpl_push(168); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[168] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(168); // LOAD_CONSTANT
    bcpl_push(169); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L14; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[192] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(98)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L14; // GOTO
    bcpl_push(168); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L98:
    L13:
    goto L13; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L2:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_HEADER - 95 parameters
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L15:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L15; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L3:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_50 50 - not implemented
    L50:
    // FUNCTION_END 4
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L16:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L16; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L4:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 95]); // DUPLICATE
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L17:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L17; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L5:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_52 52 - not implemented
    L52:
    // FUNCTION_END 6
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L18:
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L18; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L6:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_53 53 - not implemented
    L53:
    // FUNCTION_END 7
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L19:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    goto L19; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_7 7 - not implemented
    L7:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L7:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_54 54 - not implemented
    L54:
    // FUNCTION_END 8
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L20:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L20; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L8:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    // FUNCTION_END 2
    // JUMP_IF_NOT_ZERO 45 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[67]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[100] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L22; // CALL_FUNCTION (as GOTO)
    goto L23; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_push(100); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_67 67 - not implemented
    L67:
    goto L22; // GOTO
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L23; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[67]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[132] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    bcpl_pop(); // POP
    bcpl_push(bcpl_globals[89]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_locals[103] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[104] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_locals[105] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[91]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 89]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L24; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L21:
    goto L24; // GOTO
    // JUMP_IF_NOT_ZERO 45 - not implemented
    goto L91; // GOTO
    // UNKNOWN_219 219 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[89]); // LOAD_LOCAL
    bcpl_locals[106] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_220 220 - not implemented
    bcpl_push(bcpl_globals[477]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[219]); // LOAD_LOCAL
    bcpl_locals[108] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_478 478 - not implemented
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L26
    // LOOP_END L25
    bcpl_push(bcpl_locals[477]); // LOAD_LOCAL
    bcpl_locals[148] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L27; // CALL_FUNCTION (as GOTO)
    goto L28; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_579 579 - not implemented
    goto L27; // GOTO
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[580]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L28; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(121); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 579]); // DUPLICATE
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L25; } // BRANCH_IF_LT
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 579]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    goto L7; // JUMP
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_73 73 - not implemented
    L73:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 32]); // DUPLICATE
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 579]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L21:
    goto L30; // GOTO
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L29; // GOTO
    // LOOP_START L32
    // LOOP_END L31
    goto L33; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 5
    L31:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    L71:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(174); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L35; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(95)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L35; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 - not implemented
    L32:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L98:
    L36:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L37; // GOTO
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L98:
    L36:
    goto L36; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L34:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L34; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    goto L33; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(49)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(49)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 - not implemented
    L32:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L98:
    L38:
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    goto L39; // GOTO
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 - not implemented
    L32:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    goto L41; // GOTO
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    goto L40; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L98:
    L38:
    goto L38; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_579 579 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[582]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(99)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 580]); // DUPLICATE
    goto L42; // GOTO
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L21:
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[477]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[219]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[89]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[67]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L21; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L9:
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    L80:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 4
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[191] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L29; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L32; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_58 58 - not implemented
    L58:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L11:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(131); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(191); // LOAD_CONSTANT
    bcpl_push(192); // LOAD_CONSTANT
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L43; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L21; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L43; // GOTO
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[122] = bcpl_pop(); // STORE_LOCAL
    goto L45; // CALL_FUNCTION (as GOTO)
    goto L44; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L45; // GOTO
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(74)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46; // CONDITIONAL_JUMP
    bcpl_push(122); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L44; } // BRANCH_IF_NEQ
    goto L46; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(135); // LOAD_CONSTANT
    bcpl_push(136); // LOAD_CONSTANT
    bcpl_push(32); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L10:
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // FUNCTION_END 4
    goto L48; // CALL_FUNCTION (as GOTO)
    goto L50; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L8; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L51; // GOTO
    goto L18; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_36 36 - not implemented
    L36:
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L84; } // BRANCH_IF_EQ
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L52; // GOTO
    goto L17; // JUMP
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L53; // GOTO
    goto L16; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L54; // GOTO
    goto L11; // JUMP
    // UNKNOWN_78 78 - not implemented
    L78:
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_80 80 - not implemented
    L80:
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L55; // GOTO
    goto L17; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    if (bcpl_pop()) goto L69; // CONDITIONAL_JUMP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L56; // GOTO
    goto L17; // JUMP
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    L32:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L57; // GOTO
    goto L21; // JUMP
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L58; // GOTO
    goto L59; // GOTO
    goto L60; // GOTO
    goto L13; // JUMP
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L61; // GOTO
    goto L13; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_36 36 - not implemented
    L36:
    bcpl_push(bcpl_locals[39]); // LOAD_LOCAL
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L62; // GOTO
    goto L13; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_36 36 - not implemented
    L36:
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L63; // GOTO
    goto L22; // JUMP
    goto L78; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_36 36 - not implemented
    L36:
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L64; // GOTO
    goto L19; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L65; // GOTO
    goto L10; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_78 78 - not implemented
    L78:
    goto L77; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_66 66 - not implemented
    L66:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L66; // GOTO
    goto L32; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L67; // GOTO
    goto L68; // GOTO
    goto L69; // GOTO
    goto L11; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L70; // GOTO
    goto L26; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L71; // GOTO
    goto L21; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    L67:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    goto L82; // CALL_FUNCTION (as GOTO)
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_72 72 - not implemented
    L72:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L72; // GOTO
    goto L73; // GOTO
    goto L15; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L74; // GOTO
    goto L14; // JUMP
    goto L78; // CALL_FUNCTION (as GOTO)
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_58 58 - not implemented
    L58:
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L75; // GOTO
    goto L16; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L76; // GOTO
    goto L15; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L77; // GOTO
    goto L78; // GOTO
    goto L12; // JUMP
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L79; // GOTO
    goto L15; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L80; // GOTO
    goto L81; // GOTO
    goto L12; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_58 58 - not implemented
    L58:
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L82; // GOTO
    goto L12; // JUMP
    // UNKNOWN_39 39 - not implemented
    L39:
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    // UNKNOWN_39 39 - not implemented
    L39:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_98 98 - not implemented
    L98:
    L47:
    goto L49; // CALL_FUNCTION (as GOTO)
    goto L48; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    L50:
    bcpl_push(bcpl_globals[L51]); // LOAD_GLOBAL
    // FUNCTION_START L52
    // FUNCTION_END L53
    // UNKNOWN_96 96 - not implemented
    L96:
    L54:
    return; // RETURN
    L55:
    // UNKNOWN_98 98 - not implemented
    L98:
    L56:
    // UNKNOWN_99 99 - not implemented
    L99:
    L57:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L58:
    bcpl_push(bcpl_locals[L59]); // LOAD_LOCAL
    goto L60; // JUMP
    bcpl_push(bcpl_rdline()); // READ_LINE
    L61:
    // UNKNOWN_7 7 - not implemented
    L7:
    L62:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L63:
    // UNKNOWN_32 32 - not implemented
    L32:
    L64:
    // UNKNOWN_33 33 - not implemented
    L33:
    L65:
    // UNKNOWN_34 34 - not implemented
    L34:
    L66:
    bcpl_push(-bcpl_pop()); // NEGATE
    L67:
    // UNKNOWN_19 19 - not implemented
    L19:
    L68:
    bcpl_push(L69); // LOAD_CONSTANT
    // UNKNOWN_30 30 - not implemented
    L30:
    L70:
    bcpl_push(bcpl_load_indirect(L71)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 - not implemented
    L72:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L73:
    // UNKNOWN_50 50 - not implemented
    L50:
    L74:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L75]); // DUPLICATE
    // UNKNOWN_54 54 - not implemented
    L54:
    L76:
    // UNKNOWN_57 57 - not implemented
    L57:
    L77:
    // UNKNOWN_58 58 - not implemented
    L58:
    L78:
    // UNKNOWN_60 60 - not implemented
    L60:
    L79:
    // UNKNOWN_61 61 - not implemented
    L61:
    L80:
    // UNKNOWN_62 62 - not implemented
    L62:
    L81:
    // UNKNOWN_63 63 - not implemented
    L63:
    L82:
    goto L49; // GOTO
    goto L47; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L12; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_167 167 - not implemented
    L1:
    // UNKNOWN_161 161 - not implemented
    L2:
    // UNKNOWN_162 162 - not implemented
    L3:
    // UNKNOWN_163 163 - not implemented
    L4:
    // UNKNOWN_164 164 - not implemented
    L5:
    // UNKNOWN_165 165 - not implemented
    L6:
    // UNKNOWN_166 166 - not implemented
    L7:
    // UNKNOWN_150 150 - not implemented
    L8:
    // UNKNOWN_151 151 - not implemented
    L9:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // FUNCTION_HEADER - 91 parameters
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L9; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 11
    L1:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_66 66 - not implemented
    L66:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_75 75 - not implemented
    L75:
    // UNKNOWN_66 66 - not implemented
    L66:
    // PUSH_STRING - string handling
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L95; } // BRANCH_IF_LT
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(135); // LOAD_CONSTANT
    bcpl_push(136); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L12
    // LOOP_END L11
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L13; // CALL_FUNCTION (as GOTO)
    goto L15; // GOTO
    goto L16; // GOTO
    goto L17; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(147); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L14; // CALL_FUNCTION (as GOTO)
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L18; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(145); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L11; } // BRANCH_IF_LT
    goto L20; // CALL_FUNCTION (as GOTO)
    goto L19; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(145); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L20; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L19; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(74)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L14; // CALL_FUNCTION (as GOTO)
    goto L21; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L22; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L22; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L22; // GOTO
    goto L23; // GOTO
    goto L24; // GOTO
    goto L14; // CALL_FUNCTION (as GOTO)
    goto L13; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdline()); // READ_LINE
    L21:
    // UNKNOWN_75 75 - not implemented
    L75:
    L15:
    // PUSH_STRING - string handling
    L16:
    // STRING_CONSTANT definition
    L17:
    // UNKNOWN_74 74 - not implemented
    L74:
    L18:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    L23:
    goto L24; // GOTO
    goto L14; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L10:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L10; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L2:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    bcpl_locals[95] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L27; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26; } // BRANCH_IF_NEQ
    goto L27; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L25:
    goto L26; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(73)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L25:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L25; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L3:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_67 67 - not implemented
    L67:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(135); // LOAD_CONSTANT
    bcpl_push(136); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L30
    // LOOP_END L29
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L30:
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    goto L31; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L34; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L32; } // BRANCH_IF_NEQ
    goto L34; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L33; // CALL_FUNCTION (as GOTO)
    goto L32; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L33; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(43)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[14]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    bcpl_push(164); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L29; } // BRANCH_IF_LT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L31; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L28:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L28; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L4:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 3
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(6)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L36; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(7)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L36; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L38; // CALL_FUNCTION (as GOTO)
    goto L37; // GOTO
    bcpl_push(134); // LOAD_CONSTANT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L39; // GOTO
    goto L38; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L35:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L35; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L5:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L41; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    goto L41; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L40; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L6:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // FUNCTION_END 2
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L42:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L42; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L7:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_78 78 - not implemented
    L78:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L43; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L43; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L8:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_75 75 - not implemented
    L75:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // FUNCTION_END 4
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L44; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L44; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L9; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_140 140 - not implemented
    L1:
    // UNKNOWN_156 156 - not implemented
    L2:
    // UNKNOWN_147 147 - not implemented
    L3:
    // UNKNOWN_141 141 - not implemented
    L4:
    // UNKNOWN_142 142 - not implemented
    L142:
    L5:
    // UNKNOWN_143 143 - not implemented
    L6:
    // UNKNOWN_154 154 - not implemented
    L7:
    // UNKNOWN_153 153 - not implemented
    L8:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_50 50 - not implemented
    L50:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L3; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 5
    L1:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_66 66 - not implemented
    L66:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L5; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L8; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_push(161); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L9; // GOTO
    goto L10; // GOTO
    goto L11; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L12; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L13; // CALL_FUNCTION (as GOTO)
    goto L14; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(106); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L13; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L14; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L15; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(101); // LOAD_CONSTANT
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L16; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(15)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L17; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(6)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L18; // GOTO
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L19; // GOTO
    goto L20; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(37)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L21; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L22; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L23; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_17 17 - not implemented
    L17:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L24; // CALL_FUNCTION (as GOTO)
    goto L23; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(17)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L24; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L25; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(24)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L26; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(19)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(35)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L27; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(39)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L4:
    goto L6; // CALL_FUNCTION (as GOTO)
    goto L5; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_16 16 - not implemented
    L16:
    L7:
    // UNKNOWN_16 16 - not implemented
    L16:
    L8:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L9:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L10:
    // UNKNOWN_2 2 - not implemented
    L2:
    L11:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L12:
    // UNKNOWN_1 1 - not implemented
    L1:
    L15:
    // UNKNOWN_105 105 - not implemented
    L105:
    L16:
    bcpl_push(bcpl_rdline()); // READ_LINE
    L17:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L18:
    // UNKNOWN_7 7 - not implemented
    L7:
    L19:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L20:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L21:
    bcpl_push(-bcpl_pop()); // NEGATE
    L22:
    // UNKNOWN_30 30 - not implemented
    L30:
    L25:
    // UNKNOWN_19 19 - not implemented
    L19:
    L26:
    // UNKNOWN_39 39 - not implemented
    L39:
    L27:
    goto L6; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L2:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(174); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L29; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L31
    // LOOP_END L30
    // LOOP_START L33
    // LOOP_END L32
    bcpl_push(122); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L34; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L28:
    goto L34; // GOTO
    goto L35; // CALL_FUNCTION (as GOTO)
    goto L37; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L28:
    goto L38; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L39; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L39; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(19)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29; // CALL_FUNCTION (as GOTO)
    goto L40; // GOTO
    bcpl_push(bcpl_load_indirect(36)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L41; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L42; // GOTO
    goto L43; // GOTO
    goto L44; // GOTO
    bcpl_push(bcpl_load_indirect(35)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L45; // GOTO
    goto L46; // GOTO
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L47; // GOTO
    goto L48; // GOTO
    goto L49; // GOTO
    goto L50; // GOTO
    goto L51; // GOTO
    goto L52; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L53; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L28:
    goto L53; // GOTO
    goto L54; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L55; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L56; // CALL_FUNCTION (as GOTO)
    goto L55; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L56; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    L24:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L57; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(25)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    L24:
    if (bcpl_pop()) goto L54; // CONDITIONAL_JUMP
    goto L57; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29; // CALL_FUNCTION (as GOTO)
    goto L58; // GOTO
    goto L59; // GOTO
    bcpl_push(bcpl_load_indirect(25)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_7 7 - not implemented
    L7:
    // JUMP_IF_ZERO 44 - not implemented
    L31:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L60; // GOTO
    bcpl_push(bcpl_load_indirect(23)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L61; // GOTO
    bcpl_push(bcpl_load_indirect(22)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L62; // GOTO
    goto L63; // GOTO
    bcpl_push(bcpl_load_indirect(21)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L64; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(13)); // LOAD_INDIRECT
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L65; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L28:
    goto L65; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(37)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[16]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(164); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29; // CALL_FUNCTION (as GOTO)
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32; } // BRANCH_IF_LT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_7 7 - not implemented
    L7:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L30; } // BRANCH_IF_LT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L66; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L28:
    goto L66; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_13 13 - not implemented
    L13:
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29; // CALL_FUNCTION (as GOTO)
    goto L36; // CALL_FUNCTION (as GOTO)
    goto L35; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_21 21 - not implemented
    L21:
    L37:
    // UNKNOWN_105 105 - not implemented
    L105:
    L38:
    // UNKNOWN_28 28 - not implemented
    L28:
    L40:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L41:
    // UNKNOWN_13 13 - not implemented
    L13:
    L42:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L43:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L44:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L45:
    bcpl_push(-bcpl_pop()); // NEGATE
    L46:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L47:
    // UNKNOWN_21 21 - not implemented
    L21:
    L48:
    // UNKNOWN_24 24 - not implemented
    L24:
    L49:
    // UNKNOWN_25 25 - not implemented
    L25:
    L50:
    // UNKNOWN_22 22 - not implemented
    L22:
    L51:
    // UNKNOWN_23 23 - not implemented
    L23:
    L52:
    // UNKNOWN_31 31 - not implemented
    L31:
    L58:
    // UNKNOWN_32 32 - not implemented
    L32:
    L59:
    // UNKNOWN_33 33 - not implemented
    L33:
    L60:
    // UNKNOWN_34 34 - not implemented
    L34:
    L61:
    // UNKNOWN_35 35 - not implemented
    L35:
    L62:
    // UNKNOWN_36 36 - not implemented
    L36:
    L63:
    // UNKNOWN_37 37 - not implemented
    L37:
    L64:
    goto L36; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L29; // CALL_FUNCTION (as GOTO)
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L28; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L3; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L68; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 8
    L67:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L70; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L71; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L69:
    goto L71; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L70; // CALL_FUNCTION (as GOTO)
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L69; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L68; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L73; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 4
    L72:
    // UNKNOWN_82 82 - not implemented
    L82:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L75; // CALL_FUNCTION (as GOTO)
    goto L77; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L78; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L78; // GOTO
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L79; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(89)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L80; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(165); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L74:
    goto L80; // GOTO
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L81; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(165); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L74:
    goto L81; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L82; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L83; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(103)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L84; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L85; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(43)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L85; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L74:
    goto L84; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L74:
    goto L76; // CALL_FUNCTION (as GOTO)
    goto L75; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_2 2 - not implemented
    L2:
    L82:
    // UNKNOWN_105 105 - not implemented
    L105:
    L77:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L83:
    goto L76; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L74; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L73; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_174 174 - not implemented
    L1:
    // UNKNOWN_144 144 - not implemented
    L2:
    // UNKNOWN_155 155 - not implemented
    L67:
    // UNKNOWN_145 145 - not implemented
    L72:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_52 52 - not implemented
    L52:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L2
    // LOOP_END L1
    goto L4; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 5
    L1:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L6; // CALL_FUNCTION (as GOTO)
    goto L8; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L9; // GOTO
    goto L10; // GOTO
    goto L11; // GOTO
    goto L12; // GOTO
    goto L13; // GOTO
    goto L14; // GOTO
    goto L15; // GOTO
    goto L16; // GOTO
    goto L17; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_load_indirect(50)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L18; } // BRANCH_IF_NEQ
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L18; // GOTO
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L20; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(50)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L20; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(164); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L19; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L21; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L22; // GOTO
    goto L23; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L24; // GOTO
    goto L25; // GOTO
    goto L26; // GOTO
    goto L27; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L28; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(55)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(164); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L29; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(99)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(58)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_7 7 - not implemented
    L7:
    goto L30; // GOTO
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(56)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[17]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(166); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L31; // GOTO
    goto L32; // GOTO
    goto L33; // GOTO
    goto L34; // GOTO
    goto L35; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L36; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(98)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(60)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(70)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L37; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(71)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L38; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(72)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L39; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L7; // CALL_FUNCTION (as GOTO)
    goto L6; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_26 26 - not implemented
    L26:
    L8:
    // UNKNOWN_2 2 - not implemented
    L2:
    L9:
    // UNKNOWN_1 1 - not implemented
    L1:
    L10:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L11:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L12:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L13:
    // UNKNOWN_7 7 - not implemented
    L7:
    L14:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L15:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L16:
    // UNKNOWN_105 105 - not implemented
    L105:
    L17:
    // UNKNOWN_52 52 - not implemented
    L52:
    L22:
    // UNKNOWN_53 53 - not implemented
    L53:
    L23:
    // UNKNOWN_57 57 - not implemented
    L57:
    L24:
    // UNKNOWN_58 58 - not implemented
    L58:
    L25:
    // UNKNOWN_59 59 - not implemented
    L59:
    L26:
    // UNKNOWN_60 60 - not implemented
    L60:
    L27:
    // UNKNOWN_55 55 - not implemented
    L55:
    L28:
    // UNKNOWN_56 56 - not implemented
    L56:
    L29:
    // UNKNOWN_65 65 - not implemented
    L65:
    L31:
    // UNKNOWN_66 66 - not implemented
    L66:
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    L33:
    bcpl_pop(); // POP
    L34:
    // LOCAL_VAR allocation
    L35:
    // TEMP_VAR allocation
    L36:
    // UNKNOWN_71 71 - not implemented
    L71:
    L37:
    // UNKNOWN_72 72 - not implemented
    L72:
    L38:
    bcpl_push(bcpl_globals[L39]); // LOAD_GLOBAL
    goto L7; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L3:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    L2:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L41; // GOTO
    goto L43; // CALL_FUNCTION (as GOTO)
    goto L42; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L44; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L45; // CALL_FUNCTION (as GOTO)
    goto L44; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L45; // GOTO
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L43; // GOTO
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L40:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L40; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    L1:
    // UNKNOWN_146 146 - not implemented
    L3:
    // FUNCTION_HEADER - 5 parameters
    // UNKNOWN_80 80 - not implemented
    L80:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 5
    L1:
    // UNKNOWN_80 80 - not implemented
    L80:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 5
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L3
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    L102:
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_47 47 - not implemented
    L47:
    L3:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L4; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L3; // JUMP
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L4; // GOTO
    goto L5; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(62); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L8; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L9; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L4; // JUMP
    // UNKNOWN_34 34 - not implemented
    L34:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_34 34 - not implemented
    L34:
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L10; // GOTO
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L11; // GOTO
    goto L12; // GOTO
    goto L13; // GOTO
    goto L14; // GOTO
    goto L15; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L16; // GOTO
    goto L17; // GOTO
    goto L18; // GOTO
    goto L19; // GOTO
    goto L20; // GOTO
    goto L21; // GOTO
    goto L22; // GOTO
    goto L23; // GOTO
    goto L24; // GOTO
    goto L25; // GOTO
    goto L26; // GOTO
    goto L27; // GOTO
    goto L28; // GOTO
    goto L29; // GOTO
    goto L30; // GOTO
    goto L31; // GOTO
    goto L32; // GOTO
    goto L33; // GOTO
    goto L34; // GOTO
    goto L35; // GOTO
    goto L36; // GOTO
    goto L37; // GOTO
    goto L38; // GOTO
    goto L39; // GOTO
    goto L40; // GOTO
    goto L41; // GOTO
    goto L42; // GOTO
    goto L43; // GOTO
    goto L44; // GOTO
    goto L45; // GOTO
    goto L46; // GOTO
    goto L47; // GOTO
    goto L48; // GOTO
    goto L49; // GOTO
    goto L50; // GOTO
    goto L51; // GOTO
    goto L52; // GOTO
    goto L53; // GOTO
    goto L54; // GOTO
    goto L55; // GOTO
    goto L56; // GOTO
    goto L57; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L58; // GOTO
    goto L59; // GOTO
    goto L60; // GOTO
    goto L61; // GOTO
    goto L62; // GOTO
    goto L63; // GOTO
    goto L64; // GOTO
    goto L65; // GOTO
    goto L66; // GOTO
    goto L67; // GOTO
    goto L68; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L69; // GOTO
    goto L70; // GOTO
    goto L71; // GOTO
    goto L72; // GOTO
    goto L73; // GOTO
    goto L74; // GOTO
    goto L75; // GOTO
    goto L76; // GOTO
    goto L77; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L78; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L3; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_67 67 - not implemented
    L67:
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L78; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L2; // JUMP
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(62); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L79; // CALL_FUNCTION (as GOTO)
    goto L80; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L81; // CALL_FUNCTION (as GOTO)
    goto L82; // GOTO
    bcpl_push(bcpl_globals[13]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 11]); // DUPLICATE
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    goto L81; // GOTO
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[10]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L82; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    goto L2; // JUMP
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L84; } // BRANCH_IF_NEQ
    goto L2; // JUMP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_98 98 - not implemented
    L98:
    L83:
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L84; // GOTO
    goto L2; // JUMP
    // UNKNOWN_33 33 - not implemented
    L33:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_98 98 - not implemented
    L98:
    L83:
    goto L83; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(152); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_7 7 - not implemented
    L7:
    goto L79; // GOTO
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    return; // RETURN
    goto L6; // CALL_FUNCTION (as GOTO)
    goto L5; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // TEMP_VAR allocation
    L77:
    // UNKNOWN_1 1 - not implemented
    L1:
    L7:
    // UNKNOWN_2 2 - not implemented
    L2:
    L8:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L9:
    // UNKNOWN_56 56 - not implemented
    L56:
    L10:
    // UNKNOWN_37 37 - not implemented
    L37:
    L11:
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L13:
    // UNKNOWN_55 55 - not implemented
    L55:
    L14:
    goto L15; // JUMP
    // UNKNOWN_48 48 - not implemented
    L48:
    L16:
    // FUNCTION_HEADER - L17 parameters
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L18:
    // UNKNOWN_28 28 - not implemented
    L28:
    L19:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    L20:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L21:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L22:
    // UNKNOWN_13 13 - not implemented
    L13:
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L24:
    bcpl_push(-bcpl_pop()); // NEGATE
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L26:
    // UNKNOWN_21 21 - not implemented
    L21:
    L27:
    // UNKNOWN_22 22 - not implemented
    L22:
    L28:
    // UNKNOWN_23 23 - not implemented
    L23:
    L29:
    // UNKNOWN_24 24 - not implemented
    L24:
    L30:
    // UNKNOWN_25 25 - not implemented
    L25:
    L31:
    // UNKNOWN_31 31 - not implemented
    L31:
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    L33:
    // UNKNOWN_33 33 - not implemented
    L33:
    L34:
    // UNKNOWN_34 34 - not implemented
    L34:
    L35:
    // UNKNOWN_35 35 - not implemented
    L35:
    L36:
    // UNKNOWN_36 36 - not implemented
    L36:
    L37:
    // UNKNOWN_38 38 - not implemented
    L38:
    L38:
    bcpl_push(bcpl_locals[L39]); // LOAD_LOCAL
    bcpl_push(L40); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(L41)); // LOAD_INDIRECT
    // UNKNOWN_50 50 - not implemented
    L50:
    L42:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L43]); // DUPLICATE
    // UNKNOWN_54 54 - not implemented
    L54:
    L44:
    // UNKNOWN_57 57 - not implemented
    L57:
    L45:
    // UNKNOWN_58 58 - not implemented
    L58:
    L46:
    // UNKNOWN_59 59 - not implemented
    L59:
    L47:
    // UNKNOWN_60 60 - not implemented
    L60:
    L48:
    // UNKNOWN_62 62 - not implemented
    L62:
    L49:
    // UNKNOWN_63 63 - not implemented
    L63:
    L50:
    // TEMP_VAR allocation
    L51:
    // UNKNOWN_71 71 - not implemented
    L71:
    L52:
    // UNKNOWN_73 73 - not implemented
    L73:
    L53:
    // UNKNOWN_74 74 - not implemented
    L74:
    L54:
    // UNKNOWN_75 75 - not implemented
    L75:
    L55:
    // PUSH_STRING - string handling
    L56:
    // STRING_CONSTANT definition
    L57:
    bcpl_push(bcpl_rdline()); // READ_LINE
    L58:
    // UNKNOWN_7 7 - not implemented
    L7:
    L59:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L60:
    // UNKNOWN_17 17 - not implemented
    L17:
    L61:
    // UNKNOWN_30 30 - not implemented
    L30:
    L62:
    // UNKNOWN_39 39 - not implemented
    L39:
    L63:
    // UNKNOWN_52 52 - not implemented
    L52:
    L64:
    // UNKNOWN_53 53 - not implemented
    L53:
    L65:
    // UNKNOWN_61 61 - not implemented
    L61:
    L66:
    // UNKNOWN_72 72 - not implemented
    L72:
    L67:
    // UNKNOWN_19 19 - not implemented
    L19:
    L68:
    // UNKNOWN_65 65 - not implemented
    L65:
    L69:
    // UNKNOWN_66 66 - not implemented
    L66:
    L70:
    // UNKNOWN_67 67 - not implemented
    L67:
    L71:
    bcpl_pop(); // POP
    L72:
    // LOCAL_VAR allocation
    L73:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L74:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L75:
    // UNKNOWN_16 16 - not implemented
    L16:
    L76:
    goto L6; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    L1:
    // UNKNOWN_152 152 - not implemented
    L1:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_48 48 - not implemented
    L48:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L4
    // LOOP_END L3
    goto L5; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 9
    L1:
    // UNKNOWN_78 78 - not implemented
    L78:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L84; } // BRANCH_IF_EQ
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(244); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[244] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(244); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L98:
    L6:
    goto L6; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    // UNKNOWN_2 2 - not implemented
    L2:
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 11
    L2:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    L80:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 4
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[191] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(191); // LOAD_CONSTANT
    bcpl_push(192); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L7; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L21; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L7; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L11; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    L80:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_58 58 - not implemented
    L58:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L22; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_78 78 - not implemented
    L78:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(288); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(152); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(195); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L3:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_71 71 - not implemented
    L71:
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    goto L9; // CALL_FUNCTION (as GOTO)
    goto L11; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L18; // JUMP
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_37 37 - not implemented
    L37:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L12; // GOTO
    goto L14; // JUMP
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32; } // BRANCH_IF_LT
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L13; // GOTO
    goto L38; // JUMP
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    L32:
    goto L83; // CALL_FUNCTION (as GOTO)
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_75 75 - not implemented
    L75:
    // JUMP_IF_ZERO 44 - not implemented
    // UNKNOWN_32 32 - not implemented
    L32:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    goto L76; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L14; // GOTO
    goto L15; // GOTO
    goto L30; // JUMP
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    L32:
    goto L83; // CALL_FUNCTION (as GOTO)
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    goto L76; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L16; // GOTO
    goto L28; // JUMP
    // UNKNOWN_84 84 - not implemented
    L84:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79; } // BRANCH_IF_NEQ
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_32 32 - not implemented
    L32:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L17; // GOTO
    goto L16; // JUMP
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32; } // BRANCH_IF_LT
    // UNKNOWN_71 71 - not implemented
    L71:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_66 66 - not implemented
    L66:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L18; // GOTO
    goto L19; // JUMP
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_84 84 - not implemented
    L84:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73; } // BRANCH_IF_NEQ
    // UNKNOWN_67 67 - not implemented
    L67:
    // LOCAL_VAR allocation
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L19; // GOTO
    goto L23; // JUMP
    // UNKNOWN_84 84 - not implemented
    L84:
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32; } // BRANCH_IF_LT
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L20; // GOTO
    goto L17; // JUMP
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_78 78 - not implemented
    L78:
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L21; // GOTO
    goto L26; // JUMP
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_32 32 - not implemented
    L32:
    // TEMP_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    if (bcpl_pop()) goto L65; // CONDITIONAL_JUMP
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    goto L83; // CALL_FUNCTION (as GOTO)
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L22; // GOTO
    goto L23; // GOTO
    goto L24; // GOTO
    goto L28; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L25; // GOTO
    goto L26; // GOTO
    goto L24; // JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_78 78 - not implemented
    L78:
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L27; // GOTO
    goto L28; // GOTO
    goto L25; // JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_84 84 - not implemented
    L84:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L80; } // BRANCH_IF_LT
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    L82:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_32 32 - not implemented
    L32:
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L98:
    L8:
    goto L10; // CALL_FUNCTION (as GOTO)
    goto L9; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_17 17 - not implemented
    L17:
    L11:
    // UNKNOWN_141 141 - not implemented
    L12:
    // UNKNOWN_104 104 - not implemented
    L104:
    L13:
    // LOOP_END L14
    // UNKNOWN_105 105 - not implemented
    L105:
    L15:
    // UNKNOWN_106 106 - not implemented
    L106:
    L16:
    // UNKNOWN_144 144 - not implemented
    L17:
    // UNKNOWN_142 142 - not implemented
    L142:
    L18:
    // UNKNOWN_143 143 - not implemented
    L19:
    // UNKNOWN_115 115 - not implemented
    L115:
    L20:
    // UNKNOWN_116 116 - not implemented
    L116:
    L21:
    // UNKNOWN_117 117 - not implemented
    L117:
    L22:
    // UNKNOWN_118 118 - not implemented
    L118:
    L23:
    // UNKNOWN_119 119 - not implemented
    L119:
    L24:
    // UNKNOWN_110 110 - not implemented
    L110:
    L25:
    // UNKNOWN_112 112 - not implemented
    L112:
    L26:
    // UNKNOWN_109 109 - not implemented
    L109:
    L27:
    // UNKNOWN_113 113 - not implemented
    L113:
    L28:
    goto L10; // GOTO
    goto L8; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L30; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 9
    L29:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_73 73 - not implemented
    L73:
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    L65:
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    // JUMP_IF_NOT_ZERO 45 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[1505]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_1506 1506 - not implemented
    bcpl_push(bcpl_globals[1707]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_1708 1708 - not implemented
    bcpl_push(bcpl_globals[2009]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_2010 2010 - not implemented
    bcpl_push(bcpl_globals[2311]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[260] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[263] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1500)); // LOAD_INDIRECT
    bcpl_locals[264] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[1505]); // LOAD_LOCAL
    bcpl_locals[285] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[286] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(200)); // LOAD_INDIRECT
    bcpl_locals[287] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[1707]); // LOAD_LOCAL
    bcpl_locals[265] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2009]); // LOAD_LOCAL
    bcpl_locals[266] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[267] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(300)); // LOAD_INDIRECT
    bcpl_locals[268] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[269] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[274] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[273] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[272] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[288] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[270] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[251] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[244] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(282); // LOAD_CONSTANT
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L31; // CONDITIONAL_JUMP
    goto L32; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(49)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L33; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L33; // CONDITIONAL_JUMP
    goto L34; // CALL_FUNCTION (as GOTO)
    goto L33; // GOTO
    bcpl_push(bcpl_globals[2313]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2311]); // DUPLICATE
    bcpl_push(bcpl_globals[2313]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(289); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2311]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L32; // CALL_FUNCTION (as GOTO)
    goto L34; // GOTO
    goto L31; // GOTO
    bcpl_push(bcpl_globals[2313]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2311]); // DUPLICATE
    bcpl_push(bcpl_globals[2313]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(209); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2311]); // DUPLICATE
    bcpl_push(bcpl_globals[2313]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2311]); // DUPLICATE
    bcpl_push(bcpl_globals[2313]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2311]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L36; // CALL_FUNCTION (as GOTO)
    goto L35; // GOTO
    bcpl_push(bcpl_globals[2314]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2311]); // LOAD_LOCAL
    bcpl_push(285); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(295); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2312]); // DUPLICATE
    bcpl_push(bcpl_globals[2314]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2311]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(285); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(296); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2312]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2311]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2311 2311 - not implemented
    goto L36; // GOTO
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2311]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L35; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[2314]); // LOAD_GLOBAL
    bcpl_push(252); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2312]); // DUPLICATE
    bcpl_push(bcpl_globals[2311]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2009]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[1707]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[1505]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L30; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_243 243 - not implemented
    L1:
    // UNKNOWN_210 210 - not implemented
    L2:
    // UNKNOWN_245 245 - not implemented
    L29:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // FUNCTION_HEADER - 91 parameters
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L2; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 5
    L1:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // LOOP_START L4
    // LOOP_END L3
    // FUNCTION_END 3
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L3; } // BRANCH_IF_LT
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L5; } // BRANCH_IF_NEQ
    return; // RETURN
    goto L5; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[270] = bcpl_pop(); // STORE_LOCAL
    goto L6; // CALL_FUNCTION (as GOTO)
    goto L8; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L9; // GOTO
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(281); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(201); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(204); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_locals[281] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(207); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L10; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(110)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L10; // GOTO
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L11; // CONDITIONAL_JUMP
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L11; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(209); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_locals[281] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L12; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L12; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L13; // GOTO
    goto L14; // GOTO
    goto L15; // GOTO
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(75)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L16; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_7 7 - not implemented
    L7:
    goto L16; // GOTO
    goto L18; // CALL_FUNCTION (as GOTO)
    goto L17; // GOTO
    bcpl_push(bcpl_load_indirect(79)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(78)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(234); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_13 13 - not implemented
    L13:
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L20; // CALL_FUNCTION (as GOTO)
    goto L19; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_13 13 - not implemented
    L13:
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L20; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    goto L18; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(209); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L21; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(230); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L22; // GOTO
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(282); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(233); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L23; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(52)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L24; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(89)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L25; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L26; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L27; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L28; // GOTO
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(104)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L29; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    goto L30; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L31; // GOTO
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L32; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(104)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L32; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L33; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    goto L33; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L34; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L35; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(68)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L36; // GOTO
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(104)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L37; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(98)); // LOAD_INDIRECT
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L38; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L39; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L40; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    goto L40; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L41; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L42; // GOTO
    goto L43; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L44; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L45; // CALL_FUNCTION (as GOTO)
    goto L44; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L46; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L45; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L47; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L47; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L48; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(268); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L49; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(141)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L49; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L50; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L50; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L51; // CALL_FUNCTION (as GOTO)
    goto L52; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(265); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L53; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    goto L53; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    goto L51; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L52; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(265); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(266); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(267); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[267] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L54; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L55; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L55; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(273); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L56; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L56; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[273] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(273); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L57; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L58; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L59; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(221); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L60; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(222); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L61; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(288); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[288] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L7; // CALL_FUNCTION (as GOTO)
    goto L6; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // UNKNOWN_27 27 - not implemented
    L27:
    L8:
    // UNKNOWN_74 74 - not implemented
    L74:
    L9:
    // PUSH_STRING - string handling
    L13:
    // STRING_CONSTANT definition
    L14:
    // UNKNOWN_75 75 - not implemented
    L75:
    L15:
    // UNKNOWN_50 50 - not implemented
    L50:
    L21:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L22]); // DUPLICATE
    // UNKNOWN_52 52 - not implemented
    L52:
    L23:
    // UNKNOWN_54 54 - not implemented
    L54:
    L24:
    // UNKNOWN_58 58 - not implemented
    L58:
    L25:
    // UNKNOWN_57 57 - not implemented
    L57:
    L26:
    // UNKNOWN_55 55 - not implemented
    L55:
    L27:
    // UNKNOWN_65 65 - not implemented
    L65:
    L28:
    // UNKNOWN_66 66 - not implemented
    L66:
    L31:
    // UNKNOWN_67 67 - not implemented
    L67:
    L34:
    bcpl_pop(); // POP
    L35:
    // UNKNOWN_53 53 - not implemented
    L53:
    L36:
    // UNKNOWN_59 59 - not implemented
    L59:
    L38:
    // UNKNOWN_60 60 - not implemented
    L60:
    L39:
    // UNKNOWN_62 62 - not implemented
    L62:
    L41:
    // UNKNOWN_63 63 - not implemented
    L63:
    L42:
    // UNKNOWN_61 61 - not implemented
    L61:
    L43:
    // UNKNOWN_71 71 - not implemented
    L71:
    L48:
    // UNKNOWN_72 72 - not implemented
    L72:
    L54:
    // LOCAL_VAR allocation
    L57:
    // TEMP_VAR allocation
    L59:
    // UNKNOWN_56 56 - not implemented
    L56:
    L60:
    // UNKNOWN_73 73 - not implemented
    L73:
    L61:
    goto L7; // GOTO
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    L1:
    // UNKNOWN_200 200 - not implemented
    L1:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_50 50 - not implemented
    L50:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L9
    // LOOP_END L8
    // LOOP_START L12
    // LOOP_END L11
    // LOOP_START L14
    // LOOP_END L13
    // LOOP_START L16
    // LOOP_END L15
    goto L17; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 9
    L1:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L18; // CONDITIONAL_JUMP
    goto L19; // CALL_FUNCTION (as GOTO)
    goto L21; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L22; // GOTO
    goto L23; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(202); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L24; // GOTO
    goto L25; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(203); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L26; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(201); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(201); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L20; // CALL_FUNCTION (as GOTO)
    goto L19; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L21:
    bcpl_push(bcpl_load_indirect(L22)); // LOAD_INDIRECT
    bcpl_push(L23); // LOAD_CONSTANT
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L24:
    // JUMP_IF_ZERO 44 - not implemented
    L25:
    bcpl_push(bcpl_locals[L26]); // LOAD_LOCAL
    goto L20; // GOTO
    goto L18; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L2:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L27; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L28; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(77)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L28; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(77)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(202); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L29; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(103)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L27; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L3:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 4
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(206); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(287); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(144)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L31; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(285); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(286); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(285); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(286); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[286] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L30; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(78)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(234); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L4:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 3
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(204); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 13
    L5:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_75 75 - not implemented
    L75:
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 4
    goto L33; // CALL_FUNCTION (as GOTO)
    goto L32; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L35; // CALL_FUNCTION (as GOTO)
    goto L34; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L36; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(142)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L36; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L35; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_22 22 - not implemented
    L22:
    if (bcpl_pop()) goto L34; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L33; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L32; } // BRANCH_IF_NEQ
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L6:
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    bcpl_pop(); // POP
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // FUNCTION_END 5
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(264); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    L25:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(143)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L37; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 12
    L7:
    // UNKNOWN_67 67 - not implemented
    L67:
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_72 72 - not implemented
    L72:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    bcpl_push(262); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L39; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L40; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39; } // BRANCH_IF_NEQ
    goto L40; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L98:
    L38:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L38; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L8:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L41; // CONDITIONAL_JUMP
    goto L42; // CALL_FUNCTION (as GOTO)
    goto L44; // GOTO
    return; // RETURN
    goto L45; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(203); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L46; // GOTO
    goto L47; // GOTO
    goto L48; // GOTO
    goto L49; // GOTO
    goto L50; // GOTO
    goto L51; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L52; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L53; // GOTO
    goto L54; // GOTO
    goto L55; // GOTO
    goto L56; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L57; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L43; // CALL_FUNCTION (as GOTO)
    goto L42; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // UNKNOWN_13 13 - not implemented
    L13:
    L44:
    // UNKNOWN_54 54 - not implemented
    L54:
    L45:
    // UNKNOWN_57 57 - not implemented
    L57:
    L46:
    // UNKNOWN_58 58 - not implemented
    L58:
    L47:
    // UNKNOWN_59 59 - not implemented
    L59:
    L48:
    // UNKNOWN_60 60 - not implemented
    L60:
    L49:
    // TEMP_VAR allocation
    L50:
    // UNKNOWN_71 71 - not implemented
    L71:
    L51:
    // UNKNOWN_73 73 - not implemented
    L73:
    L52:
    // UNKNOWN_61 61 - not implemented
    L61:
    L53:
    // UNKNOWN_62 62 - not implemented
    L62:
    L54:
    // UNKNOWN_63 63 - not implemented
    L63:
    L55:
    // UNKNOWN_72 72 - not implemented
    L72:
    L56:
    // UNKNOWN_55 55 - not implemented
    L55:
    L57:
    goto L43; // GOTO
    goto L41; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L10:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L16:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L14:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L58; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 12
    L11:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78; } // BRANCH_IF_LT
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 3
    goto L59; // CALL_FUNCTION (as GOTO)
    goto L61; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L62; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(281); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[281] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L63; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(233); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L64; // GOTO
    return; // RETURN
    goto L60; // CALL_FUNCTION (as GOTO)
    goto L59; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L64:
    bcpl_push(bcpl_locals[L61]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(L62)); // LOAD_INDIRECT
    bcpl_push(L63); // LOAD_CONSTANT
    goto L60; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 13
    L13:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 3
    goto L65; // CALL_FUNCTION (as GOTO)
    goto L67; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L14:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L14:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L68; // GOTO
    goto L69; // GOTO
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(263); // LOAD_CONSTANT
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(269); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[272] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_locals[269] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(242); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(282); // LOAD_CONSTANT
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[263] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(202); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(204); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(209); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(95)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L70; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(96)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    goto L71; // CALL_FUNCTION (as GOTO)
    goto L70; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    goto L71; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(103)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_locals[272] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_locals[269] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[263] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L72; // GOTO
    return; // RETURN
    goto L66; // CALL_FUNCTION (as GOTO)
    goto L65; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L72:
    bcpl_push(bcpl_locals[L67]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 - not implemented
    L68:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L69:
    goto L66; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L15:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    L83:
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L75; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L74; } // BRANCH_IF_NEQ
    goto L75; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L73:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L74; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    // UNKNOWN_21 21 - not implemented
    L21:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L77; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L76:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L77; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L16:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79; } // BRANCH_IF_NEQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L78:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L79; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 - not implemented
    L16:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L78:
    goto L78; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L76:
    goto L76; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L73:
    goto L73; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L17; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_201 201 - not implemented
    L1:
    // UNKNOWN_202 202 - not implemented
    L2:
    // UNKNOWN_203 203 - not implemented
    L3:
    // UNKNOWN_209 209 - not implemented
    L4:
    // UNKNOWN_204 204 - not implemented
    L5:
    // UNKNOWN_205 205 - not implemented
    L6:
    // UNKNOWN_206 206 - not implemented
    L7:
    // UNKNOWN_207 207 - not implemented
    L10:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 91]); // DUPLICATE
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L4; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 8
    L1:
    // UNKNOWN_74 74 - not implemented
    L74:
    goto L77; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // FUNCTION_END 5
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L5; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    L30:
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L8; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L9; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L9; // GOTO
    return; // RETURN
    goto L10; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    L30:
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    return; // RETURN
    goto L11; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    L30:
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L12; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L14; // CALL_FUNCTION (as GOTO)
    goto L13; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    L30:
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L14; // GOTO
    return; // RETURN
    goto L15; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(86)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L16:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L17; // GOTO
    bcpl_push(bcpl_load_indirect(87)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L16:
    goto L16; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L6; // CALL_FUNCTION (as GOTO)
    goto L5; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L15:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L7:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L8:
    // UNKNOWN_30 30 - not implemented
    L30:
    L10:
    // UNKNOWN_33 33 - not implemented
    L33:
    L11:
    // UNKNOWN_34 34 - not implemented
    L34:
    L12:
    goto L6; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 11
    L2:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_67 67 - not implemented
    L67:
    // UNKNOWN_72 72 - not implemented
    L72:
    // FUNCTION_END 3
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(273); // LOAD_CONSTANT
    bcpl_push(274); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[274] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_locals[269] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[273] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(273); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L18; } // BRANCH_IF_NEQ
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_locals[273] = bcpl_pop(); // STORE_LOCAL
    goto L18; // GOTO
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(70)); // LOAD_INDIRECT
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(273); // LOAD_CONSTANT
    bcpl_push(294); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L19; // CALL_FUNCTION (as GOTO)
    goto L20; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(265); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(295); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(266); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(296); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    goto L19; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L20; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[274] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[267] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[269] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[273] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L3:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    L82:
    // FUNCTION_END 3
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(77)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[12]); // LOAD_LOCAL
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    goto L22; // CALL_FUNCTION (as GOTO)
    goto L21; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L22; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L23; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_13 13 - not implemented
    L13:
    // UNKNOWN_80 80 - not implemented
    L80:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    goto L23; // GOTO
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(209); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L24; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L24; // GOTO
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[12]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[11]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(14)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(80)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[12]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_locals[11]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L25; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[12]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[10]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L26; // CALL_FUNCTION (as GOTO)
    goto L25; // GOTO
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[10]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[12]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L26; // GOTO
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(88)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L27; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L27; // GOTO
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[12]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_220 220 - not implemented
    L1:
    // UNKNOWN_221 221 - not implemented
    L2:
    // UNKNOWN_222 222 - not implemented
    L3:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_52 52 - not implemented
    L52:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 4
    L1:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L6; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(148)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L6; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L7; // CALL_FUNCTION (as GOTO)
    goto L9; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(147)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L10; // GOTO
    bcpl_push(bcpl_load_indirect(120)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L11; // GOTO
    goto L12; // GOTO
    goto L13; // GOTO
    goto L14; // GOTO
    goto L15; // GOTO
    goto L16; // GOTO
    goto L17; // GOTO
    goto L18; // GOTO
    goto L19; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L20; // GOTO
    goto L21; // GOTO
    goto L22; // GOTO
    goto L23; // GOTO
    goto L24; // GOTO
    goto L25; // GOTO
    goto L26; // GOTO
    goto L27; // GOTO
    goto L28; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L30; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29; } // BRANCH_IF_NEQ
    goto L30; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L29; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(14)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L31; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L32; // GOTO
    goto L33; // GOTO
    goto L34; // GOTO
    goto L35; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L36; // GOTO
    goto L37; // GOTO
    goto L38; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L39; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(232); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L40; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L41; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(43)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(289); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L42; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(237); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L43; // GOTO
    bcpl_push(272); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(262); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(209); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    bcpl_locals[272] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(200); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(93)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[272] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L44; // GOTO
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(282); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(233); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L45; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(98)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(98)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(93)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L46; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(234); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L48; // CALL_FUNCTION (as GOTO)
    goto L47; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    goto L48; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L47; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L8; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_34 34 - not implemented
    L34:
    L9:
    // UNKNOWN_28 28 - not implemented
    L28:
    L10:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L11:
    // UNKNOWN_13 13 - not implemented
    L13:
    L12:
    bcpl_push(-bcpl_pop()); // NEGATE
    L13:
    // UNKNOWN_22 22 - not implemented
    L22:
    L14:
    // UNKNOWN_23 23 - not implemented
    L23:
    L15:
    // UNKNOWN_24 24 - not implemented
    L24:
    L16:
    // UNKNOWN_25 25 - not implemented
    L25:
    L17:
    // UNKNOWN_31 31 - not implemented
    L31:
    L18:
    // UNKNOWN_32 32 - not implemented
    L32:
    L19:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L20:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L21:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L23:
    // UNKNOWN_21 21 - not implemented
    L21:
    L24:
    // UNKNOWN_33 33 - not implemented
    L33:
    L25:
    // UNKNOWN_34 34 - not implemented
    L34:
    L26:
    // UNKNOWN_35 35 - not implemented
    L35:
    L27:
    // UNKNOWN_36 36 - not implemented
    L36:
    L28:
    // UNKNOWN_17 17 - not implemented
    L17:
    L32:
    // UNKNOWN_30 30 - not implemented
    L30:
    L33:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L34:
    // UNKNOWN_19 19 - not implemented
    L19:
    L35:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L36:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L37:
    // UNKNOWN_16 16 - not implemented
    L16:
    L38:
    // UNKNOWN_7 7 - not implemented
    L7:
    L39:
    // UNKNOWN_1 1 - not implemented
    L1:
    L40:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L41:
    // UNKNOWN_2 2 - not implemented
    L2:
    L42:
    bcpl_push(bcpl_rdline()); // READ_LINE
    L43:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    L44:
    // UNKNOWN_37 37 - not implemented
    L37:
    L45:
    // UNKNOWN_39 39 - not implemented
    L39:
    L46:
    goto L8; // GOTO
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L2:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // STRING_CONSTANT definition
    if (bcpl_pop()) goto L100; // CONDITIONAL_JUMP
    L50:
    // LOOP_END L49
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L51; } // BRANCH_IF_NEQ
    // JUMP_IF_ZERO 44 - not implemented
    L50:
    // UNKNOWN_52 52 - not implemented
    L52:
    goto L51; // GOTO
    goto L52; // CALL_FUNCTION (as GOTO)
    goto L54; // GOTO
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L49; } // BRANCH_IF_LT
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(113)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L55; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(46)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(237); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L56; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L57; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L58; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(14)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L53; // CALL_FUNCTION (as GOTO)
    goto L52; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L54:
    // UNKNOWN_2 2 - not implemented
    L2:
    L55:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L56:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L57:
    goto L53; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L3:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    goto L69; // GOTO
    // UNKNOWN_82 82 - not implemented
    L82:
    // PUSH_STRING - string handling
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L4:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    L65:
    bcpl_pop(); // POP
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L59; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L60; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L60; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(233); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(233); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L59; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_231 231 - not implemented
    L1:
    // UNKNOWN_232 232 - not implemented
    L2:
    // UNKNOWN_236 236 - not implemented
    L3:
    // UNKNOWN_233 233 - not implemented
    L4:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_53 53 - not implemented
    L53:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 9
    L1:
    // LOCAL_VAR allocation
    if (bcpl_pop()) goto L65; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L6; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(117)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L6; // GOTO
    goto L7; // CALL_FUNCTION (as GOTO)
    goto L9; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(118)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L10; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(206); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L11; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L11; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(119)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L12; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L13; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L14; // GOTO
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L15; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_17 17 - not implemented
    L17:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L16; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_19 19 - not implemented
    L19:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L17; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_30 30 - not implemented
    L30:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L18; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L19; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L20; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_13 13 - not implemented
    L13:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L21; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L22; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(-bcpl_pop()); // NEGATE
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L23; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_31 31 - not implemented
    L31:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L24; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_32 32 - not implemented
    L32:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L25; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_34 34 - not implemented
    L34:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L26; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_33 33 - not implemented
    L33:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L27; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_35 35 - not implemented
    L35:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L28; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_36 36 - not implemented
    L36:
    // UNKNOWN_98 98 - not implemented
    L98:
    L5:
    goto L8; // CALL_FUNCTION (as GOTO)
    goto L7; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // UNKNOWN_18 18 - not implemented
    L18:
    L9:
    // UNKNOWN_2 2 - not implemented
    L2:
    L10:
    // UNKNOWN_1 1 - not implemented
    L1:
    L12:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L13:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L14:
    // UNKNOWN_17 17 - not implemented
    L17:
    L15:
    // UNKNOWN_19 19 - not implemented
    L19:
    L16:
    // UNKNOWN_30 30 - not implemented
    L30:
    L17:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L18:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L19:
    // UNKNOWN_13 13 - not implemented
    L13:
    L20:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L21:
    bcpl_push(-bcpl_pop()); // NEGATE
    L22:
    // UNKNOWN_31 31 - not implemented
    L31:
    L23:
    // UNKNOWN_32 32 - not implemented
    L32:
    L24:
    // UNKNOWN_34 34 - not implemented
    L34:
    L25:
    // UNKNOWN_33 33 - not implemented
    L33:
    L26:
    // UNKNOWN_35 35 - not implemented
    L35:
    L27:
    // UNKNOWN_36 36 - not implemented
    L36:
    L28:
    goto L8; // GOTO
    goto L5; // GOTO
    // UNKNOWN_93 93 - not implemented
    L93:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    L96:
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L2:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_71 71 - not implemented
    L71:
    // UNKNOWN_78 78 - not implemented
    L78:
    // FUNCTION_END 4
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L30; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29; } // BRANCH_IF_NEQ
    goto L30; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(110)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L29; // GOTO
    goto L31; // CALL_FUNCTION (as GOTO)
    goto L33; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L34; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(112)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L34; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(230); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(230); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L35; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(80)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(81)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(82)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(237); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L36; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(121)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L37; // GOTO
    goto L38; // GOTO
    goto L39; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(232); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(83)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L40; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(109)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L32; // CALL_FUNCTION (as GOTO)
    goto L31; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdline()); // READ_LINE
    L40:
    // UNKNOWN_38 38 - not implemented
    L38:
    L33:
    // UNKNOWN_2 2 - not implemented
    L2:
    L35:
    // UNKNOWN_28 28 - not implemented
    L28:
    L36:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L37:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L38:
    // UNKNOWN_37 37 - not implemented
    L37:
    L39:
    goto L32; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L3:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_77 77 - not implemented
    L77:
    // LOCAL_VAR allocation
    // FUNCTION_END 7
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(206); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    L7:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(115)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L41; // GOTO
    goto L42; // CALL_FUNCTION (as GOTO)
    goto L44; // GOTO
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(263); // LOAD_CONSTANT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L45; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(116)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    goto L45; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L46; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L47; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L48; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L49; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(113)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdline()); // READ_LINE
    goto L49; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    goto L43; // CALL_FUNCTION (as GOTO)
    goto L42; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // TEMP_VAR allocation
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L43:
    // UNKNOWN_77 77 - not implemented
    L77:
    L44:
    // STRING_CONSTANT definition
    L46:
    // UNKNOWN_78 78 - not implemented
    L78:
    L47:
    // UNKNOWN_1 1 - not implemented
    L1:
    L48:
    goto L43; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_235 235 - not implemented
    L1:
    // UNKNOWN_230 230 - not implemented
    L2:
    // UNKNOWN_237 237 - not implemented
    L3:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_54 54 - not implemented
    L54:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L18; // CALL_FUNCTION (as GOTO)
    // FUNCTION_START 7
    L1:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L2:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L95; } // BRANCH_IF_LT
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(94)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(85); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(294); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(85); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdline()); // READ_LINE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L19; // CALL_FUNCTION (as GOTO)
    goto L20; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(85); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(297); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L19; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L20; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 11
    L3:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_pop(); // POP
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_65 65 - not implemented
    L65:
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    L65:
    // UNKNOWN_66 66 - not implemented
    L66:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L4:
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    L77:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_74 74 - not implemented
    L74:
    goto L77; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_80 80 - not implemented
    L80:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(85)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L5:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // FUNCTION_HEADER - 95 parameters
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(298); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L6:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_50 50 - not implemented
    L50:
    // FUNCTION_END 4
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(298); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L7:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_50 50 - not implemented
    L50:
    // UNKNOWN_80 80 - not implemented
    L80:
    // FUNCTION_END 4
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(298); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L8:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 80]); // DUPLICATE
    // FUNCTION_END 5
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(298); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L9:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_78 78 - not implemented
    L78:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L10:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // STRING_CONSTANT definition
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L11:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_67 67 - not implemented
    L67:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L12:
    // PUSH_STRING - string handling
    goto L84; // CALL_FUNCTION (as GOTO)
    // UNKNOWN_83 83 - not implemented
    L83:
    // UNKNOWN_84 84 - not implemented
    L84:
    // UNKNOWN_82 82 - not implemented
    L82:
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_78 78 - not implemented
    L78:
    // UNKNOWN_71 71 - not implemented
    L71:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(85); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L21; // CALL_FUNCTION (as GOTO)
    goto L22; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(85); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(297); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    L80:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L21; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L22; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L13:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82; } // BRANCH_IF_NEQ
    // UNKNOWN_73 73 - not implemented
    L73:
    // UNKNOWN_84 84 - not implemented
    L84:
    // LOCAL_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    L80:
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 3
    L14:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82; } // BRANCH_IF_NEQ
    // UNKNOWN_78 78 - not implemented
    L78:
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L23; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_17 17 - not implemented
    L17:
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    L22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L24; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_32 32 - not implemented
    L32:
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(-bcpl_pop()); // NEGATE
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_2 2 - not implemented
    L2:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L24; // GOTO
    goto L23; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L15:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82; } // BRANCH_IF_NEQ
    // UNKNOWN_80 80 - not implemented
    L80:
    // UNKNOWN_78 78 - not implemented
    L78:
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L25; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L25; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    // UNKNOWN_13 13 - not implemented
    L13:
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L16:
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    L78:
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    L67:
    // PUSH_STRING - string handling
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[251] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 3
    L17:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82; } // BRANCH_IF_NEQ
    // UNKNOWN_67 67 - not implemented
    L67:
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(251); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[251] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(251); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    L23:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[251] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L26; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L18; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_17 17 - not implemented
    L17:
    // UNKNOWN_240 240 - not implemented
    L1:
    // UNKNOWN_242 242 - not implemented
    L2:
    // UNKNOWN_234 234 - not implemented
    L3:
    // UNKNOWN_241 241 - not implemented
    L4:
    // UNKNOWN_290 290 - not implemented
    L5:
    // UNKNOWN_291 291 - not implemented
    L6:
    // UNKNOWN_292 292 - not implemented
    L7:
    // UNKNOWN_294 294 - not implemented
    L8:
    // UNKNOWN_295 295 - not implemented
    L9:
    // UNKNOWN_296 296 - not implemented
    L10:
    // UNKNOWN_297 297 - not implemented
    L11:
    // UNKNOWN_289 289 - not implemented
    L12:
    // UNKNOWN_298 298 - not implemented
    L13:
    // UNKNOWN_253 253 - not implemented
    L14:
    // UNKNOWN_254 254 - not implemented
    L15:
    // UNKNOWN_252 252 - not implemented
    L16:
    // UNKNOWN_250 250 - not implemented
    L17:
}

int main(int argc, char* argv[]) {
    bcpl_init(argc, argv);
    bcpl_start();
    return 0;
}
