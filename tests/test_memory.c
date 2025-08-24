/**
 * @file test_memory.c
 * @brief Tests for bcpl_getvec/bcpl_freevec reference counting
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

static int test_reference_counting(void) {
  bcpl_vector_t *vec = bcpl_getvec(4);
  TEST_ASSERT(vec != NULL, "Allocation succeeded");

  TEST_ASSERT(vec->size == 4, "Size stored correctly");
  TEST_ASSERT(vec->refcount == 1, "Initial refcount is 1");

  bcpl_freevec(vec);
  return 0;
}

int run_test_memory(void) {
  printf("Memory Management Tests\n");
  printf("======================\n");

  int result = test_reference_counting();
  if (result == 0) {
    printf("All memory tests PASSED\n");
  } else {
    printf("Some memory tests FAILED\n");
  }
  return result;
}
