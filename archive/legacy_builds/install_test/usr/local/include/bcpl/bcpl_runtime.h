/**
 * @file bcpl_runtime.h
 * @brief BCPL runtime system interface declarations
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This header provides the public interface to the modernized BCPL runtime
 * system. It includes declarations for all runtime functions that were
 * previously implemented in assembly language.
 *
 * ## Key Features
 * - **Memory Management**: Vector allocation and deallocation
 * - **I/O Operations**: Character and stream-based I/O
 * - **String Operations**: String manipulation and conversion
 * - **File Operations**: File handling and buffered I/O
 * - **Platform Abstraction**: Cross-platform system interfaces
 *
 * ## Migration Status
 * This header represents the C23 modernization of the original BCPL
 * runtime system, providing enhanced type safety, better performance,
 * and cross-platform compatibility while maintaining full ABI
 * compatibility with existing BCPL programs.
 */

#ifndef BCPL_RUNTIME_H
#define BCPL_RUNTIME_H

#include "bcpl_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// =============================================================================
// INITIALIZATION AND CLEANUP
// =============================================================================

/**
 * @brief Initialize the BCPL runtime system
 * @param argc Command line argument count
 * @param argv Command line argument vector
 * @param envp Environment variables (may be NULL)
 * @return Pointer to initialized BCPL context, or NULL on failure
 *
 * This function initializes the BCPL runtime environment, setting up:
 * - Global vector with standard functions
 * - BCPL stack separate from system stack
 * - Memory management system
 * - File I/O system
 * - Platform-specific interfaces
 */
BCPL_EXPORT bcpl_context_t *bcpl_init(int argc, char *argv[], char *envp[]);

/**
 * @brief Cleanup and shutdown the BCPL runtime system
 * @param ctx BCPL context to cleanup
 *
 * Performs orderly shutdown of the runtime system, including:
 * - Closing all open files
 * - Freeing all allocated memory
 * - Restoring system state
 */
BCPL_EXPORT void bcpl_cleanup(bcpl_context_t *ctx);

/**
 * @brief Get the current BCPL runtime context
 * @return Current context pointer, or NULL if not initialized
 */
BCPL_EXPORT bcpl_context_t *bcpl_get_context(void);

// =============================================================================
// MEMORY MANAGEMENT
// =============================================================================

/**
 * @brief Allocate a BCPL vector
 * @param size Vector size in words
 * @return Pointer to allocated vector, or NULL on failure
 *
 * Allocates a BCPL vector with the specified size. The vector includes
 * metadata for size and reference counting.
 */
BCPL_EXPORT bcpl_vector_t *bcpl_getvec(bcpl_word_t size);

/**
 * @brief Free a BCPL vector
 * @param vec Vector to free (may be NULL)
 *
 * Decrements the reference count and frees the vector if the count
 * reaches zero. Safe to call with NULL pointer.
 */
BCPL_EXPORT void bcpl_freevec(bcpl_vector_t *vec);

/**
 * @brief Increase reference count of a vector
 * @param vec Vector to reference
 * @return The same vector pointer for convenience
 */
BCPL_EXPORT bcpl_vector_t *bcpl_addref(bcpl_vector_t *vec);

/**
 * @brief Get vector data pointer
 * @param vec Vector
 * @return Pointer to vector data, or NULL if vec is NULL
 */
BCPL_ALWAYS_INLINE bcpl_word_t *bcpl_vector_data(bcpl_vector_t *vec) {
  return vec ? vec->data : NULL;
}

/**
 * @brief Get vector size
 * @param vec Vector
 * @return Vector size in words, or 0 if vec is NULL
 */
BCPL_ALWAYS_INLINE bcpl_word_t bcpl_vector_size(bcpl_vector_t *vec) {
  return vec ? vec->size : 0;
}

// =============================================================================
// STRING OPERATIONS
// =============================================================================

/**
 * @brief Create a BCPL string from C string
 * @param cstr C string (null-terminated)
 * @return BCPL string, or NULL on failure
 */
