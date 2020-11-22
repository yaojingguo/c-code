#include <stdio.h>
#include "power_slow.h"

int power2(int x)
{
  fprintf(stderr, "slow power2()\n");
  return x*x;
}

int power3(int x)
{
  return power2(x)*x;
}
