#include <stdio.h>

int cube[2][3][4];

int main(int argc, const char *argv[]) 
{
  int *p;
  p = (int*) cube;
  int i, j, k;
  for (i = 0; i < 2 * 3 * 4; i++)
    p[i] = i + 1;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      for (k = 0; k < 4; k++)
        printf("%3d\n", cube[i][j][k]);
  return 0;
}
