.data
ok_msg: .ascii "OK (isatty(0) likely successful, returned 1 for TTY)\n"
ok_msg_len = . - ok_msg

notty_msg: .ascii "OK (isatty(0) likely successful, returned 0 for non-TTY)\n"
notty_msg_len = . - notty_msg

err_msg_badfd_test: .ascii "OK (isatty(-1) correctly returned 0 and set RESULT2)\n"
err_msg_badfd_test_len = . - err_msg_badfd_test

fail_msg_badfd_val: .ascii "FAIL (isatty(-1) did not return 0)\n"
fail_msg_badfd_val_len = . - fail_msg_badfd_val

fail_msg_badfd_res2: .ascii "FAIL (isatty(-1) ret 0, but RESULT2 not EBADF (9))\n"
fail_msg_badfd_res2_len = . - fail_msg_badfd_res2

fail_msg_goodfd_err: .ascii "FAIL (isatty(0) returned non-0/1 or set RESULT2 unexpectedly)\n"
fail_msg_goodfd_err_len = . - fail_msg_goodfd_err

result2_label: .ascii "RESULT2 val: "
result2_label_len = . - result2_label
newline: .ascii "\n"

.text

# Define RESULT2_OFFSET locally for this test, mirroring sys_linux_x86_64.s
.set RESULT2_OFFSET, 91*8

.global _start

# Helper to print a 64-bit number in hex (simplified, positive only)
# Input: %rdi = number to print
# Output: prints to stdout
# Clobbers: rax, rsi, rdx, rcx, r8-r11
print_hex:
    pushq %rdi
    pushq %rsi
    pushq %rdx
    pushq %rcx
    pushq %rbp
    movq %rsp, %rbp

    movq $hex_buffer + 15, %rsi # End of buffer for null terminator + last char
    movb $0, (%rsi)             # Null terminate
    movq %rdi, %rax             # Number to convert
    movq $16, %rcx              # Base 16

    cmpq $0, %rax
    je .print_hex_zero

.print_hex_loop:
    xorq %rdx, %rdx             # Clear rdx for div
    divq %rcx                   # rax = rax / 16, rdx = rax % 16
    cmpb $10, %dl
    jl .print_hex_digit
    addb $'A'-10, %dl           # Convert 10-15 to A-F
    jmp .print_hex_store
.print_hex_digit:
    addb $'0', %dl              # Convert 0-9 to '0'-'9'
.print_hex_store:
    decq %rsi
    movb %dl, (%rsi)
    testq %rax, %rax            # Is quotient zero?
    jnz .print_hex_loop
    jmp .print_hex_do_write

.print_hex_zero:
    decq %rsi
    movb $'0', (%rsi)

.print_hex_do_write:
    # Now %rsi points to the start of the hex string
    movq %rsi, %r8              # Save start of string
    movq $hex_buffer + 16, %r9  # End of buffer
    subq %r8, %r9               # r9 = length of string

    movq $1, %rax               # syscall write
    movq $1, %rdi               # fd stdout
    # rsi is already start of string
    movq %r9, %rdx              # length
    syscall

    movq %rbp, %rsp
    popq %rbp
    popq %rcx
    popq %rdx
    popq %rsi
    popq %rdi
    ret

_start:
    # Test 1: Call isatty with a bad FD (-1)
    movq $-1, %rdi      # Pass -1 as fd to isatty
    call isatty         # rax should be 0 (error/not tty), RESULT2 should be EBADF (9)

    movq G+RESULT2_OFFSET, %rbx # Get RESULT2 into rbx (for checking)
                                # RESULT2_OFFSET is 91*8 = 728

    cmpq $0, %rax
    jne .test1_fail_retval # Should return 0

    cmpq $9, %rbx # Check if RESULT2 is EBADF (9)
    jne .test1_fail_result2

    # Test 1 Success Path
    movq $1, %rax       # syscall write
    movq $1, %rdi       # fd stdout
    movq $err_msg_badfd_test, %rsi
    movq $err_msg_badfd_test_len, %rdx
    syscall
    jmp .test2

.test1_fail_retval:
    movq $1, %rax
    movq $1, %rdi
    movq $fail_msg_badfd_val, %rsi
    movq $fail_msg_badfd_val_len, %rdx
    syscall
    jmp .print_result2_and_exit # Print RESULT2 to help debug

.test1_fail_result2:
    movq $1, %rax
    movq $1, %rdi
    movq $fail_msg_badfd_res2, %rsi
    movq $fail_msg_badfd_res2_len, %rdx
    syscall
    # Fall through to print RESULT2

.print_result2_and_exit:
    movq $1, %rax
    movq $1, %rdi
    movq $result2_label, %rsi
    movq $result2_label_len, %rdx
    syscall
    movq %rbx, %rdi # Value of RESULT2 that was in rbx
    call print_hex
    movq $1, %rax
    movq $1, %rdi
    movq $newline, %rsi
    movq $1, %rdx
    syscall
    jmp .exit_program_fail # Exit with error after printing RESULT2

.test2:
    # Test 2: Call isatty with FD 0 (stdin)
    # Clear RESULT2 first to ensure we see if isatty(0) sets it on error
    movq $0, G+RESULT2_OFFSET

    movq $0, %rdi       # Pass 0 as fd to isatty
    call isatty         # rax should be 1 (if stdin is a tty) or 0 (if not)
                        # RESULT2 should be 0 if no *new* error for this call

    movq G+RESULT2_OFFSET, %rbx # Get RESULT2

    cmpq $0, %rax
    je .test2_is_not_tty
    cmpq $1, %rax
    je .test2_is_tty
    # If neither 0 nor 1, it's an unexpected return value
    jmp .test2_fail

.test2_is_tty:
    # isatty(0) returned 1. Check RESULT2 is still 0 (no error)
    cmpq $0, %rbx
    jne .test2_fail # RESULT2 was set, unexpected
    movq $1, %rax
    movq $1, %rdi
    movq $ok_msg, %rsi
    movq $ok_msg_len, %rdx
    syscall
    jmp .exit_program_ok

.test2_is_not_tty:
    # isatty(0) returned 0. Check RESULT2 is still 0 (no error)
    cmpq $0, %rbx
    jne .test2_fail # RESULT2 was set, unexpected (unless fd 0 itself is bad, unlikely for this test)
    movq $1, %rax
    movq $1, %rdi
    movq $notty_msg, %rsi
    movq $notty_msg_len, %rdx
    syscall
    jmp .exit_program_ok

.test2_fail:
    movq $1, %rax
    movq $1, %rdi
    movq $fail_msg_goodfd_err, %rsi
    movq $fail_msg_goodfd_err_len, %rdx
    syscall
    jmp .print_result2_and_exit # Also prints RESULT2

.exit_program_ok:
    movq $60, %rax      # syscall exit
    xorq %rdi, %rdi     # exit code 0
    syscall

.exit_program_fail:
    movq $60, %rax      # syscall exit
    movq $1, %rdi     # exit code 1
    syscall

.bss
.align 8
hex_buffer: .space 17 # For 16 hex digits + null
