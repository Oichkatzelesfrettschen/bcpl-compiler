/**
 * @file ocode_64bit.h
 * @brief Modern 64-bit OCODE definitions and enhancements for native builds
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 *
 * This header provides enhanced OCODE definitions specifically optimized for
 * native 64-bit builds. It extends the original OCODE system with:
 * - 64-bit native pointer arithmetic
 * - Enhanced type safety with C23 features
 * - Modern memory management operations
 * - SIMD-friendly operation groupings
 * - Cache-optimized data structures
 */

/**
 * @file ocode_64bit.h
 * @brief Modern 64-bit OCODE definitions and enhancements for native builds
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 *
 * This header provides enhanced OCODE definitions specifically optimized for
 * native 64-bit builds. It extends the original OCODE system with:
 * - 64-bit native pointer arithmetic
 * - Enhanced type safety with C23 features
 * - Modern memory management operations
 * - SIMD-friendly operation groupings
 * - Cache-optimized data structures
 */

#ifndef OCODE_64BIT_H
#define OCODE_64BIT_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Ensure we're building for 64-bit
#if !defined(BCPL_ARCH_BITS) || BCPL_ARCH_BITS != 64
#error "ocode_64bit.h requires 64-bit build configuration"
#endif

// =============================================================================
// MODERN TYPE DEFINITIONS
// =============================================================================

/**
 * @brief Native 64-bit word type for BCPL values
 *
 * This replaces the legacy 32-bit word assumptions with native 64-bit words,
 * providing better performance and larger address space support.
 */
typedef int64_t bcpl_word_t;
typedef uint64_t bcpl_uword_t;

/**
 * @brief Load stack entry types (compatible with legacy cg.c)
 */
#define X_R 0  /**< Register value */
#define X_P 1  /**< Parameter reference */
#define X_G 2  /**< Global variable reference */
#define X_L 3  /**< Local variable reference */
#define X_N 4  /**< Numeric constant */
#define X_LP 5 /**< Parameter pointer */
#define X_LG 6 /**< Global pointer */
#define X_LL 7 /**< Local pointer */

/**
 * @brief OCODE operation with enhanced type safety
 */
typedef enum ocode_op_64 : uint16_t {
  // Legacy OCODE operations (maintained for compatibility)
  OCODE_TRUE = 4,
  OCODE_FALSE = 5,
  OCODE_RV = 8,
  OCODE_FNAP = 10,
  OCODE_MULT = 11,
  OCODE_DIV = 12,
  OCODE_REM = 13,
  OCODE_PLUS = 14,
  OCODE_MINUS = 15,
  OCODE_QUERY = 16,
  OCODE_NEG = 17,
  OCODE_ABS = 19,
  OCODE_EQ = 20,
  OCODE_NE = 21,
  OCODE_LS = 22,
  OCODE_GR = 23,
  OCODE_LE = 24,
  OCODE_GE = 25,
  OCODE_NOT = 30,
  OCODE_LSHIFT = 31,
  OCODE_RSHIFT = 32,
  OCODE_LOGAND = 33,
  OCODE_LOGOR = 34,
  OCODE_EQV = 35,
  OCODE_NEQV = 36,
  OCODE_COND = 37,
  OCODE_LP = 40,
  OCODE_LG = 41,
  OCODE_LN = 42,
  OCODE_LSTR = 43,
  OCODE_LL = 44,
  OCODE_LLP = 45,
  OCODE_LLG = 46,
  OCODE_LLL = 47,

  // Enhanced 64-bit operations
  OCODE_MULT64 = 200,      ///< 64-bit multiplication with overflow detection
  OCODE_DIV64 = 201,       ///< 64-bit division with remainder
  OCODE_LSHIFT64 = 202,    ///< 64-bit left shift (up to 63 bits)
  OCODE_RSHIFT64 = 203,    ///< 64-bit right shift (arithmetic/logical)
  OCODE_LOAD_PTR64 = 204,  ///< Load 64-bit pointer
  OCODE_STORE_PTR64 = 205, ///< Store 64-bit pointer
  OCODE_PTR_ADD = 206,     ///< Pointer arithmetic addition
  OCODE_PTR_SUB = 207,     ///< Pointer arithmetic subtraction
  OCODE_PTR_DIFF = 208,    ///< Pointer difference calculation

  // Memory management operations
  OCODE_ALLOC = 220,   ///< Allocate memory block
  OCODE_FREE = 221,    ///< Free memory block
  OCODE_REALLOC = 222, ///< Reallocate memory block
  OCODE_MEMCPY = 223,  ///< Memory copy operation
  OCODE_MEMSET = 224,  ///< Memory set operation
  OCODE_MEMMOVE = 225, ///< Memory move operation

  // Vector/SIMD operations (future extension)
  OCODE_VEC_ADD = 240,   ///< Vector addition
  OCODE_VEC_MUL = 241,   ///< Vector multiplication
  OCODE_VEC_LOAD = 242,  ///< Vector load from memory
  OCODE_VEC_STORE = 243, ///< Vector store to memory

  // Atomic operations for concurrent execution
  OCODE_ATOMIC_LOAD = 260,  ///< Atomic load operation
  OCODE_ATOMIC_STORE = 261, ///< Atomic store operation
  OCODE_ATOMIC_ADD = 262,   ///< Atomic add operation
  OCODE_ATOMIC_CAS = 263,   ///< Compare-and-swap operation

  // Debug and profiling operations
  OCODE_DEBUG_BREAK = 280,   ///< Debug breakpoint
  OCODE_PROFILE_BEGIN = 281, ///< Begin profiling block
  OCODE_PROFILE_END = 282,   ///< End profiling block

  OCODE_MAX_64 = 299 ///< Maximum 64-bit OCODE value
} ocode_op_64_t;

