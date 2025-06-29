// BCPL compiler IA-16 runtime system interface
// This is a very small DOS-like stub using INT 21h to implement a
// subset of the required system calls.  It is only sufficient for the
// test suite and should be replaced with a full implementation.

.code16
.set RESULT2,91

.global _exit, read, write, open, close, olseek
.global sbrk, ioctl, isatty

_exit:
        mov    4(%sp), %al
        mov    $0x4c, %ah
        int    $0x21

read:
        ret                     # not implemented
write:
        mov    4(%sp), %bx      # fd
        mov    6(%sp), %dx      # buf
        mov    8(%sp), %cx      # len
        mov    $0x40, %ah
        int    $0x21
        ret
open:
        ret                     # not implemented
close:
        ret                     # not implemented
olseek:
        ret                     # not implemented
sbrk:
        xor    %ax, %ax
        ret
ioctl:
        xor    %ax, %ax
        ret
isatty:
        xor    %ax, %ax
        ret

.data
curbrk:
        .word 0
