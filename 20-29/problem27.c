/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <math.h>

static int is_prime(int n);

int main(void)
{
  int a, b, n;
  int nmax = 0, amax = 0, bmax = 0;

  for (a = -999; a < 1000; a++) {
    for (b = -999; b < 1000; b++) {
      for (n = 0; is_prime(n*n + a*n + b); n++);
      if (n > nmax) {
        nmax = n;
        amax = a;
        bmax = b;
      }
    }
  }
  printf("%d\n", amax * bmax);

  return 0;
}

int is_prime(int n)
{
  int i;

  if (n <= 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }

  for (i = 2; i < sqrt((double)n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

