#include <stdio.h>
#include "add.h"

/*
int one = 0xFF; 
int two = 0xFFFFFFFF;
*/

int main(int argc, char *argv[]) {
  int result;

  result = add(10, 1);
  printf("add result: %d\n", result);
  
  return 0;
}
