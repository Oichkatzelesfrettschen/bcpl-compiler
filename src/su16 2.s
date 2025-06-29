// BCPL compiler IA-16 startup code (experimental)
// Minimal stub that sets up a small stack and jumps to the BCPL entry
// point defined in the global vector.  Real implementations should
// populate ARGC/ARGV properly and handle environment setup.

.code16

.set    STKSIZ,0x4000         # 16 KiB stack
.set    START,1
.set    STACKBASE,95
.set    STACKEND,96
.set    ARGC,97
.set    ARGV,98
.set    PARAM,99

.global _start, _stop, finish

_start:
        cli
        mov    $G, %di         # Global vector
        mov    %sp, %ax
        mov    %ax, STACKEND*2(%di)
        sub    $STKSIZ, %sp
        mov    %sp, %bp
        mov    %sp, %ax
        mov    %ax, STACKBASE*2(%di)
        mov    $0, PARAM*2(%di)
        call   rtinit
        mov    $G, %di
        mov    %bp, %cx
        mov    START*2(%di), %ax
        call   *%ax            # To BCPL start
finish:
        xor    %ax, %ax
_stop:
        push   %ax
        call   rtexit
        call   _exit
