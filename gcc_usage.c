#include <stdio.h>

void __f () {
  printf("__f\n");
}
void f () __attribute__((weak, alias ("__f")));

void test0()
{
  f();
}

void test1()
{
  int a;
  __typeof__(a) b;

  a = b = 10;
  printf("a = %d, b = %d\n", a, b);
}

// Use 'gcc -Wall' to compile
void test2()
{
  int __attribute__((unused)) a;
  a = 10;
}

int main()
{
  test0();
  test1();
  test2();

  return 0;
}

