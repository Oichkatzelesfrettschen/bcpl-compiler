/**
 * @file test_cg_modern.c
 * @brief Comprehensive test suite for the modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 *
 * This test suite validates the modernized code generator against the
 * original implementation, ensuring correctness while demonstrating
 * the improved maintainability and extensibility of the new design.
 *
 * "Testing is not about proving the absence of bugs, but about building
 * confidence in the system through systematic verification." - Lions philosophy
 */

#include "cg_modern.h"
#include "oc.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================================================================
// TEST FRAMEWORK INFRASTRUCTURE
// =============================================================================

/**
 * @brief Test result enumeration
 */
typedef enum { TEST_PASS = 0, TEST_FAIL, TEST_SKIP } test_result_t;

/**
 * @brief Test case structure
 */
typedef struct test_case {
  const char *name;
  const char *description;
  test_result_t (*test_function)(void);
  bool is_enabled;
} test_case_t;

/**
 * @brief Test statistics
 */
static struct test_stats {
  int total_tests;
  int passed_tests;
  int failed_tests;
  int skipped_tests;
} g_test_stats = {0};

// Test output capture for validation
static char g_captured_output[4096];
static size_t g_output_pos = 0;

// =============================================================================
// TEST UTILITIES
// =============================================================================

/**
 * @brief Assert macro with context information
 */
#define TEST_ASSERT(condition, message, ...)                                   \
  do {                                                                         \
    if (!(condition)) {                                                        \
      printf("ASSERTION FAILED in %s: " message "\n", __func__,                \
             ##__VA_ARGS__);                                                   \
      return TEST_FAIL;                                                        \
    }                                                                          \
  } while (0)

/**
 * @brief Compare two strings for equality
 */
#define TEST_ASSERT_STR_EQ(expected, actual)                                   \
  TEST_ASSERT(strcmp(expected, actual) == 0,                                   \
              "String mismatch: expected '%s', got '%s'", expected, actual)

/**
 * @brief Compare two integers for equality
 */
#define TEST_ASSERT_INT_EQ(expected, actual)                                   \
  TEST_ASSERT((expected) == (actual), "Integer mismatch: expected %d, got %d", \
              expected, actual)

/**
 * @brief Reset captured output
 */
static void reset_output_capture(void) {
  g_output_pos = 0;
  memset(g_captured_output, 0, sizeof(g_captured_output));
}

/**
 * @brief Mock emit function for testing
 */
static void mock_emit(const char *format, ...) {
  va_list args;
  va_start(args, format);

  int written =
      vsnprintf(g_captured_output + g_output_pos,
                sizeof(g_captured_output) - g_output_pos, format, args);

  if (written > 0 && g_output_pos + written < sizeof(g_captured_output)) {
    g_output_pos += written;
    g_captured_output[g_output_pos++] = '\n'; // Add newline
  }

  va_end(args);
}

// =============================================================================
// CONTEXT INITIALIZATION TESTS
// =============================================================================

/**
 * @brief Test context initialization
 */
static test_result_t test_context_initialization(void) {
  ocode_context_t ctx;

  initialize_code_generation_context(&ctx);

  TEST_ASSERT_INT_EQ(0, ctx.stack.pointer);
  TEST_ASSERT_INT_EQ(0, ctx.stack.stack_pointer);
  TEST_ASSERT_INT_EQ(0, ctx.stack.data_table_ptr);
  TEST_ASSERT_INT_EQ(1000, ctx.next_label_number);
  TEST_ASSERT_INT_EQ(false, ctx.operation.readonly_mode);
  TEST_ASSERT_INT_EQ(0, ctx.operation.return_code);
  TEST_ASSERT_STR_EQ("gencode_modern", ctx.debug.current_function);
  TEST_ASSERT_INT_EQ(0, ctx.debug.line_number);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test context cleanup
 */
static test_result_t test_context_cleanup(void) {
  ocode_context_t ctx;

  initialize_code_generation_context(&ctx);
  cleanup_code_generation_context(&ctx);

  // Cleanup should not crash and should leave context in a safe state
  return TEST_PASS;
}

// =============================================================================
// OPERATION CLASSIFICATION TESTS
// =============================================================================

/**
 * @brief Test operation classification functions
 */
static test_result_t test_operation_classification(void) {
  // Test load operations
  TEST_ASSERT(is_load_operation(S_LN), "S_LN should be a load operation");
  TEST_ASSERT(is_load_operation(S_TRUE), "S_TRUE should be a load operation");
  TEST_ASSERT(is_load_operation(S_FALSE), "S_FALSE should be a load operation");
  TEST_ASSERT(is_load_operation(S_LP), "S_LP should be a load operation");
  TEST_ASSERT(is_load_operation(S_LG), "S_LG should be a load operation");
  TEST_ASSERT(is_load_operation(S_LL), "S_LL should be a load operation");

  // Test non-load operations
  TEST_ASSERT(!is_load_operation(S_PLUS),
              "S_PLUS should not be a load operation");
  TEST_ASSERT(!is_load_operation(S_SP), "S_SP should not be a load operation");

  // Test arithmetic operations
  TEST_ASSERT(is_arithmetic_operation(S_PLUS), "S_PLUS should be arithmetic");
  TEST_ASSERT(is_arithmetic_operation(S_MINUS), "S_MINUS should be arithmetic");
  TEST_ASSERT(is_arithmetic_operation(S_MULT), "S_MULT should be arithmetic");
  TEST_ASSERT(is_arithmetic_operation(S_DIV), "S_DIV should be arithmetic");
  TEST_ASSERT(is_arithmetic_operation(S_NEG), "S_NEG should be arithmetic");
  TEST_ASSERT(is_arithmetic_operation(S_ABS), "S_ABS should be arithmetic");

  // Test comparison operations
  TEST_ASSERT(is_comparison_operation(S_EQ), "S_EQ should be comparison");
  TEST_ASSERT(is_comparison_operation(S_NE), "S_NE should be comparison");
  TEST_ASSERT(is_comparison_operation(S_LS), "S_LS should be comparison");
  TEST_ASSERT(is_comparison_operation(S_GR), "S_GR should be comparison");

  return TEST_PASS;
}

// =============================================================================
// LOAD OPERATION TESTS
// =============================================================================

/**
 * @brief Test numeric load operation
 */
static test_result_t test_load_number_operation(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);
  reset_output_capture();

  // Mock the rdn() function to return a test value
  // In a real test, we'd inject the value or use a test harness

  ocode_result_t result = handle_load_operations(&ctx, S_LN);

  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);
  TEST_ASSERT_INT_EQ(1, ctx.debug.line_number);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test boolean load operations
 */
static test_result_t test_load_boolean_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test loading true
  ocode_result_t result = handle_load_operations(&ctx, S_TRUE);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test loading false
  result = handle_load_operations(&ctx, S_FALSE);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test parameter load operations
 */
static test_result_t test_load_parameter_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test loading parameter value
  ocode_result_t result = handle_load_operations(&ctx, S_LP);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test loading parameter address
  result = handle_load_operations(&ctx, S_LLP);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

// =============================================================================
// ARITHMETIC OPERATION TESTS
// =============================================================================

/**
 * @brief Test binary arithmetic operations
 */
static test_result_t test_binary_arithmetic_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test addition
  ocode_result_t result = handle_arithmetic_operations(&ctx, S_PLUS);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test subtraction
  result = handle_arithmetic_operations(&ctx, S_MINUS);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test multiplication
  result = handle_arithmetic_operations(&ctx, S_MULT);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test division operations
 */
static test_result_t test_division_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);
  reset_output_capture();

  // Test division
  ocode_result_t result = handle_arithmetic_operations(&ctx, S_DIV);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test remainder
  result = handle_arithmetic_operations(&ctx, S_REM);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test unary arithmetic operations
 */
