#include <stdio.h>

/*
 * 0(n) stable sorting algorithm
 */
void counting_sort(int c[], int c_len, int src[], int data_len, int dest[]) {
  int i, v;

  for (i = 0; i < c_len; i++)
    c[i] = 0;

  for (i = 0; i < data_len; i++)
    c[src[i]]++;

  c[0]--;
  for (i = 1; i < c_len; i++)
    c[i] += c[i-1];

  for (i = data_len-1; i >= 0; i--) {
    v = src[i];
    dest[c[v]] = v;
    c[v]--;
  }
}

int main(int argc, const char *argv[]) {
  int i;
  int c[10];
  int src1[] = {1, 2, 3, 7, 4, 3, 5};
  int dest1[7];

  counting_sort(c, 10, src1, 7, dest1);
  for (i = 0; i < 7; i++)
    printf("%d ", dest1[i]);
  printf("\n");

  return 0;
}
