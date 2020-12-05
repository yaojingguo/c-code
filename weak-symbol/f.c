#include <stdio.h>

void __attribute__((weak)) info();

int main() {
  printf("function: %p\n", info);
}
