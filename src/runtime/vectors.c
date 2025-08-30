/**
 * @file vectors.c
 * @brief BCPL vector operations implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 */

#include "bcpl_runtime.h"
#include <stdlib.h>

/**
 * @brief Create a new vector with initialization
 */
bcpl_vector_t *bcpl_newvec(bcpl_word_t size, bcpl_word_t init_val) {
  bcpl_vector_t *vec = bcpl_getvec(size);
  if (!vec) {
    return NULL;
  }

  // Initialize all elements to the specified value
  for (bcpl_word_t i = 0; i < size; i++) {
    vec->data[i] = init_val;
  }

  return vec;
}

/**
 * @brief Get the size of a vector
 */
bcpl_word_t bcpl_vecsize(const bcpl_vector_t *vec) {
  if (!vec) {
    return 0;
  }

  // Check if it's a modern vector with magic number
  if (vec->magic == BCPL_VECTOR_MAGIC) {
    return vec->size;
  }

  // Legacy vector format - size is stored at data[-1]
  const bcpl_word_t *data = (const bcpl_word_t *)vec;
  return data[-1];
}

/**
 * @brief Check if vector index is valid
 */
bcpl_bool_t bcpl_vec_bounds_check(const bcpl_vector_t *vec, bcpl_word_t index) {
  if (!vec) {
    return BCPL_FALSE;
  }

  bcpl_word_t size = bcpl_vecsize(vec);
  return (index < size) ? BCPL_TRUE : BCPL_FALSE;
}
