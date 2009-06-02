/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  unsigned int a1 = 1, a2 = 1, a3 = 2, sum = 0;

  while (a3 < 4000000) {
    a3 = a1 + a2;
    sum += a3 * !(a3%2);
    a1 = a2;
    a2 = a3;
  }

  printf("%u\n", sum);

  return 0;
}

