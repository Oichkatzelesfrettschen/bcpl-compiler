/**
 * @file cg_modern.h
 * @brief Modern C23 BCPL code generator architecture definitions
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This header defines the modern architecture for the BCPL code generator,
 * replacing the monolithic gencode() function with a clean, modular design
 * that embodies the Lions philosophy of beautiful, readable systems code.
 *
 * "The best programs are written not just for computers to execute,
 *  but for humans to read and understand." - John Lions
 */

#pragma once

// =============================================================================
// CRITICAL CONSTANTS DEFINITIONS (must be before any usage)
// =============================================================================

/**
 * @brief Static data array size (from original SDSZ)
 */
#ifndef SDSZ
#define SDSZ 1000
#endif

#include "oc.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================================================================
// MODERN C23 FEATURE USAGE
// =============================================================================

// Use C23 static_assert for compile-time checks
#ifndef static_assert
#include <assert.h>
#endif

// Use C23 typeof for type safety (if available)
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 202311L
#define TYPEOF(x) typeof(x)
#else
#define TYPEOF(x) __typeof__(x)
#endif
#else
#define TYPEOF(x) int // Fallback for older compilers
#endif

// Modern function attributes
#ifdef __GNUC__
#define PURE_FUNCTION __attribute__((pure))
#define CONST_FUNCTION __attribute__((const))
#define HOT_FUNCTION __attribute__((hot))
#define COLD_FUNCTION __attribute__((cold))
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define PURE_FUNCTION
#define CONST_FUNCTION
#define HOT_FUNCTION
#define COLD_FUNCTION
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

// =============================================================================
// CORE TYPE DEFINITIONS
// =============================================================================

/**
 * @brief Code generation context
 *
 * This structure encapsulates all state needed for code generation,
 * replacing global variables with clean, organized context.
 * Designed to be compatible with legacy BCPL compiler globals.
 */
typedef struct ocode_context {
  // Core legacy globals (direct compatibility with original cg.c)
  int s; ///< Stack pointer (simulated evaluation stack)
  int k; ///< Current parameter/operand value
  void (*output_handler)(
      const char *instruction); ///< Function to emit assembly

  // Load stack state (from original lp, ltype, ldata)
  int load_pointer; ///< Load stack pointer (lp from original)
  int load_type[2]; ///< Load stack types (ltype from original)
  int load_data[2]; ///< Load stack data (ldata from original)

  // Static data management (from original sdata, dt)
  int (*data_table)[2]; ///< Static data table (sdata from original) -
                        ///< dynamically allocated
  int data_pointer;     ///< Data table pointer (dt from original)
  int data_table_size;  ///< Current size of allocated data table

  // Label management (from original labno, loff)
  int next_label_number; ///< Label counter for unique labels (labno from
                         ///< original)
  int label_offset;      ///< Label offset for relative addressing (loff from
                         ///< original)

  // Input state (from original ch)
  int current_char; ///< Last character read from input (ch from original)

  // Error handling and debug information
  struct {
    const char *current_function; ///< Current function context
    int line_number;              ///< Current line being processed
    int error_count;              ///< Number of errors encountered
  } debug;

// Performance tracking (optional)
#ifdef ENABLE_PERFORMANCE_TRACKING
  struct {
    uint64_t operations_processed;  ///< Total operations processed
    uint64_t instructions_emitted;  ///< Total instructions emitted
    uint64_t optimizations_applied; ///< Number of optimizations applied
  } performance;
#endif

  // Stack management (for load operations)
  struct {
    int pointer;          ///< Current stack pointer
    int evaluation_depth; ///< Evaluation stack depth
  } stack;
} ocode_context_t;

/**
 * @brief Operation result codes
 */
typedef enum {
  OCODE_SUCCESS = 0,         ///< Operation completed successfully
  OCODE_END_OF_STREAM,       ///< End of input stream reached
  OCODE_SYNTAX_ERROR,        ///< Syntax error in OCODE
  OCODE_RUNTIME_ERROR,       ///< Runtime error during processing
  OCODE_MEMORY_ERROR,        ///< Memory allocation error
  OCODE_OPTIMIZATION_APPLIED ///< Operation was optimized away
} ocode_result_t;

/**
 * @brief OCODE operation handler function signature
 */
typedef ocode_result_t (*ocode_handler_fn)(ocode_context_t *ctx, ocode_op op);

/**
 * @brief Operation dispatch table entry
 */
typedef struct ocode_dispatch_entry {
  ocode_op operation;       ///< OCODE operation
  ocode_handler_fn handler; ///< Handler function
  const char *name;         ///< Operation name (for debugging)
  int8_t stack_effect;      ///< Stack pointer change (-128 to +127)
  uint8_t flags;            ///< Operation flags (see OCODE_FLAG_*)
} ocode_dispatch_entry_t;

