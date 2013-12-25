// http://graphics.stanford.edu/~seander/bithacks.html
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool parity(unsigned int v)
{
  v ^= v >> 16;
  v ^= v >> 8;
  v ^= v >> 4;
  v &= 0xf;
  return (0x6996 >> v) & 1;
}

void test_parity()
{
  assert(!parity(0));
  assert(parity(1));
  assert(parity(2));
  assert(!parity(0xF));
}

int main(int argc, const char *argv[]) 
{
  test_parity();
  return 0;
}
