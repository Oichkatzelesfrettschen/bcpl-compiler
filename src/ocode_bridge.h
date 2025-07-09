/**
 * @file ocode_bridge.h
 * @brief Compatibility bridge between legacy and 64-bit OCODE systems
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 *
 * This header provides a compatibility layer that allows existing code to work
 * with both the legacy OCODE system and the new 64-bit OCODE system. The
 * appropriate implementation is selected at build time based on the target
 * architecture.
 */

/**
 * @file ocode_bridge.h
 * @brief Compatibility bridge between legacy and 64-bit OCODE systems
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 *
 * This header provides a compatibility layer that allows existing code to work
 * with both the legacy OCODE system and the new 64-bit OCODE system. The
 * appropriate implementation is selected at build time based on the target
 * architecture.
 */

#ifndef OCODE_BRIDGE_H
#define OCODE_BRIDGE_H

#include <stdbool.h>
#include <stdint.h>

// Always include the legacy OCODE header for compatibility
#include "oc.h"

// Conditionally include 64-bit OCODE for 64-bit builds
#if defined(BCPL_USE_64BIT_OCODE) && BCPL_USE_64BIT_OCODE == 1
#include "ocode_64bit.h"
#define OCODE_64BIT_AVAILABLE 1
#else
#define OCODE_64BIT_AVAILABLE 0
#endif

// =============================================================================
// COMPATIBILITY TYPES AND MACROS
// =============================================================================

#if OCODE_64BIT_AVAILABLE
// Use 64-bit native types when available
typedef bcpl_word_t ocode_word_t;
typedef bcpl_uword_t ocode_uword_t;
typedef ocode_context_64_t ocode_context_t;
typedef enum ocode_op_64 ocode_op_t;
typedef ocode_attr_64_t ocode_attr_t;

// Extended operation codes available in 64-bit mode
#define OCODE_MULT64_AVAILABLE 1
#define OCODE_PTR_ARITHMETIC_AVAILABLE 1
#define OCODE_ATOMIC_AVAILABLE 1
#define OCODE_VECTOR_AVAILABLE 1
#define OCODE_MEMORY_MANAGEMENT_AVAILABLE 1

#else
// Use legacy 32-bit types for compatibility
typedef int32_t ocode_word_t;
typedef uint32_t ocode_uword_t;
typedef int ocode_op_t; // Legacy OCODE uses plain int

// No extended operations in legacy mode
#define OCODE_MULT64_AVAILABLE 0
#define OCODE_PTR_ARITHMETIC_AVAILABLE 0
#define OCODE_ATOMIC_AVAILABLE 0
#define OCODE_VECTOR_AVAILABLE 0
#define OCODE_MEMORY_MANAGEMENT_AVAILABLE 0

// Legacy attribute structure (simplified)
typedef struct {
  int operands;   // Number of operands
  int results;    // Number of results
  int precedence; // Operation precedence
  int flags;      // Operation flags
} ocode_attr_t;

// Minimal context for legacy mode
typedef struct {
  void *legacy_data;
} ocode_context_t;

#endif

// =============================================================================
// UNIFIED API FUNCTIONS
// =============================================================================

/**
 * @brief Initialize OCODE context for the appropriate implementation
 * @param ctx Context to initialize
 * @param initial_capacity Initial capacity hint (ignored in legacy mode)
 * @return true on success, false on failure
 */
static inline bool ocode_init_context(ocode_context_t *ctx,
                                      size_t initial_capacity) {
#if OCODE_64BIT_AVAILABLE
  return ocode_context_64_init(ctx, initial_capacity);
#else
  (void)initial_capacity; // Suppress unused parameter warning
  if (ctx) {
    ctx->legacy_data = NULL;
    return true;
  }
  return false;
#endif
}

/**
 * @brief Clean up OCODE context
 * @param ctx Context to clean up
 */
static inline void ocode_cleanup_context(ocode_context_t *ctx) {
#if OCODE_64BIT_AVAILABLE
  ocode_context_64_cleanup(ctx);
#else
  if (ctx) {
    ctx->legacy_data = NULL;
  }
#endif
}

/**
 * @brief Get operation attributes for a given OCODE operation
 * @param op Operation code
 * @return Operation attributes, or NULL for invalid operations
 */