// Operation flags
#define OCODE_FLAG_REQUIRES_REGISTER 0x01 ///< Needs register allocation
#define OCODE_FLAG_CAN_OPTIMIZE 0x02      ///< Can be optimized
#define OCODE_FLAG_TERMINATES_BLOCK 0x04  ///< Ends basic block
#define OCODE_FLAG_SIDE_EFFECTS 0x08      ///< Has observable side effects

// =============================================================================
// GLOBAL FUNCTION DECLARATIONS
// =============================================================================

// Core processing functions
extern ocode_result_t process_ocode_stream(ocode_context_t *ctx) HOT_FUNCTION;
extern void initialize_code_generation_context(ocode_context_t *ctx);
extern void cleanup_code_generation_context(ocode_context_t *ctx);

// Main entry point (replaces gencode())
extern ocode_op gencode_modern(void);

// =============================================================================
// OPERATION HANDLER DECLARATIONS
// =============================================================================

// Load operations (cg_load_ops.c)
extern ocode_result_t handle_load_operations(ocode_context_t *ctx,
                                             ocode_op op) HOT_FUNCTION;

// Store operations (cg_store_ops.c)
extern ocode_result_t handle_store_operations(ocode_context_t *ctx,
                                              ocode_op op);

// Arithmetic operations (cg_arith_ops.c)
extern ocode_result_t handle_arithmetic_operations(ocode_context_t *ctx,
                                                   ocode_op op) HOT_FUNCTION;

// Logical operations (cg_logical_ops.c)
extern ocode_result_t handle_logical_operations(ocode_context_t *ctx,
                                                ocode_op op);

// Comparison operations (cg_compare_ops.c)
extern ocode_result_t handle_comparison_operations(ocode_context_t *ctx,
                                                   ocode_op op);

// Control flow operations (cg_ctrl_flow_ops.c)
extern ocode_result_t handle_control_flow_operations(ocode_context_t *ctx,
                                                     ocode_op op);

// Function operations (cg_func_ops.c)
extern ocode_result_t handle_function_operations(ocode_context_t *ctx,
                                                 ocode_op op);

// Memory operations (cg_memory_ops.c)
extern ocode_result_t handle_memory_operations(ocode_context_t *ctx,
                                               ocode_op op);

// Meta operations (cg_meta_ops.c)
extern ocode_result_t handle_meta_operations(ocode_context_t *ctx,
                                             ocode_op op) COLD_FUNCTION;

// =============================================================================
// UTILITY FUNCTION DECLARATIONS
// =============================================================================

// Operation classification
extern bool is_load_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_store_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_arithmetic_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_logical_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_comparison_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_control_flow_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_function_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_memory_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;
extern bool is_meta_operation(ocode_op op) CONST_FUNCTION PURE_FUNCTION;

// Context management
extern void reset_operation_context(ocode_context_t *ctx);
extern void prepare_operands_for_operation(ocode_context_t *ctx, ocode_op op);
extern void update_stack_pointers(ocode_context_t *ctx,
                                  const ocode_dispatch_entry_t *entry);

// Error handling
extern void report_context_error(ocode_context_t *ctx, const char *format, ...)
    __attribute__((format(printf, 2, 3)));
extern void report_context_warning(ocode_context_t *ctx, const char *format,
                                   ...) __attribute__((format(printf, 2, 3)));

// =============================================================================
// OPTIMIZATION FRAMEWORK DECLARATIONS
// =============================================================================

#ifdef ENABLE_OPTIMIZATIONS
// Peephole optimization
extern bool try_peephole_optimization(ocode_context_t *ctx, ocode_op op);

// Constant folding
extern bool try_constant_folding(ocode_context_t *ctx, ocode_op op);

// Strength reduction
extern bool try_strength_reduction(ocode_context_t *ctx, ocode_op op);

// Dead code elimination
extern bool is_dead_code(ocode_context_t *ctx, ocode_op op);
#endif

// =============================================================================
// DEBUG AND INSTRUMENTATION DECLARATIONS
// =============================================================================

#ifdef DEBUG_CODE_GENERATION
extern void debug_dump_context(const ocode_context_t *ctx);
extern void debug_log_operation(ocode_op op, const char *description);
extern void debug_verify_context_integrity(const ocode_context_t *ctx);
#endif

#ifdef ENABLE_PERFORMANCE_COUNTERS
extern void performance_report_counters(void);
extern void performance_reset_counters(void);
#endif

// =============================================================================
// STATIC ASSERTIONS FOR TYPE SAFETY
// =============================================================================

// Ensure our context structure isn't too large for stack allocation
static_assert(
    sizeof(ocode_context_t) <= 1024,
    "ocode_context_t should be reasonably sized for stack allocation");

// Ensure operation codes fit in our dispatch table
static_assert(S_GLOBAL < 256,
              "OCODE operations should fit in uint8_t for efficiency");

// Ensure stack effects fit in int8_t
static_assert(-128 <= -3 && 3 <= 127,
              "Stack effects should fit in int8_t range");

// =============================================================================
// INLINE UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Check if operation requires register allocation
 * @param op OCODE operation
 * @return true if register allocation is needed
 */
