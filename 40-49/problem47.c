/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

#define N 4
#define M 1000000

/* this program may take sevaral seconds */
int main(void)
{
  unsigned i;
  for (i = 2; i < M; i++) {
    unsigned factors[N][N];
    unsigned j;

    for (j = 0; j < N; j++) {
      unsigned c, k, l;

      for (c = 0; c < N; c++) {
        factors[j][c] = 1;
      }

      /* factorize */
      k = i+j;
      l = 2;
      c = 0;
      while (k != 1 && c < N) {
        while (k % l == 0) {
          k /= l;
          factors[j][c] *= l;
        }
        l++;
        if (factors[j][c] != 1) {
          c++;
        }
      }
      if (c != N) {
        /* too few factors */
        goto NEXT;
      }
      if (k != 1) {
        /* too many factors */
        goto NEXT;
      }
    }

    /* this i is the answer! */
    printf("%u\n", i);
    break;
NEXT:
    ;
  }

  return 0;
}

