/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

static unsigned collatz_count(unsigned n);

int main(void)
{
  unsigned i, max_c = 0, max_i = 0;

  for (i = 1; i < 1000000; i++) {
    unsigned c = collatz_count(i);
    if (c > max_c) {
      max_c = c;
      max_i = i;
    }
  }
  printf("%u\n", max_i);
  return 0;
}

unsigned collatz_count(unsigned n)
{
  unsigned c = 0;
  while (n > 1) {
    n = n%2==0 ? n/2 : 3*n+1;
    c++;
  }
  return c+1;
}

