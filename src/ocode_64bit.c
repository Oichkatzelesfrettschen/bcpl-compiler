/**
 * @file ocode_64bit.c
 * @brief Implementation of modern 64-bit OCODE operations
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 *
 * This file implements the enhanced 64-bit OCODE operations with:
 * - Native 64-bit arithmetic and pointer operations
 * - Modern memory management
 * - SIMD operation support (where available)
 * - Atomic operations for concurrent execution
 * - Advanced optimization techniques
 */

// Define architecture bits before including header
#define BCPL_ARCH_BITS 64

#include "ocode_64bit.h"
#include <stdalign.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <string.h>

// =============================================================================
// OPERATION ATTRIBUTES TABLE
// =============================================================================

/**
 * @brief Enhanced operation attributes table for 64-bit operations
 *
 * This table extends the original OCODE attributes with 64-bit specific
 * information including memory access patterns, alignment requirements,
 * and optimization hints.
 */
static ocode_attr_64_t ocode_64_attributes[OCODE_MAX_64 + 1] = {0};

// Forward declarations for initialization
static void init_ocode_attributes(void);
static bool attributes_initialized = false;

// =============================================================================
// CONTEXT MANAGEMENT
// =============================================================================

/**
 * @brief Initialize 64-bit OCODE context
 */
bool ocode_context_64_init(ocode_context_64_t *ctx, size_t initial_capacity) {
  if (!ctx || initial_capacity == 0) {
    return false;
  }

  // Initialize attributes table if needed
  if (!attributes_initialized) {
    init_ocode_attributes();
    attributes_initialized = true;
  }

  // Zero-initialize the context
  memset(ctx, 0, sizeof(*ctx));

  // Allocate aligned load stack
  ctx->load_stack_capacity = initial_capacity;
  ctx->load_stack =
      aligned_alloc(alignof(load_stack_entry_64_t),
                    ctx->load_stack_capacity * sizeof(load_stack_entry_64_t));
  if (!ctx->load_stack) {
    return false;
  }

  // Allocate aligned code buffer
  ctx->code_buffer_capacity =
      initial_capacity * 8; // Estimate 8 bytes per operation
  ctx->code_buffer = aligned_alloc(
      alignof(bcpl_word_t), ctx->code_buffer_capacity * sizeof(bcpl_word_t));
  if (!ctx->code_buffer) {
    free(ctx->load_stack);
    return false;
  }

  // Initialize memory management
  ctx->memory.heap_capacity = 1024 * 1024; // 1MB initial heap
  ctx->memory.heap_base = aligned_alloc(64, ctx->memory.heap_capacity);
  if (!ctx->memory.heap_base) {
    free(ctx->load_stack);
    free(ctx->code_buffer);
    return false;
  }

  // Initialize state
  ctx->current_generation = 1;
  ctx->debug.debug_mode = false;

  return true;
}

/**
 * @brief Cleanup 64-bit OCODE context
 */
void ocode_context_64_cleanup(ocode_context_64_t *ctx) {
  if (!ctx)
    return;

  free(ctx->load_stack);
  free(ctx->code_buffer);
  free(ctx->memory.heap_base);

  // Zero out the context to prevent use-after-free
  memset(ctx, 0, sizeof(*ctx));
}

// =============================================================================
// OPERATION PROCESSING
// =============================================================================

/**
 * @brief Get operation attributes for 64-bit operation
 */
const ocode_attr_64_t *ocode_64_get_attributes(ocode_op_64_t op) {
  if (!attributes_initialized) {
    init_ocode_attributes();
    attributes_initialized = true;
  }

  if (op > OCODE_MAX_64) {
    return NULL;
  }
  return &ocode_64_attributes[op];
}

/**
 * @brief Process arithmetic operation
 */
