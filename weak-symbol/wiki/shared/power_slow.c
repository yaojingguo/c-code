#include <stdio.h>
#include "power_slow.h"

// void __attribute__((weak)) user_hook(void);
void user_hook(void);
#ifdef ENABLE_DEF
void user_hook(void) {
  fprintf(stderr, "power_slow: user_hook()\n");
}
#endif

int power2(int x) {
  if (user_hook) // only needed ifndef ENABLE_DEF
    user_hook();
  return x*x;
}

int power3(int x) {
  return power2(x)*x;
}
