/**
 * @file cg.c
 * @brief BCPL compiler backend: x86 assembly code generator from OCODE
 * @author Robert Nordier
 * @copyright Copyright (c) 2012 Robert Nordier. All rights reserved.
 *
 * This file implements the primary code generation backend for the BCPL
 * compiler. It translates OCODE (intermediate representation) into x86 assembly
 * language. The generator supports multiple target architectures (16-bit,
 * 32-bit, and 64-bit) and produces GNU assembler-compatible output.
 *
 * ## Architecture Support
 * - **x86-16**: 16-bit Intel 8086 compatible code
 * - **x86-32**: 32-bit Intel 386+ compatible code
 * - **x86-64**: 64-bit AMD64/Intel 64 compatible code
 *
 * ## Code Generation Strategy
 * The generator uses a stack-based approach with load stack tracking to
 * optimize register usage and minimize memory accesses. It implements
 * various optimization techniques including:
 * - Register allocation for frequently used values
 * - Dead code elimination for unused stack entries
 * - Peephole optimizations for common instruction patterns
 *
 * ## OCODE Processing
 * The generator reads OCODE instructions from stdin and produces assembly
 * code to stdout. Each OCODE instruction is processed sequentially with
 * context maintained through the load stack and various state variables.
 */

/* Copyright (c) 2012 Robert Nordier. All rights reserved. */

/* BCPL compiler backend: generate x86 assembler from OCODE. */

#include "oc.h"

// Include 64-bit OCODE bridge for enhanced functionality on 64-bit builds
#if defined(BCPL_USE_64BIT_OCODE) && BCPL_USE_64BIT_OCODE == 1
#include "ocode_bridge.h"
#define OCODE_ENHANCED_64BIT 1
#else
#define OCODE_ENHANCED_64BIT 0
#endif

#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Word size configuration based on target architecture
 *
 * These macros define the word size and shift values for different
 * target architectures. The BITS preprocessor variable determines
 * the target architecture at compile time.
 */
#if BITS == 64
#define WORDSZ 8     /**< 64-bit word size in bytes */
#define WORD_SHIFT 3 /**< Log2 of word size for shifts */
#elif BITS == 32
#define WORDSZ 4     /**< 32-bit word size in bytes */
#define WORD_SHIFT 2 /**< Log2 of word size for shifts */
#elif BITS == 16
#define WORDSZ 2     /**< 16-bit word size in bytes */
#define WORD_SHIFT 1 /**< Log2 of word size for shifts */
#else
#error "Unsupported BITS value"
#endif

/** @brief Size of static data array for constant storage */
#define SDSZ 5000

/**
 * @brief Load stack entry types
 *
 * These constants define the different types of values that can be
 * stored on the load stack during code generation.
 */
#define X_R 0  /**< Register value */
#define X_P 1  /**< Parameter reference */
#define X_G 2  /**< Global variable reference */
#define X_L 3  /**< Local variable reference */
#define X_N 4  /**< Numeric constant */
#define X_LP 5 /**< Parameter pointer */
#define X_LG 6 /**< Global pointer */
#define X_LL 7 /**< Local pointer */

/**
 * @brief x86 instruction opcodes used in instruction template table
 *
 * These constants map to entries in the instruction template table
 * and represent different x86 assembly instructions.
 */
#define X_MOV 0  /**< Move instruction */
#define X_LEA 1  /**< Load effective address */
#define X_JMP 2  /**< Jump instruction */
#define X_CALL 3 /**< Call instruction */
#define X_IMUL 4 /**< Integer multiply */
#define X_IDIV 5 /**< Integer divide */
#define X_SUB 6  /**< Subtract instruction */
#define X_CMP 7  /**< Compare instruction */
#define X_ADD 8  /**< Add instruction */
#define X_NEG 9  /**< Negate instruction */
#define X_NOT 10 /**< Bitwise NOT instruction */
#define X_AND 11 /**< Bitwise AND instruction */
#define X_OR 12  /**< Bitwise OR instruction */
#define X_XOR 13 /**< Bitwise XOR instruction */

