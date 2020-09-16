#include <stdio.h>
#include "add.h"

int main(int argc, char *argv[]) {
  int result;

  result = add(10, 1);
  printf("add result: %d\n", result);
  
  return 0;
}
