/**
 * @file bcpl_types.h
 * @brief Core BCPL data types and constants for C23 implementation
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This header defines the fundamental data types, constants, and structures
 * used throughout the modernized BCPL compiler runtime system. It provides
 * a portable C23 foundation for the BCPL runtime environment.
 *
 * ## Design Principles
 * - **Portability**: Works across all major platforms (Linux, macOS, Windows,
 * FreeBSD)
 * - **Performance**: Optimized for modern architectures (x86, x86_64, ARM64)
 * - **Safety**: Uses C23 features for enhanced type safety
 * - **Compatibility**: Maintains ABI compatibility with existing BCPL code
 *
 * ## Architecture Support
 * - **16-bit**: Legacy 8086/8088 support via MASM
 * - **32-bit**: i386+ with full feature set
 * - **64-bit**: Native x86_64 and ARM64 support
 */

#ifndef BCPL_TYPES_H
#define BCPL_TYPES_H

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <stdatomic.h>

// C23 feature detection and compatibility
#if __STDC_VERSION__ >= 202311L
#define BCPL_HAS_C23 1
#define BCPL_TYPEOF typeof
#define BCPL_BITINT _BitInt
#else
#define BCPL_HAS_C23 0
#define BCPL_TYPEOF __typeof__
#define BCPL_BITINT long long
#endif

// Compiler-specific attributes
#ifdef __clang__
#define BCPL_ALWAYS_INLINE __attribute__((always_inline)) inline
#define BCPL_NOINLINE __attribute__((noinline))
#define BCPL_PURE __attribute__((pure))
#define BCPL_CONST __attribute__((const))
#define BCPL_HOT __attribute__((hot))
#define BCPL_COLD __attribute__((cold))
#define BCPL_LIKELY(x) __builtin_expect(!!(x), 1)
#define BCPL_UNLIKELY(x) __builtin_expect(!!(x), 0)
#elif defined(__GNUC__)
#define BCPL_ALWAYS_INLINE __attribute__((always_inline)) inline
#define BCPL_NOINLINE __attribute__((noinline))
#define BCPL_PURE __attribute__((pure))
#define BCPL_CONST __attribute__((const))
#define BCPL_HOT __attribute__((hot))
#define BCPL_COLD __attribute__((cold))
#define BCPL_LIKELY(x) __builtin_expect(!!(x), 1)
#define BCPL_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define BCPL_ALWAYS_INLINE inline
#define BCPL_NOINLINE
#define BCPL_PURE
#define BCPL_CONST
#define BCPL_HOT
#define BCPL_COLD
#define BCPL_LIKELY(x) (x)
#define BCPL_UNLIKELY(x) (x)
#endif

// Platform detection
#if defined(__linux__)
#define BCPL_PLATFORM_LINUX 1
#define BCPL_PLATFORM_NAME "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
#define BCPL_PLATFORM_MACOS 1
#define BCPL_PLATFORM_NAME "macOS"
#elif defined(__FreeBSD__)
#define BCPL_PLATFORM_FREEBSD 1
#define BCPL_PLATFORM_NAME "FreeBSD"
#elif defined(_WIN32) || defined(_WIN64)
#define BCPL_PLATFORM_WINDOWS 1
#define BCPL_PLATFORM_NAME "Windows"
#else
#define BCPL_PLATFORM_UNKNOWN 1
#define BCPL_PLATFORM_NAME "Unknown"
#endif

// Architecture detection
#if defined(__x86_64__) || defined(_M_X64)
#define BCPL_ARCH_X86_64 1
#define BCPL_ARCH_BITS 64
#define BCPL_ARCH_NAME "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
#define BCPL_ARCH_X86_32 1
#define BCPL_ARCH_BITS 32
#define BCPL_ARCH_NAME "i386"
#elif defined(__aarch64__) || defined(_M_ARM64)
#define BCPL_ARCH_ARM64 1
#define BCPL_ARCH_BITS 64
#define BCPL_ARCH_NAME "ARM64"
#elif defined(__arm__) || defined(_M_ARM)
#define BCPL_ARCH_ARM32 1
#define BCPL_ARCH_BITS 32
#define BCPL_ARCH_NAME "ARM32"
#else
#define BCPL_ARCH_UNKNOWN 1
#define BCPL_ARCH_BITS 32
#define BCPL_ARCH_NAME "Unknown"
#endif