/**
 * @brief Special instruction attributes for the instruction table
 *
 * These constants are used as flags in the instruction attribute table
 * to indicate special properties of x86 instructions.
 */
#define XCJ 8 /**< Call/jump instruction flag */
#define XI1 4 /**< EAX register assumed flag */
#define XNA 3 /**< Attribute mask */

/**
 * @brief x86 instruction mnemonic strings
 *
 * This array contains the assembly mnemonics for x86 instructions,
 * indexed by the X_* constants defined above. Different mnemonics
 * are used based on the target architecture (64-bit vs 32-bit).
 */
static const char *const xistr[] = {
#if BITS == 64
    "movl", "leal", "jmp",  "call", "imull", "idivl", "subl",
#else
    "movl", "leal", "jmpl", "calll", "imull", "idivl", "subl",
#endif
    "cmpl", "addl", "negl", "notl", "andl",  "orl",   "xorl"};

/**
 * @brief x86 instruction attribute table
 *
 * This table contains attributes for each x86 instruction, including
 * the number of operands and special flags for register usage and
 * instruction type (call/jump vs regular instructions).
 */
static const int xitab[] = {2, 2, XCJ | 1, XCJ | 1, XI1 | 2, XI1 | 2, 2,
                            2, 2, 1,       1,       2,       2,       2};

/**
 * @brief Machine register names
 *
 * Array of register names used for code generation. The code generator
 * primarily uses EAX and ECX registers for computations.
 */
static const char *const reg[] = {"eax", "ecx"};

/**
 * @brief Relational operator condition codes
 *
 * This 2D array maps BCPL relational operators to x86 condition codes.
 * Each entry contains the condition code and its negation for efficient
 * implementation of both true and false branches.
 */
static const char *relstr[][2] = {
    {"ne", "e"}, /**< Not equal / Equal */
    {"e", "ne"}, /**< Equal / Not equal */
    {"ge", "l"}, /**< Greater or equal / Less */
    {"le", "g"}, /**< Less or equal / Greater */
    {"g", "le"}, /**< Greater / Less or equal */
    {"l", "ge"}  /**< Less / Greater or equal */
};

/**
 * @brief Global state variables for code generation
 *
 * These variables maintain the state of the code generator across
 * OCODE instruction processing.
 */
static int sdata[SDSZ][2]; /**< Static data array for constants */
static int dt;             /**< Data table pointer */
static int sp;             /**< Stack pointer offset */
static int ltype[2];       /**< Load stack: entry types */
static int ldata[2];       /**< Load stack: entry data */
static int lp;             /**< Load stack pointer */
static int labno;          /**< Label counter for unique labels */
static int loff;           /**< Label offset for relative addressing */
static int ch;             /**< Last character read from input */

/* Additional state used by the refactored gencode() */
static bool ro_flag;   /**< Deferred relational jump flag */
static int rcode_flag; /**< Deferred relational operation code */
static int sn_value;   /**< Temporary stack slot value */

/**
 * @brief Function prototypes for code generation
 *
 * These functions implement the core code generation functionality,
 * from OCODE processing to x86 assembly output.
 */

/**
 * @brief Main code generation function
 * @return The current OCODE operation being processed
 *
 * Processes OCODE instructions and generates corresponding x86 assembly.
 * This is the main entry point for the code generation phase.
 */
static ocode_op gencode(void);

/* Dispatch table and handler declarations */
typedef void (*op_handler_t)(ocode_op);
static void handle_load(ocode_op op);
static void handle_store(ocode_op op);
static void handle_arithmetic(ocode_op op);
static void handle_comparison(ocode_op op);
static void handle_memory(ocode_op op);
static void handle_control_flow(ocode_op op);
static void handle_function(ocode_op op);
static void handle_meta(ocode_op op);

