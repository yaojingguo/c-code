#include<stdio.h>

// http://kernelnewbies.org/KernelJanitors/Todo
int main()
{
  // This form creates two variables in the final assembly output, a static 
  // string, and a char pointer to the static string.
  char *p =  "abc";
  // This form is better because it declares a single variable. 
  char q[] = "def";
  printf("p: %s, q: %s\n", p, q);
}

/*
The result of 'gcc -S string.c'. Some comments are added:

	.file	"string.c"
	.section	.rodata
.LC0:
	.string	"abc"
.LC1:
	.string	"p: %s, q: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
  // Copy string pointer to the stack
	movq	$.LC0, -24(%rbp)
  // Copy string data to the stack
	movl	$6710628, -16(%rbp)
	leaq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L2
	call	__stack_chk_fail
.L2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
*/
