/**
 * @file io.c
 * @brief BCPL I/O operations implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 */

#include "../include/bcpl_runtime.h"
#include "../include/platform.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Read a character from input stream
 */
bcpl_word_t bcpl_rdch(bcpl_word_t stream_idx) {
  return platform_read_char(stream_idx);
}

/**
 * @brief Write a character to output stream
 */
void bcpl_wrch(bcpl_word_t ch, bcpl_word_t stream_idx) {
  platform_write_char(stream_idx, ch);
}

/**
 * @brief Write a string to output
 */
void bcpl_writes(bcpl_string_t *str) {
  if (!str) {
    return;
  }

  const char *s = (const char *)str;
  bcpl_word_t len = s[0]; // BCPL string length is in first byte

  for (bcpl_word_t i = 1; i <= len; i++) {
    bcpl_wrch(s[i], 1); // stdout
  }
}

/**
 * @brief Write a newline
 */
void bcpl_newline(void) { bcpl_wrch('\n', 1); }