// =============================================================================
// ENHANCED OPERATION ATTRIBUTES
// =============================================================================

/**
 * @brief Enhanced operation attributes for 64-bit operations
 */
typedef struct ocode_attr_64 {
  uint8_t stack_pops;    ///< Number of values popped from stack
  uint8_t stack_pushes;  ///< Number of values pushed to stack
  uint8_t register_hint; ///< Register allocation hint
  uint8_t flags;         ///< Operation flags (see OCODE_FLAG_*)

  // 64-bit specific attributes
  uint16_t memory_access_size; ///< Memory access size in bytes (0 if none)
  uint8_t alignment_req;       ///< Required alignment (power of 2)
  uint8_t instruction_count;   ///< Estimated instruction count for scheduling
} ocode_attr_64_t;

// Operation flags
#define OCODE_FLAG_COMMUTATIVE 0x01   ///< Operation is commutative
#define OCODE_FLAG_ASSOCIATIVE 0x02   ///< Operation is associative
#define OCODE_FLAG_SIDE_EFFECT 0x04   ///< Has observable side effects
#define OCODE_FLAG_MEMORY_ACCESS 0x08 ///< Accesses memory
#define OCODE_FLAG_ATOMIC 0x10        ///< Atomic operation
#define OCODE_FLAG_VECTOR 0x20        ///< Vector/SIMD operation
#define OCODE_FLAG_CAN_FAULT 0x40     ///< Can cause CPU fault/exception
#define OCODE_FLAG_TERMINATES 0x80    ///< Terminates basic block

// =============================================================================
// NATIVE 64-BIT OPTIMIZED STRUCTURES
// =============================================================================

/**
 * @brief 64-bit optimized load stack entry
 *
 * Redesigned for 64-bit architectures with cache-line awareness.
 */
typedef struct load_stack_entry_64 {
  union {
    bcpl_word_t value;    ///< Immediate value
    bcpl_word_t *address; ///< Memory address
    struct {
      uint32_t offset; ///< Offset for relative addressing
      uint16_t type;   ///< Entry type (X_R, X_P, X_G, etc.)
      uint16_t flags;  ///< Entry-specific flags
    };
  };

  // Optimization metadata
  uint32_t generation;       ///< Generation counter for dead code elimination
  uint16_t use_count;        ///< Usage count for register allocation
  uint8_t register_assigned; ///< Assigned register number (0 = none)
  uint8_t spill_slot;        ///< Spill slot if register spilled
} load_stack_entry_64_t;

/**
 * @brief Enhanced code generation context for 64-bit
 */
typedef struct ocode_context_64 {
  // Stack management
  load_stack_entry_64_t *load_stack; ///< Load stack entries
  size_t load_stack_size;            ///< Current stack size
  size_t load_stack_capacity;        ///< Maximum stack capacity

  // Register allocation state
  uint64_t registers_used;   ///< Bitmask of used registers
  uint64_t registers_dirty;  ///< Bitmask of dirty registers
  uint32_t spill_slots_used; ///< Bitmask of used spill slots

  // Code generation state
  bcpl_word_t *code_buffer;    ///< Generated code buffer
  size_t code_buffer_size;     ///< Current code size
  size_t code_buffer_capacity; ///< Code buffer capacity

  // Optimization state
  uint32_t current_generation; ///< Current generation counter
  uint32_t basic_block_count;  ///< Number of basic blocks processed

  // Memory management
  struct {
    void *heap_base;         ///< Heap base address
    size_t heap_size;        ///< Current heap size
    size_t heap_capacity;    ///< Maximum heap capacity
    size_t allocation_count; ///< Number of active allocations
  } memory;

  // Performance counters
  struct {
    uint64_t operations_processed;  ///< Total operations processed
    uint64_t instructions_emitted;  ///< Total instructions emitted
    uint64_t optimizations_applied; ///< Optimizations applied
    uint64_t cache_hits;            ///< Register cache hits
    uint64_t cache_misses;          ///< Register cache misses
  } stats;

  // Debug information
  struct {
    const char *current_function; ///< Current function name
    uint32_t line_number;         ///< Current line number
    uint32_t error_count;         ///< Number of errors
    bool debug_mode;              ///< Debug mode enabled
  } debug;

} ocode_context_64_t;

