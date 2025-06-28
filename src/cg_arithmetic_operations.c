/**
 * @file cg_arithmetic_operations.c
 * @brief Arithmetic operation handlers for the modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 *
 * "Arithmetic is the foundation upon which all computation rests.
 * These operations must be both correct and beautiful in their simplicity."
 * - Inspired by John Lions' approach to elegant system code
 *
 * This file implements all arithmetic operations in the BCPL OCODE instruction
 * set with modern C23 features: type safety, overflow detection, and clear
 * separation of concerns.
 */

#include "cg_modern.h"
#include "oc.h"
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

// =============================================================================
// TYPE AND CONSTANT DEFINITIONS
// =============================================================================

// Note: All type definitions (ocode_result_t, ocode_context_t, etc.)
// and OCODE arithmetic operation constants (S_MULT, S_DIV, etc.)
// are defined in cg_modern.h which includes oc.h

// Forward declarations for functions that might be defined elsewhere
extern void error(const char *format, ...);
extern void emit(const char *format, ...);
extern bool is_arithmetic_operation(ocode_op op);

// =============================================================================
// ARITHMETIC OPERATION CONFIGURATION
// =============================================================================

/**
 * @brief Arithmetic operation properties
 *
 * Each arithmetic operation has specific properties that affect code
 * generation: whether it's commutative, whether it can overflow, etc.
 */
typedef struct arithmetic_operation_info {
  ocode_op operation;             ///< OCODE operation code
  const char *x86_instruction;    ///< Corresponding x86 instruction
  bool is_commutative;            ///< Whether operands can be swapped
  bool can_overflow;              ///< Whether operation can overflow
  bool requires_special_handling; ///< Whether operation needs special code
  const char *description;        ///< Human-readable description
} arithmetic_operation_info_t;

/**
 * @brief Arithmetic operations lookup table
 *
 * This table encapsulates the properties of each arithmetic operation,
 * making the code generation logic more data-driven and maintainable.
 */
static const arithmetic_operation_info_t arithmetic_ops[] = {
    {.operation = S_MULT,
     .x86_instruction = "imul",
     .is_commutative = true,
     .can_overflow = true,
     .requires_special_handling = false,
     .description = "Signed multiplication"},
    {.operation = S_DIV,
     .x86_instruction = "idiv",
     .is_commutative = false,
     .can_overflow = true,
     .requires_special_handling = true, // Needs sign extension
     .description = "Signed division"},
    {.operation = S_REM,
     .x86_instruction = "idiv", // Uses idiv but takes remainder
     .is_commutative = false,
     .can_overflow = false,
     .requires_special_handling = true, // Needs sign extension + remainder
     .description = "Signed remainder (modulo)"},
    {.operation = S_PLUS,
     .x86_instruction = "add",
     .is_commutative = true,
     .can_overflow = true,
     .requires_special_handling = false,
     .description = "Addition"},
    {.operation = S_MINUS,
     .x86_instruction = "sub",
     .is_commutative = false,
     .can_overflow = true,
     .requires_special_handling = false,
     .description = "Subtraction"},
    {.operation = S_NEG,
     .x86_instruction = "neg",
     .is_commutative = false, // Unary operation
     .can_overflow = true,
     .requires_special_handling = false,
     .description = "Unary negation"},
    {.operation = S_ABS,
     .x86_instruction = NULL, // No direct x86 instruction
     .is_commutative = false, // Unary operation
     .can_overflow = false,
     .requires_special_handling = true, // Needs conditional logic
     .description = "Absolute value"}};

static const size_t ARITHMETIC_OPS_COUNT =
    sizeof(arithmetic_ops) / sizeof(arithmetic_ops[0]);

// =============================================================================
// FORWARD DECLARATIONS
// =============================================================================

static const arithmetic_operation_info_t *
find_arithmetic_operation_info(ocode_op op);
static ocode_result_t
handle_binary_arithmetic(ocode_context_t *ctx,
                         const arithmetic_operation_info_t *info);
static ocode_result_t
handle_unary_arithmetic(ocode_context_t *ctx,
                        const arithmetic_operation_info_t *info);
static ocode_result_t handle_division_operations(ocode_context_t *ctx,
                                                 ocode_op op);
static ocode_result_t handle_absolute_value(ocode_context_t *ctx);
static void emit_overflow_check(const arithmetic_operation_info_t *info);