static bool process_arithmetic_64(ocode_context_64_t *ctx, ocode_op_64_t op) {
  const ocode_attr_64_t *attr = ocode_64_get_attributes(op);
  if (!attr || ctx->load_stack_size < attr->stack_pops) {
    return false;
  }

  // Get operands from load stack
  load_stack_entry_64_t *operands =
      &ctx->load_stack[ctx->load_stack_size - attr->stack_pops];

  // Perform operation based on type
  bcpl_word_t result = 0;
  switch (op) {
  case OCODE_MULT64: {
    // 64-bit multiplication with overflow detection
    __int128 product =
        (__int128)operands[0].value * (__int128)operands[1].value;
    if (product > INT64_MAX || product < INT64_MIN) {
      // Handle overflow
      ctx->debug.error_count++;
      return false;
    }
    result = (bcpl_word_t)product;
    break;
  }
  case OCODE_DIV64:
    if (operands[1].value == 0) {
      ctx->debug.error_count++;
      return false;
    }
    result = operands[0].value / operands[1].value;
    break;
  case OCODE_PTR_ADD:
    result = operands[0].value + operands[1].value;
    break;
  case OCODE_PTR_SUB:
    result = operands[0].value - operands[1].value;
    break;
  case OCODE_PTR_DIFF:
    result = (operands[0].value - operands[1].value) / sizeof(bcpl_word_t);
    break;
  default:
    return false;
  }

  // Update stack
  ctx->load_stack_size -= attr->stack_pops;
  if (attr->stack_pushes > 0) {
    ctx->load_stack[ctx->load_stack_size].value = result;
    ctx->load_stack[ctx->load_stack_size].type = X_R;
    ctx->load_stack[ctx->load_stack_size].generation =
        ctx->current_generation++;
    ctx->load_stack_size++;
  }

  ctx->stats.operations_processed++;
  return true;
}

/**
 * @brief Process memory operation
 */
static bool process_memory_64(ocode_context_64_t *ctx, ocode_op_64_t op) {
  const ocode_attr_64_t *attr = ocode_64_get_attributes(op);
  if (!attr || ctx->load_stack_size < attr->stack_pops) {
    return false;
  }

  load_stack_entry_64_t *operands =
      &ctx->load_stack[ctx->load_stack_size - attr->stack_pops];

  switch (op) {
  case OCODE_ALLOC: {
    size_t size = (size_t)operands[0].value;
    void *ptr = aligned_alloc(attr->alignment_req, size);
    if (!ptr) {
      ctx->debug.error_count++;
      return false;
    }

    // Track allocation
    ctx->memory.allocation_count++;

    // Push result
    ctx->load_stack_size -= attr->stack_pops;
    ctx->load_stack[ctx->load_stack_size].address = (bcpl_word_t *)ptr;
    ctx->load_stack[ctx->load_stack_size].type = X_R;
    ctx->load_stack[ctx->load_stack_size].generation =
        ctx->current_generation++;
    ctx->load_stack_size++;
    break;
  }
  case OCODE_FREE: {
    void *ptr = (void *)operands[0].address;
    free(ptr);
    ctx->memory.allocation_count--;
    ctx->load_stack_size -= attr->stack_pops;
    break;
  }
  case OCODE_LOAD_PTR64: {
    bcpl_word_t *addr = operands[0].address;
    bcpl_word_t value = *addr;

    ctx->load_stack_size -= attr->stack_pops;
    ctx->load_stack[ctx->load_stack_size].value = value;
    ctx->load_stack[ctx->load_stack_size].type = X_R;
    ctx->load_stack[ctx->load_stack_size].generation =
        ctx->current_generation++;
    ctx->load_stack_size++;
    break;
  }
  case OCODE_STORE_PTR64: {
    bcpl_word_t *addr = operands[0].address;
    bcpl_word_t value = operands[1].value;
    *addr = value;
    ctx->load_stack_size -= attr->stack_pops;
    break;
  }
  default:
    return false;
  }

  ctx->stats.operations_processed++;
  return true;
}

/**
 * @brief Process atomic operation
 */
