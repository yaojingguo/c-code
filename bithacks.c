// http://graphics.stanford.edu/~seander/bithacks.html
#include <stdio.h>
#include <stdbool.h>

bool parity(unsigned int v)
{
  v ^= v >> 16;
  v ^= v >> 8;
  v ^= v >> 4;
  v &= 0xF;
}


int main(int argc, const char *argv[]) 
{
  return 0;
}
