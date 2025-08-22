/**
 * @file common_memory.c
 * @brief Cross-platform memory management helpers for BCPL runtime
 *
 * This module centralizes memory allocation routines that were previously
 * duplicated across the platform-specific files.  Implementations rely on
 * standard C and OS primitives while preserving BCPL's historical semantics
 * of returning a minimal non-null pointer for zero-byte requests.
 */

#include "../include/universal_platform.h"

#include <stdlib.h>
#include <string.h>

#if defined(BCPL_PLATFORM_WINDOWS)
#include <malloc.h>
#include <windows.h>
#else
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>
#endif

void *bcpl_platform_aligned_alloc(size_t size, size_t alignment) {
  if (size == 0) size = 1;  // guarantee non-null result
#if defined(BCPL_PLATFORM_WINDOWS)
  return _aligned_malloc(size, alignment);
#else
  void *ptr = NULL;
  return posix_memalign(&ptr, alignment, size) == 0 ? ptr : NULL;
#endif
}

void bcpl_platform_aligned_free(void *ptr) {
#if defined(BCPL_PLATFORM_WINDOWS)
  if (ptr) _aligned_free(ptr);
#else
  free(ptr);
#endif
}

size_t bcpl_platform_get_page_size(void) {
#if defined(BCPL_PLATFORM_WINDOWS)
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  return si.dwPageSize;
#elif defined(_SC_PAGESIZE)
  long page = sysconf(_SC_PAGESIZE);
  return page > 0 ? (size_t)page : 4096;
#else
  return 4096;  // conservative fallback
#endif
}

void *bcpl_platform_alloc(size_t size) {
  if (size == 0) size = 1;
  return malloc(size);
}

void *bcpl_platform_realloc(void *ptr, size_t size) {
  if (size == 0) size = 1;
  return realloc(ptr, size);
}

void bcpl_platform_free(void *ptr) { free(ptr); }

void *bcpl_platform_alloc_pages(size_t size) {
  size_t page = bcpl_platform_get_page_size();
  size = (size + page - 1) & ~(page - 1);
#if defined(BCPL_PLATFORM_WINDOWS)
  return VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
  void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  return mem == MAP_FAILED ? NULL : mem;
#endif
}

void bcpl_platform_free_pages(void *ptr, size_t size) {
  if (!ptr) return;
  size_t page = bcpl_platform_get_page_size();
  size = (size + page - 1) & ~(page - 1);
#if defined(BCPL_PLATFORM_WINDOWS)
  (void)size;
  VirtualFree(ptr, 0, MEM_RELEASE);
#else
  munmap(ptr, size);
#endif
}
