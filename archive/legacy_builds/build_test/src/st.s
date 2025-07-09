	.text
//	SECTION: MASTER
	jmp L2
//	START
L1:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 24(%rbp),%ecx
	call *128(%rdi)
	movl %eax,24(%rbp)
	leal 32(%rbp),%ecx
	call *136(%rdi)
	movl %eax,32(%rbp)
	movl $L999,%eax
	shr $3,%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *328(%rdi)
	movl %eax,1552(%rdi)
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *96(%rdi)
	movl $L998,%eax
	shr $3,%eax
	movl %eax,56(%rbp)
	leal 8(%rdi),%eax
	shr $3,%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *608(%rdi)
	leal 56(%rbp),%eax
	shr $3,%eax
	movl %eax,40(%rbp)
	movl $55000,48(%rbp)
	movl 40(%rbp),%eax
	movl %eax,1024(%rdi)
	movl $2,2256(%rdi)
	movl $0,1016(%rdi)
	movl $0,880(%rdi)
	movl $1,1064(%rdi)
	movl $0,888(%rdi)
	movl $0,224(%rbp)
	jmp L3
L4:
	movl $0,232(%rbp)
	movl 224(%rbp),%eax
	addl 40(%rbp),%eax
	mov %eax,%ecx
	movl 232(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 224(%rbp)
L3:
	cmpl $20,224(%rbp)
	jle L4
	movl $L997,%eax
	shr $3,%eax
	movl %eax,240(%rbp)
	leal 224(%rbp),%ecx
	call *336(%rdi)
	movl %eax,1544(%rdi)
	movl %eax,240(%rbp)
	leal 224(%rbp),%ecx
	call *1576(%rdi)
	orl %eax,%eax
	jnz L5
	movl $0,224(%rbp)
	movl $0,232(%rbp)
	movl 1544(%rdi),%eax
	movl %eax,256(%rbp)
	leal 240(%rbp),%ecx
	call *88(%rdi)
	movl $L996,%eax
	shr $3,%eax
	movl %eax,256(%rbp)
	leal 240(%rbp),%ecx
	call *480(%rdi)
L8:
	leal 240(%rbp),%ecx
	call *104(%rdi)
	movl %eax,224(%rbp)
L6:
	cmpl $10,224(%rbp)
	je L10
	cmpl $-1,224(%rbp)
	jne L9
L10:
	jmp L11
L9:
	movl 224(%rbp),%eax
	movl %eax,256(%rbp)
	leal 240(%rbp),%ecx
	call *112(%rdi)
	cmpl $80,224(%rbp)
	jne L12
	movl $1,232(%rbp)
L12:
	cmpl $84,224(%rbp)
	jne L13
	movl $2,232(%rbp)
L13:
	cmpl $67,224(%rbp)
	jne L14
	movl $3,232(%rbp)
L14:
	cmpl $77,224(%rbp)
	jne L15
	movl $4,232(%rbp)
L15:
	cmpl $78,224(%rbp)
	jne L16
	movl $5,232(%rbp)
L16:
	cmpl $83,224(%rbp)
	jne L17
	movl $-1,880(%rdi)
L17:
	cmpl $69,224(%rbp)
	jne L18
	movl $-1,1016(%rdi)
L18:
	cmpl $76,224(%rbp)
	jne L19
	leal 240(%rbp),%ecx
	call *560(%rdi)
	movl %eax,48(%rbp)
	movl %eax,256(%rbp)
	leal 240(%rbp),%ecx
	call *496(%rdi)
L19:
	cmpl $51,224(%rbp)
	jne L20
	movl $3,2256(%rdi)
L20:
	movl $-1,240(%rbp)
	movl 232(%rbp),%eax
	addl 1024(%rdi),%eax
	mov %eax,%ecx
	movl 240(%rbp),%eax
	mov %eax,(,%rcx,8)
	jmp L8
L11:
	leal 240(%rbp),%ecx
	call *504(%rdi)
	leal 240(%rbp),%ecx
	call *368(%rdi)
L5:
	movl $3,%eax
	addl 1024(%rdi),%eax
	mov (,%rax,8),%eax
	notl %eax
	movl %eax,912(%rdi)
	movl $20,1536(%rdi)
	movl $0,1528(%rdi)
	movl 24(%rbp),%eax
	movl %eax,1544(%rdi)
	movl %eax,240(%rbp)
	leal 224(%rbp),%ecx
	call *88(%rdi)
	movl 32(%rbp),%eax
	movl %eax,1560(%rdi)
	movl %eax,240(%rbp)
	leal 224(%rbp),%ecx
	call *1576(%rdi)
	orl %eax,%eax
	jz L21
	movl 1552(%rdi),%eax
	movl %eax,1560(%rdi)
L21:
	jmp L24
//	COMP
L22:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 40(%rbp),%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	movl %eax,800(%rdi)
L25:
	movl 24(%rbp),%eax
	addl 16(%rbp),%eax
	movl %eax,1344(%rdi)
	movl 16(%rbp),%eax
	movl %eax,1352(%rdi)
	movl 880(%rdi),%eax
	orl %eax,%eax
	jz L26
	movl $L995,%eax
	shr $3,%eax
	movl %eax,568(%rbp)
	leal 552(%rbp),%ecx
	call *328(%rdi)
	movl %eax,1568(%rdi)
	movl %eax,568(%rbp)
	leal 552(%rbp),%ecx
	call *1576(%rdi)
	orl %eax,%eax
	jz L28
	movl 1552(%rdi),%eax
	movl %eax,1568(%rdi)
L28:
	jmp L27
L26:
	movl 1552(%rdi),%eax
	movl %eax,1568(%rdi)
L27:
	leal 552(%rbp),%ecx
	call *1200(%rdi)
	movl %eax,552(%rbp)
	cmpl $0,552(%rbp)
	jne L29
	jmp L30
L29:
	movl $L994,%eax
	shr $3,%eax
	movl %eax,576(%rbp)
	movl 1352(%rdi),%eax
	addl 24(%rbp),%eax
	subl 1344(%rdi),%eax
	movl %eax,584(%rbp)
	leal 560(%rbp),%ecx
	call *608(%rdi)
	movl $2,%eax
	addl 1024(%rdi),%eax
	mov (,%rax,8),%eax
	orl %eax,%eax
	jz L31
	movl $L993,%eax
	shr $3,%eax
	movl %eax,576(%rbp)
	leal 560(%rbp),%ecx
	call *480(%rdi)
	movl 552(%rbp),%eax
	movl %eax,576(%rbp)
	movl $0,584(%rbp)
	movl $20,592(%rbp)
	leal 560(%rbp),%ecx
	call *1216(%rdi)
	leal 560(%rbp),%ecx
	call *504(%rdi)
L31:
	cmpl $0,1528(%rdi)
	je L32
	movl $8,576(%rbp)
	leal 560(%rbp),%ecx
	call *240(%rdi)
L32:
	movl $3,%eax
	addl 1024(%rdi),%eax
	mov (,%rax,8),%eax
	orl %eax,%eax
	jnz L33
	movl 1560(%rdi),%eax
	movl %eax,576(%rbp)
	leal 560(%rbp),%ecx
	call *96(%rdi)
	movl 552(%rbp),%eax
	movl %eax,576(%rbp)
	leal 560(%rbp),%ecx
	call *1960(%rdi)
	movl 1552(%rdi),%eax
	movl %eax,576(%rbp)
	leal 560(%rbp),%ecx
	call *96(%rdi)
L33:
	jmp L25
L30:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L24:
	movl L23,%eax
	movl %eax,240(%rbp)
	movl 48(%rbp),%eax
	movl %eax,248(%rbp)
	leal 224(%rbp),%ecx
	call *320(%rdi)
	leal 224(%rbp),%ecx
	call *368(%rdi)
	movl $L992,%eax
	shr $3,%eax
	movl %eax,240(%rbp)
	leal 224(%rbp),%ecx
	call *480(%rdi)
	cmpl $0,1528(%rdi)
	je L34
	movl $8,240(%rbp)
	leal 224(%rbp),%ecx
	call *240(%rdi)
L34:
	jmp finish
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L2:
	ret
	.data
	.align 4
L999:
	.byte 11
	.byte 47
	.byte 100
	.byte 101
	.byte 118
	.byte 47
	.byte 115
	.byte 116
	.byte 100
	.byte 101
	.byte 114
	.byte 114
	.align 4
L998:
	.byte 9
	.byte 10
	.byte 66
	.byte 67
	.byte 80
	.byte 76
	.byte 32
	.byte 37
	.byte 78
	.byte 10
	.align 4
L997:
	.byte 3
	.byte 79
	.byte 80
	.byte 84
	.align 4
L7:
	.long L6
	.align 4
L996:
	.byte 9
	.byte 79
	.byte 80
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.byte 83
	.byte 32
	.byte 32
	.align 4
L23:
	.long L22
	.align 4
L995:
	.byte 4
	.byte 76
	.byte 73
	.byte 83
	.byte 84
	.align 4
L994:
	.byte 14
	.byte 10
	.byte 84
	.byte 82
	.byte 69
	.byte 69
	.byte 32
	.byte 83
	.byte 73
	.byte 90
	.byte 69
	.byte 32
	.byte 37
	.byte 78
	.byte 10
	.align 4
L993:
	.byte 8
	.byte 65
	.byte 69
	.byte 32
	.byte 84
	.byte 82
	.byte 69
	.byte 69
	.byte 10
	.align 4
L992:
	.byte 18
	.byte 10
	.byte 80
	.byte 72
	.byte 65
	.byte 83
	.byte 69
	.byte 32
	.byte 49
	.byte 32
	.byte 67
	.byte 79
	.byte 77
	.byte 80
	.byte 76
	.byte 69
	.byte 84
	.byte 69
	.byte 10
	.global G1
	.equ G1,L1
	.text
//	SECTION: LEX1
	jmp L1002
//	NEXTSYMB
L1001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,976(%rdi)
L1003:
	movl 1016(%rdi),%eax
	orl %eax,%eax
	jz L1004
	movl 936(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *112(%rdi)
L1004:
	jmp L1005
L1007:
L1008:
	incl 1064(%rdi)
	movl $-1,976(%rdi)
L1009:
L1010:
L1011:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $32,936(%rdi)
	je L1009
	jmp L1003
L1012:
L1013:
L1014:
L1015:
L1016:
L1017:
L1018:
L1019:
L1020:
L1021:
	movl $1,920(%rdi)
	movl $10,32(%rbp)
	leal 16(%rbp),%ecx
	call *896(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1022:
L1023:
L1024:
L1025:
L1026:
L1027:
L1028:
L1029:
L1030:
L1031:
L1032:
L1033:
L1034:
L1035:
L1036:
L1037:
L1038:
L1039:
L1040:
L1041:
L1042:
L1043:
L1044:
L1045:
L1046:
L1047:
L1048:
L1049:
L1050:
L1051:
L1052:
L1053:
L1054:
L1055:
L1056:
L1057:
L1058:
L1059:
L1060:
L1061:
L1062:
L1063:
L1064:
L1065:
L1066:
L1067:
L1068:
L1069:
L1070:
L1071:
L1072:
L1073:
	movl 936(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *944(%rdi)
	leal 16(%rbp),%ecx
	call *1000(%rdi)
	movl %eax,920(%rdi)
	cmpl $93,920(%rdi)
	jne L1074
	leal 16(%rbp),%ecx
	call *952(%rdi)
	jmp L1003
L1074:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1075:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $40,936(%rdi)
	je L1076
	cmpl $41,936(%rdi)
	je L1076
	movl $91,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L1076:
	cmpl $40,936(%rdi)
	jne L1078
	movl $91,%eax
	jmp L1077
L1078:
	movl $92,%eax
L1077:
	movl %eax,920(%rdi)
	movl $36,32(%rbp)
	leal 16(%rbp),%ecx
	call *944(%rdi)
	leal 16(%rbp),%ecx
	call *1000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1079:
L1080:
	movl $105,920(%rdi)
	jmp L1081
L1082:
L1083:
	movl $106,920(%rdi)
	jmp L1081
L1084:
	movl $1,920(%rdi)
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	movl 936(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *736(%rdi)
	movl %eax,936(%rdi)
	cmpl $48,936(%rdi)
	jl L1085
	cmpl $55,936(%rdi)
	jg L1085
	movl $8,32(%rbp)
	leal 16(%rbp),%ecx
	call *896(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1085:
	cmpl $66,936(%rdi)
	jne L1086
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	movl $2,32(%rbp)
	leal 16(%rbp),%ecx
	call *896(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1086:
	cmpl $79,936(%rdi)
	jne L1087
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	movl $8,32(%rbp)
	leal 16(%rbp),%ecx
	call *896(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1087:
	cmpl $88,936(%rdi)
	jne L1088
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	movl $16,32(%rbp)
	leal 16(%rbp),%ecx
	call *896(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1088:
	movl $33,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L1089:
	movl $16,920(%rdi)
	jmp L1081
L1090:
	movl $14,920(%rdi)
	jmp L1081
L1091:
	movl $38,920(%rdi)
	jmp L1081
L1092:
	movl $97,920(%rdi)
	jmp L1081
L1093:
	movl $7,920(%rdi)
	jmp L1081
L1094:
	movl $33,920(%rdi)
	jmp L1081
L1095:
	movl $34,920(%rdi)
	jmp L1081
L1096:
	movl $20,920(%rdi)
	jmp L1081
L1097:
	movl $9,920(%rdi)
	jmp L1081
L1098:
	movl $28,920(%rdi)
	jmp L1081
L1099:
	movl $11,920(%rdi)
	jmp L1081
L1100:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $92,936(%rdi)
	jne L1101
	movl $33,920(%rdi)
	jmp L1081
L1101:
	cmpl $47,936(%rdi)
	jne L1102
L1103:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $10,936(%rdi)
	je L1104
	cmpl $-1,936(%rdi)
	jne L1103
L1104:
	jmp L1003
L1102:
	cmpl $42,936(%rdi)
	je L1105
	movl $12,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1105:
L1106:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $42,936(%rdi)
	jne L1107
L1108:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $42,936(%rdi)
	je L1108
	cmpl $47,936(%rdi)
	jne L1109
	jmp L1110
L1109:
L1107:
	cmpl $10,936(%rdi)
	jne L1111
	incl 1064(%rdi)
L1111:
	cmpl $-1,936(%rdi)
	jne L1112
	movl $63,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L1112:
	jmp L1106
L1110:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	jmp L1003
L1113:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $61,936(%rdi)
	jne L1114
	movl $21,920(%rdi)
	jmp L1081
L1114:
	movl $30,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1115:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $47,936(%rdi)
	jne L1116
	movl $34,920(%rdi)
	jmp L1081
L1116:
	cmpl $61,936(%rdi)
	jne L1117
	movl $21,920(%rdi)
	jmp L1081
L1117:
	movl $30,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1118:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $61,936(%rdi)
	jne L1119
	movl $24,920(%rdi)
	jmp L1081
L1119:
	cmpl $60,936(%rdi)
	jne L1120
	movl $31,920(%rdi)
	jmp L1081
L1120:
	movl $22,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1121:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $61,936(%rdi)
	jne L1122
	movl $25,920(%rdi)
	jmp L1081
L1122:
	cmpl $62,936(%rdi)
	jne L1123
	movl $32,920(%rdi)
	jmp L1081
L1123:
	movl $23,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1124:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $62,936(%rdi)
	jne L1125
	movl $37,920(%rdi)
	jmp L1081
L1125:
	movl $15,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1126:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	cmpl $61,936(%rdi)
	jne L1127
	movl $50,920(%rdi)
	jmp L1081
L1127:
	movl $54,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1128:
	movl $0,872(%rdi)
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	jmp L1130
L1129:
	cmpl $255,872(%rdi)
	jne L1131
	movl $34,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L1131:
	incl 872(%rdi)
	leal 16(%rbp),%ecx
	call *904(%rdi)
	movl %eax,16(%rbp)
	movl 872(%rdi),%eax
	addl 864(%rdi),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	mov %eax,(,%rcx,8)
L1130:
	cmpl $34,936(%rdi)
	jne L1129
	movl 872(%rdi),%eax
	movl %eax,16(%rbp)
	movl $0,%eax
	addl 864(%rdi),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 864(%rdi),%eax
	movl %eax,32(%rbp)
	movl 848(%rdi),%eax
	movl %eax,40(%rbp)
	leal 16(%rbp),%ecx
	call *528(%rdi)
	movl %eax,856(%rdi)
	movl $3,920(%rdi)
	jmp L1081
L1132:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	leal 16(%rbp),%ecx
	call *904(%rdi)
	movl %eax,808(%rdi)
	movl $1,920(%rdi)
	cmpl $39,936(%rdi)
	je L1133
	movl $34,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L1133:
	jmp L1081
L1134:
	cmpl $-1,936(%rdi)
	je L1135
	movl $32,936(%rdi)
	movl $94,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L1135:
L1136:
	cmpl $0,832(%rdi)
	jne L1137
	movl $90,920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1137:
	leal 16(%rbp),%ecx
	call *368(%rdi)
	movl 832(%rdi),%eax
	subl $3,%eax
	movl %eax,832(%rdi)
	addl 824(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,1544(%rdi)
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *88(%rdi)
	movl 832(%rdi),%eax
	incl %eax
	addl 824(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,1064(%rdi)
	movl $2,%eax
	addl 832(%rdi),%eax
	addl 824(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,936(%rdi)
	jmp L1003
	jmp L1006
L1005:
	movl 936(%rdi),%eax
	mov $L1999,%rdx
	mov $93,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L1134
3:	jmp *8(%rdx)
L1006:
	jmp L1003
L1081:
	leal 16(%rbp),%ecx
	call *1008(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L1002:
	ret
	.data
	.align 4
L1999:
	.long 12
	.long L1007
	.long 10
	.long L1008
	.long 9
	.long L1010
	.long 32
	.long L1011
	.long 48
	.long L1012
	.long 49
	.long L1013
	.long 50
	.long L1014
	.long 51
	.long L1015
	.long 52
	.long L1016
	.long 53
	.long L1017
	.long 54
	.long L1018
	.long 55
	.long L1019
	.long 56
	.long L1020
	.long 57
	.long L1021
	.long 97
	.long L1022
	.long 98
	.long L1023
	.long 99
	.long L1024
	.long 100
	.long L1025
	.long 101
	.long L1026
	.long 102
	.long L1027
	.long 103
	.long L1028
	.long 104
	.long L1029
	.long 105
	.long L1030
	.long 106
	.long L1031
	.long 107
	.long L1032
	.long 108
	.long L1033
	.long 109
	.long L1034
	.long 110
	.long L1035
	.long 111
	.long L1036
	.long 112
	.long L1037
	.long 113
	.long L1038
	.long 114
	.long L1039
	.long 115
	.long L1040
	.long 116
	.long L1041
	.long 117
	.long L1042
	.long 118
	.long L1043
	.long 119
	.long L1044
	.long 120
	.long L1045
	.long 121
	.long L1046
	.long 122
	.long L1047
	.long 65
	.long L1048
	.long 66
	.long L1049
	.long 67
	.long L1050
	.long 68
	.long L1051
	.long 69
	.long L1052
	.long 70
	.long L1053
	.long 71
	.long L1054
	.long 72
	.long L1055
	.long 73
	.long L1056
	.long 74
	.long L1057
	.long 75
	.long L1058
	.long 76
	.long L1059
	.long 77
	.long L1060
	.long 78
	.long L1061
	.long 79
	.long L1062
	.long 80
	.long L1063
	.long 81
	.long L1064
	.long 82
	.long L1065
	.long 83
	.long L1066
	.long 84
	.long L1067
	.long 85
	.long L1068
	.long 86
	.long L1069
	.long 87
	.long L1070
	.long 88
	.long L1071
	.long 89
	.long L1072
	.long 90
	.long L1073
	.long 36
	.long L1075
	.long 91
	.long L1079
	.long 40
	.long L1080
	.long 93
	.long L1082
	.long 41
	.long L1083
	.long 35
	.long L1084
	.long 63
	.long L1089
	.long 43
	.long L1090
	.long 44
	.long L1091
	.long 59
	.long L1092
	.long 64
	.long L1093
	.long 38
	.long L1094
	.long 124
	.long L1095
	.long 61
	.long L1096
	.long 33
	.long L1097
	.long 37
	.long L1098
	.long 42
	.long L1099
	.long 47
	.long L1100
	.long 126
	.long L1113
	.long 92
	.long L1115
	.long 60
	.long L1118
	.long 62
	.long L1121
	.long 45
	.long L1124
	.long 58
	.long L1126
	.long 34
	.long L1128
	.long 39
	.long L1132
	.long 46
	.long L1136
	.global G120
	.equ G120,L1001
	.text
//	SECTION: LEX2
	jmp L2005
//	LOOKUPWORD
L2001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,%eax
	addl 848(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,16(%rbp)
	movl 856(%rdi),%eax
	addl 848(%rdi),%eax
	mov (,%rax,8),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	addl %ecx,%eax
	shrl $1,%eax
	movl $100,%ecx
	cqto
	idivl %ecx
	mov %edx,%eax
	movl %eax,16(%rbp)
	movl $0,24(%rbp)
	movl 16(%rbp),%eax
	addl 1184(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,928(%rdi)
	jmp L2008
L2007:
	movl $2,%eax
	addl 24(%rbp),%eax
	addl 928(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
	movl 24(%rbp),%eax
	addl 848(%rdi),%eax
	mov (,%rax,8),%eax
	mov %eax,%ecx
	cmpl %ecx,32(%rbp)
	jne L2009
	incl 24(%rbp)
	jmp L2010
L2009:
	movl 928(%rdi),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,928(%rdi)
	movl $0,24(%rbp)
L2010:
L2008:
	cmpl $0,928(%rdi)
	je L2011
	movl 24(%rbp),%eax
	cmpl 856(%rdi),%eax
	jle L2007
L2011:
	cmpl $0,928(%rdi)
	jne L2012
	movl $2,%eax
	addl 856(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,928(%rdi)
	movl $2,32(%rbp)
	movl $0,%eax
	addl 928(%rdi),%eax
	mov %eax,%ecx
	movl 32(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 16(%rbp),%eax
	addl 1184(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
	movl 928(%rdi),%eax
	incl %eax
	mov %eax,%ecx
	movl 32(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $0,32(%rbp)
	movl 856(%rdi),%eax
	movl %eax,40(%rbp)
	jmp L2013
L2014:
	movl 32(%rbp),%eax
	addl 848(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	movl $2,%eax
	addl 32(%rbp),%eax
	addl 928(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 32(%rbp)
L2013:
	movl 32(%rbp),%eax
	cmpl 40(%rbp),%eax
	jle L2014
	movl 928(%rdi),%eax
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	addl 1184(%rdi),%eax
	mov %eax,%ecx
	movl 32(%rbp),%eax
	mov %eax,(,%rcx,8)
L2012:
	movl 928(%rdi),%eax
	mov (,%rax,8),%eax
L2006:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	DECLSYSWORDS
L2002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $L2015,%eax
	shr $3,%eax
	movl %eax,984(%rdi)
	movl $L2999,%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *L2004
	movl $L2998,%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *L2004
	movl 928(%rdi),%eax
	movl %eax,1072(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	D
L2003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $1,24(%rbp)
	movl $0,32(%rbp)
L2016:
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *680(%rdi)
	movl %eax,40(%rbp)
	cmpl $47,40(%rbp)
	jne L2017
	cmpl $0,32(%rbp)
	jne L2019
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L2019:
	movl 32(%rbp),%eax
	movl %eax,48(%rbp)
	movl $0,%eax
	addl 864(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 864(%rdi),%eax
	movl %eax,64(%rbp)
	movl 848(%rdi),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *528(%rdi)
	movl %eax,856(%rdi)
	leal 48(%rbp),%ecx
	call *1000(%rdi)
	movl 984(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	movl 928(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 984(%rdi)
	movl $0,32(%rbp)
	jmp L2018
L2017:
	incl 32(%rbp)
	movl 40(%rbp),%eax
	movl %eax,48(%rbp)
	movl 32(%rbp),%eax
	addl 864(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
L2018:
	incl 24(%rbp)
	jmp L2016
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L2005:
	ret
	.data
	.align 4
L2004:
	.long L2003
	.align 4
L2015:
	.long 40
	.long 19
	.long 89
	.long 66
	.long 100
	.long 71
	.long 101
	.long 72
	.long 20
	.long 35
	.long 102
	.long 69
	.long 5
	.long 56
	.long 68
	.long 52
	.long 25
	.long 23
	.long 76
	.long 93
	.long 57
	.long 98
	.long 74
	.long 7
	.long 24
	.long 22
	.long 34
	.long 33
	.long 65
	.long 31
	.long 75
	.long 21
	.long 30
	.long 36
	.long 48
	.long 102
	.long 53
	.long 67
	.long 13
	.long 32
	.long 8
	.long 61
	.long 62
	.long 63
	.long 70
	.long 79
	.long 49
	.long 99
	.long 55
	.long 4
	.long 101
	.long 39
	.long 60
	.long 58
	.long 103
	.long 6
	.long 59
	.long 0
	.align 4
L2999:
	.byte 142
	.byte 65
	.byte 78
	.byte 68
	.byte 47
	.byte 65
	.byte 66
	.byte 83
	.byte 47
	.byte 66
	.byte 69
	.byte 47
	.byte 66
	.byte 82
	.byte 69
	.byte 65
	.byte 75
	.byte 47
	.byte 66
	.byte 89
	.byte 47
	.byte 67
	.byte 65
	.byte 83
	.byte 69
	.byte 47
	.byte 68
	.byte 79
	.byte 47
	.byte 68
	.byte 69
	.byte 70
	.byte 65
	.byte 85
	.byte 76
	.byte 84
	.byte 47
	.byte 69
	.byte 81
	.byte 47
	.byte 69
	.byte 81
	.byte 86
	.byte 47
	.byte 69
	.byte 76
	.byte 83
	.byte 69
	.byte 47
	.byte 69
	.byte 78
	.byte 68
	.byte 67
	.byte 65
	.byte 83
	.byte 69
	.byte 47
	.byte 70
	.byte 65
	.byte 76
	.byte 83
	.byte 69
	.byte 47
	.byte 70
	.byte 79
	.byte 82
	.byte 47
	.byte 70
	.byte 73
	.byte 78
	.byte 73
	.byte 83
	.byte 72
	.byte 47
	.byte 71
	.byte 79
	.byte 84
	.byte 79
	.byte 47
	.byte 71
	.byte 69
	.byte 47
	.byte 71
	.byte 82
	.byte 47
	.byte 71
	.byte 76
	.byte 79
	.byte 66
	.byte 65
	.byte 76
	.byte 47
	.byte 71
	.byte 69
	.byte 84
	.byte 47
	.byte 73
	.byte 70
	.byte 47
	.byte 73
	.byte 78
	.byte 84
	.byte 79
	.byte 47
	.byte 76
	.byte 69
	.byte 84
	.byte 47
	.byte 76
	.byte 86
	.byte 47
	.byte 76
	.byte 69
	.byte 47
	.byte 76
	.byte 83
	.byte 47
	.byte 76
	.byte 79
	.byte 71
	.byte 79
	.byte 82
	.byte 47
	.byte 76
	.byte 79
	.byte 71
	.byte 65
	.byte 78
	.byte 68
	.byte 47
	.byte 76
	.byte 79
	.byte 79
	.byte 80
	.byte 47
	.byte 76
	.byte 83
	.byte 72
	.byte 73
	.byte 70
	.byte 84
	.byte 47
	.byte 47
	.align 4
L2998:
	.byte 171
	.byte 77
	.byte 65
	.byte 78
	.byte 73
	.byte 70
	.byte 69
	.byte 83
	.byte 84
	.byte 47
	.byte 78
	.byte 69
	.byte 47
	.byte 78
	.byte 79
	.byte 84
	.byte 47
	.byte 78
	.byte 69
	.byte 81
	.byte 86
	.byte 47
	.byte 78
	.byte 69
	.byte 69
	.byte 68
	.byte 83
	.byte 47
	.byte 79
	.byte 82
	.byte 47
	.byte 82
	.byte 69
	.byte 83
	.byte 85
	.byte 76
	.byte 84
	.byte 73
	.byte 83
	.byte 47
	.byte 82
	.byte 69
	.byte 84
	.byte 85
	.byte 82
	.byte 78
	.byte 47
	.byte 82
	.byte 69
	.byte 77
	.byte 47
	.byte 82
	.byte 83
	.byte 72
	.byte 73
	.byte 70
	.byte 84
	.byte 47
	.byte 82
	.byte 86
	.byte 47
	.byte 82
	.byte 69
	.byte 80
	.byte 69
	.byte 65
	.byte 84
	.byte 47
	.byte 82
	.byte 69
	.byte 80
	.byte 69
	.byte 65
	.byte 84
	.byte 87
	.byte 72
	.byte 73
	.byte 76
	.byte 69
	.byte 47
	.byte 82
	.byte 69
	.byte 80
	.byte 69
	.byte 65
	.byte 84
	.byte 85
	.byte 78
	.byte 84
	.byte 73
	.byte 76
	.byte 47
	.byte 83
	.byte 87
	.byte 73
	.byte 84
	.byte 67
	.byte 72
	.byte 79
	.byte 78
	.byte 47
	.byte 83
	.byte 84
	.byte 65
	.byte 84
	.byte 73
	.byte 67
	.byte 47
	.byte 83
	.byte 69
	.byte 67
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.byte 47
	.byte 84
	.byte 79
	.byte 47
	.byte 84
	.byte 69
	.byte 83
	.byte 84
	.byte 47
	.byte 84
	.byte 82
	.byte 85
	.byte 69
	.byte 47
	.byte 84
	.byte 72
	.byte 69
	.byte 78
	.byte 47
	.byte 84
	.byte 65
	.byte 66
	.byte 76
	.byte 69
	.byte 47
	.byte 85
	.byte 78
	.byte 84
	.byte 73
	.byte 76
	.byte 47
	.byte 85
	.byte 78
	.byte 76
	.byte 69
	.byte 83
	.byte 83
	.byte 47
	.byte 86
	.byte 69
	.byte 67
	.byte 47
	.byte 86
	.byte 65
	.byte 76
	.byte 79
	.byte 70
	.byte 47
	.byte 87
	.byte 72
	.byte 73
	.byte 76
	.byte 69
	.byte 47
	.byte 36
	.byte 47
	.byte 47
	.global G125
	.equ G125,L2001
	.global G121
	.equ G121,L2002
	.text
//	SECTION: LEX3
	jmp L3012
//	RCH
L3001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 16(%rbp),%ecx
	call *104(%rdi)
	movl %eax,936(%rdi)
	movl 880(%rdi),%eax
	orl %eax,%eax
	jz L3013
	cmpl $0,832(%rdi)
	jne L3013
	cmpl $-1,936(%rdi)
	je L3013
	movl 1568(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *96(%rdi)
	movl 888(%rdi),%eax
	cmpl 1064(%rdi),%eax
	je L3014
	movl $L3999,%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	movl 1064(%rdi),%eax
	movl %eax,40(%rbp)
	leal 16(%rbp),%ecx
	call *608(%rdi)
	movl 1064(%rdi),%eax
	movl %eax,888(%rdi)
L3014:
	movl 936(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *112(%rdi)
	movl 1552(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *96(%rdi)
L3013:
	incl 1056(%rdi)
	movl 936(%rdi),%eax
	movl %eax,16(%rbp)
	movl $63,%eax
	andl 1056(%rdi),%eax
	addl 800(%rdi),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	mov %eax,(,%rcx,8)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRCHBUF
L3002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $L3998,%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *480(%rdi)
	movl 1056(%rdi),%eax
	subl $63,%eax
	movl %eax,16(%rbp)
	movl 1056(%rdi),%eax
	movl %eax,24(%rbp)
	jmp L3015
L3016:
	movl $63,%eax
	andl 16(%rbp),%eax
	addl 800(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
	cmpl $0,32(%rbp)
	je L3017
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *112(%rdi)
L3017:
	incl 16(%rbp)
L3015:
	movl 16(%rbp),%eax
	cmpl 24(%rbp),%eax
	jle L3016
	leal 16(%rbp),%ecx
	call *504(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RDTAG
L3003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $1,872(%rdi)
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *736(%rdi)
	movl %eax,24(%rbp)
	movl 864(%rdi),%eax
	incl %eax
	mov %eax,%ecx
	movl 24(%rbp),%eax
	mov %eax,(,%rcx,8)
L3018:
	leal 24(%rbp),%ecx
	call *1008(%rdi)
	movl 936(%rdi),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *736(%rdi)
	movl %eax,936(%rdi)
	cmpl $65,936(%rdi)
	jl L3020
	cmpl $90,936(%rdi)
	jle L3019
L3020:
	cmpl $48,936(%rdi)
	jl L3021
	cmpl $57,936(%rdi)
	jle L3019
L3021:
	cmpl $46,936(%rdi)
	je L3019
	cmpl $95,936(%rdi)
	je L3019
	jmp L3022
L3019:
	incl 872(%rdi)
	movl 936(%rdi),%eax
	movl %eax,24(%rbp)
	movl 872(%rdi),%eax
	addl 864(%rdi),%eax
	mov %eax,%ecx
	movl 24(%rbp),%eax
	mov %eax,(,%rcx,8)
	jmp L3018
L3022:
	movl 872(%rdi),%eax
	movl %eax,24(%rbp)
	movl $0,%eax
	addl 864(%rdi),%eax
	mov %eax,%ecx
	movl 24(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 864(%rdi),%eax
	movl %eax,40(%rbp)
	movl 848(%rdi),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *528(%rdi)
	movl %eax,856(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	PERFORMGET
L3004:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,912(%rdi)
	leal 16(%rbp),%ecx
	call *960(%rdi)
	movl $3,%eax
	addl 1024(%rdi),%eax
	mov (,%rax,8),%eax
	notl %eax
	movl %eax,912(%rdi)
	cmpl $3,920(%rdi)
	je L3023
	movl $97,32(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
L3023:
	movl 1544(%rdi),%eax
	movl %eax,16(%rbp)
	movl 832(%rdi),%eax
	addl 824(%rdi),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 1064(%rdi),%eax
	movl %eax,16(%rbp)
	movl 832(%rdi),%eax
	incl %eax
	addl 824(%rdi),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 936(%rdi),%eax
	movl %eax,16(%rbp)
	movl $2,%eax
	addl 832(%rdi),%eax
	addl 824(%rdi),%eax
	mov %eax,%ecx
	movl 16(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $3,%eax
	addl 832(%rdi),%eax
	movl %eax,832(%rdi)
	movl $1,1064(%rdi)
	movl 848(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *336(%rdi)
	movl %eax,1544(%rdi)
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *1576(%rdi)
	orl %eax,%eax
	jz L3024
	leal 32(%rbp),%eax
	shr $3,%eax
	movl %eax,16(%rbp)
	movl $L3997,%eax
	shr $3,%eax
	movl %eax,24(%rbp)
	jmp L3027
//	APPEND
L3025:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	shl $3,%eax
	movzb (%rax),%eax
	movl %eax,32(%rbp)
	movl $1,40(%rbp)
	movl 24(%rbp),%eax
	shl $3,%eax
	movzb (%rax),%eax
	movl %eax,48(%rbp)
	jmp L3028
L3029:
	incl 32(%rbp)
	movl 24(%rbp),%eax
	shl $3,%eax
	addl 40(%rbp),%eax
	movzb (%rax),%eax
	movl %eax,56(%rbp)
	movl 16(%rbp),%eax
	shl $3,%eax
	addl 32(%rbp),%eax
	movl 56(%rbp),%ecx
	mov %cl,(%rax)
	incl 40(%rbp)
L3028:
	movl 40(%rbp),%eax
	cmpl 48(%rbp),%eax
	jle L3029
	movl 32(%rbp),%eax
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	shl $3,%eax
	movl 40(%rbp),%ecx
	mov %cl,(%rax)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L3027:
	movl 24(%rbp),%eax
	shl $3,%eax
	movzb (%rax),%eax
	movl %eax,544(%rbp)
	movl 848(%rdi),%eax
	shl $3,%eax
	movzb (%rax),%eax
	mov %eax,%ecx
	movl 544(%rbp),%eax
	addl %ecx,%eax
	cmpl $255,%eax
	jg L3030
	movl $0,544(%rbp)
	movl 16(%rbp),%eax
	shl $3,%eax
	movl 544(%rbp),%ecx
	mov %cl,(%rax)
	movl 16(%rbp),%eax
	movl %eax,560(%rbp)
	movl 24(%rbp),%eax
	movl %eax,568(%rbp)
	leal 544(%rbp),%ecx
	call *L3026
	movl 16(%rbp),%eax
	movl %eax,560(%rbp)
	movl 848(%rdi),%eax
	movl %eax,568(%rbp)
	leal 544(%rbp),%ecx
	call *L3026
	movl 16(%rbp),%eax
	movl %eax,560(%rbp)
	leal 544(%rbp),%ecx
	call *336(%rdi)
	movl %eax,1544(%rdi)
L3030:
L3024:
	movl 1544(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *1576(%rdi)
	orl %eax,%eax
	jz L3031
	movl 832(%rdi),%eax
	subl $3,%eax
	movl %eax,832(%rdi)
	addl 824(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,1544(%rdi)
	movl 832(%rdi),%eax
	incl %eax
	addl 824(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,1064(%rdi)
	movl $96,32(%rbp)
	movl 848(%rdi),%eax
	movl %eax,40(%rbp)
	leal 16(%rbp),%ecx
	call *1208(%rdi)
	jmp L3032
L3031:
	movl 1544(%rdi),%eax
	movl %eax,32(%rbp)
	leal 16(%rbp),%ecx
	call *88(%rdi)
	leal 16(%rbp),%ecx
	call *1008(%rdi)
L3032:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	FINDFAIL
L3005:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	sete %al
	movzx %al,%eax
	neg %eax
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	READNUMBER
L3006:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 936(%rdi),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L3008
	movl %eax,24(%rbp)
	movl %eax,808(%rdi)
	movl 24(%rbp),%eax
	cmpl 16(%rbp),%eax
	jl L3033
	movl $33,48(%rbp)
	leal 32(%rbp),%ecx
	call *1208(%rdi)
L3033:
L3034:
	leal 32(%rbp),%ecx
	call *1008(%rdi)
	movl 936(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *L3008
	movl %eax,24(%rbp)
	cmpl 16(%rbp),%eax
	jl L3035
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L3035:
	movl 808(%rdi),%eax
	imull 16(%rbp)
	addl 24(%rbp),%eax
	movl %eax,808(%rdi)
	jmp L3034
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	VALUE
L3007:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $48,16(%rbp)
	jl L3037
	cmpl $57,16(%rbp)
	jg L3037
	movl 16(%rbp),%eax
	subl $48,%eax
	jmp L3036
L3037:
	cmpl $65,16(%rbp)
	jl L3039
	cmpl $70,16(%rbp)
	jg L3039
	movl 16(%rbp),%eax
	subl $65,%eax
	addl $10,%eax
	jmp L3038
L3039:
	cmpl $97,16(%rbp)
	jl L3041
	cmpl $102,16(%rbp)
	jg L3041
	movl 16(%rbp),%eax
	subl $97,%eax
	addl $10,%eax
	jmp L3040
L3041:
	movl $100,%eax
L3040:
L3038:
L3036:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RDSTRCH
L3009:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
L3042:
	movl 936(%rdi),%eax
	movl %eax,16(%rbp)
	leal 24(%rbp),%ecx
	call *1008(%rdi)
	cmpl $10,16(%rbp)
	jne L3045
	movl $34,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L3045:
	cmpl $42,16(%rbp)
	jne L3046
	cmpl $10,936(%rdi)
	je L3049
	cmpl $32,936(%rdi)
	je L3049
	cmpl $9,936(%rdi)
	jne L3048
L3049:
L3050:
	cmpl $10,936(%rdi)
	jne L3051
	incl 1064(%rdi)
L3051:
	leal 24(%rbp),%ecx
	call *1008(%rdi)
	cmpl $10,936(%rdi)
	je L3050
	cmpl $32,936(%rdi)
	je L3050
	cmpl $9,936(%rdi)
	je L3050
	cmpl $42,936(%rdi)
	je L3052
	movl $34,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L3052:
	leal 24(%rbp),%ecx
	call *1008(%rdi)
	jmp *L3043
L3048:
	movl 936(%rdi),%eax
	movl %eax,16(%rbp)
	movl 936(%rdi),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *736(%rdi)
	movl %eax,936(%rdi)
	cmpl $84,936(%rdi)
	jne L3053
	movl $9,16(%rbp)
L3053:
	cmpl $83,936(%rdi)
	jne L3054
	movl $32,16(%rbp)
L3054:
	cmpl $78,936(%rdi)
	jne L3055
	movl $10,16(%rbp)
L3055:
	cmpl $69,936(%rdi)
	jne L3056
	movl $69,16(%rbp)
L3056:
	cmpl $66,936(%rdi)
	jne L3057
	movl $8,16(%rbp)
L3057:
	cmpl $80,936(%rdi)
	jne L3058
	movl $12,16(%rbp)
L3058:
	cmpl $67,936(%rdi)
	jne L3059
	movl $13,16(%rbp)
L3059:
	cmpl $88,936(%rdi)
	jne L3060
	movl $16,40(%rbp)
	movl $2,48(%rbp)
	leal 24(%rbp),%ecx
	call *L3011
	movl %eax,16(%rbp)
L3060:
	cmpl $48,936(%rdi)
	jl L3061
	cmpl $57,936(%rdi)
	jg L3061
	movl 936(%rdi),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L3008
	movl $64,%ecx
	imull %ecx
	movl %eax,24(%rbp)
	movl $8,48(%rbp)
	movl $2,56(%rbp)
	leal 32(%rbp),%ecx
	call *L3011
	mov %eax,%ecx
	movl 24(%rbp),%eax
	addl %ecx,%eax
	movl %eax,16(%rbp)
	cmpl $255,%eax
	jle L3062
	movl $34,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L3062:
L3061:
	leal 24(%rbp),%ecx
	call *1008(%rdi)
	jmp L3047
L3046:
	cmpl $10,936(%rdi)
	jne L3063
	incl 1064(%rdi)
L3063:
L3047:
	movl 16(%rbp),%eax
L3044:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	READOCTALORHEX
L3010:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,32(%rbp)
	movl $1,40(%rbp)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	jmp L3065
L3066:
	leal 72(%rbp),%ecx
	call *1008(%rdi)
	movl 936(%rdi),%eax
L3067:
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *L3008
	movl %eax,56(%rbp)
	cmpl 16(%rbp),%eax
	jle L3068
	movl $34,80(%rbp)
	leal 64(%rbp),%ecx
	call *1208(%rdi)
L3068:
	movl 16(%rbp),%eax
	imull 32(%rbp)
	addl 56(%rbp),%eax
	movl %eax,32(%rbp)
	incl 40(%rbp)
L3065:
	movl 40(%rbp),%eax
	cmpl 48(%rbp),%eax
	jle L3066
	movl 32(%rbp),%eax
L3064:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L3012:
	ret
	.data
	.align 4
L3008:
	.long L3007
	.align 4
L3011:
	.long L3010
	.align 4
L3999:
	.byte 5
	.byte 37
	.byte 73
	.byte 52
	.byte 32
	.byte 32
	.align 4
L3998:
	.byte 4
	.byte 10
	.byte 46
	.byte 46
	.byte 46
	.align 4
L3026:
	.long L3025
	.align 4
L3997:
	.byte 21
	.byte 47
	.byte 117
	.byte 115
	.byte 114
	.byte 47
	.byte 108
	.byte 111
	.byte 99
	.byte 97
	.byte 108
	.byte 47
	.byte 108
	.byte 105
	.byte 98
	.byte 47
	.byte 111
	.byte 98
	.byte 99
	.byte 112
	.byte 108
	.byte 47
	.align 4
L3043:
	.long L3042
	.global G126
	.equ G126,L3001
	.global G131
	.equ G131,L3002
	.global G118
	.equ G118,L3003
	.global G119
	.equ G119,L3004
	.global G197
	.equ G197,L3005
	.global G112
	.equ G112,L3006
	.global G113
	.equ G113,L3009
	.text
//	SECTION: SYN0
	jmp L4012
//	NEWVEC
L4001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 1344(%rdi),%eax
	subl 16(%rbp),%eax
	decl %eax
	movl %eax,1344(%rdi)
	cmpl 1352(%rdi),%eax
	jg L4014
	movl $0,1536(%rdi)
	movl $98,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L4014:
	movl 1344(%rdi),%eax
L4013:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LIST1
L4002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,40(%rbp)
	leal 24(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	movl %eax,32(%rbp)
	movl $0,%eax
	addl 24(%rbp),%eax
	mov %eax,%ecx
	movl 32(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
L4015:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LIST2
L4003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $1,48(%rbp)
	leal 32(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	movl $0,%eax
	addl 32(%rbp),%eax
	mov %eax,%ecx
	movl 40(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,40(%rbp)
	movl 32(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 40(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
L4016:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LIST3
L4004:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $2,56(%rbp)
	leal 40(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	movl $0,%eax
	addl 40(%rbp),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl 40(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	movl %eax,48(%rbp)
	movl $2,%eax
	addl 40(%rbp),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 40(%rbp),%eax
L4017:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LIST4
L4005:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $3,64(%rbp)
	leal 48(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	movl $0,%eax
	addl 48(%rbp),%eax
	mov %eax,%ecx
	movl 56(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	movl 48(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 56(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	movl $2,%eax
	addl 48(%rbp),%eax
	mov %eax,%ecx
	movl 56(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 40(%rbp),%eax
	movl %eax,56(%rbp)
	movl $3,%eax
	addl 48(%rbp),%eax
	mov %eax,%ecx
	movl 56(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 48(%rbp),%eax
L4018:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LIST5
L4006:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $4,72(%rbp)
	leal 56(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	movl $0,%eax
	addl 56(%rbp),%eax
	mov %eax,%ecx
	movl 64(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	movl 56(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 64(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	movl $2,%eax
	addl 56(%rbp),%eax
	mov %eax,%ecx
	movl 64(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	movl $3,%eax
	addl 56(%rbp),%eax
	mov %eax,%ecx
	movl 64(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 48(%rbp),%eax
	movl %eax,64(%rbp)
	movl $4,%eax
	addl 56(%rbp),%eax
	mov %eax,%ecx
	movl 64(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 56(%rbp),%eax
L4019:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LIST6
L4007:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $5,80(%rbp)
	leal 64(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,64(%rbp)
	movl 16(%rbp),%eax
	movl %eax,72(%rbp)
	movl $0,%eax
	addl 64(%rbp),%eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,72(%rbp)
	movl 64(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	movl $2,%eax
	addl 64(%rbp),%eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 40(%rbp),%eax
	movl %eax,72(%rbp)
	movl $3,%eax
	addl 64(%rbp),%eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 48(%rbp),%eax
	movl %eax,72(%rbp)
	movl $4,%eax
	addl 64(%rbp),%eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 56(%rbp),%eax
	movl %eax,72(%rbp)
	movl $5,%eax
	addl 64(%rbp),%eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 64(%rbp),%eax
L4020:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	FORMTREE
L4008:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 24(%rbp),%eax
	shr $3,%eax
	movl %eax,16(%rbp)
	movl %eax,800(%rdi)
	movl $0,536(%rbp)
	jmp L4022
L4023:
	movl $0,544(%rbp)
	movl 536(%rbp),%eax
	addl 800(%rdi),%eax
	mov %eax,%ecx
	movl 544(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 536(%rbp)
L4022:
	cmpl $63,536(%rbp)
	jle L4023
	movl $0,1056(%rdi)
	leal 544(%rbp),%eax
	shr $3,%eax
	movl %eax,536(%rbp)
	movl %eax,824(%rdi)
	movl $0,832(%rdi)
	movl $20,840(%rdi)
	leal 712(%rbp),%ecx
	call *1008(%rdi)
	cmpl $-1,936(%rdi)
	jne L4024
	movl $0,%eax
	jmp L4021
L4024:
	leal 720(%rbp),%eax
	shr $3,%eax
	movl %eax,712(%rbp)
	movl %eax,848(%rdi)
	leal 1760(%rbp),%eax
	shr $3,%eax
	movl %eax,1752(%rbp)
	movl %eax,864(%rdi)
	movl $0,872(%rdi)
	leal 3824(%rbp),%eax
	shr $3,%eax
	movl %eax,3816(%rbp)
	movl %eax,1184(%rdi)
	movl $0,4632(%rbp)
	movl $100,4640(%rbp)
	jmp L4027
L4028:
	movl $0,4648(%rbp)
	movl 4632(%rbp),%eax
	addl 1184(%rdi),%eax
	mov %eax,%ecx
	movl 4648(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 4632(%rbp)
L4027:
	movl 4632(%rbp),%eax
	cmpl 4640(%rbp),%eax
	jle L4028
	leal 4632(%rbp),%ecx
	call *968(%rdi)
	leal 4632(%rbp),%ecx
	call *248(%rdi)
	movl %eax,1080(%rdi)
	movl L4026,%eax
	movl %eax,1088(%rdi)
L4025:
	leal 4632(%rbp),%ecx
	call *960(%rdi)
	movl 1024(%rdi),%eax
	incl %eax
	mov (,%rax,8),%eax
	orl %eax,%eax
	jz L4029
	movl $L4999,%eax
	shr $3,%eax
	movl %eax,4648(%rbp)
	movl 920(%rdi),%eax
	movl %eax,4656(%rbp)
	movl 848(%rdi),%eax
	movl %eax,4664(%rbp)
	leal 4632(%rbp),%ecx
	call *608(%rdi)
	cmpl $90,920(%rdi)
	jne L4030
	movl $0,%eax
	jmp L4021
L4030:
	jmp *L4026
L4029:
	jmp L4033
//	RPROG
L4031:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,24(%rbp)
	leal 32(%rbp),%ecx
	call *960(%rdi)
	leal 32(%rbp),%ecx
	call *1392(%rdi)
	movl %eax,24(%rbp)
	mov (,%rax,8),%eax
	cmpl $3,%eax
	je L4035
	movl $95,48(%rbp)
	leal 32(%rbp),%ecx
	call *1208(%rdi)
L4035:
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	cmpl $48,920(%rdi)
	jne L4037
	movl $48,80(%rbp)
	leal 64(%rbp),%ecx
	call *L4032
	jmp L4036
L4037:
	leal 64(%rbp),%ecx
	call *1120(%rdi)
L4036:
	movl %eax,64(%rbp)
	leal 32(%rbp),%ecx
	call *1304(%rdi)
L4034:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L4033:
	cmpl $49,920(%rdi)
	jne L4039
	movl $49,4648(%rbp)
	leal 4632(%rbp),%ecx
	call *L4032
	jmp L4038
L4039:
	cmpl $48,920(%rdi)
	jne L4041
	movl $48,4648(%rbp)
	leal 4632(%rbp),%ecx
	call *L4032
	jmp L4040
L4041:
	leal 4632(%rbp),%ecx
	call *1120(%rdi)
L4040:
L4038:
	movl %eax,4632(%rbp)
	cmpl $90,920(%rdi)
	je L4042
	movl $99,4656(%rbp)
	leal 4640(%rbp),%ecx
	call *1208(%rdi)
L4042:
	movl 4632(%rbp),%eax
L4021:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	SYNREPORT
L4009:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	incl 1528(%rdi)
	movl $L4998,%eax
	shr $3,%eax
	movl %eax,48(%rbp)
	movl 1064(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *608(%rdi)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *L4011
	leal 32(%rbp),%ecx
	call *1048(%rdi)
	movl 1528(%rdi),%eax
	cmpl 1536(%rdi),%eax
	jle L4043
	movl $L4997,%eax
	shr $3,%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *480(%rdi)
	movl $8,48(%rbp)
	leal 32(%rbp),%ecx
	call *240(%rdi)
L4043:
	movl $0,976(%rdi)
	jmp L4045
L4044:
	leal 32(%rbp),%ecx
	call *960(%rdi)
L4045:
	cmpl $91,920(%rdi)
	je L4046
	cmpl $92,920(%rdi)
	je L4046
	cmpl $74,920(%rdi)
	je L4046
	cmpl $40,920(%rdi)
	je L4046
	cmpl $90,920(%rdi)
	je L4046
	movl 976(%rdi),%eax
	orl %eax,%eax
	jz L4044
L4046:
	movl 1080(%rdi),%eax
	movl %eax,48(%rbp)
	movl 1088(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *256(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	SYNMESSAGE
L4010:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	jmp L4048
L4050:
	movl 16(%rbp),%eax
	movl %eax,24(%rbp)
	movl $L4996,%eax
	shr $3,%eax
	jmp L4047
L4051:
	movl $L4995,%eax
	shr $3,%eax
	jmp L4047
L4052:
	movl $L4994,%eax
	shr $3,%eax
	jmp L4047
L4053:
	movl $L4993,%eax
	shr $3,%eax
	jmp L4047
L4054:
	movl $L4992,%eax
	shr $3,%eax
	jmp L4047
L4055:
	movl $L4991,%eax
	shr $3,%eax
	jmp L4047
L4056:
	movl $L4990,%eax
	shr $3,%eax
	jmp L4047
L4057:
	movl $L4989,%eax
	shr $3,%eax
	jmp L4047
L4058:
L4059:
L4060:
	movl $L4988,%eax
	shr $3,%eax
	jmp L4047
L4061:
	movl $L4987,%eax
	shr $3,%eax
	jmp L4047
L4062:
	movl $L4986,%eax
	shr $3,%eax
	jmp L4047
L4063:
	movl $L4985,%eax
	shr $3,%eax
	jmp L4047
L4064:
	movl $L4984,%eax
	shr $3,%eax
	jmp L4047
L4065:
	movl $L4983,%eax
	shr $3,%eax
	jmp L4047
L4066:
	movl $L4982,%eax
	shr $3,%eax
	jmp L4047
L4067:
L4068:
L4069:
	movl $L4981,%eax
	shr $3,%eax
	jmp L4047
L4070:
	movl $L4980,%eax
	shr $3,%eax
	jmp L4047
L4071:
	movl $L4979,%eax
	shr $3,%eax
	jmp L4047
L4072:
L4073:
	movl $L4978,%eax
	shr $3,%eax
	jmp L4047
L4074:
	movl $L4977,%eax
	shr $3,%eax
	jmp L4047
L4075:
	movl $L4976,%eax
	shr $3,%eax
	jmp L4047
L4076:
	movl $L4975,%eax
	shr $3,%eax
	jmp L4047
L4077:
L4078:
	movl $L4974,%eax
	shr $3,%eax
	jmp L4047
L4079:
	movl $L4973,%eax
	shr $3,%eax
	jmp L4047
L4080:
L4081:
	movl $L4972,%eax
	shr $3,%eax
	jmp L4047
L4082:
	movl $L4971,%eax
	shr $3,%eax
	jmp L4047
	jmp L4049
L4048:
	movl 16(%rbp),%eax
	mov $L4970,%rdx
	mov $32,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L4050
3:	jmp *8(%rdx)
L4049:
L4047:
	movl %eax,32(%rbp)
	movl %eax,56(%rbp)
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *608(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L4012:
	ret
	.data
	.align 4
L4011:
	.long L4010
	.align 4
L4026:
	.long L4025
	.align 4
L4999:
	.byte 7
	.byte 37
	.byte 73
	.byte 51
	.byte 32
	.byte 37
	.byte 83
	.byte 10
	.align 4
L4032:
	.long L4031
	.align 4
L4998:
	.byte 29
	.byte 10
	.byte 83
	.byte 89
	.byte 78
	.byte 84
	.byte 65
	.byte 88
	.byte 32
	.byte 69
	.byte 82
	.byte 82
	.byte 79
	.byte 82
	.byte 32
	.byte 78
	.byte 69
	.byte 65
	.byte 82
	.byte 32
	.byte 76
	.byte 73
	.byte 78
	.byte 69
	.byte 32
	.byte 37
	.byte 78
	.byte 58
	.byte 32
	.byte 32
	.align 4
L4997:
	.byte 21
	.byte 10
	.byte 67
	.byte 79
	.byte 77
	.byte 80
	.byte 73
	.byte 76
	.byte 65
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.byte 32
	.byte 65
	.byte 66
	.byte 79
	.byte 82
	.byte 84
	.byte 69
	.byte 68
	.byte 10
	.align 4
L4996:
	.byte 8
	.byte 69
	.byte 82
	.byte 82
	.byte 79
	.byte 82
	.byte 32
	.byte 37
	.byte 78
	.align 4
L4995:
	.byte 18
	.byte 39
	.byte 36
	.byte 39
	.byte 32
	.byte 79
	.byte 85
	.byte 84
	.byte 32
	.byte 79
	.byte 70
	.byte 32
	.byte 67
	.byte 79
	.byte 78
	.byte 84
	.byte 69
	.byte 88
	.byte 84
	.align 4
L4994:
	.byte 17
	.byte 73
	.byte 76
	.byte 76
	.byte 69
	.byte 71
	.byte 65
	.byte 76
	.byte 32
	.byte 67
	.byte 72
	.byte 65
	.byte 82
	.byte 65
	.byte 67
	.byte 84
	.byte 69
	.byte 82
	.align 4
L4993:
	.byte 16
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 83
	.byte 69
	.byte 67
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.byte 32
	.byte 78
	.byte 65
	.byte 77
	.byte 69
	.align 4
L4992:
	.byte 11
	.byte 78
	.byte 79
	.byte 32
	.byte 73
	.byte 78
	.byte 80
	.byte 85
	.byte 84
	.byte 32
	.byte 37
	.byte 83
	.align 4
L4991:
	.byte 17
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 71
	.byte 69
	.byte 84
	.byte 32
	.byte 68
	.byte 73
	.byte 82
	.byte 69
	.byte 67
	.byte 84
	.byte 73
	.byte 86
	.byte 69
	.align 4
L4990:
	.byte 17
	.byte 80
	.byte 82
	.byte 79
	.byte 71
	.byte 82
	.byte 65
	.byte 77
	.byte 32
	.byte 84
	.byte 79
	.byte 79
	.byte 32
	.byte 76
	.byte 65
	.byte 82
	.byte 71
	.byte 69
	.align 4
L4989:
	.byte 21
	.byte 73
	.byte 78
	.byte 67
	.byte 79
	.byte 82
	.byte 82
	.byte 69
	.byte 67
	.byte 84
	.byte 32
	.byte 84
	.byte 69
	.byte 82
	.byte 77
	.byte 73
	.byte 78
	.byte 65
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.align 4
L4988:
	.byte 13
	.byte 78
	.byte 65
	.byte 77
	.byte 69
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L4987:
	.byte 13
	.byte 39
	.byte 36
	.byte 40
	.byte 39
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L4986:
	.byte 13
	.byte 39
	.byte 36
	.byte 41
	.byte 39
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L4985:
	.byte 22
	.byte 85
	.byte 78
	.byte 84
	.byte 65
	.byte 71
	.byte 71
	.byte 69
	.byte 68
	.byte 32
	.byte 39
	.byte 36
	.byte 41
	.byte 39
	.byte 32
	.byte 77
	.byte 73
	.byte 83
	.byte 77
	.byte 65
	.byte 84
	.byte 67
	.byte 72
	.align 4
L4984:
	.byte 19
	.byte 69
	.byte 82
	.byte 82
	.byte 79
	.byte 82
	.byte 32
	.byte 73
	.byte 78
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 82
	.byte 69
	.byte 83
	.byte 83
	.byte 73
	.byte 79
	.byte 78
	.align 4
L4983:
	.byte 10
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 78
	.byte 85
	.byte 77
	.byte 66
	.byte 69
	.byte 82
	.align 4
L4982:
	.byte 32
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 83
	.byte 84
	.byte 82
	.byte 73
	.byte 78
	.byte 71
	.byte 32
	.byte 79
	.byte 82
	.byte 32
	.byte 67
	.byte 72
	.byte 65
	.byte 82
	.byte 65
	.byte 67
	.byte 84
	.byte 69
	.byte 82
	.byte 32
	.byte 67
	.byte 79
	.byte 78
	.byte 83
	.byte 84
	.byte 65
	.byte 78
	.byte 84
	.align 4
L4981:
	.byte 11
	.byte 39
	.byte 41
	.byte 39
	.byte 32
	.byte 77
	.byte 73
	.byte 83
	.byte 83
	.byte 73
	.byte 78
	.byte 71
	.align 4
L4980:
	.byte 26
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 67
	.byte 79
	.byte 78
	.byte 68
	.byte 73
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.byte 65
	.byte 76
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 82
	.byte 69
	.byte 83
	.byte 83
	.byte 73
	.byte 79
	.byte 78
	.align 4
L4979:
	.byte 21
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 80
	.byte 82
	.byte 79
	.byte 67
	.byte 69
	.byte 68
	.byte 85
	.byte 82
	.byte 69
	.byte 32
	.byte 72
	.byte 69
	.byte 65
	.byte 68
	.byte 73
	.byte 78
	.byte 71
	.align 4
L4978:
	.byte 15
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 68
	.byte 69
	.byte 67
	.byte 76
	.byte 65
	.byte 82
	.byte 65
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.align 4
L4977:
	.byte 14
	.byte 85
	.byte 78
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.byte 32
	.byte 39
	.byte 58
	.byte 39
	.align 4
L4976:
	.byte 16
	.byte 69
	.byte 82
	.byte 82
	.byte 79
	.byte 82
	.byte 32
	.byte 73
	.byte 78
	.byte 32
	.byte 67
	.byte 79
	.byte 77
	.byte 77
	.byte 65
	.byte 78
	.byte 68
	.align 4
L4975:
	.byte 15
	.byte 39
	.byte 69
	.byte 76
	.byte 83
	.byte 69
	.byte 39
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L4974:
	.byte 12
	.byte 66
	.byte 65
	.byte 68
	.byte 32
	.byte 70
	.byte 79
	.byte 82
	.byte 32
	.byte 76
	.byte 79
	.byte 79
	.byte 80
	.align 4
L4973:
	.byte 15
	.byte 39
	.byte 73
	.byte 78
	.byte 84
	.byte 79
	.byte 39
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L4972:
	.byte 12
	.byte 39
	.byte 58
	.byte 39
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L4971:
	.byte 12
	.byte 39
	.byte 42
	.byte 47
	.byte 39
	.byte 32
	.byte 77
	.byte 73
	.byte 83
	.byte 83
	.byte 73
	.byte 78
	.byte 71
	.align 4
L4970:
	.long 91
	.long L4051
	.long 94
	.long L4052
	.long 95
	.long L4053
	.long 96
	.long L4054
	.long 97
	.long L4055
	.long 98
	.long L4056
	.long 99
	.long L4057
	.long 8
	.long L4058
	.long 40
	.long L4059
	.long 43
	.long L4060
	.long 6
	.long L4061
	.long 7
	.long L4062
	.long 9
	.long L4063
	.long 32
	.long L4064
	.long 33
	.long L4065
	.long 34
	.long L4066
	.long 15
	.long L4067
	.long 19
	.long L4068
	.long 41
	.long L4069
	.long 30
	.long L4070
	.long 42
	.long L4071
	.long 44
	.long L4072
	.long 45
	.long L4073
	.long 50
	.long L4074
	.long 51
	.long L4075
	.long 54
	.long L4076
	.long 57
	.long L4077
	.long 58
	.long L4078
	.long 60
	.long L4079
	.long 61
	.long L4080
	.long 62
	.long L4081
	.long 63
	.long L4082
	.global G167
	.equ G167,L4001
	.global G161
	.equ G161,L4002
	.global G162
	.equ G162,L4003
	.global G163
	.equ G163,L4004
	.global G164
	.equ G164,L4005
	.global G165
	.equ G165,L4006
	.global G166
	.equ G166,L4007
	.global G150
	.equ G150,L4008
	.global G151
	.equ G151,L4009
	.text
//	SECTION: SYN1
	jmp L5009
//	RDBLOCKBODY
L5001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 1080(%rdi),%eax
	movl %eax,16(%rbp)
	movl 1088(%rdi),%eax
	movl %eax,24(%rbp)
	movl $0,32(%rbp)
	leal 40(%rbp),%ecx
	call *248(%rdi)
	movl %eax,1080(%rdi)
	movl L5012,%eax
	movl %eax,1088(%rdi)
	movl $97,56(%rbp)
	leal 40(%rbp),%ecx
	call *1232(%rdi)
	jmp L5013
L5015:
L5016:
L5017:
	movl 920(%rdi),%eax
	movl %eax,40(%rbp)
	leal 48(%rbp),%ecx
	call *960(%rdi)
	movl 1176(%rdi),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1128(%rdi)
	movl %eax,32(%rbp)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	leal 80(%rbp),%ecx
	call *1120(%rdi)
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,32(%rbp)
	jmp L5014
L5018:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	leal 40(%rbp),%ecx
	call *1160(%rdi)
	movl %eax,32(%rbp)
L5011:
	jmp L5020
L5019:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $40,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *1160(%rdi)
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,32(%rbp)
L5020:
	cmpl $40,920(%rdi)
	je L5019
	movl $74,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *1120(%rdi)
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,32(%rbp)
	jmp L5014
L5021:
	leal 40(%rbp),%ecx
	call *1248(%rdi)
	movl %eax,32(%rbp)
	cmpl $92,920(%rdi)
	je L5022
	cmpl $90,920(%rdi)
	je L5022
	movl $51,56(%rbp)
	leal 40(%rbp),%ecx
	call *1208(%rdi)
L5022:
L5023:
L5024:
	jmp L5014
L5013:
	movl 920(%rdi),%eax
	mov $L5999,%rdx
	mov $6,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L5021
3:	jmp *8(%rdx)
L5014:
	movl 16(%rbp),%eax
	movl %eax,1080(%rdi)
	movl 24(%rbp),%eax
	movl %eax,1088(%rdi)
	movl 32(%rbp),%eax
L5010:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RDSEQ
L5002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,16(%rbp)
	movl $97,40(%rbp)
	leal 24(%rbp),%ecx
	call *1232(%rdi)
	leal 24(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,16(%rbp)
	cmpl $92,920(%rdi)
	je L5027
	cmpl $90,920(%rdi)
	jne L5026
L5027:
	movl 16(%rbp),%eax
	jmp L5025
L5026:
	movl $73,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 56(%rbp),%ecx
	call *1248(%rdi)
	movl %eax,56(%rbp)
	leal 24(%rbp),%ecx
	call *1304(%rdi)
L5025:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RDCDEFS
L5003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,16(%rbp)
	movl $0,24(%rbp)
	leal 16(%rbp),%eax
	shr $3,%eax
	movl %eax,32(%rbp)
	movl 1080(%rdi),%eax
	movl %eax,40(%rbp)
	movl 1088(%rdi),%eax
	movl %eax,48(%rbp)
	leal 56(%rbp),%ecx
	call *248(%rdi)
	movl %eax,1080(%rdi)
	movl L5030,%eax
	movl %eax,1088(%rdi)
L5031:
	leal 56(%rbp),%ecx
	call *1144(%rdi)
	movl %eax,24(%rbp)
	cmpl $20,920(%rdi)
	je L5034
	cmpl $54,920(%rdi)
	jne L5032
L5034:
	leal 56(%rbp),%ecx
	call *960(%rdi)
	jmp L5033
L5032:
	movl $45,72(%rbp)
	leal 56(%rbp),%ecx
	call *1208(%rdi)
L5033:
	movl $43,72(%rbp)
	movl $0,80(%rbp)
	movl 24(%rbp),%eax
	movl %eax,88(%rbp)
	movl $0,112(%rbp)
	leal 96(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,96(%rbp)
	leal 56(%rbp),%ecx
	call *1312(%rdi)
	movl 32(%rbp),%ecx
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	mov (,%rax,8),%eax
	incl %eax
	movl %eax,32(%rbp)
L5029:
	movl $97,72(%rbp)
	leal 56(%rbp),%ecx
	call *1232(%rdi)
	cmpl $2,920(%rdi)
	je L5031
	movl 40(%rbp),%eax
	movl %eax,1080(%rdi)
	movl 48(%rbp),%eax
	movl %eax,1088(%rdi)
	movl 16(%rbp),%eax
L5028:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RDSECT
L5004:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 928(%rdi),%eax
	movl %eax,24(%rbp)
	movl $0,32(%rbp)
	movl $91,56(%rbp)
	movl $6,64(%rbp)
	leal 40(%rbp),%ecx
	call *1224(%rdi)
	leal 40(%rbp),%ecx
	call *16(%rbp)
	movl %eax,32(%rbp)
	cmpl $92,920(%rdi)
	je L5036
	movl $7,56(%rbp)
	leal 40(%rbp),%ecx
	call *1208(%rdi)
L5036:
	movl 928(%rdi),%eax
	cmpl 24(%rbp),%eax
	jne L5037
	leal 40(%rbp),%ecx
	call *960(%rdi)
	jmp L5038
L5037:
	movl 1072(%rdi),%eax
	cmpl 928(%rdi),%eax
	jne L5039
	movl $0,920(%rdi)
	movl $9,56(%rbp)
	leal 40(%rbp),%ecx
	call *1208(%rdi)
L5039:
L5038:
	movl 32(%rbp),%eax
L5035:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RNAMELIST
L5005:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 16(%rbp),%ecx
	call *1144(%rdi)
	movl %eax,16(%rbp)
	cmpl $38,920(%rdi)
	je L5041
	movl 16(%rbp),%eax
	jmp L5040
L5041:
	leal 24(%rbp),%ecx
	call *960(%rdi)
	movl $38,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 56(%rbp),%ecx
	call *1136(%rdi)
	movl %eax,56(%rbp)
	leal 24(%rbp),%ecx
	call *1304(%rdi)
L5040:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RNAME
L5006:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 928(%rdi),%eax
	movl %eax,16(%rbp)
	movl $2,40(%rbp)
	movl $8,48(%rbp)
	leal 24(%rbp),%ecx
	call *1224(%rdi)
	movl 16(%rbp),%eax
L5042:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	IGNORE
L5007:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	cmpl 920(%rdi),%eax
	jne L5043
	leal 24(%rbp),%ecx
	call *960(%rdi)
L5043:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	CHECKFOR
L5008:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	cmpl 920(%rdi),%eax
	je L5044
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1208(%rdi)
L5044:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L5009:
	ret
	.data
	.align 4
L5012:
	.long L5011
	.align 4
L5999:
	.long 75
	.long L5015
	.long 79
	.long L5016
	.long 76
	.long L5017
	.long 74
	.long L5018
	.long 92
	.long L5023
	.long 90
	.long L5024
	.align 4
L5030:
	.long L5029
	.global G140
	.equ G140,L5001
	.global G156
	.equ G156,L5002
	.global G147
	.equ G147,L5003
	.global G141
	.equ G141,L5004
	.global G142
	.equ G142,L5005
	.global G143
	.equ G143,L5006
	.global G154
	.equ G154,L5007
	.global G153
	.equ G153,L5008
	.text
//	SECTION: SYN2
	jmp L6003
//	RBEXP
L6001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,16(%rbp)
	movl 920(%rdi),%eax
	movl %eax,24(%rbp)
	jmp L6005
L6007:
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *1208(%rdi)
L6008:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $16,48(%rbp)
	leal 32(%rbp),%ecx
	call *1288(%rdi)
	jmp L6004
L6009:
L6010:
L6011:
	movl 928(%rdi),%eax
	movl %eax,16(%rbp)
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl 16(%rbp),%eax
	jmp L6004
L6012:
	movl 856(%rdi),%eax
	incl %eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1336(%rdi)
	movl %eax,16(%rbp)
	movl $3,32(%rbp)
	movl $0,%eax
	addl 16(%rbp),%eax
	mov %eax,%ecx
	movl 32(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $0,32(%rbp)
	movl 856(%rdi),%eax
	movl %eax,40(%rbp)
	jmp L6013
L6014:
	movl 32(%rbp),%eax
	addl 848(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	movl 32(%rbp),%eax
	incl %eax
	addl 16(%rbp),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 32(%rbp)
L6013:
	movl 32(%rbp),%eax
	cmpl 40(%rbp),%eax
	jle L6014
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl 16(%rbp),%eax
	jmp L6004
L6015:
	movl $1,48(%rbp)
	movl 808(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	movl %eax,16(%rbp)
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl 16(%rbp),%eax
	jmp L6004
L6016:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $0,48(%rbp)
	leal 32(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,16(%rbp)
	movl $106,48(%rbp)
	movl $15,56(%rbp)
	leal 32(%rbp),%ecx
	call *1224(%rdi)
	movl 16(%rbp),%eax
	jmp L6004
L6017:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $6,48(%rbp)
	leal 56(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	jmp L6004
L6018:
	movl $8,24(%rbp)
L6019:
L6020:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl $37,72(%rbp)
	leal 56(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	jmp L6004
L6021:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $34,48(%rbp)
	leal 32(%rbp),%ecx
	call *1152(%rdi)
	jmp L6004
L6022:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $34,48(%rbp)
	leal 32(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,16(%rbp)
	mov (,%rax,8),%eax
	cmpl $1,%eax
	jne L6023
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	negl %eax
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov %eax,%ecx
	movl 32(%rbp),%eax
	mov %eax,(,%rcx,8)
	jmp L6024
L6023:
	movl $17,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	movl %eax,16(%rbp)
L6024:
	movl 16(%rbp),%eax
	jmp L6004
L6025:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $30,48(%rbp)
	movl $24,72(%rbp)
	leal 56(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	jmp L6004
L6026:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $19,48(%rbp)
	movl $35,72(%rbp)
	leal 56(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	jmp L6004
L6027:
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $39,48(%rbp)
	leal 56(%rbp),%ecx
	call *1240(%rdi)
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	jmp L6004
	jmp L6006
L6005:
	movl 920(%rdi),%eax
	mov $L6999,%rdx
	mov $16,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L6007
3:	jmp *8(%rdx)
L6006:
L6004:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	REXP
L6002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 24(%rbp),%ecx
	call *1392(%rdi)
	movl %eax,24(%rbp)
	movl $0,32(%rbp)
	movl $0,40(%rbp)
	movl $0,48(%rbp)
	movl $0,56(%rbp)
L6029:
	movl 920(%rdi),%eax
	movl %eax,64(%rbp)
	movl 976(%rdi),%eax
	orl %eax,%eax
	jz L6034
	movl 24(%rbp),%eax
	jmp L6028
L6034:
	jmp L6035
L6037:
	movl 24(%rbp),%eax
	jmp L6028
L6038:
	leal 72(%rbp),%ecx
	call *960(%rdi)
	movl $0,32(%rbp)
	cmpl $106,920(%rdi)
	je L6039
	leal 72(%rbp),%ecx
	call *1240(%rdi)
	movl %eax,32(%rbp)
L6039:
	movl $106,88(%rbp)
	movl $19,96(%rbp)
	leal 72(%rbp),%ecx
	call *1224(%rdi)
	movl $10,88(%rbp)
	movl 24(%rbp),%eax
	movl %eax,96(%rbp)
	movl 32(%rbp),%eax
	movl %eax,104(%rbp)
	leal 72(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,24(%rbp)
	jmp L6029
L6040:
	movl $36,48(%rbp)
	jmp *L6033
L6041:
	movl $40,48(%rbp)
	jmp *L6033
L6042:
L6043:
L6044:
	movl $35,48(%rbp)
	jmp *L6033
L6045:
L6046:
	movl $34,48(%rbp)
	jmp *L6033
L6047:
L6048:
L6049:
L6050:
L6051:
L6052:
	cmpl $30,16(%rbp)
	jl L6053
	movl 24(%rbp),%eax
	jmp L6028
L6053:
L6054:
	leal 72(%rbp),%ecx
	call *960(%rdi)
	movl $30,88(%rbp)
	leal 72(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,32(%rbp)
	movl 64(%rbp),%eax
	movl %eax,88(%rbp)
	movl 24(%rbp),%eax
	movl %eax,96(%rbp)
	movl 32(%rbp),%eax
	movl %eax,104(%rbp)
	leal 72(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,24(%rbp)
	cmpl $0,40(%rbp)
	jne L6055
	movl 24(%rbp),%eax
	movl %eax,40(%rbp)
	jmp L6056
L6055:
	movl $33,88(%rbp)
	movl 40(%rbp),%eax
	movl %eax,96(%rbp)
	movl 24(%rbp),%eax
	movl %eax,104(%rbp)
	leal 72(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,40(%rbp)
L6056:
	movl 32(%rbp),%eax
	movl %eax,24(%rbp)
	movl 920(%rdi),%eax
	movl %eax,64(%rbp)
	cmpl $20,64(%rbp)
	jl L6057
	cmpl $25,64(%rbp)
	jle L6054
L6057:
	movl 40(%rbp),%eax
	movl %eax,24(%rbp)
	jmp L6029
L6058:
L6059:
	movl $25,48(%rbp)
	movl $30,56(%rbp)
	jmp *L6031
L6060:
	movl $23,48(%rbp)
	jmp *L6033
L6061:
	movl $22,48(%rbp)
	jmp *L6033
L6062:
L6063:
	movl $21,48(%rbp)
	jmp *L6033
L6064:
	cmpl $13,16(%rbp)
	jl L6065
	movl 24(%rbp),%eax
	jmp L6028
L6065:
	leal 72(%rbp),%ecx
	call *960(%rdi)
	movl $0,88(%rbp)
	leal 72(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,32(%rbp)
	movl $38,88(%rbp)
	movl $30,96(%rbp)
	leal 72(%rbp),%ecx
	call *1224(%rdi)
	movl $37,88(%rbp)
	movl 24(%rbp),%eax
	movl %eax,96(%rbp)
	movl 32(%rbp),%eax
	movl %eax,104(%rbp)
	movl $0,128(%rbp)
	leal 112(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,112(%rbp)
	leal 72(%rbp),%ecx
	call *1312(%rdi)
	movl %eax,24(%rbp)
	jmp L6029
L6032:
	movl 48(%rbp),%eax
	movl %eax,56(%rbp)
L6030:
	movl 16(%rbp),%eax
	cmpl 48(%rbp),%eax
	jl L6066
	movl 24(%rbp),%eax
	jmp L6028
L6066:
	leal 72(%rbp),%ecx
	call *960(%rdi)
	movl 64(%rbp),%eax
	movl %eax,88(%rbp)
	movl 24(%rbp),%eax
	movl %eax,96(%rbp)
	movl 56(%rbp),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,104(%rbp)
	leal 72(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,24(%rbp)
	jmp L6029
	jmp L6036
L6035:
	movl 64(%rbp),%eax
	mov $L6998,%rdx
	mov $21,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L6037
3:	jmp *8(%rdx)
L6036:
	jmp L6029
L6028:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L6003:
	jmp L6068
//	REXPLIST
L6067:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,16(%rbp)
	leal 16(%rbp),%eax
	shr $3,%eax
	movl %eax,24(%rbp)
L6070:
	movl $0,48(%rbp)
	leal 32(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,32(%rbp)
	cmpl $38,920(%rdi)
	je L6071
	movl 32(%rbp),%eax
	movl 24(%rbp),%ecx
	mov %eax,(,%rcx,8)
	movl 16(%rbp),%eax
	jmp L6069
L6071:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $38,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	movl $0,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	movl 24(%rbp),%ecx
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	mov (,%rax,8),%eax
	addl $2,%eax
	movl %eax,24(%rbp)
	jmp L6070
L6069:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L6068:
	jmp L6073
//	RDEF
L6072:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 16(%rbp),%ecx
	call *1136(%rdi)
	movl %eax,16(%rbp)
	jmp L6075
L6077:
	movl $0,24(%rbp)
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $2,%eax
	je L6078
	movl $40,48(%rbp)
	leal 32(%rbp),%ecx
	call *1208(%rdi)
L6078:
	cmpl $2,920(%rdi)
	jne L6079
	leal 32(%rbp),%ecx
	call *1136(%rdi)
	movl %eax,24(%rbp)
L6079:
	movl $106,48(%rbp)
	movl $41,56(%rbp)
	leal 32(%rbp),%ecx
	call *1224(%rdi)
	cmpl $89,920(%rdi)
	jne L6080
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $45,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,72(%rbp)
	movl $0,80(%rbp)
	leal 32(%rbp),%ecx
	call *1320(%rdi)
	jmp L6074
L6080:
	cmpl $20,920(%rdi)
	jne L6081
	leal 32(%rbp),%ecx
	call *960(%rdi)
	movl $44,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	movl $0,88(%rbp)
	leal 72(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,72(%rbp)
	movl $0,80(%rbp)
	leal 32(%rbp),%ecx
	call *1320(%rdi)
	jmp L6074
L6081:
	movl $42,48(%rbp)
	leal 32(%rbp),%ecx
	call *1208(%rdi)
L6082:
	movl $44,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L6083:
	leal 24(%rbp),%ecx
	call *960(%rdi)
	cmpl $103,920(%rdi)
	jne L6084
	leal 24(%rbp),%ecx
	call *960(%rdi)
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $2,%eax
	je L6085
	movl $43,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L6085:
	movl $42,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	movl $0,72(%rbp)
	leal 56(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,56(%rbp)
	leal 24(%rbp),%ecx
	call *1304(%rdi)
	jmp L6074
L6084:
	movl $41,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 56(%rbp),%ecx
	call *1240(%rdi)
	movl %eax,56(%rbp)
	leal 24(%rbp),%ecx
	call *1304(%rdi)
	jmp L6074
	jmp L6076
L6075:
	movl 920(%rdi),%eax
	mov $L6997,%rdx
	mov $2,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L6082
3:	jmp *8(%rdx)
L6076:
L6074:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L6073:
	ret
	.data
	.align 4
L6999:
	.long 16
	.long L6008
	.long 4
	.long L6009
	.long 5
	.long L6010
	.long 2
	.long L6011
	.long 3
	.long L6012
	.long 1
	.long L6015
	.long 105
	.long L6016
	.long 6
	.long L6017
	.long 9
	.long L6018
	.long 7
	.long L6019
	.long 8
	.long L6020
	.long 14
	.long L6021
	.long 15
	.long L6022
	.long 30
	.long L6025
	.long 19
	.long L6026
	.long 39
	.long L6027
	.align 4
L6031:
	.long L6030
	.align 4
L6033:
	.long L6032
	.align 4
L6998:
	.long 105
	.long L6038
	.long 28
	.long L6040
	.long 9
	.long L6041
	.long 13
	.long L6042
	.long 11
	.long L6043
	.long 12
	.long L6044
	.long 14
	.long L6045
	.long 15
	.long L6046
	.long 20
	.long L6047
	.long 21
	.long L6048
	.long 24
	.long L6049
	.long 25
	.long L6050
	.long 22
	.long L6051
	.long 23
	.long L6052
	.long 31
	.long L6058
	.long 32
	.long L6059
	.long 33
	.long L6060
	.long 34
	.long L6061
	.long 35
	.long L6062
	.long 36
	.long L6063
	.long 37
	.long L6064
	.align 4
L6997:
	.long 105
	.long L6077
	.long 20
	.long L6083
	.global G174
	.equ G174,L6001
	.global G144
	.equ G144,L6002
	.global G155
	.equ G155,L6067
	.global G145
	.equ G145,L6072
	.text
//	SECTION: SYN4
	jmp L7004
//	RBCOM
L7001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,16(%rbp)
	movl $0,24(%rbp)
	movl 920(%rdi),%eax
	movl %eax,32(%rbp)
	jmp L7006
L7008:
	movl $0,%eax
	jmp L7005
L7009:
L7010:
L7011:
L7012:
L7013:
L7014:
L7015:
L7016:
L7017:
	leal 40(%rbp),%ecx
	call *1240(%rdi)
	movl %eax,16(%rbp)
	cmpl $50,920(%rdi)
	jne L7018
	movl 920(%rdi),%eax
	movl %eax,32(%rbp)
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *1240(%rdi)
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	jmp L7005
L7018:
	cmpl $54,920(%rdi)
	jne L7019
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $2,%eax
	je L7020
	movl $50,56(%rbp)
	leal 40(%rbp),%ecx
	call *1208(%rdi)
L7020:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $54,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *L7002
	movl %eax,72(%rbp)
	movl $0,80(%rbp)
	leal 40(%rbp),%ecx
	call *1312(%rdi)
	jmp L7005
L7019:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $10,%eax
	jne L7021
	movl $51,40(%rbp)
	movl 16(%rbp),%eax
	mov %eax,%ecx
	movl 40(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 16(%rbp),%eax
	jmp L7005
L7021:
	movl $51,56(%rbp)
	leal 40(%rbp),%ecx
	call *1208(%rdi)
	movl 16(%rbp),%eax
	jmp L7005
L7022:
L7023:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	movl $0,80(%rbp)
	leal 64(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *1296(%rdi)
	jmp L7005
L7024:
L7025:
L7026:
L7027:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $0,56(%rbp)
	leal 40(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,16(%rbp)
	movl $101,56(%rbp)
	leal 40(%rbp),%ecx
	call *1232(%rdi)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	jmp L7005
L7028:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $0,56(%rbp)
	leal 40(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,16(%rbp)
	movl $101,56(%rbp)
	leal 40(%rbp),%ecx
	call *1232(%rdi)
	leal 40(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,24(%rbp)
	movl $102,56(%rbp)
	movl $54,64(%rbp)
	leal 40(%rbp),%ecx
	call *1224(%rdi)
	movl $55,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	movl 24(%rbp),%eax
	movl %eax,72(%rbp)
	leal 80(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,80(%rbp)
	leal 40(%rbp),%ecx
	call *1312(%rdi)
	jmp L7005
L7029:
	movl $0,40(%rbp)
	movl $0,48(%rbp)
	movl $0,56(%rbp)
	leal 64(%rbp),%ecx
	call *960(%rdi)
	leal 64(%rbp),%ecx
	call *1144(%rdi)
	movl %eax,16(%rbp)
	movl $20,80(%rbp)
	movl $57,88(%rbp)
	leal 64(%rbp),%ecx
	call *1224(%rdi)
	movl $0,80(%rbp)
	leal 64(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,40(%rbp)
	movl $99,80(%rbp)
	movl $58,88(%rbp)
	leal 64(%rbp),%ecx
	call *1224(%rdi)
	movl $0,80(%rbp)
	leal 64(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,48(%rbp)
	cmpl $100,920(%rdi)
	jne L7030
	leal 64(%rbp),%ecx
	call *960(%rdi)
	movl $0,80(%rbp)
	leal 64(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,56(%rbp)
L7030:
	movl $101,80(%rbp)
	leal 64(%rbp),%ecx
	call *1232(%rdi)
	movl $56,80(%rbp)
	movl 16(%rbp),%eax
	movl %eax,88(%rbp)
	movl 40(%rbp),%eax
	movl %eax,96(%rbp)
	movl 48(%rbp),%eax
	movl %eax,104(%rbp)
	movl 56(%rbp),%eax
	movl %eax,112(%rbp)
	leal 120(%rbp),%ecx
	call *1168(%rdi)
	movl %eax,120(%rbp)
	leal 64(%rbp),%ecx
	call *1328(%rdi)
	jmp L7005
L7031:
L7032:
L7033:
L7034:
L7035:
	movl 928(%rdi),%eax
	movl %eax,16(%rbp)
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl 16(%rbp),%eax
	jmp L7005
L7036:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $0,56(%rbp)
	leal 40(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,16(%rbp)
	movl $98,56(%rbp)
	movl $60,64(%rbp)
	leal 40(%rbp),%ecx
	call *1224(%rdi)
	movl $70,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	movl 1248(%rdi),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1128(%rdi)
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	jmp L7005
L7037:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $0,56(%rbp)
	leal 40(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,16(%rbp)
	movl $54,56(%rbp)
	movl $61,64(%rbp)
	leal 40(%rbp),%ecx
	call *1224(%rdi)
	movl $71,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	leal 72(%rbp),%ecx
	call *L7002
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1304(%rdi)
	jmp L7005
L7038:
	leal 40(%rbp),%ecx
	call *960(%rdi)
	movl $54,56(%rbp)
	movl $62,64(%rbp)
	leal 40(%rbp),%ecx
	call *1224(%rdi)
	movl $72,56(%rbp)
	leal 64(%rbp),%ecx
	call *L7002
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *1296(%rdi)
	jmp L7005
L7039:
	movl 1120(%rdi),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1128(%rdi)
	jmp L7005
	jmp L7007
L7006:
	movl 920(%rdi),%eax
	mov $L7999,%rdx
	mov $26,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L7008
3:	jmp *8(%rdx)
L7007:
L7005:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	RCOM
L7003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 16(%rbp),%ecx
	call *L7002
	movl %eax,16(%rbp)
	cmpl $0,16(%rbp)
	jne L7041
	movl $51,40(%rbp)
	leal 24(%rbp),%ecx
	call *1208(%rdi)
L7041:
	jmp L7043
L7042:
	movl 920(%rdi),%eax
	movl %eax,24(%rbp)
	leal 32(%rbp),%ecx
	call *960(%rdi)
	cmpl $61,24(%rbp)
	jne L7044
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1296(%rdi)
	movl %eax,16(%rbp)
	jmp L7045
L7044:
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	movl $0,80(%rbp)
	leal 64(%rbp),%ecx
	call *1152(%rdi)
	movl %eax,64(%rbp)
	leal 32(%rbp),%ecx
	call *1304(%rdi)
	movl %eax,16(%rbp)
L7045:
L7043:
	cmpl $61,920(%rdi)
	je L7042
	cmpl $62,920(%rdi)
	je L7042
	cmpl $63,920(%rdi)
	je L7042
	movl 16(%rbp),%eax
L7040:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L7004:
	ret
	.data
	.align 4
L7002:
	.long L7001
	.align 4
L7999:
	.long 2
	.long L7009
	.long 1
	.long L7010
	.long 3
	.long L7011
	.long 4
	.long L7012
	.long 5
	.long L7013
	.long 7
	.long L7014
	.long 8
	.long L7015
	.long 9
	.long L7016
	.long 105
	.long L7017
	.long 52
	.long L7022
	.long 53
	.long L7023
	.long 57
	.long L7024
	.long 58
	.long L7025
	.long 59
	.long L7026
	.long 60
	.long L7027
	.long 55
	.long L7028
	.long 56
	.long L7029
	.long 65
	.long L7031
	.long 66
	.long L7032
	.long 67
	.long L7033
	.long 68
	.long L7034
	.long 69
	.long L7035
	.long 70
	.long L7036
	.long 71
	.long L7037
	.long 72
	.long L7038
	.long 91
	.long L7039
	.global G146
	.equ G146,L7003
	.text
//	SECTION: PLIST
	jmp L8002
//	PLIST
L8001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $0,40(%rbp)
	movl $L8003,%eax
	shr $3,%eax
	movl %eax,48(%rbp)
	cmpl $0,16(%rbp)
	jne L8004
	movl $L8999,%eax
	shr $3,%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *480(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L8004:
	jmp L8005
L8007:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *496(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L8008:
	movl $2,%eax
	addl 16(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *480(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L8009:
	movl $L8998,%eax
	shr $3,%eax
	movl %eax,72(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	movl %eax,80(%rbp)
	leal 56(%rbp),%ecx
	call *608(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L8010:
	movl $2,%eax
	addl 40(%rbp),%eax
	movl %eax,40(%rbp)
L8011:
L8012:
L8013:
L8014:
L8015:
	incl 40(%rbp)
L8016:
L8017:
L8018:
L8019:
L8020:
L8021:
L8022:
L8023:
L8024:
L8025:
L8026:
L8027:
L8028:
L8029:
L8030:
L8031:
L8032:
L8033:
L8034:
L8035:
L8036:
L8037:
L8038:
L8039:
L8040:
L8041:
L8042:
L8043:
L8044:
L8045:
L8046:
L8047:
L8048:
L8049:
L8050:
L8051:
L8052:
L8053:
L8054:
L8055:
L8056:
L8057:
	incl 40(%rbp)
L8058:
L8059:
L8060:
L8061:
L8062:
L8063:
L8064:
L8065:
L8066:
L8067:
L8068:
	incl 40(%rbp)
L8069:
L8070:
L8071:
L8072:
L8073:
L8074:
L8075:
L8076:
L8077:
	incl 40(%rbp)
	movl 32(%rbp),%eax
	cmpl 24(%rbp),%eax
	jne L8078
	movl $L8997,%eax
	shr $3,%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *480(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L8078:
	movl $L8996,%eax
	shr $3,%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *480(%rdi)
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *496(%rdi)
	movl $2,56(%rbp)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	jmp L8079
L8080:
	leal 72(%rbp),%ecx
	call *504(%rdi)
	movl $0,72(%rbp)
	movl 24(%rbp),%eax
	decl %eax
	movl %eax,80(%rbp)
	jmp L8081
L8082:
	movl 72(%rbp),%eax
	addl 48(%rbp),%eax
	mov (,%rax,8),%eax
	movl %eax,104(%rbp)
	leal 88(%rbp),%ecx
	call *480(%rdi)
	incl 72(%rbp)
L8081:
	movl 72(%rbp),%eax
	cmpl 80(%rbp),%eax
	jle L8082
	movl $L8995,%eax
	shr $3,%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *480(%rdi)
	movl 40(%rbp),%eax
	cmpl 56(%rbp),%eax
	jne L8084
	movl $L8994,%eax
	shr $3,%eax
	jmp L8083
L8084:
	movl $L8993,%eax
	shr $3,%eax
L8083:
	movl %eax,72(%rbp)
	movl 24(%rbp),%eax
	addl 48(%rbp),%eax
	mov %eax,%ecx
	movl 72(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 56(%rbp),%eax
	addl 16(%rbp),%eax
	decl %eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	movl 24(%rbp),%eax
	incl %eax
	movl %eax,96(%rbp)
	movl 32(%rbp),%eax
	movl %eax,104(%rbp)
	leal 72(%rbp),%ecx
	call *1216(%rdi)
	incl 56(%rbp)
L8079:
	movl 56(%rbp),%eax
	cmpl 64(%rbp),%eax
	jle L8080
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L8006
L8005:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L8992,%rdx
	mov $70,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L8077
3:	jmp *8(%rdx)
L8006:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L8002:
	ret
	.data
	.align 4
L8003:
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.align 4
L8999:
	.byte 3
	.byte 78
	.byte 73
	.byte 76
	.align 4
L8998:
	.byte 4
	.byte 34
	.byte 37
	.byte 83
	.byte 34
	.align 4
L8997:
	.byte 3
	.byte 69
	.byte 84
	.byte 67
	.align 4
L8996:
	.byte 2
	.byte 79
	.byte 80
	.align 4
L8995:
	.byte 2
	.byte 42
	.byte 45
	.align 4
L8994:
	.byte 2
	.byte 32
	.byte 32
	.align 4
L8993:
	.byte 2
	.byte 33
	.byte 32
	.align 4
L8992:
	.long 1
	.long L8007
	.long 2
	.long L8008
	.long 3
	.long L8009
	.long 56
	.long L8010
	.long 37
	.long L8011
	.long 44
	.long L8012
	.long 45
	.long L8013
	.long 55
	.long L8014
	.long 43
	.long L8015
	.long 48
	.long L8016
	.long 49
	.long L8017
	.long 9
	.long L8018
	.long 28
	.long L8019
	.long 10
	.long L8020
	.long 11
	.long L8021
	.long 12
	.long L8022
	.long 13
	.long L8023
	.long 14
	.long L8024
	.long 15
	.long L8025
	.long 20
	.long L8026
	.long 21
	.long L8027
	.long 22
	.long L8028
	.long 23
	.long L8029
	.long 24
	.long L8030
	.long 25
	.long L8031
	.long 31
	.long L8032
	.long 32
	.long L8033
	.long 33
	.long L8034
	.long 34
	.long L8035
	.long 35
	.long L8036
	.long 36
	.long L8037
	.long 38
	.long L8038
	.long 40
	.long L8039
	.long 41
	.long L8040
	.long 42
	.long L8041
	.long 50
	.long L8042
	.long 51
	.long L8043
	.long 54
	.long L8044
	.long 57
	.long L8045
	.long 58
	.long L8046
	.long 59
	.long L8047
	.long 60
	.long L8048
	.long 62
	.long L8049
	.long 63
	.long L8050
	.long 70
	.long L8051
	.long 71
	.long L8052
	.long 73
	.long L8053
	.long 74
	.long L8054
	.long 75
	.long L8055
	.long 79
	.long L8056
	.long 76
	.long L8057
	.long 6
	.long L8058
	.long 7
	.long L8059
	.long 8
	.long L8060
	.long 17
	.long L8061
	.long 30
	.long L8062
	.long 39
	.long L8063
	.long 52
	.long L8064
	.long 53
	.long L8065
	.long 61
	.long L8066
	.long 72
	.long L8067
	.long 19
	.long L8068
	.long 65
	.long L8069
	.long 66
	.long L8070
	.long 67
	.long L8071
	.long 68
	.long L8072
	.long 69
	.long L8073
	.long 4
	.long L8074
	.long 5
	.long L8075
	.long 16
	.long L8076
	.global G152
	.equ G152,L8001
	.text
//	SECTION: TRN0
	jmp L9005
//	NEXTPARAM
L9001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	incl 1952(%rdi)
	movl 1952(%rdi),%eax
L9006:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSREPORT
L9002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 1552(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *96(%rdi)
	incl 1528(%rdi)
	movl 1528(%rdi),%eax
	cmpl 1536(%rdi),%eax
	jl L9007
	movl $L9999,%eax
	shr $3,%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *480(%rdi)
	movl $8,48(%rbp)
	leal 32(%rbp),%ecx
	call *240(%rdi)
L9007:
	movl $L9998,%eax
	shr $3,%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *480(%rdi)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *L9004
	movl $L9997,%eax
	shr $3,%eax
	movl %eax,48(%rbp)
	movl 2304(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *608(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl $0,56(%rbp)
	movl $4,64(%rbp)
	leal 32(%rbp),%ecx
	call *1216(%rdi)
	leal 32(%rbp),%ecx
	call *504(%rdi)
	movl 1560(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *96(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRNMESSAGE
L9003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	jmp L9009
L9011:
	movl $L9996,%eax
	shr $3,%eax
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *608(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L9012:
	movl $L9995,%eax
	shr $3,%eax
	jmp L9008
L9013:
	movl $L9994,%eax
	shr $3,%eax
	jmp L9008
L9014:
L9015:
	movl $L9993,%eax
	shr $3,%eax
	jmp L9008
L9016:
	movl $L9992,%eax
	shr $3,%eax
	jmp L9008
L9017:
	movl $L9991,%eax
	shr $3,%eax
	jmp L9008
L9018:
	movl $L9990,%eax
	shr $3,%eax
	jmp L9008
L9019:
	movl $L9989,%eax
	shr $3,%eax
	jmp L9008
L9020:
	movl $L9988,%eax
	shr $3,%eax
	jmp L9008
L9021:
	movl $L9987,%eax
	shr $3,%eax
	jmp L9008
L9022:
L9023:
L9024:
	movl $L9986,%eax
	shr $3,%eax
	jmp L9008
L9025:
L9026:
	movl $L9985,%eax
	shr $3,%eax
	jmp L9008
L9027:
L9028:
	movl $L9984,%eax
	shr $3,%eax
	jmp L9008
	jmp L9010
L9009:
	movl 16(%rbp),%eax
	mov $L9983,%rdx
	mov $17,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L9011
3:	jmp *8(%rdx)
L9010:
L9008:
	movl %eax,24(%rbp)
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *480(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L9005:
	jmp L9030
//	COMPILEAE
L9029:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	leal 32(%rbp),%eax
	shr $3,%eax
	movl %eax,24(%rbp)
	leal 12048(%rbp),%eax
	shr $3,%eax
	movl %eax,12040(%rbp)
	leal 13664(%rbp),%eax
	shr $3,%eax
	movl %eax,13656(%rbp)
	leal 16080(%rbp),%eax
	shr $3,%eax
	movl %eax,16072(%rbp)
	movl 24(%rbp),%eax
	movl %eax,2080(%rdi)
	movl $3,2088(%rdi)
	movl $3,2096(%rdi)
	movl $3,2104(%rdi)
	movl $1500,2112(%rdi)
	movl $0,18488(%rbp)
	movl $0,%eax
	addl 2080(%rdi),%eax
	mov %eax,%ecx
	movl 18488(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $0,18488(%rbp)
	movl 2080(%rdi),%eax
	incl %eax
	mov %eax,%ecx
	movl 18488(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $0,18488(%rbp)
	movl $2,%eax
	addl 2080(%rdi),%eax
	mov %eax,%ecx
	movl 18488(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 12040(%rbp),%eax
	movl %eax,2280(%rdi)
	movl $0,2288(%rdi)
	movl $200,2296(%rdi)
	movl 13656(%rbp),%eax
	movl %eax,2120(%rdi)
	movl 16072(%rbp),%eax
	movl %eax,2128(%rdi)
	movl $0,2136(%rdi)
	movl $300,2144(%rdi)
	movl $-1,2152(%rdi)
	movl $0,2192(%rdi)
	movl $0,2184(%rdi)
	movl $-1,2176(%rdi)
	movl $-1,2168(%rdi)
	movl $-1,2200(%rdi)
	movl $0,2304(%rdi)
	movl 16(%rbp),%eax
	movl %eax,2160(%rdi)
	movl $0,2008(%rdi)
	movl $0,1952(%rdi)
	movl 2256(%rdi),%eax
	movl %eax,2240(%rdi)
	cmpl $0,16(%rbp)
	je L9031
L9032:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $49,%eax
	je L9033
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $48,%eax
	je L9033
	jmp L9034
L9033:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	movl %eax,18504(%rbp)
	leal 18488(%rbp),%ecx
	call *2320(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	incl %eax
	movl %eax,18504(%rbp)
	leal 18488(%rbp),%ecx
	call *2312(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,16(%rbp)
	jmp L9032
L9034:
L9031:
	movl $91,18504(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,18512(%rbp)
	leal 18488(%rbp),%ecx
	call *2328(%rdi)
	movl 16(%rbp),%eax
	movl %eax,18504(%rbp)
	leal 18488(%rbp),%ecx
	call *1672(%rdi)
	movl 16(%rbp),%eax
	movl %eax,18504(%rbp)
	leal 18488(%rbp),%ecx
	call *1600(%rdi)
	movl $76,18504(%rbp)
	movl 2288(%rdi),%eax
	movl $2,%ecx
	cqto
	idivl %ecx
	movl %eax,18512(%rbp)
	leal 18488(%rbp),%ecx
	call *2328(%rdi)
	movl $0,18488(%rbp)
	jmp L9036
L9035:
	movl 18488(%rbp),%eax
	addl 2280(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,18512(%rbp)
	leal 18496(%rbp),%ecx
	call *2360(%rdi)
	movl 18488(%rbp),%eax
	incl %eax
	addl 2280(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,18512(%rbp)
	leal 18496(%rbp),%ecx
	call *2368(%rdi)
	movl $2,%eax
	addl 18488(%rbp),%eax
	movl %eax,18488(%rbp)
L9036:
	movl 2288(%rdi),%eax
	cmpl 18488(%rbp),%eax
	jne L9035
	leal 18496(%rbp),%ecx
	call *2016(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L9030:
	ret
	.data
	.align 4
L9004:
	.long L9003
	.align 4
L9999:
	.byte 21
	.byte 10
	.byte 67
	.byte 79
	.byte 77
	.byte 80
	.byte 73
	.byte 76
	.byte 65
	.byte 84
	.byte 73
	.byte 79
	.byte 78
	.byte 32
	.byte 65
	.byte 66
	.byte 79
	.byte 82
	.byte 84
	.byte 69
	.byte 68
	.byte 10
	.align 4
L9998:
	.byte 11
	.byte 10
	.byte 82
	.byte 69
	.byte 80
	.byte 79
	.byte 82
	.byte 84
	.byte 58
	.byte 32
	.byte 32
	.byte 32
	.align 4
L9997:
	.byte 22
	.byte 10
	.byte 67
	.byte 79
	.byte 77
	.byte 77
	.byte 65
	.byte 78
	.byte 68
	.byte 83
	.byte 32
	.byte 67
	.byte 79
	.byte 77
	.byte 80
	.byte 73
	.byte 76
	.byte 69
	.byte 68
	.byte 32
	.byte 37
	.byte 78
	.byte 10
	.align 4
L9996:
	.byte 18
	.byte 67
	.byte 79
	.byte 77
	.byte 80
	.byte 73
	.byte 76
	.byte 69
	.byte 82
	.byte 32
	.byte 69
	.byte 82
	.byte 82
	.byte 79
	.byte 82
	.byte 32
	.byte 32
	.byte 37
	.byte 78
	.align 4
L9995:
	.byte 14
	.byte 84
	.byte 79
	.byte 79
	.byte 32
	.byte 77
	.byte 65
	.byte 78
	.byte 89
	.byte 32
	.byte 67
	.byte 65
	.byte 83
	.byte 69
	.byte 83
	.align 4
L9994:
	.byte 38
	.byte 73
	.byte 76
	.byte 76
	.byte 69
	.byte 71
	.byte 65
	.byte 76
	.byte 32
	.byte 85
	.byte 83
	.byte 69
	.byte 32
	.byte 79
	.byte 70
	.byte 32
	.byte 66
	.byte 82
	.byte 69
	.byte 65
	.byte 75
	.byte 44
	.byte 32
	.byte 76
	.byte 79
	.byte 79
	.byte 80
	.byte 32
	.byte 79
	.byte 82
	.byte 32
	.byte 82
	.byte 69
	.byte 83
	.byte 85
	.byte 76
	.byte 84
	.byte 73
	.byte 83
	.align 4
L9993:
	.byte 30
	.byte 73
	.byte 76
	.byte 76
	.byte 69
	.byte 71
	.byte 65
	.byte 76
	.byte 32
	.byte 85
	.byte 83
	.byte 69
	.byte 32
	.byte 79
	.byte 70
	.byte 32
	.byte 67
	.byte 65
	.byte 83
	.byte 69
	.byte 32
	.byte 79
	.byte 82
	.byte 32
	.byte 68
	.byte 69
	.byte 70
	.byte 65
	.byte 85
	.byte 76
	.byte 84
	.align 4
L9992:
	.byte 28
	.byte 84
	.byte 87
	.byte 79
	.byte 32
	.byte 67
	.byte 65
	.byte 83
	.byte 69
	.byte 83
	.byte 32
	.byte 87
	.byte 73
	.byte 84
	.byte 72
	.byte 32
	.byte 83
	.byte 65
	.byte 77
	.byte 69
	.byte 32
	.byte 67
	.byte 79
	.byte 78
	.byte 83
	.byte 84
	.byte 65
	.byte 78
	.byte 84
	.align 4
L9991:
	.byte 16
	.byte 84
	.byte 79
	.byte 79
	.byte 32
	.byte 77
	.byte 65
	.byte 78
	.byte 89
	.byte 32
	.byte 71
	.byte 76
	.byte 79
	.byte 66
	.byte 65
	.byte 76
	.byte 83
	.align 4
L9990:
	.byte 19
	.byte 78
	.byte 65
	.byte 77
	.byte 69
	.byte 32
	.byte 68
	.byte 69
	.byte 67
	.byte 76
	.byte 65
	.byte 82
	.byte 69
	.byte 68
	.byte 32
	.byte 84
	.byte 87
	.byte 73
	.byte 67
	.byte 69
	.align 4
L9989:
	.byte 23
	.byte 84
	.byte 79
	.byte 79
	.byte 32
	.byte 77
	.byte 65
	.byte 78
	.byte 89
	.byte 32
	.byte 78
	.byte 65
	.byte 77
	.byte 69
	.byte 83
	.byte 32
	.byte 68
	.byte 69
	.byte 67
	.byte 76
	.byte 65
	.byte 82
	.byte 69
	.byte 68
	.align 4
L9988:
	.byte 17
	.byte 78
	.byte 65
	.byte 77
	.byte 69
	.byte 32
	.byte 78
	.byte 79
	.byte 84
	.byte 32
	.byte 68
	.byte 69
	.byte 67
	.byte 76
	.byte 65
	.byte 82
	.byte 69
	.byte 68
	.align 4
L9987:
	.byte 26
	.byte 68
	.byte 89
	.byte 78
	.byte 65
	.byte 77
	.byte 73
	.byte 67
	.byte 32
	.byte 70
	.byte 82
	.byte 69
	.byte 69
	.byte 32
	.byte 86
	.byte 65
	.byte 82
	.byte 73
	.byte 65
	.byte 66
	.byte 76
	.byte 69
	.byte 32
	.byte 85
	.byte 83
	.byte 69
	.byte 68
	.align 4
L9986:
	.byte 28
	.byte 69
	.byte 82
	.byte 82
	.byte 79
	.byte 82
	.byte 32
	.byte 73
	.byte 78
	.byte 32
	.byte 67
	.byte 79
	.byte 78
	.byte 83
	.byte 84
	.byte 65
	.byte 78
	.byte 84
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 82
	.byte 69
	.byte 83
	.byte 83
	.byte 73
	.byte 79
	.byte 78
	.align 4
L9985:
	.byte 24
	.byte 76
	.byte 72
	.byte 83
	.byte 32
	.byte 65
	.byte 78
	.byte 68
	.byte 32
	.byte 82
	.byte 72
	.byte 83
	.byte 32
	.byte 68
	.byte 79
	.byte 32
	.byte 78
	.byte 79
	.byte 84
	.byte 32
	.byte 77
	.byte 65
	.byte 84
	.byte 67
	.byte 72
	.align 4
L9984:
	.byte 25
	.byte 76
	.byte 84
	.byte 89
	.byte 80
	.byte 69
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 82
	.byte 69
	.byte 83
	.byte 83
	.byte 73
	.byte 79
	.byte 78
	.byte 32
	.byte 69
	.byte 88
	.byte 80
	.byte 69
	.byte 67
	.byte 84
	.byte 69
	.byte 68
	.align 4
L9983:
	.long 141
	.long L9012
	.long 104
	.long L9013
	.long 101
	.long L9014
	.long 105
	.long L9015
	.long 106
	.long L9016
	.long 144
	.long L9017
	.long 142
	.long L9018
	.long 143
	.long L9019
	.long 115
	.long L9020
	.long 116
	.long L9021
	.long 117
	.long L9022
	.long 118
	.long L9023
	.long 119
	.long L9024
	.long 110
	.long L9025
	.long 112
	.long L9026
	.long 109
	.long L9027
	.long 113
	.long L9028
	.global G243
	.equ G243,L9001
	.global G210
	.equ G210,L9002
	.global G245
	.equ G245,L9029
	.text
//	SECTION: TRN1
	jmp L10002
//	TRANS
L10001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
L10003:
	movl $0,24(%rbp)
	cmpl $0,16(%rbp)
	jne L10005
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10005:
	movl 16(%rbp),%eax
	movl %eax,2160(%rdi)
	jmp L10006
L10008:
	movl $100,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10009:
	movl 2096(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,40(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,48(%rbp)
	movl $0,56(%rbp)
	movl 2248(%rdi),%eax
	movl %eax,64(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1608(%rdi)
	movl 40(%rbp),%eax
	movl %eax,88(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,96(%rbp)
	leal 72(%rbp),%ecx
	call *1632(%rdi)
	movl 2088(%rdi),%eax
	movl %eax,2096(%rdi)
	movl 2240(%rdi),%eax
	movl %eax,2248(%rdi)
	movl 2240(%rdi),%eax
	movl %eax,56(%rbp)
	movl 48(%rbp),%eax
	movl %eax,2240(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1656(%rdi)
	movl 56(%rbp),%eax
	cmpl 2240(%rdi),%eax
	je L10010
	movl $110,88(%rbp)
	movl 16(%rbp),%eax
	movl %eax,96(%rbp)
	leal 72(%rbp),%ecx
	call *1680(%rdi)
L10010:
	movl 2248(%rdi),%eax
	cmpl 2240(%rdi),%eax
	je L10011
	movl 2248(%rdi),%eax
	movl %eax,2240(%rdi)
	movl $91,88(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,96(%rbp)
	leal 72(%rbp),%ecx
	call *2328(%rdi)
L10011:
	movl $92,88(%rbp)
	leal 72(%rbp),%ecx
	call *2320(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1672(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1600(%rdi)
	movl 64(%rbp),%eax
	movl %eax,2248(%rdi)
	movl 48(%rbp),%eax
	cmpl 2240(%rdi),%eax
	je L10012
	movl $91,88(%rbp)
	movl 48(%rbp),%eax
	movl %eax,96(%rbp)
	leal 72(%rbp),%ecx
	call *2328(%rdi)
L10012:
	movl 32(%rbp),%eax
	movl %eax,2096(%rdi)
	movl 40(%rbp),%eax
	movl %eax,2088(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10013:
L10014:
L10015:
	movl 2096(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,40(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	cmpl $75,56(%rbp)
	jne L10016
	movl $1,56(%rbp)
L10016:
	jmp L10018
L10017:
	cmpl $79,56(%rbp)
	jne L10019
	leal 72(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,72(%rbp)
	movl 64(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	movl $78,104(%rbp)
	movl 72(%rbp),%eax
	movl %eax,112(%rbp)
	leal 80(%rbp),%ecx
	call *1640(%rdi)
	movl 72(%rbp),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *1872(%rdi)
	movl $102,96(%rbp)
	movl 64(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	jmp L10020
L10019:
	movl 64(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	movl 56(%rbp),%eax
	movl %eax,96(%rbp)
	movl 64(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,104(%rbp)
	leal 72(%rbp),%ecx
	call *1640(%rdi)
L10020:
	movl 64(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,2096(%rdi)
L10018:
	cmpl $0,64(%rbp)
	jne L10017
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1672(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,88(%rbp)
	leal 72(%rbp),%ecx
	call *1600(%rdi)
	movl 32(%rbp),%eax
	movl %eax,2096(%rdi)
	movl 40(%rbp),%eax
	movl %eax,2088(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10021:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1840(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10022:
	movl 2240(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2256(%rdi),%eax
	addl 2240(%rdi),%eax
	movl %eax,2240(%rdi)
	movl $91,56(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1864(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1848(%rdi)
	movl $51,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl 32(%rbp),%eax
	movl %eax,2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10023:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl $52,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10024:
	movl $89,48(%rbp)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *2336(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1600(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10025:
	movl $-1,24(%rbp)
L10026:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *1760(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1600(%rdi)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10027:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	leal 40(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	movl $0,72(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1760(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1600(%rdi)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1928(%rdi)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1600(%rdi)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1920(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10028:
	cmpl $0,2200(%rdi)
	jge L10029
	movl $104,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
L10029:
	cmpl $0,2200(%rdi)
	jne L10030
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,2200(%rdi)
L10030:
	movl 2200(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1928(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10031:
	cmpl $0,2168(%rdi)
	jge L10032
	movl $104,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
L10032:
	cmpl $0,2168(%rdi)
	jne L10033
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,2168(%rdi)
L10033:
	movl 2168(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1928(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10034:
	movl $97,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10035:
	movl $68,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10036:
	cmpl $0,2176(%rdi)
	jge L10037
	movl $104,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
L10037:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl $98,48(%rbp)
	movl 2176(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *2336(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10038:
	movl $-1,24(%rbp)
L10039:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	leal 40(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,40(%rbp)
	movl 2168(%rdi),%eax
	movl %eax,48(%rbp)
	movl 2200(%rdi),%eax
	movl %eax,56(%rbp)
	movl $0,2168(%rdi)
	movl 40(%rbp),%eax
	movl %eax,2200(%rdi)
	movl 40(%rbp),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1928(%rdi)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1600(%rdi)
	movl 40(%rbp),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,80(%rbp)
	movl 24(%rbp),%eax
	movl %eax,88(%rbp)
	movl 32(%rbp),%eax
	movl %eax,96(%rbp)
	leal 64(%rbp),%ecx
	call *1760(%rdi)
	cmpl $0,2168(%rdi)
	je L10040
	movl 2168(%rdi),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1920(%rdi)
L10040:
	movl 48(%rbp),%eax
	movl %eax,2168(%rdi)
	movl 56(%rbp),%eax
	movl %eax,2200(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10041:
	movl $-1,24(%rbp)
L10042:
L10043:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	movl 2168(%rdi),%eax
	movl %eax,40(%rbp)
	movl 2200(%rdi),%eax
	movl %eax,48(%rbp)
	movl $0,2168(%rdi)
	movl $0,2200(%rdi)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $61,%eax
	jne L10044
	movl 32(%rbp),%eax
	movl %eax,2200(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1600(%rdi)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1928(%rdi)
	jmp L10045
L10044:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1600(%rdi)
	cmpl $0,2200(%rdi)
	je L10046
	movl 2200(%rdi),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
L10046:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	movl 24(%rbp),%eax
	movl %eax,80(%rbp)
	movl 32(%rbp),%eax
	movl %eax,88(%rbp)
	leal 56(%rbp),%ecx
	call *1760(%rdi)
L10045:
	cmpl $0,2168(%rdi)
	je L10047
	movl 2168(%rdi),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
L10047:
	movl 40(%rbp),%eax
	movl %eax,2168(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2200(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10048:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,40(%rbp)
	movl 2136(%rdi),%eax
	cmpl 2144(%rdi),%eax
	jl L10049
	movl $141,64(%rbp)
	movl 16(%rbp),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *1680(%rdi)
L10049:
	cmpl $0,2152(%rdi)
	jge L10050
	movl $105,64(%rbp)
	movl 16(%rbp),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *1680(%rdi)
L10050:
	movl 2152(%rdi),%eax
	movl %eax,48(%rbp)
	movl 2136(%rdi),%eax
	decl %eax
	movl %eax,56(%rbp)
	jmp L10051
L10052:
	movl 48(%rbp),%eax
	addl 2120(%rdi),%eax
	mov (,%rax,8),%eax
	cmpl 40(%rbp),%eax
	jne L10053
	movl $106,80(%rbp)
	movl 16(%rbp),%eax
	movl %eax,88(%rbp)
	leal 64(%rbp),%ecx
	call *1680(%rdi)
L10053:
	incl 48(%rbp)
L10051:
	movl 48(%rbp),%eax
	cmpl 56(%rbp),%eax
	jle L10052
	movl 40(%rbp),%eax
	movl %eax,48(%rbp)
	movl 2136(%rdi),%eax
	addl 2120(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	movl %eax,48(%rbp)
	movl 2136(%rdi),%eax
	addl 2128(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	incl 2136(%rdi)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1600(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10054:
	cmpl $0,2152(%rdi)
	jge L10055
	movl $105,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
L10055:
	cmpl $0,2184(%rdi)
	je L10056
	movl $101,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
L10056:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,2184(%rdi)
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1600(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10057:
	cmpl $0,2152(%rdi)
	jge L10058
	movl $105,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
L10058:
	movl 2192(%rdi),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1928(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10059:
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1768(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10060:
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1776(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10061:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1600(%rdi)
	incl 2304(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,16(%rbp)
	jmp *L10004
	jmp L10007
L10006:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L10999,%rdx
	mov $27,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L10008
3:	jmp *8(%rdx)
L10007:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L10002:
	ret
	.data
	.align 4
L10004:
	.long L10003
	.align 4
L10999:
	.long 74
	.long L10009
	.long 79
	.long L10013
	.long 76
	.long L10014
	.long 75
	.long L10015
	.long 50
	.long L10021
	.long 51
	.long L10022
	.long 52
	.long L10023
	.long 54
	.long L10024
	.long 58
	.long L10025
	.long 57
	.long L10026
	.long 55
	.long L10027
	.long 65
	.long L10028
	.long 66
	.long L10031
	.long 67
	.long L10034
	.long 68
	.long L10035
	.long 53
	.long L10036
	.long 59
	.long L10038
	.long 60
	.long L10039
	.long 62
	.long L10041
	.long 63
	.long L10042
	.long 61
	.long L10043
	.long 71
	.long L10048
	.long 72
	.long L10054
	.long 69
	.long L10057
	.long 70
	.long L10059
	.long 56
	.long L10060
	.long 73
	.long L10061
	.global G200
	.equ G200,L10001
	.text
//	SECTION: TRN2
	jmp L11017
//	DECLNAMES
L11001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	je L11018
	jmp L11019
L11021:
	movl $102,40(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1680(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11022:
L11023:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1616(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11024:
L11025:
	leal 24(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $4,%eax
	mov %eax,%ecx
	movl 24(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	addl $4,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1624(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11026:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1608(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1608(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L11020
L11019:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L11999,%rdx
	mov $5,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L11021
3:	jmp *8(%rdx)
L11020:
L11018:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	DECLDYN
L11002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	je L11027
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $2,%eax
	jne L11028
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	movl $77,48(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,56(%rbp)
	leal 24(%rbp),%ecx
	call *1640(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11028:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $38,%eax
	jne L11029
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	movl $77,48(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,56(%rbp)
	leal 24(%rbp),%ecx
	call *1640(%rdi)
	incl 2240(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1616(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11029:
	movl $103,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1680(%rdi)
L11027:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	DECLSTAT
L11003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1648(%rdi)
	movl %eax,32(%rbp)
	movl 32(%rbp),%eax
	incl %eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	cmpl $76,%eax
	jne L11030
	movl $2,%eax
	addl 32(%rbp),%eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	movl $76,72(%rbp)
	movl 40(%rbp),%eax
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1640(%rdi)
	movl 2288(%rdi),%eax
	cmpl 2296(%rdi),%eax
	jl L11031
	movl $144,64(%rbp)
	movl 16(%rbp),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *1680(%rdi)
L11031:
	movl 40(%rbp),%eax
	movl %eax,48(%rbp)
	movl 2288(%rdi),%eax
	addl 2280(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl 2288(%rdi),%eax
	incl %eax
	addl 2280(%rdi),%eax
	mov %eax,%ecx
	movl 48(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $2,%eax
	addl 2288(%rdi),%eax
	movl %eax,2288(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11030:
	leal 40(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	movl $78,72(%rbp)
	movl 40(%rbp),%eax
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1640(%rdi)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1872(%rdi)
	movl $101,64(%rbp)
	movl 24(%rbp),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *2336(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	DECLLABELS
L11004:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 2088(%rdi),%eax
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *L11009
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1632(%rdi)
	movl 2088(%rdi),%eax
	movl %eax,2096(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	CHECKDISTINCT
L11005:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	jmp L11033
L11032:
	movl $3,%eax
	addl 16(%rbp),%eax
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	jmp L11035
L11034:
	movl 32(%rbp),%eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	cmpl 40(%rbp),%eax
	jne L11036
	movl $142,64(%rbp)
	movl 40(%rbp),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *1680(%rdi)
L11036:
	movl $3,%eax
	addl 32(%rbp),%eax
	movl %eax,32(%rbp)
L11035:
	movl 32(%rbp),%eax
	cmpl 24(%rbp),%eax
	jl L11034
	movl $3,%eax
	addl 16(%rbp),%eax
	movl %eax,16(%rbp)
L11033:
	movl 24(%rbp),%eax
	cmpl 16(%rbp),%eax
	jne L11032
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	ADDNAME
L11006:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 2088(%rdi),%eax
	cmpl 2112(%rdi),%eax
	jl L11037
	movl $143,56(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *1680(%rdi)
L11037:
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	movl 2088(%rdi),%eax
	addl 2080(%rdi),%eax
	mov %eax,%ecx
	movl 40(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 24(%rbp),%eax
	movl %eax,40(%rbp)
	movl 2088(%rdi),%eax
	incl %eax
	addl 2080(%rdi),%eax
	mov %eax,%ecx
	movl 40(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 32(%rbp),%eax
	movl %eax,40(%rbp)
	movl $2,%eax
	addl 2088(%rdi),%eax
	addl 2080(%rdi),%eax
	mov %eax,%ecx
	movl 40(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl $3,%eax
	addl 2088(%rdi),%eax
	movl %eax,2088(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	CELLWITHNAME
L11007:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 2096(%rdi),%eax
	movl %eax,24(%rbp)
L11039:
	movl 24(%rbp),%eax
	subl $3,%eax
	movl %eax,24(%rbp)
	cmpl $0,24(%rbp)
	je L11040
	movl 24(%rbp),%eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	cmpl 16(%rbp),%eax
	jne L11039
L11040:
	movl 24(%rbp),%eax
L11038:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	SCANLABELS
L11008:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	je L11041
	jmp L11042
L11044:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11045:
	leal 24(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov %eax,%ecx
	movl 24(%rbp),%eax
	mov %eax,(,%rcx,8)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1624(%rdi)
L11046:
L11047:
L11048:
L11049:
L11050:
L11051:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11009
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11052:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11009
L11053:
L11054:
L11055:
L11056:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11009
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11057:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11009
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11009
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L11043
L11042:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L11998,%rdx
	mov $13,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L11044
3:	jmp *8(%rdx)
L11043:
L11041:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSDEF
L11010:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11012
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11016
	orl %eax,%eax
	jz L11058
	leal 24(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,24(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,32(%rbp)
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1928(%rdi)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *L11014
	movl 32(%rbp),%eax
	movl %eax,2240(%rdi)
	movl $91,56(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1920(%rdi)
L11058:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSDYNDEFS
L11011:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	jmp L11059
L11061:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11012
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11012
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11062:
	movl $45,40(%rbp)
	movl 2248(%rdi),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *2328(%rdi)
	incl 2240(%rdi)
	movl 2248(%rdi),%eax
	incl %eax
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	addl %ecx,%eax
	movl %eax,2248(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11063:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1864(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11064:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L11060
L11059:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L11997,%rdx
	mov $3,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L11064
3:	jmp *8(%rdx)
L11060:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSSTATDEFS
L11013:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	jmp L11065
L11067:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11014
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11014
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11068:
L11069:
	movl 2096(%rdi),%eax
	movl %eax,24(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2104(%rdi),%eax
	movl %eax,40(%rbp)
	movl 2168(%rdi),%eax
	movl %eax,48(%rbp)
	movl 2200(%rdi),%eax
	movl %eax,56(%rbp)
	movl 2176(%rdi),%eax
	movl %eax,64(%rbp)
	movl 2152(%rdi),%eax
	movl %eax,72(%rbp)
	movl $-1,2168(%rdi)
	movl $-1,2200(%rdi)
	movl $-1,2176(%rdi)
	movl $-1,2152(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	movl 16(%rbp),%eax
	addl $4,%eax
	mov (,%rax,8),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *1936(%rdi)
	movl 2256(%rdi),%eax
	movl %eax,2240(%rdi)
	movl 2088(%rdi),%eax
	movl %eax,2104(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *1616(%rdi)
	movl 32(%rbp),%eax
	movl %eax,96(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *1632(%rdi)
	movl 2088(%rdi),%eax
	movl %eax,2096(%rdi)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *1672(%rdi)
	movl $95,96(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $44,%eax
	jne L11070
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *1848(%rdi)
	movl $96,96(%rbp)
	leal 80(%rbp),%ecx
	call *2320(%rdi)
	jmp L11071
L11070:
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *1600(%rdi)
	movl $97,96(%rbp)
	leal 80(%rbp),%ecx
	call *2320(%rdi)
L11071:
	movl $103,96(%rbp)
	movl $0,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2168(%rdi)
	movl 56(%rbp),%eax
	movl %eax,2200(%rdi)
	movl 64(%rbp),%eax
	movl %eax,2176(%rdi)
	movl 72(%rbp),%eax
	movl %eax,2152(%rdi)
	movl 24(%rbp),%eax
	movl %eax,2096(%rdi)
	movl 32(%rbp),%eax
	movl %eax,2088(%rdi)
	movl 40(%rbp),%eax
	movl %eax,2104(%rdi)
L11072:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L11066
L11065:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L11996,%rdx
	mov $3,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L11072
3:	jmp *8(%rdx)
L11066:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	STATDEFS
L11015:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $44,%eax
	je L11075
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $45,%eax
	jne L11074
L11075:
	movl $-1,%eax
	jmp L11073
L11074:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $40,%eax
	je L11077
	movl $0,%eax
	jmp L11076
L11077:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11016
	orl %eax,%eax
	jz L11079
	movl $-1,%eax
	jmp L11078
L11079:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *L11016
L11078:
L11076:
L11073:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L11017:
	ret
	.data
	.align 4
L11009:
	.long L11008
	.align 4
L11012:
	.long L11011
	.align 4
L11014:
	.long L11013
	.align 4
L11016:
	.long L11015
	.align 4
L11999:
	.long 42
	.long L11022
	.long 41
	.long L11023
	.long 45
	.long L11024
	.long 44
	.long L11025
	.long 40
	.long L11026
	.align 4
L11998:
	.long 54
	.long L11045
	.long 57
	.long L11046
	.long 58
	.long L11047
	.long 59
	.long L11048
	.long 60
	.long L11049
	.long 70
	.long L11050
	.long 71
	.long L11051
	.long 73
	.long L11052
	.long 61
	.long L11053
	.long 62
	.long L11054
	.long 63
	.long L11055
	.long 72
	.long L11056
	.long 55
	.long L11057
	.align 4
L11997:
	.long 40
	.long L11061
	.long 42
	.long L11062
	.long 41
	.long L11063
	.align 4
L11996:
	.long 40
	.long L11067
	.long 44
	.long L11068
	.long 45
	.long L11069
	.global G201
	.equ G201,L11001
	.global G202
	.equ G202,L11002
	.global G203
	.equ G203,L11003
	.global G209
	.equ G209,L11004
	.global G204
	.equ G204,L11005
	.global G205
	.equ G205,L11006
	.global G206
	.equ G206,L11007
	.global G207
	.equ G207,L11010
	.text
//	SECTION: TRN3
	jmp L12004
//	JUMPCOND
L12001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 24(%rbp),%eax
	movl %eax,40(%rbp)
	jmp L12005
L12007:
	notl 24(%rbp)
L12008:
	movl 24(%rbp),%eax
	orl %eax,%eax
	jz L12009
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1928(%rdi)
L12009:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L12010:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	movl 24(%rbp),%eax
	notl %eax
	movl %eax,72(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1760(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L12011:
	notl 40(%rbp)
L12012:
	movl 40(%rbp),%eax
	orl %eax,%eax
	jz L12013
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	movl 24(%rbp),%eax
	movl %eax,72(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1760(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	movl 24(%rbp),%eax
	movl %eax,72(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 48(%rbp),%ecx
	call *1760(%rdi)
	jmp L12014
L12013:
	leal 48(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	movl 24(%rbp),%eax
	notl %eax
	movl %eax,80(%rbp)
	movl 48(%rbp),%eax
	movl %eax,88(%rbp)
	leal 56(%rbp),%ecx
	call *1760(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	movl 24(%rbp),%eax
	movl %eax,80(%rbp)
	movl 32(%rbp),%eax
	movl %eax,88(%rbp)
	leal 56(%rbp),%ecx
	call *1760(%rdi)
	movl 48(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
L12014:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L12015:
	movl 16(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1848(%rdi)
	movl 24(%rbp),%eax
	orl %eax,%eax
	jz L12017
	movl $86,%eax
	jmp L12016
L12017:
	movl $87,%eax
L12016:
	movl %eax,64(%rbp)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	leal 48(%rbp),%ecx
	call *2336(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L12006
L12005:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L12999,%rdx
	mov $5,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L12015
3:	jmp *8(%rdx)
L12006:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSSWITCH
L12002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 2136(%rdi),%eax
	movl %eax,24(%rbp)
	movl 2152(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2184(%rdi),%eax
	movl %eax,40(%rbp)
	movl 2192(%rdi),%eax
	movl %eax,48(%rbp)
	leal 56(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,56(%rbp)
	leal 64(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,2192(%rdi)
	movl 2136(%rdi),%eax
	movl %eax,2152(%rdi)
	movl 56(%rbp),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1928(%rdi)
	movl $0,2184(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1600(%rdi)
	movl 2192(%rdi),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1928(%rdi)
	movl 56(%rbp),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1848(%rdi)
	cmpl $0,2184(%rdi)
	jne L12018
	movl 2192(%rdi),%eax
	movl %eax,2184(%rdi)
L12018:
	movl $70,80(%rbp)
	movl 2136(%rdi),%eax
	subl 24(%rbp),%eax
	movl %eax,88(%rbp)
	movl 2184(%rdi),%eax
	movl %eax,96(%rbp)
	leal 64(%rbp),%ecx
	call *2352(%rdi)
	movl 2152(%rdi),%eax
	movl %eax,64(%rbp)
	movl 2136(%rdi),%eax
	decl %eax
	movl %eax,72(%rbp)
	jmp L12019
L12020:
	movl 64(%rbp),%eax
	addl 2120(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *2360(%rdi)
	movl 64(%rbp),%eax
	addl 2128(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,96(%rbp)
	leal 80(%rbp),%ecx
	call *2368(%rdi)
	incl 64(%rbp)
L12019:
	movl 64(%rbp),%eax
	cmpl 72(%rbp),%eax
	jle L12020
	decl 2240(%rdi)
	movl 2192(%rdi),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1920(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2192(%rdi)
	movl 24(%rbp),%eax
	movl %eax,2136(%rdi)
	movl 32(%rbp),%eax
	movl %eax,2152(%rdi)
	movl 40(%rbp),%eax
	movl %eax,2184(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSFOR
L12003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 2096(%rdi),%eax
	movl %eax,24(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,32(%rbp)
	leal 40(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,40(%rbp)
	leal 48(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,48(%rbp)
	movl 2168(%rdi),%eax
	movl %eax,56(%rbp)
	movl 2200(%rdi),%eax
	movl %eax,64(%rbp)
	movl $0,72(%rbp)
	movl $0,80(%rbp)
	movl $1,88(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,96(%rbp)
	movl $0,2168(%rdi)
	movl $0,2200(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	movl $77,128(%rbp)
	movl 96(%rbp),%eax
	movl %eax,136(%rbp)
	leal 104(%rbp),%ecx
	call *1640(%rdi)
	movl 2088(%rdi),%eax
	movl %eax,2096(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1848(%rdi)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	mov (,%rax,8),%eax
	cmpl $1,%eax
	jne L12021
	movl $42,72(%rbp)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,80(%rbp)
	jmp L12022
L12021:
	movl $40,72(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,80(%rbp)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1848(%rdi)
L12022:
	movl 16(%rbp),%eax
	addl $4,%eax
	mov (,%rax,8),%eax
	cmpl $0,%eax
	je L12023
	movl 16(%rbp),%eax
	addl $4,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,88(%rbp)
L12023:
	movl $92,120(%rbp)
	leal 104(%rbp),%ecx
	call *2320(%rdi)
	movl 40(%rbp),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1928(%rdi)
	movl 16(%rbp),%eax
	addl $5,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1672(%rdi)
	movl 48(%rbp),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	addl $5,%eax
	mov (,%rax,8),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1600(%rdi)
	cmpl $0,2200(%rdi)
	je L12024
	movl 2200(%rdi),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1920(%rdi)
L12024:
	movl $40,120(%rbp)
	movl 96(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	movl $42,120(%rbp)
	movl 88(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	movl $14,120(%rbp)
	leal 104(%rbp),%ecx
	call *2320(%rdi)
	movl $80,120(%rbp)
	movl 96(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	movl 40(%rbp),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1920(%rdi)
	cmpl $0,88(%rbp)
	jle L12025
	movl $40,120(%rbp)
	movl 96(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	movl 72(%rbp),%eax
	movl %eax,120(%rbp)
	movl 80(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	jmp L12026
L12025:
	movl 72(%rbp),%eax
	movl %eax,120(%rbp)
	movl 80(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	movl $40,120(%rbp)
	movl 96(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
L12026:
	movl $88,120(%rbp)
	movl 48(%rbp),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2336(%rdi)
	cmpl $0,2168(%rdi)
	je L12027
	movl 2168(%rdi),%eax
	movl %eax,120(%rbp)
	leal 104(%rbp),%ecx
	call *1920(%rdi)
L12027:
	movl 56(%rbp),%eax
	movl %eax,2168(%rdi)
	movl 64(%rbp),%eax
	movl %eax,2200(%rdi)
	movl 96(%rbp),%eax
	movl %eax,2240(%rdi)
	movl $91,120(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,128(%rbp)
	leal 104(%rbp),%ecx
	call *2328(%rdi)
	movl 24(%rbp),%eax
	movl %eax,2096(%rdi)
	movl 32(%rbp),%eax
	movl %eax,2088(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L12004:
	ret
	.data
	.align 4
L12999:
	.long 5
	.long L12007
	.long 4
	.long L12008
	.long 30
	.long L12010
	.long 33
	.long L12011
	.long 34
	.long L12012
	.global G220
	.equ G220,L12001
	.global G221
	.equ G221,L12002
	.global G222
	.equ G222,L12003
	.text
//	SECTION: TRN4
	jmp L13005
//	LOAD
L13001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	jne L13006
	movl $148,40(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1680(%rdi)
	leal 24(%rbp),%ecx
	call *1888(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13006:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	movl %eax,24(%rbp)
	jmp L13007
L13009:
	movl $147,48(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
	leal 32(%rbp),%ecx
	call *1888(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13010:
	movl $120,24(%rbp)
L13011:
L13012:
L13013:
L13014:
L13015:
L13016:
L13017:
L13018:
L13019:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13020:
L13021:
L13022:
L13023:
L13024:
L13025:
L13026:
L13027:
L13028:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	movl 32(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $2,%eax
	je L13030
	movl 32(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $1,%eax
	jne L13029
L13030:
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
L13029:
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1848(%rdi)
	movl 40(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *1848(%rdi)
	cmpl $9,24(%rbp)
	jne L13031
	movl $14,64(%rbp)
	leal 48(%rbp),%ecx
	call *2320(%rdi)
	movl $8,24(%rbp)
L13031:
	movl 24(%rbp),%eax
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *2320(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13032:
L13033:
L13034:
L13035:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13036:
L13037:
L13038:
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13039:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1856(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13040:
	movl $42,48(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *2328(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13041:
	movl $43,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2312(%rdi)
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13042:
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	movl $40,56(%rbp)
	movl $41,64(%rbp)
	movl $44,72(%rbp)
	movl $42,80(%rbp)
	leal 32(%rbp),%ecx
	call *1896(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13043:
	movl 2176(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2088(%rdi),%eax
	movl %eax,40(%rbp)
	movl 2096(%rdi),%eax
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1672(%rdi)
	leal 56(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,2176(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1600(%rdi)
	movl 2176(%rdi),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
	movl $93,72(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,80(%rbp)
	leal 56(%rbp),%ecx
	call *2328(%rdi)
	incl 2240(%rdi)
	movl 40(%rbp),%eax
	movl %eax,2088(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2096(%rdi)
	movl 32(%rbp),%eax
	movl %eax,2176(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13044:
	movl 2240(%rdi),%eax
	movl %eax,32(%rbp)
	movl 2256(%rdi),%eax
	addl 2240(%rdi),%eax
	movl %eax,2240(%rdi)
	movl $91,56(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1864(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1848(%rdi)
	movl $10,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl 32(%rbp),%eax
	incl %eax
	movl %eax,2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13045:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	leal 40(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,40(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,48(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	movl $0,80(%rbp)
	movl 40(%rbp),%eax
	movl %eax,88(%rbp)
	leal 56(%rbp),%ecx
	call *1760(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1848(%rdi)
	movl $98,72(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 56(%rbp),%ecx
	call *2336(%rdi)
	movl 48(%rbp),%eax
	movl %eax,2240(%rdi)
	movl $91,72(%rbp)
	movl 2240(%rdi),%eax
	movl %eax,80(%rbp)
	leal 56(%rbp),%ecx
	call *2328(%rdi)
	movl 40(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
	movl 16(%rbp),%eax
	addl $3,%eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1848(%rdi)
	movl $98,72(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	leal 56(%rbp),%ecx
	call *2336(%rdi)
	movl 32(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1920(%rdi)
	movl $93,72(%rbp)
	movl 48(%rbp),%eax
	movl %eax,80(%rbp)
	leal 56(%rbp),%ecx
	call *2328(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13046:
	leal 32(%rbp),%ecx
	call *1944(%rdi)
	movl %eax,32(%rbp)
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1872(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,16(%rbp)
	jmp L13048
L13047:
	movl $102,56(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,16(%rbp)
L13048:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $38,%eax
	je L13047
	movl $102,56(%rbp)
	movl 16(%rbp),%eax
	movl %eax,80(%rbp)
	leal 64(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2328(%rdi)
	movl $47,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	leal 40(%rbp),%ecx
	call *2336(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L13008
L13007:
	movl 24(%rbp),%eax
	mov $L13999,%rdx
	mov $34,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L13009
3:	jmp *8(%rdx)
L13008:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LOADLV
L13002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	jne L13051
	jmp *L13050
L13051:
	jmp L13052
L13054:
L13049:
	movl $113,40(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1680(%rdi)
	leal 24(%rbp),%ecx
	call *1888(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13055:
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	movl $45,48(%rbp)
	movl $46,56(%rbp)
	movl $47,64(%rbp)
	movl $0,72(%rbp)
	leal 24(%rbp),%ecx
	call *1896(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13056:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1848(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13057:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
	movl 24(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $2,%eax
	jne L13058
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,32(%rbp)
L13058:
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1848(%rdi)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *1848(%rdi)
	movl $14,56(%rbp)
	leal 40(%rbp),%ecx
	call *2320(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
	jmp L13053
L13052:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L13998,%rdx
	mov $3,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L13054
3:	jmp *8(%rdx)
L13053:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LOADZERO
L13003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $42,32(%rbp)
	movl $0,40(%rbp)
	leal 16(%rbp),%ecx
	call *2328(%rdi)
	incl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	LOADLIST
L13004:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	je L13059
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $38,%eax
	je L13060
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1848(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13060:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1864(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1864(%rdi)
L13059:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L13005:
	ret
	.data
	.align 4
L13999:
	.long 28
	.long L13010
	.long 12
	.long L13011
	.long 13
	.long L13012
	.long 15
	.long L13013
	.long 22
	.long L13014
	.long 23
	.long L13015
	.long 24
	.long L13016
	.long 25
	.long L13017
	.long 31
	.long L13018
	.long 32
	.long L13019
	.long 9
	.long L13020
	.long 11
	.long L13021
	.long 14
	.long L13022
	.long 20
	.long L13023
	.long 21
	.long L13024
	.long 33
	.long L13025
	.long 34
	.long L13026
	.long 35
	.long L13027
	.long 36
	.long L13028
	.long 17
	.long L13032
	.long 30
	.long L13033
	.long 8
	.long L13034
	.long 19
	.long L13035
	.long 4
	.long L13036
	.long 5
	.long L13037
	.long 16
	.long L13038
	.long 7
	.long L13039
	.long 1
	.long L13040
	.long 3
	.long L13041
	.long 2
	.long L13042
	.long 6
	.long L13043
	.long 10
	.long L13044
	.long 37
	.long L13045
	.long 39
	.long L13046
	.align 4
L13050:
	.long L13049
	.align 4
L13998:
	.long 2
	.long L13055
	.long 8
	.long L13056
	.long 9
	.long L13057
	.global G231
	.equ G231,L13001
	.global G232
	.equ G232,L13002
	.global G236
	.equ G236,L13003
	.global G233
	.equ G233,L13004
	.text
//	SECTION: TRN5
	jmp L14004
//	EVALCONST
L14001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	jne L14006
	movl $117,40(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1680(%rdi)
	movl $0,%eax
	jmp L14005
L14006:
	jmp L14007
L14009:
	movl $118,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *1680(%rdi)
	movl $0,%eax
	jmp L14005
L14010:
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1648(%rdi)
	movl %eax,24(%rbp)
	movl 24(%rbp),%eax
	incl %eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	cmpl $1,%eax
	jne L14011
	movl $2,%eax
	addl 24(%rbp),%eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	jmp L14005
L14011:
	movl $119,48(%rbp)
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
	movl $0,%eax
	jmp L14005
L14012:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	jmp L14005
L14013:
	movl $-1,%eax
	jmp L14005
L14014:
	movl $0,%eax
	jmp L14005
L14015:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	negl %eax
	jmp L14005
L14016:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	test %eax,%eax
	jns 1f
	neg %eax
1:
	jmp L14005
L14017:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	notl %eax
	jmp L14005
L14018:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	imull %ecx
	jmp L14005
L14019:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	cqto
	idivl %ecx
	jmp L14005
L14020:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	cqto
	idivl %ecx
	mov %edx,%eax
	jmp L14005
L14021:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	addl %ecx,%eax
	jmp L14005
L14022:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	subl %ecx,%eax
	jmp L14005
L14023:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	shll %cl,%eax
	jmp L14005
L14024:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	shrl %cl,%eax
	jmp L14005
L14025:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	orl %ecx,%eax
	jmp L14005
L14026:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	andl %ecx,%eax
	jmp L14005
L14027:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	xorl $-1,%eax
	xorl %ecx,%eax
	jmp L14005
L14028:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *1880(%rdi)
	movl %eax,24(%rbp)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1880(%rdi)
	mov %eax,%ecx
	movl 24(%rbp),%eax
	xorl %ecx,%eax
	jmp L14005
	jmp L14008
L14007:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L14999,%rdx
	mov $18,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L14009
3:	jmp *8(%rdx)
L14008:
L14005:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	ASSIGN
L14002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	je L14030
	cmpl $0,24(%rbp)
	jne L14029
L14030:
	movl $110,48(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14029:
	jmp L14031
L14033:
	movl 24(%rbp),%eax
	mov (,%rax,8),%eax
	cmpl $38,%eax
	je L14034
	movl $112,48(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14034:
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	movl 24(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1840(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	movl 24(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1840(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14035:
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	movl $80,56(%rbp)
	movl $81,64(%rbp)
	movl $82,72(%rbp)
	movl $0,80(%rbp)
	leal 32(%rbp),%ecx
	call *1896(%rdi)
	decl 2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14036:
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 16(%rbp),%eax
	incl %eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 16(%rbp),%eax
	addl $2,%eax
	mov (,%rax,8),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl $121,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	movl 2240(%rdi),%eax
	subl $3,%eax
	movl %eax,2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14037:
L14038:
L14039:
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1848(%rdi)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *1856(%rdi)
	movl $83,48(%rbp)
	leal 32(%rbp),%ecx
	call *2320(%rdi)
	movl 2240(%rdi),%eax
	subl $2,%eax
	movl %eax,2240(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14040:
	movl $109,48(%rbp)
	movl 2160(%rdi),%eax
	movl %eax,56(%rbp)
	leal 32(%rbp),%ecx
	call *1680(%rdi)
	jmp L14032
L14031:
	movl 16(%rbp),%eax
	mov (,%rax,8),%eax
	mov $L14998,%rdx
	mov $6,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L14040
3:	jmp *8(%rdx)
L14032:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	TRANSNAME
L14003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *1648(%rdi)
	movl %eax,56(%rbp)
	movl 56(%rbp),%eax
	incl %eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,64(%rbp)
	movl $2,%eax
	addl 56(%rbp),%eax
	addl 2080(%rdi),%eax
	mov (,%rax,8),%eax
	movl %eax,72(%rbp)
	cmpl $0,56(%rbp)
	jne L14041
	movl $115,96(%rbp)
	movl 16(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *1680(%rdi)
	movl 32(%rbp),%eax
	movl %eax,96(%rbp)
	movl $2,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14041:
	jmp L14042
L14044:
	movl 56(%rbp),%eax
	cmpl 2104(%rdi),%eax
	jge L14045
	movl $116,96(%rbp)
	movl 16(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *1680(%rdi)
L14045:
	movl 24(%rbp),%eax
	movl %eax,96(%rbp)
	movl 72(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14046:
	movl 32(%rbp),%eax
	movl %eax,96(%rbp)
	movl 72(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14047:
	movl 40(%rbp),%eax
	movl %eax,96(%rbp)
	movl 72(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *2336(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14048:
	cmpl $0,48(%rbp)
	jne L14049
	movl $113,96(%rbp)
	movl 16(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *1680(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
L14049:
	movl 48(%rbp),%eax
	movl %eax,96(%rbp)
	movl 72(%rbp),%eax
	movl %eax,104(%rbp)
	leal 80(%rbp),%ecx
	call *2328(%rdi)
	jmp L14043
L14042:
	movl 64(%rbp),%eax
	mov $L14997,%rdx
	mov $4,%rcx
1:	cmp (%rdx),%eax
	je 3f
	add $8,%rdx
	loop 1b
2:	jmp L14043
3:	jmp *8(%rdx)
L14043:
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L14004:
	ret
	.data
	.align 4
L14999:
	.long 2
	.long L14010
	.long 1
	.long L14012
	.long 4
	.long L14013
	.long 5
	.long L14014
	.long 17
	.long L14015
	.long 19
	.long L14016
	.long 30
	.long L14017
	.long 11
	.long L14018
	.long 12
	.long L14019
	.long 13
	.long L14020
	.long 14
	.long L14021
	.long 15
	.long L14022
	.long 31
	.long L14023
	.long 32
	.long L14024
	.long 34
	.long L14025
	.long 33
	.long L14026
	.long 35
	.long L14027
	.long 36
	.long L14028
	.align 4
L14998:
	.long 38
	.long L14033
	.long 2
	.long L14035
	.long 28
	.long L14036
	.long 8
	.long L14037
	.long 9
	.long L14038
	.long 37
	.long L14039
	.align 4
L14997:
	.long 77
	.long L14044
	.long 76
	.long L14046
	.long 78
	.long L14047
	.long 1
	.long L14048
	.global G235
	.equ G235,L14001
	.global G230
	.equ G230,L14002
	.global G237
	.equ G237,L14003
	.text
//	SECTION: TRN6
	jmp L15018
//	COMPLAB
L15001:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $90,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *2336(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	COMPENTRY
L15002:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $2,%eax
	addl 16(%rbp),%eax
	movl %eax,32(%rbp)
	movl $94,56(%rbp)
	movl 32(%rbp),%eax
	movl %eax,80(%rbp)
	movl $0,88(%rbp)
	leal 64(%rbp),%ecx
	call *680(%rdi)
	movl %eax,64(%rbp)
	movl 24(%rbp),%eax
	movl %eax,72(%rbp)
	leal 40(%rbp),%ecx
	call *2352(%rdi)
	movl $1,40(%rbp)
	movl 32(%rbp),%eax
	movl %eax,64(%rbp)
	movl $0,72(%rbp)
	leal 48(%rbp),%ecx
	call *680(%rdi)
	movl %eax,48(%rbp)
	jmp L15019
L15020:
	movl 32(%rbp),%eax
	movl %eax,88(%rbp)
	movl 40(%rbp),%eax
	movl %eax,96(%rbp)
	leal 72(%rbp),%ecx
	call *680(%rdi)
	movl %eax,72(%rbp)
	leal 56(%rbp),%ecx
	call *2376(%rdi)
	incl 40(%rbp)
L15019:
	movl 40(%rbp),%eax
	cmpl 48(%rbp),%eax
	jle L15020
	movl $32,56(%rbp)
	leal 40(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	COMPDATALAB
L15003:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $100,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *2336(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	COMPJUMP
L15004:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $85,40(%rbp)
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 24(%rbp),%ecx
	call *2336(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUT1
L15005:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2384(%rdi)
	movl $32,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUT2
L15006:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2384(%rdi)
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2024(%rdi)
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUT2P
L15007:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2384(%rdi)
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	movl $76,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	movl 24(%rbp),%eax
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2024(%rdi)
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUT3P
L15008:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *2384(%rdi)
	movl $32,56(%rbp)
	leal 40(%rbp),%ecx
	call *2000(%rdi)
	movl 24(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *2024(%rdi)
	movl $32,56(%rbp)
	leal 40(%rbp),%ecx
	call *2000(%rdi)
	movl $76,56(%rbp)
	leal 40(%rbp),%ecx
	call *2000(%rdi)
	movl 32(%rbp),%eax
	movl %eax,56(%rbp)
	leal 40(%rbp),%ecx
	call *2024(%rdi)
	movl $32,56(%rbp)
	leal 40(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUTN
L15009:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2024(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUTL
L15010:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $32,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	movl $76,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2024(%rdi)
	movl $32,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUTC
L15011:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2024(%rdi)
	movl $32,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	OUTSTRING
L15012:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	movl $0,48(%rbp)
	leal 24(%rbp),%ecx
	call *680(%rdi)
	movl %eax,24(%rbp)
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2024(%rdi)
	movl $32,48(%rbp)
	leal 32(%rbp),%ecx
	call *2000(%rdi)
	movl $1,32(%rbp)
	movl 24(%rbp),%eax
	movl %eax,40(%rbp)
	jmp L15021
L15022:
	movl 16(%rbp),%eax
	movl %eax,80(%rbp)
	movl 32(%rbp),%eax
	movl %eax,88(%rbp)
	leal 64(%rbp),%ecx
	call *680(%rdi)
	movl %eax,64(%rbp)
	leal 48(%rbp),%ecx
	call *2376(%rdi)
	incl 32(%rbp)
L15021:
	movl 32(%rbp),%eax
	cmpl 40(%rbp),%eax
	jle L15022
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRITEOP
L15013:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2032(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRN
L15014:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $0,16(%rbp)
	jge L15023
	movl $45,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	negl 16(%rbp)
	cmpl $0,16(%rbp)
	jge L15024
	movl 16(%rbp),%eax
	shrl $1,%eax
	movl $5,%ecx
	cqto
	idivl %ecx
	movl %eax,24(%rbp)
	movl %eax,48(%rbp)
	leal 32(%rbp),%ecx
	call *2032(%rdi)
	movl 16(%rbp),%eax
	movl %eax,32(%rbp)
	movl $10,%eax
	imull 24(%rbp)
	mov %eax,%ecx
	movl 32(%rbp),%eax
	subl %ecx,%eax
	movl %eax,16(%rbp)
L15024:
L15023:
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2032(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRPN
L15015:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	cmpl $9,16(%rbp)
	jle L15025
	movl 16(%rbp),%eax
	movl $10,%ecx
	cqto
	idivl %ecx
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2032(%rdi)
L15025:
	movl 16(%rbp),%eax
	movl $10,%ecx
	cqto
	idivl %ecx
	mov %edx,%eax
	addl $48,%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *2000(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	ENDOCODE
L15016:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	movl $10,32(%rbp)
	leal 16(%rbp),%ecx
	call *112(%rdi)
	movl $0,2008(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
//	WRC
L15017:
	pop (%rcx)
	mov %rbp,8(%rcx)
	mov %rcx,%rbp
	incl 2008(%rdi)
	cmpl $62,2008(%rdi)
	jle L15026
	cmpl $32,16(%rbp)
	jne L15026
	movl $10,40(%rbp)
	leal 24(%rbp),%ecx
	call *112(%rdi)
	movl $0,2008(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L15026:
	movl 16(%rbp),%eax
	movl %eax,40(%rbp)
	leal 24(%rbp),%ecx
	call *112(%rdi)
	mov %rbp,%rcx
	mov 8(%rcx),%eax
	mov %eax,%ebp
	mov (%rcx),%eax
	jmp *%rax
L15018:
	ret
	.data
	.global G240
	.equ G240,L15001
	.global G242
	.equ G242,L15002
	.global G234
	.equ G234,L15003
	.global G241
	.equ G241,L15004
	.global G290
	.equ G290,L15005
	.global G291
	.equ G291,L15006
	.global G292
	.equ G292,L15007
	.global G294
	.equ G294,L15008
	.global G295
	.equ G295,L15009
	.global G296
	.equ G296,L15010
	.global G297
	.equ G297,L15011
	.global G289
	.equ G289,L15012
	.global G298
	.equ G298,L15013
	.global G253
	.equ G253,L15014
	.global G254
	.equ G254,L15015
	.global G252
	.equ G252,L15016
	.global G250
	.equ G250,L15017
	.text
