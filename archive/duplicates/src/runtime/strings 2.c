/**
 * @file strings.c
 * @brief BCPL string operations implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 */

#include "../include/bcpl_runtime.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Get length of BCPL string
 */
bcpl_word_t bcpl_string_length(const bcpl_word_t *str) {
  if (!str) {
    return 0;
  }

  // BCPL strings are byte-packed with length in first byte
  return ((const char *)str)[0];
}

/**
 * @brief Compare two BCPL strings
 */
bcpl_word_t bcpl_string_compare(const bcpl_word_t *str1,
                                const bcpl_word_t *str2) {
  if (!str1 || !str2) {
    return 0;
  }

  const char *s1 = (const char *)str1;
  const char *s2 = (const char *)str2;

  bcpl_word_t len1 = s1[0];
  bcpl_word_t len2 = s2[0];

  bcpl_word_t min_len = (len1 < len2) ? len1 : len2;

  int result = memcmp(&s1[1], &s2[1], min_len);

  if (result == 0) {
    return len1 - len2;
  }

  return result;
}

/**
 * @brief Copy BCPL string
 */
void bcpl_string_copy(bcpl_word_t *dest, const bcpl_word_t *src) {
  if (!dest || !src) {
    return;
  }

  const char *s = (const char *)src;
  char *d = (char *)dest;

  bcpl_word_t len = s[0];
  memcpy(d, s, len + 1); // Copy length byte + data
}