static op_handler_t dispatch_table[OPMAX + 1] = {
    [S_LN] = handle_load,
    [S_TRUE] = handle_load,
    [S_FALSE] = handle_load,
    [S_LP] = handle_load,
    [S_LG] = handle_load,
    [S_LL] = handle_load,
    [S_LLP] = handle_load,
    [S_LLG] = handle_load,
    [S_LLL] = handle_load,
    [S_QUERY] = handle_load,
    [S_LSTR] = handle_load,

    [S_SP] = handle_store,
    [S_SG] = handle_store,
    [S_SL] = handle_store,

    [S_MULT] = handle_arithmetic,
    [S_DIV] = handle_arithmetic,
    [S_REM] = handle_arithmetic,
    [S_PLUS] = handle_arithmetic,
    [S_MINUS] = handle_arithmetic,
    [S_NEG] = handle_arithmetic,
    [S_NOT] = handle_arithmetic,
    [S_ABS] = handle_arithmetic,
    [S_LSHIFT] = handle_arithmetic,
    [S_RSHIFT] = handle_arithmetic,
    [S_LOGAND] = handle_arithmetic,
    [S_LOGOR] = handle_arithmetic,
    [S_EQV] = handle_arithmetic,
    [S_NEQV] = handle_arithmetic,

    [S_EQ] = handle_comparison,
    [S_NE] = handle_comparison,
    [S_LS] = handle_comparison,
    [S_GR] = handle_comparison,
    [S_LE] = handle_comparison,
    [S_GE] = handle_comparison,

    [S_RV] = handle_memory,
    [S_GETBYTE] = handle_memory,
    [S_PUTBYTE] = handle_memory,
    [S_STIND] = handle_memory,

    [S_GOTO] = handle_control_flow,
    [S_JT] = handle_control_flow,
    [S_JF] = handle_control_flow,
    [S_JUMP] = handle_control_flow,
    [S_SWITCHON] = handle_control_flow,
    [S_RES] = handle_control_flow,
    [S_RSTACK] = handle_control_flow,
    [S_ENDFOR] = handle_control_flow,

    [S_FNAP] = handle_function,
    [S_RTAP] = handle_function,
    [S_FNRN] = handle_function,
    [S_RTRN] = handle_function,
    [S_ENTRY] = handle_function,
    [S_ENDPROC] = handle_function,

    [S_BLAB] = handle_meta,
    [S_LAB] = handle_meta,
    [S_DATALAB] = handle_meta,
    [S_ITEML] = handle_meta,
    [S_ITEMN] = handle_meta,
    [S_NEEDS] = handle_meta,
    [S_SECTION] = handle_meta,
    [S_GLOBAL] = handle_meta,
    [S_SAVE] = handle_meta,
    [S_STACK] = handle_meta,
    [S_STORE] = handle_meta,
    [S_FINISH] = handle_meta,
};

/**
 * @brief Load a value onto the load stack
 * @param type The type of value being loaded (X_R, X_P, X_G, etc.)
 * @param data The data associated with the value
 *
 * Pushes a value onto the load stack for later code generation.
 * The load stack tracks values that will be used in subsequent operations.
 */
static void load(int type, int data);

/**
 * @brief Save the top of load stack to a location
 * @param type The destination type (X_P, X_G, X_L, etc.)
 * @param data The destination data (offset, global number, etc.)
 *
 * Generates code to store the top load stack entry to the specified location.
 */
static void save(int type, int data);

/**
 * @brief Force a load stack entry into a register
 * @param entry The load stack entry index to force
 *
 * Generates code to ensure the specified load stack entry is in a register,
 * loading it if necessary.
 */
static void force(int entry);

/**
 * @brief Load a value into a specific register
 * @param reg_idx The register index to load into
 * @param src_idx The load stack entry to load from
 *
 * Generates code to load a load stack entry into the specified register.
 */
static void loadreg(int reg_idx, int src_idx);

/**
 * @brief Generate a generic x86 instruction
 * @param opcode The x86 instruction opcode (X_MOV, X_ADD, etc.)
 *
 * Generates an x86 instruction using the values on the load stack.
 */
static void codex(int opcode);

/**
 * @brief Generate an x86 instruction with operands
 * @param opcode The x86 instruction opcode
 * @param ... Variable arguments for instruction operands
 *
 * Generates an x86 instruction with the specified operands.
 */
static void code(int opcode, ...);

/**
 * @brief Define static data entry
 * @param op The OCODE operation type (S_ITEML, S_ITEMN)
 * @param data The data value to store
 *
 * Adds an entry to the static data table for later output.
 */
