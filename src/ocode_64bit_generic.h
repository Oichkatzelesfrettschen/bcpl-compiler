/**
 * @file ocode_64bit_generic.h
 * @brief Generic 64-bit OCODE optimizations for portable builds
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Modernization Team. All rights reserved.
 */

#pragma once

// =============================================================================
// GENERIC 64-BIT OPTIMIZATIONS
// =============================================================================

/**
 * @brief Generic register allocation strategy
 */
#define OCODE_64_GENERIC_REGISTERS 16

/**
 * @brief Generic instruction scheduling (no-op for generic builds)
 */
static inline void ocode_64_schedule_generic(ocode_context_64_t *ctx) {
  (void)ctx; // No scheduling optimizations in generic build
}

/**
 * @brief Generic peephole optimization
 */
static inline uint32_t ocode_64_peephole_generic(ocode_context_64_t *ctx) {
  (void)ctx;
  return 0; // No peephole optimizations in generic build
}

// Architecture-specific macros
#define OCODE_64_ARCH_OPTIMIZE(ctx) ocode_64_schedule_generic(ctx)
#define OCODE_64_ARCH_PEEPHOLE(ctx) ocode_64_peephole_generic(ctx)
#define OCODE_64_ARCH_NAME "generic"
