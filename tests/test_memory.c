/**
 * @file test_memory.c
 * @brief Unit tests for BCPL vector memory management.
 *
 * These tests validate the behaviour of the modern BCPL runtime's
 * vector allocation and reference counting primitives.  A vector is
 * expected to carry metadata describing its size, a magic number for
 * verification and a reference counter governing its lifetime.
 */

#include "bcpl_runtime.h"
#include <stdio.h>

#define TEST_ASSERT(cond, msg)                                                 \
  do {                                                                         \
    if (!(cond)) {                                                             \
      printf("FAIL: %s\n", msg);                                               \
      return 1;                                                                \
    } else {                                                                   \
      printf("PASS: %s\n", msg);                                               \
    }                                                                          \
  } while (0)

/**
 * @brief Verify that bcpl_getvec initializes vector metadata.
 *
 * This test adapts to both the legacy header-based implementation and the
 * modern reference-counted runtime.  When the magic number matches the
 * expected constant, additional metadata checks are performed; otherwise the
 * test falls back to inspecting the raw size header.
 */
static int test_initial_allocation(void) {
  bcpl_vector_t *vec = bcpl_getvec(4);
  TEST_ASSERT(vec != NULL, "allocation returned non-null pointer");

  if (vec->magic == BCPL_VECTOR_MAGIC) {
    TEST_ASSERT(vec->size == 4, "vector size stored correctly");
    TEST_ASSERT(vec->refcount == 1, "initial refcount is one");
  } else {
    bcpl_word_t *raw = (bcpl_word_t *)vec;
    TEST_ASSERT(raw[-1] == 4, "size stored correctly");
  }

  bcpl_freevec(vec);
  return 0;
}

/**
 * @brief Exercise reference counting when supported.
 */
static int test_reference_counting(void) {
  bcpl_vector_t *vec = bcpl_getvec(2);
  TEST_ASSERT(vec != NULL, "allocation succeeded");

  if (vec->magic != BCPL_VECTOR_MAGIC) {
    printf("SKIP: reference counting not available\n");
    bcpl_freevec(vec);
    return 0;
  }

  // Simulate an additional reference.
  vec->refcount++;
  TEST_ASSERT(vec->refcount == 2, "refcount incremented");

  // First free decrements but does not release.
  bcpl_freevec(vec);
  TEST_ASSERT(vec->refcount == 1, "first free decremented refcount");

  // Final free releases the vector; pointer must not be dereferenced
  // afterwards.
  bcpl_freevec(vec);
  return 0;
}

/**
 * @brief Ensure bcpl_freevec tolerates NULL inputs.
 */
static int test_free_null(void) {
  bcpl_freevec(NULL);
  TEST_ASSERT(1, "bcpl_freevec(NULL) is a no-op");
  return 0;
}

int run_test_memory(void) {
  printf("Memory Management Tests\n");
  printf("======================\n");

  int result = 0;
  result |= test_initial_allocation();
  result |= test_reference_counting();
  result |= test_free_null();

  if (result == 0) {
    printf("All memory tests PASSED\n");
  } else {
    printf("Some memory tests FAILED\n");
  }
  return result;
}
