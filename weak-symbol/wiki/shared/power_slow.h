#ifndef POWER2_SLOW_H
#define POWER2_SLOW_H

// alternative syntax
// #pragma weak power2
int
  __attribute__((weak))
    power2(int x)
      // alternatively after symbol
      // __attribute__((weak))
  ;

int power3(int x);

#endif
