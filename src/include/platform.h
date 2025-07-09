/**
 * @file platform.h
 * @brief Platform abstraction layer for BCPL runtime
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This header provides a unified platform abstraction layer that allows
 * the BCPL runtime to work across different operating systems and
 * architectures. It abstracts away platform-specific system calls and
 * provides a consistent interface.
 *
 * ## Supported Platforms
 * - **Linux**: Full feature support with Linux system calls
 * - **macOS**: Native support for Apple Silicon and Intel Macs
 * - **FreeBSD**: BSD-style system calls and conventions
 * - **Windows**: Windows API integration (future)
 *
 * ## Architecture Support
 * - **x86_64**: Primary 64-bit Intel/AMD support
 * - **i386**: Legacy 32-bit Intel support
 * - **ARM64**: Apple Silicon and other ARM64 platforms
 * - **ARM32**: Embedded and legacy ARM systems
 */

#ifndef BCPL_PLATFORM_H
#define BCPL_PLATFORM_H

#include "bcpl_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// =============================================================================
// STANDARD UNIX FILE OPERATIONS
// =============================================================================

/**
 * @brief Standard file open flags (POSIX-compatible)
 */
enum bcpl_open_flags {
  BCPL_O_RDONLY = 0x0000,   ///< Read only
  BCPL_O_WRONLY = 0x0001,   ///< Write only
  BCPL_O_RDWR = 0x0002,     ///< Read/write
  BCPL_O_CREAT = 0x0040,    ///< Create if not exists
  BCPL_O_EXCL = 0x0080,     ///< Exclusive creation
  BCPL_O_TRUNC = 0x0200,    ///< Truncate to zero length
  BCPL_O_APPEND = 0x0400,   ///< Append mode
  BCPL_O_NONBLOCK = 0x0800, ///< Non-blocking I/O
};

/**
 * @brief Standard file permissions (POSIX-compatible)
 */
enum bcpl_file_perms {
  BCPL_S_IRUSR = 0400, ///< User read
  BCPL_S_IWUSR = 0200, ///< User write
  BCPL_S_IXUSR = 0100, ///< User execute
  BCPL_S_IRGRP = 0040, ///< Group read
  BCPL_S_IWGRP = 0020, ///< Group write
  BCPL_S_IXGRP = 0010, ///< Group execute
  BCPL_S_IROTH = 0004, ///< Other read
  BCPL_S_IWOTH = 0002, ///< Other write
  BCPL_S_IXOTH = 0001, ///< Other execute
  BCPL_S_IRWXU = 0700, ///< User all
  BCPL_S_IRWXG = 0070, ///< Group all
  BCPL_S_IRWXO = 0007, ///< Other all
};

/**
 * @brief Seek operations
 */
enum bcpl_seek {
  BCPL_SEEK_SET = 0, ///< Seek from beginning
  BCPL_SEEK_CUR = 1, ///< Seek from current position
  BCPL_SEEK_END = 2, ///< Seek from end
};

// =============================================================================
// MEMORY MAPPING
// =============================================================================

/**
 * @brief Memory protection flags
 */
enum bcpl_mmap_prot {
  BCPL_PROT_NONE = 0,  ///< No access
  BCPL_PROT_READ = 1,  ///< Read access
  BCPL_PROT_WRITE = 2, ///< Write access
  BCPL_PROT_EXEC = 4,  ///< Execute access
};

/**
 * @brief Memory mapping flags
 */
enum bcpl_mmap_flags {
  BCPL_MAP_PRIVATE = 2,    ///< Private mapping
  BCPL_MAP_ANONYMOUS = 32, ///< Anonymous mapping
};

// =============================================================================
// STANDARD I/O FILE DESCRIPTORS
// =============================================================================

enum bcpl_std_fd {
  BCPL_STDIN_FD = 0,  ///< Standard input
  BCPL_STDOUT_FD = 1, ///< Standard output
  BCPL_STDERR_FD = 2, ///< Standard error
};

// =============================================================================
// PLATFORM-SPECIFIC IMPLEMENTATIONS
// =============================================================================

#if defined(BCPL_PLATFORM_MACOS)
#include "platform/macos.h"
#endif

// =============================================================================
// UNIFIED PLATFORM INTERFACE
// =============================================================================

/**
 * @brief Initialize platform-specific subsystems
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_platform_init(void);

/**
 * @brief Cleanup platform-specific subsystems
 */
BCPL_EXPORT void bcpl_platform_cleanup(void);

/**
 * @brief Get platform information string
 * @return Platform description string
 */
BCPL_EXPORT const char *bcpl_platform_info(void);

