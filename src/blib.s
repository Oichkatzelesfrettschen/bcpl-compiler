	.text
	jmp L11
//	WRITES
L1:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	movl $1,12(%rbp)
	movl 8(%rbp),%eax
	shl $2,%eax
	movzb (%rax),%eax
	movl %eax,16(%rbp)
	jmp L12
L13:
	movl 8(%rbp),%eax
	shl $2,%eax
	addl 12(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,28(%rbp)
	leal 20(%rbp),%ecx
	call *56(%rdi)
	incl 12(%rbp)
L12:
	movl 12(%rbp),%eax
	cmpl 16(%rbp),%eax
	jle L13
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITED
L2:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	leal 28(%rbp),%eax
	shr $2,%eax
	movl %eax,16(%rbp)
	movl $0,20(%rbp)
	movl 8(%rbp),%eax
	movl %eax,24(%rbp)
	cmpl $0,8(%rbp)
	jge L14
	decl 12(%rbp)
	jmp L15
L14:
	movl 8(%rbp),%eax
	negl %eax
	movl %eax,24(%rbp)
L15:
L16:
	movl 24(%rbp),%eax
	movl $10,%ecx
	cqto
	idivl %ecx
	mov %edx,%eax
	movl %eax,112(%rbp)
	movl 20(%rbp),%eax
	addl 16(%rbp),%eax
	mov %eax,%ecx
	movl 112(%rbp),%eax
	mov %eax,(,%rcx,4)
	movl 24(%rbp),%eax
	movl $10,%ecx
	cqto
	idivl %ecx
	movl %eax,24(%rbp)
	incl 20(%rbp)
	cmpl $0,24(%rbp)
	jne L16
	movl 20(%rbp),%eax
	incl %eax
	movl %eax,112(%rbp)
	movl 12(%rbp),%eax
	movl %eax,116(%rbp)
	jmp L17
L18:
	movl $32,128(%rbp)
	leal 120(%rbp),%ecx
	call *56(%rdi)
	incl 112(%rbp)
L17:
	movl 112(%rbp),%eax
	cmpl 116(%rbp),%eax
	jle L18
	cmpl $0,8(%rbp)
	jge L19
	movl $45,120(%rbp)
	leal 112(%rbp),%ecx
	call *56(%rdi)
L19:
	movl 20(%rbp),%eax
	decl %eax
	movl %eax,112(%rbp)
	jmp L20
L21:
	movl $48,124(%rbp)
	movl 112(%rbp),%eax
	addl 16(%rbp),%eax
	mov (,%rax,4),%eax
	mov %eax,%ecx
	movl 124(%rbp),%eax
	subl %ecx,%eax
	movl %eax,124(%rbp)
	leal 116(%rbp),%ecx
	call *56(%rdi)
	decl 112(%rbp)
L20:
	cmpl $0,112(%rbp)
	jge L21
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEN
L3:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	movl 8(%rbp),%eax
	movl %eax,20(%rbp)
	movl $0,24(%rbp)
	leal 12(%rbp),%ecx
	call *272(%rdi)
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	NEWLINE
L4:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	movl $10,16(%rbp)
	leal 8(%rbp),%ecx
	call *56(%rdi)
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	NEWPAGE
L5:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	movl $12,16(%rbp)
	leal 8(%rbp),%ecx
	call *56(%rdi)
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	READN
L6:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	movl $0,8(%rbp)
	movl $0,12(%rbp)
L23:
	leal 16(%rbp),%ecx
	call *52(%rdi)
	movl %eax,284(%rdi)
	jmp L25
L27:
L28:
L29:
	jmp *L24
L30:
	movl $-1,12(%rbp)
L31:
	leal 16(%rbp),%ecx
	call *52(%rdi)
	movl %eax,284(%rdi)
	jmp L26
L25:
	movl 284(%rdi),%eax
	mov $L999,%rdx
	mov $5,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L26
3:	jmp *4(%rdx)
L26:
	jmp L33
L32:
	movl 8(%rbp),%eax
	movl $10,%ecx
	imull %ecx
	addl 284(%rdi),%eax
	subl $48,%eax
	movl %eax,8(%rbp)
	leal 16(%rbp),%ecx
	call *52(%rdi)
	movl %eax,284(%rdi)
L33:
	cmpl $48,284(%rdi)
	jl L34
	cmpl $57,284(%rdi)
	jle L32
L34:
	movl 12(%rbp),%eax
	orl %eax,%eax
	jz L35
	negl 8(%rbp)
L35:
	movl 8(%rbp),%eax
L22:
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEOCT
L7:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	cmpl $1,12(%rbp)
	jle L36
	movl 8(%rbp),%eax
	movl $3,%ecx
	shrl %cl,%eax
	movl %eax,24(%rbp)
	movl 12(%rbp),%eax
	decl %eax
	movl %eax,28(%rbp)
	leal 16(%rbp),%ecx
	call *308(%rdi)
L36:
	movl $7,%eax
	andl 8(%rbp),%eax
	addl $48,%eax
	movl %eax,24(%rbp)
	leal 16(%rbp),%ecx
	call *56(%rdi)
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEHEX
L8:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	cmpl $1,12(%rbp)
	jle L37
	movl 8(%rbp),%eax
	movl $4,%ecx
	shrl %cl,%eax
	movl %eax,24(%rbp)
	movl 12(%rbp),%eax
	decl %eax
	movl %eax,28(%rbp)
	leal 16(%rbp),%ecx
	call *300(%rdi)
L37:
	movl $15,%eax
	andl 8(%rbp),%eax
	movl $L38,%ecx
	shr $2,%ecx
	addl %ecx,%eax
	mov (,%rax,4),%eax
	movl %eax,24(%rbp)
	leal 16(%rbp),%ecx
	call *56(%rdi)
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEF
L9:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	leal 12(%rbp),%eax
	shr $2,%eax
	movl %eax,56(%rbp)
	movl $1,60(%rbp)
	movl 8(%rbp),%eax
	shl $2,%eax
	movzb (%rax),%eax
	movl %eax,64(%rbp)
	jmp L39
L40:
	movl 8(%rbp),%eax
	shl $2,%eax
	addl 60(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,68(%rbp)
	cmpl $37,68(%rbp)
	jne L41
	movl $0,72(%rbp)
	movl $0,%eax
	addl 56(%rbp),%eax
	mov (,%rax,4),%eax
	movl %eax,76(%rbp)
	movl $0,80(%rbp)
	movl 8(%rbp),%eax
	movl %eax,84(%rbp)
	movl 60(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 84(%rbp),%eax
	shl $2,%eax
	addl %ecx,%eax
	movzb (%rax),%eax
	movl %eax,84(%rbp)
	incl 60(%rbp)
	jmp L47
L49:
	movl 84(%rbp),%eax
	movl %eax,96(%rbp)
	leal 88(%rbp),%ecx
	call *56(%rdi)
	jmp L48
L50:
	movl 240(%rdi),%eax
	movl %eax,72(%rbp)
	jmp *L44
L51:
	movl 56(%rdi),%eax
	movl %eax,72(%rbp)
	jmp *L44
L52:
	movl 308(%rdi),%eax
	movl %eax,72(%rbp)
	jmp *L46
L53:
	movl 300(%rdi),%eax
	movl %eax,72(%rbp)
	jmp *L46
L54:
	movl 272(%rdi),%eax
	movl %eax,72(%rbp)
	jmp *L46
L55:
	movl 272(%rdi),%eax
	movl %eax,72(%rbp)
	jmp *L44
L45:
	incl 60(%rbp)
	movl 8(%rbp),%eax
	shl $2,%eax
	addl 60(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,96(%rbp)
	leal 88(%rbp),%ecx
	call *368(%rdi)
	movl %eax,80(%rbp)
	cmpl $48,80(%rbp)
	jl L57
	cmpl $57,80(%rbp)
	jg L57
	movl 80(%rbp),%eax
	subl $48,%eax
	jmp L56
L57:
	movl 80(%rbp),%eax
	subl $65,%eax
	addl $10,%eax
L56:
	movl %eax,80(%rbp)
L43:
	movl 76(%rbp),%eax
	movl %eax,96(%rbp)
	movl 80(%rbp),%eax
	movl %eax,100(%rbp)
	leal 88(%rbp),%ecx
	call *72(%rbp)
	incl 56(%rbp)
	jmp L48
L47:
	movl 84(%rbp),%eax
	movl %eax,96(%rbp)
	leal 88(%rbp),%ecx
	call *368(%rdi)
	mov $L998,%rdx
	mov $6,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L49
3:	jmp *4(%rdx)
L48:
	jmp L42
L41:
	movl 68(%rbp),%eax
	movl %eax,80(%rbp)
	leal 72(%rbp),%ecx
	call *56(%rdi)
L42:
	incl 60(%rbp)
L39:
	movl 60(%rbp),%eax
	cmpl 64(%rbp),%eax
	jle L40
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	CAPITALCH
L10:
	pop (%rcx)
	mov %rbp,4(%rcx)
	mov %rcx,%rbp
	cmpl $97,8(%rbp)
	jl L59
	cmpl $122,8(%rbp)
	jg L59
	movl 8(%rbp),%eax
	movl %eax,12(%rbp)
	movl $97,%eax
	subl $65,%eax
	mov %eax,%ecx
	movl 12(%rbp),%eax
	subl %ecx,%eax
	jmp L58
L59:
	movl 8(%rbp),%eax
L58:
	mov %rbp,%rcx
	mov 4(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11:
	ret
	.data
	.align 4
L24:
	.long L23
	.align 4
L999:
	.long 32
	.long L27
	.long 9
	.long L28
	.long 10
	.long L29
	.long 45
	.long L30
	.long 43
	.long L31
	.align 4
L38:
	.long 48
	.long 49
	.long 50
	.long 51
	.long 52
	.long 53
	.long 54
	.long 55
	.long 56
	.long 57
	.long 65
	.long 66
	.long 67
	.long 68
	.long 69
	.long 70
	.align 4
L44:
	.long L43
	.align 4
L46:
	.long L45
	.align 4
L998:
	.long 83
	.long L50
	.long 67
	.long L51
	.long 79
	.long L52
	.long 88
	.long L53
	.long 73
	.long L54
	.long 78
	.long L55
	.global G60
	.equ G60,L1
	.global G68
	.equ G68,L2
	.global G62
	.equ G62,L3
	.global G63
	.equ G63,L4
	.global G64
	.equ G64,L5
	.global G70
	.equ G70,L6
	.global G77
	.equ G77,L7
	.global G75
	.equ G75,L8
	.global G76
	.equ G76,L9
	.global G92
	.equ G92,L10
	.text
