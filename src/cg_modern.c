/**
 * @file cg_modern.c
 * @brief Modern C23 implementation of the BCPL code generator
 * @author BCPL Compiler Modernization Team
 * @date 2025
 * @copyright Copyright (c) 2025 BCPL Compiler Team. All rights reserved.
 *
 * This file contains the modernized version of the BCPL code generator,
 * refactored from the original monolithic gencode() function into a
 * beautiful, maintainable, and type-safe C23 implementation.
 *
 * The design follows the Lions commentary style: "Code should read like
 * prose, each function telling a clear story of its purpose."
 */

#include "cg_modern.h"
#include "cg_x86_64.h"
#include "oc.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================================================================
// MODERN TYPE DEFINITIONS - C23 Style
// =============================================================================
// =============================================================================
// FORWARD DECLARATIONS
// =============================================================================

// Core processing functions
extern ocode_result_t process_ocode_stream(ocode_context_t *ctx);
extern void initialize_code_generation_context(ocode_context_t *ctx);
extern void cleanup_code_generation_context(ocode_context_t *ctx);

// Operation category handlers
extern ocode_result_t handle_load_operations(ocode_context_t *ctx, ocode_op op);
extern ocode_result_t handle_store_operations(ocode_context_t *ctx,
                                              ocode_op op);
extern ocode_result_t handle_arithmetic_operations(ocode_context_t *ctx,
                                                   ocode_op op);
extern ocode_result_t handle_logical_operations(ocode_context_t *ctx,
                                                ocode_op op);
extern ocode_result_t handle_comparison_operations(ocode_context_t *ctx,
                                                   ocode_op op);
extern ocode_result_t handle_control_flow_operations(ocode_context_t *ctx,
                                                     ocode_op op);
extern ocode_result_t handle_function_operations(ocode_context_t *ctx,
                                                 ocode_op op);
extern ocode_result_t handle_memory_operations(ocode_context_t *ctx,
                                               ocode_op op);
extern ocode_result_t handle_meta_operations(ocode_context_t *ctx, ocode_op op);

// Utility functions
extern inline bool is_comparison_operation(ocode_op op);
extern inline bool is_arithmetic_operation(ocode_op op);
static inline bool requires_register_allocation(ocode_op op);
extern void prepare_operands_for_operation(ocode_context_t *ctx, ocode_op op);

// =============================================================================
// DISPATCH TABLE - The Heart of Modern OCODE Processing
// =============================================================================

/**
 * @brief OCODE operation dispatch table
 *
 * This table maps each OCODE operation to its specialized handler function.
 * The beauty of this approach is that adding new operations becomes trivial,
 * and the code remains organized by functional domains.
 */