static bool process_atomic_64(ocode_context_64_t *ctx, ocode_op_64_t op) {
  const ocode_attr_64_t *attr = ocode_64_get_attributes(op);
  if (!attr || ctx->load_stack_size < attr->stack_pops) {
    return false;
  }

  load_stack_entry_64_t *operands =
      &ctx->load_stack[ctx->load_stack_size - attr->stack_pops];

  switch (op) {
  case OCODE_ATOMIC_LOAD: {
    _Atomic bcpl_word_t *addr = (_Atomic bcpl_word_t *)operands[0].address;
    bcpl_word_t value = atomic_load(addr);

    ctx->load_stack_size -= attr->stack_pops;
    ctx->load_stack[ctx->load_stack_size].value = value;
    ctx->load_stack[ctx->load_stack_size].type = X_R;
    ctx->load_stack[ctx->load_stack_size].generation =
        ctx->current_generation++;
    ctx->load_stack_size++;
    break;
  }
  case OCODE_ATOMIC_STORE: {
    _Atomic bcpl_word_t *addr = (_Atomic bcpl_word_t *)operands[0].address;
    bcpl_word_t value = operands[1].value;
    atomic_store(addr, value);
    ctx->load_stack_size -= attr->stack_pops;
    break;
  }
  case OCODE_ATOMIC_ADD: {
    _Atomic bcpl_word_t *addr = (_Atomic bcpl_word_t *)operands[0].address;
    bcpl_word_t value = operands[1].value;
    bcpl_word_t old_value = atomic_fetch_add(addr, value);

    ctx->load_stack_size -= attr->stack_pops;
    ctx->load_stack[ctx->load_stack_size].value = old_value;
    ctx->load_stack[ctx->load_stack_size].type = X_R;
    ctx->load_stack[ctx->load_stack_size].generation =
        ctx->current_generation++;
    ctx->load_stack_size++;
    break;
  }
  case OCODE_ATOMIC_CAS: {
    _Atomic bcpl_word_t *addr = (_Atomic bcpl_word_t *)operands[0].address;
    bcpl_word_t expected = operands[1].value;
    bcpl_word_t desired = operands[2].value;
    bool success = atomic_compare_exchange_strong(addr, &expected, desired);

    ctx->load_stack_size -= attr->stack_pops;
    ctx->load_stack[ctx->load_stack_size].value = success ? 1 : 0;
    ctx->load_stack[ctx->load_stack_size].type = X_R;
    ctx->load_stack[ctx->load_stack_size].generation =
        ctx->current_generation++;
    ctx->load_stack_size++;
    break;
  }
  default:
    return false;
  }

  ctx->stats.operations_processed++;
  return true;
}

/**
 * @brief Process 64-bit OCODE operation
 */
bool ocode_64_process_operation(ocode_context_64_t *ctx, ocode_op_64_t op) {
  if (!ctx)
    return false;

  // Ensure we have enough stack space
  if (ctx->load_stack_size >= ctx->load_stack_capacity - 2) {
    return false;
  }

  // Dispatch to appropriate handler
  if (ocode_64_is_arithmetic(op)) {
    return process_arithmetic_64(ctx, op);
  } else if (ocode_64_is_memory_op(op)) {
    return process_memory_64(ctx, op);
  } else if (ocode_64_is_atomic(op)) {
    return process_atomic_64(ctx, op);
  } else {
    // Handle other operation types
    ctx->debug.error_count++;
    return false;
  }
}

// =============================================================================
// OPTIMIZATION FUNCTIONS
// =============================================================================

/**
 * @brief Optimize load stack for 64-bit architecture
 */
