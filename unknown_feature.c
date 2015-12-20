#include <stdio.h>

#define LEN 3

int main(int argc, char *argv[])
{
  int array[3] = <%1, 2, 3%>;
  printf("array:");
  for (int i = 0; i < LEN; i++)
    printf(" %d", array[i]);
  printf("\n");

  int num = 12\
3;
  printf("num: %d\n", num);
  return 0;
}
