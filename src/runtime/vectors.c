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

  bcpl_word_t *data = bcpl_vector_data(vec);

  // Initialize all elements
  for (bcpl_word_t i = 0; i < size; i++) {
    data[i] = init_val;
  }

  return vec;
}

/**
 * @brief Get the size of a vector
 */
bcpl_word_t bcpl_vecsize(const bcpl_vector_t *vec) {
  return vec ? vec->size : 0;
}

/**
 * @brief Check if vector index is valid
 */
bcpl_bool_t bcpl_vec_bounds_check(const bcpl_vector_t *vec, bcpl_word_t index) {
  return (vec && index < vec->size) ? BCPL_TRUE : BCPL_FALSE;
}