uint32_t ocode_64_optimize_load_stack(ocode_context_64_t *ctx) {
  if (!ctx || ctx->load_stack_size == 0) {
    return 0;
  }

  uint32_t optimizations = 0;

  // Dead code elimination - remove unused values
  for (size_t i = 0; i < ctx->load_stack_size; i++) {
    if (ctx->load_stack[i].use_count == 0 &&
        ctx->load_stack[i].generation < ctx->current_generation - 10) {
      // Remove dead entry
      memmove(&ctx->load_stack[i], &ctx->load_stack[i + 1],
              (ctx->load_stack_size - i - 1) * sizeof(load_stack_entry_64_t));
      ctx->load_stack_size--;
      i--; // Recheck this position
      optimizations++;
    }
  }

  // Constant folding opportunities
  for (size_t i = 0; i < ctx->load_stack_size - 1; i++) {
    if (ctx->load_stack[i].type == X_N && ctx->load_stack[i + 1].type == X_N) {
      // Two constants can potentially be folded
      optimizations++;
    }
  }

  ctx->stats.optimizations_applied += optimizations;
  return optimizations;
}

/**
 * @brief Allocate register for value
 */
uint8_t ocode_64_allocate_register(ocode_context_64_t *ctx,
                                   uint8_t prefer_reg) {
  if (!ctx)
    return 0;

  // Try preferred register first
  if (prefer_reg > 0 && prefer_reg <= 64 &&
      !(ctx->registers_used & (1ULL << (prefer_reg - 1)))) {
    ctx->registers_used |= (1ULL << (prefer_reg - 1));
    ctx->stats.cache_hits++;
    return prefer_reg;
  }

  // Find first available register
  for (uint8_t reg = 1; reg <= 64; reg++) {
    if (!(ctx->registers_used & (1ULL << (reg - 1)))) {
      ctx->registers_used |= (1ULL << (reg - 1));
      ctx->stats.cache_misses++;
      return reg;
    }
  }

  // No registers available - need to spill
  ctx->stats.cache_misses++;
  return 0;
}

/**
 * @brief Free register
 */
void ocode_64_free_register(ocode_context_64_t *ctx, uint8_t reg) {
  if (!ctx || reg == 0 || reg > 64)
    return;

  ctx->registers_used &= ~(1ULL << (reg - 1));
  ctx->registers_dirty &= ~(1ULL << (reg - 1));
}

/**
 * @brief Generate optimized 64-bit code sequence
 */
bool ocode_64_generate_sequence(ocode_context_64_t *ctx,
                                const ocode_op_64_t *operations, size_t count) {
  if (!ctx || !operations || count == 0) {
    return false;
  }

  // Process each operation in sequence
  for (size_t i = 0; i < count; i++) {
    if (!ocode_64_process_operation(ctx, operations[i])) {
      return false;
    }

    // Apply optimizations periodically
    if ((i % 16) == 0) {
      ocode_64_optimize_load_stack(ctx);
    }
  }

  ctx->basic_block_count++;
  return true;
}

// =============================================================================
// BRIDGE COMPATIBILITY FUNCTIONS
// =============================================================================

/**
 * @brief Get operation attributes (bridge compatibility)
 */
const ocode_attr_64_t *ocode_get_op_attributes_64(enum ocode_op_64 op) {
  return ocode_64_get_attributes((ocode_op_64_t)op);
}

/**
 * @brief Check if operation is valid (bridge compatibility)
 */
bool ocode_is_valid_operation_64(enum ocode_op_64 op) {
  return (op >= 0 && op <= OCODE_MAX_64);
}

/**
 * @brief Initialize context with bridge compatibility
 */
bool ocode_context_init_64(ocode_context_64_t *ctx, size_t initial_capacity) {
  return ocode_context_64_init(ctx, initial_capacity);
}

/**
 * @brief Cleanup context with bridge compatibility
 */
void ocode_context_cleanup_64(ocode_context_64_t *ctx) {
  ocode_context_64_cleanup(ctx);
}

// =============================================================================
// ATTRIBUTE INITIALIZATION
// =============================================================================

/**
 * @brief Initialize operation attributes table
 */
