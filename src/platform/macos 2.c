/**
 * @file macos.c
 * @brief macOS-specific platform implementation for BCPL runtime
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This file provides macOS-specific implementations of the platform
 * abstraction layer. It handles system calls, memory management, and
 * other OS-specific functionality for both Intel and Apple Silicon Macs.
 *
 * ## Features
 * - Native Apple Silicon (ARM64) support
 * - Intel Mac (x86_64) compatibility
 * - Unified macOS system call interface
 * - Optimized memory management with VM subsystem
 * - File system integration with HFS+/APFS
 */

#include "../include/bcpl_types.h"
#include "../include/platform.h"
#include <errno.h>
#include <fcntl.h>
#include <mach/mach_time.h>
#include <mach/vm_map.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// Forward declarations for internal functions
int platform_read_char(int fd);
int platform_write_char(int fd, int ch);

// =============================================================================
// MACOS SYSTEM CALL WRAPPERS
// =============================================================================

/**
 * @brief macOS platform initialization
 * @return 0 on success, non-zero on failure
 */
int bcpl_platform_init(void) {
  // Initialize macOS-specific components
  return 0;
}

/**
 * @brief macOS platform cleanup
 */
void bcpl_platform_cleanup(void) {
  // Cleanup macOS-specific components
}

/**
 * @brief Get platform name
 * @return Platform name string
 */
const char *bcpl_platform_name(void) { return "macOS"; }

/**
 * @brief Open file with macOS-specific optimizations
 */
static int macos_open(const char *path, int flags, int mode) {
  // Convert BCPL flags to macOS flags
  int mac_flags = 0;

  if (flags & BCPL_O_RDONLY)
    mac_flags |= O_RDONLY;
  if (flags & BCPL_O_WRONLY)
    mac_flags |= O_WRONLY;
  if (flags & BCPL_O_RDWR)
    mac_flags |= O_RDWR;
  if (flags & BCPL_O_CREAT)
    mac_flags |= O_CREAT;
  if (flags & BCPL_O_EXCL)
    mac_flags |= O_EXCL;
  if (flags & BCPL_O_TRUNC)
    mac_flags |= O_TRUNC;
  if (flags & BCPL_O_APPEND)
    mac_flags |= O_APPEND;
  if (flags & BCPL_O_NONBLOCK)
    mac_flags |= O_NONBLOCK;

  return open(path, mac_flags, mode);
}

/**
 * @brief Close file descriptor
 */
static int macos_close(int fd) { return close(fd); }

/**
 * @brief Read from file descriptor
 */
static long macos_read(int fd, void *buf, size_t count) {
  ssize_t result = read(fd, buf, count);
  return (long)result;
}

/**
 * @brief Write to file descriptor
 */
static long macos_write(int fd, const void *buf, size_t count) {
  ssize_t result = write(fd, buf, count);
  return (long)result;
}

/**
 * @brief Seek in file
 */
static long macos_lseek(int fd, long offset, int whence) {
  // Convert BCPL seek constants to macOS constants
  int mac_whence;
  switch (whence) {
  case BCPL_SEEK_SET:
    mac_whence = SEEK_SET;
    break;
  case BCPL_SEEK_CUR:
    mac_whence = SEEK_CUR;
    break;
  case BCPL_SEEK_END:
    mac_whence = SEEK_END;
    break;
  default:
    mac_whence = SEEK_SET;
    break;
  }

  off_t result = lseek(fd, (off_t)offset, mac_whence);
  return (long)result;
}

/**
 * @brief Memory allocation using sbrk (legacy compatibility)
 */
static void *macos_sbrk(long increment) {
  // macOS doesn't have sbrk, use malloc/realloc instead
  static void *heap_end = NULL;
  static size_t heap_size = 0;

  if (increment == 0) {
    return heap_end;
  }

  if (heap_end == NULL) {
    // Initial allocation
    heap_size = (increment > 0) ? increment : BCPL_PGSZ;
    heap_end = malloc(heap_size);
    return heap_end;
  }

  if (increment > 0) {
    // Expand heap
    size_t new_size = heap_size + increment;
    void *new_heap = realloc(heap_end, new_size);
    if (new_heap == NULL) {
      return (void *)-1;
    }
    void *old_end = (char *)heap_end + heap_size;
    heap_end = new_heap;
    heap_size = new_size;
    return old_end;
  } else {
    // Shrink heap (not implemented in this simple version)
    return heap_end;
  }
}

/**
 * @brief Memory mapping with macOS optimizations
 */
void *macos_mmap(void *addr, size_t length, int prot, int flags, int fd,
                 long offset) {
  // Convert BCPL protection flags to macOS flags
  int mac_prot = 0;
  if (prot & BCPL_PROT_READ)
    mac_prot |= PROT_READ;
  if (prot & BCPL_PROT_WRITE)
    mac_prot |= PROT_WRITE;
  if (prot & BCPL_PROT_EXEC)
    mac_prot |= PROT_EXEC;

  // Convert BCPL mapping flags to macOS flags
  int mac_flags = 0;
  if (flags & BCPL_MAP_PRIVATE)
    mac_flags |= MAP_PRIVATE;
  if (flags & BCPL_MAP_ANONYMOUS)
    mac_flags |= MAP_ANON;

  return mmap(addr, length, mac_prot, mac_flags, fd, (off_t)offset);
}

