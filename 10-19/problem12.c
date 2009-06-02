/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

static unsigned divisor_count(unsigned long n);

int main(void)
{
  unsigned long i = 1, n = 1;

  while (divisor_count(n) < 500) {
    n += ++i;
  }
  printf("%lu\n", n);
  return 0;
}

unsigned divisor_count(unsigned long n)
{
  unsigned ret = 1;
  unsigned long i;

  for (i = 2; i <= n; i++) {
    unsigned c = 0;
    while (n % i == 0) {
      c++;
      n /= i;
    }
    ret *= c+1;
  }
  return ret;
}