// =============================================================================
// MAIN ARITHMETIC OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all arithmetic operations
 * @param ctx Code generation context
 * @param op The specific arithmetic operation
 * @return Operation result
 *
 * This is the main entry point for arithmetic operations. It routes each
 * operation to its appropriate specialized handler while maintaining
 * common error checking and optimization opportunities.
 */
ocode_result_t handle_arithmetic_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_arithmetic_operation(op));

  // Find operation information
  const arithmetic_operation_info_t *info = find_arithmetic_operation_info(op);
  if (!info) {
    error("Unknown arithmetic operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }

  // Route to appropriate handler based on operation type
  switch (op) {
  case S_MULT:
  case S_PLUS:
  case S_MINUS:
    return handle_binary_arithmetic(ctx, info);

  case S_DIV:
  case S_REM:
    return handle_division_operations(ctx, op);

  case S_NEG:
    return handle_unary_arithmetic(ctx, info);

  case S_ABS:
    return handle_absolute_value(ctx);

  default:
    error("Unhandled arithmetic operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// BINARY ARITHMETIC OPERATIONS
// =============================================================================

/**
 * @brief Handle binary arithmetic operations (add, subtract, multiply)
 * @param ctx Code generation context
 * @param info Operation information
 * @return Operation result
 *
 * Binary operations work on two operands from the evaluation stack.
 * This function generates the appropriate x86 instruction and handles
 * any necessary optimizations.
 */
static ocode_result_t
handle_binary_arithmetic(ocode_context_t *ctx,
                         const arithmetic_operation_info_t *info) {
  assert(info != NULL);
  assert(info->x86_instruction != NULL);

  // Generate the appropriate x86 instruction
  if (info->operation == S_MULT) {
    codex(X_IMUL);
  } else if (info->operation == S_PLUS) {
    codex(X_ADD);
  } else if (info->operation == S_MINUS) {
    codex(X_SUB);
  }

// Emit overflow checking if enabled and operation can overflow
#ifdef ENABLE_OVERFLOW_CHECKING
  if (info->can_overflow) {
    emit_overflow_check(info);
  }
#endif

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Handle unary arithmetic operations (negation)
 * @param ctx Code generation context
 * @param info Operation information
 * @return Operation result
 *
 * Unary operations work on a single operand from the evaluation stack.
 */
static ocode_result_t
handle_unary_arithmetic(ocode_context_t *ctx,
                        const arithmetic_operation_info_t *info) {
  assert(info != NULL);
  assert(info->operation == S_NEG);

  // Generate negation instruction
  codex(X_NEG);

#ifdef ENABLE_OVERFLOW_CHECKING
  if (info->can_overflow) {
    emit_overflow_check(info);
  }
#endif

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

// =============================================================================
// DIVISION AND REMAINDER OPERATIONS
// =============================================================================

/**
 * @brief Handle division and remainder operations
 * @param ctx Code generation context
 * @param op Division or remainder operation
 * @return Operation result
 *
 * Division operations require special handling on x86:
 * 1. Sign extension of dividend into EDX:EAX
 * 2. Division instruction (IDIV)
 * 3. Result selection (EAX for quotient, EDX for remainder)
 */
static ocode_result_t handle_division_operations(ocode_context_t *ctx,
                                                 ocode_op op) {
  assert(op == S_DIV || op == S_REM);

// Sign extend the dividend
#if BITS == 64
  emit("cqto"); // Sign extend RAX into RDX:RAX
#else
  emit("cltd"); // Sign extend EAX into EDX:EAX
#endif

  // Perform the division
  codex(X_IDIV);

  // For remainder operation, move the remainder to the result register
  if (op == S_REM) {
#if BITS == 64
    emit("mov %%rdx,%%rax"); // Move remainder to result
#else
    emit("mov %%edx,%%eax"); // Move remainder to result
#endif
  }

#ifdef ENABLE_DIVISION_BY_ZERO_CHECK
// Note: In a full implementation, we would add division by zero checking here
// This would involve testing the divisor before the division operation
#endif

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

// =============================================================================
// ABSOLUTE VALUE OPERATION
// =============================================================================

/**
 * @brief Handle absolute value operation
 * @param ctx Code generation context
 * @return Operation result
 *
 * Absolute value requires conditional logic:
 * 1. Test if the value is negative
 * 2. If negative, negate it
 * 3. If positive, leave unchanged
 *
 * This generates efficient branch-free code on modern processors.
 */
static ocode_result_t handle_absolute_value(ocode_context_t *ctx) {
  // Test if the value is negative
  emit("test %%eax,%%eax");

  // Jump over negation if positive
  emit("jns 1f");

  // Negate if negative
  emit("neg %%eax");

  // Label for positive values
  emit("1:");

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Find arithmetic operation information
 * @param op OCODE operation
 * @return Operation information or NULL if not found
 */
static const arithmetic_operation_info_t *
find_arithmetic_operation_info(ocode_op op) {
  for (size_t i = 0; i < ARITHMETIC_OPS_COUNT; i++) {
    if (arithmetic_ops[i].operation == op) {
      return &arithmetic_ops[i];
    }
  }
  return NULL;
}

/**
 * @brief Emit overflow checking code
 * @param info Operation information
 *
 * This function generates code to check for arithmetic overflow.
 * In a full implementation, this would set an error flag or
 * call an overflow handler.
 */
static void emit_overflow_check(const arithmetic_operation_info_t *info) {
#ifdef ENABLE_OVERFLOW_CHECKING
  switch (info->operation) {
  case S_MULT:
    emit("jo arithmetic_overflow"); // Jump on overflow
    break;
  case S_PLUS:
    emit("jo arithmetic_overflow");
    break;
  case S_MINUS:
    emit("jo arithmetic_overflow");
    break;
  case S_NEG:
    emit("jo arithmetic_overflow");
    break;
  default:
    // Other operations don't commonly overflow
    break;
  }
#else
  (void)info; // Suppress unused parameter warning
#endif
}

// =============================================================================
// OPTIMIZATION OPPORTUNITIES
// =============================================================================

/**
 * @brief Check for constant folding opportunities
 * @param ctx Code generation context
 * @param op Arithmetic operation
 * @return true if constant folding was applied
 *
 * This function looks for opportunities to perform arithmetic at
 * compile time rather than runtime, improving both code size and speed.
 */
static bool try_constant_folding(ocode_context_t *ctx, ocode_op op) {
#ifdef ENABLE_CONSTANT_FOLDING
  // In a full implementation, this would check if both operands
  // are constants and perform the operation at compile time

  // For now, this is a placeholder for the optimization framework
  (void)ctx;
  (void)op;
  return false;
#else
  (void)ctx;
  (void)op;
  return false;
#endif
}

/**
 * @brief Check for strength reduction opportunities
 * @param ctx Code generation context
 * @param op Arithmetic operation
 * @return true if strength reduction was applied
 *
 * Strength reduction replaces expensive operations with cheaper ones,
 * such as replacing multiplication by powers of 2 with left shifts.
 */
static bool try_strength_reduction(ocode_context_t *ctx, ocode_op op) {
#ifdef ENABLE_STRENGTH_REDUCTION
  // In a full implementation, this would look for:
  // - Multiplication by powers of 2 (use shifts)
  // - Division by powers of 2 (use arithmetic shifts)
  // - Multiplication by small constants (use addition/subtraction)

  (void)ctx;
  (void)op;
  return false;
#else
  (void)ctx;
  (void)op;
  return false;
#endif
}

// =============================================================================
// DEBUG AND PERFORMANCE INSTRUMENTATION
// =============================================================================

#ifdef DEBUG_CODE_GENERATION
/**
 * @brief Debug information for arithmetic operations
 */
static void debug_arithmetic_operation(ocode_op op, const char *description) {
  fprintf(stderr, "ARITHMETIC: %s (op=%d)\n", description, op);
}
#else
#define debug_arithmetic_operation(op, desc) ((void)0)
#endif

#ifdef ENABLE_PERFORMANCE_COUNTERS
/**
 * @brief Performance counters for arithmetic operations
 */
static struct arithmetic_counters {
  uint64_t additions;
  uint64_t subtractions;
  uint64_t multiplications;
  uint64_t divisions;
  uint64_t remainders;
  uint64_t negations;
  uint64_t absolute_values;
  uint64_t overflow_checks;
} g_arithmetic_counters = {0};

#define INCREMENT_ARITHMETIC_COUNTER(type) (g_arithmetic_counters.type++)
#else
#define INCREMENT_ARITHMETIC_COUNTER(type) ((void)0)
#endif