static void defdata(int op, int data);

/**
 * @brief Output static data
 * @param op The OCODE operation type
 * @param data The data value
 *
 * Immediately outputs a data definition to the assembly output.
 */
static void outdata(int op, int data);

/**
 * @brief Generate a code label
 * @param lab The label number
 *
 * Outputs a label definition to the assembly output.
 */
static void codelab(int lab);

/**
 * @brief Emit assembly code with printf-style formatting
 * @param fmt The format string
 * @param ... Arguments for the format string
 *
 * Outputs formatted assembly code with proper indentation.
 */
static void emit(const char *fmt, ...);

/**
 * @brief Generate a unique label string
 * @param lab The label number
 * @return A formatted label string
 *
 * Creates a unique label string for use in assembly output.
 */
static char *label(int lab);

/**
 * @brief Read an OCODE operation with validation
 * @param expected The expected operation code (-1 for any)
 * @return The operation code read
 *
 * Reads and validates an OCODE operation from the input stream.
 */
static int rdop(int expected);

/**
 * @brief Read a numeric value from input
 * @return The numeric value read
 *
 * Reads a decimal number from the OCODE input stream.
 */
static int rdn(void);

/**
 * @brief Report a fatal error and exit
 * @param fmt The error message format string
 * @param ... Arguments for the format string
 *
 * Reports a fatal error to stderr and terminates the program.
 */
[[noreturn]] static void error(const char *fmt, ...);

/**
 * @brief Helper function to append formatted data to a buffer
 * @param sp Pointer to current position in buffer
 * @param rem Pointer to remaining space in buffer
 * @param fmt Format string for data to append
 * @param ... Arguments for the format string
 *
 * Safely appends formatted data to a buffer while tracking remaining space.
 * Aborts with an error if the buffer would overflow.
 */
static void buf_append(char **sp, size_t *rem, const char *fmt, ...) {
  int n;
  va_list ap;

  if (*rem == 0) {
    error("instruction too long");
  }
  va_start(ap, fmt);
  n = vsnprintf(*sp, *rem, fmt, ap);
  va_end(ap);
  if (n < 0 || (size_t)n >= *rem) {
    error("instruction too long");
  }
  *sp += n;
  *rem -= n;
}

int main(void) {
  ocode_op op;

#if OCODE_ENHANCED_64BIT
  // Initialize 64-bit OCODE context for enhanced features
  ocode_context_t ocode_ctx;
  if (ocode_init_context(&ocode_ctx, 1024)) {
    printf("# Using %s OCODE implementation version %s\n",
           ocode_get_implementation_name(), ocode_get_version());
    printf("# Native word size: %zu bytes\n", ocode_get_word_size());
    if (ocode_has_64bit_features()) {
      printf("# Enhanced 64-bit features available\n");
    }
  }
#endif

  do {
    labno = 1000;
    op = gencode();
    loff += 1000;
  } while (op != S_END);

#if OCODE_ENHANCED_64BIT
  // Cleanup 64-bit OCODE context
  ocode_cleanup_context(&ocode_ctx);
#endif

  return 0;
}

static ocode_op gencode(void) {
  int s1, s2, s3;
  ocode_op op;

  dt = sp = lp = 0;
  rcode_flag = 0;
  ro_flag = false;
  emit(".text");
  for (;;) {
    op = rdop(0);
    if (ch == EOF) {
      return S_END;
    }
    if ((int)op < 0 || op > (ocode_op)OPMAX) {

      error("Bad op %d", op);
    }
    s1 = optab1(op);
    s2 = optab2(op);
    s3 = optab3(op);
    if (s3 <= 7) {
      force(s1);
      if (s3) {
        loadreg(0, s3 == 1 ? 0 : s3 == 2 ? ltype[0] != X_N : 1);
      }
      if (s3 >= 4) {
        loadreg(1, s3 == 4 ? 0 : s3 == 5 ? ltype[1] == X_N : 1);
      }
    }

    op_handler_t handler = dispatch_table[op];
    if (!handler) {
      error("Unknown op %d", op);
    }
    handler(op);

    /* adjust stack pointer */
    sp = s2 & 2 ? sn_value : sp - s1;
    if (s2 & 1)
      sp++;
    /* adjust load stack pointer */
    if (s3 <= 7) {
      lp = s2 & 1;
    } else if (s3 == 8 && lp < 2) {
      lp++;
    }

    if (op == S_GLOBAL) {
      return op;
    }
  }
  return op;
}

