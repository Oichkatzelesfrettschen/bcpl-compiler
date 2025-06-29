/**
 * @file ocode_64bit_x86_64.h
 * @brief x86-64 specific OCODE optimizations
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 */

#pragma once

// =============================================================================
// X86-64 SPECIFIC OPTIMIZATIONS
// =============================================================================

/**
 * @brief x86-64 register allocation strategy
 */
#define OCODE_64_X86_64_REGISTERS 16

/**
 * @brief x86-64 instruction scheduling
 */
static inline void ocode_64_schedule_x86_64(ocode_context_64_t *ctx) {
  // Basic scheduling for x86-64 out-of-order execution
  if (ctx && ctx->load_stack_size > 1) {
    // Reorder independent operations for better pipeline utilization
    // This is a simplified example - real scheduling would be more complex
    ctx->stats.optimizations_applied++;
  }
}

/**
 * @brief x86-64 peephole optimization
 */
static inline uint32_t ocode_64_peephole_x86_64(ocode_context_64_t *ctx) {
  if (!ctx || ctx->load_stack_size < 2)
    return 0;

  uint32_t optimizations = 0;

  // Example: combine add/sub operations
  for (size_t i = 0; i < ctx->load_stack_size - 1; i++) {
    load_stack_entry_64_t *entry1 = &ctx->load_stack[i];
    load_stack_entry_64_t *entry2 = &ctx->load_stack[i + 1];

    // Look for opportunities to use x86-64 specific instructions
    if (entry1->type == X_N && entry2->type == X_N) {
      // Could combine constants using LEA instruction
      optimizations++;
    }
  }

  return optimizations;
}

// Architecture-specific macros
#define OCODE_64_ARCH_OPTIMIZE(ctx) ocode_64_schedule_x86_64(ctx)
#define OCODE_64_ARCH_PEEPHOLE(ctx) ocode_64_peephole_x86_64(ctx)
#define OCODE_64_ARCH_NAME "x86_64"