BCPL_EXPORT bcpl_string_t *bcpl_string_from_cstr(const char *cstr);

/**
 * @brief Create a BCPL string with specified length
 * @param data Character data
 * @param length String length
 * @return BCPL string, or NULL on failure
 */
BCPL_EXPORT bcpl_string_t *bcpl_string_from_data(const bcpl_char_t *data,
                                                 bcpl_strlen_t length);

/**
 * @brief Free a BCPL string
 * @param str String to free (may be NULL)
 */
BCPL_EXPORT void bcpl_string_free(bcpl_string_t *str);

/**
 * @brief Get C string representation
 * @param str BCPL string
 * @return C string (null-terminated), or NULL if str is NULL
 * @note The returned pointer is valid until the string is freed
 */
BCPL_ALWAYS_INLINE const char *bcpl_string_cstr(bcpl_string_t *str) {
  return str ? (const char *)str->data : NULL;
}

/**
 * @brief Pack a BCPL string into a vector
 * @param str Source string
 * @param vec Destination vector
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_packstring(bcpl_string_t *str, bcpl_vector_t *vec);

/**
 * @brief Unpack a BCPL string from a vector
 * @param vec Source vector
 * @return Unpacked string, or NULL on failure
 */
BCPL_EXPORT bcpl_string_t *bcpl_unpackstring(bcpl_vector_t *vec);

// =============================================================================
// CHARACTER I/O
// =============================================================================

/**
 * @brief Read a character from current input
 * @return Character read, or BCPL_ENDSTREAMCH on EOF/error
 */
BCPL_EXPORT int bcpl_rdch(void);

/**
 * @brief Write a character to current output
 * @param ch Character to write
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_wrch(int ch);

/**
 * @brief Unread a character (push back to input)
 * @param ch Character to unread
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_unrdch(int ch);

/**
 * @brief Select input stream
 * @param stream Stream identifier
 * @return Previous input stream
 */
BCPL_EXPORT bcpl_word_t bcpl_selectinput(bcpl_word_t stream);

/**
 * @brief Select output stream
 * @param stream Stream identifier
 * @return Previous output stream
 */
BCPL_EXPORT bcpl_word_t bcpl_selectoutput(bcpl_word_t stream);

// =============================================================================
// FILE OPERATIONS
// =============================================================================

/**
 * @brief Find and open input file
 * @param name File name
 * @return File handle, or 0 on failure
 */
BCPL_EXPORT bcpl_word_t bcpl_findinput(bcpl_string_t *name);

/**
 * @brief Find and open output file
 * @param name File name
 * @return File handle, or 0 on failure
 */
BCPL_EXPORT bcpl_word_t bcpl_findoutput(bcpl_string_t *name);

/**
 * @brief Close input file
 * @param stream Stream to close
 */
BCPL_EXPORT void bcpl_endread(bcpl_word_t stream);

/**
 * @brief Close output file
 * @param stream Stream to close
 */
BCPL_EXPORT void bcpl_endwrite(bcpl_word_t stream);

/**
 * @brief Rewind a file stream
 * @param stream Stream to rewind
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_rewind(bcpl_word_t stream);

// =============================================================================
// BYTE OPERATIONS
// =============================================================================

/**
 * @brief Get byte from vector
 * @param vec Vector
 * @param index Byte index
 * @return Byte value, or 0 if out of bounds
 */
BCPL_EXPORT bcpl_char_t bcpl_getbyte(bcpl_vector_t *vec, bcpl_word_t index);

/**
 * @brief Put byte into vector
 * @param vec Vector
 * @param index Byte index
 * @param value Byte value
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_putbyte(bcpl_vector_t *vec, bcpl_word_t index,
                             bcpl_char_t value);

// =============================================================================
// FORMATTED OUTPUT
// =============================================================================

/**
 * @brief Write string to current output
 * @param str String to write
 */
BCPL_EXPORT void bcpl_writes(bcpl_string_t *str);

