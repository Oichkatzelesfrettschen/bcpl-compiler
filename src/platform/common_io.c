#include "../include/universal_platform.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @file common_io.c
 * @brief Cross-platform file I/O helpers shared by all targets.
 */

bcpl_file_handle_t *bcpl_platform_fopen(const char *filename, char mode,
                                        bool binary) {
  bcpl_file_handle_t *handle = malloc(sizeof(bcpl_file_handle_t));
  if (!handle)
    return NULL;

  const char *fmode = NULL;
  switch (mode) {
  case 'r':
    fmode = binary ? "rb" : "r";
    break;
  case 'w':
    fmode = binary ? "wb" : "w";
    break;
  case 'a':
    fmode = binary ? "ab" : "a";
    break;
  default:
    free(handle);
    return NULL;
  }

  handle->native_handle = fopen(filename, fmode);
  if (!handle->native_handle) {
    free(handle);
    return NULL;
  }

  handle->flags = 0;
  handle->buffer = NULL;
  handle->buffer_size = 0;
  handle->is_binary = binary;
  return handle;
}

int bcpl_platform_fclose(bcpl_file_handle_t *handle) {
  if (!handle)
    return -1;
  int result = 0;
  if (handle->native_handle)
    result = fclose(handle->native_handle);
  free(handle->buffer);
  free(handle);
  return result;
}

int bcpl_platform_fgetc(bcpl_file_handle_t *handle) {
  if (!handle || !handle->native_handle)
    return -1;
  return fgetc(handle->native_handle);
}

int bcpl_platform_fputc(int ch, bcpl_file_handle_t *handle) {
  if (!handle || !handle->native_handle)
    return -1;
  return fputc(ch, handle->native_handle);
}

int bcpl_platform_remove(const char *filename) { return remove(filename); }
