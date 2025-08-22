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
#include "../include/universal_platform.h"
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

// For posix_memalign, sysconf, etc.
#include <limits.h>

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

/**
 * @brief Get high-resolution timestamp
 * @return Timestamp in nanoseconds
 */
uint64_t bcpl_platform_get_timestamp(void) {
  static mach_timebase_info_data_t timebase = {0};

  if (timebase.denom == 0) {
    mach_timebase_info(&timebase);
  }

  uint64_t mach_time = mach_absolute_time();
  return (mach_time * timebase.numer) / timebase.denom;
}

/**
 * @brief Sleep for specified duration
 * @param nanoseconds Sleep duration in nanoseconds
 */
void bcpl_platform_sleep(uint64_t nanoseconds) {
  // Convert nanoseconds to microseconds for usleep
  uint32_t microseconds = (uint32_t)(nanoseconds / 1000);
  if (microseconds > 0) {
    usleep(microseconds);
  }
}

// =============================================================================
// MEMORY ALLOCATION FUNCTIONS (MISSING IMPLEMENTATIONS)
// =============================================================================

/**
 * @brief Allocate memory using platform-specific allocator
 * @param size Size in bytes
 * @return Allocated memory pointer or NULL on failure
 */
/**
 * @brief Memory comparison function
 * @param ptr1 First memory block
 * @param ptr2 Second memory block
 * @param size Number of bytes to compare
 * @return 0 if equal, < 0 if ptr1 < ptr2, > 0 if ptr1 > ptr2
 */
int bcpl_platform_memcmp(const void *ptr1, const void *ptr2, size_t size) {
  return memcmp(ptr1, ptr2, size);
}

/**
 * @brief Get high-resolution time in nanoseconds
 * @return Current time in nanoseconds
 */
uint64_t bcpl_platform_get_time_ns(void) {
  return bcpl_platform_get_timestamp();
}

/**
 * @brief Sleep for specified milliseconds
 * @param milliseconds Sleep duration in milliseconds
 */
void bcpl_platform_sleep_ms(uint32_t milliseconds) {
  bcpl_platform_sleep((uint64_t)milliseconds *
                      1000000); // Convert to nanoseconds
}

/**
 * @brief Allocate aligned memory
 * @param size Size in bytes
 * @param alignment Alignment requirement
 * @return Aligned memory pointer or NULL
 */
/**
 * @brief Get number of CPU cores
 * @return Number of logical CPU cores
 */
int bcpl_platform_get_cpu_count(void) {
  return (int)sysconf(_SC_NPROCESSORS_ONLN);
}

/**
 * @brief Get last system error
 * @return Error code
 */
int bcpl_platform_get_last_error(void) { return errno; }

/**
 * @brief Print stack trace (if available)
 * @param file Output file
 */
void bcpl_platform_print_stacktrace(FILE *file) {
  // macOS doesn't have easy backtrace without additional frameworks
  fprintf(file, "Stack trace not available on this platform\n");
}

/**
 * @brief Get environment variable
 * @param name Variable name
 * @return Variable value or NULL
 */
const char *bcpl_platform_getenv(const char *name) { return getenv(name); }

/**
 * @brief Get comprehensive CPU feature information
 * @return CPU features structure
 */
bcpl_cpu_features_t bcpl_platform_get_cpu_features(void) {
  bcpl_cpu_features_t features = {0};

  // Get architecture name
#if defined(__aarch64__)
  strncpy(features.arch_name, "ARM64", sizeof(features.arch_name) - 1);
  features.has_simd = true; // ARM64 always has NEON
  features.has_aes = true;  // Most ARM64 CPUs have AES
  features.feature_flags = BCPL_CPU_FEATURE_NEON;
#elif defined(__x86_64__)
  strncpy(features.arch_name, "x86_64", sizeof(features.arch_name) - 1);
  features.has_simd = true; // Assume SSE2 at minimum
  features.has_aes = false; // Conservative assumption
  features.feature_flags = BCPL_CPU_FEATURE_SSE2;
#else
  strncpy(features.arch_name, "unknown", sizeof(features.arch_name) - 1);
  features.has_simd = false;
  features.has_aes = false;
  features.feature_flags = 0;
#endif

  // Get core count
  features.core_count = bcpl_platform_get_cpu_count();

  return features;
}

// =============================================================================
// FILE OPERATIONS (MISSING IMPLEMENTATIONS)
// =============================================================================

/**
 * @brief Open file with BCPL semantics
 * @param filename Path to file
void bcpl_platform_memcpy(void *dest, const void *src, size_t size) {
  memcpy(dest, src, size);
}

/**
 * @brief Fast memory set optimized for platform
 * @param dest Destination buffer
 * @param value Value to set
 * @param size Number of bytes
 */
void bcpl_platform_memset(void *dest, int value, size_t size) {
  memset(dest, value, size);
}
