#include <stdio.h>

#define N 10

#define NA -1

int vec[N] = {
  [0 ... N-1] = NA,
  [6] = 9,
  [0] =  8,
};

int main()
{
  int i;

  for (i = 0; i < N; i++)
    printf("vec[%d] = %d\n", i, vec[i]);
}