/**
 * @brief BCPL word type
 *
 * The fundamental BCPL data type. Traditionally 32 bits, but can be
 * configured for different architectures.
 */
#if BCPL_ARCH_BITS == 64
typedef uint64_t bcpl_word_t;
typedef int64_t bcpl_sword_t;
#define BCPL_WORD_SIZE 8
#define BCPL_WORD_BITS 64
#else
typedef uint32_t bcpl_word_t;
typedef int32_t bcpl_sword_t;
#define BCPL_WORD_SIZE 4
#define BCPL_WORD_BITS 32
#endif

/**
 * @brief BCPL boolean type
 */
typedef bool bcpl_bool_t;
#define BCPL_TRUE true
#define BCPL_FALSE false

/**
 * @brief BCPL character type
 */
typedef uint8_t bcpl_char_t;

/**
 * @brief BCPL string length type
 */
typedef uint32_t bcpl_strlen_t;

/**
 * @brief BCPL global vector index type
 */
typedef uint32_t bcpl_global_t;

/**
 * @brief BCPL function pointer type
 */
typedef bcpl_word_t (*bcpl_function_t)(bcpl_word_t *args);

/**
 * @brief Runtime configuration constants
 */
enum bcpl_constants {
  BCPL_STKSIZ = 0x400000,   ///< BCPL stack size (4MB)
  BCPL_PGSZ = 4096,         ///< Page size for memory allocation
  BCPL_FCBCNT = 8,          ///< Number of file control blocks
  BCPL_BUFSIZ = 512,        ///< I/O buffer size
  BCPL_STRSIZ = 256,        ///< BCPL string size limit
  BCPL_FCBSIZ = 20,         ///< File control block size
  BCPL_GLOBVEC_SIZE = 1000, ///< Default global vector size
  BCPL_ENDSTREAMCH = -1,    ///< End of stream character
  BCPL_MAX_VECTOR_SIZE = 1000000, ///< Maximum vector size
  BCPL_VECTOR_MAGIC = 0x42434056,  ///< Magic number for vectors ('BCPV')
};

/**
 * @brief Standard global vector slot assignments
 */
enum bcpl_globals {
  BCPL_G_START = 1,         ///< Entry point function
  BCPL_G_SELECTINPUT = 11,  ///< Select input stream
  BCPL_G_SELECTOUTPUT = 12, ///< Select output stream
  BCPL_G_RDCH = 13,         ///< Read character
  BCPL_G_WRCH = 14,         ///< Write character
  BCPL_G_UNRDCH = 15,       ///< Unread character
  BCPL_G_INPUT = 16,        ///< Input stream
  BCPL_G_OUTPUT = 17,       ///< Output stream
  BCPL_G_STOP = 30,         ///< Stop execution
  BCPL_G_LEVEL = 31,        ///< Exception level
  BCPL_G_LONGJUMP = 32,     ///< Long jump
  BCPL_G_GETVEC = 87,       ///< Allocate vector
  BCPL_G_FREEVEC = 88,      ///< Free vector
  BCPL_G_STACKBASE = 95,    ///< Base of BCPL stack
  BCPL_G_STACKEND = 96,     ///< End of BCPL stack
  BCPL_G_ARGC = 97,         ///< Command line argument count
  BCPL_G_ARGV = 98,         ///< Command line argument vector
  BCPL_G_PARAM = 99,        ///< Parameter string
};

/**
 * @brief File operation modes
 */
enum bcpl_file_mode {
  BCPL_MODE_READ = 0,
  BCPL_MODE_WRITE = 1,
  BCPL_MODE_APPEND = 2,
};

/**
 * @brief Error codes
 */
enum bcpl_error {
  BCPL_OK = 0,
  BCPL_ERROR_NOMEM = -1,
  BCPL_ERROR_NOFILE = -2,
  BCPL_ERROR_IO = -3,
  BCPL_ERROR_INVAL = -4,
  BCPL_ERROR_PERM = -5,
};

/**
 * @brief BCPL vector structure
 *
 * Represents a BCPL vector with reference counting for automatic
 * memory management.
 */
