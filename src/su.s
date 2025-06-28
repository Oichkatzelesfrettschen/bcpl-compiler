/**
 * @file su.s
 * @brief BCPL compiler x86 startup code
 * @author Robert Nordier
 * @copyright Copyright (c) 2004, 2012 Robert Nordier. All rights reserved.
 * 
 * This file provides the startup and initialization code for BCPL programs.
 * It sets up the BCPL runtime environment, initializes the global vector,
 * allocates the BCPL stack, and transfers control to the BCPL program.
 * 
 * ## Architecture Support
 * The startup code supports both 32-bit and 64-bit x86 architectures
 * through conditional assembly based on the BITS preprocessor variable.
 * 
 * ## BCPL Runtime Environment
 * The startup code establishes:
 * - Global vector for inter-module communication
 * - BCPL stack separate from the system stack
 * - Command-line argument processing
 * - Standard global variables (ARGC, ARGV, etc.)
 * 
 * ## Memory Layout
 * - System stack: Used for system calls and startup
 * - BCPL stack: Separate stack for BCPL program execution
 * - Global vector: Fixed-size array for global variables
 * - Heap: Managed separately by the BCPL runtime
 */

// Copyright (c) 2004, 2012 Robert Nordier. All rights reserved.

// BCPL compiler x86 startup code

/**
 * @brief Architecture configuration
 * Default to 32-bit if BITS is not defined
 */
.ifndef BITS
.set BITS,32
.endif

/**
 * @brief BCPL stack size configuration
 * The BCPL stack is separate from the system stack and is used
 * for all BCPL program execution. This can be adjusted based on
 * program requirements.
 */
        .set    STKSIZ,0x400000         # BCPL stack size (4MB default)

/**
 * @brief BCPL global vector slot assignments
 * These constants define the standard global vector slots used
 * by the BCPL runtime system.
 */
        .set    START,1                 # Entry point function (global 1)
        .set    STACKBASE,95           # Base of BCPL stack
        .set    STACKEND,96            # End of BCPL stack  
        .set    ARGC,97                # Command line argument count
        .set    ARGV,98                # Command line argument vector
        .set    PARAM,99               # Parameter string

/**
 * @brief Exported symbols for linker
 * These symbols are referenced by the BCPL runtime and linker
 */
        .global _start, _stop, finish

/**
 * @brief Program entry point
 * 
 * This is the main entry point called by the operating system.
 * It performs the following initialization:
 * 1. Sets up the BCPL global vector
 * 2. Processes command-line arguments
 * 3. Allocates and initializes the BCPL stack
 * 4. Transfers control to the BCPL START function
 */

_start:
        cld
.if BITS==64
        mov     $G,%rdi                 # Global vector
        mov     (%rsp),%ecx             # UNIX argc
        lea     8(%rsp),%rbx            # UNIX argv

        mov     %rsp,%rax
        shr     $2,%eax
        mov     %eax,STACKEND*4(%rdi)   # Define STACKEND
        sub     $STKSIZ,%rsp
        mov     %rsp,%rbp               # Set BCPL stack
        sub     $STKSIZ>>2,%eax
        mov     %eax,STACKBASE*4(%rdi)  # Define STACKBASE

        mov     %ecx,ARGC*4(%rdi)       # Define ARGC
        inc     %ecx
        sub     %ecx,%eax
        mov     %eax,ARGV*4(%rdi)       # Define ARGV
        shl     $2,%ecx
        sub     %rcx,%rsp
        mov     %rsp,%rdx               # BCPL argv

        xor     %ecx,%ecx
1:      mov     (%rbx),%rsi             # Get UNIX arg
        test    %rsi,%rsi               # NULL?
        jz      1f
        xor     %eax,%eax
        mov     %eax,-4(%rsp)           # Zero last cell
        mov     %rsi,%rdi
        inc     %ch
        repne   scasb
        xor     $255,%cl
        mov     %ecx,%eax               # String length
        or      $3,%al
        inc     %eax
        sub     %rax,%rsp               # Allocate space
        mov     %rsp,%rdi
        mov     %rdi,%rax
        shr     $2,%eax
        mov     %eax,(%rdx)             # BCPL pointer
        mov     %cl,(%rdi)              # Convert string
        inc     %rdi
        rep     movsb
        add     $8,%rbx                 # Bump for next arg
        add     $4,%rdx
        jmp     1b
1:      mov     %esi,(%rdx)

        call    rtinit                  # Runtime setup
        mov     $G,%rdi                 # Global vector

        mov     ARGV*4(%rdi),%eax
        inc     %eax
        mov     (,%rax,4),%ecx
        jecxz   1f
        mov     %ecx,%eax
1:      mov     %eax,PARAM*4(%rdi)      # Define PARAM

        mov     %eax,8(%rbp)            # As arg
        mov     %rbp,%rcx
        mov     START*4(%rdi),%eax
        call    *%rax                   # To BCPL start
.else
        mov     $G,%edi                 # Global vector
        mov     (%esp),%ecx             # UNIX argc
        lea     4(%esp),%ebx            # UNIX argv

        mov     %esp,%eax
        shr     $2,%eax
        mov     %eax,STACKEND*4(%edi)   # Define STACKEND
        sub     $STKSIZ,%esp
        mov     %esp,%ebp               # Set BCPL stack
        sub     $STKSIZ>>2,%eax
        mov     %eax,STACKBASE*4(%edi)  # Define STACKBASE

        mov     %ecx,ARGC*4(%edi)       # Define ARGC
        inc     %ecx
        sub     %ecx,%eax
        mov     %eax,ARGV*4(%edi)       # Define ARGV
        shl     $2,%ecx
        sub     %ecx,%esp
        mov     %esp,%edx               # BCPL argv

        xor     %ecx,%ecx
1:      mov     (%ebx),%esi             # Get UNIX arg
        test    %esi,%esi               # NULL?
        jz      1f
        xor     %eax,%eax
        mov     %eax,-4(%esp)           # Zero last cell
        mov     %esi,%edi
        inc     %ch
        repne   scasb
        xor     $255,%cl
        mov     %ecx,%eax               # String length
        or      $3,%al
        inc     %eax
        sub     %eax,%esp               # Allocate space
        mov     %esp,%edi
        mov     %edi,%eax
        shr     $2,%eax
        mov     %eax,(%edx)             # BCPL pointer
        mov     %cl,(%edi)              # Convert string
        inc     %edi
        rep     movsb
        add     $4,%ebx                 # Bump for
        add     $4,%edx                 #  next arg
        jmp     1b
1:      mov     %esi,(%edx)

        call    rtinit                  # Runtime setup
        mov     $G,%edi                 # Global vector

        mov     ARGV*4(%edi),%eax
        inc     %eax
        mov     (,%eax,4),%ecx
        jecxz    1f
        mov     %ecx,%eax
1:      mov     %eax,PARAM*4(%edi)      # Define PARAM

        mov     %eax,8(%ebp)            # As arg
        mov     %ebp,%ecx
        call    *START*4(%edi)          # To BCPL start
.endif
finish:
        xor     %eax,%eax               # Exit code
_stop:
.if BITS==64
        mov     %eax,%edi
        call    rtexit                  # Runtime cleanup
        call    _exit                   # Terminate
.else
        push    %eax
        call    rtexit                  # Runtime cleanup
        call    _exit                   # Terminate
.endif
