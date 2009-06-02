/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

#define N 1001

int main(void)
{
  int sum = 1, i;
  for (i = 3; i <= N; i += 2) {
    sum += 2*(2*i*i - 3*i + 3);
  }
  printf("%d\n", sum);
  return 0;
}