/* ------------------------------------------------------------------------- */
/* Operation handlers                                                        */
/* ------------------------------------------------------------------------- */

static void handle_load(ocode_op op) {
  switch (op) {
    case S_LN:
      load(X_N, rdn());
      break;
    case S_TRUE:
      load(X_N, -1);
      break;
    case S_FALSE:
      load(X_N, 0);
      break;
    case S_LP:
      load(X_P, rdn());
      break;
    case S_LG:
      load(X_G, rdn());
      break;
    case S_LL:
      load(X_L, rdn());
      break;
    case S_LLP:
      load(X_LP, rdn());
      break;
    case S_LLG:
      load(X_LG, rdn());
      break;
    case S_LLL:
      load(X_LL, rdn());
      break;
    case S_QUERY:
      load(X_R, lp != 0);
      break;
    case S_LSTR: {
      int n, l, i;
      n = rdn();
      l = --labno;
      defdata(S_DATALAB, l);
      defdata(S_LSTR, n);
      for (i = 1; i <= n; i++) {
        defdata(S_LSTR, rdn());
      }
      load(X_LL, l);
    } break;
    default:
      error("bad load op %d", op);
  }
}

static void handle_store(ocode_op op) {
  switch (op) {
    case S_SP:
      save(X_P, rdn());
      break;
    case S_SG:
      save(X_G, rdn());
      break;
    case S_SL:
      save(X_L, rdn());
      break;
    default:
      error("bad store op %d", op);
  }
}

static void handle_arithmetic(ocode_op op) {
  switch (op) {
    case S_ABS:
      emit("test %%eax,%%eax");
      emit("jns 1f");
      emit("neg %%eax");
      emit("1:");
      break;
    case S_NEG:
    case S_NOT:
      codex(op == S_NEG ? X_NEG : X_NOT);
      break;
    case S_MULT:
    case S_DIV:
    case S_REM:
      if (op == S_DIV || op == S_REM) {
#if BITS == 64
        emit("cqto");
#else
        emit("cltd");
#endif
      }
      codex(op == S_MULT ? X_IMUL : X_IDIV);
      if (op == S_REM) {
        emit("mov %%edx,%%eax");
      }
      break;
    case S_PLUS:
    case S_MINUS:
      codex(op == S_MINUS ? X_SUB : X_ADD);
      break;
    case S_LSHIFT:
    case S_RSHIFT:
      emit("sh%cl %%cl,%%eax", op == S_RSHIFT ? 'r' : 'l');
      break;
    case S_LOGAND:
    case S_LOGOR:
      codex(op == S_LOGOR ? X_OR : X_AND);
      break;
    case S_EQV:
    case S_NEQV:
      if (op == S_EQV) {
        emit("xorl $-1,%%eax");
      }
      codex(X_XOR);
      break;
    default:
      error("bad arithmetic op %d", op);
  }
}

static void handle_comparison(ocode_op op) {
  int o2;
  codex(X_CMP);
  o2 = rdop(1);
  if (o2 == S_JT || o2 == S_JF) {
    ro_flag = true;
    rcode_flag = op;
  } else {
    emit("set%s %%al", relstr[op - S_EQ][1]);
    emit("movzx %%al,%%eax");
    emit("neg %%eax");
  }
}

