#include <stdio.h>

#define VAL 0x80000000

int main(int argc, const char *argv[]) 
{
  unsigned long long ull;
  int signed_num = VAL;
  unsigned int unsigned_num = VAL;

  ull = signed_num;
  printf("%016llx\n", ull);

  ull = unsigned_num;
  printf("%016llx\n", ull);
  return 0;
}
