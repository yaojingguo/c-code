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
  test(xchg_star);
  test(xchg);
  return 0;
}
