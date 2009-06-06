/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

static int is_square(unsigned n);
static char *prime_sieve(unsigned n);

int main(void)
{
  char *sieve = prime_sieve(N);
  unsigned *primes = malloc(sizeof(unsigned) * N);
  unsigned i, j = 0;

  for (i = 0; i < N; i++) {
    if (!sieve[i]) {
      primes[j++] = i;
    }
  }
  primes[j] = 0;

  for (i = 3; i < N; i += 2) {
    if (!sieve[i]) {
      /* skip if i is prime */
      continue;
    }
    for (j = 0; primes[j]; j++) {
      unsigned s;

      if (primes[j] > i) {
        printf("%u\n", i);
        goto FINISH;
      }

      s = (i - primes[j])/2;
      if (is_square(s)) {
        break;
      }
    }
  }
FINISH:
  free(sieve);
  free(primes);

  return 0;
}

char *prime_sieve(unsigned n)
{
  char *sieve = calloc(n, sizeof *sieve);
  unsigned i;
  sieve[0] = sieve[1] = 1;
  for (i = 2; i < n; i++) {
    if (!sieve[i]) {
      unsigned j;
      for (j = i*2; j < n; j += i) {
        sieve[j] = 1;
      }
    }
  }
  return sieve;
}

int is_square(unsigned n)
{
  unsigned sq = sqrt(n);
  return sq*sq == n;
}

