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

  if (size > BCPL_MAX_VECTOR_SIZE) {
    // Prevent unreasonably large allocations
    return NULL;
  }

  // Allocate memory for the complete bcpl_vector_t structure + data
  size_t total_size = sizeof(bcpl_vector_t) + (size * sizeof(bcpl_word_t));
  bcpl_vector_t *vec = malloc(total_size);
  if (!vec) {
    return NULL;
  }

  // Initialize the vector metadata
  vec->magic = BCPL_VECTOR_MAGIC;
  vec->size = size;
  vec->refcount = 1;

  // Initialize data to zero for safety
  memset(vec->data, 0, size * sizeof(bcpl_word_t));

  return vec;
}

/**
 * @brief Free a BCPL vector
 */
void bcpl_freevec(bcpl_vector_t *vec) {
  if (!vec) {
    return;
  }

  // Validate magic number for safety
  if (vec->magic != BCPL_VECTOR_MAGIC) {
    // Legacy vector format - handle the old way for backward compatibility
    bcpl_word_t *raw_vec = (bcpl_word_t *)vec;
    free(&raw_vec[-1]);
    return;
  }

  // Decrement reference count
  if (vec->refcount > 1) {
    vec->refcount--;
    return;
  }

  // Reference count reached zero - actually free the memory
  vec->magic = 0; // Clear magic number for safety
  free(vec);
}

/**
 * @brief Increase reference count of a vector
 */
bcpl_vector_t *bcpl_addref(bcpl_vector_t *vec) {
  if (!vec) {
    return NULL;
  }

  // Only increment for modern vectors with magic number
  if (vec->magic == BCPL_VECTOR_MAGIC) {
    vec->refcount++;
  }

  return vec;
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
