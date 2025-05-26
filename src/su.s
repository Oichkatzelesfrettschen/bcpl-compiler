// Copyright (c) 2004, 2012 Robert Nordier. All rights reserved.

// BCPL compiler x86 startup code

.ifndef BITS
.set BITS,32
.endif

// The following setting can be changed as desired.
        .set    STKSIZ,0x400000         # BCPL stack size

// BCPL globals
        .set    START,1
        .set    STACKBASE,95
        .set    STACKEND,96
        .set    ARGC,97
        .set    ARGV,98
        .set    PARAM,99

        .global _start, _stop, finish

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
.elseif BITS==32
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
.elseif BITS==16
        mov     $G,%di                  # Global vector
        call    rtinit
        movw    START*2(%di),%ax
        call    *%ax                    # To BCPL start
.endif
finish:
        xor     %eax,%eax               # Exit code
_stop:
.if BITS==64
        mov     %eax,%edi
        call    rtexit                  # Runtime cleanup
        call    _exit                   # Terminate
.elseif BITS==32
        push    %eax
        call    rtexit                  # Runtime cleanup
        call    _exit                   # Terminate
.elseif BITS==16
        call    rtexit                  # Runtime cleanup
        ret
.endif
