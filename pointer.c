#include <stdio.h>

void test1()
{
  // p's value is 10;
  // * is part of declartion.
  int *p = 10;
}

void test2()
{
  int val;

  int *p;
  p = &val;
  *p = 10;
  printf("value: %d\n", *p);

  int *q = &val;
  printf("value: %d\n", *q);
}

void test3()
{
  // Segement fault:
  // p points to some invalid memory location. Storing a value to that location 
  // causes a segment fault.
  int *p;
  // * is dereference operator.
  *p = 10;
}

int main(int argc, const char *argv[]) 
{
  test1();
  test2();
  test3();
  return 0;
}

