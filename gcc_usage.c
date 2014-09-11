#include <stdio.h>

void __f () {
  printf("__f\n");
}
void f () __attribute__((weak, alias ("__f")));

int main()
{
  f();
}