static inline bool requires_register_allocation(ocode_op op) {
  // This would be implemented by looking up the operation in the dispatch table
  // For now, a simple heuristic based on operation type
  return is_arithmetic_operation(op) || is_logical_operation(op) ||
         is_comparison_operation(op) || is_memory_operation(op);
}

/**
 * @brief Get a human-readable name for an operation
 * @param op OCODE operation
 * @return Operation name string
 */
static inline const char *get_operation_name(ocode_op op) {
  // In a full implementation, this would use the dispatch table
  // For now, a simple lookup
  switch (op) {
  case S_LN:
    return "LOAD_NUMBER";
  case S_TRUE:
    return "LOAD_TRUE";
  case S_FALSE:
    return "LOAD_FALSE";
  case S_PLUS:
    return "ADD";
  case S_MINUS:
    return "SUBTRACT";
  case S_MULT:
    return "MULTIPLY";
  case S_DIV:
    return "DIVIDE";
  default:
    return "UNKNOWN";
  }
}

/**
 * @brief Calculate stack depth change for an operation
 * @param op OCODE operation
 * @return Stack depth change (-negative means pop, +positive means push)
 */
static inline int calculate_stack_effect(ocode_op op) {
  // This would normally use the dispatch table
  // For now, simple heuristics
  if (is_load_operation(op))
    return +1;
  if (is_store_operation(op))
    return -1;
  if (is_arithmetic_operation(op) && op != S_NEG && op != S_ABS)
    return -1;
  if (is_comparison_operation(op))
    return -1;
  return 0;
}

// =============================================================================
// LEGACY FUNCTION DECLARATIONS (for compatibility with original cg.c)
// =============================================================================

/**
 * @brief Read a number from the OCODE input stream
 * @return The integer value read
 */
int rdn(void);

/**
 * @brief Read an OCODE operation from input stream
 * @param expected Expected operation (0 for any)
 * @return The operation code read
 */
int rdop(int expected);

/**
 * @brief Emit assembly instruction
 * @param format Printf-style format string
 * @param ... Format arguments
 */
void emit(const char *format, ...);

/**
 * @brief Report error and exit
 * @param format Printf-style format string
 * @param ... Format arguments
 */
void error(const char *format, ...);

/**
 * @brief Load value into register/stack
 * @param type Value type
 * @param data Value data
 */
void load(int type, int data);

/**
 * @brief Force operand evaluation
 * @param stack_level Stack level to force
 */
void force(int stack_level);

/**
 * @brief Load value into specific register
 * @param reg Register number
 * @param condition Load condition
 */
void loadreg(int reg, int condition);

/**
 * @brief Read operation from OCODE stream
 * @param dummy Unused parameter for compatibility
 * @return Operation code
 */
int rdop(int dummy);

/**
 * @brief Current character in OCODE stream
 */
extern int ch;

// =============================================================================
// ARCHITECTURE-SPECIFIC DEFINITIONS
// =============================================================================

// Include architecture-specific definitions
#if BITS == 64
#include "cg_x86_64.h"
#elif BITS == 32
#include "cg_x86_32.h"
#elif BITS == 16
#include "cg_x86_16.h"
#else
#error "Unsupported target architecture"
#endif

// =============================================================================
// LEGACY CONSTANTS (for compatibility with original cg.c)
// =============================================================================

/**
 * @brief Addressing mode constants
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
 * @brief Instruction type constants
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

// =============================================================================
// LEGACY GLOBAL VARIABLES AND STATE
// =============================================================================

// Legacy load stack state (ltype, ldata from original cg.c)
static int ltype[2] = {0, 0}; ///< Load stack types
static int ldata[2] = {0, 0}; ///< Load stack data

// Legacy static data table (sdata, dt from original cg.c)
static int sdata[SDSZ][2]; ///< Static data table
static int dt = 0;         ///< Data table pointer

// Legacy instruction tables and strings (from original cg.c)
static const char *reg[] = {"eax", "ecx"}; ///< Register names
static const char *xistr[] = {             ///< x86 instruction strings
    "mov", "lea", "jmp", "call", "imul", "idiv", "sub",
    "cmp", "add", "neg", "not",  "and",  "or",   "xor"};

// x86 instruction properties table
static const int xitab[] = {0x03, 0x03, 0x01, 0x01, 0x02, 0x02, 0x02,
                            0x02, 0x02, 0x01, 0x01, 0x02, 0x02, 0x02};

// Instruction property flags
#define XCJ 0x01 ///< Conditional jump flag
#define XI1 0x02 ///< One operand flag
#define XNA 0x03 ///< Number of arguments mask

// Forward declarations for legacy functions
extern void emit(const char *format, ...);
extern int rdn(void);
extern void codelab(int label);
extern const char *label(int n);

// Legacy utility functions
static void buf_append(char **s, size_t *rem, const char *format, ...);
static void outdata(int k, int n);
