#include <stdio.h>
#include <stdlib.h>

// Quicksort is unstable. For example, the original array is 1 5 5_ 4. The 
// array after quicksorting is 1 4 5_ 5.

int rand_(int min, int max) {
  return min + random() % (max-min+1);
}

int swap(int arr[], int i, int j) {
  int t;
  t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}

int partition(int arr[], int p, int r) {
  int j, i;

  for (i = p-1, j = p; j <= r-1; j++) 
    if (arr[j] <= arr[r]) {
      i++;
      swap(arr, i, j);
    }

  swap(arr, ++i, r);
  return i;
}

int random_partition(int arr[], int p, int r) {
  int pivot;
  pivot = rand_(p, r);
  swap(arr, pivot, r);
  partition(arr, p, r);
}

void random_qsort(int arr[], int p, int r) {
  if (p >= r) 
    return;

  int q;
  q = random_partition(arr, p, r);
  random_qsort(arr, p, q-1);
  random_qsort(arr, q+1, r);
}

int random_select(int arr[], int p, int r, int i) {
  if (arr[p] == arr[r])
    return arr[p];
  int q, k;
  q = random_partition(arr, p, r);
  k = q - p;

  if (k == i)
    return arr[q];
  else if (k > i) 
    return random_select(arr, p, q-1, i);
  else 
    return random_select(arr, q+1, r, i-k-1);
}

void test_random_select() {
  int arr1[] = {12, 3, 3, 8, 1, 90};
  printf("arr[%d]: %d\n", 0, random_select(arr1, 0, 5, 0));
  int arr2[] = {12, 3, 3, 8, 1, 90};
  printf("arr[%d]: %d\n", 1, random_select(arr2, 0, 5, 1));
  int arr3[] = {12, 3, 3, 8, 1, 90};
  printf("arr[%d]: %d\n", 2, random_select(arr3, 0, 5, 2));
  int arr4[] = {12, 3, 3, 8, 1, 90};
  printf("arr[%d]: %d\n", 4, random_select(arr4, 0, 5, 4));
  int arr5[] = {12, 3, 3, 8, 1, 90};
  printf("arr[%d]: %d\n", 5, random_select(arr5, 0, 5, 5));
}

void test_random_partition(int arr[], int len) {
  random_qsort(arr, 0, len-1);

  int i;
  for (i = 0; i < len; i++) 
    printf("%d ", arr[i]);
  printf("\n");
}

void test_qsort() {
  int arr1[] = {12, 3, 3, 8, 1, 90};
  test_random_partition(arr1, 6);

  int arr2[] = {10, 2};
  test_random_partition(arr2, 2);
}

int main(int argc, const char *argv[]) {
  test_random_select();
  return 0;
}

