/**
 * @file test_ocode_64bit.c
 * @brief Test program for 64-bit OCODE integration
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Test both with and without 64-bit OCODE
#define BCPL_USE_64BIT_OCODE 1
#include "ocode_bridge.h"

/**
 * @brief Test basic context operations
 */
static void test_context_operations(void) {
  printf("Testing context operations...\n");

  ocode_context_t ctx;

  // Test initialization
  bool init_success = ocode_init_context(&ctx, 512);
  assert(init_success && "Context initialization should succeed");

  // Test implementation info
  printf("  Implementation: %s\n", ocode_get_implementation_name());
  printf("  Version: %s\n", ocode_get_version());
  printf("  Word size: %zu bytes\n", ocode_get_word_size());
  printf("  64-bit features: %s\n", ocode_has_64bit_features() ? "Yes" : "No");

  // Test cleanup
  ocode_cleanup_context(&ctx);

  printf("  ✓ Context operations passed\n");
}

/**
 * @brief Test operation attribute queries
 */
static void test_operation_attributes(void) {
  printf("Testing operation attributes...\n");

  // Test basic operations
  const ocode_attr_t *attr_true = ocode_get_attributes(OCODE_OP_TRUE);
  assert(attr_true != NULL && "TRUE operation should have attributes");

  const ocode_attr_t *attr_plus = ocode_get_attributes(OCODE_OP_PLUS);
  assert(attr_plus != NULL && "PLUS operation should have attributes");

  // Test operation availability
  assert(ocode_is_operation_available(OCODE_OP_TRUE) &&
         "TRUE should be available");
  assert(ocode_is_operation_available(OCODE_OP_MULT) &&
         "MULT should be available");

  // Test invalid operation
  assert(!ocode_is_operation_available(-1) &&
         "Invalid operation should not be available");

#if OCODE_64BIT_AVAILABLE
  // Test 64-bit specific operations
  if (ocode_has_64bit_features()) {
    printf("  Testing 64-bit specific operations...\n");

    if (OCODE_MULT64_AVAILABLE) {
      assert(ocode_is_operation_available(OCODE_OP_MULT64) &&
             "MULT64 should be available");
    }

    if (OCODE_PTR_ARITHMETIC_AVAILABLE) {
      assert(ocode_is_operation_available(OCODE_OP_PTR_ADD) &&
             "PTR_ADD should be available");
    }

    if (OCODE_ATOMIC_AVAILABLE) {
      assert(ocode_is_operation_available(OCODE_ATOMIC_LOAD) &&
             "ATOMIC_LOAD should be available");
    }

    printf("    ✓ 64-bit operations verified\n");
  }
#endif

  printf("  ✓ Operation attributes passed\n");
}

/**
 * @brief Test compatibility between legacy and 64-bit modes
 */
static void test_compatibility(void) {
  printf("Testing legacy/64-bit compatibility...\n");

  // All legacy operations should be available in both modes
  static const ocode_op_t legacy_ops[] = {
      OCODE_OP_TRUE,   OCODE_OP_FALSE, OCODE_OP_RV,     OCODE_OP_FNAP,
      OCODE_OP_MULT,   OCODE_OP_DIV,   OCODE_OP_REM,    OCODE_OP_PLUS,
      OCODE_OP_MINUS,  OCODE_OP_NEG,   OCODE_OP_ABS,    OCODE_OP_EQ,
      OCODE_OP_NE,     OCODE_OP_LS,    OCODE_OP_GR,     OCODE_OP_LE,
      OCODE_OP_GE,     OCODE_OP_NOT,   OCODE_OP_LSHIFT, OCODE_OP_RSHIFT,
      OCODE_OP_LOGAND, OCODE_OP_LOGOR, OCODE_OP_EQV,    OCODE_OP_NEQV};

  size_t num_legacy_ops = sizeof(legacy_ops) / sizeof(legacy_ops[0]);

  for (size_t i = 0; i < num_legacy_ops; i++) {
    assert(ocode_is_operation_available(legacy_ops[i]) &&
           "All legacy operations should be available");

    const ocode_attr_t *attr = ocode_get_attributes(legacy_ops[i]);
    assert(attr != NULL && "All legacy operations should have attributes");
  }

  printf("  ✓ Compatibility test passed\n");
}

/**
 * @brief Test word size consistency
 */
static void test_word_size(void) {
  printf("Testing word size consistency...\n");

  size_t word_size = ocode_get_word_size();

#if OCODE_64BIT_AVAILABLE
  if (ocode_has_64bit_features()) {
    assert(word_size == 8 && "64-bit mode should have 8-byte words");
    assert(sizeof(ocode_word_t) == 8 && "ocode_word_t should be 8 bytes");
  } else {
    assert(word_size == 4 && "Legacy mode should have 4-byte words");
    assert(sizeof(ocode_word_t) == 4 && "ocode_word_t should be 4 bytes");
  }
#else
  assert(word_size == 4 && "Legacy mode should have 4-byte words");
  assert(sizeof(ocode_word_t) == 4 && "ocode_word_t should be 4 bytes");
#endif

  printf("  Word size: %zu bytes\n", word_size);
  printf("  ✓ Word size consistency passed\n");
}

/**
 * @brief Performance benchmark for operation processing
 */
static void benchmark_operations(void) {
  printf("Running basic performance benchmark...\n");

  ocode_context_t ctx;
  if (!ocode_init_context(&ctx, 1024)) {
    printf("  ⚠️  Could not initialize context for benchmark\n");
    return;
  }

  // Simple benchmark: query attributes for common operations many times
  const int iterations = 10000;

  for (int i = 0; i < iterations; i++) {
    // Test common operations
    ocode_get_attributes(OCODE_OP_PLUS);
    ocode_get_attributes(OCODE_OP_MULT);
    ocode_get_attributes(OCODE_OP_EQ);
    ocode_is_operation_available(OCODE_OP_TRUE);
    ocode_is_operation_available(OCODE_OP_FALSE);
  }

  ocode_cleanup_context(&ctx);

  printf("  ✓ Completed %d operation queries\n", iterations * 5);
}

/**
 * @brief Main test function
 */
int main(void) {
  printf("=== BCPL 64-bit OCODE Integration Test ===\n\n");

  test_context_operations();
  printf("\n");

  test_operation_attributes();
  printf("\n");

  test_compatibility();
  printf("\n");

  test_word_size();
  printf("\n");

  benchmark_operations();
  printf("\n");

  printf("=== All tests passed! ===\n");
  return 0;
}
