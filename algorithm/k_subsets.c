/* 
 * This program accepts n and k on the command line, then prints
 * all n C k combinations of integers from 1..n
 */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int n, k, i, j, c;

  if (argc != 3) {
    printf ("Usage: %s n k\n", argv[0]);
    exit (1);
  }
  n = atoi (argv[1]);
  k = atoi (argv[2]);

  /* i goes through all n-bit numbers */

  for (i=0; i < (1<<n); i++) {
    /* 
     * Masking the j'th bit as j goes through all the bits,
     * count the number of 1 bits.  this is called finding
     * a population count.
     */
    for (j = 0, c = 0; j < 32; j++) 
      if (i & (1<<j)) 
        c++;

    /* if that number is equal to k, print the combination... */
    if (c == k) {
      /* by again going through all the bits indices, printing only the ones 
       * with 1-bits
       */
      for (j=0;j<32; j++) if (i & (1<<j)) printf ("%i ", j+1);
      printf ("\n");
    }
  }
  exit (0);
}
