#include <stdio.h>

// http://wangcong.org/blog/archives/649

int callee(int a, int b)
{
  printf("callee: a = %d, b = %d\n", a, b);
}

static int c = 0xF;

int call(int a, int b)
{
  int ret = callee(c, b);
  return ret;
}
