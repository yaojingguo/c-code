	.file	"tail_call.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"callee: a = %d, b = %d\n"
	.text
	.p2align 4,,15
	.globl	callee
	.type	callee, @function
callee:
.LFB14:
	.cfi_startproc
	movl	%edi, %edx
	movl	%esi, %ecx
	movl	$1, %edi
	movl	$.LC0, %esi
	xorl	%eax, %eax
	jmp	__printf_chk
	.cfi_endproc
.LFE14:
	.size	callee, .-callee
	.p2align 4,,15
	.globl	call
	.type	call, @function
call:
.LFB15:
	.cfi_startproc
	movl	$15, %edi
	jmp	callee
	.cfi_endproc
.LFE15:
	.size	call, .-call
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
