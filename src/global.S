/**
 * @file global.s
 * @brief BCPL global vector definition and runtime support
 * @author Robert Nordier
 * @date 2004, 2012
 *
 * Defines the BCPL global vector (G) which provides access to runtime
 * functions and standard library routines. The global vector is a key
 * component of BCPL's runtime environment, providing a standardized
 * interface to system services.
 *
 * Global Vector Layout:
 * - G0-G99: Standard library functions
 * - G100+: User-defined global functions
 *
 * Key global functions include:
 * - I/O operations (RDCH, WRCH, etc.)
 * - Memory management (GETVEC, FREEVEC)
 * - String operations
 * - Mathematical functions
 * - System interface functions
 *
 * @see blib.bcpl for the BCPL implementations of many global functions
 * @see LIBHDR for global vector indices and function declarations
 */

// Copyright (c) 2004, 2012 Robert Nordier. All rights reserved.

// BCPL compiler x86 runtime

// This file defines the global vector; change as desired.

#if defined(__64BIT__)
    .set GLOBAL_ENTRY_SIZE_S, 8
#elif defined(__32BIT__)
    .set GLOBAL_ENTRY_SIZE_S, 4
#elif defined(__16BIT__)
    .set GLOBAL_ENTRY_SIZE_S, 2
#else
    // This will cause an assembly error if none of the bitness flags are defined by CMake.
    .error "Target bitness (__64BIT__, __32BIT__, or __16BIT__) not defined for global.s via assembler flags."
    // Provide a dummy value to allow parsing past the error for some assemblers, though the build will fail.
    .set GLOBAL_ENTRY_SIZE_S, 4
#endif

// Define the number of entries in the global vector
.set NUM_GLOBAL_ENTRIES_S, 400

	.bss            /* Use .bss section for zero-initialized data */
	.global G
G:
	// Reserve space for G: NUM_GLOBAL_ENTRIES_S * GLOBAL_ENTRY_SIZE_S bytes.
	// GLOBAL_ENTRY_SIZE_S is set above based on __xBIT__ flags passed by CMake.
	// This memory will be zero-initialized by the OS loader.
	.space NUM_GLOBAL_ENTRIES_S * GLOBAL_ENTRY_SIZE_S

// With G defined as a single block in .bss, individual Gx symbols are not
// defined here. Access to G[x] should be G + x*GLOBAL_ENTRY_SIZE_ASM.
// The .weak Gx directives are removed as they are no longer applicable
// to this way of defining G as a single contiguous block.
// If code relied on linking against individual Gx symbols, that code
// will need to be updated to calculate offsets from the base G symbol.
