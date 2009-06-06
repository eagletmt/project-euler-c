/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

#define N 1000
#define Q 10000000000ULL

int main(void)
{
  unsigned long long rem = 0;
  unsigned i;
  for (i = 1; i < N; i++) {
    unsigned long long r = 1;
    unsigned j;
    for (j = 0; j < i; j++) {
      r = (r * i) % Q;
    }
    rem = (rem + r) % Q;
  }
  printf("%llu\n", rem);

  return 0;
}

