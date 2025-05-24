// Copyright (c) 2004, 2012 Robert Nordier. All rights reserved.

// BCPL compiler x86 runtime
// System interface: Linux

.ifndef BITS
.set BITS,32
.endif

.if BITS==64

        .set    RESULT2,91              # BCPL RESULT2

        .global _exit
_exit:  mov     8(%rsp),%edi
        mov     $60,%eax
        syscall

        .global read
read:   mov     8(%rsp),%edi
        mov     16(%rsp),%rsi
        mov     24(%rsp),%edx
        mov     $0,%eax
        jmp     syscall

        .global write
write:  mov     8(%rsp),%edi
        mov     16(%rsp),%rsi
        mov     24(%rsp),%edx
        mov     $1,%eax
        jmp     syscall

        .global open
open:   mov     8(%rsp),%rdi
        mov     16(%rsp),%rsi
        mov     24(%rsp),%edx
        mov     $2,%eax
        jmp     syscall

        .global close
close:  mov     8(%rsp),%edi
        mov     $3,%eax
        jmp     syscall

        .global olseek
olseek: mov     8(%rsp),%edi
        mov     16(%rsp),%rsi
        mov     24(%rsp),%edx
        mov     $8,%eax
        jmp     syscall

        .global sbrk
sbrk:   mov     curbrk(%rip),%rax
        test    %rax,%rax
        jnz     1f
        mov     %rax,%rdi
        call    brk
1:      mov     %rax,%r10               # old break
        mov     8(%rsp),%rcx
        mov     %r10,%rdi
        add     %rcx,%rdi
        call    brk
        mov     %r10,%rax
        ret

brk:    mov     $12,%eax
        jmp     syscall

        .global ioctl
ioctl:  mov     8(%rsp),%rdi
        mov     16(%rsp),%rsi
        mov     24(%rsp),%rdx
        mov     $16,%eax

syscall:
        syscall
        cmp     $0,%rax
        jge     1f
        neg     %rax
        mov     %eax,G+RESULT2*4
        mov     $-1,%eax
        stc
1:      ret

        .set    TERMIOSZ,0x40
        .set    TCGETS,0x5401

        .global isatty
isatty: sub     $TERMIOSZ,%rsp
        mov     TERMIOSZ+8(%rsp),%rdi
        mov     $TCGETS,%esi
        mov     %rsp,%rdx
        call    ioctl
        mov     $0,%eax
        jc      1f
        inc     %eax
1:      add     $TERMIOSZ,%rsp
        ret

        .global oflags
oflags: .long   01101

        .data
curbrk: .quad   0

.else

        .set    RESULT2,91              # BCPL RESULT2

        .global _exit
_exit:  mov     $1,%eax
        jmp     syscall

        .global read
read:   mov     $3,%eax
        jmp     syscall

        .global write
write:  mov     $4,%eax
        jmp     syscall

        .global open
open:   mov     $5,%eax
        jmp     syscall

        .global close
close:  mov     $6,%eax
        jmp     syscall

        .global olseek
olseek: mov     $0x13,%eax
        jmp     syscall

        .global sbrk
sbrk:   mov     curbrk,%eax
        test    %eax,%eax
        jnz     1f
        call    brk
1:      push    %eax
        add     8(%esp),%eax
        call    brk
        pop     %eax
        ret

brk:    push    %eax
        mov     $45,%eax
        call    syscall
        pop     %ecx
        mov     %eax,curbrk
        ret

        .global ioctl
ioctl:  mov     $0x36,%eax

syscall:push    %edx
        push    %ecx
        push    %ebx
        mov     0x10(%esp),%ebx
        mov     0x14(%esp),%ecx
        mov     0x18(%esp),%edx
        int     $0x80
        or      %eax,%eax
        jge     1f
        neg     %eax
        mov     %eax,G+RESULT2*4        # Set error code
        mov     $-1,%eax
        stc
1:      pop     %ebx
        pop     %ecx
        pop     %edx
        ret

        .set    TERMIOSZ,0x40
        .set    TCGETS,0x5401

        .global isatty
isatty: sub     $TERMIOSZ,%esp
        push    %esp
        push    $TCGETS
        push    0xc+TERMIOSZ(%esp)
        call    ioctl
        mov     $0,%eax
        jc      1f
        inc     %eax
1:      add     $0xc+TERMIOSZ,%esp
        ret

// Set to the value of O_TRUNC | O_CREAT | O_WRONLY in <fcntl.h>
        .global oflags
oflags: .long   01101

        .data
curbrk: .long   0

.endif
