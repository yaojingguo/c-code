#include <stdio.h>
#include <assert.h>

typedef unsigned int uint;

static inline uint
xchg_star(volatile uint *addr, uint newval)
{
  uint result;
  
  // The + in "+m" denotes a read-modify-write operand.
  asm volatile("lock; xchgl %0, %1" :
               "+m" (*addr), "=a" (result) :
               "1" (newval) :
               "cc");
  // "*" means that addr is an address. The usual meaning of "*" is pointer
  // type declaratoin such as "int *p" or the content of a pointer such as
  // "*p".
  return result;
}

static inline uint
xchg(volatile uint *addr, uint newval)
{
  uint result;
  
  // The + in "+m" denotes a read-modify-write operand.
  asm volatile("lock; xchgl %0, %1" :
               "+m" (addr), "=a" (result) :
               "1" (newval) :
               "cc");
  return result;
}

void test(uint (*func)(volatile uint *, uint))
{
  uint val, result;
  uint *addr;

  val = 0;
  addr = &val;

  result = func(addr, 1);
  printf("result: %d\n", result);

  result = func(addr, 1);
  printf("result: %d\n", result);
}

int main(int argc, char *argv[])
{
  int no = 1;
  int *p;

  p = &no;
  printf("pointer content: %d\n", *p);
  test(xchg_star);
  test(xchg);
  return 0;
}

/*
Use gcc -S to produce assembly code.

xchg_star:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rdx
	movl	-28(%rbp), %eax
	movq	-24(%rbp), %rcx
	lock; xchgl (%rdx), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	ret

"lock; xchgl (%rdx), %eax" means to treat addr as an address.

xchg:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	-28(%rbp), %eax
	lock; xchgl -24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	ret

"lock; xchgl -24(%rbp), %eax" means to treat addr as a value.

*/
