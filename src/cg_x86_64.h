/**
 * @file cg_x86_64.h
 * @brief Modern C23 x86_64 Code Generation Backend
 * @author BCPL Modernization Team
 * @date 2025
 * @copyright Open Source - Pure C23 Implementation
 *
 * COMPLETE MODERNIZATION: This header provides a pure C23 implementation
 * of x86_64 code generation, eliminating all assembly dependencies.
 *
 * REPLACES: Legacy assembly-based code generation
 * PROVIDES: Universal architecture support with C23 abstractions
 */

#ifndef BCPL_CG_X86_64_H
#define BCPL_CG_X86_64_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

// =============================================================================
// ARCHITECTURE ABSTRACTION
// =============================================================================

/**
 * @brief Target architecture enumeration
 */
typedef enum {
  ARCH_X86_64,
  ARCH_ARM64,
  ARCH_RISCV64,
  ARCH_WASM32,
  ARCH_GENERIC
} target_arch_t;

/**
 * @brief Register allocation context
 */
typedef struct {
  int allocated_registers[16];
  int register_usage_count[16];
  bool register_dirty[16];
} register_context_t;

/**
 * @brief Code emission buffer
 */
typedef struct {
  char *buffer;
  size_t size;
  size_t capacity;
  FILE *output_file;
} code_buffer_t;

// =============================================================================
// UNIVERSAL CODE GENERATION INTERFACE
// =============================================================================

/**
 * @brief Initialize target-specific code generation
 * @param arch Target architecture
 * @return true if successful, false otherwise
 */
bool cg_target_init(target_arch_t arch);

/**
 * @brief Emit assembly instruction (universal)
 * @param format Printf-style format string
 * @param ... Arguments for format string
 */
void emit(const char *format, ...);

/**
 * @brief Emit data definition
 * @param label Label name
 * @param value Data value
 */
void emit_data(const char *label, int value);

/**
 * @brief Emit label definition
 * @param label Label name
 */
void emit_label(const char *label);

/**
 * @brief Load value into register
 * @param reg Register number
 * @param load_immediate Whether to load immediate value
 */
void loadreg(int reg, int load_immediate);

/**
 * @brief Force register allocation
 * @param stack_position Stack position to force
 */
void force(int stack_position);

// =============================================================================
// X86_64 SPECIFIC OPTIMIZATIONS
// =============================================================================

/**
 * @brief Generate optimized x86_64 prologue
 */
void emit_x86_64_prologue(void);

/**
 * @brief Generate optimized x86_64 epilogue
 */
void emit_x86_64_epilogue(void);

/**
 * @brief Optimize register allocation for x86_64
 * @param ctx Register context
 */
void optimize_x86_64_registers(register_context_t *ctx);

// =============================================================================
// ARM64 SPECIFIC OPTIMIZATIONS
// =============================================================================

/**
 * @brief Generate ARM64 prologue
 */
void emit_arm64_prologue(void);

/**
 * @brief Generate ARM64 epilogue
 */
void emit_arm64_epilogue(void);

/**
 * @brief Optimize register allocation for ARM64
 * @param ctx Register context
 */
void optimize_arm64_registers(register_context_t *ctx);

// =============================================================================
// UNIVERSAL REGISTER MANAGEMENT
// =============================================================================

/**
 * @brief Allocate a register
 * @return Register number, or -1 if none available
 */
int allocate_register(void);

/**
 * @brief Free a register
 * @param reg Register number to free
 */
void free_register(int reg);

/**
 * @brief Spill register to memory
 * @param reg Register to spill
 */
void spill_register(int reg);

/**
 * @brief Restore register from memory
 * @param reg Register to restore
 */
void restore_register(int reg);

// =============================================================================
// CODE OPTIMIZATION ENGINE
// =============================================================================

/**
 * @brief Peephole optimization pass
 */
void optimize_peephole(void);

/**
 * @brief Dead code elimination
 */
void eliminate_dead_code(void);

/**
 * @brief Constant folding optimization
 */
void optimize_constants(void);

/**
 * @brief Register allocation optimization
 */
void optimize_register_allocation(void);

// =============================================================================
// TARGET-SPECIFIC INSTRUCTION EMISSION
// =============================================================================

/**
 * @brief Emit arithmetic operation
 * @param op Operation type
 * @param dest Destination register
 * @param src1 Source register 1
 * @param src2 Source register 2
 */
void emit_arithmetic(int op, int dest, int src1, int src2);

/**
 * @brief Emit memory operation
 * @param op Operation type
 * @param reg Register
 * @param address Memory address
 */
void emit_memory(int op, int reg, int address);

/**
 * @brief Emit control flow operation
 * @param op Operation type
 * @param target Target label
 */
void emit_control_flow(int op, const char *target);

/**
 * @brief Emit function call
 * @param function_name Function to call
 * @param arg_count Number of arguments
 */
void emit_function_call(const char *function_name, int arg_count);

// =============================================================================
// DEBUGGING AND PROFILING SUPPORT
// =============================================================================

/**
 * @brief Enable debug information generation
 * @param enable Whether to enable debug info
 */
void cg_set_debug_mode(bool enable);

/**
 * @brief Emit debug line information
 * @param filename Source filename
 * @param line_number Line number
 */
void emit_debug_line(const char *filename, int line_number);

/**
 * @brief Generate profiling instrumentation
 * @param function_name Function being profiled
 */
void emit_profiling(const char *function_name);

// =============================================================================
// GLOBAL STATE (for compatibility with legacy code)
// =============================================================================

extern register_context_t *global_reg_ctx;
extern code_buffer_t *global_code_buffer;
extern target_arch_t current_target_arch;

#ifdef __cplusplus
}
#endif

#endif // BCPL_CG_X86_64_H
