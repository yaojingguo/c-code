// Reed-Solomon Coding
#include <stdio.h>

#define W 4
#define NW (1 << W)

unsigned short gflog[NW];
unsigned short gfilog[NW];

unsigned int prim_poly = 023;

void setup_tables()
{
  unsigned int b, log, x_to_w, prim_ploy;

  x_to_w = 1 << W;
  b = 1;
  for (log = 0; log < x_to_w-1; log++) {
    gflog[b] = (unsigned short) log;
    gfilog[log] = (unsigned short) b;
    b = b << 1;
    if (b & x_to_w) b = b ^ prim_poly;
  }
}

int mult(int a, int b)
{
  int sum_log;

  if (a == 0 || b == 0) return 0;
  sum_log = gflog[a] + gflog[b];
  if (sum_log > NW-1) sum_log -= NW-1;
  return gfilog[sum_log];
}

int div(int a, int b)
{
  int diff_log;

  if (a == 0) return 0;
  if (b == 0) return -1;
  diff_log = gflog[a] - gflog[b];
  if (diff_log < 0) diff_log += NW-1;
  return gfilog[diff_log];
}

void test_setup_tables() {
  int i;
  setup_tables();

  printf("%10s", "i");
  for (i = 0; i < NW; i++) 
    printf("%3d", i);
  printf("\n");

  printf("%10s", "gflog[i]");
  for (i = 0; i < NW; i++) 
    if (i == 0)
      printf("%3s", "-");
    else 
      printf("%3d", gflog[i]);
  printf("\n");

  printf("%10s", "gfilog[i]");
  for (i = 0; i < NW; i++) 
    if (i == NW-1)
      printf("%3s", "-");
    else
      printf("%3d", gfilog[i]);
  printf("\n");
}

int main(int argc, const char *argv[]) 
{
  test_setup_tables();
  return 0;
}

