/**
 * @file cg_meta_ops.c
 * @brief Meta operations handler for modern BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This module implements meta operations for the modernized BCPL code
 * generator, handling compiler directives, data definitions, and program
 * structure operations that don't directly generate runtime code.
 *
 * "The meta is the message." - Douglas Hofstadter (adapted)
 *
 * Meta Operations Handled:
 * - S_GLOBAL   (Global variable declaration)
 * - S_SECTION  (Module section)
 * - S_NEEDS    (Module dependency)
 * - S_DATALAB  (Data label)
 * - S_ITEML    (Data item - label)
 * - S_ITEMN    (Data item - number)
 * - S_END      (End marker)
 * - S_FINISH   (Program termination)
 * - S_TRUE     (Boolean true constant)
 * - S_FALSE    (Boolean false constant)
 */

#include "cg_modern.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// =============================================================================
// INTERNAL FUNCTION PROTOTYPES
// =============================================================================

static ocode_result_t handle_global_declaration(ocode_context_t *ctx);
static ocode_result_t handle_section(ocode_context_t *ctx);
static ocode_result_t handle_needs(ocode_context_t *ctx);
static ocode_result_t handle_data_label(ocode_context_t *ctx);
static ocode_result_t handle_item_label(ocode_context_t *ctx);
static ocode_result_t handle_item_number(ocode_context_t *ctx);
static ocode_result_t handle_end_marker(ocode_context_t *ctx);
static ocode_result_t handle_finish(ocode_context_t *ctx);
static ocode_result_t handle_true_constant(ocode_context_t *ctx);
static ocode_result_t handle_false_constant(ocode_context_t *ctx);

static void emit_data_section_directive(ocode_context_t *ctx,
                                        const char *section_name);
static void emit_global_symbol(ocode_context_t *ctx, int32_t symbol_id,
                               const char *type);
static void emit_alignment_directive(ocode_context_t *ctx, int alignment);

// =============================================================================
// MAIN META OPERATION HANDLER
// =============================================================================

/**
 * @brief Handle all meta operations
 * @param ctx Code generation context
 * @param op OCODE operation
 * @return Operation result code
 *
 * This function dispatches meta operations to their specific handlers.
 * Meta operations typically affect the compilation process rather than
 * generating runtime code.
 */
ocode_result_t handle_meta_operations(ocode_context_t *ctx, ocode_op op) {
  assert(ctx != NULL);
  assert(is_meta_operation(op));

#ifdef DEBUG_CODE_GENERATION
  debug_log_operation(op, "Processing meta operation");
#endif

  // Prepare for meta operation
  prepare_operands_for_operation(ctx, op);

  switch (op) {
  case S_GLOBAL:
    return handle_global_declaration(ctx);

  case S_SECTION:
    return handle_section(ctx);

  case S_NEEDS:
    return handle_needs(ctx);

  case S_DATALAB:
    return handle_data_label(ctx);

  case S_ITEML:
    return handle_item_label(ctx);

  case S_ITEMN:
    return handle_item_number(ctx);

  case S_END:
    return handle_end_marker(ctx);

  case S_FINISH:
    return handle_finish(ctx);

  case S_TRUE:
    return handle_true_constant(ctx);

  case S_FALSE:
    return handle_false_constant(ctx);

  default:
    report_context_error(ctx, "Unknown meta operation: %d", op);
    return OCODE_SYNTAX_ERROR;
  }
}

// =============================================================================
// SPECIFIC META OPERATION HANDLERS
// =============================================================================

/**
 * @brief Handle global variable declaration
 * @param ctx Code generation context
 * @return Operation result
 *
 * Declares a global variable in the symbol table and generates
 * appropriate assembler directives.
 */
