/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  int a, b;

  for (a = 1; a <= 333; a++) {
    for (b = a; b <= 666; b++) {
      int c = (1000 - a - b);
      if (a*a + b*b == c*c) {
        printf("%d\n", a * b * c);
      }
    }
  }
  return 0;
}
  