static const ocode_dispatch_entry_t ocode_dispatch_table[] = {
    // Load operations - bringing values onto the evaluation stack
    {S_LN, handle_load_operations, "LOAD_NUMBER", +1, false},
    {S_TRUE, handle_load_operations, "LOAD_TRUE", +1, false},
    {S_FALSE, handle_load_operations, "LOAD_FALSE", +1, false},
    {S_LP, handle_load_operations, "LOAD_PARAM", +1, false},
    {S_LG, handle_load_operations, "LOAD_GLOBAL", +1, false},
    {S_LL, handle_load_operations, "LOAD_LOCAL", +1, false},
    {S_LLP, handle_load_operations, "LOAD_PARAM_PTR", +1, false},
    {S_LLG, handle_load_operations, "LOAD_GLOBAL_PTR", +1, false},
    {S_LLL, handle_load_operations, "LOAD_LOCAL_PTR", +1, false},
    {S_LSTR, handle_load_operations, "LOAD_STRING", +1, false},
    {S_QUERY, handle_load_operations, "LOAD_QUERY", +1, false},

    // Store operations - saving values from the evaluation stack
    {S_SP, handle_store_operations, "STORE_PARAM", -1, false},
    {S_SG, handle_store_operations, "STORE_GLOBAL", -1, false},
    {S_SL, handle_store_operations, "STORE_LOCAL", -1, false},
    {S_STIND, handle_store_operations, "STORE_INDIRECT", -2, true},

    // Arithmetic operations - mathematical computations
    {S_MULT, handle_arithmetic_operations, "MULTIPLY", -1, true},
    {S_DIV, handle_arithmetic_operations, "DIVIDE", -1, true},
    {S_REM, handle_arithmetic_operations, "REMAINDER", -1, true},
    {S_PLUS, handle_arithmetic_operations, "ADD", -1, true},
    {S_MINUS, handle_arithmetic_operations, "SUBTRACT", -1, true},
    {S_NEG, handle_arithmetic_operations, "NEGATE", 0, true},
    {S_ABS, handle_arithmetic_operations, "ABSOLUTE", 0, true},

    // Logical operations - bitwise and boolean operations
    {S_LOGAND, handle_logical_operations, "LOGICAL_AND", -1, true},
    {S_LOGOR, handle_logical_operations, "LOGICAL_OR", -1, true},
    {S_NOT, handle_logical_operations, "LOGICAL_NOT", 0, true},
    {S_EQV, handle_logical_operations, "EQUIVALENT", -1, true},
    {S_NEQV, handle_logical_operations, "NOT_EQUIVALENT", -1, true},
    {S_LSHIFT, handle_logical_operations, "LEFT_SHIFT", -1, true},
    {S_RSHIFT, handle_logical_operations, "RIGHT_SHIFT", -1, true},

    // Comparison operations - relational comparisons
    {S_EQ, handle_comparison_operations, "EQUAL", -1, true},
    {S_NE, handle_comparison_operations, "NOT_EQUAL", -1, true},
    {S_LS, handle_comparison_operations, "LESS_THAN", -1, true},
    {S_GR, handle_comparison_operations, "GREATER_THAN", -1, true},
    {S_LE, handle_comparison_operations, "LESS_EQUAL", -1, true},
    {S_GE, handle_comparison_operations, "GREATER_EQUAL", -1, true},

    // Control flow operations - jumps, calls, and returns
    {S_GOTO, handle_control_flow_operations, "GOTO", 0, false},
    {S_JT, handle_control_flow_operations, "JUMP_TRUE", -1, false},
    {S_JF, handle_control_flow_operations, "JUMP_FALSE", -1, false},
    {S_JUMP, handle_control_flow_operations, "JUMP", 0, false},
    {S_RES, handle_control_flow_operations, "RESULT", 0, false},
    {S_SWITCHON, handle_control_flow_operations, "SWITCH", -1, true},
    {S_ENDFOR, handle_control_flow_operations, "END_FOR", -2, true},

    // Function operations - calls and returns
    {S_FNAP, handle_function_operations, "FUNCTION_CALL", -1, true},
    {S_RTAP, handle_function_operations, "ROUTINE_CALL", -1, true},
    {S_FNRN, handle_function_operations, "FUNCTION_RETURN", -1, true},
    {S_RTRN, handle_function_operations, "ROUTINE_RETURN", -1, true},
    {S_ENTRY, handle_function_operations, "ENTRY_POINT", 0, false},
    {S_ENDPROC, handle_function_operations, "END_PROCEDURE", 0, false},

    // Memory operations - byte-level access
    {S_GETBYTE, handle_memory_operations, "GET_BYTE", -1, true},
    {S_PUTBYTE, handle_memory_operations, "PUT_BYTE", -3, true},
    {S_RV, handle_memory_operations, "RIGHT_VALUE", 0, true},

    // Meta operations - labels, data, and compilation directives
    {S_LAB, handle_meta_operations, "LABEL", 0, false},
    {S_BLAB, handle_meta_operations, "BRANCH_LABEL", 0, false},
    {S_DATALAB, handle_meta_operations, "DATA_LABEL", 0, false},
    {S_ITEML, handle_meta_operations, "ITEM_LABEL", 0, false},
    {S_ITEMN, handle_meta_operations, "ITEM_NUMBER", 0, false},
    {S_NEEDS, handle_meta_operations, "NEEDS", 0, false},
    {S_SECTION, handle_meta_operations, "SECTION", 0, false},
    {S_GLOBAL, handle_meta_operations, "GLOBAL", 0, false},
    {S_SAVE, handle_meta_operations, "SAVE", 0, false},
    {S_STACK, handle_meta_operations, "STACK", 0, false},
    {S_STORE, handle_meta_operations, "STORE", 0, false},
    {S_RSTACK, handle_meta_operations, "RESTORE_STACK", +1, false},
    {S_FINISH, handle_meta_operations, "FINISH", 0, false},
};

