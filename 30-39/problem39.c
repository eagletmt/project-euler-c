/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  unsigned a, b, c, p;
  unsigned cnt, max = 0, maxp = 0;

  for (p = 1; p <= 1000; p++) {
    cnt = 0;
    for (a = 1; a < p/2; a++) {
      for (b = a; b < p/2; b++) {
        c = p - a - b;
        if (a*a + b*b == c*c) {
          cnt++;
        }
      }
    }
    if (cnt > max) {
      max = cnt;
      maxp = p;
    }
  }
  printf("%u\n", maxp);

  return 0;
}