static void handle_memory(ocode_op op) {
  switch (op) {
    case S_RV:
#if BITS == 64
      emit("mov (,%%rax,%d),%%eax", WORDSZ);
#else
      emit("mov (,%%eax,%d),%%eax", WORDSZ);
#endif
      break;
    case S_GETBYTE:
    case S_PUTBYTE:
      emit("shl $%d,%%eax", WORD_SHIFT);
      codex(X_ADD);
      if (op == S_GETBYTE) {
#if BITS == 64
        emit("movzb (%%rax),%%eax");
#else
        emit("movzb (%%eax),%%eax");
#endif
      } else {
        code(X_MOV, X_R, 1, X_P, sp - 3);
#if BITS == 64
        emit("mov %%cl,(%%rax)");
#else
        emit("mov %%cl,(%%eax)");
#endif
        sp--;
      }
      break;
    case S_STIND:
#if BITS == 64
      emit("mov %%eax,(,%%rcx,%d)", WORDSZ);
#else
      emit("mov %%eax,(,%%ecx,%d)", WORDSZ);
#endif
      break;
    default:
      error("bad memory op %d", op);
  }
}

static void handle_control_flow(ocode_op op) {
  switch (op) {
    case S_GOTO:
      codex(X_JMP);
      break;
    case S_JT:
    case S_JF:
      if (ro_flag) {
        emit("j%s %s", relstr[rcode_flag - S_EQ][op == S_JT], label(rdn()));
        ro_flag = false;
      } else {
        emit("orl %%eax,%%eax");
        emit("j%s %s", op == S_JF ? "z" : "nz", label(rdn()));
      }
      break;
    case S_JUMP:
      emit("jmp %s", label(rdn()));
      break;
    case S_SWITCHON: {
      int n, d, l, i;
      n = rdn();
      d = rdn();
      l = --labno;
      defdata(S_DATALAB, l);
      for (i = 0; i < n; i++) {
        defdata(S_ITEMN, rdn());
        defdata(S_ITEML, rdn());
      }
#if BITS == 64
      emit("mov $%s,%%rdx", label(l));
      emit("mov $%d,%%rcx", n);
#else
      emit("mov $%s,%%edx", label(l));
      emit("mov $%d,%%ecx", n);
#endif
      emit("jecxz 2f");
#if BITS == 64
      emit("1:cmp (%%rdx),%%eax");
#else
      emit("1:cmp (%%edx),%%eax");
#endif
      emit("je 3f");
#if BITS == 64
      emit("add $8,%%rdx");
#else
      emit("add $8,%%edx");
#endif
      emit("loop 1b");
      emit("2:jmp %s", label(d));
#if BITS == 64
      emit("3:jmp *%d(%%rdx)", WORDSZ);
#else
      emit("3:jmp *%d(%%edx)", WORDSZ);
#endif
    } break;
    case S_RES:
      emit("jmp %s", label(rdn()));
      break;
    case S_RSTACK:
      sn_value = rdn();
      ltype[0] = X_R;
      ldata[0] = 0;
      break;
    case S_ENDFOR:
      codex(X_CMP);
      emit("jle %s", label(rdn()));
      break;
    default:
      error("bad control op %d", op);
  }
}

static void handle_function(ocode_op op) {
  switch (op) {
    case S_FNAP:
    case S_RTAP:
      sn_value = rdn();
      code(X_LEA, X_R, 1, X_P, sn_value);
      codex(X_CALL);
      if (op == S_FNAP) {
        ltype[0] = X_R;
        ldata[0] = 0;
      }
      break;
    case S_FNRN:
    case S_RTRN:
#if BITS == 64
      emit("mov %%rbp,%%rcx");
      emit("mov %d(%%rcx),%%eax", WORDSZ);
      emit("mov %%eax,%%ebp");
      emit("mov (%%rcx),%%eax");
      emit("jmp *%%rax");
#else
      emit("mov %%ebp,%%ecx");
      emit("mov %d(%%ecx),%%ebp", WORDSZ);
      emit("jmp *(%%ecx)");
#endif
      break;
    case S_ENTRY: {
      int n, l, i;
      n = rdn();
      l = rdn();
      printf("//\t");
      for (i = 0; i < n; i++) {
        putchar(rdn());
      }
      putchar('\n');
      codelab(l);
#if BITS == 64
      emit("pop (%%rcx)");
      emit("mov %%rbp,%d(%%rcx)", WORDSZ);
      emit("mov %%rcx,%%rbp");
#else
      emit("pop (%%ecx)");
      emit("mov %%ebp,%d(%%ecx)", WORDSZ);
      emit("mov %%ecx,%%ebp");
#endif
    } break;
    case S_ENDPROC:
      rdn();
      break;
    default:
      error("bad function op %d", op);
  }
}