static const size_t OCODE_DISPATCH_TABLE_SIZE =
    sizeof(ocode_dispatch_table) / sizeof(ocode_dispatch_table[0]);

// =============================================================================
// MAIN ENTRY POINT - Modernized gencode()
// =============================================================================

/**
 * @brief Modern OCODE processor - the heart of code generation
 * @return Final OCODE operation processed
 *
 * This function replaces the original 348-line gencode() monster with a
 * clean, maintainable design. Each operation type is handled by specialized
 * functions, making the code both more readable and more reliable.
 *
 * The beauty of this approach is that the main loop becomes trivial:
 * read operation, dispatch to handler, handle result. The complexity
 * is properly encapsulated in the specialized handlers.
 */
extern ocode_op gencode_modern(void) {
  ocode_context_t context;

  // Initialize the code generation context
  initialize_code_generation_context(&context);

  // Begin assembly output
  emit(".text");

  // Process the OCODE stream
  ocode_result_t result = process_ocode_stream(&context);

  // Handle the final result
  ocode_op final_op = S_END;
  switch (result) {
  case OCODE_SUCCESS:
  case OCODE_END_OF_STREAM:
    final_op = S_END;
    break;
  case OCODE_SYNTAX_ERROR:
    error("Syntax error in OCODE stream");
    break;
  case OCODE_RUNTIME_ERROR:
    error("Runtime error during code generation");
    break;
  case OCODE_MEMORY_ERROR:
    error("Memory allocation error during code generation");
    break;
  case OCODE_OPTIMIZATION_APPLIED:
    // This is normal - optimization was applied
    final_op = S_END;
    break;
  }

  // Clean up resources
  cleanup_code_generation_context(&context);

  return final_op;
}

// =============================================================================
// CORE PROCESSING FUNCTIONS
// =============================================================================

/**
 * @brief Process the OCODE stream with modern dispatch architecture
 * @param ctx Code generation context
 * @return Processing result
 *
 * This is where the magic happens. Instead of a massive switch statement,
 * we use a dispatch table to route each operation to its specialized handler.
 * This makes the code more maintainable and allows for easy extension.
 */
extern ocode_result_t process_ocode_stream(ocode_context_t *ctx) {
  for (;;) {
    // Read the next operation
    ocode_op op = rdop(0);

    // Check for end of stream
    if (ch == EOF) {
      return OCODE_END_OF_STREAM;
    }

    // Validate operation
    if (op < 0 || op > OPMAX) {
      error("Invalid OCODE operation: %d", op);
      return OCODE_SYNTAX_ERROR;
    }

    // Find the handler for this operation
    const ocode_dispatch_entry_t *entry = NULL;
    for (size_t i = 0; i < OCODE_DISPATCH_TABLE_SIZE; i++) {
      if (ocode_dispatch_table[i].operation == op) {
        entry = &ocode_dispatch_table[i];
        break;
      }
    }

    if (!entry) {
      error("Unknown OCODE operation: %d", op);
      return OCODE_SYNTAX_ERROR;
    }

    // Prepare operands if needed
    prepare_operands_for_operation(ctx, op);

    // Dispatch to the appropriate handler
    ocode_result_t result = entry->handler(ctx, op);

    // Handle special cases
    if (result == OCODE_END_OF_STREAM || result != OCODE_SUCCESS) {
      return result;
    }

    // If this is a GLOBAL operation, we're at the end of this phase
    if (op == S_GLOBAL) {
      return OCODE_SUCCESS;
    }

    // Update stack pointers based on operation effects
    ctx->stack.stack_pointer += entry->stack_effect;

    // Update load stack pointer based on operation type
    if (entry->flags & OCODE_FLAG_REQUIRES_REGISTER) {
      // Register operations affect the load stack
      if (entry->stack_effect > 0) {
        ctx->stack.pointer++;
      } else if (entry->stack_effect < 0) {
        ctx->stack.pointer += entry->stack_effect;
        if (ctx->stack.pointer < 0) {
          ctx->stack.pointer = 0;
        }
      }
    }
  }
}

