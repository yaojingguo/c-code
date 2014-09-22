#include <stdio.h>
#include <alloca.h>

int main()
{
  char *p;
  
  p = alloca(sizeof(int));
  *p = 123;
  printf("no: %d\n", *p);

  return 0;
}