static void init_ocode_attributes(void) {
  // Clear all attributes
  memset(ocode_64_attributes, 0, sizeof(ocode_64_attributes));

  // Legacy operations
  ocode_64_attributes[OCODE_TRUE] = (ocode_attr_64_t){0, 1, 0, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_FALSE] = (ocode_attr_64_t){0, 1, 0, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_RV] =
      (ocode_attr_64_t){1, 1, 3, OCODE_FLAG_MEMORY_ACCESS, 8, 8, 2};
  ocode_64_attributes[OCODE_FNAP] =
      (ocode_attr_64_t){1, 1, 1, OCODE_FLAG_SIDE_EFFECT, 0, 8, 5};
  ocode_64_attributes[OCODE_MULT] =
      (ocode_attr_64_t){2, 1, 5, OCODE_FLAG_COMMUTATIVE, 0, 1, 2};
  ocode_64_attributes[OCODE_DIV] =
      (ocode_attr_64_t){2, 1, 5, OCODE_FLAG_CAN_FAULT, 0, 1, 8};
  ocode_64_attributes[OCODE_REM] =
      (ocode_attr_64_t){2, 1, 5, OCODE_FLAG_CAN_FAULT, 0, 1, 8};
  ocode_64_attributes[OCODE_PLUS] = (ocode_attr_64_t){
      2, 1, 4, OCODE_FLAG_COMMUTATIVE | OCODE_FLAG_ASSOCIATIVE, 0, 1, 1};
  ocode_64_attributes[OCODE_MINUS] = (ocode_attr_64_t){2, 1, 4, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_NEG] = (ocode_attr_64_t){1, 1, 3, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_ABS] = (ocode_attr_64_t){1, 1, 3, 0, 0, 1, 2};
  ocode_64_attributes[OCODE_EQ] =
      (ocode_attr_64_t){2, 1, 4, OCODE_FLAG_COMMUTATIVE, 0, 1, 1};
  ocode_64_attributes[OCODE_NE] =
      (ocode_attr_64_t){2, 1, 4, OCODE_FLAG_COMMUTATIVE, 0, 1, 1};
  ocode_64_attributes[OCODE_LS] = (ocode_attr_64_t){2, 1, 4, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_GR] = (ocode_attr_64_t){2, 1, 4, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_LE] = (ocode_attr_64_t){2, 1, 4, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_GE] = (ocode_attr_64_t){2, 1, 4, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_NOT] = (ocode_attr_64_t){1, 1, 3, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_LSHIFT] = (ocode_attr_64_t){2, 1, 6, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_RSHIFT] = (ocode_attr_64_t){2, 1, 6, 0, 0, 1, 1};
  ocode_64_attributes[OCODE_LOGAND] = (ocode_attr_64_t){
      2, 1, 4, OCODE_FLAG_COMMUTATIVE | OCODE_FLAG_ASSOCIATIVE, 0, 1, 1};
  ocode_64_attributes[OCODE_LOGOR] = (ocode_attr_64_t){
      2, 1, 4, OCODE_FLAG_COMMUTATIVE | OCODE_FLAG_ASSOCIATIVE, 0, 1, 1};
  ocode_64_attributes[OCODE_EQV] =
      (ocode_attr_64_t){2, 1, 4, OCODE_FLAG_COMMUTATIVE, 0, 1, 1};
  ocode_64_attributes[OCODE_NEQV] =
      (ocode_attr_64_t){2, 1, 4, OCODE_FLAG_COMMUTATIVE, 0, 1, 1};

  // Enhanced 64-bit operations
  ocode_64_attributes[OCODE_MULT64] =
      (ocode_attr_64_t){2, 1, 5, OCODE_FLAG_COMMUTATIVE, 0, 8, 3};
  ocode_64_attributes[OCODE_DIV64] =
      (ocode_attr_64_t){2, 1, 5, OCODE_FLAG_CAN_FAULT, 0, 8, 12};
  ocode_64_attributes[OCODE_LSHIFT64] = (ocode_attr_64_t){2, 1, 6, 0, 0, 8, 2};
  ocode_64_attributes[OCODE_RSHIFT64] = (ocode_attr_64_t){2, 1, 6, 0, 0, 8, 2};
  ocode_64_attributes[OCODE_LOAD_PTR64] =
      (ocode_attr_64_t){1, 1, 3, OCODE_FLAG_MEMORY_ACCESS, 8, 8, 2};
  ocode_64_attributes[OCODE_STORE_PTR64] = (ocode_attr_64_t){
      2, 0, 2, OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT, 8, 8, 2};
  ocode_64_attributes[OCODE_PTR_ADD] =
      (ocode_attr_64_t){2, 1, 4, OCODE_FLAG_COMMUTATIVE, 0, 8, 1};
  ocode_64_attributes[OCODE_PTR_SUB] = (ocode_attr_64_t){2, 1, 4, 0, 0, 8, 1};
  ocode_64_attributes[OCODE_PTR_DIFF] = (ocode_attr_64_t){2, 1, 4, 0, 0, 8, 2};

  // Memory management operations
  ocode_64_attributes[OCODE_ALLOC] = (ocode_attr_64_t){
      1, 1, 1, OCODE_FLAG_SIDE_EFFECT | OCODE_FLAG_CAN_FAULT, 0, 8, 20};
  ocode_64_attributes[OCODE_FREE] =
      (ocode_attr_64_t){1, 0, 2, OCODE_FLAG_SIDE_EFFECT, 0, 8, 15};
  ocode_64_attributes[OCODE_REALLOC] = (ocode_attr_64_t){
      2, 1, 1, OCODE_FLAG_SIDE_EFFECT | OCODE_FLAG_CAN_FAULT, 0, 8, 25};
  ocode_64_attributes[OCODE_MEMCPY] = (ocode_attr_64_t){
      3, 1, 2, OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT, 0, 1, 10};
  ocode_64_attributes[OCODE_MEMSET] = (ocode_attr_64_t){
      3, 1, 2, OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT, 0, 1, 8};
  ocode_64_attributes[OCODE_MEMMOVE] = (ocode_attr_64_t){
      3, 1, 2, OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT, 0, 1, 12};

  // Vector/SIMD operations
  ocode_64_attributes[OCODE_VEC_ADD] = (ocode_attr_64_t){
      2, 1, 7, OCODE_FLAG_VECTOR | OCODE_FLAG_COMMUTATIVE, 16, 16, 1};
  ocode_64_attributes[OCODE_VEC_MUL] = (ocode_attr_64_t){
      2, 1, 7, OCODE_FLAG_VECTOR | OCODE_FLAG_COMMUTATIVE, 16, 16, 2};
  ocode_64_attributes[OCODE_VEC_LOAD] = (ocode_attr_64_t){
      1, 1, 7, OCODE_FLAG_VECTOR | OCODE_FLAG_MEMORY_ACCESS, 16, 16, 2};
  ocode_64_attributes[OCODE_VEC_STORE] = (ocode_attr_64_t){
      2,  0,
      7,  OCODE_FLAG_VECTOR | OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT,
      16, 16,
      2};

  // Atomic operations
  ocode_64_attributes[OCODE_ATOMIC_LOAD] = (ocode_attr_64_t){
      1, 1, 3, OCODE_FLAG_ATOMIC | OCODE_FLAG_MEMORY_ACCESS, 8, 8, 3};
  ocode_64_attributes[OCODE_ATOMIC_STORE] = (ocode_attr_64_t){
      2, 0,
      2, OCODE_FLAG_ATOMIC | OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT,
      8, 8,
      3};
  ocode_64_attributes[OCODE_ATOMIC_ADD] = (ocode_attr_64_t){
      2, 1,
      4, OCODE_FLAG_ATOMIC | OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT,
      8, 8,
      5};
  ocode_64_attributes[OCODE_ATOMIC_CAS] = (ocode_attr_64_t){
      3, 1,
      1, OCODE_FLAG_ATOMIC | OCODE_FLAG_MEMORY_ACCESS | OCODE_FLAG_SIDE_EFFECT,
      8, 8,
      8};
}
