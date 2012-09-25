#include <stdio.h>

void min_max(int array[], int len, int result[]) {
  int min, max, small, large, p, q;
  if (len % 2) {
    min = max = array[0];
    p = 1;
  } else {
    if (array[0] < array[1]) {
      min = array[0]; max = array[1];
    } else {
      min = array[1]; max = array[0];
    }
    p = 2;
  }

  for (; p < len; p += 2) {
    q = p + 1;
    if (array[p] < array[q]) {
      small = array[p]; large = array[q];
    } else {
      small = array[q]; large = array[p];
    }
    if (min > small) min = small;
    if (max < large) max = large;
  }
  result[0] = min;
  result[1] = max;
}

void test(int array[], int len) {
  int result[2];
  min_max(array, len, result);
  printf("min: %d, max: %d\n", result[0], result[1]);
}

int main(int argc, const char *argv[]) {
  int array1[4] = {22, 1, 10, 8};
  test(array1, 4);

  int array2[9] = {20, 3, 1, 40, 5, 60, 7, 80, 9};
  test(array2, 9);
  
  return 0;
}
