/**
 * @file oc.c
 * @brief OCODE operation attributes table implementation
 * @author Robert Nordier
 * @copyright Copyright (c) 2012 Robert Nordier. All rights reserved.
 *
 * This file contains the operation attributes table for OCODE instructions.
 * The table provides metadata about each OCODE operation including stack
 * effects, operand requirements, and code generation hints.
 *
 * ## Table Format
 * Each OCODE operation has a 4-byte attribute entry:
 * - **Byte 0**: Currently unused, reserved for future extensions
 * - **Byte 1**: Number of values popped from the load stack (0, 1, or 2)
 * - **Byte 2**: Stack push behavior:
 *   - 0: Nothing pushed
 *   - 1: One value pushed
 *   - 2: Set stack to specific size n
 *   - 3: Set stack to size n + 1
 * - **Byte 3**: Code generation hints:
 *   - 0-7: Force load stack entry into register
 *   - 1-7: Load into specific register
 *   - 8: Load operation
 *   - 9: Data operation
 *
 * ## Usage
 * The code generator uses this table to determine how to process each
 * OCODE instruction, including register allocation, stack management,
 * and instruction selection.
 */

/* Copyright (c) 2012 Robert Nordier. All rights reserved. */

#include "oc.h"

/**
 * @brief OCODE operation attributes table
 *
 * This table defines the attributes for each OCODE operation.
 * The attributes control code generation behavior including:
 *
 * - Stack manipulation (pops/pushes)
 * - Register allocation hints
 * - Operation categorization
 *
 * Byte Layout:
 * - Byte 0: Unused (reserved)
 * - Byte 1: Pops from stack (0, 1, 2)
 * - Byte 2: Pushes onto stack (0, 1, 2 = set to n, 3 = set to n + 1)
 * - Byte 3: Code generation hints (0-7: force; 1-7: loadreg; 8: load op; 9:
 * data op)
 */

const char optab[][OPATTR] = {
    {0, 0, 0, 0}, /* 0: Unused */
    {0, 0, 0, 0}, /* 1: Unused */
    {0, 0, 0, 0}, /* 2: Unused */
    {0, 0, 0, 0}, /* 3: Unused */
    {1, 0, 1, 8}, /* 4: S_TRUE - Load constant true */
    {1, 0, 1, 8}, /* 5: S_FALSE - Load constant false */
    {0, 0, 0, 0}, /* 6: Unused */
    {0, 0, 0, 0}, /* 7: Unused */
    {1, 1, 1, 3}, /* 8: S_RV - Right-hand value (dereference) */
    {0, 0, 0, 0}, /* 9: Unused */
    {2, 1, 3, 1}, /* 10: S_FNAP - Function application */
    {1, 2, 1, 5}, /* 11: S_MULT - Multiplication */
    {1, 2, 1, 5}, /* 12: S_DIV - Division */
    {1, 2, 1, 5}, /* 13: S_REM - Remainder */
    {1, 2, 1, 4}, /* 14: S_PLUS - Addition */
    {1, 2, 1, 4}, /* 15: S_MINUS - Subtraction */
    {1, 0, 1, 8}, /* 16: S_QUERY - Query operator */
    {1, 1, 1, 3}, /* 17: S_NEG - Negation */
    {0, 0, 0, 0}, /* 18: Unused */
    {1, 1, 1, 3}, /* 19: S_ABS - Absolute value */
    {1, 2, 1, 4}, /* 20: S_EQ - Equality */
    {1, 2, 1, 4}, /* 21: S_NE - Inequality */
    {1, 2, 1, 4}, /* 22: S_LS - Less than */
    {1, 2, 1, 4}, /* 23: S_GR - Greater than */
    {1, 2, 1, 4}, /* 24: S_LE - Less or equal */
    {1, 2, 1, 4}, /* 25: S_GE - Greater or equal */
    {0, 0, 0, 0}, /* 26: Unused */
    {0, 0, 0, 0}, /* 27: Unused */
    {0, 0, 0, 0}, /* 28: Unused */
    {0, 0, 0, 0}, /* 29: Unused */
    {1, 1, 1, 3}, /* 30: S_NOT - Logical NOT */
    {1, 2, 1, 6}, /* 31: S_LSHIFT - Left shift */
    {1, 2, 1, 6}, /* 32: S_RSHIFT - Right shift */
    {1, 2, 1, 4}, /* 33: S_LOGAND - Logical AND */
    {1, 2, 1, 4}, /* 34: S_LOGOR - Logical OR */
    {1, 2, 1, 4}, /* 35: S_EQV - Equivalence */
    {1, 2, 1, 4}, /* 36: S_NEQV - Non-equivalence */
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 1, 8}, /* LP */
    {2, 0, 1, 8},                                           /* LG */
    {2, 0, 1, 8},                                           /* LN */
    {4, 0, 1, 8},                                           /* LSTR */
    {3, 0, 1, 8},                                           /* LL */
    {2, 0, 1, 8},                                           /* LLP */
    {2, 0, 1, 8},                                           /* LLG */
    {3, 0, 1, 8},                                           /* LLL */
    {0, 0, 0, 0}, {4, 0, 0, 0},                             /* SECTION */
    {0, 0, 0, 0}, {2, 1, 2, 1},                             /* RTAP */
    {1, 1, 0, 1},                                           /* GOTO */
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, /* FINISH */
    {0, 0, 0, 0}, {7, 1, 0, 3},                             /* SWITCHON */
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {6, 0, 0, 0},                             /* GLOBAL */
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {2, 1, 0, 2}, /* SP */
    {2, 1, 0, 2},                                           /* SG */
    {3, 1, 0, 2},                                           /* SL */
    {1, 2, 0, 6},                                           /* STIND */
    {0, 0, 0, 0}, {3, 0, 0, 0},                             /* JUMP */
    {3, 1, 0, 3},                                           /* JT */
    {3, 1, 0, 3},                                           /* JF */
    {3, 2, 0, 4},                                           /* ENDFOR */
    {3, 0, 0, 0},                                           /* BLAB */
    {3, 0, 0, 0},                                           /* LAB */
    {2, 0, 2, 0},                                           /* STACK */
    {1, 0, 0, 0},                                           /* STORE */
    {2, 0, 3, 0},                                           /* RSTACK */
    {5, 0, 0, 0},                                           /* ENTRY */
    {2, 0, 2, 0},                                           /* SAVE */
    {1, 1, 0, 3},                                           /* FNRN */
    {1, 0, 0, 0},                                           /* RTRN */
    {3, 1, 0, 3},                                           /* RES */
    {0, 0, 0, 0}, {3, 0, 0, 9},                             /* DATALAB */
    {3, 0, 0, 9},                                           /* ITEML */
    {2, 0, 0, 9},                                           /* ITEMN */
    {2, 0, 0, 0},                                           /* ENDPROC */
    {1, 0, 0, 0},                                           /* END */
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 2, 1, 4}, /* GETBYTE */
    {1, 2, 0, 4} /* PUTBYTE (actually 3 args) */
};
