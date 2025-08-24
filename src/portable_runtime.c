/**
 * @file portable_runtime.c
 * @brief Universal BCPL Runtime - Replaces Assembly Files
 * @author BCPL Modernization Team
 * @date 2025
 *
 * This file provides a pure C implementation of the BCPL runtime
 * that replaces the platform-specific assembly files. Uses inline
 * assembly only where absolutely necessary and provides portable
 * alternatives for all major platforms.
 */

#include "bcpl_types.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// BCPL Global Vector Size
#define GLOBAL_VECTOR_SIZE 1000
#define BCPL_STACK_SIZE (4 * 1024 * 1024) // 4MB default

// Global variables matching assembly implementation
static int32_t global_vector[GLOBAL_VECTOR_SIZE];
static int32_t *bcpl_stack;
static int32_t *bcpl_stack_base;
static int32_t bcpl_argc;
static int32_t **bcpl_argv;

// Standard BCPL global indices
#define STACKBASE 95
#define STACKEND 96
#define ARGC 97
#define ARGV 98
#define PARAM 99

/**
 * @brief Initialize BCPL runtime environment
 * Replaces the assembly startup code in su.s
 */
int bcpl_runtime_startup(int argc, char **argv) {
  // Allocate BCPL stack
  bcpl_stack = malloc(BCPL_STACK_SIZE);
  if (!bcpl_stack) {
    fprintf(stderr, "Failed to allocate BCPL stack\n");
    return 1;
  }

  bcpl_stack_base = bcpl_stack + (BCPL_STACK_SIZE / sizeof(int32_t));

  // Initialize global vector
  memset(global_vector, 0, sizeof(global_vector));

  // Set up stack pointers in global vector
  global_vector[STACKBASE] = (intptr_t)bcpl_stack / 4;
  global_vector[STACKEND] = (intptr_t)bcpl_stack_base / 4;

  // Process command line arguments
  global_vector[ARGC] = argc;
  bcpl_argc = argc;

  // Convert argv to BCPL format
  bcpl_argv = malloc(argc * sizeof(int32_t *));
  for (int i = 0; i < argc; i++) {
    int len = strlen(argv[i]);
    char *bcpl_str = malloc(len + 2); // Length byte + string + terminator
    bcpl_str[0] = len;
    memcpy(bcpl_str + 1, argv[i], len);
    bcpl_str[len + 1] = 0;
    bcpl_argv[i] = (int32_t *)bcpl_str;
  }

  global_vector[ARGV] = (intptr_t)bcpl_argv / 4;

  return 0;
}

/**
 * @brief BCPL system call interface
 * Replaces platform-specific sys*.s files
 */
int32_t bcpl_syscall(int32_t call_num, int32_t arg1, int32_t arg2,
                     int32_t arg3) {
  switch (call_num) {
  case 1: // write
    return write(arg1, (void *)(intptr_t)arg2, arg3);
  case 0: // read
    return read(arg1, (void *)(intptr_t)arg2, arg3);
  case 60: // exit
    exit(arg1);
    return 0;
  default:
    return -1;
  }
}

/**
 * @brief BCPL character I/O functions
 * Replaces rt.s I/O functions
 */
int32_t bcpl_rdch(void) {
  int c = getchar();
  return (c == EOF) ? -1 : c;
}

void bcpl_wrch(int32_t ch) { putchar(ch); }

/**
 * @brief BCPL memory management
 * Replaces rt.s memory functions
 */
BCPL_EXPORT bcpl_vector_t *bcpl_getvec(bcpl_word_t size) {
  if (size <= 0) {
    return NULL;
  }

  size_t total_size = sizeof(bcpl_vector_t) + (size * sizeof(bcpl_word_t));
  bcpl_vector_t *vec = malloc(total_size);
  if (!vec) {
    return NULL;
  }

  vec->magic = BCPL_VECTOR_MAGIC;
  vec->size = size;
  vec->refcount = 1;
  memset(vec->data, 0, size * sizeof(bcpl_word_t));

  return vec;
}

BCPL_EXPORT void bcpl_freevec(bcpl_vector_t *vec) {
  if (!vec || vec->magic != BCPL_VECTOR_MAGIC) {
    return;
  }

  if (--vec->refcount <= 0) {
    vec->magic = 0;
    free(vec);
  }
}

/**
 * @brief Get global vector pointer
 * Replaces global.s access patterns
 */
int32_t *bcpl_get_global(void) { return global_vector; }

/**
 * @brief BCPL string operations
 * Portable implementations of string functions
 */
void bcpl_writes(const char *str) { printf("%s", str); }

void bcpl_writef(const char *format, int32_t value) { printf(format, value); }

/**
 * @brief Cleanup BCPL runtime
 */
void bcpl_runtime_cleanup(void) {
  free(bcpl_stack);
  for (int i = 0; i < bcpl_argc; i++) {
    free(bcpl_argv[i]);
  }
  free(bcpl_argv);
}
