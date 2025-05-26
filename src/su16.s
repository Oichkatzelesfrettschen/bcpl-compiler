.ifndef BITS
.set BITS,16
.endif

// Simplified IA-16 startup code

.set    STKSIZ,0x2000         # BCPL stack size for 16-bit

.set    START,1
.set    STACKBASE,95
.set    STACKEND,96
.set    ARGC,97
.set    ARGV,98
.set    PARAM,99

.global _start, _stop, finish

_start:
        cld
        call    rtinit
        mov     $G, %di
        movw    START*2(%di), %ax
        call    *%ax
finish:
        xor     %ax, %ax
_stop:
        call    rtexit
        ret
