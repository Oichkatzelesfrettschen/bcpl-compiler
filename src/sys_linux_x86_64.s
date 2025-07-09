# BCPL compiler x86_64 runtime
# System interface: Linux (64-bit)

# Syscall numbers from <asm/unistd_64.h>
.equ SYS_READ, 0
.equ SYS_WRITE, 1
.equ SYS_OPEN, 2
.equ SYS_CLOSE, 3
.equ SYS_LSEEK, 8
.equ SYS_MMAP, 9       # For sbrk emulation
.equ SYS_BRK, 12       # For sbrk emulation / direct brk
.equ SYS_IOCTL, 16
.equ SYS_EXIT, 60
.equ SYS_GETCWD, 79    # Not in original, but good for reference

# BCPL RESULT2 global variable offset (assuming G is base pointer for globals)
# Needs to be confirmed how G is defined and accessed in BCPL runtime
# For now, assuming G is a label pointing to a block of memory.
# If G is a register, this needs adjustment.
.set    RESULT2_OFFSET, 91*8            # RESULT2 is word 91, 8 bytes/word for 64-bit

        .text
        .global _exit
_exit:
        mov     %rdi, %rdi              # Arg1: status (already in rdi from C calling convention)
        mov     $SYS_EXIT, %rax
        syscall
        # Should not return

        .global read
read:
        # BCPL: read(fd, buffer, count)
        # Linux: read(fd, buf, count)
        # Args: rdi (fd), rsi (buffer), rdx (count)
        mov     $SYS_READ, %rax
        syscall
        # Return: rax (bytes read or -errno)
        cmp     $0, %rax
        jge     .read_ok
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $-1, %rax               # Return -1 for error in BCPL
.read_ok:
        ret

        .global write
write:
        # BCPL: write(fd, buffer, count)
        # Linux: write(fd, buf, count)
        # Args: rdi (fd), rsi (buffer), rdx (count)
        mov     $SYS_WRITE, %rax
        syscall
        # Return: rax (bytes written or -errno)
        cmp     $0, %rax
        jge     .write_ok
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $-1, %rax               # Return -1 for error in BCPL
.write_ok:
        ret

        .global open
open:
        # BCPL: open(name, mode) - BCPL mode might need translation
        # Linux: open(pathname, flags, mode_t)
        # Args: rdi (name), rsi (BCPL mode)
        # Assuming BCPL mode maps directly to Linux flags for now.
        # For creat(), mode (3rd arg for open) would be needed.
        # The original sys_linux.s open takes 2 args.
        mov     %rsi, %rsi              # flags
        mov     $0, %rdx                # mode_t (permissions, set to 0 if not creating)
        mov     $SYS_OPEN, %rax
        syscall
        # Return: rax (fd or -errno)
        cmp     $0, %rax
        jge     .open_ok
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $-1, %rax               # Return -1 for error in BCPL
.open_ok:
        ret

        .global close
close:
        # BCPL: close(fd)
        # Linux: close(fd)
        # Arg: rdi (fd)
        mov     $SYS_CLOSE, %rax
        syscall
        # Return: rax (0 or -errno)
        cmp     $0, %rax
        jge     .close_ok
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $-1, %rax               # Return -1 for error in BCPL
.close_ok:
        ret

        .global olseek # "old lseek"
olseek:
        # BCPL: olseek(fd, offset, whence)
        # Linux: lseek(fd, offset, whence)
        # Args: rdi (fd), rsi (offset), rdx (whence)
        mov     $SYS_LSEEK, %rax
        syscall
        # Return: rax (new offset or -errno)
        cmp     $0, %rax
        jge     .olseek_ok
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $-1, %rax               # Return -1 for error in BCPL
.olseek_ok:
        ret

# sbrk implementation using brk syscall
# curbrk_val needs to be defined in .data or .bss

        .data
        .align 16
# Simple static heap for testing sbrk
static_heap_space:
        .space 16384  # 16KB static heap
static_heap_ptr:
        .quad static_heap_space
