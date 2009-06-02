/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

static int divisors_sum(int n);

int main(void)
{
  int i, d, sum = 0;

  for (i = 2; i < 10000; i++) {
    d = divisors_sum(i);
    if (i < d && i == divisors_sum(d)) {
      sum += i + d;
    }
  }
  printf("%d\n", sum);

  return 0;
}

int divisors_sum(int n)
{
  int sum= 1;
  int i, k = n;

  for (i = 2; i <= k; i++) {
    int p = 1;
    while (k % i == 0) {
      p *= i;
      k /= i;
    }
    sum *= (p*i - 1)/(i-1);
  }
  return sum - n;
}