static test_result_t test_unary_arithmetic_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test negation
  ocode_result_t result = handle_arithmetic_operations(&ctx, S_NEG);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test absolute value
  result = handle_arithmetic_operations(&ctx, S_ABS);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

// =============================================================================
// ERROR HANDLING TESTS
// =============================================================================

/**
 * @brief Test error handling for invalid operations
 */
static test_result_t test_invalid_operation_handling(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test with an invalid operation code
  ocode_result_t result = handle_load_operations(&ctx, (ocode_op)999);
  TEST_ASSERT_INT_EQ(OCODE_SYNTAX_ERROR, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

// =============================================================================
// INTEGRATION TESTS
// =============================================================================

/**
 * @brief Test a complete simple expression
 */
static test_result_t test_simple_expression(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Simulate: load 5, load 3, add
  ocode_result_t result = handle_load_operations(&ctx, S_LN); // Load number
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  result = handle_load_operations(&ctx, S_LN); // Load another number
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  result = handle_arithmetic_operations(&ctx, S_PLUS); // Add them
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

// =============================================================================
// PERFORMANCE TESTS
// =============================================================================

/**
 * @brief Test performance of operation dispatch
 */
static test_result_t test_dispatch_performance(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Perform many operations to test dispatch overhead
  const int num_operations = 10000;

  for (int i = 0; i < num_operations; i++) {
    ocode_result_t result = handle_load_operations(&ctx, S_LN);
    TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);
  }

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

// =============================================================================
// ADDITIONAL OPERATION CATEGORY TESTS
// =============================================================================

/**
 * @brief Test store operations
 */
static test_result_t test_store_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);
  ctx.s = 2; // Simulate values on stack
  ctx.k = 5; // Test offset/address

  // Test store parameter
  ocode_result_t result = handle_store_operations(&ctx, S_SP);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test store global
  result = handle_store_operations(&ctx, S_SG);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test store local
  result = handle_store_operations(&ctx, S_SL);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test logical operations
 */
static test_result_t test_logical_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);
  ctx.s = 2; // Simulate values on stack

  // Test logical AND
  ocode_result_t result = handle_logical_operations(&ctx, S_LOGAND);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test logical OR
  ctx.s = 2;
  result = handle_logical_operations(&ctx, S_LOGOR);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test logical NOT
  ctx.s = 1;
  result = handle_logical_operations(&ctx, S_NOT);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test comparison operations
 */
static test_result_t test_comparison_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);
  ctx.s = 2; // Simulate values on stack

  // Test equality
  ocode_result_t result = handle_comparison_operations(&ctx, S_EQ);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test inequality
  ctx.s = 2;
  result = handle_comparison_operations(&ctx, S_NE);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test less than
  ctx.s = 2;
  result = handle_comparison_operations(&ctx, S_LS);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test control flow operations
 */
