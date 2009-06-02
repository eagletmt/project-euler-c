/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <math.h>

#define N 1000000

static int is_prime(unsigned n);

int main(void)
{
  unsigned i, count = 0;

  for (i = 2; i < N; i++) {
    unsigned digits;
    unsigned k;
    unsigned j;

    if (!is_prime(i)) {
      continue;
    }
    digits = log10(i);
    k = i;
    for (j = 0; j < digits; j++) {
      unsigned l = pow(10, digits);
      unsigned t = k % l;
      k /= l;
      k += t*10;
      if (!is_prime(k)) {
        goto NEXT;
      }
    }
    count++;
NEXT:
    ;
  }
  printf("%u\n", count);

  return 0;
}

int is_prime(unsigned n)
{
  if (n <= 1) {
    return 0;
  }
  else if (n == 2) {
    return 1;
  }
  else {
    unsigned i;
    for (i = 2; i*i <= n; i++) {
      if (n % i == 0) {
        return 0;
      }
    }
    return 1;
  }
}

