#include <stdio.h>
#include "arith.h"

int main(int argc, char *argv[]) {
  int result;

  result = sum(10, 1);
  printf("sum result: %d\n", result);

  result = subtract(10, 1);
  printf("subtraction result: %d\n", result);

  return 0;
}