static ocode_result_t handle_global_declaration(ocode_context_t *ctx) {
  assert(ctx != NULL);

  // Generate global symbol declaration
  emit_global_symbol(ctx, ctx->k, "word");

  if (ctx->output_handler) {
    char directive[256];
    snprintf(directive, sizeof(directive),
             ".global\tG%d\t\t; Global variable %d\n"
             "G%d:\t.word\t0\t; Initialize to 0",
             ctx->k, ctx->k, ctx->k);
    ctx->output_handler(directive);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
// Global declarations don't generate runtime instructions
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle section directive
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles module section declarations, organizing code into logical sections.
 */
static ocode_result_t handle_section(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    char directive[256];
    snprintf(directive, sizeof(directive), "; Section %d begins", ctx->k);
    ctx->output_handler(directive);

    // Emit section directive based on section type
    switch (ctx->k) {
    case 0:
      emit_data_section_directive(ctx, ".data");
      break;
    case 1:
      emit_data_section_directive(ctx, ".text");
      break;
    case 2:
      emit_data_section_directive(ctx, ".bss");
      break;
    default:
      emit_data_section_directive(ctx, ".section");
      break;
    }
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle module dependency (NEEDS)
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles module dependency declarations, ensuring required modules
 * are linked properly.
 */
static ocode_result_t handle_needs(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    char directive[256];
    snprintf(directive, sizeof(directive), "; NEEDS module %d", ctx->k);
    ctx->output_handler(directive);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle data label
 * @param ctx Code generation context
 * @return Operation result
 *
 * Defines a label in the data section.
 */
static ocode_result_t handle_data_label(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    char label[128];
    snprintf(label, sizeof(label), "D%d:\t\t\t; Data label %d", ctx->k, ctx->k);
    ctx->output_handler(label);

    // Ensure proper alignment for data items
    emit_alignment_directive(ctx, 4);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle data item with label reference
 * @param ctx Code generation context
 * @return Operation result
 *
 * Generates a data item containing a label reference.
 */
static ocode_result_t handle_item_label(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    char item[256];
    snprintf(item, sizeof(item), ".word\tL%d\t\t; Data item: label reference",
             ctx->k);
    ctx->output_handler(item);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle data item with numeric value
 * @param ctx Code generation context
 * @return Operation result
 *
 * Generates a data item containing a numeric constant.
 */
static ocode_result_t handle_item_number(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    char item[256];
    snprintf(item, sizeof(item), ".word\t%d\t\t; Data item: numeric constant",
             ctx->k);
    ctx->output_handler(item);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle end marker
 * @param ctx Code generation context
 * @return Operation result
 *
 * Handles the end of compilation unit marker.
 */
static ocode_result_t handle_end_marker(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    ctx->output_handler("; End of compilation unit");
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
#endif

  // Signal end of stream
  return OCODE_END_OF_STREAM;
}

/**
 * @brief Handle program termination
 * @param ctx Code generation context
 * @return Operation result
 *
 * Generates code for normal program termination.
 */
static ocode_result_t handle_finish(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    char termination[512];
    snprintf(termination, sizeof(termination),
             "MOV\tR0, #%d\t\t; Exit code\n"
             "MOV\tR7, #1\t\t; sys_exit system call\n"
             "SWI\t0\t\t\t; Invoke system call",
             ctx->k);
    ctx->output_handler(termination);
  }

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted += 3;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle boolean true constant
 * @param ctx Code generation context
 * @return Operation result
 *
 * Loads the boolean true value (1) onto the stack.
 */
static ocode_result_t handle_true_constant(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    ctx->output_handler("MOV\tR1, #1\t\t; Load TRUE constant");
  }

  // Update stack pointer (pushing one value)
  ctx->s++;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

/**
 * @brief Handle boolean false constant
 * @param ctx Code generation context
 * @return Operation result
 *
 * Loads the boolean false value (0) onto the stack.
 */
static ocode_result_t handle_false_constant(ocode_context_t *ctx) {
  assert(ctx != NULL);

  if (ctx->output_handler) {
    ctx->output_handler("MOV\tR1, #0\t\t; Load FALSE constant");
  }

  // Update stack pointer (pushing one value)
  ctx->s++;

#ifdef ENABLE_PERFORMANCE_COUNTERS
  ctx->performance.operations_processed++;
  ctx->performance.instructions_emitted++;
#endif

  return OCODE_SUCCESS;
}

// =============================================================================
// UTILITY FUNCTIONS
// =============================================================================

/**
 * @brief Emit data section directive
 * @param ctx Code generation context
 * @param section_name Name of the section
 */
static void emit_data_section_directive(ocode_context_t *ctx,
                                        const char *section_name) {
  if (ctx->output_handler) {
    char directive[256];
    snprintf(directive, sizeof(directive), "%s\t\t\t; Switch to %s section",
             section_name, section_name);
    ctx->output_handler(directive);
  }
}

/**
 * @brief Emit global symbol declaration
 * @param ctx Code generation context
 * @param symbol_id Symbol identifier
 * @param type Symbol type description
 */
static void emit_global_symbol(ocode_context_t *ctx, int32_t symbol_id,
                               const char *type) {
  if (ctx->output_handler) {
    char symbol[256];
    snprintf(symbol, sizeof(symbol), ".globl\tG%d\t\t; Global %s symbol",
             symbol_id, type);
    ctx->output_handler(symbol);
  }
}

/**
 * @brief Emit alignment directive
 * @param ctx Code generation context
 * @param alignment Alignment requirement in bytes
 */
static void emit_alignment_directive(ocode_context_t *ctx, int alignment) {
  if (ctx->output_handler) {
    char directive[128];
    snprintf(directive, sizeof(directive),
             ".align\t%d\t\t; Align to %d-byte boundary", alignment, alignment);
    ctx->output_handler(directive);
  }
}

// =============================================================================
// OPERATION CLASSIFICATION
// =============================================================================

/**
 * @brief Check if operation is a meta operation
 * @param op OCODE operation to check
 * @return true if op is a meta operation
 */
bool is_meta_operation(ocode_op op) {
  switch (op) {
  case S_GLOBAL:
  case S_SECTION:
  case S_NEEDS:
  case S_DATALAB:
  case S_ITEML:
  case S_ITEMN:
  case S_END:
  case S_FINISH:
  case S_TRUE:
  case S_FALSE:
    return true;
  default:
    return false;
  }
}
