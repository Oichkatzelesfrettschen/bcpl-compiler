/**
 * @file ocode_64bit_aarch64.h
 * @brief ARM64/AArch64 specific OCODE optimizations
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 */

#pragma once

// =============================================================================
// AARCH64 SPECIFIC OPTIMIZATIONS
// =============================================================================

/**
 * @brief AArch64 register allocation strategy
 */
#define OCODE_64_AARCH64_REGISTERS 31 // 31 general-purpose registers

/**
 * @brief AArch64 instruction scheduling
 */
static inline void ocode_64_schedule_aarch64(ocode_context_64_t *ctx) {
  // Basic scheduling for AArch64 in-order/out-of-order cores
  if (ctx && ctx->load_stack_size > 1) {
    // Take advantage of AArch64's flexible addressing modes
    // and conditional execution capabilities
    ctx->stats.optimizations_applied++;
  }
}

/**
 * @brief AArch64 peephole optimization
 */
static inline uint32_t ocode_64_peephole_aarch64(ocode_context_64_t *ctx) {
  if (!ctx || ctx->load_stack_size < 2)
    return 0;

  uint32_t optimizations = 0;

  // Example: use AArch64 specific features
  for (size_t i = 0; i < ctx->load_stack_size - 1; i++) {
    load_stack_entry_64_t *entry1 = &ctx->load_stack[i];
    load_stack_entry_64_t *entry2 = &ctx->load_stack[i + 1];

    // Look for opportunities to use AArch64 specific instructions
    if (entry1->type == X_N && entry2->type == X_N) {
      // Could use AArch64 immediate encoding or shifted operands
      optimizations++;
    }
  }

  return optimizations;
}

// Architecture-specific macros
#define OCODE_64_ARCH_OPTIMIZE(ctx) ocode_64_schedule_aarch64(ctx)
#define OCODE_64_ARCH_PEEPHOLE(ctx) ocode_64_peephole_aarch64(ctx)
#define OCODE_64_ARCH_NAME "aarch64"