typedef struct bcpl_vector {
  bcpl_word_t magic;    ///< Magic number for validation
  bcpl_word_t size;     ///< Vector size in words
  bcpl_word_t refcount; ///< Reference count
  bcpl_word_t data[];   ///< Vector data
} bcpl_vector_t;

/**
 * @brief BCPL string structure
 *
 * BCPL strings with length prefix and null termination for C interop.
 */
typedef struct bcpl_string {
  bcpl_strlen_t length; ///< String length (excluding null terminator)
  bcpl_char_t data[];   ///< String data (null-terminated)
} bcpl_string_t;

/**
 * @brief File control block structure
 */
typedef struct bcpl_fcb {
  int status;                      ///< FCB status (FREE, INPUT, OUTPUT, ERROR)
  int fd;                          ///< System file descriptor
  int pos;                         ///< Current position in buffer
  int count;                       ///< Number of valid bytes in buffer
  int error;                       ///< Error code (0 = no error)
  char buffer[BCPL_BUFSIZ];        ///< I/O buffer
  char *filename;                  ///< Associated filename (for error reporting)
} bcpl_fcb_t;

/**
 * @brief BCPL runtime context structure
 *
 * Maintains the complete runtime state for a BCPL program.
 */
typedef struct bcpl_context {
  bcpl_word_t *global_vector;      ///< Global vector
  size_t global_size;              ///< Global vector size  
  bcpl_word_t *stack_base;         ///< BCPL stack base
  bcpl_word_t *stack_end;          ///< BCPL stack end
  bcpl_word_t *stack_pointer;      ///< Current stack pointer
  size_t stack_size;               ///< Stack size in words
  int argc;                        ///< Command line argument count
  char **argv;                     ///< Command line arguments
  char *param_string;              ///< Parameter string
  jmp_buf error_context;           ///< Error handling context
  atomic_int initialized;          ///< Thread-safe initialization flag
  bcpl_fcb_t *fcb_table;           ///< File control block table
  bcpl_word_t current_input;       ///< Current input stream
  bcpl_word_t current_output;      ///< Current output stream
  void *heap_base;                 ///< Heap base pointer
  size_t heap_size;                ///< Current heap size
} bcpl_context_t;

/**
 * @brief Platform-specific system call interface
 */
typedef struct bcpl_platform {
  const char *name; ///< Platform name

  // File operations
  int (*sys_open)(const char *path, int flags, int mode);
  int (*sys_close)(int fd);
  long (*sys_read)(int fd, void *buf, size_t count);
  long (*sys_write)(int fd, const void *buf, size_t count);
  long (*sys_lseek)(int fd, long offset, int whence);

  // Memory operations
  void *(*sys_sbrk)(long increment);
  void *(*sys_mmap)(void *addr, size_t length, int prot, int flags, int fd,
                    long offset);
  int (*sys_munmap)(void *addr, size_t length);

  // Process operations
  void (*sys_exit)(int status) __attribute__((noreturn));
  int (*sys_getpid)(void);

  // Time operations
  long (*sys_time)(long *tloc);
} bcpl_platform_t;

// Function declaration macros
#define BCPL_EXPORT __attribute__((visibility("default")))
#define BCPL_INTERNAL __attribute__((visibility("hidden")))

// Alignment macros
#define BCPL_ALIGN_WORD __attribute__((aligned(BCPL_WORD_SIZE)))
#define BCPL_ALIGN_CACHE __attribute__((aligned(64)))

// Utility macros
#define BCPL_ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define BCPL_MIN(a, b) ((a) < (b) ? (a) : (b))
#define BCPL_MAX(a, b) ((a) > (b) ? (a) : (b))
#define BCPL_CLAMP(x, min, max) BCPL_MIN(BCPL_MAX(x, min), max)

// Word manipulation macros
#define BCPL_WORD_TO_PTR(w) ((void *)(uintptr_t)(w))
#define BCPL_PTR_TO_WORD(p) ((bcpl_word_t)(uintptr_t)(p))
#define BCPL_WORDS_TO_BYTES(w) ((w) * BCPL_WORD_SIZE)
#define BCPL_BYTES_TO_WORDS(b) (((b) + BCPL_WORD_SIZE - 1) / BCPL_WORD_SIZE)

#endif /* BCPL_TYPES_H */
