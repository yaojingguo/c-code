#include <stdio.h>
extern char **environ;

int main(int argc, char **argv) {
  unsigned int a, *x;
  unsigned char *y;

  printf("argv = %08x\n", (unsigned int) argv);
  printf("argv[0] = %08x\n", (unsigned int) argv[0]);
  printf("environ = %08x\n", (unsigned int) environ);
  printf("environ[0] = %08x\n", (unsigned int) environ[0]);
  printf("\n\n");

  x = (unsigned int *) ((unsigned int) &a & ~0xf);
  while ((unsigned int) x < (unsigned int) argv[0]) {
    printf("%08x:", (unsigned int) x);
    for (a=0; a<4; a++)
      printf(" %08x", x[a]);
    printf("\n");
    x += 4;
  }

  printf("\n\n");
  y = (unsigned char *) ((unsigned int) argv[0] & ~0xf) - 16;
  while ((unsigned int) y < 0xc0000000) {
    printf("%08x:", (unsigned int) y);
    for (a=0; a<16; a++)
      printf(" %02x", y[a]);
    printf("   ");
    for (a=0; a<16; a++)
      putchar((y[a] > 32 && y[a] < 127) ? y[a] : '.');
    printf("\n");
    y += 16;
  }
  return 0;
}
