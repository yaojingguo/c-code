// Code to show pass-by-reference in C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int* p)
{
  int* q = (int*) malloc(sizeof(int));
  memcpy(q, p, sizeof(int));
  printf("val: %d in func\n", *q);
  *q = 10;
  printf("val: %d in func\n", *q);
  free(q);
}

int main(int argc, const char *argv[]) 
{
  int i = 1;
  printf("val: %d in main\n", i);
  func(&i);  
  printf("val: %d in main\n", i);
  return 0;
}
