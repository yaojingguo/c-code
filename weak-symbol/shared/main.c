#include <stdio.h>
#include <stdlib.h>

#include "power_slow.h"

#ifndef NO_USER_HOOK
void user_hook(void)
{
  fprintf(stderr, "main: user_hook()\n");
}
#endif


int main(int argc, char **argv)
{
  fprintf(stderr, "power3() = %d\n", power3(atoi(argv[1])));
  return 0;
}
