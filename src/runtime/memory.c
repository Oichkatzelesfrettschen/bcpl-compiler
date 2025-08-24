/**
 * @file memory.c
 * @brief BCPL memory management implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 */

#include "bcpl_runtime.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocate a BCPL vector
 */
bcpl_vector_t *bcpl_getvec(bcpl_word_t size) {
  if (size == 0) {
    // Zero-length allocations are unsupported by the BCPL runtime.
    // Returning NULL communicates allocation failure to callers.
    return NULL;
  }

  // Allocate memory for vector + size header
  bcpl_word_t *vec = malloc((size + 1) * sizeof(bcpl_word_t));
  if (!vec) {
    return NULL;
  }

  // Store size in first word, return pointer to data
  vec[0] = size;
  return (bcpl_vector_t *)&vec[1];
}

/**
 * @brief Free a BCPL vector
 */
void bcpl_freevec(bcpl_vector_t *vec) {
  if (!vec) {
    return;
  }

  // Free from actual start (size header is at vec[-1])
  bcpl_word_t *raw_vec = (bcpl_word_t *)vec;
  free(&raw_vec[-1]);
}

/**
 * @brief Copy memory (BCPL movmem equivalent)
 */
void bcpl_movmem(bcpl_word_t *dest, const bcpl_word_t *src, bcpl_word_t count) {
  if (!dest || !src || count <= 0) {
    return;
  }

  memmove(dest, src, count * sizeof(bcpl_word_t));
}
