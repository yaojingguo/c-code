#include <stdio.h>

long int simple_1(long int *xp, long int y)
{
  long int t = *xp + y;
  *xp = t;
  return t;
}

int main(int argc, char *argv[])
{
  long int i = 0;
  long int j = 0;
  if (1) i = 10;
  if (1) j = 20;
  printf("result: %ld\n", simple_1(&i, j));
  return 0;
}
