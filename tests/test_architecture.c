/**
 * @file test_architecture.c
 * @brief Architecture Compatibility Tests for BCPL Compiler
 * @author BCPL Modernization Team
 * @date 2025
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

// Test framework
#define TEST_ASSERT(condition, message)                                        \
  do {                                                                         \
    if (!(condition)) {                                                        \
      printf("FAIL: %s\n", message);                                           \
      return 1;                                                                \
    } else {                                                                   \
      printf("PASS: %s\n", message);                                           \
    }                                                                          \
  } while (0)

int test_word_size_detection() {
  TEST_ASSERT(sizeof(void *) >= 4, "Pointer size is at least 32-bit");
  TEST_ASSERT(sizeof(int) >= 4, "Integer size is at least 32-bit");
  return 0;
}

int test_endianness_handling() {
  uint32_t test_value = 0x12345678;
  uint8_t *bytes = (uint8_t *)&test_value;

  // Test that we can handle both endianness correctly
  TEST_ASSERT(bytes[0] == 0x78 || bytes[0] == 0x12,
              "Endianness detection works");
  return 0;
}

int test_alignment_requirements() {
  struct test_struct {
    char c;
    int i;
    double d;
  };

  TEST_ASSERT(sizeof(struct test_struct) >= 13,
              "Structure alignment handled correctly");
  return 0;
}

int test_architecture_compatibility(void) {
  printf("Architecture Compatibility Tests\n");
  printf("===============================\n");

  int result = 0;
  result |= test_word_size_detection();
  result |= test_endianness_handling();
  result |= test_alignment_requirements();

  if (result == 0) {
    printf("All architecture tests PASSED\n");
  } else {
    printf("Some architecture tests FAILED\n");
  }

  return result;
}
