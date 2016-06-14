#include <stdio.h>
#include <assert.h>

int divide(int a, int b);

int main()
{
  assert(divide(0, 5) == 0);

  assert(divide(10, 5) == 2);
  assert(divide(11, 5) == 2);

  assert(divide(-10, -5) == 2);
  assert(divide(-11, -5) == 2);

  assert(divide(5, -3) == -2);
  assert(divide(-5, 3) == -2);
}

int divide(int a, int b)
{
  if (a == 0 || b == 0) return a / b;
  if (a > 0 && b > 0) return a / b;
  if (a < 0 && b < 0) return a / b;
  int quotient = a / b;
  if (quotient * b > a)
    quotient--;
  return quotient;
}
