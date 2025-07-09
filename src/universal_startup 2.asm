; Universal BCPL Startup Code - NASM Format
; Compatible with multiple platforms and architectures
; 
; Build with: nasm -f elf64 universal_startup.asm (Linux x86_64)
;            nasm -f macho64 universal_startup.asm (macOS x86_64)
;            nasm -f elf32 universal_startup.asm (Linux i386)

%ifdef BITS64
    %define WORD_SIZE 8
    %define PTR_SIZE 8
%else
    %define WORD_SIZE 4
    %define PTR_SIZE 4
%endif

section .data
    global_vector: times 1000 dd 0  ; BCPL global vector
    stack_size: equ 4194304          ; 4MB BCPL stack

section .bss
    bcpl_stack: resb stack_size      ; BCPL stack allocation

section .text
    global _start
    global bcpl_main
    extern main                      ; C main function

_start:
    ; Universal startup - works on x86_64, i386, ARM64 (with modifications)
    
%ifdef BITS64
    ; 64-bit initialization
    mov rdi, global_vector           ; Global vector address
    mov rsi, rsp                     ; System stack pointer
    mov rdx, bcpl_stack + stack_size ; BCPL stack top
    call bcpl_init
%else
    ; 32-bit initialization  
    push global_vector
    push esp
    push bcpl_stack + stack_size
    call bcpl_init
    add esp, 12
%endif

    ; Call main program
    call main
    
    ; Exit
%ifdef BITS64
    mov rax, 60      ; sys_exit
    mov rdi, 0       ; exit status
    syscall
%else
    mov eax, 1       ; sys_exit
    mov ebx, 0       ; exit status
    int 0x80
%endif

bcpl_init:
    ; Portable initialization routine
    ; Arguments: global_vector, system_stack, bcpl_stack_top
    ; Returns: initialized runtime
    ret

; Universal system call interface
global bcpl_syscall
bcpl_syscall:
%ifdef BITS64
    ; x86_64 calling convention
    mov rax, rdi     ; syscall number
    mov rdi, rsi     ; arg1
    mov rsi, rdx     ; arg2  
    mov rdx, rcx     ; arg3
    syscall
    ret
%else
    ; i386 calling convention
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]  ; syscall number
    mov ebx, [ebp+12] ; arg1
    mov ecx, [ebp+16] ; arg2
    mov edx, [ebp+20] ; arg3
    int 0x80
    pop ebp
    ret
%endif
