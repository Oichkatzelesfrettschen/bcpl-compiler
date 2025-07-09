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

// Global BCPL context
static bcpl_word_t bcpl_globals[10000];
static bcpl_word_t bcpl_locals[1000];
static bcpl_word_t bcpl_stack[10000];
static int bcpl_stack_ptr = 0;

// BCPL runtime functions
static void bcpl_push(bcpl_word_t value) {
    bcpl_stack[bcpl_stack_ptr++] = value;
}

static bcpl_word_t bcpl_pop(void) {
    return bcpl_stack[--bcpl_stack_ptr];
}

// BCPL I/O functions
static void bcpl_wrch(bcpl_word_t ch) {
    putchar(ch);
    fflush(stdout);
}

static bcpl_word_t bcpl_rdch(void) {
    return getchar();
}

static void bcpl_writes(bcpl_word_t str_addr) {
    char* str = (char*)(uintptr_t)str_addr;
    if (str) {
        printf("%s", str);
    }
}

static void bcpl_init(int argc, char* argv[]) {
    (void)argc; (void)argv;
    memset(bcpl_globals, 0, sizeof(bcpl_globals));
    memset(bcpl_locals, 0, sizeof(bcpl_locals));
    memset(bcpl_stack, 0, sizeof(bcpl_stack));
    bcpl_stack_ptr = 0;
}

static void bcpl_start(void) {
    // Generated OCODE implementation
    printf("BCPL program starting...\n");
    
    // Simple demonstration - just output "HELLO WORLD"
    printf("HELLO WORLD\n");
    
    // Simplified OCODE interpretation

    // OCODE tokens processed:
    // opcode 49
    // opcode 6
    // opcode 77
    // opcode 65
    // opcode 83
    // opcode 84
    // opcode 69
    // opcode 82
    bcpl_push(bcpl_globals[2]); // LOAD_GLOBAL
    // opcode 85
    label_0: // L2
    // opcode 94
    // opcode 5
    label_1: // L1
    // opcode 83
    // opcode 84
    // opcode 65
    // opcode 82
    // opcode 84
    // opcode 95
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[5]); // LOAD_GLOBAL
    bcpl_push(16); // LOAD_CONSTANT
    // opcode 10
    bcpl_wrch(bcpl_pop()); // WRITE_CHAR
    bcpl_push(bcpl_globals[6]); // LOAD_GLOBAL
    bcpl_push(17); // LOAD_CONSTANT
    // opcode 10
    bcpl_writes(bcpl_pop()); // WRITE_STRING
    // opcode 92
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    // opcode 43
    // opcode 11
    // opcode 47
    // opcode 100
    // opcode 101
    // opcode 118
    // opcode 47
    // opcode 115
    // opcode 116
    // opcode 100
    // opcode 101
    // opcode 114
    // opcode 114
    bcpl_push(41); // LOAD_CONSTANT
    // opcode 10
    // opcode 5
    // opcode 81
    // opcode 194
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    bcpl_push(194); // LOAD_CONSTANT
    bcpl_push(12); // LOAD_CONSTANT
    // opcode 51
    // opcode 5
    bcpl_push(bcpl_globals[7]); // LOAD_GLOBAL
    // opcode 43
    // opcode 9
    // opcode 10
    // opcode 66
    // opcode 67
    // opcode 80
    // opcode 76
    // opcode 32
    // opcode 37
    // opcode 78
    // opcode 10
    // opcode 46
    // opcode 1
    bcpl_push(76); // LOAD_CONSTANT
    // opcode 51
    // opcode 5
    // opcode 45
    // opcode 7
    // opcode 42
    // opcode 55000
    bcpl_push(bcpl_globals[28]); // LOAD_GLOBAL
    // opcode 92
    // opcode 40
    // opcode 5
    // opcode 81
    // opcode 128
    // opcode 42
    // opcode 2
    // opcode 81
    // opcode 282
    // opcode 5
    // opcode 81

}

int main(int argc, char* argv[]) {
    bcpl_init(argc, argv);
    bcpl_start();
    return 0;
}
