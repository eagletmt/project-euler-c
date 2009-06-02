/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  unsigned s1 = 0, s2 = 0, i;

  for (i = 1; i <= 100; i++) {
    s1 += i*i;
    s2 += i;
  }
  printf("%u\n", s2*s2 - s1);
  return 0;
}

