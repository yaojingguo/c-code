#include <stdio.h>
#include <assert.h>

int bsf(int n)
{
  assert(n > 0);
  int idx;
  asm("bsf %1, %0": "=r" (idx) : "r" (n));
  return idx;
}

int bsr(int n)
{
  assert(n > 0);
  int idx;
  asm("bsr %1, %0": "=r" (idx) : "r" (n));
  return idx;
}

void test_bsf() 
{
  assert(bsf(1) == 0);
  assert(bsf(2) == 1);
  assert(bsf(6) == 1);
  assert(bsf(8) == 3);
}

int test_bsr()
{
  assert(bsr(0x1) == 0);
  assert(bsr(0x3) == 1);
  assert(bsr(0x8) == 3);
  assert(bsr(0x28) == 5);
}

int main(int argc, const char *argv[]) 
{
  test_bsf();
  test_bsr();
  return 0;
}
