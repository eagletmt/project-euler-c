/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>

static int is_abundant(int n);

int main(void)
{
  int i, j;
  const int upper_limit = 28123;
  int *abundants, abundants_count = 0;
  char *expressed;
  int sum = 0;

  for (i = 1; i < upper_limit; i++) {
    if (is_abundant(i)) {
      abundants_count++;
    }
  }

  abundants = malloc(abundants_count * sizeof *abundants);
  j = 0;
  for (i = 1; i < upper_limit; i++) {
    if (is_abundant(i)) {
      abundants[j++] = i;
    }
  }

  expressed = calloc(upper_limit, sizeof *expressed);
  for (i = 0; i < abundants_count; i++) {
    for (j = i; j < abundants_count; j++) {
      int k = abundants[i] + abundants[j];
      if (k >= upper_limit) {
        break;
      }
      expressed[k-1] = 1;
    }
  }

  for (i = 1; i < upper_limit; i++) {
    if (!expressed[i-1]) {
      sum += i;
    }
  }
  printf("%d\n", sum);

  free(abundants);
  free(expressed);

  return 0;
}

int is_abundant(int n)
{
  int sum = 1;
  int i, k = n;
  for (i = 2; i <= k; i++) {
    int p = 1;
    while (k % i == 0) {
      p *= i;
      k /= i;
    } 
    sum *= (p*i - 1)/(i-1);
  }
  return 2*n < sum;
}