/**
 * @brief Write integer in decimal format
 * @param value Integer value
 * @param width Minimum field width (0 for no padding)
 */
BCPL_EXPORT void bcpl_writed(bcpl_sword_t value, int width);

/**
 * @brief Write integer in hexadecimal format
 * @param value Integer value
 * @param width Minimum field width (0 for no padding)
 */
BCPL_EXPORT void bcpl_writehex(bcpl_word_t value, int width);

/**
 * @brief Write newline character
 */
BCPL_EXPORT void bcpl_newline(void);

/**
 * @brief Write form feed character
 */
BCPL_EXPORT void bcpl_newpage(void);

/**
 * @brief Formatted write (printf-style)
 * @param format Format string
 * @param ... Arguments
 * @return Number of characters written, or negative on error
 */
BCPL_EXPORT int bcpl_writef(const char *format, ...);

// =============================================================================
// FORMATTED INPUT
// =============================================================================

/**
 * @brief Read integer in decimal format
 * @return Integer value read, or 0 on error
 */
BCPL_EXPORT bcpl_sword_t bcpl_readn(void);

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Convert character to uppercase
 * @param ch Character to convert
 * @return Uppercase character
 */
BCPL_EXPORT int bcpl_capitalch(int ch);

/**
 * @brief Stop program execution
 * @param code Exit code
 */
BCPL_EXPORT void bcpl_stop(int code) __attribute__((noreturn));

/**
 * @brief Get current exception level
 * @return Current level
 */
BCPL_EXPORT bcpl_word_t bcpl_level(void);

/**
 * @brief Perform long jump to specified level
 * @param level Target level
 * @param value Return value
 */
BCPL_EXPORT void bcpl_longjump(bcpl_word_t level, bcpl_word_t value);

/**
 * @brief Call function with vector argument
 * @param func Function to call
 * @param vec Argument vector
 * @return Function result
 */
BCPL_EXPORT bcpl_word_t bcpl_aptovec(bcpl_function_t func, bcpl_vector_t *vec);

// =============================================================================
// PLATFORM INTERFACE
// =============================================================================

/**
 * @brief Get platform-specific interface
 * @return Platform interface structure
 */
BCPL_EXPORT const bcpl_platform_t *bcpl_get_platform(void);

/**
 * @brief Register custom platform interface
 * @param platform Platform interface to register
 * @return BCPL_OK on success, error code on failure
 */
BCPL_EXPORT int bcpl_register_platform(const bcpl_platform_t *platform);

// =============================================================================
// DEBUGGING AND DIAGNOSTICS
// =============================================================================

/**
 * @brief Print stack trace
 * @param ctx BCPL context (NULL for current)
 */
BCPL_EXPORT void bcpl_backtrace(bcpl_context_t *ctx);

/**
 * @brief Print memory map
 * @param ctx BCPL context (NULL for current)
 */
BCPL_EXPORT void bcpl_mapstore(bcpl_context_t *ctx);

/**
 * @brief Abort with diagnostic message
 * @param message Error message
 * @param code Error code
 */
BCPL_EXPORT void bcpl_abort(const char *message, int code)
    __attribute__((noreturn));

// =============================================================================
// GLOBAL VECTOR MANAGEMENT
// =============================================================================

/**
 * @brief Set global vector entry
 * @param index Global index
 * @param value Value to set
 * @return Previous value
 */
BCPL_EXPORT bcpl_word_t bcpl_setglobal(bcpl_global_t index, bcpl_word_t value);

/**
 * @brief Get global vector entry
 * @param index Global index
 * @return Current value
 */
BCPL_EXPORT bcpl_word_t bcpl_getglobal(bcpl_global_t index);

/**
 * @brief Get pointer to global vector entry
 * @param index Global index
 * @return Pointer to global entry, or NULL if invalid
 */
BCPL_EXPORT bcpl_word_t *bcpl_globalptr(bcpl_global_t index);

#ifdef __cplusplus
}
#endif

#endif /* BCPL_RUNTIME_H */
