#include <stdio.h>
#include <stdlib.h>

#include "power_slow.h"

int main(int argc, char **argv)
{
  fprintf(stderr, "power3() = %d\n", power3(atoi(argv[1])));
  return 0;
}
