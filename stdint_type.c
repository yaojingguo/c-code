#include <stdio.h>
#include <stdint.h>

int main(int argc, const char *argv[]) 
{
  uint64_t dividend, quotient, remainder;

  dividend = 0xF0FFFFFFFFFFFFFF; 
  quotient = dividend / 64;
  remainder = dividend % 64;
  printf("uint64_t size: %d\n", sizeof(dividend));
  printf("quotient: %016llx, remainder: %llx\n", quotient, remainder);
  return 0;
}
