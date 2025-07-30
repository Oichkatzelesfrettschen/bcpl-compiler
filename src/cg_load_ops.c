/**
 * @file cg_load_ops.c
 * @brief Load operation handlers for the modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 *
 * This file contains the handlers for all load operations in the BCPL
 * OCODE instruction set. Each handler is crafted with the Lions philosophy:
 * "Every function should read like a well-written paragraph, with each
 * line contributing meaningfully to the whole story."
 *
 * Load operations bring values onto the evaluation stack from various
 * sources: constants, variables, parameters, and computed addresses.
 */

#include "cg_modern.h"
#include "oc.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

// =============================================================================
// LOAD OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle all load operations
 * @param ctx Code generation context
 * @param op The specific load operation
 * @return Operation result
 *
 * This function dispatches to specific load handlers based on the operation
 * type. The beauty of this design is that each load type gets its own
 * specialized, focused implementation.
 */
ocode_result_t handle_load_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);

  switch (op) {
  case S_LN:
    return load_number(ctx);
  case S_TRUE:
    return load_boolean_true(ctx);
  case S_FALSE:
    return load_boolean_false(ctx);
  case S_LP:
    return load_parameter(ctx);
  case S_LG:
    return load_global(ctx);
  case S_LL:
    return load_local(ctx);
  case S_LLP:
    return load_parameter_pointer(ctx);
  case S_LLG:
    return load_global_pointer(ctx);
  case S_LLL:
    return load_local_pointer(ctx);
  case S_LSTR:
    return load_string_literal(ctx);
  case S_QUERY:
    return load_query_result(ctx);
  default:
    error("Unknown load operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// INDIVIDUAL LOAD OPERATION IMPLEMENTATIONS
// =============================================================================

/**
 * @brief Load a numeric constant onto the stack
 * @param ctx Code generation context
 * @return Operation result
 *
 * Reads a numeric value from the OCODE stream and places it on the
 * evaluation stack. This is the simplest and most fundamental operation.
 */
ocode_result_t load_number(ocode_context_t *ctx) {
  int value = rdn();
  load(X_N, value);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load boolean true value (-1 in BCPL convention)
 * @param ctx Code generation context
 * @return Operation result
 *
 * BCPL uses -1 for true (all bits set) following the PDP-11 tradition
 * where boolean operations were bitwise operations.
 */
ocode_result_t load_boolean_true(ocode_context_t *ctx) {
  load(X_N, -1); // BCPL true is -1 (all bits set)

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load boolean false value (0)
 * @param ctx Code generation context
 * @return Operation result
 *
 * False is represented as 0, the natural complement to true's -1.
 */
ocode_result_t load_boolean_false(ocode_context_t *ctx) {
  load(X_N, 0); // BCPL false is 0

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load a parameter value
 * @param ctx Code generation context
 * @return Operation result
 *
 * Parameters are stored relative to the frame pointer at positive offsets.
 * This loads the value of the parameter (not its address).
 */
ocode_result_t load_parameter(ocode_context_t *ctx) {
  int param_offset = rdn();
  load(X_P, param_offset);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load a global variable value
 * @param ctx Code generation context
 * @return Operation result
 *
 * Global variables are accessed through the global vector, which provides
 * a level of indirection for dynamic linking and module systems.
 */
ocode_result_t load_global(ocode_context_t *ctx) {
  int global_number = rdn();
  load(X_G, global_number);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load a local variable value
 * @param ctx Code generation context
 * @return Operation result
 *
 * Local variables are stored relative to the frame pointer at negative
 * offsets, growing downward from the frame base.
 */
ocode_result_t load_local(ocode_context_t *ctx) {
  int local_offset = rdn();
  load(X_L, local_offset);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load address of a parameter
 * @param ctx Code generation context
 * @return Operation result
 *
 * This loads the address of a parameter, not its value. Used for
 * pass-by-reference semantics and taking addresses of parameters.
 */
ocode_result_t load_parameter_pointer(ocode_context_t *ctx) {
  int param_offset = rdn();
  load(X_LP, param_offset);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load address of a global variable
 * @param ctx Code generation context
 * @return Operation result
 *
 * Loads the address of a global variable from the global vector.
 * This is used for taking addresses and pass-by-reference operations.
 */
ocode_result_t load_global_pointer(ocode_context_t *ctx) {
  int global_number = rdn();
  load(X_LG, global_number);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load address of a local variable
 * @param ctx Code generation context
 * @return Operation result
 *
 * Loads the address of a local variable. Combined with indirection
 * operations, this enables pointer operations on local variables.
 */
ocode_result_t load_local_pointer(ocode_context_t *ctx) {
  int local_offset = rdn();
  load(X_LL, local_offset);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load a string literal
 * @param ctx Code generation context
 * @return Operation result
 *
 * String literals are stored in the data section with a length prefix
 * (BCPL packed string format). This creates a data label and loads
 * its address onto the stack.
 */
ocode_result_t load_string_literal(ocode_context_t *ctx) {
  int string_length = rdn();
  int label_number = --ctx->next_label_number;

  // Define the string data in the data section
  defdata(S_DATALAB, label_number);
  defdata(S_LSTR, string_length);

  // Read and store each character of the string
  for (int i = 1; i <= string_length; i++) {
    int character = rdn();
    defdata(S_LSTR, character);
  }

  // Load the address of the string
  load(X_LL, label_number);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

/**
 * @brief Load query result (stack pointer state)
 * @param ctx Code generation context
 * @return Operation result
 *
 * The QUERY operation loads a boolean indicating whether there are
 * values on the load stack. This is used in complex expressions
 * for conditional evaluation.
 */
ocode_result_t load_query_result(ocode_context_t *ctx) {
  bool has_stack_values = (ctx->stack.pointer != 0);
  load(X_R, has_stack_values ? -1 : 0);

  ctx->debug.line_number++;
  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS FOR LOAD OPERATIONS
// =============================================================================

/**
 * @brief Validate parameter offset
 * @param offset Parameter offset to validate
 * @return true if offset is valid
 *
 * Parameters should have positive offsets from the frame pointer.
 * This helps catch common addressing errors at code generation time.
 */
static inline bool is_valid_parameter_offset(int offset) {
  return offset >= 0 && offset < 1000; // Reasonable upper bound
}

/**
 * @brief Validate local variable offset
 * @param offset Local variable offset to validate
 * @return true if offset is valid
 *
 * Local variables should have negative offsets from the frame pointer.
 */
static inline bool is_valid_local_offset(int offset) {
  return offset <= 0 && offset > -1000; // Reasonable lower bound
}

/**
 * @brief Validate global variable number
 * @param global_num Global variable number to validate
 * @return true if global number is valid
 *
 * Global variable numbers should be within the global vector bounds.
 */
static inline bool is_valid_global_number(int global_num) {
  return global_num >= 0 && global_num < 10000; // Generous upper bound
}

// =============================================================================
// DEBUG AND INSTRUMENTATION
// =============================================================================

#ifdef DEBUG_CODE_GENERATION
/**
 * @brief Log a load operation for debugging
 * @param op The load operation
 * @param value The value or offset being loaded
 * @param description Human-readable description
 */
static void debug_log_load_operation(ocode_op op, int value,
                                     const char *description) {
  fprintf(stderr, "LOAD: %s (op=%d, value=%d)\n", description, op, value);
}
#else
#define debug_log_load_operation(op, value, desc) ((void)0)
#endif

/**
 * @brief Performance counters for load operations
 *
 * These counters can be used to analyze the frequency of different
 * load operations for optimization purposes.
 */
#ifdef ENABLE_PERFORMANCE_COUNTERS
static struct load_operation_counters {
  uint64_t numeric_loads;
  uint64_t parameter_loads;
  uint64_t global_loads;
  uint64_t local_loads;
  uint64_t pointer_loads;
  uint64_t string_loads;
} g_load_counters = {0};

#define INCREMENT_LOAD_COUNTER(type) (g_load_counters.type++)
#else
#define INCREMENT_LOAD_COUNTER(type) ((void)0)
#endif
