/*─────────────────────────────────────────────────────────────────────────────
 *  global.s  ―  BCPL Global Vector  “G”
 *─────────────────────────────────────────────────────────────────────────────
 *  • One contiguous block of zeros whose size      = TOTAL_G_SPACE  bytes
 *  • Alignment guarantee                           = WORDSIZE_ALIGN_VAL
 *  • Link-time constants are injected from Makefile:
 *        $(AS) … --defsym TOTAL_G_SPACE=<bytes> \
 *                 --defsym WORDSIZE_ALIGN_VAL=<power-of-two>
 *
 *  Layout expectation (word-indexed):
 *    G[  0] – G[ 99]   : BCPL standard library jump table
 *    G[100] …          : user / runtime scratch
 *
 *  If you change GLOBALSIZE in the Makefile, that value is propagated here
 *  via TOTAL_G_SPACE, so no edits are needed in this file.
 *───────────────────────────────────────────────────────────────────────────*/

        .data

/* GNU as & clang-as both honour .globl / .global (alias). */
        .globl  G

/*---------------------------------------------------------------------------
 *  Align ‘G’ to word boundary — portable across GNU as & clang-as:
 *    .align n   (where n = 1,2,4,8 …)   on ELF / GNU
 *    .p2align k (k = log2(n))            on Mach-O
 *  We macro-select the directive at assemble-time.
 *---------------------------------------------------------------------------*/
#ifdef __APPLE__
        .p2align WORDSIZE_ALIGN_VAL /* clang-as Mach-O (expects power-of-two) */
#else
        .align  WORDSIZE_ALIGN_VAL  /* GNU as / ELF                          */
#endif

/*---------------------------------------------------------------------------
 *  The BCPL Global Vector
 *---------------------------------------------------------------------------*/
G:
        .space  TOTAL_G_SPACE       /* zero-filled by the loader */
#if defined(__ELF__)
        .type   G, @object
        .size   G, TOTAL_G_SPACE
#endif