/**
 * @brief Unmap memory
 */
int macos_munmap(void *addr, size_t length) { return munmap(addr, length); }

/**
 * @brief Exit process
 */
static void macos_exit(int status) __attribute__((noreturn));
static void macos_exit(int status) { exit(status); }

/**
 * @brief Get process ID
 */
static int macos_getpid(void) { return (int)getpid(); }

/**
 * @brief Get current time
 */
static long macos_time(long *tloc) {
  time_t t = time(NULL);
  if (tloc != NULL) {
    *tloc = (long)t;
  }
  return (long)t;
}

// =============================================================================
// MACOS PLATFORM STRUCTURE
// =============================================================================

static const bcpl_platform_t macos_platform = {
    .name = "macOS",
    .sys_open = macos_open,
    .sys_close = macos_close,
    .sys_read = macos_read,
    .sys_write = macos_write,
    .sys_lseek = macos_lseek,
    .sys_sbrk = macos_sbrk,
    .sys_mmap = macos_mmap,
    .sys_munmap = macos_munmap,
    .sys_exit = macos_exit,
    .sys_getpid = macos_getpid,
    .sys_time = macos_time,
};

// =============================================================================
// PLATFORM INTERFACE IMPLEMENTATION
// =============================================================================

// Duplicate function definitions removed - implemented above

/**
 * @brief Read a character from file descriptor
 */
int platform_read_char(int fd) {
  char ch;
  if (read(fd, &ch, 1) == 1) {
    return (unsigned char)ch;
  }
  return -1; // EOF or error
}

/**
 * @brief Write a character to file descriptor
 */
int platform_write_char(int fd, int ch) {
  char c = (char)ch;
  return (write(fd, &c, 1) == 1) ? 0 : -1;
}

// =============================================================================
// PLATFORM ABSTRACTION LAYER IMPLEMENTATIONS
// =============================================================================

const bcpl_platform_t *bcpl_get_platform(void) { return &macos_platform; }

const char *bcpl_platform_info(void) {
#if defined(__aarch64__)
  return "macOS ARM64 (Apple Silicon)";
#elif defined(__x86_64__)
  return "macOS x86_64 (Intel)";
#else
  return "macOS (Unknown Architecture)";
#endif
}

size_t bcpl_platform_pagesize(void) { return (size_t)getpagesize(); }

bool bcpl_platform_is_big_endian(void) {
  // macOS is always little-endian on supported architectures
  return false;
}

uint64_t bcpl_platform_timestamp(void) {
  // Use Mach absolute time for high-resolution timestamps
  static mach_timebase_info_data_t timebase = {0, 0};

  if (timebase.denom == 0) {
    mach_timebase_info(&timebase);
  }

  uint64_t mach_time = mach_absolute_time();
  return (mach_time * timebase.numer) / timebase.denom;
}

int bcpl_platform_usleep(uint32_t microseconds) { return usleep(microseconds); }

int bcpl_platform_errno(void) { return errno; }

const char *bcpl_platform_strerror(int error_code) {
  return strerror(error_code);
}

int bcpl_platform_error_convert(int sys_error) {
  switch (sys_error) {
  case 0:
    return BCPL_OK;
  case ENOMEM:
    return BCPL_ERROR_NOMEM;
  case ENOENT:
    return BCPL_ERROR_NOFILE;
  case EIO:
    return BCPL_ERROR_IO;
  case EINVAL:
    return BCPL_ERROR_INVAL;
  case EACCES:
    return BCPL_ERROR_PERM;
  case EPERM:
    return BCPL_ERROR_PERM;
  default:
    return BCPL_ERROR_IO;
  }
}

// =============================================================================
// STACK OPERATIONS
// =============================================================================

void *bcpl_get_stack_pointer(void) {
#if defined(__aarch64__)
  void *sp;
  __asm__ volatile("mov %0, sp" : "=r"(sp));
  return sp;
#elif defined(__x86_64__)
  void *sp;
  __asm__ volatile("movq %%rsp, %0" : "=r"(sp));
  return sp;
#else
  // Fallback using a local variable address
  char dummy;
  return &dummy;
#endif
}

bool bcpl_is_on_stack(void *addr) {
  // Simple heuristic: check if address is near current stack pointer
  void *sp = bcpl_get_stack_pointer();
  uintptr_t addr_val = (uintptr_t)addr;
  uintptr_t sp_val = (uintptr_t)sp;

  // Assume stack grows downward and is within 8MB
  uintptr_t stack_size = 8 * 1024 * 1024;

  return (addr_val <= sp_val) && (addr_val >= (sp_val - stack_size));
}

size_t bcpl_get_stack_size(void) {
  // Return a conservative estimate
  return 8 * 1024 * 1024; // 8MB default on macOS
}
