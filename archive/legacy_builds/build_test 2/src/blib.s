	.text
	jmp L11
//	WRITES
L1:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $1,24(%rbp)
	movl 16(%rbp),%eax
	shl $3,%eax
	movzb (%rax),%eax
	movl %eax,32(%rbp)
	jmp L12
L13:
	movl 16(%rbp),%eax
	shl $3,%eax
	addl 24(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *112(%rdi)
	incl 24(%rbp)
L12:
	movl 24(%rbp),%eax
	cmpl 32(%rbp),%eax
	jle L13
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITED
L2:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 56(%rbp),%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	movl $0,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	cmpl $0,16(%rbp)
	jge L14
	decl 24(%rbp)
	jmp L15
L14:
	movl 16(%rbp),%eax
	negl %eax
	movl %eax,48(%rbp)
L15:
L16:
	movl 48(%rbp),%eax
	movl $10,%ecx
	cqto
	idivl %ecx
	mov %edx,%eax
	movl %eax,224(%rbp)
	movl 40(%rbp),%eax
	addl 32(%rbp),%eax
	mov %eax,%ecx
	movl 224(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 48(%rbp),%eax
	movl $10,%ecx
	cqto
	idivl %ecx
	movl %eax,48(%rbp)
	incl 40(%rbp)
	cmpl $0,48(%rbp)
	jne L16
	movl 40(%rbp),%eax
	incl %eax
	movl %eax,224(%rbp)
	movl 24(%rbp),%eax
	movl %eax,232(%rbp)
	jmp L17
L18:
	movl $32,256(%rbp)
	leal 240(%rbp),%ecx
	call *112(%rdi)
	incl 224(%rbp)
L17:
	movl 224(%rbp),%eax
	cmpl 232(%rbp),%eax
	jle L18
	cmpl $0,16(%rbp)
	jge L19
	movl $45,240(%rbp)
	leal 224(%rbp),%ecx
	call *112(%rdi)
L19:
	movl 40(%rbp),%eax
	decl %eax
	movl %eax,224(%rbp)
	jmp L20
L21:
	movl $48,248(%rbp)
	movl 224(%rbp),%eax
	addl 32(%rbp),%eax
	mov (,%rax,8),%eax
	mov %eax,%ecx
	movl 248(%rbp),%eax
	subl %ecx,%eax
	movl %eax,248(%rbp)
	leal 232(%rbp),%ecx
	call *112(%rdi)
	decl 224(%rbp)
L20:
	cmpl $0,224(%rbp)
	jge L21
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEN
L3:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	movl $0,48(%rbp)
	leal 24(%rbp),%ecx
	call *544(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	NEWLINE
L4:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $10,32(%rbp)
	leal 16(%rbp),%ecx
	call *112(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	NEWPAGE
L5:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $12,32(%rbp)
	leal 16(%rbp),%ecx
	call *112(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	READN
L6:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,16(%rbp)
	movl $0,24(%rbp)
L23:
	leal 32(%rbp),%ecx
	call *104(%rdi)
	movl %eax,568(%rdi)
	jmp L25
L27:
L28:
L29:
	jmp *L24
L30:
	movl $-1,24(%rbp)
L31:
	leal 32(%rbp),%ecx
	call *104(%rdi)
	movl %eax,568(%rdi)
	jmp L26
L25:
	movl 568(%rdi),%eax
	mov $L999,%rdx
	mov $5,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L26
3:	jmp *8(%rdx)
L26:
	jmp L33
L32:
	movl 16(%rbp),%eax
	movl $10,%ecx
	imull %ecx
	addl 568(%rdi),%eax
	subl $48,%eax
	movl %eax,16(%rbp)
	leal 32(%rbp),%ecx
	call *104(%rdi)
	movl %eax,568(%rdi)
L33:
	cmpl $48,568(%rdi)
	jl L34
	cmpl $57,568(%rdi)
	jle L32
L34:
	movl 24(%rbp),%eax
	orl %eax,%eax
	jz L35
	negl 16(%rbp)
L35:
	movl 16(%rbp),%eax
L22:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEOCT
L7:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $1,24(%rbp)
	jle L36
	movl 16(%rbp),%eax
	movl $3,%ecx
	shrl %cl,%eax
	movl %eax,48(%rbp)
	movl 24(%rbp),%eax
	decl %eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *616(%rdi)
L36:
	movl $7,%eax
	andl 16(%rbp),%eax
	addl $48,%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *112(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEHEX
L8:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $1,24(%rbp)
	jle L37
	movl 16(%rbp),%eax
	movl $4,%ecx
	shrl %cl,%eax
	movl %eax,48(%rbp)
	movl 24(%rbp),%eax
	decl %eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *600(%rdi)
L37:
	movl $15,%eax
	andl 16(%rbp),%eax
	movl $L38,%ecx
	shr $3,%ecx
	addl %ecx,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *112(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEF
L9:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 24(%rbp),%eax
	shr $3,%eax
	movl %eax,112(%rbp)
	movl $1,120(%rbp)
	movl 16(%rbp),%eax
	shl $3,%eax
	movzb (%rax),%eax
	movl %eax,128(%rbp)
	jmp L39
L40:
	movl 16(%rbp),%eax
	shl $3,%eax
	addl 120(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,136(%rbp)
	cmpl $37,136(%rbp)
	jne L41
	movl $0,144(%rbp)
	movl $0,%eax
	addl 112(%rbp),%eax
	mov (,%rax,8),%eax
	movl %eax,152(%rbp)
	movl $0,160(%rbp)
	movl 16(%rbp),%eax
	movl %eax,168(%rbp)
	movl 120(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 168(%rbp),%eax
	shl $3,%eax
	addl %ecx,%eax
	movzb (%rax),%eax
	movl %eax,168(%rbp)
	incl 120(%rbp)
	jmp L47
L49:
	movl 168(%rbp),%eax
	movl %eax,192(%rbp)
	leal 176(%rbp),%ecx
	call *112(%rdi)
	jmp L48
L50:
	movl 480(%rdi),%eax
	movl %eax,144(%rbp)
	jmp *L44
L51:
	movl 112(%rdi),%eax
	movl %eax,144(%rbp)
	jmp *L44
L52:
	movl 616(%rdi),%eax
	movl %eax,144(%rbp)
	jmp *L46
L53:
	movl 600(%rdi),%eax
	movl %eax,144(%rbp)
	jmp *L46
L54:
	movl 544(%rdi),%eax
	movl %eax,144(%rbp)
	jmp *L46
L55:
	movl 544(%rdi),%eax
	movl %eax,144(%rbp)
	jmp *L44
L45:
	incl 120(%rbp)
	movl 16(%rbp),%eax
	shl $3,%eax
	addl 120(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,192(%rbp)
	leal 176(%rbp),%ecx
	call *736(%rdi)
	movl %eax,160(%rbp)
	cmpl $48,160(%rbp)
	jl L57
	cmpl $57,160(%rbp)
	jg L57
	movl 160(%rbp),%eax
	subl $48,%eax
	jmp L56
L57:
	movl 160(%rbp),%eax
	subl $65,%eax
	addl $10,%eax
L56:
	movl %eax,160(%rbp)
L43:
	movl 152(%rbp),%eax
	movl %eax,192(%rbp)
	movl 160(%rbp),%eax
	movl %eax,200(%rbp)
	leal 176(%rbp),%ecx
	call *144(%rbp)
	incl 112(%rbp)
	jmp L48
L47:
	movl 168(%rbp),%eax
	movl %eax,192(%rbp)
	leal 176(%rbp),%ecx
	call *736(%rdi)
	mov $L998,%rdx
	mov $6,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L49
3:	jmp *8(%rdx)
L48:
	jmp L42
L41:
	movl 136(%rbp),%eax
	movl %eax,160(%rbp)
	leal 144(%rbp),%ecx
	call *112(%rdi)
L42:
	incl 120(%rbp)
L39:
	movl 120(%rbp),%eax
	cmpl 128(%rbp),%eax
	jle L40
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	CAPITALCH
L10:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $97,16(%rbp)
	jl L59
	cmpl $122,16(%rbp)
	jg L59
	movl 16(%rbp),%eax
	movl %eax,24(%rbp)
	movl $97,%eax
	subl $65,%eax
	mov %eax,%ecx
	movl 24(%rbp),%eax
	subl %ecx,%eax
	jmp L58
L59:
	movl 16(%rbp),%eax
L58:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
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
