#include <stdio.h>

void int_divide() {
  int a = 1;
  int b = 0;
  int result = a / b;

  // Causes the following exception:
  // [1]    37393 floating point exception  ./a.out
  printf("result: %d\n", result);
}

void float_divide() {
  float a = 1;
  float b = 0;
  float result = a / b;

  // Print: result: inf
  printf("result: %f\n", result);
}

int main(int argc, char *argv[])
{
  float_divide();
  return 0;
}