// =============================================================================
// FUNCTION DECLARATIONS
// =============================================================================

/**
 * @brief Initialize 64-bit OCODE context
 * @param ctx Context to initialize
 * @param initial_capacity Initial capacity for buffers
 * @return true on success, false on failure
 */
bool ocode_context_64_init(ocode_context_64_t *ctx, size_t initial_capacity);

/**
 * @brief Cleanup 64-bit OCODE context
 * @param ctx Context to cleanup
 */
void ocode_context_64_cleanup(ocode_context_64_t *ctx);

/**
 * @brief Process 64-bit OCODE operation
 * @param ctx Code generation context
 * @param op Operation to process
 * @return true on success, false on error
 */
bool ocode_64_process_operation(ocode_context_64_t *ctx, ocode_op_64_t op);

/**
 * @brief Get operation attributes for 64-bit operation
 * @param op Operation code
 * @return Pointer to attributes structure
 */
const ocode_attr_64_t *ocode_64_get_attributes(ocode_op_64_t op);

/**
 * @brief Optimize load stack for 64-bit architecture
 * @param ctx Code generation context
 * @return Number of optimizations applied
 */
uint32_t ocode_64_optimize_load_stack(ocode_context_64_t *ctx);

/**
 * @brief Allocate register for value
 * @param ctx Code generation context
 * @param prefer_reg Preferred register (0 = any)
 * @return Allocated register number, 0 if allocation failed
 */
uint8_t ocode_64_allocate_register(ocode_context_64_t *ctx, uint8_t prefer_reg);

/**
 * @brief Free register
 * @param ctx Code generation context
 * @param reg Register to free
 */
void ocode_64_free_register(ocode_context_64_t *ctx, uint8_t reg);

/**
 * @brief Generate optimized 64-bit code sequence
 * @param ctx Code generation context
 * @param operations Array of operations to process
 * @param count Number of operations
 * @return true on success, false on error
 */
bool ocode_64_generate_sequence(ocode_context_64_t *ctx,
                                const ocode_op_64_t *operations, size_t count);

/**
 * @brief Get operation attributes (bridge compatibility)
 * @param op Operation code
 * @return Pointer to attributes structure
 */
const ocode_attr_64_t *ocode_get_op_attributes_64(enum ocode_op_64 op);

/**
 * @brief Check if operation is valid (bridge compatibility)
 * @param op Operation code
 * @return true if valid, false otherwise
 */
bool ocode_is_valid_operation_64(enum ocode_op_64 op);

// =============================================================================
// INLINE UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Check if operation is arithmetic
 */
static inline bool ocode_64_is_arithmetic(ocode_op_64_t op) {
  return (op >= OCODE_MULT && op <= OCODE_MINUS) ||
         (op >= OCODE_MULT64 && op <= OCODE_PTR_DIFF);
}

/**
 * @brief Check if operation accesses memory
 */
static inline bool ocode_64_is_memory_op(ocode_op_64_t op) {
  return (op >= OCODE_ALLOC && op <= OCODE_MEMMOVE) ||
         (op == OCODE_LOAD_PTR64) || (op == OCODE_STORE_PTR64);
}

/**
 * @brief Check if operation is atomic
 */
static inline bool ocode_64_is_atomic(ocode_op_64_t op) {
  return op >= OCODE_ATOMIC_LOAD && op <= OCODE_ATOMIC_CAS;
}

/**
 * @brief Get operation category for optimization grouping
 */
static inline uint8_t ocode_64_get_category(ocode_op_64_t op) {
  if (ocode_64_is_arithmetic(op))
    return 1;
  if (ocode_64_is_memory_op(op))
    return 2;
  if (ocode_64_is_atomic(op))
    return 3;
  if (op >= OCODE_VEC_ADD && op <= OCODE_VEC_STORE)
    return 4;
  return 0; // Control flow or other
}

// =============================================================================
// ARCHITECTURE-SPECIFIC OPTIMIZATIONS
// =============================================================================

#if defined(__x86_64__)
#include "ocode_64bit_x86_64.h"
#elif defined(__aarch64__)
#include "ocode_64bit_aarch64.h"
#elif defined(__riscv) && (__riscv_xlen == 64)
#include "ocode_64bit_riscv64.h"
#else
#include "ocode_64bit_generic.h"
#endif

// =============================================================================
// COMPILE-TIME ASSERTIONS
// =============================================================================

// Ensure our data structures are efficiently sized
static_assert(sizeof(ocode_attr_64_t) == 8,
              "ocode_attr_64_t should be 8 bytes for cache efficiency");
static_assert(sizeof(load_stack_entry_64_t) == 16,
              "load_stack_entry_64_t should be 16 bytes for alignment");
static_assert(sizeof(bcpl_word_t) == 8, "bcpl_word_t must be 64 bits");

// Ensure operation codes fit in our type
static_assert(OCODE_MAX_64 < UINT16_MAX,
              "Operation codes must fit in uint16_t");

#endif // OCODE_64BIT_H
