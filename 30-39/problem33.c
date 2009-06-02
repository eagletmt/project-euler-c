/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <math.h>

static unsigned gcd(unsigned a, unsigned b);
static int cancel(unsigned n1, unsigned d1, unsigned *n2, unsigned *d2);

int main(void)
{
  unsigned ans_n = 1, ans_d = 1;
  unsigned i;
  for (i = 11; i < 100; i++) {
    unsigned j;

    if (i % 10 == 0) {
      continue;
    }

    for (j = 11; j < i; j++) {
      unsigned g, n, d;
      unsigned n2, d2;

      if (j % 10 == 0) {
        continue;
      }

      if ((g = gcd(i, j)) == 1) {
        continue;
      }
      /* cancel numerically */
      n = j/g;
      d = i/g;

      /* cancel symbolically */
      if (cancel(j, i, &n2, &d2)) {
        unsigned g2 = gcd(n2, d2);
        n2 /= g2; d2 /= g2;
        if (n == n2 && d == d2) {
          ans_n *= n;
          ans_d *= d;
        }
      }
    }
  }
  printf("%u\n", ans_d / gcd(ans_n, ans_d));
  return 0;
}

unsigned gcd(unsigned a, unsigned b)
{
  unsigned r;
  while ((r = a % b) != 0) {
    a = b; b = r;
  }
  return b;
}

int cancel(unsigned n1, unsigned d1, unsigned *n2, unsigned *d2)
{
  if (n1%10 == d1%10) {
    /* e.g. 24 and 34 */
    *n2 = n1/10;
    *d2 = d1/10;
    return 1;
  }
  else if (n1%10 == d1/10) {
    /* e.g. 24 and 41 */
    *n2 = n1/10;
    *d2 = d1%10;
    return 1;
  }
  else if (n1/10 == d1%10) {
    /* e.g. 24 and 32 */
    *n2 = n1%10;
    *d2 = d1/10;
    return 1;
  }
  else if (n1/10 == d1/10) {
    /* e.g. 24 and 21 */
    *n2 = n1%10;
    *d2 = d1%10;
    return 1;
  }
  else {
    *n2 = n1;
    *d2 = d1;
    return 0;
  }
}