/**
 * @brief Get platform-specific implementation
 */
BCPL_EXPORT const bcpl_platform_t *bcpl_get_platform(void);

/**
 * @brief Get page size for memory allocation
 * @return Page size in bytes
 */
BCPL_EXPORT size_t bcpl_platform_pagesize(void);

/**
 * @brief Get system endianness
 * @return true if big-endian, false if little-endian
 */
BCPL_EXPORT bool bcpl_platform_is_big_endian(void);

/**
 * @brief Get high-resolution timestamp
 * @return Timestamp in nanoseconds since epoch
 */
BCPL_EXPORT uint64_t bcpl_platform_timestamp(void);

/**
 * @brief Sleep for specified microseconds
 * @param microseconds Sleep duration
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_platform_usleep(uint32_t microseconds);

// =============================================================================
// ERROR HANDLING
// =============================================================================

/**
 * @brief Get last system error code
 * @return System-specific error code
 */
BCPL_EXPORT int bcpl_platform_errno(void);

/**
 * @brief Get error message for error code
 * @param error_code System error code
 * @return Error message string
 */
BCPL_EXPORT const char *bcpl_platform_strerror(int error_code);

/**
 * @brief Convert system error to BCPL error
 * @param sys_error System error code
 * @return BCPL error code
 */
BCPL_EXPORT int bcpl_platform_error_convert(int sys_error);

// =============================================================================
// ATOMIC OPERATIONS (for thread safety)
// =============================================================================

/**
 * @brief Atomic increment
 * @param ptr Pointer to value
 * @return New value after increment
 */
BCPL_ALWAYS_INLINE bcpl_word_t bcpl_atomic_inc(volatile bcpl_word_t *ptr) {
#if defined(__GNUC__) || defined(__clang__)
  return __sync_add_and_fetch(ptr, 1);
#else
  return ++(*ptr); // Non-atomic fallback
#endif
}

/**
 * @brief Atomic decrement
 * @param ptr Pointer to value
 * @return New value after decrement
 */
BCPL_ALWAYS_INLINE bcpl_word_t bcpl_atomic_dec(volatile bcpl_word_t *ptr) {
#if defined(__GNUC__) || defined(__clang__)
  return __sync_sub_and_fetch(ptr, 1);
#else
  return --(*ptr); // Non-atomic fallback
#endif
}

/**
 * @brief Atomic compare and swap
 * @param ptr Pointer to value
 * @param expected Expected current value
 * @param desired Desired new value
 * @return true if swap occurred, false otherwise
 */
BCPL_ALWAYS_INLINE bool bcpl_atomic_cas(volatile bcpl_word_t *ptr,
                                        bcpl_word_t expected,
                                        bcpl_word_t desired) {
#if defined(__GNUC__) || defined(__clang__)
  return __sync_bool_compare_and_swap(ptr, expected, desired);
#else
  if (*ptr == expected) {
    *ptr = desired;
    return true;
  }
  return false; // Non-atomic fallback
#endif
}

// =============================================================================
// MEMORY BARRIERS
// =============================================================================

/**
 * @brief Full memory barrier
 */
BCPL_ALWAYS_INLINE void bcpl_memory_barrier(void) {
#if defined(__GNUC__) || defined(__clang__)
  __sync_synchronize();
#else
  // No-op fallback
#endif
}

/**
 * @brief Compiler barrier (prevent reordering)
 */
BCPL_ALWAYS_INLINE void bcpl_compiler_barrier(void) {
#if defined(__GNUC__) || defined(__clang__)
  __asm__ __volatile__("" ::: "memory");
#else
  // No-op fallback
#endif
}

// =============================================================================
// STACK OPERATIONS
// =============================================================================

/**
 * @brief Get current stack pointer
 * @return Current stack pointer value
 */
BCPL_EXPORT void *bcpl_get_stack_pointer(void);

/**
 * @brief Check if address is on current stack
 * @param addr Address to check
 * @return true if on stack, false otherwise
 */
BCPL_EXPORT bool bcpl_is_on_stack(void *addr);

/**
 * @brief Get stack size limit
 * @return Stack size in bytes, or 0 if unknown
 */
BCPL_EXPORT size_t bcpl_get_stack_size(void);

/**
 * @brief Read a character from file descriptor
 */
BCPL_EXPORT int platform_read_char(int fd);

/**
 * @brief Write a character to file descriptor
 */
BCPL_EXPORT int platform_write_char(int fd, int ch);

#ifdef __cplusplus
}
#endif

#endif /* BCPL_PLATFORM_H */