static void handle_meta(ocode_op op) {
  switch (op) {
    case S_BLAB:
    case S_LAB:
      codelab(rdn());
      break;
    case S_DATALAB:
    case S_ITEML:
    case S_ITEMN:
      defdata(op, rdn());
      break;
    case S_NEEDS:
    case S_SECTION: {
      int n, i;
      n = rdn();
      printf("//\t%s: ", op == S_NEEDS ? "NEEDS" : "SECTION");
      for (i = 0; i < n; i++) {
        putchar(rdn());
      }
      putchar('\n');
    } break;
    case S_GLOBAL: {
      int n, x, i;
      emit("ret");
      emit(".data");
      for (i = 0; i < dt; i++) {
        outdata(sdata[i][0], sdata[i][1]);
      }
      n = rdn();
      for (i = 0; i < n; i++) {
        x = rdn();
        emit(".global G%d", x);
        emit(".equ G%d,%s", x, label(rdn()));
      }
    } break;
    case S_SAVE:
    case S_STACK:
      sn_value = rdn();
      break;
    case S_STORE:
      break;
    case S_FINISH:
      emit("jmp finish");
      break;
    default:
      error("bad meta op %d", op);
  }
}

static void load(int t, int d) {
  assert(lp >= 0 && lp <= 2);
  if (lp == 2) {
    force(1);
  }
  ltype[lp] = t;
  ldata[lp] = d;
}

static void save(int k, int v) { code(X_MOV, k, v, ltype[0], ldata[0]); }

static void force(int st) {
  assert(lp >= 0 && lp <= 2);
  assert(st >= 0 && st <= 2);
  if (lp == st) {
    return;
  }
  if (lp == 0) {
    ltype[0] = X_R;
    ldata[0] = 0;
    code(X_MOV, ltype[0], ldata[0], X_P, sp - 1);
    lp = 1;
    if (lp == st) {
      return;
    }
  }
  assert(lp != 0);
  if (st == 2) {
    assert(ltype[0] == X_R && ldata[0] == 0);
    emit("mov %%eax,%%ecx");
    code(X_MOV, ltype[0], ldata[0], X_P, sp - 2);
    ltype[1] = X_R;
    ldata[1] = 1;
    lp = 2;
  } else {
    do {
      loadreg(0, ltype[0] != X_N);
      code(X_MOV, X_P, sp - lp, ltype[0], ldata[0]);
      if (lp == 2) {
        ltype[0] = ltype[1];
        ldata[0] = ltype[1] == X_R ? 0 : ldata[1];
      }
    } while (--lp != st);
  }
}

static void loadreg(int i, int must) {
  int t, p;

  t = ltype[i];
  if (t == X_R) {
    return;
  }
  p = t == X_LP || t == X_LG || t == X_LL;
  if (p || must) {
    code(p && t != X_LL ? X_LEA : X_MOV, X_R, i, t, ldata[i]);
    if (p) {
      emit("shr $%d,%%%s", WORD_SHIFT, reg[i]);
    }
    ltype[i] = X_R;
    ldata[i] = i;
  }
}

static void codex(int xi) { code(xi, ltype[0], ldata[0], ltype[1], ldata[1]); }

