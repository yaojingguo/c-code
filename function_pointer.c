#include <stdio.h>

int increment(int n) 
{
  return n + 1;
}

int main(int argc, const char *argv[]) 
{
  int (*func_ptr)(int);  
  func_ptr = &increment;
  printf("result: %d\n", func_ptr(2));
  printf("result: %d\n", (*func_ptr)(2));
  return 0;
}