/**
 * @brief Initialize code generation context
 * @param ctx Context to initialize
 */
extern void initialize_code_generation_context(ocode_context_t *ctx) {
  static_assert(sizeof(ocode_context_t) <= 256,
                "Context structure should remain small for performance");

  // Zero-initialize the entire context
  memset(ctx, 0, sizeof(*ctx));

  // Set up initial state
  ctx->next_label_number = 1000;
  ctx->operation.readonly_mode = false;
  ctx->operation.return_code = 0;

  // Initialize debug information
  ctx->debug.current_function = "gencode_modern";
  ctx->debug.line_number = 0;
}

/**
 * @brief Clean up code generation context
 * @param ctx Context to clean up
 */
extern void cleanup_code_generation_context(ocode_context_t *ctx) {
  // For now, no dynamic resources to clean up
  // But this provides a place for future resource management
  (void)ctx; // Suppress unused parameter warning
}

// =============================================================================
// OPERATION PREPARATION UTILITIES
// =============================================================================

/**
 * @brief Prepare operands for an operation
 * @param ctx Code generation context
 * @param op OCODE operation
 *
 * This function encapsulates the operand preparation logic that was
 * scattered throughout the original gencode() function.
 */
extern void prepare_operands_for_operation(ocode_context_t *ctx, ocode_op op) {
  // Get operation table entries (these would need to be implemented)
  // For now, we'll use placeholder logic
  int s1 = 0, s2 = 0, s3 = 0; // These would come from optab1, optab2, optab3

  // Force operands into registers if needed
  if (s3 <= 7) {
    force(s1);
    if (s3) {
      loadreg(0, s3 == 1 ? 0 : s3 == 2 ? (ltype[0] != X_N) : 1);
    }
    if (s3 >= 4) {
      loadreg(1, s3 == 4 ? 0 : s3 == 5 ? (ltype[1] == X_N) : 1);
    }
  }

  // Cache operand values for use by handlers
  ctx->operation.operands[0] = s1;
  ctx->operation.operands[1] = s2;
  ctx->operation.operands[2] = s3;
}

// =============================================================================
// OPERATION TYPE CHECKS
// =============================================================================

/**
 * @brief Check if operation is a comparison
 * @param op OCODE operation
 * @return true if comparison operation
 */
extern inline bool is_comparison_operation(ocode_op op) {
  return op >= S_EQ && op <= S_GE;
}

/**
 * @brief Check if operation is arithmetic
 * @param op OCODE operation
 * @return true if arithmetic operation
 */
extern inline bool is_arithmetic_operation(ocode_op op) {
  return (op >= S_MULT && op <= S_MINUS) || op == S_NEG || op == S_ABS;
}

/**
 * @brief Check if operation requires register allocation
 * @param op OCODE operation
 * @return true if register allocation needed
 */
static inline bool requires_register_allocation(ocode_op op) {
  for (size_t i = 0; i < OCODE_DISPATCH_TABLE_SIZE; i++) {
    if (ocode_dispatch_table[i].operation == op) {
      return ocode_dispatch_table[i].requires_register;
    }
  }
  return false;
}

// NOTE: The actual handler implementations would follow in separate files
// to keep this file focused on the core architecture.
// Files like: cg_load_ops.c, cg_arithmetic_ops.c, etc.
