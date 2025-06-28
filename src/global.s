/*
BCPL Global Vector G
Defines G as a block of memory.
The size of this block (TOTAL_G_SPACE) and its alignment (WORDSIZE_ALIGN_VAL)
are calculated in src/Makefile and passed to the assembler via --defsym.

GLOBALSIZE (number of words in G) is assumed to be 400 for this calculation.
If GLOBALSIZE needs to change, it should be changed in src/Makefile where
TOTAL_G_SPACE_VAL is calculated.

Initialization of G entries (e.g., with function pointers or initial values for
stdin, stdout, RESULT2, etc.) is assumed to be handled by startup code (su.s)
or by the BCPL system itself (e.g., st compiler/runtime).
*/

        .data                   /* Global variables are typically in .data or .bss */
        .global G               /* Export the symbol G */
        .align WORDSIZE_ALIGN_VAL  /* Align G to the word size boundary (passed from Makefile) */
G:
        .space  TOTAL_G_SPACE      /* Reserve space for G (total bytes, passed from Makefile) */
                                /* This memory will be zero-initialized by default */
                                /* when the program loads. */
