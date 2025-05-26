// Minimal IA-16 system interface stubs

.set RESULT2,91

.global _exit
_exit:
        mov     $0x4c00, %ax
        int     $0x21

.global read, write, open, close, olseek, sbrk, ioctl
read:
write:
open:
close:
olseek:
sbrk:
ioctl:
        stc
        mov     $-1, %ax
        ret

.global isatty
isatty:
        mov     $1, %ax
        ret

        .data
oflags: .word 01101
curbrk: .word 0
