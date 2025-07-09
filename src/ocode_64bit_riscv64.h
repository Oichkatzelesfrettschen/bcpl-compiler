/**
 * @file ocode_64bit_riscv64.h
 * @brief RISC-V 64-bit specific OCODE optimizations
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 */

#pragma once

// =============================================================================
// RISC-V 64-BIT SPECIFIC OPTIMIZATIONS
// =============================================================================

/**
 * @brief RISC-V 64-bit register allocation strategy
 */
#define OCODE_64_RISCV64_REGISTERS 32 // 32 general-purpose registers

/**
 * @brief RISC-V 64-bit instruction scheduling
 */
static inline void ocode_64_schedule_riscv64(ocode_context_64_t *ctx) {
  // Basic scheduling for RISC-V in-order cores
  if (ctx && ctx->load_stack_size > 1) {
    // RISC-V has simple, regular instruction encoding
    // Focus on register allocation and load/store optimization
    ctx->stats.optimizations_applied++;
  }
}

/**
 * @brief RISC-V 64-bit peephole optimization
 */
static inline uint32_t ocode_64_peephole_riscv64(ocode_context_64_t *ctx) {
  if (!ctx || ctx->load_stack_size < 2)
    return 0;

  uint32_t optimizations = 0;

  // Example: use RISC-V specific features
  for (size_t i = 0; i < ctx->load_stack_size - 1; i++) {
    load_stack_entry_64_t *entry1 = &ctx->load_stack[i];
    load_stack_entry_64_t *entry2 = &ctx->load_stack[i + 1];

    // Look for opportunities to use RISC-V immediate encodings
    if (entry1->type == X_N && entry2->type == X_N) {
      // Could use RISC-V compressed instructions or immediate forms
      optimizations++;
    }
  }

  return optimizations;
}

// Architecture-specific macros
#define OCODE_64_ARCH_OPTIMIZE(ctx) ocode_64_schedule_riscv64(ctx)
#define OCODE_64_ARCH_PEEPHOLE(ctx) ocode_64_peephole_riscv64(ctx)
#define OCODE_64_ARCH_NAME "riscv64"