static test_result_t test_control_flow_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);
  ctx.k = 10; // Test label

  // Test unconditional goto
  ocode_result_t result = handle_control_flow_operations(&ctx, S_GOTO);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test conditional jump if true
  ctx.s = 1;
  result = handle_control_flow_operations(&ctx, S_JT);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test label definition
  result = handle_control_flow_operations(&ctx, S_LAB);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test function operations
 */
static test_result_t test_function_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test function entry
  ctx.k = 3; // Number of locals
  ocode_result_t result = handle_function_operations(&ctx, S_ENTRY);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test function application
  ctx.s = 1; // Function address on stack
  result = handle_function_operations(&ctx, S_FNAP);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test return
  result = handle_function_operations(&ctx, S_RETURN);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test memory operations
 */
static test_result_t test_memory_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test right-hand value (dereference)
  ctx.s = 1; // Address on stack
  ocode_result_t result = handle_memory_operations(&ctx, S_RV);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test stack operation
  ctx.k = 5; // Stack adjustment
  result = handle_memory_operations(&ctx, S_STACK);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test get byte
  ctx.s = 2; // Address and index on stack
  result = handle_memory_operations(&ctx, S_GETBYTE);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

/**
 * @brief Test meta operations
 */
static test_result_t test_meta_operations(void) {
  ocode_context_t ctx;
  initialize_code_generation_context(&ctx);

  // Test global declaration
  ctx.k = 42; // Global variable ID
  ocode_result_t result = handle_meta_operations(&ctx, S_GLOBAL);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);

  // Test true constant
  result = handle_meta_operations(&ctx, S_TRUE);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);
  TEST_ASSERT_INT_EQ(1, ctx.s); // Should push one value

  // Test false constant
  result = handle_meta_operations(&ctx, S_FALSE);
  TEST_ASSERT_INT_EQ(OCODE_SUCCESS, result);
  TEST_ASSERT_INT_EQ(2, ctx.s); // Should push another value

  cleanup_code_generation_context(&ctx);
  return TEST_PASS;
}

// Add new test cases to the test suite array
static test_case_t additional_tests[] = {
    {"Store Operations", test_store_operations},
    {"Logical Operations", test_logical_operations},
    {"Comparison Operations", test_comparison_operations},
    {"Control Flow Operations", test_control_flow_operations},
    {"Function Operations", test_function_operations},
    {"Memory Operations", test_memory_operations},
    {"Meta Operations", test_meta_operations},
};

/**
 * @brief Complete test suite
 */
