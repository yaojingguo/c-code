#include <stdio.h>

void bit_operations() {
  int n = 0x7FFFFFFF;
  printf("n: %d, 0x%X\n", n, n);
  int n_l1 = n << 1;
  printf("n << 1: %d, 0x%X\n", n_l1, n_l1);
  int n_l1_r1 = n_l1 >> 1;
  printf("n << 1 >> 1: %d, 0x%X\n", n_l1_r1, n_l1_r1);
  int n_restored = n_l1_r1 ^ (1 << 31);
  printf("n_restored: %d, 0x%X\n", n_restored, n_restored);
  printf("\n");
}

void shift() {
  printf("Right shift:\n");
  // Positive integer
  int sixteen = 16;
  printf("%d, 0x%08X\n", sixteen >> 1, sixteen >> 1);
  // Unsigned integer
  unsigned int max_neg_u = 0x80000000u;
  printf("%d, 0x%X\n", max_neg_u >> 1, max_neg_u >> 1);
  // Signed integer
  int max_neg = 0x80000000;
  printf("%u, 0x%X\n", max_neg >> 1, max_neg >> 1);

  printf("\nLeft shift:\n");
  // Left shift
  printf("%d, 0x%08X\n", sixteen << 1, sixteen << 1);
  int four_start = 0x40000000;
  int left_shifted = four_start << 1;
  printf("%d, 0x%08X\n", left_shifted, left_shifted);
}

int main(int argc, char *argv[]) {
  bit_operations(); 
  shift();
  return 0;
}
