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
static bcpl_word_t bcpl_globals[1000];
static bcpl_word_t bcpl_stack[10000];
static int bcpl_stack_ptr = 0;

// BCPL runtime functions
static void bcpl_push(bcpl_word_t value) {
    bcpl_stack[bcpl_stack_ptr++] = value;
}

static bcpl_word_t bcpl_pop(void) {
    return bcpl_stack[--bcpl_stack_ptr];
}

static void bcpl_store_global(int index, bcpl_word_t value) {
    bcpl_globals[index] = value;
}

static bcpl_word_t bcpl_load_global(int index) {
    return bcpl_globals[index];
}


// BCPL I/O functions
static void bcpl_wrch(bcpl_word_t ch) {
    putchar(ch);
}

static bcpl_word_t bcpl_rdch(void) {
    return getchar();
}

// BCPL string functions
static void bcpl_writes(const char* str) {
    printf("%s", str);
}

// Main BCPL program entry point
static void bcpl_start(void);

static void bcpl_start(void) {
    // Generated from OCODE
    // MULTIPLY 49 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L2:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L1:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(16); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(17); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    goto 11; // JUMP
    // ADD 47 - not implemented
    // UNKNOWN_100 100 - not implemented
    // UNKNOWN_101 101 - not implemented
    // UNKNOWN_118 118 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_116 116 - not implemented
    // UNKNOWN_100 100 - not implemented
    // UNKNOWN_101 101 - not implemented
    // UNKNOWN_114 114 - not implemented
    // UNKNOWN_114 114 - not implemented
    bcpl_push(41); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_194 194 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    goto 9; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_10 10 - not implemented
    // RETURN 46 - not implemented
    // UNKNOWN_1 1 - not implemented
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 55000 - TODO: implement function calls
    bcpl_push(bcpl_load_global(28)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_128 128 - not implemented
    // CALL 2 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_282 282 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_127 127 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_110 110 - not implemented
    // CALL 1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_111 111 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L3:
    // UNKNOWN_90 90 - not implemented
    L4:
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_90 90 - not implemented
    L3:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // CALL 20 - TODO: implement function calls
    // UNKNOWN_88 88 - not implemented
    L4:
    bcpl_push(bcpl_load_global(28)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    goto 3; // JUMP
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_push(42); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_28 28 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_193 193 - not implemented
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_86 86 - not implemented
    L5:
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(100, bcpl_pop()); // STORE_GLOBAL
    L7:
    // UNKNOWN_101 101 - not implemented
    L6:
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_30 30 - not implemented
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    goto 9; // JUMP
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_90 90 - not implemented
    L8:
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    bcpl_push(13); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_89 89 - not implemented
    L6:
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L10:
    // CALL -1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L9:
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_85 85 - not implemented
    L11:
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_30 30 - not implemented
    // CALL 80 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L12:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    // UNKNOWN_90 90 - not implemented
    L12:
    // CALL 84 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L13:
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    // UNKNOWN_90 90 - not implemented
    L13:
    // CALL 67 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L14:
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    // UNKNOWN_90 90 - not implemented
    L14:
    // CALL 77 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L15:
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    // UNKNOWN_90 90 - not implemented
    L15:
    // CALL 78 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L16:
    // CALL 5 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_29 29 - not implemented
    // UNKNOWN_90 90 - not implemented
    L16:
    // CALL 83 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L17:
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_110 110 - not implemented
    // UNKNOWN_90 90 - not implemented
    L17:
    // CALL 69 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L18:
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_127 127 - not implemented
    // UNKNOWN_90 90 - not implemented
    L18:
    // CALL 76 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L19:
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    bcpl_push(70); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(62); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_90 90 - not implemented
    L19:
    // CALL 51 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L20:
    // CALL 3 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_282 282 - not implemented
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_29 29 - not implemented
    bcpl_push(128); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_85 85 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L11:
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_30 30 - not implemented
    bcpl_push(bcpl_load_global(32)); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_30 30 - not implemented
    bcpl_push(bcpl_load_global(28)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L5:
    // CALL 3 - TODO: implement function calls
    bcpl_push(128); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_30 30 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_114 114 - not implemented
    // CALL 20 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_192 192 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_191 191 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_193 193 - not implemented
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_195 195 - not implemented
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    bcpl_push(195); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_87 87 - not implemented
    L21:
    bcpl_push(194); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_195 195 - not implemented
    // UNKNOWN_90 90 - not implemented
    L21:
    // UNKNOWN_100 100 - not implemented
    L23:
    // UNKNOWN_101 101 - not implemented
    L22:
    // UNKNOWN_85 85 - not implemented
    L24:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L22:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(69)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_100 100 - not implemented
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_168 168 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_169 169 - not implemented
    bcpl_push(110); // LOAD_CONSTANT
    // UNKNOWN_87 87 - not implemented
    L26:
    bcpl_push(bcpl_load_global(71)); // LOAD_GLOBAL
    goto 4; // JUMP
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_push(41); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_69 69 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_196 196 - not implemented
    bcpl_push(bcpl_load_global(71)); // LOAD_GLOBAL
    bcpl_push(196); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_87 87 - not implemented
    L28:
    bcpl_push(194); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_196 196 - not implemented
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_85 85 - not implemented
    L27:
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(194); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_196 196 - not implemented
    // UNKNOWN_90 90 - not implemented
    L27:
    bcpl_push(bcpl_load_global(71)); // LOAD_GLOBAL
    bcpl_push(150); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_69 69 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L29:
    // UNKNOWN_85 85 - not implemented
    L30:
    // UNKNOWN_90 90 - not implemented
    L29:
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    goto 14; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_90 90 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(169); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(168); // LOAD_CONSTANT
    // UNKNOWN_15 15 - not implemented
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    // CALL 2 - TODO: implement function calls
    bcpl_push(128); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_87 87 - not implemented
    L31:
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    goto 8; // JUMP
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_69 69 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 20 - TODO: implement function calls
    bcpl_push(152); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_90 90 - not implemented
    L31:
    // CALL 0 - TODO: implement function calls
    bcpl_push(191); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L32:
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    bcpl_push(30); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_90 90 - not implemented
    L32:
    // CALL 3 - TODO: implement function calls
    bcpl_push(128); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_86 86 - not implemented
    L33:
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    bcpl_push(195); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_69 69 - not implemented
    bcpl_push(245); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    bcpl_push(bcpl_load_global(72)); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_90 90 - not implemented
    L33:
    bcpl_push(bcpl_load_global(69)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(28)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L24:
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_30 30 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L23:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(40); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_28 28 - not implemented
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_28 28 - not implemented
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    goto 18; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // MULTIPLY 49 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_28 28 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(191); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L34:
    bcpl_push(bcpl_load_global(30)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    bcpl_push(30); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_28 28 - not implemented
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_68 68 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L2:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_1 1 - not implemented
    L1:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // MULTIPLY 49 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L2:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L1:
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_122 122 - not implemented
    // UNKNOWN_90 90 - not implemented
    L3:
    bcpl_push(127); // LOAD_CONSTANT
    // UNKNOWN_87 87 - not implemented
    L4:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L4:
    // UNKNOWN_85 85 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L7:
    // UNKNOWN_90 90 - not implemented
    L8:
    // CALL 1 - TODO: implement function calls
    bcpl_push(133); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_122 122 - not implemented
    // UNKNOWN_90 90 - not implemented
    L9:
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L11:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 32 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L9:
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L15:
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_90 90 - not implemented
    L17:
    // UNKNOWN_90 90 - not implemented
    L18:
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L21:
    // CALL 1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 10 - TODO: implement function calls
    bcpl_push(112); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L29:
    // UNKNOWN_90 90 - not implemented
    L30:
    // UNKNOWN_90 90 - not implemented
    L31:
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_90 90 - not implemented
    L35:
    // UNKNOWN_90 90 - not implemented
    L36:
    // UNKNOWN_90 90 - not implemented
    L37:
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_90 90 - not implemented
    L39:
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_90 90 - not implemented
    L41:
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_90 90 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L44:
    // UNKNOWN_90 90 - not implemented
    L45:
    // UNKNOWN_90 90 - not implemented
    L46:
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L50:
    // UNKNOWN_90 90 - not implemented
    L51:
    // UNKNOWN_90 90 - not implemented
    L52:
    // UNKNOWN_90 90 - not implemented
    L53:
    // UNKNOWN_90 90 - not implemented
    L54:
    // UNKNOWN_90 90 - not implemented
    L55:
    // UNKNOWN_90 90 - not implemented
    L56:
    // UNKNOWN_90 90 - not implemented
    L57:
    // UNKNOWN_90 90 - not implemented
    L58:
    // UNKNOWN_90 90 - not implemented
    L59:
    // UNKNOWN_90 90 - not implemented
    L60:
    // UNKNOWN_90 90 - not implemented
    L61:
    // UNKNOWN_90 90 - not implemented
    L62:
    // UNKNOWN_90 90 - not implemented
    L63:
    // UNKNOWN_90 90 - not implemented
    L64:
    // UNKNOWN_90 90 - not implemented
    L65:
    // UNKNOWN_90 90 - not implemented
    L66:
    // UNKNOWN_90 90 - not implemented
    L67:
    // UNKNOWN_90 90 - not implemented
    L68:
    // UNKNOWN_90 90 - not implemented
    L69:
    // UNKNOWN_90 90 - not implemented
    L70:
    // UNKNOWN_90 90 - not implemented
    L71:
    // UNKNOWN_90 90 - not implemented
    L72:
    // UNKNOWN_90 90 - not implemented
    L73:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(118); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // CALL 93 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L74:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(119); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_90 90 - not implemented
    L74:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L75:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 40 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L76:
    // CALL 41 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L76:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L76:
    // CALL 40 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L78:
    // CALL 91 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L77:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L78:
    // CALL 92 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L77:
    // UNKNOWN_90 90 - not implemented
    L77:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 36 - TODO: implement function calls
    bcpl_push(118); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L79:
    // UNKNOWN_90 90 - not implemented
    L80:
    // CALL 105 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L82:
    // UNKNOWN_90 90 - not implemented
    L83:
    // CALL 106 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L84:
    // CALL 1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_117 117 - not implemented
    // CALL 48 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L85:
    bcpl_push(117); // LOAD_CONSTANT
    // CALL 55 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L85:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    bcpl_push(112); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L85:
    // CALL 66 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L86:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 2 - TODO: implement function calls
    bcpl_push(112); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L86:
    // CALL 79 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L87:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    bcpl_push(112); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L87:
    // CALL 88 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L88:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 16 - TODO: implement function calls
    bcpl_push(112); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L88:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 33 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L89:
    // CALL 16 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L90:
    // CALL 14 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L91:
    // CALL 38 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L92:
    // CALL 97 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L93:
    // CALL 7 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L94:
    // CALL 33 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L95:
    // CALL 34 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L96:
    // CALL 20 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L97:
    // CALL 9 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L98:
    // CALL 28 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L99:
    // CALL 11 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L100:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 92 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L101:
    // CALL 33 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L101:
    // CALL 47 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L102:
    // UNKNOWN_90 90 - not implemented
    L103:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 10 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L104:
    // CALL -1 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L103:
    // UNKNOWN_90 90 - not implemented
    L104:
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_90 90 - not implemented
    L102:
    // CALL 42 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L105:
    // CALL 12 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L105:
    // UNKNOWN_90 90 - not implemented
    L106:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 42 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L107:
    // UNKNOWN_90 90 - not implemented
    L108:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 42 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L108:
    // CALL 47 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L109:
    // UNKNOWN_85 85 - not implemented
    L110:
    // UNKNOWN_90 90 - not implemented
    L109:
    // UNKNOWN_90 90 - not implemented
    L107:
    // CALL 10 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L111:
    // CALL 1 - TODO: implement function calls
    bcpl_push(133); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    // UNKNOWN_90 90 - not implemented
    L111:
    // CALL -1 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L112:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 63 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L112:
    // UNKNOWN_85 85 - not implemented
    L106:
    // UNKNOWN_90 90 - not implemented
    L110:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_90 90 - not implemented
    L113:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 61 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L114:
    // CALL 21 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L114:
    // CALL 30 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L115:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 47 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L116:
    // CALL 34 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L116:
    // CALL 61 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L117:
    // CALL 21 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L117:
    // CALL 30 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L118:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 61 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L119:
    // CALL 24 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L119:
    // CALL 60 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L120:
    // CALL 31 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L120:
    // CALL 22 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L121:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 61 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L122:
    // CALL 25 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L122:
    // CALL 62 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L123:
    // CALL 32 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L123:
    // CALL 23 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L124:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 62 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L125:
    // CALL 37 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L125:
    // CALL 15 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L126:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 61 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L127:
    // CALL 50 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L127:
    // CALL 54 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L128:
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_109 109 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L130:
    // UNKNOWN_90 90 - not implemented
    L129:
    // CALL 255 - TODO: implement function calls
    bcpl_push(109); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L131:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L131:
    // CALL 1 - TODO: implement function calls
    bcpl_push(109); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_109 109 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(113); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_90 90 - not implemented
    L130:
    // CALL 34 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L129:
    bcpl_push(109); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_107 107 - not implemented
    // CALL 3 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L132:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(113); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_101 101 - not implemented
    // CALL 1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // CALL 39 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L133:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L133:
    // UNKNOWN_85 85 - not implemented
    L81:
    // UNKNOWN_90 90 - not implemented
    L134:
    // CALL -1 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L135:
    // CALL 32 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_117 117 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 94 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L135:
    // UNKNOWN_90 90 - not implemented
    L136:
    // CALL 0 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L137:
    // CALL 90 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L137:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(46); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(104); // LOAD_CONSTANT
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_104 104 - not implemented
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_193 193 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    // CALL 2 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_117 117 - not implemented
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_85 85 - not implemented
    L6:
    // UNKNOWN_90 90 - not implemented
    L5:
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_93 93 - not implemented
    L134:
    // UNKNOWN_12 12 - not implemented
    L7:
    // UNKNOWN_10 10 - not implemented
    L8:
    // UNKNOWN_9 9 - not implemented
    L10:
    // UNKNOWN_32 32 - not implemented
    L11:
    // SUBTRACT 48 - not implemented
    L12:
    // MULTIPLY 49 - not implemented
    L13:
    // DIVIDE 50 - not implemented
    L14:
    // NEGATE 51 - not implemented
    L15:
    // UNKNOWN_52 52 - not implemented
    L16:
    // UNKNOWN_53 53 - not implemented
    L17:
    // UNKNOWN_54 54 - not implemented
    L18:
    // UNKNOWN_55 55 - not implemented
    L19:
    // UNKNOWN_56 56 - not implemented
    L20:
    // UNKNOWN_57 57 - not implemented
    L21:
    // UNKNOWN_97 97 - not implemented
    L22:
    // UNKNOWN_98 98 - not implemented
    L23:
    // UNKNOWN_99 99 - not implemented
    L24:
    // UNKNOWN_100 100 - not implemented
    L25:
    // UNKNOWN_101 101 - not implemented
    L26:
    // UNKNOWN_102 102 - not implemented
    L27:
    // UNKNOWN_103 103 - not implemented
    L28:
    // UNKNOWN_104 104 - not implemented
    L29:
    // UNKNOWN_105 105 - not implemented
    L30:
    // UNKNOWN_106 106 - not implemented
    L31:
    // UNKNOWN_107 107 - not implemented
    L32:
    // UNKNOWN_108 108 - not implemented
    L33:
    // UNKNOWN_109 109 - not implemented
    L34:
    // UNKNOWN_110 110 - not implemented
    L35:
    // UNKNOWN_111 111 - not implemented
    L36:
    // UNKNOWN_112 112 - not implemented
    L37:
    // UNKNOWN_113 113 - not implemented
    L38:
    // UNKNOWN_114 114 - not implemented
    L39:
    // UNKNOWN_115 115 - not implemented
    L40:
    // UNKNOWN_116 116 - not implemented
    L41:
    // UNKNOWN_117 117 - not implemented
    L42:
    // UNKNOWN_118 118 - not implemented
    L43:
    // UNKNOWN_119 119 - not implemented
    L44:
    // UNKNOWN_120 120 - not implemented
    L45:
    // UNKNOWN_121 121 - not implemented
    L46:
    // UNKNOWN_122 122 - not implemented
    L47:
    // UNKNOWN_65 65 - not implemented
    L48:
    // UNKNOWN_66 66 - not implemented
    L49:
    // UNKNOWN_67 67 - not implemented
    L50:
    // UNKNOWN_68 68 - not implemented
    L51:
    // UNKNOWN_69 69 - not implemented
    L52:
    // UNKNOWN_70 70 - not implemented
    L53:
    // UNKNOWN_71 71 - not implemented
    L54:
    // UNKNOWN_72 72 - not implemented
    L55:
    // UNKNOWN_73 73 - not implemented
    L56:
    // UNKNOWN_74 74 - not implemented
    L57:
    // UNKNOWN_75 75 - not implemented
    L58:
    // UNKNOWN_76 76 - not implemented
    L59:
    // UNKNOWN_77 77 - not implemented
    L60:
    // UNKNOWN_78 78 - not implemented
    L61:
    // UNKNOWN_79 79 - not implemented
    L62:
    // UNKNOWN_80 80 - not implemented
    L63:
    // LOAD_LOCAL 81 - not implemented
    L64:
    // STORE_LOCAL 82 - not implemented
    L65:
    // UNKNOWN_83 83 - not implemented
    L66:
    // UNKNOWN_84 84 - not implemented
    L67:
    // UNKNOWN_85 85 - not implemented
    L68:
    // UNKNOWN_86 86 - not implemented
    L69:
    // UNKNOWN_87 87 - not implemented
    L70:
    // UNKNOWN_88 88 - not implemented
    L71:
    // UNKNOWN_89 89 - not implemented
    L72:
    // UNKNOWN_90 90 - not implemented
    L73:
    // UNKNOWN_36 36 - not implemented
    L75:
    bcpl_push(bcpl_load_global(L79)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    L80:
    // UNKNOWN_93 93 - not implemented
    L82:
    bcpl_push(L83); // LOAD_CONSTANT
    // UNKNOWN_35 35 - not implemented
    L84:
    // UNKNOWN_63 63 - not implemented
    L89:
    goto L90; // JUMP
    // JUMP_IF_ZERO 44 - not implemented
    L91:
    // UNKNOWN_59 59 - not implemented
    L92:
    // UNKNOWN_64 64 - not implemented
    L93:
    // UNKNOWN_38 38 - not implemented
    L94:
    // UNKNOWN_124 124 - not implemented
    L95:
    // UNKNOWN_61 61 - not implemented
    L96:
    // UNKNOWN_33 33 - not implemented
    L97:
    // UNKNOWN_37 37 - not implemented
    L98:
    // CALL L99 - TODO: implement function calls
    // ADD 47 - not implemented
    L100:
    // UNKNOWN_126 126 - not implemented
    L113:
    bcpl_store_global(L115, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_60 60 - not implemented
    L118:
    // UNKNOWN_62 62 - not implemented
    L121:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L124:
    // UNKNOWN_58 58 - not implemented
    L126:
    // UNKNOWN_34 34 - not implemented
    L128:
    // UNKNOWN_39 39 - not implemented
    L132:
    // RETURN 46 - not implemented
    L136:
    // UNKNOWN_90 90 - not implemented
    L6:
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_90 90 - not implemented
    L81:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L2:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_120 120 - not implemented
    L1:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // DIVIDE 50 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_100 100 - not implemented
    L4:
    // UNKNOWN_101 101 - not implemented
    L3:
    // UNKNOWN_85 85 - not implemented
    L5:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L1:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(106); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(107); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_32 32 - not implemented
    // CALL 100 - TODO: implement function calls
    // UNKNOWN_13 13 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    bcpl_push(148); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_116 116 - not implemented
    // UNKNOWN_85 85 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L7:
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(106); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L9:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_push(116); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_116 116 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L8:
    // CALL 0 - TODO: implement function calls
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L11:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(107); // LOAD_CONSTANT
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L7:
    // UNKNOWN_90 90 - not implemented
    L11:
    // CALL 0 - TODO: implement function calls
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L12:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 2 - TODO: implement function calls
    bcpl_push(107); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_116 116 - not implemented
    // CALL 2 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(148); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(107); // LOAD_CONSTANT
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(106); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_88 88 - not implemented
    L14:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(148); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_90 90 - not implemented
    L12:
    bcpl_push(116); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L6:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L6:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_12 12 - not implemented
    L2:
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_100 100 - not implemented
    L15:
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_19 19 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_100 100 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_101 101 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_35 35 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_56 56 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_76 76 - not implemented
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
    // SUBTRACT 48 - not implemented
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
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_61 61 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_62 62 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_63 63 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_102 102 - not implemented
    // MULTIPLY 49 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_99 99 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_55 55 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_101 101 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_60 60 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_59 59 - not implemented
    // UNKNOWN_102 102 - not implemented
    // UNKNOWN_0 0 - not implemented
    // ADD 47 - not implemented
    L15:
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_123 123 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    goto 142; // JUMP
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_83 83 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_66 66 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_75 75 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_89 89 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_79 79 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_69 69 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_69 69 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_86 86 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_72 72 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // STORE_LOCAL 82 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_70 70 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_86 86 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // ADD 47 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    goto 171; // JUMP
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_86 86 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_83 83 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_85 85 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_77 77 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_86 86 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_67 67 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_78 78 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_70 70 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_36 36 - not implemented
    // ADD 47 - not implemented
    // ADD 47 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(116); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_134 134 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_1 1 - not implemented
    L3:
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(90, bcpl_pop()); // STORE_GLOBAL
    L16:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(85); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // ADD 47 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L17:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L19:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_107 107 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(125); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(123); // LOAD_CONSTANT
    // UNKNOWN_8 8 - not implemented
    bcpl_push(116); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(123); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_123 123 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_85 85 - not implemented
    L18:
    // UNKNOWN_90 90 - not implemented
    L17:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_90 90 - not implemented
    L18:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L16:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L5:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_125 125 - not implemented
    L1:
    // UNKNOWN_121 121 - not implemented
    L2:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // NEGATE 51 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_100 100 - not implemented
    L8:
    // UNKNOWN_101 101 - not implemented
    L7:
    // UNKNOWN_100 100 - not implemented
    L11:
    // UNKNOWN_101 101 - not implemented
    L10:
    // UNKNOWN_85 85 - not implemented
    L12:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_3 3 - not implemented
    L1:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(13); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_117 117 - not implemented
    bcpl_push(110); // LOAD_CONSTANT
    // UNKNOWN_87 87 - not implemented
    L13:
    // CALL 0 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L13:
    // CALL -1 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_21 21 - not implemented
    // UNKNOWN_87 87 - not implemented
    L13:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(196); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(111); // LOAD_CONSTANT
    bcpl_push(133); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L14:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    goto 5; // JUMP
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_111 111 - not implemented
    // UNKNOWN_90 90 - not implemented
    L14:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L13:
    // CALL 1 - TODO: implement function calls
    bcpl_push(132); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_132 132 - not implemented
    bcpl_push(117); // LOAD_CONSTANT
    // CALL 63 - TODO: implement function calls
    bcpl_push(132); // LOAD_CONSTANT
    // UNKNOWN_33 33 - not implemented
    bcpl_push(100); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L2:
    // UNKNOWN_87 87 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    goto 4; // JUMP
    // UNKNOWN_10 10 - not implemented
    // RETURN 46 - not implemented
    // RETURN 46 - not implemented
    // RETURN 46 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(132); // LOAD_CONSTANT
    // CALL 63 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    bcpl_push(132); // LOAD_CONSTANT
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L15:
    // UNKNOWN_90 90 - not implemented
    L16:
    // CALL 63 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_33 33 - not implemented
    bcpl_push(100); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L17:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L17:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L15:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_88 88 - not implemented
    L16:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L3:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_109 109 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(92); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_90 90 - not implemented
    L18:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_117 117 - not implemented
    // CALL 65 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L20:
    bcpl_push(117); // LOAD_CONSTANT
    // CALL 90 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_86 86 - not implemented
    L19:
    // UNKNOWN_90 90 - not implemented
    L20:
    // CALL 48 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L21:
    bcpl_push(117); // LOAD_CONSTANT
    // CALL 57 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_86 86 - not implemented
    L19:
    // UNKNOWN_90 90 - not implemented
    L21:
    // CALL 46 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L19:
    // CALL 95 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L19:
    // UNKNOWN_85 85 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L19:
    // CALL 1 - TODO: implement function calls
    bcpl_push(109); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_109 109 - not implemented
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(109); // LOAD_CONSTANT
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_85 85 - not implemented
    L18:
    // UNKNOWN_90 90 - not implemented
    L22:
    bcpl_push(109); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    bcpl_push(108); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(108); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(66); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_107 107 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L4:
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_114 114 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    bcpl_push(128); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_30 30 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_114 114 - not implemented
    // CALL 3 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L23:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 97 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(117); // LOAD_CONSTANT
    // CALL 2 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 3 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_104 104 - not implemented
    // CALL 1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(42); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_193 193 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_87 87 - not implemented
    L24:
    // UNKNOWN_100 100 - not implemented
    L26:
    // UNKNOWN_101 101 - not implemented
    L25:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_4 4 - not implemented
    goto 21; // JUMP
    // ADD 47 - not implemented
    // UNKNOWN_117 117 - not implemented
    // UNKNOWN_115 115 - not implemented
    // UNKNOWN_114 114 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_108 108 - not implemented
    // UNKNOWN_111 111 - not implemented
    // UNKNOWN_99 99 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_108 108 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_108 108 - not implemented
    // UNKNOWN_105 105 - not implemented
    // UNKNOWN_98 98 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_111 111 - not implemented
    // UNKNOWN_98 98 - not implemented
    // UNKNOWN_99 99 - not implemented
    // UNKNOWN_112 112 - not implemented
    // UNKNOWN_108 108 - not implemented
    // ADD 47 - not implemented
    // UNKNOWN_85 85 - not implemented
    L27:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_6 6 - not implemented
    L25:
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_120 120 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_120 120 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L28:
    // UNKNOWN_90 90 - not implemented
    L29:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_120 120 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_121 121 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_88 88 - not implemented
    L29:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_121 121 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L27:
    bcpl_push(bcpl_load_global(68)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_120 120 - not implemented
    bcpl_push(106); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_120 120 - not implemented
    // UNKNOWN_14 14 - not implemented
    // CALL 255 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L30:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_121 121 - not implemented
    bcpl_push(bcpl_load_global(70)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    // NEGATE 51 - not implemented
    // UNKNOWN_68 68 - not implemented
    bcpl_push(bcpl_load_global(70)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(106); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    // NEGATE 51 - not implemented
    // UNKNOWN_68 68 - not implemented
    bcpl_push(bcpl_load_global(70)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(42); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_68 68 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_193 193 - not implemented
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L24:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(197); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_87 87 - not implemented
    L31:
    bcpl_push(104); // LOAD_CONSTANT
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_104 104 - not implemented
    bcpl_push(104); // LOAD_CONSTANT
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_193 193 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(104); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(103); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 96 - TODO: implement function calls
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L31:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(193); // LOAD_CONSTANT
    bcpl_push(11); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L5:
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L6:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_101 101 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L33:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 33 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L34:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L35:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(101); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_101 101 - not implemented
    // UNKNOWN_85 85 - not implemented
    L34:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L7:
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 48 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L37:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 57 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L37:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 48 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // UNKNOWN_98 98 - not implemented
    L36:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L37:
    // CALL 65 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L39:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 70 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L39:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 65 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L39:
    // CALL 97 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L41:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 102 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L41:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 97 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L41:
    // CALL 100 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L40:
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38:
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L36:
    // UNKNOWN_90 90 - not implemented
    L36:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L9:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_100 100 - not implemented
    L43:
    // UNKNOWN_101 101 - not implemented
    L42:
    // UNKNOWN_89 89 - not implemented
    L42:
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_5 5 - not implemented
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L45:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    // CALL 42 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L46:
    // CALL 10 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L49:
    // CALL 32 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L49:
    // CALL 9 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L50:
    // CALL 10 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L51:
    // CALL 1 - TODO: implement function calls
    bcpl_push(133); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    // UNKNOWN_90 90 - not implemented
    L51:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 10 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L50:
    // CALL 32 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L50:
    // CALL 9 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L50:
    // CALL 42 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L52:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L52:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L43:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L48:
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    bcpl_push(92); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_117 117 - not implemented
    // CALL 84 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L53:
    // CALL 9 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L53:
    // CALL 83 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L54:
    // CALL 32 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L54:
    // CALL 78 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L55:
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L55:
    // CALL 69 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L56:
    // CALL 69 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L56:
    // CALL 66 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L57:
    // CALL 8 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L57:
    // CALL 80 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L58:
    // CALL 12 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L58:
    // CALL 67 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L59:
    // CALL 13 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L59:
    // CALL 88 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L60:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 16 - TODO: implement function calls
    // CALL 2 - TODO: implement function calls
    // JUMP_IF_ZERO 44 - not implemented
    L11:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L60:
    // CALL 48 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L61:
    bcpl_push(117); // LOAD_CONSTANT
    // CALL 57 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L61:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(117); // LOAD_CONSTANT
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 64 - TODO: implement function calls
    // UNKNOWN_11 11 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    // CALL 2 - TODO: implement function calls
    // JUMP_IF_ZERO 44 - not implemented
    L11:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 255 - TODO: implement function calls
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L62:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L62:
    // UNKNOWN_90 90 - not implemented
    L61:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L46:
    // CALL 10 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L63:
    // CALL 1 - TODO: implement function calls
    bcpl_push(133); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_133 133 - not implemented
    // UNKNOWN_90 90 - not implemented
    L63:
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L44:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L44:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_14 14 - not implemented
    L10:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L65:
    // UNKNOWN_90 90 - not implemented
    L66:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L67:
    // UNKNOWN_90 90 - not implemented
    L67:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_9 9 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L8:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L68:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_90 90 - not implemented
    L68:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L65:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_88 88 - not implemented
    L66:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L64:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L64:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L12:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_126 126 - not implemented
    L1:
    // UNKNOWN_131 131 - not implemented
    L2:
    // UNKNOWN_118 118 - not implemented
    L3:
    // UNKNOWN_119 119 - not implemented
    L4:
    // UNKNOWN_197 197 - not implemented
    L5:
    // UNKNOWN_112 112 - not implemented
    L6:
    // UNKNOWN_113 113 - not implemented
    L9:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // SUBTRACT 48 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_100 100 - not implemented
    L11:
    // UNKNOWN_101 101 - not implemented
    L10:
    // UNKNOWN_85 85 - not implemented
    L12:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_6 6 - not implemented
    L1:
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(168); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_15 15 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_168 168 - not implemented
    bcpl_push(168); // LOAD_CONSTANT
    bcpl_push(169); // LOAD_CONSTANT
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L14:
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_192 192 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 98 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L14:
    bcpl_push(168); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L2:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // MULTIPLY 49 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L15:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L15:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L3:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // DIVIDE 50 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 1 - TODO: implement function calls
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L16:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L4:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // NEGATE 51 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 2 - TODO: implement function calls
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L17:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L17:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L5:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 3 - TODO: implement function calls
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_98 98 - not implemented
    L18:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L18:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L6:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_53 53 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 4 - TODO: implement function calls
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_98 98 - not implemented
    L19:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L7:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_54 54 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 5 - TODO: implement function calls
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 5 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L20:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L8:
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(67)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_100 100 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_67 67 - not implemented
    bcpl_push(100); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_67 67 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_67 67 - not implemented
    // CALL 63 - TODO: implement function calls
    // UNKNOWN_88 88 - not implemented
    L23:
    bcpl_push(bcpl_load_global(67)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_132 132 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_68 68 - not implemented
    bcpl_push(bcpl_load_global(89)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_67 67 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_103 103 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_104 104 - not implemented
    // CALL 20 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_105 105 - not implemented
    bcpl_push(bcpl_load_global(91)); // LOAD_GLOBAL
    bcpl_push(126); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_89 89 - not implemented
    // CALL -1 - TODO: implement function calls
    bcpl_push(117); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L24:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L21:
    // UNKNOWN_90 90 - not implemented
    L24:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_90 90 - not implemented
    bcpl_push(bcpl_load_global(219)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_89 89 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_106 106 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_220 220 - not implemented
    bcpl_push(bcpl_load_global(477)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_219 219 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_108 108 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_109 109 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_478 478 - not implemented
    bcpl_push(bcpl_load_global(579)); // LOAD_GLOBAL
    bcpl_store_global(100, bcpl_pop()); // STORE_GLOBAL
    L26:
    // UNKNOWN_101 101 - not implemented
    L25:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_477 477 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_148 148 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 100 - TODO: implement function calls
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L27:
    // UNKNOWN_90 90 - not implemented
    L28:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_579 579 - not implemented
    bcpl_push(148); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_579 579 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_580 580 - not implemented
    // UNKNOWN_88 88 - not implemented
    L28:
    bcpl_push(bcpl_load_global(579)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    bcpl_push(121); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_579 579 - not implemented
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_579 579 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_135 135 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_136 136 - not implemented
    // UNKNOWN_89 89 - not implemented
    L25:
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_579 579 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(128); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_87 87 - not implemented
    L29:
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    goto 7; // JUMP
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_73 73 - not implemented
    // NEGATE 51 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_push(106); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_579 579 - not implemented
    // CALL 90 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L30:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L21:
    // UNKNOWN_90 90 - not implemented
    L30:
    // JUMP_IF_ZERO 44 - not implemented
    L26:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L29:
    // UNKNOWN_100 100 - not implemented
    L32:
    // UNKNOWN_101 101 - not implemented
    L31:
    // UNKNOWN_85 85 - not implemented
    L33:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L31:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(174); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L35:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 95 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 48 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L37:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 48 - TODO: implement function calls
    // JUMP_IF_ZERO 44 - not implemented
    L32:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L36:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L37:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L36:
    // UNKNOWN_90 90 - not implemented
    L36:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L34:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(579)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L33:
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // MULTIPLY 49 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L39:
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    // CALL 49 - TODO: implement function calls
    // JUMP_IF_ZERO 44 - not implemented
    L32:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38:
    bcpl_push(bcpl_load_global(579)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L39:
    // CALL 48 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L41:
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    // CALL 48 - TODO: implement function calls
    // JUMP_IF_ZERO 44 - not implemented
    L32:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40:
    bcpl_push(bcpl_load_global(579)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L41:
    bcpl_push(bcpl_load_global(581)); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40:
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38:
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_579 579 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_90 90 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L42:
    bcpl_push(bcpl_load_global(582)); // LOAD_GLOBAL
    // CALL 99 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_580 580 - not implemented
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_579 579 - not implemented
    // UNKNOWN_98 98 - not implemented
    L21:
    bcpl_push(bcpl_load_global(579)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(477)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(219)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(89)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(67)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L21:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L9:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(191); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_191 191 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    goto 29; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(133); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L11:
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(131); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(191); // LOAD_CONSTANT
    bcpl_push(192); // LOAD_CONSTANT
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L43:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    goto 21; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    bcpl_push(30); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L43:
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_122 122 - not implemented
    // UNKNOWN_85 85 - not implemented
    L45:
    // UNKNOWN_90 90 - not implemented
    L44:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    // CALL 91 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L46:
    // CALL 92 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L46:
    // CALL 74 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L46:
    // CALL 40 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L46:
    // CALL 90 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L46:
    bcpl_push(122); // LOAD_CONSTANT
    // UNKNOWN_87 87 - not implemented
    L44:
    // UNKNOWN_90 90 - not implemented
    L46:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(135); // LOAD_CONSTANT
    bcpl_push(136); // LOAD_CONSTANT
    bcpl_push(32); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L10:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_85 85 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L50:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    goto 8; // JUMP
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L51:
    goto 18; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L52:
    goto 17; // JUMP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L53:
    goto 16; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L54:
    goto 11; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L55:
    goto 17; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_73 73 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L56:
    goto 17; // JUMP
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_71 71 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L57:
    goto 21; // JUMP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L58:
    // UNKNOWN_90 90 - not implemented
    L59:
    // UNKNOWN_90 90 - not implemented
    L60:
    goto 13; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L61:
    goto 13; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L62:
    goto 13; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_36 36 - not implemented
    bcpl_push(39); // LOAD_CONSTANT
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L63:
    goto 22; // JUMP
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
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
    L47:
    // UNKNOWN_90 90 - not implemented
    L64:
    goto 19; // JUMP
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L65:
    goto 10; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L66:
    goto 32; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L67:
    // UNKNOWN_90 90 - not implemented
    L68:
    // UNKNOWN_90 90 - not implemented
    L69:
    goto 11; // JUMP
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
    L47:
    // UNKNOWN_90 90 - not implemented
    L70:
    goto 26; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L71:
    goto 21; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_85 85 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L72:
    // UNKNOWN_90 90 - not implemented
    L73:
    goto 15; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L74:
    goto 14; // JUMP
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L75:
    goto 16; // JUMP
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L76:
    goto 15; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L77:
    // UNKNOWN_90 90 - not implemented
    L78:
    goto 12; // JUMP
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L79:
    goto 15; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L80:
    // UNKNOWN_90 90 - not implemented
    L81:
    goto 12; // JUMP
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_39 39 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L82:
    goto 12; // JUMP
    // UNKNOWN_39 39 - not implemented
    // CALL 47 - TODO: implement function calls
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
    L47:
    // UNKNOWN_85 85 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L48:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_32 32 - not implemented
    L50:
    bcpl_push(bcpl_load_global(L51)); // LOAD_GLOBAL
    // UNKNOWN_94 94 - not implemented
    L52:
    // UNKNOWN_95 95 - not implemented
    L53:
    // UNKNOWN_96 96 - not implemented
    L54:
    // UNKNOWN_97 97 - not implemented
    L55:
    // UNKNOWN_98 98 - not implemented
    L56:
    // UNKNOWN_99 99 - not implemented
    L57:
    // UNKNOWN_8 8 - not implemented
    L58:
    // UNKNOWN_40 40 - not implemented
    L59:
    goto L60; // JUMP
    // UNKNOWN_6 6 - not implemented
    L61:
    // UNKNOWN_7 7 - not implemented
    L62:
    // UNKNOWN_9 9 - not implemented
    L63:
    // UNKNOWN_32 32 - not implemented
    L64:
    // UNKNOWN_33 33 - not implemented
    L65:
    // UNKNOWN_34 34 - not implemented
    L66:
    // UNKNOWN_15 15 - not implemented
    L67:
    // UNKNOWN_19 19 - not implemented
    L68:
    bcpl_push(L69); // LOAD_CONSTANT
    // UNKNOWN_30 30 - not implemented
    L70:
    // CALL L71 - TODO: implement function calls
    // JUMP_IF_ZERO 44 - not implemented
    L72:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L73:
    // DIVIDE 50 - not implemented
    L74:
    // NEGATE 51 - not implemented
    L75:
    // UNKNOWN_54 54 - not implemented
    L76:
    // UNKNOWN_57 57 - not implemented
    L77:
    // UNKNOWN_58 58 - not implemented
    L78:
    // UNKNOWN_60 60 - not implemented
    L79:
    // UNKNOWN_61 61 - not implemented
    L80:
    // UNKNOWN_62 62 - not implemented
    L81:
    // UNKNOWN_63 63 - not implemented
    L82:
    // UNKNOWN_90 90 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L12:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_9 9 - not implemented
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
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // MULTIPLY 49 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L9:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_11 11 - not implemented
    L1:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(135); // LOAD_CONSTANT
    bcpl_push(136); // LOAD_CONSTANT
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    bcpl_store_global(100, bcpl_pop()); // STORE_GLOBAL
    L12:
    // UNKNOWN_101 101 - not implemented
    L11:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_135 135 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_136 136 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 97 - TODO: implement function calls
    bcpl_push(154); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_85 85 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L15:
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_90 90 - not implemented
    L17:
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_8 8 - not implemented
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(147); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_85 85 - not implemented
    L14:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L18:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(145); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_89 89 - not implemented
    L11:
    // UNKNOWN_85 85 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L19:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(145); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L20:
    // CALL 40 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L19:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 74 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_85 85 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L21:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 92 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L22:
    // CALL 90 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L22:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 51 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_85 85 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L13:
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_6 6 - not implemented
    L21:
    // UNKNOWN_75 75 - not implemented
    L15:
    // UNKNOWN_79 79 - not implemented
    L16:
    // UNKNOWN_76 76 - not implemented
    L17:
    // UNKNOWN_74 74 - not implemented
    L18:
    bcpl_store_global(L23, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_135 135 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_136 136 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L10:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L2:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_5 5 - not implemented
    // CALL 97 - TODO: implement function calls
    bcpl_push(154); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 92 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L27:
    // CALL 90 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 73 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L25:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L3:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(45, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_135 135 - not implemented
    bcpl_push(136); // LOAD_CONSTANT
    bcpl_store_global(100, bcpl_pop()); // STORE_GLOBAL
    L30:
    // UNKNOWN_101 101 - not implemented
    L29:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(31); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_135 135 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L30:
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_136 136 - not implemented
    // UNKNOWN_90 90 - not implemented
    L31:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 20 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L34:
    // CALL 54 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L34:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_85 85 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L32:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 45 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L33:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 43 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(14)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_12 12 - not implemented
    bcpl_push(164); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_89 89 - not implemented
    L29:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 97 - TODO: implement function calls
    bcpl_push(154); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 2 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L31:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_135 135 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_136 136 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L28:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_6 6 - not implemented
    L4:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(116); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // CALL 91 - TODO: implement function calls
    // CALL 6 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 92 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L36:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 7 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L36:
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L37:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_85 85 - not implemented
    L38:
    // UNKNOWN_90 90 - not implemented
    L37:
    bcpl_push(134); // LOAD_CONSTANT
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L39:
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_115 115 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 9 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L39:
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L35:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L35:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L5:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_38 38 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L41:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40:
    // UNKNOWN_90 90 - not implemented
    L41:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 38 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L6:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(116); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_5 5 - not implemented
    // CALL 2 - TODO: implement function calls
    // CALL 8 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L42:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_6 6 - not implemented
    L7:
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L43:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L43:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L8:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L44:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L44:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_140 140 - not implemented
    L1:
    // UNKNOWN_156 156 - not implemented
    L2:
    // UNKNOWN_147 147 - not implemented
    L3:
    // UNKNOWN_141 141 - not implemented
    L4:
    // UNKNOWN_142 142 - not implemented
    L5:
    // UNKNOWN_143 143 - not implemented
    L6:
    // UNKNOWN_154 154 - not implemented
    L7:
    // UNKNOWN_153 153 - not implemented
    L8:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // DIVIDE 50 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L3:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L1:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L5:
    // UNKNOWN_90 90 - not implemented
    L7:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L8:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 16 - TODO: implement function calls
    bcpl_push(161); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L9:
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L11:
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L12:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 1 - TODO: implement function calls
    bcpl_push(107); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(167); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(107); // LOAD_CONSTANT
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(106); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_88 88 - not implemented
    L14:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L15:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 1 - TODO: implement function calls
    bcpl_push(101); // LOAD_CONSTANT
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L16:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 106 - TODO: implement function calls
    // CALL 15 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L17:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 6 - TODO: implement function calls
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L18:
    // CALL 8 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_90 90 - not implemented
    L20:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 37 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L21:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L22:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 34 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L23:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_17 17 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_85 85 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 17 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L25:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 30 - TODO: implement function calls
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 24 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 19 - TODO: implement function calls
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 35 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_90 90 - not implemented
    L27:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 39 - TODO: implement function calls
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L4:
    // UNKNOWN_85 85 - not implemented
    L6:
    // UNKNOWN_90 90 - not implemented
    L5:
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_16 16 - not implemented
    L7:
    // UNKNOWN_16 16 - not implemented
    L8:
    // UNKNOWN_4 4 - not implemented
    L9:
    // UNKNOWN_5 5 - not implemented
    L10:
    // UNKNOWN_2 2 - not implemented
    L11:
    // UNKNOWN_3 3 - not implemented
    L12:
    // UNKNOWN_1 1 - not implemented
    L15:
    // UNKNOWN_105 105 - not implemented
    L16:
    // UNKNOWN_6 6 - not implemented
    L17:
    // UNKNOWN_9 9 - not implemented
    L18:
    // UNKNOWN_7 7 - not implemented
    L19:
    // UNKNOWN_8 8 - not implemented
    L20:
    // UNKNOWN_14 14 - not implemented
    L21:
    // UNKNOWN_15 15 - not implemented
    L22:
    // UNKNOWN_30 30 - not implemented
    L25:
    // UNKNOWN_19 19 - not implemented
    L26:
    // UNKNOWN_39 39 - not implemented
    L27:
    // UNKNOWN_90 90 - not implemented
    L6:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L4:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L2:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(174); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(90, bcpl_pop()); // STORE_GLOBAL
    L29:
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_store_global(100, bcpl_pop()); // STORE_GLOBAL
    L31:
    // UNKNOWN_101 101 - not implemented
    L30:
    // UNKNOWN_100 100 - not implemented
    L33:
    // UNKNOWN_101 101 - not implemented
    L32:
    bcpl_push(122); // LOAD_CONSTANT
    // UNKNOWN_87 87 - not implemented
    L34:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_85 85 - not implemented
    L35:
    // UNKNOWN_90 90 - not implemented
    L37:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L38:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 106 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L39:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L39:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 106 - TODO: implement function calls
    // CALL 19 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L29:
    // UNKNOWN_90 90 - not implemented
    L40:
    // CALL 36 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L41:
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_90 90 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L44:
    // CALL 35 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    // UNKNOWN_90 90 - not implemented
    L46:
    // CALL 34 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L50:
    // UNKNOWN_90 90 - not implemented
    L51:
    // UNKNOWN_90 90 - not implemented
    L52:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 30 - TODO: implement function calls
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L53:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L53:
    // UNKNOWN_90 90 - not implemented
    L54:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 30 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L55:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_85 85 - not implemented
    L56:
    // UNKNOWN_90 90 - not implemented
    L55:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 33 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L56:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 20 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_87 87 - not implemented
    L57:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 25 - TODO: implement function calls
    // UNKNOWN_24 24 - not implemented
    // UNKNOWN_86 86 - not implemented
    L54:
    // UNKNOWN_90 90 - not implemented
    L57:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L29:
    // UNKNOWN_90 90 - not implemented
    L58:
    // UNKNOWN_90 90 - not implemented
    L59:
    // CALL 25 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 30 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L31:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L60:
    // CALL 23 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L61:
    // CALL 22 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L62:
    // UNKNOWN_90 90 - not implemented
    L63:
    // CALL 21 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L33:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L64:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 13 - TODO: implement function calls
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L65:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L65:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 38 - TODO: implement function calls
    // CALL 30 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 37 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(16)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(164); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L29:
    // UNKNOWN_89 89 - not implemented
    L32:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_89 89 - not implemented
    L30:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L66:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L66:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L29:
    // UNKNOWN_85 85 - not implemented
    L36:
    // UNKNOWN_90 90 - not implemented
    L35:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_21 21 - not implemented
    L37:
    // UNKNOWN_105 105 - not implemented
    L38:
    // UNKNOWN_28 28 - not implemented
    L40:
    // UNKNOWN_9 9 - not implemented
    L41:
    // UNKNOWN_13 13 - not implemented
    L42:
    // UNKNOWN_11 11 - not implemented
    L43:
    // UNKNOWN_12 12 - not implemented
    L44:
    // UNKNOWN_14 14 - not implemented
    L45:
    // UNKNOWN_15 15 - not implemented
    L46:
    // UNKNOWN_20 20 - not implemented
    L47:
    // UNKNOWN_21 21 - not implemented
    L48:
    // UNKNOWN_24 24 - not implemented
    L49:
    // UNKNOWN_25 25 - not implemented
    L50:
    // UNKNOWN_22 22 - not implemented
    L51:
    // UNKNOWN_23 23 - not implemented
    L52:
    // UNKNOWN_31 31 - not implemented
    L58:
    // UNKNOWN_32 32 - not implemented
    L59:
    // UNKNOWN_33 33 - not implemented
    L60:
    // UNKNOWN_34 34 - not implemented
    L61:
    // UNKNOWN_35 35 - not implemented
    L62:
    // UNKNOWN_36 36 - not implemented
    L63:
    // UNKNOWN_37 37 - not implemented
    L64:
    // UNKNOWN_90 90 - not implemented
    L36:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L29:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L3:
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L68:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L67:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(45, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2 2 - not implemented
    bcpl_store_global(90, bcpl_pop()); // STORE_GLOBAL
    L70:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_38 38 - not implemented
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L71:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L69:
    // UNKNOWN_90 90 - not implemented
    L71:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 38 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L70:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L69:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L68:
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L73:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L72:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L75:
    // UNKNOWN_90 90 - not implemented
    L77:
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L78:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 40 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L78:
    // CALL 2 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L79:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(142); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L79:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 106 - TODO: implement function calls
    // CALL 41 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 89 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L80:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 45 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(165); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L74:
    // UNKNOWN_90 90 - not implemented
    L80:
    // CALL 20 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L81:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 44 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(165); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L74:
    // UNKNOWN_90 90 - not implemented
    L81:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 42 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L82:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 44 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L83:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 103 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L84:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L85:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 43 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L85:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 42 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L74:
    // UNKNOWN_90 90 - not implemented
    L84:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 41 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L74:
    // UNKNOWN_85 85 - not implemented
    L76:
    // UNKNOWN_90 90 - not implemented
    L75:
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_2 2 - not implemented
    L82:
    // UNKNOWN_105 105 - not implemented
    L77:
    // UNKNOWN_20 20 - not implemented
    L83:
    // UNKNOWN_90 90 - not implemented
    L76:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L74:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L73:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_174 174 - not implemented
    L1:
    // UNKNOWN_144 144 - not implemented
    L2:
    // UNKNOWN_155 155 - not implemented
    L67:
    // UNKNOWN_145 145 - not implemented
    L72:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_52 52 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_100 100 - not implemented
    L2:
    // UNKNOWN_101 101 - not implemented
    L1:
    // UNKNOWN_85 85 - not implemented
    L4:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L1:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L6:
    // UNKNOWN_90 90 - not implemented
    L8:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L9:
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L11:
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L15:
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_90 90 - not implemented
    L17:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 50 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L18:
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(155); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L18:
    // CALL 54 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L19:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L20:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 50 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L20:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 54 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(164); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L21:
    // CALL 51 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L21:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 51 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L27:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 101 - TODO: implement function calls
    bcpl_push(154); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L28:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 101 - TODO: implement function calls
    bcpl_push(154); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 102 - TODO: implement function calls
    // CALL 54 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 55 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(164); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L29:
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_10 10 - not implemented
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    bcpl_push(143); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 20 - TODO: implement function calls
    // CALL 57 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 99 - TODO: implement function calls
    // CALL 58 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 100 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L30:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 101 - TODO: implement function calls
    bcpl_push(154); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 56 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(17)); // LOAD_GLOBAL
    bcpl_push(146); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_15 15 - not implemented
    bcpl_push(166); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L31:
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(116); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L36:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 98 - TODO: implement function calls
    // CALL 60 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 70 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(156); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L37:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 54 - TODO: implement function calls
    // CALL 61 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 71 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L38:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 54 - TODO: implement function calls
    // CALL 62 - TODO: implement function calls
    bcpl_push(153); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 72 - TODO: implement function calls
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L39:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(140); // LOAD_CONSTANT
    bcpl_push(141); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_85 85 - not implemented
    L7:
    // UNKNOWN_90 90 - not implemented
    L6:
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_26 26 - not implemented
    L8:
    // UNKNOWN_2 2 - not implemented
    L9:
    // UNKNOWN_1 1 - not implemented
    L10:
    // UNKNOWN_3 3 - not implemented
    L11:
    // UNKNOWN_4 4 - not implemented
    L12:
    // UNKNOWN_5 5 - not implemented
    L13:
    // UNKNOWN_7 7 - not implemented
    L14:
    // UNKNOWN_8 8 - not implemented
    L15:
    // UNKNOWN_9 9 - not implemented
    L16:
    // UNKNOWN_105 105 - not implemented
    L17:
    // UNKNOWN_52 52 - not implemented
    L22:
    // UNKNOWN_53 53 - not implemented
    L23:
    // UNKNOWN_57 57 - not implemented
    L24:
    // UNKNOWN_58 58 - not implemented
    L25:
    // UNKNOWN_59 59 - not implemented
    L26:
    // UNKNOWN_60 60 - not implemented
    L27:
    // UNKNOWN_55 55 - not implemented
    L28:
    // UNKNOWN_56 56 - not implemented
    L29:
    // UNKNOWN_65 65 - not implemented
    L31:
    // UNKNOWN_66 66 - not implemented
    L32:
    // UNKNOWN_67 67 - not implemented
    L33:
    // UNKNOWN_68 68 - not implemented
    L34:
    // UNKNOWN_69 69 - not implemented
    L35:
    // UNKNOWN_70 70 - not implemented
    L36:
    // UNKNOWN_71 71 - not implemented
    L37:
    // UNKNOWN_72 72 - not implemented
    L38:
    bcpl_push(bcpl_load_global(L39)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L7:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L5:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L3:
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // JUMP_IF_ZERO 44 - not implemented
    L2:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L41:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 51 - TODO: implement function calls
    bcpl_push(151); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L41:
    // UNKNOWN_85 85 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L42:
    bcpl_push(115); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    bcpl_push(120); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 61 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L44:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(162); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L45:
    // UNKNOWN_90 90 - not implemented
    L44:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 0 - TODO: implement function calls
    bcpl_push(144); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(163); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L43:
    // CALL 61 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L42:
    // CALL 62 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L42:
    // CALL 63 - TODO: implement function calls
    bcpl_push(115); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L42:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_98 98 - not implemented
    L40:
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L4:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_146 146 - not implemented
    L3:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L2:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L1:
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(100, bcpl_pop()); // STORE_GLOBAL
    L3:
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
    // ADD 47 - not implemented
    L3:
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L4:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    goto 3; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L4:
    // UNKNOWN_85 85 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L7:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(62); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L8:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    goto 4; // JUMP
    // UNKNOWN_34 34 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_34 34 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L10:
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L11:
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L15:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_90 90 - not implemented
    L17:
    // UNKNOWN_90 90 - not implemented
    L18:
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L21:
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L29:
    // UNKNOWN_90 90 - not implemented
    L30:
    // UNKNOWN_90 90 - not implemented
    L31:
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_90 90 - not implemented
    L35:
    // UNKNOWN_90 90 - not implemented
    L36:
    // UNKNOWN_90 90 - not implemented
    L37:
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_90 90 - not implemented
    L39:
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_90 90 - not implemented
    L41:
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_90 90 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L44:
    // UNKNOWN_90 90 - not implemented
    L45:
    // UNKNOWN_90 90 - not implemented
    L46:
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L50:
    // UNKNOWN_90 90 - not implemented
    L51:
    // UNKNOWN_90 90 - not implemented
    L52:
    // UNKNOWN_90 90 - not implemented
    L53:
    // UNKNOWN_90 90 - not implemented
    L54:
    // UNKNOWN_90 90 - not implemented
    L55:
    // UNKNOWN_90 90 - not implemented
    L56:
    // UNKNOWN_90 90 - not implemented
    L57:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L58:
    // UNKNOWN_90 90 - not implemented
    L59:
    // UNKNOWN_90 90 - not implemented
    L60:
    // UNKNOWN_90 90 - not implemented
    L61:
    // UNKNOWN_90 90 - not implemented
    L62:
    // UNKNOWN_90 90 - not implemented
    L63:
    // UNKNOWN_90 90 - not implemented
    L64:
    // UNKNOWN_90 90 - not implemented
    L65:
    // UNKNOWN_90 90 - not implemented
    L66:
    // UNKNOWN_90 90 - not implemented
    L67:
    // UNKNOWN_90 90 - not implemented
    L68:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L69:
    // UNKNOWN_90 90 - not implemented
    L70:
    // UNKNOWN_90 90 - not implemented
    L71:
    // UNKNOWN_90 90 - not implemented
    L72:
    // UNKNOWN_90 90 - not implemented
    L73:
    // UNKNOWN_90 90 - not implemented
    L74:
    // UNKNOWN_90 90 - not implemented
    L75:
    // UNKNOWN_90 90 - not implemented
    L76:
    // UNKNOWN_90 90 - not implemented
    L77:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L78:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    goto 3; // JUMP
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L78:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    goto 2; // JUMP
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(62); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L79:
    // UNKNOWN_90 90 - not implemented
    L80:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L81:
    // UNKNOWN_90 90 - not implemented
    L82:
    bcpl_push(bcpl_load_global(13)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_90 90 - not implemented
    L81:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_88 88 - not implemented
    L82:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    goto 2; // JUMP
    // CALL 45 - TODO: implement function calls
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L84:
    goto 2; // JUMP
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_98 98 - not implemented
    L83:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L84:
    goto 2; // JUMP
    // UNKNOWN_33 33 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_98 98 - not implemented
    L83:
    // UNKNOWN_90 90 - not implemented
    L83:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(152); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L79:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_88 88 - not implemented
    L80:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_85 85 - not implemented
    L6:
    // UNKNOWN_90 90 - not implemented
    L5:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_70 70 - not implemented
    L77:
    // UNKNOWN_1 1 - not implemented
    L7:
    // UNKNOWN_2 2 - not implemented
    L8:
    // UNKNOWN_3 3 - not implemented
    L9:
    // UNKNOWN_56 56 - not implemented
    L10:
    // UNKNOWN_37 37 - not implemented
    L11:
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L13:
    // UNKNOWN_55 55 - not implemented
    L14:
    goto L15; // JUMP
    // SUBTRACT 48 - not implemented
    L16:
    // MULTIPLY 49 - not implemented
    L17:
    // UNKNOWN_9 9 - not implemented
    L18:
    // UNKNOWN_28 28 - not implemented
    L19:
    // UNKNOWN_10 10 - not implemented
    L20:
    // UNKNOWN_11 11 - not implemented
    L21:
    // UNKNOWN_12 12 - not implemented
    L22:
    // UNKNOWN_13 13 - not implemented
    L23:
    // UNKNOWN_14 14 - not implemented
    L24:
    // UNKNOWN_15 15 - not implemented
    L25:
    // UNKNOWN_20 20 - not implemented
    L26:
    // UNKNOWN_21 21 - not implemented
    L27:
    // UNKNOWN_22 22 - not implemented
    L28:
    // UNKNOWN_23 23 - not implemented
    L29:
    // UNKNOWN_24 24 - not implemented
    L30:
    // UNKNOWN_25 25 - not implemented
    L31:
    // UNKNOWN_31 31 - not implemented
    L32:
    // UNKNOWN_32 32 - not implemented
    L33:
    // UNKNOWN_33 33 - not implemented
    L34:
    // UNKNOWN_34 34 - not implemented
    L35:
    // UNKNOWN_35 35 - not implemented
    L36:
    // UNKNOWN_36 36 - not implemented
    L37:
    // UNKNOWN_38 38 - not implemented
    L38:
    // UNKNOWN_40 40 - not implemented
    L39:
    bcpl_push(L40); // LOAD_CONSTANT
    // CALL L41 - TODO: implement function calls
    // DIVIDE 50 - not implemented
    L42:
    // NEGATE 51 - not implemented
    L43:
    // UNKNOWN_54 54 - not implemented
    L44:
    // UNKNOWN_57 57 - not implemented
    L45:
    // UNKNOWN_58 58 - not implemented
    L46:
    // UNKNOWN_59 59 - not implemented
    L47:
    // UNKNOWN_60 60 - not implemented
    L48:
    // UNKNOWN_62 62 - not implemented
    L49:
    // UNKNOWN_63 63 - not implemented
    L50:
    // UNKNOWN_70 70 - not implemented
    L51:
    // UNKNOWN_71 71 - not implemented
    L52:
    // UNKNOWN_73 73 - not implemented
    L53:
    // UNKNOWN_74 74 - not implemented
    L54:
    // UNKNOWN_75 75 - not implemented
    L55:
    // UNKNOWN_79 79 - not implemented
    L56:
    // UNKNOWN_76 76 - not implemented
    L57:
    // UNKNOWN_6 6 - not implemented
    L58:
    // UNKNOWN_7 7 - not implemented
    L59:
    // UNKNOWN_8 8 - not implemented
    L60:
    // UNKNOWN_17 17 - not implemented
    L61:
    // UNKNOWN_30 30 - not implemented
    L62:
    // UNKNOWN_39 39 - not implemented
    L63:
    // UNKNOWN_52 52 - not implemented
    L64:
    // UNKNOWN_53 53 - not implemented
    L65:
    // UNKNOWN_61 61 - not implemented
    L66:
    // UNKNOWN_72 72 - not implemented
    L67:
    // UNKNOWN_19 19 - not implemented
    L68:
    // UNKNOWN_65 65 - not implemented
    L69:
    // UNKNOWN_66 66 - not implemented
    L70:
    // UNKNOWN_67 67 - not implemented
    L71:
    // UNKNOWN_68 68 - not implemented
    L72:
    // UNKNOWN_69 69 - not implemented
    L73:
    // UNKNOWN_4 4 - not implemented
    L74:
    // UNKNOWN_5 5 - not implemented
    L75:
    // UNKNOWN_16 16 - not implemented
    L76:
    // UNKNOWN_90 90 - not implemented
    L6:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L2:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_152 152 - not implemented
    L1:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // SUBTRACT 48 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_100 100 - not implemented
    L4:
    // UNKNOWN_101 101 - not implemented
    L3:
    // UNKNOWN_85 85 - not implemented
    L5:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L1:
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(244); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_244 244 - not implemented
    bcpl_push(244); // LOAD_CONSTANT
    // UNKNOWN_98 98 - not implemented
    L6:
    // UNKNOWN_90 90 - not implemented
    L6:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_11 11 - not implemented
    L2:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(191); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_191 191 - not implemented
    bcpl_push(191); // LOAD_CONSTANT
    bcpl_push(192); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L7:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    goto 21; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 8 - TODO: implement function calls
    bcpl_push(30); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L7:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    goto 11; // JUMP
    // UNKNOWN_10 10 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_58 58 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    goto 22; // JUMP
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(288); // LOAD_CONSTANT
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 4 - TODO: implement function calls
    bcpl_push(152); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(63); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(195); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L3:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L9:
    // UNKNOWN_90 90 - not implemented
    L11:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    goto 18; // JUMP
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_37 37 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(76); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L12:
    goto 14; // JUMP
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L13:
    goto 38; // JUMP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_66 66 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_75 75 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L15:
    goto 30; // JUMP
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L16:
    goto 28; // JUMP
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L17:
    goto 16; // JUMP
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L18:
    goto 19; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L19:
    goto 23; // JUMP
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L20:
    goto 17; // JUMP
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L21:
    goto 26; // JUMP
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_70 70 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_65 65 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    // UNKNOWN_90 90 - not implemented
    L24:
    goto 28; // JUMP
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L26:
    goto 24; // JUMP
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_32 32 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_90 90 - not implemented
    L28:
    goto 25; // JUMP
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_88 88 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_98 98 - not implemented
    L8:
    // UNKNOWN_85 85 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L9:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_17 17 - not implemented
    L11:
    // UNKNOWN_141 141 - not implemented
    L12:
    // UNKNOWN_104 104 - not implemented
    L13:
    // UNKNOWN_101 101 - not implemented
    L14:
    // UNKNOWN_105 105 - not implemented
    L15:
    // UNKNOWN_106 106 - not implemented
    L16:
    // UNKNOWN_144 144 - not implemented
    L17:
    // UNKNOWN_142 142 - not implemented
    L18:
    // UNKNOWN_143 143 - not implemented
    L19:
    // UNKNOWN_115 115 - not implemented
    L20:
    // UNKNOWN_116 116 - not implemented
    L21:
    // UNKNOWN_117 117 - not implemented
    L22:
    // UNKNOWN_118 118 - not implemented
    L23:
    // UNKNOWN_119 119 - not implemented
    L24:
    // UNKNOWN_110 110 - not implemented
    L25:
    // UNKNOWN_112 112 - not implemented
    L26:
    // UNKNOWN_109 109 - not implemented
    L27:
    // UNKNOWN_113 113 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L10:
    // UNKNOWN_90 90 - not implemented
    L8:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(60); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L5:
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L30:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L29:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // JUMP_IF_NOT_ZERO 45 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(1505)); // LOAD_GLOBAL
    bcpl_store_global(45, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1506 1506 - not implemented
    bcpl_push(bcpl_load_global(1707)); // LOAD_GLOBAL
    bcpl_store_global(45, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1708 1708 - not implemented
    bcpl_push(bcpl_load_global(2009)); // LOAD_GLOBAL
    bcpl_store_global(45, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_2010 2010 - not implemented
    bcpl_push(bcpl_load_global(2311)); // LOAD_GLOBAL
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_260 260 - not implemented
    // CALL 3 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    // CALL 3 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // CALL 3 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_263 263 - not implemented
    // CALL 1500 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_264 264 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 1 - TODO: implement function calls
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 0 - TODO: implement function calls
    // CALL 2 - TODO: implement function calls
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_1505 1505 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_285 285 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_286 286 - not implemented
    // CALL 200 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_287 287 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_1707 1707 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_265 265 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2009 2009 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_266 266 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_267 267 - not implemented
    // CALL 300 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_268 268 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_269 269 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_274 274 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_273 273 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_272 272 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_288 288 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_270 270 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_251 251 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_244 244 - not implemented
    bcpl_push(282); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L31:
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 49 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L33:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 48 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L33:
    // UNKNOWN_85 85 - not implemented
    L34:
    // UNKNOWN_90 90 - not implemented
    L33:
    bcpl_push(bcpl_load_global(2313)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    bcpl_push(bcpl_load_global(2313)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    bcpl_push(289); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_90 90 - not implemented
    L31:
    bcpl_push(bcpl_load_global(2313)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    bcpl_push(bcpl_load_global(2313)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(209); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    bcpl_push(bcpl_load_global(2313)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    bcpl_push(bcpl_load_global(2313)); // LOAD_GLOBAL
    // CALL 76 - TODO: implement function calls
    bcpl_push(286); // LOAD_CONSTANT
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_12 12 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L36:
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(bcpl_load_global(2314)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    bcpl_push(285); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(295); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2312 2312 - not implemented
    bcpl_push(bcpl_load_global(2314)); // LOAD_GLOBAL
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(285); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(296); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2312 2312 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    // UNKNOWN_90 90 - not implemented
    L36:
    bcpl_push(286); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2311 2311 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L35:
    bcpl_push(bcpl_load_global(2314)); // LOAD_GLOBAL
    bcpl_push(252); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2312 2312 - not implemented
    bcpl_push(bcpl_load_global(2311)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(2009)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(1707)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(1505)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_243 243 - not implemented
    L1:
    // UNKNOWN_210 210 - not implemented
    L2:
    // UNKNOWN_245 245 - not implemented
    L29:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // MULTIPLY 49 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L2:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L1:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_100 100 - not implemented
    L4:
    // UNKNOWN_101 101 - not implemented
    L3:
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_89 89 - not implemented
    L3:
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L5:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L5:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_270 270 - not implemented
    // UNKNOWN_85 85 - not implemented
    L6:
    // UNKNOWN_90 90 - not implemented
    L8:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 100 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_281 281 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(201); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(204); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_281 281 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(207); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L10:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 110 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_90 90 - not implemented
    L10:
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L11:
    bcpl_push(281); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_90 90 - not implemented
    L11:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 92 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(209); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_281 281 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L12:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L15:
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L16:
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_85 85 - not implemented
    L18:
    // UNKNOWN_90 90 - not implemented
    L17:
    // CALL 79 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L19:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_12 12 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 78 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(234); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 102 - TODO: implement function calls
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L19:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // UNKNOWN_90 90 - not implemented
    L18:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L17:
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(209); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L21:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(230); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L22:
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_282 282 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(233); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 51 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 52 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L24:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 89 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L27:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L28:
    bcpl_push(275); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L29:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 104 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L29:
    // CALL 0 - TODO: implement function calls
    bcpl_push(275); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L30:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L31:
    bcpl_push(271); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L32:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 104 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L32:
    // CALL 0 - TODO: implement function calls
    bcpl_push(271); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L33:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // UNKNOWN_90 90 - not implemented
    L33:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L34:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 97 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 68 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L36:
    bcpl_push(272); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L37:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 104 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L37:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 98 - TODO: implement function calls
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L39:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_271 271 - not implemented
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(271); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L40:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L41:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_90 90 - not implemented
    L43:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 61 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L44:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_85 85 - not implemented
    L45:
    // UNKNOWN_90 90 - not implemented
    L44:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(275); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L46:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L46:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    // CALL 0 - TODO: implement function calls
    bcpl_push(271); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L47:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L48:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_267 267 - not implemented
    bcpl_push(268); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L49:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 141 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L49:
    bcpl_push(269); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L50:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 105 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L50:
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(267); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L51:
    // UNKNOWN_90 90 - not implemented
    L52:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(265); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L53:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 106 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_90 90 - not implemented
    L53:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L51:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_88 88 - not implemented
    L52:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(265); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(266); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(267); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_267 267 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L54:
    bcpl_push(269); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L55:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 105 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L55:
    // CALL 0 - TODO: implement function calls
    bcpl_push(273); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L56:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 101 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L56:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_273 273 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(273); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L57:
    bcpl_push(269); // LOAD_CONSTANT
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L58:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 105 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L58:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L59:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(221); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L60:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(222); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L61:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(288); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_288 288 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L4:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_85 85 - not implemented
    L7:
    // UNKNOWN_90 90 - not implemented
    L6:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_27 27 - not implemented
    L8:
    // UNKNOWN_74 74 - not implemented
    L9:
    // UNKNOWN_79 79 - not implemented
    L13:
    // UNKNOWN_76 76 - not implemented
    L14:
    // UNKNOWN_75 75 - not implemented
    L15:
    // DIVIDE 50 - not implemented
    L21:
    // NEGATE 51 - not implemented
    L22:
    // UNKNOWN_52 52 - not implemented
    L23:
    // UNKNOWN_54 54 - not implemented
    L24:
    // UNKNOWN_58 58 - not implemented
    L25:
    // UNKNOWN_57 57 - not implemented
    L26:
    // UNKNOWN_55 55 - not implemented
    L27:
    // UNKNOWN_65 65 - not implemented
    L28:
    // UNKNOWN_66 66 - not implemented
    L31:
    // UNKNOWN_67 67 - not implemented
    L34:
    // UNKNOWN_68 68 - not implemented
    L35:
    // UNKNOWN_53 53 - not implemented
    L36:
    // UNKNOWN_59 59 - not implemented
    L38:
    // UNKNOWN_60 60 - not implemented
    L39:
    // UNKNOWN_62 62 - not implemented
    L41:
    // UNKNOWN_63 63 - not implemented
    L42:
    // UNKNOWN_61 61 - not implemented
    L43:
    // UNKNOWN_71 71 - not implemented
    L48:
    // UNKNOWN_72 72 - not implemented
    L54:
    // UNKNOWN_69 69 - not implemented
    L57:
    // UNKNOWN_70 70 - not implemented
    L59:
    // UNKNOWN_56 56 - not implemented
    L60:
    // UNKNOWN_73 73 - not implemented
    L61:
    // UNKNOWN_90 90 - not implemented
    L7:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L2:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_200 200 - not implemented
    L1:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // DIVIDE 50 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_100 100 - not implemented
    L9:
    // UNKNOWN_101 101 - not implemented
    L8:
    // UNKNOWN_100 100 - not implemented
    L12:
    // UNKNOWN_101 101 - not implemented
    L11:
    // UNKNOWN_100 100 - not implemented
    L14:
    // UNKNOWN_101 101 - not implemented
    L13:
    // UNKNOWN_100 100 - not implemented
    L16:
    // UNKNOWN_101 101 - not implemented
    L15:
    // UNKNOWN_85 85 - not implemented
    L17:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L1:
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L18:
    // UNKNOWN_85 85 - not implemented
    L19:
    // UNKNOWN_90 90 - not implemented
    L21:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 102 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(202); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L25:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(203); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(201); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(201); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_85 85 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_5 5 - not implemented
    L21:
    // CALL L22 - TODO: implement function calls
    bcpl_push(L23); // LOAD_CONSTANT
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L24:
    // JUMP_IF_ZERO 44 - not implemented
    L25:
    // UNKNOWN_40 40 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L18:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L2:
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L27:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L28:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 77 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 38 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L29:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 77 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(202); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L29:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 103 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L3:
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(206); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 76 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L30:
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 76 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(287); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L31:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 144 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L31:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(286); // LOAD_CONSTANT
    bcpl_push(285); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(286); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(285); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 2 - TODO: implement function calls
    bcpl_push(286); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_286 286 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 78 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(234); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 101 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L4:
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(204); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_13 13 - not implemented
    L5:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_75 75 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_85 85 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L32:
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L35:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L36:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 142 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L36:
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L35:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_86 86 - not implemented
    L34:
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L32:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L6:
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(264); // LOAD_CONSTANT
    // UNKNOWN_25 25 - not implemented
    // UNKNOWN_87 87 - not implemented
    L37:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 143 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L37:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(261); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    bcpl_push(261); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    // CALL 3 - TODO: implement function calls
    bcpl_push(261); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_12 12 - not implemented
    L7:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_store_global(90, bcpl_pop()); // STORE_GLOBAL
    L39:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L40:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L39:
    // UNKNOWN_90 90 - not implemented
    L40:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L38:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_10 10 - not implemented
    L8:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L41:
    // UNKNOWN_85 85 - not implemented
    L42:
    // UNKNOWN_90 90 - not implemented
    L44:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_83 83 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(203); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L46:
    // UNKNOWN_90 90 - not implemented
    L47:
    // UNKNOWN_90 90 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L49:
    // UNKNOWN_90 90 - not implemented
    L50:
    // UNKNOWN_90 90 - not implemented
    L51:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L52:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L53:
    // UNKNOWN_90 90 - not implemented
    L54:
    // UNKNOWN_90 90 - not implemented
    L55:
    // UNKNOWN_90 90 - not implemented
    L56:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L57:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L9:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_85 85 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_13 13 - not implemented
    L44:
    // UNKNOWN_54 54 - not implemented
    L45:
    // UNKNOWN_57 57 - not implemented
    L46:
    // UNKNOWN_58 58 - not implemented
    L47:
    // UNKNOWN_59 59 - not implemented
    L48:
    // UNKNOWN_60 60 - not implemented
    L49:
    // UNKNOWN_70 70 - not implemented
    L50:
    // UNKNOWN_71 71 - not implemented
    L51:
    // UNKNOWN_73 73 - not implemented
    L52:
    // UNKNOWN_61 61 - not implemented
    L53:
    // UNKNOWN_62 62 - not implemented
    L54:
    // UNKNOWN_63 63 - not implemented
    L55:
    // UNKNOWN_72 72 - not implemented
    L56:
    // UNKNOWN_55 55 - not implemented
    L57:
    // UNKNOWN_90 90 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L41:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L10:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L16:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_87 87 - not implemented
    L58:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L14:
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L58:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_12 12 - not implemented
    L11:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L59:
    // UNKNOWN_90 90 - not implemented
    L61:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L12:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L62:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 45 - TODO: implement function calls
    bcpl_push(281); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(281); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_281 281 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L63:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(233); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L64:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_85 85 - not implemented
    L60:
    // UNKNOWN_90 90 - not implemented
    L59:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_3 3 - not implemented
    L64:
    // UNKNOWN_40 40 - not implemented
    L61:
    // CALL L62 - TODO: implement function calls
    bcpl_push(L63); // LOAD_CONSTANT
    // UNKNOWN_90 90 - not implemented
    L60:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_13 13 - not implemented
    L13:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_85 85 - not implemented
    L65:
    // UNKNOWN_90 90 - not implemented
    L67:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L14:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L14:
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L68:
    // UNKNOWN_90 90 - not implemented
    L69:
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(263); // LOAD_CONSTANT
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_272 272 - not implemented
    // CALL -1 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_269 269 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(242); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(282); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_263 263 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(202); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_push(204); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(209); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 95 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 44 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L70:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 96 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_85 85 - not implemented
    L71:
    // UNKNOWN_90 90 - not implemented
    L70:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 97 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_90 90 - not implemented
    L71:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 103 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_272 272 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_269 269 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_263 263 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L72:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_85 85 - not implemented
    L66:
    // UNKNOWN_90 90 - not implemented
    L65:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_3 3 - not implemented
    L72:
    // UNKNOWN_40 40 - not implemented
    L67:
    // JUMP_IF_ZERO 44 - not implemented
    L68:
    // JUMP_IF_NOT_ZERO 45 - not implemented
    L69:
    // UNKNOWN_90 90 - not implemented
    L66:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L15:
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 44 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L75:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 45 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L74:
    // UNKNOWN_90 90 - not implemented
    L75:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L73:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L74:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_21 21 - not implemented
    // UNKNOWN_87 87 - not implemented
    L77:
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L76:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L77:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L16:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_87 87 - not implemented
    L79:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L78:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L79:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // JUMP_IF_ZERO 44 - not implemented
    L16:
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L78:
    // UNKNOWN_90 90 - not implemented
    L78:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L76:
    // UNKNOWN_90 90 - not implemented
    L76:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_98 98 - not implemented
    L73:
    // UNKNOWN_90 90 - not implemented
    L73:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L17:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_8 8 - not implemented
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
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // NEGATE 51 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L4:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L1:
    // UNKNOWN_74 74 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L5:
    // UNKNOWN_90 90 - not implemented
    L7:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L8:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_87 87 - not implemented
    L9:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L9:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L10:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L11:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_87 87 - not implemented
    L13:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_85 85 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L13:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L15:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_87 87 - not implemented
    L17:
    // CALL 86 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L16:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L17:
    // CALL 87 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L16:
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_85 85 - not implemented
    L6:
    // UNKNOWN_90 90 - not implemented
    L5:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_5 5 - not implemented
    L15:
    // UNKNOWN_5 5 - not implemented
    L7:
    // UNKNOWN_4 4 - not implemented
    L8:
    // UNKNOWN_30 30 - not implemented
    L10:
    // UNKNOWN_33 33 - not implemented
    L11:
    // UNKNOWN_34 34 - not implemented
    L12:
    // UNKNOWN_90 90 - not implemented
    L6:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_11 11 - not implemented
    L2:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_87 87 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_72 72 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(267); // LOAD_CONSTANT
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(273); // LOAD_CONSTANT
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_9 9 - not implemented
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_10 10 - not implemented
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_274 274 - not implemented
    bcpl_push(267); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_269 269 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_273 273 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(273); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L18:
    bcpl_push(274); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_273 273 - not implemented
    // UNKNOWN_90 90 - not implemented
    L18:
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // CALL 70 - TODO: implement function calls
    bcpl_push(267); // LOAD_CONSTANT
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_15 15 - not implemented
    bcpl_push(273); // LOAD_CONSTANT
    bcpl_push(294); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(269); // LOAD_CONSTANT
    bcpl_push(267); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L19:
    // UNKNOWN_90 90 - not implemented
    L20:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(265); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(295); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(266); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(296); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_88 88 - not implemented
    L20:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    bcpl_push(274); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_274 274 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_267 267 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_269 269 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_273 273 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L3:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_79 79 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_push(261); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_271 271 - not implemented
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_280 280 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 77 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_12 12 - not implemented
    bcpl_push(205); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(261); // LOAD_CONSTANT
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L21:
    // CALL 42 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_85 85 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L21:
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L23:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 4 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 92 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(241); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 5 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(209); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 5 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(275); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L24:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    bcpl_push(275); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_90 90 - not implemented
    L24:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_12 12 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 42 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_11 11 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 14 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 80 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_12 12 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_11 11 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L25:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_12 12 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_85 85 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L25:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 40 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_12 12 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 88 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(271); // LOAD_CONSTANT
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L27:
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    bcpl_push(271); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_271 271 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_275 275 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_12 12 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(15)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L4:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_220 220 - not implemented
    L1:
    // UNKNOWN_221 221 - not implemented
    L2:
    // UNKNOWN_222 222 - not implemented
    L3:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_52 52 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L5:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L1:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L6:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 148 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L6:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L7:
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 147 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L10:
    // CALL 120 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L11:
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_90 90 - not implemented
    L15:
    // UNKNOWN_90 90 - not implemented
    L16:
    // UNKNOWN_90 90 - not implemented
    L17:
    // UNKNOWN_90 90 - not implemented
    L18:
    // UNKNOWN_90 90 - not implemented
    L19:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L20:
    // UNKNOWN_90 90 - not implemented
    L21:
    // UNKNOWN_90 90 - not implemented
    L22:
    // UNKNOWN_90 90 - not implemented
    L23:
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L25:
    // UNKNOWN_90 90 - not implemented
    L26:
    // UNKNOWN_90 90 - not implemented
    L27:
    // UNKNOWN_90 90 - not implemented
    L28:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L30:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L29:
    // UNKNOWN_90 90 - not implemented
    L30:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L29:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 9 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L31:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // CALL 14 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // CALL 8 - TODO: implement function calls
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L31:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_90 90 - not implemented
    L34:
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L36:
    // UNKNOWN_90 90 - not implemented
    L37:
    // UNKNOWN_90 90 - not implemented
    L38:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L39:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(232); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L40:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 42 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L41:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 43 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    bcpl_push(289); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L42:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 40 - TODO: implement function calls
    // CALL 41 - TODO: implement function calls
    // CALL 44 - TODO: implement function calls
    // CALL 42 - TODO: implement function calls
    bcpl_push(237); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L43:
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_261 261 - not implemented
    bcpl_push(262); // LOAD_CONSTANT
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(209); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_272 272 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(200); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(272); // LOAD_CONSTANT
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 93 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_261 261 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_262 262 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_272 272 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L44:
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_282 282 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(233); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L45:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_store_global(41, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_280 280 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_9 9 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(220); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 98 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 91 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 98 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(240); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // CALL 93 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L46:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    bcpl_push(243); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(234); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_85 85 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L47:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 102 - TODO: implement function calls
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_90 90 - not implemented
    L48:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 38 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L47:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 102 - TODO: implement function calls
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 47 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L7:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_34 34 - not implemented
    L9:
    // UNKNOWN_28 28 - not implemented
    L10:
    // UNKNOWN_12 12 - not implemented
    L11:
    // UNKNOWN_13 13 - not implemented
    L12:
    // UNKNOWN_15 15 - not implemented
    L13:
    // UNKNOWN_22 22 - not implemented
    L14:
    // UNKNOWN_23 23 - not implemented
    L15:
    // UNKNOWN_24 24 - not implemented
    L16:
    // UNKNOWN_25 25 - not implemented
    L17:
    // UNKNOWN_31 31 - not implemented
    L18:
    // UNKNOWN_32 32 - not implemented
    L19:
    // UNKNOWN_9 9 - not implemented
    L20:
    // UNKNOWN_11 11 - not implemented
    L21:
    // UNKNOWN_14 14 - not implemented
    L22:
    // UNKNOWN_20 20 - not implemented
    L23:
    // UNKNOWN_21 21 - not implemented
    L24:
    // UNKNOWN_33 33 - not implemented
    L25:
    // UNKNOWN_34 34 - not implemented
    L26:
    // UNKNOWN_35 35 - not implemented
    L27:
    // UNKNOWN_36 36 - not implemented
    L28:
    // UNKNOWN_17 17 - not implemented
    L32:
    // UNKNOWN_30 30 - not implemented
    L33:
    // UNKNOWN_8 8 - not implemented
    L34:
    // UNKNOWN_19 19 - not implemented
    L35:
    // UNKNOWN_4 4 - not implemented
    L36:
    // UNKNOWN_5 5 - not implemented
    L37:
    // UNKNOWN_16 16 - not implemented
    L38:
    // UNKNOWN_7 7 - not implemented
    L39:
    // UNKNOWN_1 1 - not implemented
    L40:
    // UNKNOWN_3 3 - not implemented
    L41:
    // UNKNOWN_2 2 - not implemented
    L42:
    // UNKNOWN_6 6 - not implemented
    L43:
    // UNKNOWN_10 10 - not implemented
    L44:
    // UNKNOWN_37 37 - not implemented
    L45:
    // UNKNOWN_39 39 - not implemented
    L46:
    // UNKNOWN_90 90 - not implemented
    L8:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_6 6 - not implemented
    L2:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_100 100 - not implemented
    L50:
    // UNKNOWN_101 101 - not implemented
    L49:
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L51:
    // JUMP_IF_ZERO 44 - not implemented
    L50:
    // UNKNOWN_52 52 - not implemented
    // UNKNOWN_90 90 - not implemented
    L51:
    // UNKNOWN_85 85 - not implemented
    L52:
    // UNKNOWN_90 90 - not implemented
    L54:
    // UNKNOWN_89 89 - not implemented
    L49:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 113 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(236); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L55:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 45 - TODO: implement function calls
    // CALL 46 - TODO: implement function calls
    // CALL 47 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(237); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L56:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L57:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(40, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L58:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L58:
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 14 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L53:
    // UNKNOWN_90 90 - not implemented
    L52:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_3 3 - not implemented
    L54:
    // UNKNOWN_2 2 - not implemented
    L55:
    // UNKNOWN_8 8 - not implemented
    L56:
    // UNKNOWN_9 9 - not implemented
    L57:
    // UNKNOWN_90 90 - not implemented
    L53:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L3:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_90 90 - not implemented
    // UNKNOWN_69 69 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 42 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(280); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L4:
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L59:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 38 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L60:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L60:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(233); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(233); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L59:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L5:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_231 231 - not implemented
    L1:
    // UNKNOWN_232 232 - not implemented
    L2:
    // UNKNOWN_236 236 - not implemented
    L3:
    // UNKNOWN_233 233 - not implemented
    L4:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_53 53 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L4:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L1:
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_86 86 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L6:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 117 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L6:
    // UNKNOWN_85 85 - not implemented
    L7:
    // UNKNOWN_90 90 - not implemented
    L9:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 118 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L10:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(206); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L11:
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L11:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 119 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_98 98 - not implemented
    L5:
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L12:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L13:
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L14:
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L15:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_17 17 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L16:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_19 19 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L17:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_30 30 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L18:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L19:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_12 12 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L20:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_13 13 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L21:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L22:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_15 15 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_31 31 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L24:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_32 32 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L25:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_34 34 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_33 33 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L27:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_35 35 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_90 90 - not implemented
    L28:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(235); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_36 36 - not implemented
    // UNKNOWN_98 98 - not implemented
    L5:
    // UNKNOWN_85 85 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L7:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_18 18 - not implemented
    L9:
    // UNKNOWN_2 2 - not implemented
    L10:
    // UNKNOWN_1 1 - not implemented
    L12:
    // UNKNOWN_4 4 - not implemented
    L13:
    // UNKNOWN_5 5 - not implemented
    L14:
    // UNKNOWN_17 17 - not implemented
    L15:
    // UNKNOWN_19 19 - not implemented
    L16:
    // UNKNOWN_30 30 - not implemented
    L17:
    // UNKNOWN_11 11 - not implemented
    L18:
    // UNKNOWN_12 12 - not implemented
    L19:
    // UNKNOWN_13 13 - not implemented
    L20:
    // UNKNOWN_14 14 - not implemented
    L21:
    // UNKNOWN_15 15 - not implemented
    L22:
    // UNKNOWN_31 31 - not implemented
    L23:
    // UNKNOWN_32 32 - not implemented
    L24:
    // UNKNOWN_34 34 - not implemented
    L25:
    // UNKNOWN_33 33 - not implemented
    L26:
    // UNKNOWN_35 35 - not implemented
    L27:
    // UNKNOWN_36 36 - not implemented
    L28:
    // UNKNOWN_90 90 - not implemented
    L8:
    // UNKNOWN_90 90 - not implemented
    L5:
    // UNKNOWN_93 93 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_96 96 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_6 6 - not implemented
    L2:
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L30:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L29:
    // UNKNOWN_90 90 - not implemented
    L30:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 110 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L29:
    // UNKNOWN_85 85 - not implemented
    L31:
    // UNKNOWN_90 90 - not implemented
    L33:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 38 - TODO: implement function calls
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_86 86 - not implemented
    L34:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 112 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L34:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(230); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(230); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L35:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 80 - TODO: implement function calls
    // CALL 81 - TODO: implement function calls
    // CALL 82 - TODO: implement function calls
    // CALL 0 - TODO: implement function calls
    bcpl_push(237); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L36:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 121 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 3 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L37:
    // UNKNOWN_90 90 - not implemented
    L38:
    // UNKNOWN_90 90 - not implemented
    L39:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(231); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(232); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 83 - TODO: implement function calls
    bcpl_push(290); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(280); // LOAD_CONSTANT
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_15 15 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_280 280 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L40:
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 109 - TODO: implement function calls
    bcpl_push(270); // LOAD_CONSTANT
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_85 85 - not implemented
    L32:
    // UNKNOWN_90 90 - not implemented
    L31:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_6 6 - not implemented
    L40:
    // UNKNOWN_38 38 - not implemented
    L33:
    // UNKNOWN_2 2 - not implemented
    L35:
    // UNKNOWN_28 28 - not implemented
    L36:
    // UNKNOWN_8 8 - not implemented
    L37:
    // UNKNOWN_9 9 - not implemented
    L38:
    // UNKNOWN_37 37 - not implemented
    L39:
    // UNKNOWN_90 90 - not implemented
    L32:
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L3:
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(206); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_1 1 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_push(260); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_store_global(42, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L41:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 115 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L41:
    // UNKNOWN_85 85 - not implemented
    L42:
    // UNKNOWN_90 90 - not implemented
    L44:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_7 7 - not implemented
    bcpl_push(263); // LOAD_CONSTANT
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L45:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 116 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_90 90 - not implemented
    L45:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L46:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L47:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L48:
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L49:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // CALL 113 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(210); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_90 90 - not implemented
    L49:
    bcpl_push(bcpl_load_global(12)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(291); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_85 85 - not implemented
    L43:
    // UNKNOWN_90 90 - not implemented
    L42:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_70 70 - not implemented
    // UNKNOWN_4 4 - not implemented
    L43:
    // UNKNOWN_77 77 - not implemented
    L44:
    // UNKNOWN_76 76 - not implemented
    L46:
    // UNKNOWN_78 78 - not implemented
    L47:
    // UNKNOWN_1 1 - not implemented
    L48:
    // UNKNOWN_90 90 - not implemented
    L43:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L4:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_235 235 - not implemented
    L1:
    // UNKNOWN_230 230 - not implemented
    L2:
    // UNKNOWN_237 237 - not implemented
    L3:
    // MULTIPLY 49 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_54 54 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_85 85 - not implemented
    L18:
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L1:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 90 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L2:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_89 89 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 2 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_14 14 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_7 7 - not implemented
    // CALL 94 - TODO: implement function calls
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(85); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(294); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(85); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_6 6 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L19:
    // UNKNOWN_90 90 - not implemented
    L20:
    bcpl_push(bcpl_load_global(9)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(11)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(85); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_9 9 - not implemented
    bcpl_push(297); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_7 7 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_90 90 - not implemented
    L19:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_88 88 - not implemented
    L20:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_11 11 - not implemented
    L3:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_65 65 - not implemented
    // UNKNOWN_66 66 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 100 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L4:
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_74 74 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_77 77 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 85 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(292); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L5:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // MULTIPLY 49 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(298); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L6:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // DIVIDE 50 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(298); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L7:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // DIVIDE 50 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(298); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 76 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_5 5 - not implemented
    L8:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // NEGATE 51 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(298); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 76 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    bcpl_push(bcpl_load_global(7)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L9:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L10:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_76 76 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 76 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L11:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_9 9 - not implemented
    L12:
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_85 85 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_83 83 - not implemented
    // UNKNOWN_84 84 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_71 71 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    bcpl_push(85); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(253); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(bcpl_load_global(6)); // LOAD_GLOBAL
    // CALL 32 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_store_global(85, bcpl_pop()); // STORE_GLOBAL
    L21:
    // UNKNOWN_90 90 - not implemented
    L22:
    bcpl_push(bcpl_load_global(8)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(10)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    bcpl_push(85); // LOAD_CONSTANT
    // UNKNOWN_10 10 - not implemented
    // UNKNOWN_8 8 - not implemented
    bcpl_push(297); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_90 90 - not implemented
    L21:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_5 5 - not implemented
    // UNKNOWN_88 88 - not implemented
    L22:
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_7 7 - not implemented
    L13:
    // UNKNOWN_87 87 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_73 73 - not implemented
    // UNKNOWN_84 84 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(254); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_3 3 - not implemented
    L14:
    // UNKNOWN_87 87 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L23:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 45 - TODO: implement function calls
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_17 17 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // UNKNOWN_22 22 - not implemented
    // UNKNOWN_87 87 - not implemented
    L24:
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 1 - TODO: implement function calls
    // UNKNOWN_32 32 - not implemented
    // CALL 5 - TODO: implement function calls
    // UNKNOWN_12 12 - not implemented
    bcpl_store_global(91, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_6 6 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    bcpl_push(254); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_4 4 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_11 11 - not implemented
    // UNKNOWN_15 15 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(3)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L24:
    // UNKNOWN_90 90 - not implemented
    L23:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(254); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_4 4 - not implemented
    L15:
    // UNKNOWN_87 87 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_80 80 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 9 - TODO: implement function calls
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L25:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_12 12 - not implemented
    bcpl_push(254); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_90 90 - not implemented
    L25:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 10 - TODO: implement function calls
    // UNKNOWN_13 13 - not implemented
    // CALL 48 - TODO: implement function calls
    // UNKNOWN_14 14 - not implemented
    bcpl_push(250); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_8 8 - not implemented
    L16:
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_78 78 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_79 79 - not implemented
    // UNKNOWN_68 68 - not implemented
    // UNKNOWN_69 69 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(bcpl_load_global(4)); // LOAD_GLOBAL
    // CALL 10 - TODO: implement function calls
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_2 2 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_251 251 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    // UNKNOWN_94 94 - not implemented
    // UNKNOWN_3 3 - not implemented
    L17:
    // UNKNOWN_87 87 - not implemented
    // STORE_LOCAL 82 - not implemented
    // UNKNOWN_67 67 - not implemented
    // UNKNOWN_95 95 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 1 - TODO: implement function calls
    bcpl_push(251); // LOAD_CONSTANT
    // UNKNOWN_14 14 - not implemented
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_251 251 - not implemented
    bcpl_push(251); // LOAD_CONSTANT
    // CALL 62 - TODO: implement function calls
    // UNKNOWN_23 23 - not implemented
    // UNKNOWN_87 87 - not implemented
    L26:
    // CALL 32 - TODO: implement function calls
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    // UNKNOWN_20 20 - not implemented
    // UNKNOWN_87 87 - not implemented
    L26:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // CALL 10 - TODO: implement function calls
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // CALL 0 - TODO: implement function calls
    // LOAD_LOCAL 81 - not implemented
    // UNKNOWN_251 251 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_90 90 - not implemented
    L26:
    bcpl_push(bcpl_load_global(5)); // LOAD_GLOBAL
    // UNKNOWN_40 40 - not implemented
    // UNKNOWN_2 2 - not implemented
    bcpl_push(14); // LOAD_CONSTANT
    // NEGATE 51 - not implemented
    // UNKNOWN_3 3 - not implemented
    // UNKNOWN_97 97 - not implemented
    // UNKNOWN_103 103 - not implemented
    // UNKNOWN_0 0 - not implemented
    bcpl_push(bcpl_load_global(2)); // LOAD_GLOBAL
    // UNKNOWN_90 90 - not implemented
    L18:
    bcpl_store_global(76, bcpl_pop()); // STORE_GLOBAL
    // UNKNOWN_17 17 - not implemented
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
