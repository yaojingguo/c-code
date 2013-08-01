#include <stdio.h>
#include <assert.h>

int max_subarray_sum(int a[], int n) 
{
  int sum = 0;
  int endHere = 0;
  int i;

  for (i = 0; i < n; i++) {
    endHere += a[i];
    if (endHere < 0)
      endHere = 0;
    if (endHere > sum)
      sum = endHere;
  }
  
  return sum;
}

void test() {
  int a1[] = {1, 2};
  assert(max_subarray_sum(a1, 2) == 3);

  int a2[] = {-1, -2};
  assert(max_subarray_sum(a2, 2) == 0);

  int a3[] = {1, -1, 2, 3, -2, 6, 7, 8, -9, 10};
  assert(max_subarray_sum(a3, 10) == 25);
}

int main(int argc, const char *argv[]) 
{
  test();  
  return 0;
}