static_heap_end:
        .quad static_heap_space + 16384

        .text
        .global sbrk
sbrk:
        # Simplified sbrk for testing - uses a static buffer
        # Arg: rdi (increment)
        push    %rbx                    # Save rbx
        push    %rcx                    # Save rcx
        push    %rsi                    # Save rsi

        mov     static_heap_ptr(%rip), %rax  # current heap pointer
        mov     %rax, %rbx                   # rbx = old heap pointer (return value on success)
        add     %rdi, %rax                   # rax = new potential heap pointer

        mov     static_heap_end(%rip), %rcx  # rcx = end of static heap
        cmp     %rax, %rcx                   # is new_ptr > end_of_heap?
        jle     .sbrk_in_bounds              # If new_ptr <= end_of_heap, it's ok (simple check)

        # Out of bounds / sbrk failure
        movq    $12, G+RESULT2_OFFSET        # ENOMEM
        mov     $-1, %rax                    # Return -1 for BCPL error
        jmp     .sbrk_done

.sbrk_in_bounds:
        mov     %rax, static_heap_ptr(%rip)  # Update heap pointer
        mov     %rbx, %rax                   # Return old heap pointer

.sbrk_done:
        pop     %rsi
        pop     %rcx
        pop     %rbx
        ret

        .global ioctl
ioctl:
        # BCPL: ioctl(fd, request, data)
        # Linux: ioctl(fd, request, argp)
        # Args: rdi (fd), rsi (request), rdx (data)
        mov     $SYS_IOCTL, %rax
        syscall
        # Return: rax (0 or -errno)
        cmp     $0, %rax
        jge     .ioctl_ok
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $-1, %rax               # Return -1 for error in BCPL
.ioctl_ok:
        ret

.set    TERMIOSZ_64, 0x38 # Approximate size for termios struct on 64-bit, may vary.
                          # For isatty, we only care if TCGETS succeeds, not struct content.
.set    TCGETS_64, 0x5401 # From <sys/ioctl.h>, usually same across architectures

        .global isatty
isatty:
        # BCPL: isatty(fd)
        # Arg: rdi (fd)
        sub     $TERMIOSZ_64, %rsp      # Allocate space on stack for termios struct
        mov     %rsp, %rdx              # argp for ioctl = pointer to stack space
        # rdi (fd) is already set by caller for the syscall
        mov     $TCGETS_64, %rsi        # request for ioctl

        mov     $SYS_IOCTL, %rax
        syscall                         # rax = 0 on success, or -errno on error

        add     $TERMIOSZ_64, %rsp      # Deallocate stack space

        cmp     $0, %rax
        jl      .isatty_error           # Syscall error (e.g., -EBADF)

        # Syscall success (ioctl itself returned 0 for TCGETS)
        mov     $1, %rax                # isatty returns 1 (is a TTY)
        # Optionally clear RESULT2 if successful and BCPL expects this
        # movq    $0, G+RESULT2_OFFSET
        ret

.isatty_error:
        neg     %rax                    # rax = positive errno
        movq    %rax, G+RESULT2_OFFSET  # Store errno in RESULT2
        mov     $0, %rax                # isatty returns 0 (not a TTY / error)
        ret

        # Set to the value of O_TRUNC | O_CREAT | O_WRONLY from <fcntl.h>
        # O_TRUNC = 01000
        # O_CREAT = 00100
        # O_WRONLY= 00001
        # Total   = 01101 (decimal 577)
        .global oflags
oflags:
        .quad   01101

        .data
        .align 8
curbrk_val:
        .quad   0                   # Current break address for sbrk emulation

# Placeholder for BCPL global variable RESULT2 handling
# This needs to be properly integrated with how BCPL runtime manages globals.
# If 'G' is a register, then these direct memory accesses won't work.
# The original sys_linux.s used: mov %eax,G+RESULT2*4
# For 64-bit, it would be G+RESULT2_OFFSET or similar.
# For now, the error setting lines are commented out.
# G: .space 100*8 # Example if G were a label for a global block