static inline const ocode_attr_t *ocode_get_attributes(ocode_op_t op) {
#if OCODE_64BIT_AVAILABLE
  return ocode_get_op_attributes_64(op);
#else
  // Legacy mode: provide minimal attributes
  static ocode_attr_t legacy_attr = {0, 0, 0, 0};

  // Basic operation validation
  if (op < 0 || op >= 300) { // Legacy OCODE has ~300 operations
    return NULL;
  }

  // Set basic attributes based on operation
  legacy_attr.operands = 1; // Default assumption
  legacy_attr.results = 1;
  legacy_attr.precedence = 5;
  legacy_attr.flags = 0;

  return &legacy_attr;
#endif
}

/**
 * @brief Check if an operation is available in the current build
 * @param op Operation code to check
 * @return true if operation is supported, false otherwise
 */
static inline bool ocode_is_operation_available(ocode_op_t op) {
#if OCODE_64BIT_AVAILABLE
  return ocode_is_valid_operation_64(op);
#else
  // Legacy mode: check against basic OCODE range
  return (op >= 0 && op < 300);
#endif
}

/**
 * @brief Get the native word size for the current OCODE implementation
 * @return Word size in bytes (4 for legacy, 8 for 64-bit)
 */
static inline size_t ocode_get_word_size(void) {
#if OCODE_64BIT_AVAILABLE
  return 8; // 64-bit words
#else
  return 4; // 32-bit words
#endif
}

/**
 * @brief Check if 64-bit OCODE features are available
 * @return true if 64-bit OCODE is enabled, false for legacy mode
 */
static inline bool ocode_has_64bit_features(void) {
  return OCODE_64BIT_AVAILABLE;
}

// =============================================================================
// OPERATION COMPATIBILITY MACROS
// =============================================================================

// Define operation codes that exist in both systems
#define OCODE_OP_TRUE OCODE_TRUE
#define OCODE_OP_FALSE OCODE_FALSE
#define OCODE_OP_RV OCODE_RV
#define OCODE_OP_FNAP OCODE_FNAP
#define OCODE_OP_MULT OCODE_MULT
#define OCODE_OP_DIV OCODE_DIV
#define OCODE_OP_REM OCODE_REM
#define OCODE_OP_PLUS OCODE_PLUS
#define OCODE_OP_MINUS OCODE_MINUS
#define OCODE_OP_NEG OCODE_NEG
#define OCODE_OP_ABS OCODE_ABS
#define OCODE_OP_EQ OCODE_EQ
#define OCODE_OP_NE OCODE_NE
#define OCODE_OP_LS OCODE_LS
#define OCODE_OP_GR OCODE_GR
#define OCODE_OP_LE OCODE_LE
#define OCODE_OP_GE OCODE_GE
#define OCODE_OP_NOT OCODE_NOT
#define OCODE_OP_LSHIFT OCODE_LSHIFT
#define OCODE_OP_RSHIFT OCODE_RSHIFT
#define OCODE_OP_LOGAND OCODE_LOGAND
#define OCODE_OP_LOGOR OCODE_LOGOR
#define OCODE_OP_EQV OCODE_EQV
#define OCODE_OP_NEQV OCODE_NEQV

// Extended operations only available in 64-bit mode
#if OCODE_64BIT_AVAILABLE
#define OCODE_OP_MULT64 OCODE_MULT64
#define OCODE_OP_DIV64 OCODE_DIV64
#define OCODE_OP_LSHIFT64 OCODE_LSHIFT64
#define OCODE_OP_RSHIFT64 OCODE_RSHIFT64
#define OCODE_OP_LOAD_PTR64 OCODE_LOAD_PTR64
#define OCODE_OP_STORE_PTR64 OCODE_STORE_PTR64
#define OCODE_OP_PTR_ADD OCODE_PTR_ADD
#define OCODE_OP_PTR_SUB OCODE_PTR_SUB
#define OCODE_OP_PTR_DIFF OCODE_PTR_DIFF
#endif

// =============================================================================
// DEBUGGING AND DIAGNOSTICS
// =============================================================================

/**
 * @brief Get a string description of the current OCODE implementation
 * @return Human-readable description
 */
static inline const char *ocode_get_implementation_name(void) {
#if OCODE_64BIT_AVAILABLE
  return "64-bit Native OCODE";
#else
  return "Legacy 32-bit OCODE";
#endif
}

/**
 * @brief Get version information for the OCODE implementation
 * @return Version string
 */
static inline const char *ocode_get_version(void) {
#if OCODE_64BIT_AVAILABLE
  return "2025.1.0-64bit";
#else
  return "Legacy";
#endif
}

#endif // OCODE_BRIDGE_H
