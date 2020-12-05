#include <stdio.h>
#include <stdlib.h>

#include "power_slow.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: main number\n");
    exit(1);
  }
  fprintf(stderr, "power3() = %d\n", power3(atoi(argv[1])));
  return 0;
}