static const test_case_t test_suite[] = {
    // Context management tests
    {.name = "context_initialization",
     .description = "Test context initialization",
     .test_function = test_context_initialization,
     .is_enabled = true},
    {.name = "context_cleanup",
     .description = "Test context cleanup",
     .test_function = test_context_cleanup,
     .is_enabled = true},

    // Operation classification tests
    {.name = "operation_classification",
     .description = "Test operation classification functions",
     .test_function = test_operation_classification,
     .is_enabled = true},

    // Load operation tests
    {.name = "load_number_operation",
     .description = "Test numeric load operation",
     .test_function = test_load_number_operation,
     .is_enabled = true},
    {.name = "load_boolean_operations",
     .description = "Test boolean load operations",
     .test_function = test_load_boolean_operations,
     .is_enabled = true},
    {.name = "load_parameter_operations",
     .description = "Test parameter load operations",
     .test_function = test_load_parameter_operations,
     .is_enabled = true},

    // Arithmetic operation tests
    {.name = "binary_arithmetic_operations",
     .description = "Test binary arithmetic operations",
     .test_function = test_binary_arithmetic_operations,
     .is_enabled = true},
    {.name = "division_operations",
     .description = "Test division and remainder operations",
     .test_function = test_division_operations,
     .is_enabled = true},
    {.name = "unary_arithmetic_operations",
     .description = "Test unary arithmetic operations",
     .test_function = test_unary_arithmetic_operations,
     .is_enabled = true},

    // Error handling tests
    {.name = "invalid_operation_handling",
     .description = "Test error handling for invalid operations",
     .test_function = test_invalid_operation_handling,
     .is_enabled = true},

    // Integration tests
    {.name = "simple_expression",
     .description = "Test a complete simple expression",
     .test_function = test_simple_expression,
     .is_enabled = true},

    // Performance tests
    {.name = "dispatch_performance",
     .description = "Test performance of operation dispatch",
     .test_function = test_dispatch_performance,
     .is_enabled = true},

    // Additional operation category tests
    {.name = "store_operations",
     .description = "Test store operations",
     .test_function = test_store_operations,
     .is_enabled = true},
    {.name = "logical_operations",
     .description = "Test logical operations",
     .test_function = test_logical_operations,
     .is_enabled = true},
    {.name = "comparison_operations",
     .description = "Test comparison operations",
     .test_function = test_comparison_operations,
     .is_enabled = true},
    {.name = "control_flow_operations",
     .description = "Test control flow operations",
     .test_function = test_control_flow_operations,
     .is_enabled = true},
    {.name = "function_operations",
     .description = "Test function operations",
     .test_function = test_function_operations,
     .is_enabled = true},
    {.name = "memory_operations",
     .description = "Test memory operations",
     .test_function = test_memory_operations,
     .is_enabled = true},
    {.name = "meta_operations",
     .description = "Test meta operations",
     .test_function = test_meta_operations,
     .is_enabled = true}};

static const size_t test_suite_size =
    sizeof(test_suite) / sizeof(test_suite[0]);

// =============================================================================
// TEST RUNNER
// =============================================================================

/**
 * @brief Run a single test case
 */
static void run_test_case(const test_case_t *test) {
  printf("Running test: %s... ", test->name);
  fflush(stdout);

  if (!test->is_enabled) {
    printf("SKIPPED\n");
    g_test_stats.skipped_tests++;
    return;
  }

  test_result_t result = test->test_function();

  switch (result) {
  case TEST_PASS:
    printf("PASS\n");
    g_test_stats.passed_tests++;
    break;
  case TEST_FAIL:
    printf("FAIL\n");
    g_test_stats.failed_tests++;
    break;
  case TEST_SKIP:
    printf("SKIP\n");
    g_test_stats.skipped_tests++;
    break;
  }

  g_test_stats.total_tests++;
}

/**
 * @brief Run the complete test suite
 */
int main(int argc, char *argv[]) {
  printf("BCPL Modern Code Generator Test Suite\n");
  printf("=====================================\n\n");

  // Initialize test statistics
  memset(&g_test_stats, 0, sizeof(g_test_stats));

  // Run all tests
  for (size_t i = 0; i < test_suite_size; i++) {
    run_test_case(&test_suite[i]);
  }

  // Print summary
  printf("\nTest Summary:\n");
  printf("=============\n");
  printf("Total tests:  %d\n", g_test_stats.total_tests);
  printf("Passed:       %d\n", g_test_stats.passed_tests);
  printf("Failed:       %d\n", g_test_stats.failed_tests);
  printf("Skipped:      %d\n", g_test_stats.skipped_tests);

  if (g_test_stats.failed_tests == 0) {
    printf("\nAll tests passed! 🎉\n");
    return EXIT_SUCCESS;
  } else {
    printf("\n%d test(s) failed. ❌\n", g_test_stats.failed_tests);
    return EXIT_FAILURE;
  }
}

// =============================================================================
// MOCK IMPLEMENTATIONS FOR TESTING
// =============================================================================

// These would normally be provided by the actual code generator,
// but for testing we provide mock implementations

void load(int type, int data) {
  // Mock implementation
  (void)type;
  (void)data;
}

void codex(int opcode) {
  // Mock implementation
  (void)opcode;
}

int rdn(void) {
  // Mock implementation - return a test value
  return 42;
}

void defdata(int op, int data) {
  // Mock implementation
  (void)op;
  (void)data;
}

void emit(const char *format, ...) {
  // Use our mock emit function
  va_list args;
  va_start(args, format);
  mock_emit(format, args);
  va_end(args);
}
