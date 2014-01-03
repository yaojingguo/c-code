#include <stdio.h>
#include <assert.h>

void test1()
{
  int i, j;
  j = i;
  if (scanf("%d", &i) != EOF)
    printf("%d\n", i);
  else
    assert(i == j);
}

void test2()
{
  int i, j;
  int cnt = scanf("%d%d", &i, &j);
  printf("i: %d, j: %d, cnt: %d\n", i, j, cnt);
}

int main(int argc, const char *argv[]) 
{
  test2();
  return 0;
}