static void code(int xi, ...) {
  /*
   * A 64-byte buffer easily accommodates the longest formatted
   * instruction which is well under 32 characters.
   */
  char buf[64], *s;
  size_t rem = sizeof(buf);
  int typ[2], dat[2];
  va_list ap;
  int cj, i1, na, x, i, t, d;

  va_start(ap, xi);
  x = xitab[xi];
  cj = x & XCJ;
  i1 = x & XI1 ? 1 : 0;
  na = x & XNA;
  for (i = 0; i < na; i++) {
    typ[i] = va_arg(ap, int);
    dat[i] = va_arg(ap, int);
  }
  s = buf;
  buf_append(&s, &rem, "%s", xistr[xi]);
  for (i = na - 1; i >= i1; i--) {
    if (rem <= 1) {
      error("instruction too long");
    }
    *s++ = i == na - 1 ? ' ' : ',';
    rem--;
    t = typ[i];
    d = dat[i];
    if (t <= 3) {
      if (cj) {
        if (rem <= 1) {
          error("instruction too long");
        }
        *s++ = '*';
        rem--;
      }
    } else if (t != X_LP && t != X_LG && !cj) {
      if (rem <= 1) {
        error("instruction too long");
      }
      *s++ = '$';
      rem--;
    }
    switch (t) {
    case X_R:
      buf_append(&s, &rem, "%%%s", reg[d]);
      break;
    case X_P:
    case X_LP:
#if BITS == 64
      buf_append(&s, &rem, "%d(%%rbp)", d * WORDSZ);
#else
      buf_append(&s, &rem, "%d(%%ebp)", d * WORDSZ);
#endif
      break;
    case X_G:
    case X_LG:
      // Accessing global variable or pointer to global.
      // It is a critical convention of this BCPL compiler's runtime environment
      // that the %rdi (for 64-bit targets) or %edi (for 32-bit targets) register
      // holds the base address of the BCPL Global Vector (G).
      // This register must be set up correctly by the program's startup code
      // (e.g., in rt.s or platform-specific startup) and its value preserved
      // across function calls that might use globals. Incorrect setup will lead
      // to misaddressing global variables.
#if BITS == 64
      buf_append(&s, &rem, "%d(%%rdi)", d * WORDSZ); // d is the global slot number, WORDSZ is 8
#else
      buf_append(&s, &rem, "%d(%%edi)", d * WORDSZ); // d is the global slot number, WORDSZ is 4 or 2
#endif
      break;
    case X_L:
    case X_LL:
      buf_append(&s, &rem, "%s", label(d));
      break;
    case X_N:
      buf_append(&s, &rem, "%d", d);
      break;
    }
  }
  va_end(ap);
  emit("%s", buf);
}

static void defdata(int k, int v) {
  if (dt >= SDSZ) {
    error("Too many constants");
  }
  sdata[dt][0] = k;
  sdata[dt][1] = v;
  dt++;
}

static void outdata(int k, int n) {
  switch (k) {
  case S_DATALAB:
    // Align data labels to the word size of the target architecture.
    // WORD_SHIFT is log2(WORDSZ), e.g., 3 for 64-bit (8 bytes), 2 for 32-bit (4 bytes).
    // .p2align N aligns to 2^N bytes.
    emit(".p2align %d", WORD_SHIFT);
    codelab(n);
    return;
  case S_ITEMN:
    emit(".long %d", n);
    return;
  case S_ITEML:
    emit(".long %s", label(n));
    return;
  case S_LSTR:
    emit(".byte %d", n);
    return;
  }
}

static void codelab(int n) {
  char buf[32];

  if (snprintf(buf, sizeof(buf), "%s:", label(n)) >= (int)sizeof(buf)) {
    error("label buffer overflow");
  }
  emit(buf);
}

static void emit(const char *fmt, ...) {
  va_list ap;

  while (isupper(*fmt) || isdigit(*fmt) || *fmt == ':') {
    putchar(*fmt++);
  }
  if (*fmt) {
    putchar('\t');
    va_start(ap, fmt);
    vprintf(fmt, ap);
  }
  putchar('\n');
  va_end(ap);
}

static char *label(int n) {
  static char buf[32];

  if (snprintf(buf, sizeof(buf), "L%d", loff + n) >= (int)sizeof(buf)) {
    error("label buffer overflow");
  }
  return buf;
}

static int rdop(int peek) {
  static int got, op;

  if (!got) {
    op = rdn();
  }
  got = peek;
  return op;
}

static int rdn(void) {
  bool neg;
  int n;

  neg = false;
  n = 0;
  do {
    ch = getchar();
  } while (ch == ' ' || ch == '\n');
  if (ch == 'L') {
    ch = getchar();
  } else if (ch == '-') {
    neg = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return neg ? -n : n;
}

[[noreturn]] static void error(const char *msg, ...) {
  va_list ap;

  va_start(ap, msg);
  vfprintf(stderr, msg, ap);
  fputc('\n', stderr);
  va_end(ap);
  exit(1);
}
