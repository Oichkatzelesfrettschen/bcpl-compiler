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
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // CALL (as GOTO)
    // FUNCTION_START 5
    L1_1:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_84 84 - not implemented
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
    goto L11_2; // JUMP
    // UNKNOWN_47 47 - not implemented
    // LOOP_START 101
    // UNKNOWN_118 118 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_116 116 - not implemented
    // LOOP_START 101
    // UNKNOWN_114 114 - not implemented
    // UNKNOWN_114 114 - not implemented
    bcpl_push(41); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[194] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    goto L9_3; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_46 46 - not implemented
    // UNKNOWN_1 1 - not implemented
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    // JUMP_IF_NOT_ZERO 45 7 - not implemented
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
    goto L3_4; // CALL (as GOTO)
    goto L4_5; // GOTO
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_28 28 - not implemented
    goto L3_4; // GOTO
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L4_5; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    goto L3_4; // JUMP
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_push(42); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_28 28 - not implemented
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_28 28 - not implemented
    if (bcpl_pop()) goto L5_6; // CONDITIONAL_JUMP
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
    goto L9_3; // JUMP
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    goto L8_7; // GOTO
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(13); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_28 28 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L6_8; } // BRANCH_IF_LT
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L10_9; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L9_3; } // BRANCH_IF_NEQ
    goto L10_9; // GOTO
    goto L11_2; // CALL (as GOTO)
    goto L9_3; // GOTO
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(80)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L12_10; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    goto L12_10; // GOTO
    bcpl_push(bcpl_load_indirect(84)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13_11; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    goto L13_11; // GOTO
    bcpl_push(bcpl_load_indirect(67)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L14_12; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    goto L14_12; // GOTO
    bcpl_push(bcpl_load_indirect(77)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L15_13; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    goto L15_13; // GOTO
    bcpl_push(bcpl_load_indirect(78)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L16_14; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    goto L16_14; // GOTO
    bcpl_push(bcpl_load_indirect(83)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17_15; } // BRANCH_IF_NEQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[110] = bcpl_pop(); // STORE_LOCAL
    goto L17_15; // GOTO
    bcpl_push(bcpl_load_indirect(69)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L18_16; } // BRANCH_IF_NEQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[127] = bcpl_pop(); // STORE_LOCAL
    goto L18_16; // GOTO
    bcpl_push(bcpl_load_indirect(76)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19_17; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(70); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(62); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    goto L19_17; // GOTO
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[28]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L20_18; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[282] = bcpl_pop(); // STORE_LOCAL
    goto L20_18; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[29]); // LOAD_LOCAL
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    goto L8_7; // CALL (as GOTO)
    goto L11_2; // GOTO
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_globals[32]); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 30]); // DUPLICATE
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    goto L5_6; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_30 30 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21_19; } // BRANCH_IF_NEQ
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_locals[195] = bcpl_pop(); // STORE_LOCAL
    goto L21_19; // GOTO
    // LOOP_START L23
    // LOOP_END L22
    goto L24_20; // CALL (as GOTO)
    // FUNCTION_START 4
    L22_21:
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // FUNCTION_END 4
    // JUMP_IF_NOT_ZERO 45 5 - not implemented
    bcpl_push(bcpl_globals[69]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[100] = bcpl_pop(); // STORE_LOCAL
    goto L25_22; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[168] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[169] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(110); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26_23; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[71]); // LOAD_GLOBAL
    goto L4_5; // JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_push(41); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // LOCAL_VAR allocation
    bcpl_locals[196] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[71]); // LOAD_GLOBAL
    bcpl_push(196); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L28_24; } // BRANCH_IF_NEQ
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_locals[196] = bcpl_pop(); // STORE_LOCAL
    goto L28_24; // GOTO
    goto L27_25; // CALL (as GOTO)
    goto L26_23; // GOTO
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_locals[196] = bcpl_pop(); // STORE_LOCAL
    goto L27_25; // GOTO
    bcpl_push(bcpl_globals[71]); // LOAD_GLOBAL
    bcpl_push(150); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // LOCAL_VAR allocation
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[69]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29_26; } // BRANCH_IF_NEQ
    goto L30_27; // CALL (as GOTO)
    goto L29_26; // GOTO
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    goto L14_12; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    goto L69_28; // GOTO
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31_29; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    goto L8_7; // JUMP
    // UNKNOWN_65 65 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
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
    goto L31_29; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L32_30; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[72]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 70]); // DUPLICATE
    goto L32_30; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    if (bcpl_pop()) goto L33_31; // CONDITIONAL_JUMP
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
    goto L33_31; // GOTO
    bcpl_push(bcpl_globals[69]); // LOAD_GLOBAL
    goto L25_22; // CALL (as GOTO)
    goto L30_27; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    goto L24_20; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 L23 - not implemented
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(40); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    goto L18_16; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // FUNCTION_HEADER - 32 parameters
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L34_32; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[30]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 28]); // DUPLICATE
    goto L34_32; // GOTO
    bcpl_pop(); // POP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_1 1 - not implemented
    L1_1:
    // FUNCTION_HEADER - 4 parameters
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L49_33; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // CALL (as GOTO)
    // FUNCTION_START 8
    L1_1:
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L84_34; } // BRANCH_IF_EQ
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L77_35; } // BRANCH_IF_LT
    // UNKNOWN_66 66 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[122] = bcpl_pop(); // STORE_LOCAL
    goto L3_4; // GOTO
    bcpl_push(127); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L4_5; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L4_5; // GOTO
    goto L5_6; // CALL (as GOTO)
    goto L7_36; // GOTO
    goto L8_7; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[122] = bcpl_pop(); // STORE_LOCAL
    goto L9_3; // GOTO
    goto L10_9; // GOTO
    goto L11_2; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L9_3; // CONDITIONAL_JUMP
    goto L3_4; // CALL (as GOTO)
    goto L12_10; // GOTO
    goto L13_11; // GOTO
    goto L14_12; // GOTO
    goto L15_13; // GOTO
    goto L16_14; // GOTO
    goto L17_15; // GOTO
    goto L18_16; // GOTO
    goto L19_17; // GOTO
    goto L20_18; // GOTO
    goto L21_19; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L22_21; // GOTO
    goto L23_37; // GOTO
    goto L24_20; // GOTO
    goto L25_22; // GOTO
    goto L26_23; // GOTO
    goto L27_25; // GOTO
    goto L28_24; // GOTO
    goto L29_26; // GOTO
    goto L30_27; // GOTO
    goto L31_29; // GOTO
    goto L32_30; // GOTO
    goto L33_31; // GOTO
    goto L34_32; // GOTO
    goto L35_38; // GOTO
    goto L36_39; // GOTO
    goto L37_40; // GOTO
    goto L38_41; // GOTO
    goto L39_42; // GOTO
    goto L40_43; // GOTO
    goto L41_44; // GOTO
    goto L42_45; // GOTO
    goto L43_46; // GOTO
    goto L44_47; // GOTO
    goto L45_48; // GOTO
    goto L46_49; // GOTO
    goto L47_50; // GOTO
    goto L48_51; // GOTO
    goto L49_33; // GOTO
    goto L50_52; // GOTO
    goto L51_53; // GOTO
    goto L52_54; // GOTO
    goto L53_55; // GOTO
    goto L54_56; // GOTO
    goto L55_57; // GOTO
    goto L56_58; // GOTO
    goto L57_59; // GOTO
    goto L58_60; // GOTO
    goto L59_61; // GOTO
    goto L60_62; // GOTO
    goto L61_63; // GOTO
    goto L62_64; // GOTO
    goto L63_65; // GOTO
    goto L64_66; // GOTO
    goto L65_67; // GOTO
    goto L66_68; // GOTO
    goto L67_69; // GOTO
    goto L68_70; // GOTO
    goto L69_28; // GOTO
    goto L70_71; // GOTO
    goto L71_72; // GOTO
    goto L72_73; // GOTO
    goto L73_74; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(118); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(93)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L74_75; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(119); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L3_4; // CALL (as GOTO)
    goto L74_75; // GOTO
    return; // RETURN
    goto L75_76; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L76_77; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L76_77; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L76_77; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L78_78; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L77_35:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L78_78; // GOTO
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L77_35:
    goto L77_35; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(36)); // LOAD_INDIRECT
    bcpl_push(118); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L79_79; // GOTO
    goto L80_80; // GOTO
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L82_82; // GOTO
    goto L83_83; // GOTO
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L84_34; // GOTO
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
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L85_84; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(55)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L85_84; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L85_84; // GOTO
    bcpl_push(bcpl_load_indirect(66)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L86_85; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L86_85; // GOTO
    bcpl_push(bcpl_load_indirect(79)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L87_86; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L87_86; // GOTO
    bcpl_push(bcpl_load_indirect(88)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L88_87; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_push(112); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    goto L88_87; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L89_88; // GOTO
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L90_89; // GOTO
    bcpl_push(bcpl_load_indirect(14)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L91_90; // GOTO
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L92_91; // GOTO
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L93_92; // GOTO
    bcpl_push(bcpl_load_indirect(7)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L94_93; // GOTO
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L95_94; // GOTO
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L96_95; // GOTO
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L97_96; // GOTO
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L98_97; // GOTO
    bcpl_push(bcpl_load_indirect(28)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L99_98; // GOTO
    bcpl_push(bcpl_load_indirect(11)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L100_99; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L101_100; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L101_100; // GOTO
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L102_101; } // BRANCH_IF_NEQ
    goto L103_102; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L104_103; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L103_102; } // BRANCH_IF_NEQ
    goto L104_103; // GOTO
    goto L3_4; // CALL (as GOTO)
    goto L102_101; // GOTO
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L105_104; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(12)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L105_104; // GOTO
    goto L106_105; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L107_106; } // BRANCH_IF_NEQ
    goto L108_107; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L108_107; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L109_108; } // BRANCH_IF_NEQ
    goto L110_109; // CALL (as GOTO)
    goto L109_108; // GOTO
    goto L107_106; // GOTO
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L111_110; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    goto L111_110; // GOTO
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L112_111; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L112_111; // GOTO
    goto L106_105; // CALL (as GOTO)
    goto L110_109; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L3_4; // CALL (as GOTO)
    goto L113_112; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L114_113; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(21)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L114_113; // GOTO
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L115_114; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L116_115; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L116_115; // GOTO
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L117_116; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(21)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L117_116; // GOTO
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L118_117; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L119_118; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(24)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L119_118; // GOTO
    bcpl_push(bcpl_load_indirect(60)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L120_119; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(31)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L120_119; // GOTO
    bcpl_push(bcpl_load_indirect(22)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L121_120; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L122_121; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(25)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L122_121; // GOTO
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L123_122; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L123_122; // GOTO
    bcpl_push(bcpl_load_indirect(23)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L124_123; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L125_124; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(37)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L125_124; // GOTO
    bcpl_push(bcpl_load_indirect(15)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L126_125; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L127_126; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(50)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L127_126; // GOTO
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L128_127; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L130_128; // CALL (as GOTO)
    goto L129_129; // GOTO
    bcpl_push(bcpl_load_indirect(255)); // LOAD_INDIRECT
    bcpl_push(109); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L131_130; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L131_130; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(109); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(113); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    goto L130_128; // GOTO
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L129_129; } // BRANCH_IF_NEQ
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    bcpl_locals[107] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    goto L81_81; // CALL (as GOTO)
    goto L132_131; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(113); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    bcpl_locals[101] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(39)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L133_132; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L133_132; // GOTO
    goto L81_81; // CALL (as GOTO)
    goto L134_133; // GOTO
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L135_134; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(94)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L135_134; // GOTO
    goto L136_135; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L137_136; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L137_136; // GOTO
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
    goto L3_4; // CALL (as GOTO)
    goto L6_8; // CALL (as GOTO)
    goto L5_6; // GOTO
    bcpl_push(117); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_93 93 - not implemented
    L134_133:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L7_36:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    L8_7:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L10_9:
    // UNKNOWN_32 32 - not implemented
    L11_2:
    // UNKNOWN_48 48 - not implemented
    L12_10:
    // FUNCTION_HEADER - L13 parameters
    // UNKNOWN_50 50 - not implemented
    L14_12:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L15]); // DUPLICATE
    // UNKNOWN_52 52 - not implemented
    L16_14:
    // UNKNOWN_53 53 - not implemented
    L17_15:
    // UNKNOWN_54 54 - not implemented
    L18_16:
    // UNKNOWN_55 55 - not implemented
    L19_17:
    // UNKNOWN_56 56 - not implemented
    L20_18:
    // UNKNOWN_57 57 - not implemented
    L21_19:
    return; // RETURN
    L22_21:
    // UNKNOWN_98 98 - not implemented
    L23_37:
    // UNKNOWN_99 99 - not implemented
    L24_20:
    // LOOP_START L25
    // LOOP_END L26
    // UNKNOWN_102 102 - not implemented
    L27_25:
    // END_BLOCK
    L28_24:
    // UNKNOWN_104 104 - not implemented
    L29_26:
    // UNKNOWN_105 105 - not implemented
    L30_27:
    // UNKNOWN_106 106 - not implemented
    L31_29:
    // UNKNOWN_107 107 - not implemented
    L32_30:
    // UNKNOWN_108 108 - not implemented
    L33_31:
    // UNKNOWN_109 109 - not implemented
    L34_32:
    // UNKNOWN_110 110 - not implemented
    L35_38:
    // UNKNOWN_111 111 - not implemented
    L36_39:
    // UNKNOWN_112 112 - not implemented
    L37_40:
    // UNKNOWN_113 113 - not implemented
    L38_41:
    // UNKNOWN_114 114 - not implemented
    L39_42:
    // UNKNOWN_115 115 - not implemented
    L40_43:
    // UNKNOWN_116 116 - not implemented
    L41_44:
    // UNKNOWN_117 117 - not implemented
    L42_45:
    // UNKNOWN_118 118 - not implemented
    L43_46:
    // UNKNOWN_119 119 - not implemented
    L44_47:
    // UNKNOWN_120 120 - not implemented
    L45_48:
    // UNKNOWN_121 121 - not implemented
    L46_49:
    // UNKNOWN_122 122 - not implemented
    L47_50:
    // UNKNOWN_65 65 - not implemented
    L48_51:
    // UNKNOWN_66 66 - not implemented
    L49_33:
    // UNKNOWN_67 67 - not implemented
    L50_52:
    bcpl_pop(); // POP
    L51_53:
    // LOCAL_VAR allocation
    L52_54:
    // TEMP_VAR allocation
    L53_55:
    // UNKNOWN_71 71 - not implemented
    L54_56:
    // UNKNOWN_72 72 - not implemented
    L55_57:
    // UNKNOWN_73 73 - not implemented
    L56_58:
    // UNKNOWN_74 74 - not implemented
    L57_59:
    // UNKNOWN_75 75 - not implemented
    L58_60:
    // STRING_CONSTANT definition
    L59_61:
    // UNKNOWN_77 77 - not implemented
    L60_62:
    // UNKNOWN_78 78 - not implemented
    L61_63:
    // PUSH_STRING - string handling
    L62_64:
    // UNKNOWN_80 80 - not implemented
    L63_65:
    bcpl_locals[L64] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_82 82 - not implemented
    L65_67:
    // UNKNOWN_83 83 - not implemented
    L66_68:
    // UNKNOWN_84 84 - not implemented
    L67_69:
    goto L68_70; // CALL (as GOTO)
    if (bcpl_pop()) goto L69_28; // CONDITIONAL_JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L70_71; } // BRANCH_IF_NEQ
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L71_72; } // BRANCH_IF_EQ
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L72_73; } // BRANCH_IF_LT
    goto L73_74; // GOTO
    // UNKNOWN_36 36 - not implemented
    L75_76:
    bcpl_push(bcpl_globals[L79]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[L80]); // LOAD_LOCAL
    // UNKNOWN_93 93 - not implemented
    L82_82:
    bcpl_push(L83); // LOAD_CONSTANT
    // UNKNOWN_35 35 - not implemented
    L84_34:
    // UNKNOWN_63 63 - not implemented
    L89_88:
    goto L90_89; // JUMP
    // JUMP_IF_ZERO 44 L91 - not implemented
    // UNKNOWN_59 59 - not implemented
    L92_91:
    // UNKNOWN_64 64 - not implemented
    L93_92:
    // UNKNOWN_38 38 - not implemented
    L94_93:
    // UNKNOWN_124 124 - not implemented
    L95_94:
    // UNKNOWN_61 61 - not implemented
    L96_95:
    // UNKNOWN_33 33 - not implemented
    L97_96:
    // UNKNOWN_37 37 - not implemented
    L98_97:
    bcpl_push(bcpl_load_indirect(L99)); // LOAD_INDIRECT
    // UNKNOWN_47 47 - not implemented
    L100_99:
    // UNKNOWN_126 126 - not implemented
    L113_112:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    L115_114:
    // UNKNOWN_60 60 - not implemented
    L118_117:
    // UNKNOWN_62 62 - not implemented
    L121_120:
    // JUMP_IF_NOT_ZERO 45 L124 - not implemented
    // UNKNOWN_58 58 - not implemented
    L126_125:
    // UNKNOWN_34 34 - not implemented
    L128_127:
    // UNKNOWN_39 39 - not implemented
    L132_131:
    // UNKNOWN_46 46 - not implemented
    L136_135:
    goto L6_8; // GOTO
    goto L3_4; // CALL (as GOTO)
    goto L81_81; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_120 120 - not implemented
    L1_1:
    // FUNCTION_HEADER - 4 parameters
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L50_52; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L4
    // LOOP_END L3
    goto L5_6; // CALL (as GOTO)
    // FUNCTION_START 10
    L1_1:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_75 75 - not implemented
    goto L80_80; // CALL (as GOTO)
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79_79; } // BRANCH_IF_NEQ
    // UNKNOWN_82 82 - not implemented
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
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    // UNKNOWN_13 13 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[116] = bcpl_pop(); // STORE_LOCAL
    goto L8_7; // CALL (as GOTO)
    goto L7_36; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L9_3; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L10_9; // CALL (as GOTO)
    goto L9_3; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_locals[116] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L10_9; // GOTO
    goto L8_7; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L11_2; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(107); // LOAD_CONSTANT
    // UNKNOWN_23 23 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L7_36; } // BRANCH_IF_NEQ
    goto L11_2; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L12_10; } // BRANCH_IF_NEQ
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
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L13_11; // CALL (as GOTO)
    goto L14_12; // GOTO
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
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L13_11; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L14_12; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    goto L12_10; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L6_8:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L6_8; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 12
    L2_0:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L83_83; } // BRANCH_IF_LT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79_79; } // BRANCH_IF_NEQ
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 2
    // LOOP_START L15
    // UNKNOWN_102 102 - not implemented
    bcpl_push(bcpl_locals[102]); // LOAD_LOCAL
    // UNKNOWN_19 19 - not implemented
    // UNKNOWN_102 102 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L102_101; } // BRANCH_IF_LT
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_102 102 - not implemented
    // LOOP_START 102
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_102 102 - not implemented
    // LOOP_END 102
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_102 102 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_35 35 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_102 102 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_102 102 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_56 56 - not implemented
    // UNKNOWN_102 102 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_102 102 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_57 57 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_98 98 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_74 74 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_34 34 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_33 33 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_31 31 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_21 21 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_36 36 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_48 48 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_53 53 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_102 102 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_61 61 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_62 62 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_63 63 - not implemented
    // UNKNOWN_102 102 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_102 102 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_102 102 - not implemented
    // FUNCTION_HEADER - 102 parameters
    // UNKNOWN_99 99 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_55 55 - not implemented
    // UNKNOWN_102 102 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_102 102 - not implemented
    // LOOP_END 102
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_60 60 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_102 102 - not implemented
    // END_BLOCK
    // UNKNOWN_102 102 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_59 59 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_47 47 - not implemented
    L15_13:
    bcpl_locals[123] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L142_137; // JUMP
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_66 66 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_66 66 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L47_50; } // BRANCH_IF_LT
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    goto L76_77; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // LOCAL_VAR allocation
    bcpl_locals[47] = bcpl_pop(); // STORE_LOCAL
    // LOCAL_VAR allocation
    bcpl_locals[86] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_47 47 - not implemented
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_47 47 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_73 73 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    if (bcpl_pop()) goto L47_50; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_47 47 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_73 73 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_47 47 - not implemented
    // JUMP_IF_ZERO 44 L4 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L171_138; // JUMP
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_73 73 - not implemented
    // TEMP_VAR allocation
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    bcpl_locals[86] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_47 47 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    goto L76_77; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    goto L82_82; // CALL (as GOTO)
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_73 73 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    if (bcpl_pop()) goto L47_50; // CONDITIONAL_JUMP
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L72_73; } // BRANCH_IF_NEQ
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    goto L78_78; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73_74; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    goto L69_28; // CALL (as GOTO)
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_72 72 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    goto L78_78; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_47 47 - not implemented
    goto L78_78; // CALL (as GOTO)
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_47 47 - not implemented
    if (bcpl_pop()) goto L69_28; // CONDITIONAL_JUMP
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_47 47 - not implemented
    if (bcpl_pop()) goto L65_67; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_47 47 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L72_73; } // BRANCH_IF_NEQ
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_36 36 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_47 47 - not implemented
    // JUMP_IF_ZERO 44 L4 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_locals[134] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 1
    L3_4:
    bcpl_pop(); // POP
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L16_14; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17_15; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19_17; } // BRANCH_IF_NEQ
    return; // RETURN
    goto L19_17; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(123); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[123] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L18_16; // CALL (as GOTO)
    goto L17_15; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    goto L18_16; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L16_14; // CALL (as GOTO)
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5_6; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_125 125 - not implemented
    L1_1:
    // UNKNOWN_121 121 - not implemented
    L2_0:
    // FUNCTION_HEADER - 4 parameters
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L51_53; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L8
    // LOOP_END L7
    // LOOP_START L11
    // LOOP_END L10
    goto L12_10; // CALL (as GOTO)
    // FUNCTION_START 3
    L1_1:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(13); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(110); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13_11; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13_11; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(-1)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_21 21 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13_11; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(196); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(111); // LOAD_CONSTANT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L14_12; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L5_6; // JUMP
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_locals[111] = bcpl_pop(); // STORE_LOCAL
    goto L14_12; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L13_11; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(132); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[132] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(132); // LOAD_CONSTANT
    // UNKNOWN_33 33 - not implemented
    bcpl_push(100); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L2_0:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82_82; } // BRANCH_IF_NEQ
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_66 66 - not implemented
    goto L70_71; // CALL (as GOTO)
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L4_5; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_46 46 - not implemented
    // UNKNOWN_46 46 - not implemented
    // UNKNOWN_46 46 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(132); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(132); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L15_13; // CALL (as GOTO)
    goto L16_14; // GOTO
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_33 33 - not implemented
    bcpl_push(100); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L17_15; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L17_15; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L15_13; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L16_14; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L3_4:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
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
    goto L18_16; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L20_18; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    if (bcpl_pop()) goto L19_17; // CONDITIONAL_JUMP
    goto L20_18; // GOTO
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21_19; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    if (bcpl_pop()) goto L19_17; // CONDITIONAL_JUMP
    goto L21_19; // GOTO
    bcpl_push(bcpl_load_indirect(46)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L19_17; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(95)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L19_17; // CONDITIONAL_JUMP
    goto L22_21; // CALL (as GOTO)
    goto L19_17; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(109); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    goto L18_16; // CALL (as GOTO)
    goto L22_21; // GOTO
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(108); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    L4_5:
    // UNKNOWN_80 80 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
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
    bcpl_locals[114] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L23_37; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L23_37; // GOTO
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(104); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(103); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L24_20; } // BRANCH_IF_NEQ
    // LOOP_START L26
    // LOOP_END L25
    // JUMP_IF_NOT_ZERO 45 4 - not implemented
    goto L21_19; // JUMP
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_117 117 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_114 114 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_108 108 - not implemented
    // UNKNOWN_111 111 - not implemented
    // UNKNOWN_99 99 - not implemented
    return; // RETURN
    // UNKNOWN_108 108 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_108 108 - not implemented
    // UNKNOWN_105 105 - not implemented
    // UNKNOWN_98 98 - not implemented
    // UNKNOWN_47 47 - not implemented
    // UNKNOWN_111 111 - not implemented
    // UNKNOWN_98 98 - not implemented
    // UNKNOWN_99 99 - not implemented
    // UNKNOWN_112 112 - not implemented
    // UNKNOWN_108 108 - not implemented
    // UNKNOWN_47 47 - not implemented
    goto L27_25; // CALL (as GOTO)
    // FUNCTION_START 6
    L25_22:
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_80 80 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // FUNCTION_END 4
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L28_24; // CALL (as GOTO)
    goto L29_26; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_120 120 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_121 121 - not implemented
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L28_24; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L29_26; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_121 121 - not implemented
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L27_25; // GOTO
    bcpl_push(bcpl_globals[68]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_120 120 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_load_indirect(255)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30_27; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_121 121 - not implemented
    bcpl_push(bcpl_globals[70]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L26 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 68]); // DUPLICATE
    bcpl_push(bcpl_globals[70]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(106); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 L26 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 68]); // DUPLICATE
    bcpl_push(bcpl_globals[70]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(42); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_pop(); // POP
    bcpl_locals[193] = bcpl_pop(); // STORE_LOCAL
    goto L30_27; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L24_20; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31_29; } // BRANCH_IF_NEQ
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
    goto L32_30; // CALL (as GOTO)
    goto L31_29; // GOTO
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 2]); // DUPLICATE
    goto L32_30; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L5_6:
    // TEMP_VAR allocation
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L6_8:
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_78 78 - not implemented
    goto L77_35; // CALL (as GOTO)
    // UNKNOWN_66 66 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 L8 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[101] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_25 25 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L33_31; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L33_31; // GOTO
    goto L34_32; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 L8 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_25 25 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L35_38; } // BRANCH_IF_NEQ
    return; // RETURN
    goto L35_38; // GOTO
    bcpl_push(101); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[101] = bcpl_pop(); // STORE_LOCAL
    goto L34_32; // CALL (as GOTO)
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L7_36:
    if (bcpl_pop()) goto L65_67; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    goto L69_28; // CALL (as GOTO)
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37_40; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37_40; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    // UNKNOWN_98 98 - not implemented
    L36_39:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L37_40; // GOTO
    bcpl_push(bcpl_load_indirect(65)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39_42; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(70)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39_42; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(65)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_98 98 - not implemented
    L38_41:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L39_42; // GOTO
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41_44; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41_44; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_98 98 - not implemented
    L40_43:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L41_44; // GOTO
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L40_43:
    goto L40_43; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L38_41:
    goto L38_41; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L36_39:
    goto L36_39; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L9_3:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // FUNCTION_END 2
    // LOOP_START L43
    // LOOP_END L42
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L42_45; } // BRANCH_IF_LT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L45_48; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L45_48; // GOTO
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L46_49; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L49_33; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L49_33; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L48_51; } // BRANCH_IF_NEQ
    goto L49_33; // GOTO
    goto L50_52; // GOTO
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L51_53; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    goto L51_53; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L50_52; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L50_52; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L50_52; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L52_54; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L52_54; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    // JUMP_IF_ZERO 44 L43 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L48_51; // GOTO
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_locals[117] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(84)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L53_55; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L53_55; // GOTO
    bcpl_push(bcpl_load_indirect(83)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L54_56; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L54_56; // GOTO
    bcpl_push(bcpl_load_indirect(78)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L55_57; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L55_57; // GOTO
    bcpl_push(bcpl_load_indirect(69)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L56_58; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(69)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L56_58; // GOTO
    bcpl_push(bcpl_load_indirect(66)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L57_59; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L57_59; // GOTO
    bcpl_push(bcpl_load_indirect(80)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58_60; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(12)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L58_60; // GOTO
    bcpl_push(bcpl_load_indirect(67)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L59_61; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(13)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L59_61; // GOTO
    bcpl_push(bcpl_load_indirect(88)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L60_62; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 L11 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L60_62; // GOTO
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L61_63; } // BRANCH_IF_NEQ
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(57)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L61_63; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 L8 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(64)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 L11 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(255)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L62_64; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L62_64; // GOTO
    goto L61_63; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L47_50; // CALL (as GOTO)
    goto L46_49; // GOTO
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(117); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L63_65; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(133); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[133] = bcpl_pop(); // STORE_LOCAL
    goto L63_65; // GOTO
    goto L47_50; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L44_47:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L44_47; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 14
    L10_9:
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_72 72 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L95_94; } // BRANCH_IF_EQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L65_67; // CALL (as GOTO)
    goto L66_68; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L67_69:
    goto L67_69; // GOTO
    // UNKNOWN_93 93 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // JUMP_IF_ZERO 44 L8 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_23 23 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L68_70; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    goto L68_70; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L65_67; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L66_68; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L64_66:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L64_66; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L12_10; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_126 126 - not implemented
    L1_1:
    // UNKNOWN_131 131 - not implemented
    L2_0:
    // UNKNOWN_118 118 - not implemented
    L3_4:
    // UNKNOWN_119 119 - not implemented
    L4_5:
    // UNKNOWN_197 197 - not implemented
    L5_6:
    // UNKNOWN_112 112 - not implemented
    L6_8:
    // UNKNOWN_113 113 - not implemented
    L9_3:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_48 48 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L11
    // LOOP_END L10
    goto L12_10; // CALL (as GOTO)
    // FUNCTION_START 6
    L1_1:
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L86_85; } // BRANCH_IF_NEQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L14_12; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[192] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(98)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L14_12; // GOTO
    bcpl_push(168); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L13_11:
    goto L13_11; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L2_0:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
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
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L15_13:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L15_13; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L3_4:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_50 50 - not implemented
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
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L16_14:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L16_14; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L4_5:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
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
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L17_15:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L17_15; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L5_6:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_52 52 - not implemented
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
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L18_16:
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L18_16; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L6_8:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_53 53 - not implemented
    // FUNCTION_END 7
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L19_17:
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    goto L19_17; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L7_36:
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_54 54 - not implemented
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
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(5)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L20_18:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L20_18; // GOTO
    // UNKNOWN_93 93 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L8_7:
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    // FUNCTION_END 2
    // JUMP_IF_NOT_ZERO 45 3 - not implemented
    bcpl_push(bcpl_globals[67]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[100] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L22_21; // CALL (as GOTO)
    goto L23_37; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_push(100); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_67 67 - not implemented
    goto L22_21; // GOTO
    bcpl_push(bcpl_locals[67]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L23_37; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[67]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[132] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_NOT_ZERO 45 68 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L24_20; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L21_19:
    goto L24_20; // GOTO
    // JUMP_IF_NOT_ZERO 45 90 - not implemented
    bcpl_push(bcpl_globals[219]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[89]); // LOAD_LOCAL
    bcpl_locals[106] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_NOT_ZERO 45 220 - not implemented
    bcpl_push(bcpl_globals[477]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_locals[219]); // LOAD_LOCAL
    bcpl_locals[108] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[109] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_NOT_ZERO 45 478 - not implemented
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L26
    // LOOP_END L25
    bcpl_push(bcpl_locals[477]); // LOAD_LOCAL
    bcpl_locals[148] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L27_25; // CALL (as GOTO)
    goto L28_24; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    bcpl_push(148); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_579 579 - not implemented
    goto L27_25; // GOTO
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[580]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L28_24; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(121); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 579]); // DUPLICATE
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_ZERO 44 L26 - not implemented
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L25_22; } // BRANCH_IF_LT
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 579]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(128); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29_26; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    goto L7_36; // JUMP
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_73 73 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 32]); // DUPLICATE
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 579]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30_27; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L21_19:
    goto L30_27; // GOTO
    // JUMP_IF_ZERO 44 L26 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L29_26; // GOTO
    // LOOP_START L32
    // LOOP_END L31
    goto L33_31; // CALL (as GOTO)
    // FUNCTION_START 5
    L31_29:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
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
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L35_38; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(95)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L35_38; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37_40; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 L32 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L36_39:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L37_40; // GOTO
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L36_39:
    goto L36_39; // GOTO
    // UNKNOWN_93 93 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L34_32:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L34_32; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    goto L33_31; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(49)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39_42; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(49)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 L32 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38_41:
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    goto L39_42; // GOTO
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41_44; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 L32 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40_43:
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    goto L41_44; // GOTO
    bcpl_push(bcpl_globals[581]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40_43:
    goto L40_43; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38_41:
    goto L38_41; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_579 579 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42_45; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[582]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(99)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 580]); // DUPLICATE
    goto L42_45; // GOTO
    bcpl_push(bcpl_locals[579]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L21_19:
    bcpl_push(bcpl_globals[579]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[477]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[219]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[89]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[67]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L21_19; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L9_3:
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 4
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(191); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[191] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L29_26; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L32_30; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L11 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(131); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(191); // LOAD_CONSTANT
    bcpl_push(192); // LOAD_CONSTANT
    // UNKNOWN_23 23 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L43_46; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L21_19; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L43_46; // GOTO
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_locals[122] = bcpl_pop(); // STORE_LOCAL
    goto L45_48; // CALL (as GOTO)
    goto L44_47; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L45_48; // GOTO
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46_49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46_49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(74)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46_49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46_49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L46_49; // CONDITIONAL_JUMP
    bcpl_push(122); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L44_47; } // BRANCH_IF_NEQ
    goto L46_49; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(135); // LOAD_CONSTANT
    bcpl_push(136); // LOAD_CONSTANT
    bcpl_push(32); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L10_9:
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 4
    goto L48_51; // CALL (as GOTO)
    goto L50_52; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L8_7; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L51_53; // GOTO
    goto L18_16; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L84_34; } // BRANCH_IF_EQ
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L52_54; // GOTO
    goto L17_15; // JUMP
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L53_55; // GOTO
    goto L16_14; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L54_56; // GOTO
    goto L11_2; // JUMP
    // UNKNOWN_78 78 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_80 80 - not implemented
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L55_57; // GOTO
    goto L17_15; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    if (bcpl_pop()) goto L69_28; // CONDITIONAL_JUMP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L56_58; // GOTO
    goto L17_15; // JUMP
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L57_59; // GOTO
    goto L21_19; // JUMP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L58_60; // GOTO
    goto L59_61; // GOTO
    goto L60_62; // GOTO
    goto L13_11; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L61_63; // GOTO
    goto L13_11; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    bcpl_push(bcpl_locals[39]); // LOAD_LOCAL
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L62_64; // GOTO
    goto L13_11; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L63_65; // GOTO
    goto L22_21; // JUMP
    goto L78_78; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L64_66; // GOTO
    goto L19_17; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L65_67; // GOTO
    goto L10_9; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    goto L77_35; // CALL (as GOTO)
    // UNKNOWN_66 66 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L66_68; // GOTO
    goto L32_30; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L67_69; // GOTO
    goto L68_70; // GOTO
    goto L69_28; // GOTO
    goto L11_2; // JUMP
    // UNKNOWN_39 39 - not implemented
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L70_71; // GOTO
    goto L26_23; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L71_72; // GOTO
    goto L21_19; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    goto L82_82; // CALL (as GOTO)
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_72 72 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L72_73; // GOTO
    goto L73_74; // GOTO
    goto L15_13; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L74_75; // GOTO
    goto L14_12; // JUMP
    goto L78_78; // CALL (as GOTO)
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L75_76; // GOTO
    goto L16_14; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L76_77; // GOTO
    goto L15_13; // JUMP
    // UNKNOWN_39 39 - not implemented
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L77_35; // GOTO
    goto L78_78; // GOTO
    goto L12_10; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L79_79; // GOTO
    goto L15_13; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L80_80; // GOTO
    goto L81_81; // GOTO
    goto L12_10; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L82_82; // GOTO
    goto L12_10; // JUMP
    // UNKNOWN_39 39 - not implemented
    bcpl_push(bcpl_load_indirect(47)); // LOAD_INDIRECT
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47_50:
    goto L49_33; // CALL (as GOTO)
    goto L48_51; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    L50_52:
    bcpl_push(bcpl_globals[L51]); // LOAD_GLOBAL
    // FUNCTION_START L52
    // FUNCTION_END L53
    // UNKNOWN_96 96 - not implemented
    L54_56:
    return; // RETURN
    L55_57:
    // UNKNOWN_98 98 - not implemented
    L56_58:
    // UNKNOWN_99 99 - not implemented
    L57_59:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L58_60:
    bcpl_push(bcpl_locals[L59]); // LOAD_LOCAL
    goto L60_62; // JUMP
    bcpl_push(bcpl_rdline()); // READ_LINE
    L61_63:
    // UNKNOWN_7 7 - not implemented
    L62_64:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L63_65:
    // UNKNOWN_32 32 - not implemented
    L64_66:
    // UNKNOWN_33 33 - not implemented
    L65_67:
    // UNKNOWN_34 34 - not implemented
    L66_68:
    bcpl_push(-bcpl_pop()); // NEGATE
    L67_69:
    // UNKNOWN_19 19 - not implemented
    L68_70:
    bcpl_push(L69); // LOAD_CONSTANT
    // UNKNOWN_30 30 - not implemented
    L70_71:
    bcpl_push(bcpl_load_indirect(L71)); // LOAD_INDIRECT
    // JUMP_IF_ZERO 44 L72 - not implemented
    // JUMP_IF_NOT_ZERO 45 L73 - not implemented
    // UNKNOWN_50 50 - not implemented
    L74_75:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L75]); // DUPLICATE
    // UNKNOWN_54 54 - not implemented
    L76_77:
    // UNKNOWN_57 57 - not implemented
    L77_35:
    // UNKNOWN_58 58 - not implemented
    L78_78:
    // UNKNOWN_60 60 - not implemented
    L79_79:
    // UNKNOWN_61 61 - not implemented
    L80_80:
    // UNKNOWN_62 62 - not implemented
    L81_81:
    // UNKNOWN_63 63 - not implemented
    L82_82:
    goto L49_33; // GOTO
    goto L47_50; // GOTO
    // UNKNOWN_93 93 - not implemented
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
    goto L12_10; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_167 167 - not implemented
    L1_1:
    // UNKNOWN_161 161 - not implemented
    L2_0:
    // UNKNOWN_162 162 - not implemented
    L3_4:
    // UNKNOWN_163 163 - not implemented
    L4_5:
    // UNKNOWN_164 164 - not implemented
    L5_6:
    // UNKNOWN_165 165 - not implemented
    L6_8:
    // UNKNOWN_166 166 - not implemented
    L7_36:
    // UNKNOWN_150 150 - not implemented
    L8_7:
    // UNKNOWN_151 151 - not implemented
    L9_3:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // FUNCTION_HEADER - 91 parameters
    // UNKNOWN_2 2 - not implemented
    goto L9_3; // CALL (as GOTO)
    // FUNCTION_START 11
    L1_1:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_66 66 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_66 66 - not implemented
    // PUSH_STRING - string handling
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L95_94; } // BRANCH_IF_LT
    // UNKNOWN_2 2 - not implemented
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
    // JUMP_IF_ZERO 44 L12 - not implemented
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L13_11; // CALL (as GOTO)
    goto L15_13; // GOTO
    goto L16_14; // GOTO
    goto L17_15; // GOTO
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
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L14_12; // CALL (as GOTO)
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L18_16; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(145); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L11_2; } // BRANCH_IF_LT
    goto L20_18; // CALL (as GOTO)
    goto L19_17; // GOTO
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
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L20_18; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L19_17; // CONDITIONAL_JUMP
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
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L14_12; // CALL (as GOTO)
    goto L21_19; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L22_21; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L22_21; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L22_21; // GOTO
    goto L23_37; // GOTO
    goto L24_20; // GOTO
    goto L14_12; // CALL (as GOTO)
    goto L13_11; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdline()); // READ_LINE
    L21_19:
    // UNKNOWN_75 75 - not implemented
    L15_13:
    // PUSH_STRING - string handling
    L16_14:
    // STRING_CONSTANT definition
    L17_15:
    // UNKNOWN_74 74 - not implemented
    L18_16:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    L23_37:
    goto L24_20; // GOTO
    goto L14_12; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L10_9:
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L10_9; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L2_0:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    bcpl_locals[95] = bcpl_pop(); // STORE_LOCAL
    // UNKNOWN_2 2 - not implemented
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
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L27_25; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(90)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26_23; } // BRANCH_IF_NEQ
    goto L27_25; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L25_22:
    goto L26_23; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(73)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L25_22:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L25_22; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L3_4:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_67 67 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 2 - not implemented
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
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    // JUMP_IF_ZERO 44 L30 - not implemented
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    goto L31_29; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L34_32; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L32_30; } // BRANCH_IF_NEQ
    goto L34_32; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L33_31; // CALL (as GOTO)
    goto L32_30; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L33_31; // GOTO
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
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L29_26; } // BRANCH_IF_LT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L31_29; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[135] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[136] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L28_24:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L28_24; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L4_5:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
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
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(92)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L36_39; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(7)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L36_39; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37_40; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L38_41; // CALL (as GOTO)
    goto L37_40; // GOTO
    bcpl_push(134); // LOAD_CONSTANT
    bcpl_push(116); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39_42; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[115] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L39_42; // GOTO
    goto L38_41; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L35_38:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L35_38; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L5_6:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L41_44; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L40_43:
    goto L41_44; // GOTO
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
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L40_43:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L40_43; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 5
    L6_8:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
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
    L42_45:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L42_45; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L7_36:
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_78 78 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L43_46; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L43_46; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L8_7:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_75 75 - not implemented
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // FUNCTION_END 4
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L44_47; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L44_47; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L9_3; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_140 140 - not implemented
    L1_1:
    // UNKNOWN_156 156 - not implemented
    L2_0:
    // UNKNOWN_147 147 - not implemented
    L3_4:
    // UNKNOWN_141 141 - not implemented
    L4_5:
    // UNKNOWN_142 142 - not implemented
    L5_6:
    // UNKNOWN_143 143 - not implemented
    L6_8:
    // UNKNOWN_154 154 - not implemented
    L7_36:
    // UNKNOWN_153 153 - not implemented
    L8_7:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_50 50 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L3_4; // CALL (as GOTO)
    // FUNCTION_START 5
    L1_1:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_66 66 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L5_6; // CALL (as GOTO)
    goto L7_36; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L8_7; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(16)); // LOAD_INDIRECT
    bcpl_push(161); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L9_3; // GOTO
    goto L10_9; // GOTO
    goto L11_2; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L12_10; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(167); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(107); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L13_11; // CALL (as GOTO)
    goto L14_12; // GOTO
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
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L13_11; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L14_12; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L15_13; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(101); // LOAD_CONSTANT
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L16_14; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(15)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L17_15; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(6)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L18_16; // GOTO
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L19_17; // GOTO
    goto L20_18; // GOTO
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
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L21_19; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L22_21; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L23_37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_17 17 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    goto L24_20; // CALL (as GOTO)
    goto L23_37; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(17)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L24_20; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L25_22; // GOTO
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
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L26_23; // GOTO
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
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L27_25; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(39)); // LOAD_INDIRECT
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L4_5:
    goto L6_8; // CALL (as GOTO)
    goto L5_6; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_16 16 - not implemented
    L7_36:
    // UNKNOWN_16 16 - not implemented
    L8_7:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L9_3:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L10_9:
    // UNKNOWN_2 2 - not implemented
    L11_2:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L12_10:
    // UNKNOWN_1 1 - not implemented
    L15_13:
    // UNKNOWN_105 105 - not implemented
    L16_14:
    bcpl_push(bcpl_rdline()); // READ_LINE
    L17_15:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L18_16:
    // UNKNOWN_7 7 - not implemented
    L19_17:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L20_18:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L21_19:
    bcpl_push(-bcpl_pop()); // NEGATE
    L22_21:
    // UNKNOWN_30 30 - not implemented
    L25_22:
    // UNKNOWN_19 19 - not implemented
    L26_23:
    // UNKNOWN_39 39 - not implemented
    L27_25:
    goto L6_8; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4_5; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L2_0:
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
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
    goto L29_26; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L31
    // LOOP_END L30
    // LOOP_START L33
    // LOOP_END L32
    bcpl_push(122); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L34_32; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L28_24:
    goto L34_32; // GOTO
    goto L35_38; // CALL (as GOTO)
    goto L37_40; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L28_24:
    goto L38_41; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L39_42; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L39_42; // GOTO
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
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29_26; // CALL (as GOTO)
    goto L40_43; // GOTO
    bcpl_push(bcpl_load_indirect(36)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L41_44; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L42_45; // GOTO
    goto L43_46; // GOTO
    goto L44_47; // GOTO
    bcpl_push(bcpl_load_indirect(35)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L45_48; // GOTO
    goto L46_49; // GOTO
    bcpl_push(bcpl_load_indirect(34)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L47_50; // GOTO
    goto L48_51; // GOTO
    goto L49_33; // GOTO
    goto L50_52; // GOTO
    goto L51_53; // GOTO
    goto L52_54; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    // UNKNOWN_25 25 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L53_55; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L28_24:
    goto L53_55; // GOTO
    goto L54_56; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L55_57; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L56_58; // CALL (as GOTO)
    goto L55_57; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(33)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L56_58; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // UNKNOWN_24 24 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L57_59; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(25)); // LOAD_INDIRECT
    // UNKNOWN_24 24 - not implemented
    if (bcpl_pop()) goto L54_56; // CONDITIONAL_JUMP
    goto L57_59; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29_26; // CALL (as GOTO)
    goto L58_60; // GOTO
    goto L59_61; // GOTO
    bcpl_push(bcpl_load_indirect(25)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_push(bcpl_load_indirect(30)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // JUMP_IF_ZERO 44 L31 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L60_62; // GOTO
    bcpl_push(bcpl_load_indirect(23)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L61_63; // GOTO
    bcpl_push(bcpl_load_indirect(22)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L62_64; // GOTO
    goto L63_65; // GOTO
    bcpl_push(bcpl_load_indirect(21)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    // JUMP_IF_ZERO 44 L33 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L64_66; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(13)); // LOAD_INDIRECT
    // UNKNOWN_25 25 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L65_67; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L28_24:
    goto L65_67; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
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
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29_26; // CALL (as GOTO)
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32_30; } // BRANCH_IF_LT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L30_27; } // BRANCH_IF_LT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    // UNKNOWN_25 25 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L66_68; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L28_24:
    goto L66_68; // GOTO
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
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L29_26; // CALL (as GOTO)
    goto L36_39; // CALL (as GOTO)
    goto L35_38; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_21 21 - not implemented
    L37_40:
    // UNKNOWN_105 105 - not implemented
    L38_41:
    // UNKNOWN_28 28 - not implemented
    L40_43:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L41_44:
    // UNKNOWN_13 13 - not implemented
    L42_45:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L43_46:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L44_47:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L45_48:
    bcpl_push(-bcpl_pop()); // NEGATE
    L46_49:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L47_50:
    // UNKNOWN_21 21 - not implemented
    L48_51:
    // UNKNOWN_24 24 - not implemented
    L49_33:
    // UNKNOWN_25 25 - not implemented
    L50_52:
    // UNKNOWN_22 22 - not implemented
    L51_53:
    // UNKNOWN_23 23 - not implemented
    L52_54:
    // UNKNOWN_31 31 - not implemented
    L58_60:
    // UNKNOWN_32 32 - not implemented
    L59_61:
    // UNKNOWN_33 33 - not implemented
    L60_62:
    // UNKNOWN_34 34 - not implemented
    L61_63:
    // UNKNOWN_35 35 - not implemented
    L62_64:
    // UNKNOWN_36 36 - not implemented
    L63_65:
    // UNKNOWN_37 37 - not implemented
    L64_66:
    goto L36_39; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L29_26; // CALL (as GOTO)
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L28_24; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L3_4; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L68_70; // CALL (as GOTO)
    // FUNCTION_START 8
    L67_69:
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 2 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L70_71; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L71_72; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L69_28:
    goto L71_72; // GOTO
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
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L70_71; // CALL (as GOTO)
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L69_28; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L68_70; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L73_74; // CALL (as GOTO)
    // FUNCTION_START 4
    L72_73:
    // UNKNOWN_82 82 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L75_76; // CALL (as GOTO)
    goto L77_35; // GOTO
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
    if (bcpl_pop()) goto L78_78; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L78_78; // GOTO
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79_79; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L79_79; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(89)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L80_80; } // BRANCH_IF_NEQ
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
    L74_75:
    goto L80_80; // GOTO
    bcpl_push(bcpl_load_indirect(20)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L81_81; } // BRANCH_IF_NEQ
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
    L74_75:
    goto L81_81; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L82_82; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L83_83; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(103)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L84_34; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L85_84; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(43)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L85_84; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L74_75:
    goto L84_34; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(41)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L74_75:
    goto L76_77; // CALL (as GOTO)
    goto L75_76; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_2 2 - not implemented
    L82_82:
    // UNKNOWN_105 105 - not implemented
    L77_35:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L83_83:
    goto L76_77; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L74_75; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L73_74; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_174 174 - not implemented
    L1_1:
    // UNKNOWN_144 144 - not implemented
    L2_0:
    // UNKNOWN_155 155 - not implemented
    L67_69:
    // UNKNOWN_145 145 - not implemented
    L72_73:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_52 52 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L2
    // LOOP_END L1
    goto L4_5; // CALL (as GOTO)
    // FUNCTION_START 5
    L1_1:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L6_8; // CALL (as GOTO)
    goto L8_7; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L9_3; // GOTO
    goto L10_9; // GOTO
    goto L11_2; // GOTO
    goto L12_10; // GOTO
    goto L13_11; // GOTO
    goto L14_12; // GOTO
    goto L15_13; // GOTO
    goto L16_14; // GOTO
    goto L17_15; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_indirect(50)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L18_16; } // BRANCH_IF_NEQ
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
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
    L5_6:
    goto L18_16; // GOTO
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19_17; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L20_18; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(50)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L20_18; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 L2 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(164); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L19_17; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21_19; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L21_19; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L22_21; // GOTO
    goto L23_37; // GOTO
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
    L5_6:
    goto L24_20; // GOTO
    goto L25_22; // GOTO
    goto L26_23; // GOTO
    goto L27_25; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
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
    L5_6:
    goto L28_24; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(154); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
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
    L5_6:
    goto L29_26; // GOTO
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
    // UNKNOWN_2 2 - not implemented
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
    bcpl_push(bcpl_rdline()); // READ_LINE
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30_27; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    goto L30_27; // GOTO
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
    L5_6:
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L31_29; // GOTO
    goto L32_30; // GOTO
    goto L33_31; // GOTO
    goto L34_32; // GOTO
    goto L35_38; // GOTO
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L36_39; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
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
    L5_6:
    goto L37_40; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(144); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(54)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(153); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(71)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 L2 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(163); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L38_41; // GOTO
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
    // JUMP_IF_ZERO 44 L2 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L39_42; // GOTO
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L7_36; // CALL (as GOTO)
    goto L6_8; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    // TEMP_VAR allocation
    // UNKNOWN_26 26 - not implemented
    L8_7:
    // UNKNOWN_2 2 - not implemented
    L9_3:
    // UNKNOWN_1 1 - not implemented
    L10_9:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L11_2:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L12_10:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L13_11:
    // UNKNOWN_7 7 - not implemented
    L14_12:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L15_13:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L16_14:
    // UNKNOWN_105 105 - not implemented
    L17_15:
    // UNKNOWN_52 52 - not implemented
    L22_21:
    // UNKNOWN_53 53 - not implemented
    L23_37:
    // UNKNOWN_57 57 - not implemented
    L24_20:
    // UNKNOWN_58 58 - not implemented
    L25_22:
    // UNKNOWN_59 59 - not implemented
    L26_23:
    // UNKNOWN_60 60 - not implemented
    L27_25:
    // UNKNOWN_55 55 - not implemented
    L28_24:
    // UNKNOWN_56 56 - not implemented
    L29_26:
    // UNKNOWN_65 65 - not implemented
    L31_29:
    // UNKNOWN_66 66 - not implemented
    L32_30:
    // UNKNOWN_67 67 - not implemented
    L33_31:
    bcpl_pop(); // POP
    L34_32:
    // LOCAL_VAR allocation
    L35_38:
    // TEMP_VAR allocation
    L36_39:
    // UNKNOWN_71 71 - not implemented
    L37_40:
    // UNKNOWN_72 72 - not implemented
    L38_41:
    bcpl_push(bcpl_globals[L39]); // LOAD_GLOBAL
    goto L7_36; // GOTO
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5_6; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L3_4:
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 L2 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_2 2 - not implemented
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41_44; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(51)); // LOAD_INDIRECT
    bcpl_push(151); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L41_44; // GOTO
    goto L43_46; // CALL (as GOTO)
    goto L42_45; // GOTO
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L44_47; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(162); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    goto L45_48; // CALL (as GOTO)
    goto L44_47; // GOTO
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
    // UNKNOWN_2 2 - not implemented
    goto L45_48; // GOTO
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L43_46; // GOTO
    bcpl_push(bcpl_load_indirect(61)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42_45; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42_45; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(63)); // LOAD_INDIRECT
    bcpl_push(115); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L42_45; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L40_43:
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L40_43; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4_5; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_146 146 - not implemented
    L3_4:
    // FUNCTION_HEADER - 5 parameters
    // UNKNOWN_80 80 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // CALL (as GOTO)
    // FUNCTION_START 5
    L1_1:
    // UNKNOWN_80 80 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 5
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // LOOP_START L3
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_47 47 - not implemented
    L3_4:
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L4_5; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L3_4; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L4_5; // GOTO
    goto L5_6; // CALL (as GOTO)
    goto L7_36; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(62); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L8_7; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L9_3; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L4_5; // JUMP
    // UNKNOWN_34 34 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_34 34 - not implemented
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L10_9; // GOTO
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L11_2; // GOTO
    goto L12_10; // GOTO
    goto L13_11; // GOTO
    goto L14_12; // GOTO
    goto L15_13; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L16_14; // GOTO
    goto L17_15; // GOTO
    goto L18_16; // GOTO
    goto L19_17; // GOTO
    goto L20_18; // GOTO
    goto L21_19; // GOTO
    goto L22_21; // GOTO
    goto L23_37; // GOTO
    goto L24_20; // GOTO
    goto L25_22; // GOTO
    goto L26_23; // GOTO
    goto L27_25; // GOTO
    goto L28_24; // GOTO
    goto L29_26; // GOTO
    goto L30_27; // GOTO
    goto L31_29; // GOTO
    goto L32_30; // GOTO
    goto L33_31; // GOTO
    goto L34_32; // GOTO
    goto L35_38; // GOTO
    goto L36_39; // GOTO
    goto L37_40; // GOTO
    goto L38_41; // GOTO
    goto L39_42; // GOTO
    goto L40_43; // GOTO
    goto L41_44; // GOTO
    goto L42_45; // GOTO
    goto L43_46; // GOTO
    goto L44_47; // GOTO
    goto L45_48; // GOTO
    goto L46_49; // GOTO
    goto L47_50; // GOTO
    goto L48_51; // GOTO
    goto L49_33; // GOTO
    goto L50_52; // GOTO
    goto L51_53; // GOTO
    goto L52_54; // GOTO
    goto L53_55; // GOTO
    goto L54_56; // GOTO
    goto L55_57; // GOTO
    goto L56_58; // GOTO
    goto L57_59; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L58_60; // GOTO
    goto L59_61; // GOTO
    goto L60_62; // GOTO
    goto L61_63; // GOTO
    goto L62_64; // GOTO
    goto L63_65; // GOTO
    goto L64_66; // GOTO
    goto L65_67; // GOTO
    goto L66_68; // GOTO
    goto L67_69; // GOTO
    goto L68_70; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L69_28; // GOTO
    goto L70_71; // GOTO
    goto L71_72; // GOTO
    goto L72_73; // GOTO
    goto L73_74; // GOTO
    goto L74_75; // GOTO
    goto L75_76; // GOTO
    goto L76_77; // GOTO
    goto L77_35; // GOTO
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L78_78; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L3_4; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    return; // RETURN
    goto L78_78; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L2_0; // JUMP
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
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
    goto L79_79; // CALL (as GOTO)
    goto L80_80; // GOTO
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L81_81; // CALL (as GOTO)
    goto L82_82; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    goto L81_81; // GOTO
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[10]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L82_82; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    goto L2_0; // JUMP
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L84_34; } // BRANCH_IF_NEQ
    goto L2_0; // JUMP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_98 98 - not implemented
    L83_83:
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L84_34; // GOTO
    goto L2_0; // JUMP
    // UNKNOWN_33 33 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_98 98 - not implemented
    L83_83:
    goto L83_83; // GOTO
    // UNKNOWN_93 93 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    // UNKNOWN_7 7 - not implemented
    goto L79_79; // GOTO
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    return; // RETURN
    goto L6_8; // CALL (as GOTO)
    goto L5_6; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // TEMP_VAR allocation
    L77_35:
    // UNKNOWN_1 1 - not implemented
    L7_36:
    // UNKNOWN_2 2 - not implemented
    L8_7:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L9_3:
    // UNKNOWN_56 56 - not implemented
    L10_9:
    // UNKNOWN_37 37 - not implemented
    L11_2:
    // JUMP_IF_ZERO 44 L12 - not implemented
    // JUMP_IF_NOT_ZERO 45 L13 - not implemented
    // UNKNOWN_55 55 - not implemented
    L14_12:
    goto L15_13; // JUMP
    // UNKNOWN_48 48 - not implemented
    L16_14:
    // FUNCTION_HEADER - L17 parameters
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L18_16:
    // UNKNOWN_28 28 - not implemented
    L19_17:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    L20_18:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L21_19:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L22_21:
    // UNKNOWN_13 13 - not implemented
    L23_37:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L24_20:
    bcpl_push(-bcpl_pop()); // NEGATE
    L25_22:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L26_23:
    // UNKNOWN_21 21 - not implemented
    L27_25:
    // UNKNOWN_22 22 - not implemented
    L28_24:
    // UNKNOWN_23 23 - not implemented
    L29_26:
    // UNKNOWN_24 24 - not implemented
    L30_27:
    // UNKNOWN_25 25 - not implemented
    L31_29:
    // UNKNOWN_31 31 - not implemented
    L32_30:
    // UNKNOWN_32 32 - not implemented
    L33_31:
    // UNKNOWN_33 33 - not implemented
    L34_32:
    // UNKNOWN_34 34 - not implemented
    L35_38:
    // UNKNOWN_35 35 - not implemented
    L36_39:
    // UNKNOWN_36 36 - not implemented
    L37_40:
    // UNKNOWN_38 38 - not implemented
    L38_41:
    bcpl_push(bcpl_locals[L39]); // LOAD_LOCAL
    bcpl_push(L40); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(L41)); // LOAD_INDIRECT
    // UNKNOWN_50 50 - not implemented
    L42_45:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L43]); // DUPLICATE
    // UNKNOWN_54 54 - not implemented
    L44_47:
    // UNKNOWN_57 57 - not implemented
    L45_48:
    // UNKNOWN_58 58 - not implemented
    L46_49:
    // UNKNOWN_59 59 - not implemented
    L47_50:
    // UNKNOWN_60 60 - not implemented
    L48_51:
    // UNKNOWN_62 62 - not implemented
    L49_33:
    // UNKNOWN_63 63 - not implemented
    L50_52:
    // TEMP_VAR allocation
    L51_53:
    // UNKNOWN_71 71 - not implemented
    L52_54:
    // UNKNOWN_73 73 - not implemented
    L53_55:
    // UNKNOWN_74 74 - not implemented
    L54_56:
    // UNKNOWN_75 75 - not implemented
    L55_57:
    // PUSH_STRING - string handling
    L56_58:
    // STRING_CONSTANT definition
    L57_59:
    bcpl_push(bcpl_rdline()); // READ_LINE
    L58_60:
    // UNKNOWN_7 7 - not implemented
    L59_61:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L60_62:
    // UNKNOWN_17 17 - not implemented
    L61_63:
    // UNKNOWN_30 30 - not implemented
    L62_64:
    // UNKNOWN_39 39 - not implemented
    L63_65:
    // UNKNOWN_52 52 - not implemented
    L64_66:
    // UNKNOWN_53 53 - not implemented
    L65_67:
    // UNKNOWN_61 61 - not implemented
    L66_68:
    // UNKNOWN_72 72 - not implemented
    L67_69:
    // UNKNOWN_19 19 - not implemented
    L68_70:
    // UNKNOWN_65 65 - not implemented
    L69_28:
    // UNKNOWN_66 66 - not implemented
    L70_71:
    // UNKNOWN_67 67 - not implemented
    L71_72:
    bcpl_pop(); // POP
    L72_73:
    // LOCAL_VAR allocation
    L73_74:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L74_75:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L75_76:
    // UNKNOWN_16 16 - not implemented
    L76_77:
    goto L6_8; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_152 152 - not implemented
    L1_1:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_48 48 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L4
    // LOOP_END L3
    goto L5_6; // CALL (as GOTO)
    // FUNCTION_START 9
    L1_1:
    // UNKNOWN_78 78 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L84_34; } // BRANCH_IF_EQ
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // FUNCTION_END 2
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(244); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[244] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(244); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L6_8:
    goto L6_8; // GOTO
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 11
    L2_0:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_84 84 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L7_36; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L21_19; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    bcpl_push(30); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L7_36; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L11_2; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_80 80 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L4 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    goto L22_21; // JUMP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
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
    L3_4:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    goto L9_3; // CALL (as GOTO)
    goto L11_2; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L18_16; // JUMP
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(76); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L12_10; // GOTO
    goto L14_12; // JUMP
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32_30; } // BRANCH_IF_LT
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L13_11; // GOTO
    goto L38_41; // JUMP
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    goto L83_83; // CALL (as GOTO)
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_75 75 - not implemented
    // JUMP_IF_ZERO 44 32 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    goto L76_77; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L14_12; // GOTO
    goto L15_13; // GOTO
    goto L30_27; // JUMP
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_32 32 - not implemented
    goto L83_83; // CALL (as GOTO)
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    // TEMP_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_65 65 - not implemented
    goto L76_77; // CALL (as GOTO)
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L16_14; // GOTO
    goto L28_24; // JUMP
    // UNKNOWN_84 84 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79_79; } // BRANCH_IF_NEQ
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73_74; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L17_15; // GOTO
    goto L16_14; // JUMP
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32_30; } // BRANCH_IF_LT
    // UNKNOWN_71 71 - not implemented
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L18_16; // GOTO
    goto L19_17; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73_74; } // BRANCH_IF_NEQ
    // UNKNOWN_67 67 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L19_17; // GOTO
    goto L23_37; // JUMP
    // UNKNOWN_84 84 - not implemented
    // PUSH_STRING - string handling
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L32_30; } // BRANCH_IF_LT
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L20_18; // GOTO
    goto L17_15; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L21_19; // GOTO
    goto L26_23; // JUMP
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_32 32 - not implemented
    // TEMP_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    if (bcpl_pop()) goto L65_67; // CONDITIONAL_JUMP
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    goto L83_83; // CALL (as GOTO)
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L22_21; // GOTO
    goto L23_37; // GOTO
    goto L24_20; // GOTO
    goto L28_24; // JUMP
    // LOCAL_VAR allocation
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_82 82 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L25_22; // GOTO
    goto L26_23; // GOTO
    goto L24_20; // JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L27_25; // GOTO
    goto L28_24; // GOTO
    goto L25_22; // JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_84 84 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L80_80; } // BRANCH_IF_LT
    // LOCAL_VAR allocation
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // UNKNOWN_82 82 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // LOCAL_VAR allocation
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L80_80; } // BRANCH_IF_EQ
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    bcpl_pop(); // POP
    // UNKNOWN_98 98 - not implemented
    L8_7:
    goto L10_9; // CALL (as GOTO)
    goto L9_3; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_17 17 - not implemented
    L11_2:
    // UNKNOWN_141 141 - not implemented
    L12_10:
    // UNKNOWN_104 104 - not implemented
    L13_11:
    // LOOP_END L14
    // UNKNOWN_105 105 - not implemented
    L15_13:
    // UNKNOWN_106 106 - not implemented
    L16_14:
    // UNKNOWN_144 144 - not implemented
    L17_15:
    // UNKNOWN_142 142 - not implemented
    L18_16:
    // UNKNOWN_143 143 - not implemented
    L19_17:
    // UNKNOWN_115 115 - not implemented
    L20_18:
    // UNKNOWN_116 116 - not implemented
    L21_19:
    // UNKNOWN_117 117 - not implemented
    L22_21:
    // UNKNOWN_118 118 - not implemented
    L23_37:
    // UNKNOWN_119 119 - not implemented
    L24_20:
    // UNKNOWN_110 110 - not implemented
    L25_22:
    // UNKNOWN_112 112 - not implemented
    L26_23:
    // UNKNOWN_109 109 - not implemented
    L27_25:
    // UNKNOWN_113 113 - not implemented
    L28_24:
    goto L10_9; // GOTO
    goto L8_7; // GOTO
    // UNKNOWN_93 93 - not implemented
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
    goto L5_6; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L30_27; // CALL (as GOTO)
    // FUNCTION_START 9
    L29_26:
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STRING_CONSTANT definition
    // LOCAL_VAR allocation
    // UNKNOWN_65 65 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    // JUMP_IF_NOT_ZERO 45 4 - not implemented
    bcpl_push(bcpl_globals[1505]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 1506 - not implemented
    bcpl_push(bcpl_globals[1707]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 1708 - not implemented
    bcpl_push(bcpl_globals[2009]); // LOAD_GLOBAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // JUMP_IF_NOT_ZERO 45 2010 - not implemented
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
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    if (bcpl_pop()) goto L31_29; // CONDITIONAL_JUMP
    goto L32_30; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(49)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L33_31; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L33_31; // CONDITIONAL_JUMP
    goto L34_32; // CALL (as GOTO)
    goto L33_31; // GOTO
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
    // UNKNOWN_2 2 - not implemented
    goto L32_30; // CALL (as GOTO)
    goto L34_32; // GOTO
    goto L31_29; // GOTO
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
    goto L36_39; // CALL (as GOTO)
    goto L35_38; // GOTO
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
    // UNKNOWN_2311 2311 - not implemented
    goto L36_39; // GOTO
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(bcpl_locals[2311]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L35_38; } // BRANCH_IF_NEQ
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
    goto L30_27; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_243 243 - not implemented
    L1_1:
    // UNKNOWN_210 210 - not implemented
    L2_0:
    // UNKNOWN_245 245 - not implemented
    L29_26:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // FUNCTION_HEADER - 91 parameters
    // UNKNOWN_2 2 - not implemented
    goto L2_0; // CALL (as GOTO)
    // FUNCTION_START 5
    L1_1:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // LOOP_START L4
    // LOOP_END L3
    // FUNCTION_END 3
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L3_4; } // BRANCH_IF_LT
    bcpl_push(bcpl_rdch()); // READ_CHAR
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L5_6; } // BRANCH_IF_NEQ
    return; // RETURN
    goto L5_6; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_locals[270] = bcpl_pop(); // STORE_LOCAL
    goto L6_8; // CALL (as GOTO)
    goto L8_7; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(100)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L9_3; // GOTO
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
    // UNKNOWN_7 7 - not implemented
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
    if (bcpl_pop()) goto L10_9; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(110)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L10_9; // GOTO
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L11_2; // CONDITIONAL_JUMP
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L11_2; // GOTO
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
    if (bcpl_pop()) goto L12_10; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[11]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(91)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L12_10; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L13_11; // GOTO
    goto L14_12; // GOTO
    goto L15_13; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L16_14; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    goto L16_14; // GOTO
    goto L18_16; // CALL (as GOTO)
    goto L17_15; // GOTO
    bcpl_push(bcpl_load_indirect(79)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L19_17; } // BRANCH_IF_NEQ
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
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    goto L20_18; // CALL (as GOTO)
    goto L19_17; // GOTO
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
    bcpl_push(205); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 9]); // DUPLICATE
    goto L20_18; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_locals[262] = bcpl_pop(); // STORE_LOCAL
    goto L18_16; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17_15; } // BRANCH_IF_NEQ
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
    goto L21_19; // GOTO
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
    goto L22_21; // GOTO
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
    goto L23_37; // GOTO
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
    goto L24_20; // GOTO
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
    goto L25_22; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L26_23; // GOTO
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
    goto L27_25; // GOTO
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
    goto L28_24; // GOTO
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29_26; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(104)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L29_26; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(275); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30_27; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    goto L30_27; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L31_29; // GOTO
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L32_30; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(104)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L32_30; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L33_31; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    goto L33_31; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L34_32; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(97)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L35_38; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(68)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L36_39; // GOTO
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37_40; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(104)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L37_40; // GOTO
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
    goto L38_41; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L39_42; // GOTO
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
    if (bcpl_pop()) goto L40_43; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    goto L40_43; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L41_44; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L42_45; // GOTO
    goto L43_46; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L44_47; } // BRANCH_IF_NEQ
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
    goto L45_48; // CALL (as GOTO)
    goto L44_47; // GOTO
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
    if (bcpl_pop()) goto L46_49; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L46_49; // GOTO
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L45_48; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L47_50; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 7]); // DUPLICATE
    goto L47_50; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_locals[271] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_locals[275] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L48_51; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L49_33; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(141)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L49_33; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L50_52; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L50_52; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L51_53; // CALL (as GOTO)
    goto L52_54; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(265); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L53_55; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[10]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(106)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 8]); // DUPLICATE
    goto L53_55; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    goto L51_53; // GOTO
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L52_54; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(265); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(266); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    goto L54_56; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L55_57; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L55_57; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(273); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L56_58; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(101)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L56_58; // GOTO
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
    goto L57_59; // GOTO
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58_60; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(105)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L58_60; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L59_61; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(221); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L60_62; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(222); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L61_63; // GOTO
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
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 L4 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L7_36; // CALL (as GOTO)
    goto L6_8; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // UNKNOWN_27 27 - not implemented
    L8_7:
    // UNKNOWN_74 74 - not implemented
    L9_3:
    // PUSH_STRING - string handling
    L13_11:
    // STRING_CONSTANT definition
    L14_12:
    // UNKNOWN_75 75 - not implemented
    L15_13:
    // UNKNOWN_50 50 - not implemented
    L21_19:
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - L22]); // DUPLICATE
    // UNKNOWN_52 52 - not implemented
    L23_37:
    // UNKNOWN_54 54 - not implemented
    L24_20:
    // UNKNOWN_58 58 - not implemented
    L25_22:
    // UNKNOWN_57 57 - not implemented
    L26_23:
    // UNKNOWN_55 55 - not implemented
    L27_25:
    // UNKNOWN_65 65 - not implemented
    L28_24:
    // UNKNOWN_66 66 - not implemented
    L31_29:
    // UNKNOWN_67 67 - not implemented
    L34_32:
    bcpl_pop(); // POP
    L35_38:
    // UNKNOWN_53 53 - not implemented
    L36_39:
    // UNKNOWN_59 59 - not implemented
    L38_41:
    // UNKNOWN_60 60 - not implemented
    L39_42:
    // UNKNOWN_62 62 - not implemented
    L41_44:
    // UNKNOWN_63 63 - not implemented
    L42_45:
    // UNKNOWN_61 61 - not implemented
    L43_46:
    // UNKNOWN_71 71 - not implemented
    L48_51:
    // UNKNOWN_72 72 - not implemented
    L54_56:
    // LOCAL_VAR allocation
    L57_59:
    // TEMP_VAR allocation
    L59_61:
    // UNKNOWN_56 56 - not implemented
    L60_62:
    // UNKNOWN_73 73 - not implemented
    L61_63:
    goto L7_36; // GOTO
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L2_0; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_200 200 - not implemented
    L1_1:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_50 50 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // LOOP_START L9
    // LOOP_END L8
    // LOOP_START L12
    // LOOP_END L11
    // LOOP_START L14
    // LOOP_END L13
    // LOOP_START L16
    // LOOP_END L15
    goto L17_15; // CALL (as GOTO)
    // FUNCTION_START 9
    L1_1:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L18_16; // CONDITIONAL_JUMP
    goto L19_17; // CALL (as GOTO)
    goto L21_19; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(102)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L22_21; // GOTO
    goto L23_37; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(202); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L24_20; // GOTO
    goto L25_22; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    goto L26_23; // GOTO
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
    goto L20_18; // CALL (as GOTO)
    goto L19_17; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L21_19:
    bcpl_push(bcpl_load_indirect(L22)); // LOAD_INDIRECT
    bcpl_push(L23); // LOAD_CONSTANT
    // JUMP_IF_NOT_ZERO 45 L24 - not implemented
    // JUMP_IF_ZERO 44 L25 - not implemented
    bcpl_push(bcpl_locals[L26]); // LOAD_LOCAL
    goto L20_18; // GOTO
    goto L18_16; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L2_0:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L27_25; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L28_24; } // BRANCH_IF_NEQ
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
    goto L28_24; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29_26; } // BRANCH_IF_NEQ
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
    goto L29_26; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(103)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L27_25; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L3_4:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L30_27; } // BRANCH_IF_NEQ
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31_29; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(144)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L31_29; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(285); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(286); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(285); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(286); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[286] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    goto L30_27; // GOTO
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
    L4_5:
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 3
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L9 - not implemented
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
    L5_6:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_75 75 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 4
    goto L33_31; // CALL (as GOTO)
    goto L32_30; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L35_38; // CALL (as GOTO)
    goto L34_32; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L36_39; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(142)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L36_39; // GOTO
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L35_38; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_22 22 - not implemented
    if (bcpl_pop()) goto L34_32; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    goto L33_31; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L32_30; } // BRANCH_IF_NEQ
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L6_8:
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    bcpl_pop(); // POP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 5
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(264); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L37_40; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(143)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 5]); // DUPLICATE
    goto L37_40; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(261); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[261] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 12
    L7_36:
    // UNKNOWN_67 67 - not implemented
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73_74; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 3
    bcpl_push(262); // LOAD_CONSTANT
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L39_42; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L40_43; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L39_42; } // BRANCH_IF_NEQ
    goto L40_43; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_98 98 - not implemented
    L38_41:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L38_41; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 10
    L8_7:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // LOCAL_VAR allocation
    // STRING_CONSTANT definition
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L41_44; // CONDITIONAL_JUMP
    goto L42_45; // CALL (as GOTO)
    goto L44_47; // GOTO
    return; // RETURN
    goto L45_48; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    // UNKNOWN_83 83 - not implemented
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
    goto L46_49; // GOTO
    goto L47_50; // GOTO
    goto L48_51; // GOTO
    goto L49_33; // GOTO
    goto L50_52; // GOTO
    goto L51_53; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L9 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L52_54; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L9 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L53_55; // GOTO
    goto L54_56; // GOTO
    goto L55_57; // GOTO
    goto L56_58; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L9 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L57_59; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L9 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L9 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L43_46; // CALL (as GOTO)
    goto L42_45; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // UNKNOWN_13 13 - not implemented
    L44_47:
    // UNKNOWN_54 54 - not implemented
    L45_48:
    // UNKNOWN_57 57 - not implemented
    L46_49:
    // UNKNOWN_58 58 - not implemented
    L47_50:
    // UNKNOWN_59 59 - not implemented
    L48_51:
    // UNKNOWN_60 60 - not implemented
    L49_33:
    // TEMP_VAR allocation
    L50_52:
    // UNKNOWN_71 71 - not implemented
    L51_53:
    // UNKNOWN_73 73 - not implemented
    L52_54:
    // UNKNOWN_61 61 - not implemented
    L53_55:
    // UNKNOWN_62 62 - not implemented
    L54_56:
    // UNKNOWN_63 63 - not implemented
    L55_57:
    // UNKNOWN_72 72 - not implemented
    L56_58:
    // UNKNOWN_55 55 - not implemented
    L57_59:
    goto L43_46; // GOTO
    goto L41_44; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L10_9:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L12 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L16 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58_60; } // BRANCH_IF_NEQ
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
    // JUMP_IF_ZERO 44 L14 - not implemented
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
    goto L58_60; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 12
    L11_2:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_pop(); // POP
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L78_78; } // BRANCH_IF_LT
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 3
    goto L59_61; // CALL (as GOTO)
    goto L61_63; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L12 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L12 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L62_64; // GOTO
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
    goto L63_65; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(233); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L64_66; // GOTO
    return; // RETURN
    goto L60_62; // CALL (as GOTO)
    goto L59_61; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L64_66:
    bcpl_push(bcpl_locals[L61]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(L62)); // LOAD_INDIRECT
    bcpl_push(L63); // LOAD_CONSTANT
    goto L60_62; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 13
    L13_11:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 3
    goto L65_67; // CALL (as GOTO)
    goto L67_69; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L14 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L14 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L68_70; // GOTO
    goto L69_28; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L70_71; } // BRANCH_IF_NEQ
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
    goto L71_72; // CALL (as GOTO)
    goto L70_71; // GOTO
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
    goto L71_72; // GOTO
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
    goto L72_73; // GOTO
    return; // RETURN
    goto L66_68; // CALL (as GOTO)
    goto L65_67; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L72_73:
    bcpl_push(bcpl_locals[L67]); // LOAD_LOCAL
    // JUMP_IF_ZERO 44 L68 - not implemented
    // JUMP_IF_NOT_ZERO 45 L69 - not implemented
    goto L66_68; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L15_13:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_pop(); // POP
    // LOCAL_VAR allocation
    // TEMP_VAR allocation
    // UNKNOWN_83 83 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(44)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L75_76; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L74_75; } // BRANCH_IF_NEQ
    goto L75_76; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L73_74:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L74_75; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    // UNKNOWN_21 21 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L77_35; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L76_77:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L77_35; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L16 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L79_79; } // BRANCH_IF_NEQ
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L78_78:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L79_79; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // JUMP_IF_ZERO 44 L16 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L78_78:
    goto L78_78; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L76_77:
    goto L76_77; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_98 98 - not implemented
    L73_74:
    goto L73_74; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L17_15; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_201 201 - not implemented
    L1_1:
    // UNKNOWN_202 202 - not implemented
    L2_0:
    // UNKNOWN_203 203 - not implemented
    L3_4:
    // UNKNOWN_209 209 - not implemented
    L4_5:
    // UNKNOWN_204 204 - not implemented
    L5_6:
    // UNKNOWN_205 205 - not implemented
    L6_8:
    // UNKNOWN_206 206 - not implemented
    L7_36:
    // UNKNOWN_207 207 - not implemented
    L10_9:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 91]); // DUPLICATE
    // UNKNOWN_2 2 - not implemented
    goto L4_5; // CALL (as GOTO)
    // FUNCTION_START 8
    L1_1:
    // UNKNOWN_74 74 - not implemented
    goto L77_35; // CALL (as GOTO)
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // FUNCTION_END 5
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L5_6; // CALL (as GOTO)
    goto L7_36; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L8_7; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L9_3; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(241); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    goto L9_3; // GOTO
    return; // RETURN
    goto L10_9; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(220); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    return; // RETURN
    goto L11_2; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L12_10; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L13_11; } // BRANCH_IF_NEQ
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
    goto L14_12; // CALL (as GOTO)
    goto L13_11; // GOTO
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
    goto L14_12; // GOTO
    return; // RETURN
    goto L15_13; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L17_15; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(86)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L16_14:
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    goto L17_15; // GOTO
    bcpl_push(bcpl_load_indirect(87)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L16_14:
    goto L16_14; // GOTO
    // UNKNOWN_93 93 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(-bcpl_pop()); // NEGATE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L6_8; // CALL (as GOTO)
    goto L5_6; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L15_13:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L7_36:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L8_7:
    // UNKNOWN_30 30 - not implemented
    L10_9:
    // UNKNOWN_33 33 - not implemented
    L11_2:
    // UNKNOWN_34 34 - not implemented
    L12_10:
    goto L6_8; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 11
    L2_0:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L73_74; } // BRANCH_IF_NEQ
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L18_16; } // BRANCH_IF_NEQ
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_locals[273] = bcpl_pop(); // STORE_LOCAL
    goto L18_16; // GOTO
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
    goto L19_17; // CALL (as GOTO)
    goto L20_18; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    goto L19_17; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L20_18; } // BRANCH_IF_EQ
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
    L3_4:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // TEMP_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_82 82 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L21_19; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(42)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    goto L22_21; // CALL (as GOTO)
    goto L21_19; // GOTO
    bcpl_push(bcpl_load_indirect(40)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(3)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L22_21; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L23_37; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(4)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_80 80 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    goto L23_37; // GOTO
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
    if (bcpl_pop()) goto L24_20; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L24_20; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L25_22; } // BRANCH_IF_NEQ
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
    goto L26_23; // CALL (as GOTO)
    goto L25_22; // GOTO
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
    goto L26_23; // GOTO
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(88)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(271); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L27_25; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[15]); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 13]); // DUPLICATE
    goto L27_25; // GOTO
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
    goto L4_5; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_220 220 - not implemented
    L1_1:
    // UNKNOWN_221 221 - not implemented
    L2_0:
    // UNKNOWN_222 222 - not implemented
    L3_4:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_52 52 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5_6; // CALL (as GOTO)
    // FUNCTION_START 4
    L1_1:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L6_8; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(148)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L6_8; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    goto L7_36; // CALL (as GOTO)
    goto L9_3; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(147)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L10_9; // GOTO
    bcpl_push(bcpl_load_indirect(120)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L11_2; // GOTO
    goto L12_10; // GOTO
    goto L13_11; // GOTO
    goto L14_12; // GOTO
    goto L15_13; // GOTO
    goto L16_14; // GOTO
    goto L17_15; // GOTO
    goto L18_16; // GOTO
    goto L19_17; // GOTO
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
    goto L20_18; // GOTO
    goto L21_19; // GOTO
    goto L22_21; // GOTO
    goto L23_37; // GOTO
    goto L24_20; // GOTO
    goto L25_22; // GOTO
    goto L26_23; // GOTO
    goto L27_25; // GOTO
    goto L28_24; // GOTO
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
    if (bcpl_pop()) goto L30_27; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29_26; } // BRANCH_IF_NEQ
    goto L30_27; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L29_26; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L31_29; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(14)); // LOAD_INDIRECT
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 6]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(8)); // LOAD_INDIRECT
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    goto L31_29; // GOTO
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
    goto L32_30; // GOTO
    goto L33_31; // GOTO
    goto L34_32; // GOTO
    goto L35_38; // GOTO
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
    goto L36_39; // GOTO
    goto L37_40; // GOTO
    goto L38_41; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(290); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(280); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[280] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L39_42; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(232); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L40_43; // GOTO
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
    goto L41_44; // GOTO
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
    goto L42_45; // GOTO
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
    goto L43_46; // GOTO
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
    goto L44_47; // GOTO
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
    goto L45_48; // GOTO
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
    goto L46_49; // GOTO
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
    // UNKNOWN_2 2 - not implemented
    goto L48_51; // CALL (as GOTO)
    goto L47_50; // GOTO
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
    // UNKNOWN_2 2 - not implemented
    goto L48_51; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L47_50; // CONDITIONAL_JUMP
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
    goto L8_7; // CALL (as GOTO)
    goto L7_36; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // TEMP_VAR allocation
    // UNKNOWN_34 34 - not implemented
    L9_3:
    // UNKNOWN_28 28 - not implemented
    L10_9:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L11_2:
    // UNKNOWN_13 13 - not implemented
    L12_10:
    bcpl_push(-bcpl_pop()); // NEGATE
    L13_11:
    // UNKNOWN_22 22 - not implemented
    L14_12:
    // UNKNOWN_23 23 - not implemented
    L15_13:
    // UNKNOWN_24 24 - not implemented
    L16_14:
    // UNKNOWN_25 25 - not implemented
    L17_15:
    // UNKNOWN_31 31 - not implemented
    L18_16:
    // UNKNOWN_32 32 - not implemented
    L19_17:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L20_18:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L21_19:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L22_21:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    L23_37:
    // UNKNOWN_21 21 - not implemented
    L24_20:
    // UNKNOWN_33 33 - not implemented
    L25_22:
    // UNKNOWN_34 34 - not implemented
    L26_23:
    // UNKNOWN_35 35 - not implemented
    L27_25:
    // UNKNOWN_36 36 - not implemented
    L28_24:
    // UNKNOWN_17 17 - not implemented
    L32_30:
    // UNKNOWN_30 30 - not implemented
    L33_31:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L34_32:
    // UNKNOWN_19 19 - not implemented
    L35_38:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L36_39:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L37_40:
    // UNKNOWN_16 16 - not implemented
    L38_41:
    // UNKNOWN_7 7 - not implemented
    L39_42:
    // UNKNOWN_1 1 - not implemented
    L40_43:
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L41_44:
    // UNKNOWN_2 2 - not implemented
    L42_45:
    bcpl_push(bcpl_rdline()); // READ_LINE
    L43_46:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    L44_47:
    // UNKNOWN_37 37 - not implemented
    L45_48:
    // UNKNOWN_39 39 - not implemented
    L46_49:
    goto L8_7; // GOTO
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L2_0:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // STRING_CONSTANT definition
    if (bcpl_pop()) goto L100_99; // CONDITIONAL_JUMP
    L50_52:
    // LOOP_END L49
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L51_53; } // BRANCH_IF_NEQ
    // JUMP_IF_ZERO 44 L50 - not implemented
    // UNKNOWN_52 52 - not implemented
    goto L51_53; // GOTO
    goto L52_54; // CALL (as GOTO)
    goto L54_56; // GOTO
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L49_33; } // BRANCH_IF_LT
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(113)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L55_57; // GOTO
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
    goto L56_58; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L57_59; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L58_60; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_80 80 - not implemented
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L58_60; // GOTO
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
    goto L53_55; // CALL (as GOTO)
    goto L52_54; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    L54_56:
    // UNKNOWN_2 2 - not implemented
    L55_57:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L56_58:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L57_59:
    goto L53_55; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L3_4:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    goto L69_28; // GOTO
    // UNKNOWN_82 82 - not implemented
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
    L4_5:
    // STRING_CONSTANT definition
    // PUSH_STRING - string handling
    // UNKNOWN_65 65 - not implemented
    bcpl_pop(); // POP
    // STRING_CONSTANT definition
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L59_61; // CONDITIONAL_JUMP
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L60_62; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(231); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    goto L60_62; // GOTO
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
    goto L59_61; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L5_6; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_231 231 - not implemented
    L1_1:
    // UNKNOWN_232 232 - not implemented
    L2_0:
    // UNKNOWN_236 236 - not implemented
    L3_4:
    // UNKNOWN_233 233 - not implemented
    L4_5:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_53 53 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4_5; // CALL (as GOTO)
    // FUNCTION_START 9
    L1_1:
    // LOCAL_VAR allocation
    if (bcpl_pop()) goto L65_67; // CONDITIONAL_JUMP
    // STRING_CONSTANT definition
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L6_8; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(117)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L6_8; // GOTO
    goto L7_36; // CALL (as GOTO)
    goto L9_3; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(118)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L10_9; // GOTO
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L11_2; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(2)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(260); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L11_2; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(119)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_98 98 - not implemented
    L5_6:
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L12_10; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L13_11; // GOTO
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L14_12; // GOTO
    bcpl_push(bcpl_rdch()); // READ_CHAR
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L15_13; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_17 17 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L16_14; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_19 19 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L17_15; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(235); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L18_16; // GOTO
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
    L5_6:
    goto L19_17; // GOTO
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
    L5_6:
    goto L20_18; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L21_19; // GOTO
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
    L5_6:
    goto L22_21; // GOTO
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
    L5_6:
    goto L23_37; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L24_20; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L25_22; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L26_23; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L27_25; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L28_24; // GOTO
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
    // UNKNOWN_98 98 - not implemented
    L5_6:
    goto L8_7; // CALL (as GOTO)
    goto L7_36; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    // UNKNOWN_18 18 - not implemented
    L9_3:
    // UNKNOWN_2 2 - not implemented
    L10_9:
    // UNKNOWN_1 1 - not implemented
    L12_10:
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L13_11:
    bcpl_push(bcpl_rdch()); // READ_CHAR
    L14_12:
    // UNKNOWN_17 17 - not implemented
    L15_13:
    // UNKNOWN_19 19 - not implemented
    L16_14:
    // UNKNOWN_30 30 - not implemented
    L17_15:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a / b : 0); } // DIVIDE
    L18_16:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    L19_17:
    // UNKNOWN_13 13 - not implemented
    L20_18:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    L21_19:
    bcpl_push(-bcpl_pop()); // NEGATE
    L22_21:
    // UNKNOWN_31 31 - not implemented
    L23_37:
    // UNKNOWN_32 32 - not implemented
    L24_20:
    // UNKNOWN_34 34 - not implemented
    L25_22:
    // UNKNOWN_33 33 - not implemented
    L26_23:
    // UNKNOWN_35 35 - not implemented
    L27_25:
    // UNKNOWN_36 36 - not implemented
    L28_24:
    goto L8_7; // GOTO
    goto L5_6; // GOTO
    // UNKNOWN_93 93 - not implemented
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_96 96 - not implemented
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 6
    L2_0:
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_78 78 - not implemented
    // FUNCTION_END 4
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L30_27; // CONDITIONAL_JUMP
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L29_26; } // BRANCH_IF_NEQ
    goto L30_27; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(110)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L29_26; // GOTO
    goto L31_29; // CALL (as GOTO)
    goto L33_31; // GOTO
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    bcpl_push(bcpl_load_indirect(38)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    if (bcpl_pop()) goto L34_32; // CONDITIONAL_JUMP
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(112)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    return; // RETURN
    goto L34_32; // GOTO
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
    goto L35_38; // GOTO
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
    goto L36_39; // GOTO
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
    goto L37_40; // GOTO
    goto L38_41; // GOTO
    goto L39_42; // GOTO
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
    goto L40_43; // GOTO
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(109)); // LOAD_INDIRECT
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 4]); // DUPLICATE
    goto L32_30; // CALL (as GOTO)
    goto L31_29; // GOTO
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    // TEMP_VAR allocation
    bcpl_push(bcpl_rdline()); // READ_LINE
    L40_43:
    // UNKNOWN_38 38 - not implemented
    L33_31:
    // UNKNOWN_2 2 - not implemented
    L35_38:
    // UNKNOWN_28 28 - not implemented
    L36_39:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a + b); } // ADD
    L37_40:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a - b); } // SUBTRACT
    L38_41:
    // UNKNOWN_37 37 - not implemented
    L39_42:
    goto L32_30; // GOTO
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 9
    L3_4:
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // LOCAL_VAR allocation
    // FUNCTION_END 7
    bcpl_push(bcpl_globals[9]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(206); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a * b); } // MULTIPLY
    // UNKNOWN_7 7 - not implemented
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
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L41_44; } // BRANCH_IF_NEQ
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
    goto L41_44; // GOTO
    goto L42_45; // CALL (as GOTO)
    goto L44_47; // GOTO
    bcpl_push(bcpl_locals[7]); // LOAD_LOCAL
    bcpl_push(263); // LOAD_CONSTANT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L45_48; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(116)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    goto L45_48; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L46_49; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L47_50; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(292); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    return; // RETURN
    goto L48_51; // GOTO
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L49_33; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(113)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(210); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    bcpl_push(bcpl_locals[3]); // LOAD_LOCAL
    // UNKNOWN_80 80 - not implemented
    bcpl_push(bcpl_rdline()); // READ_LINE
    goto L49_33; // GOTO
    bcpl_push(bcpl_globals[12]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[9]); // LOAD_LOCAL
    bcpl_push(291); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 10]); // DUPLICATE
    goto L43_46; // CALL (as GOTO)
    goto L42_45; // GOTO
    bcpl_push(bcpl_locals[8]); // LOAD_LOCAL
    // TEMP_VAR allocation
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    L43_46:
    // UNKNOWN_77 77 - not implemented
    L44_47:
    // STRING_CONSTANT definition
    L46_49:
    // UNKNOWN_78 78 - not implemented
    L47_50:
    // UNKNOWN_1 1 - not implemented
    L48_51:
    goto L43_46; // GOTO
    bcpl_push(bcpl_globals[8]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L4_5; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    // UNKNOWN_235 235 - not implemented
    L1_1:
    // UNKNOWN_230 230 - not implemented
    L2_0:
    // UNKNOWN_237 237 - not implemented
    L3_4:
    // FUNCTION_HEADER - 4 parameters
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_54 54 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L18_16; // CALL (as GOTO)
    // FUNCTION_START 7
    L1_1:
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
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
    L2_0:
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a < b) goto L95_94; } // BRANCH_IF_LT
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
    goto L19_17; // CALL (as GOTO)
    goto L20_18; // GOTO
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
    bcpl_push(bcpl_rdch()); // READ_CHAR
    goto L19_17; // GOTO
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[6]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L20_18; } // BRANCH_IF_EQ
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
    L3_4:
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    bcpl_pop(); // POP
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STRING_CONSTANT definition
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
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
    L4_5:
    // UNKNOWN_67 67 - not implemented
    // PUSH_STRING - string handling
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_74 74 - not implemented
    goto L77_35; // CALL (as GOTO)
    // UNKNOWN_80 80 - not implemented
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
    L5_6:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
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
    L6_8:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_50 50 - not implemented
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
    L7_36:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_50 50 - not implemented
    // UNKNOWN_80 80 - not implemented
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
    L8_7:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
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
    L9_3:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_78 78 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(253); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L10_9:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
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
    L11_2:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_67 67 - not implemented
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
    L12_10:
    // PUSH_STRING - string handling
    goto L84_34; // CALL (as GOTO)
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_82 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
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
    goto L21_19; // CALL (as GOTO)
    goto L22_21; // GOTO
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
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    goto L21_19; // GOTO
    bcpl_push(bcpl_locals[4]); // LOAD_LOCAL
    bcpl_push(bcpl_locals[5]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a == b) goto L22_21; } // BRANCH_IF_EQ
    bcpl_push(bcpl_globals[4]); // LOAD_GLOBAL
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 7
    L13_11:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82_82; } // BRANCH_IF_NEQ
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // LOCAL_VAR allocation
    // PUSH_STRING - string handling
    // UNKNOWN_80 80 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 3
    L14_12:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82_82; } // BRANCH_IF_NEQ
    // UNKNOWN_78 78 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L23_37; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(45)); // LOAD_INDIRECT
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    // UNKNOWN_17 17 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    // UNKNOWN_22 22 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L24_20; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    // UNKNOWN_32 32 - not implemented
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
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_globals[3]); // LOAD_GLOBAL
    goto L24_20; // GOTO
    goto L23_37; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 4
    L15_13:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82_82; } // BRANCH_IF_NEQ
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_78 78 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(9)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L25_22; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(b != 0 ? a % b : 0); } // MODULO
    bcpl_push(254); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    goto L25_22; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_indirect(48)); // LOAD_INDIRECT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_push(250); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    // FUNCTION_START 8
    L16_14:
    // LOCAL_VAR allocation
    // UNKNOWN_78 78 - not implemented
    bcpl_pop(); // POP
    // PUSH_STRING - string handling
    // UNKNOWN_67 67 - not implemented
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
    L17_15:
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L82_82; } // BRANCH_IF_NEQ
    // UNKNOWN_67 67 - not implemented
    // FUNCTION_END 3
    bcpl_push(bcpl_load_indirect(1)); // LOAD_INDIRECT
    bcpl_push(251); // LOAD_CONSTANT
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a == b ? 0 : (a < b ? -1 : 1)); } // COMPARE
    bcpl_locals[251] = bcpl_pop(); // STORE_LOCAL
    bcpl_push(251); // LOAD_CONSTANT
    bcpl_push(bcpl_load_indirect(62)); // LOAD_INDIRECT
    // UNKNOWN_23 23 - not implemented
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26_23; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_load_indirect(32)); // LOAD_INDIRECT
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); bcpl_push(a < b ? -1 : 0); } // LESS_THAN
    { bcpl_word_t b = bcpl_pop(); bcpl_word_t a = bcpl_pop(); if (a != b) goto L26_23; } // BRANCH_IF_NEQ
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_load_indirect(10)); // LOAD_INDIRECT
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    bcpl_push(bcpl_load_indirect(0)); // LOAD_INDIRECT
    bcpl_locals[251] = bcpl_pop(); // STORE_LOCAL
    return; // RETURN
    goto L26_23; // GOTO
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(bcpl_locals[2]); // LOAD_LOCAL
    bcpl_push(14); // LOAD_CONSTANT
    bcpl_push(bcpl_stack[bcpl_stack_ptr - 1 - 3]); // DUPLICATE
    return; // RETURN
    // END_BLOCK
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    goto L18_16; // GOTO
    { bcpl_word_t addr = bcpl_pop(); bcpl_word_t val = bcpl_pop(); bcpl_globals[addr] = val; } // STORE_GLOBAL
    // STRING_CONSTANT definition
    // UNKNOWN_17 17 - not implemented
    // UNKNOWN_240 240 - not implemented
    L1_1:
    // UNKNOWN_242 242 - not implemented
    L2_0:
    // UNKNOWN_234 234 - not implemented
    L3_4:
    // UNKNOWN_241 241 - not implemented
    L4_5:
    // UNKNOWN_290 290 - not implemented
    L5_6:
    // UNKNOWN_291 291 - not implemented
    L6_8:
    // UNKNOWN_292 292 - not implemented
    L7_36:
    // UNKNOWN_294 294 - not implemented
    L8_7:
    // UNKNOWN_295 295 - not implemented
    L9_3:
    // UNKNOWN_296 296 - not implemented
    L10_9:
    // UNKNOWN_297 297 - not implemented
    L11_2:
    // UNKNOWN_289 289 - not implemented
    L12_10:
    // UNKNOWN_298 298 - not implemented
    L13_11:
    // UNKNOWN_253 253 - not implemented
    L14_12:
    // UNKNOWN_254 254 - not implemented
    L15_13:
    // UNKNOWN_252 252 - not implemented
    L16_14:
    // UNKNOWN_250 250 - not implemented
    L17_15:
}

int main(int argc, char* argv[]) {
    bcpl_init(argc, argv);
    bcpl_start();
    return 0;
}
