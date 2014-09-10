#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

void test1()
{
  if (1, 0) 
    printf("wrong\n");
  if (0, 1)
    printf("right\n");
}

void test2()
{
  printf("number is %d\n", (1, 2, 3));
  int result;
  result = ({1+1; 2+2;});
  printf("result: %d\n", result);
}

int main(int argc, const char *argv[]) 
{
  test1();
  test2();
  return 0;
}
