/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static int compare(const void *a, const void *b);
static int is_pandigital(char *buf);
#define DIGITS(x) (lround(floor(log10((double)x))))

int main(void)
{
  int product, multiplier, multiplicand, remaindar;
  int sum = 0;
  char buf[10];

  for (product = 1111; product < 100000; product++) {
    for (multiplicand = 2; multiplicand*multiplicand < product; multiplicand++) {
      remaindar = product % multiplicand;
      if (remaindar != 0) {
        continue;
      }
      multiplier = product / multiplicand;
      if (DIGITS(multiplicand) + DIGITS(multiplier) + DIGITS(product) != 6) {
        continue;
      }

      snprintf(buf, sizeof buf, "%d%d%d", multiplicand, multiplier, product);
      if (is_pandigital(buf)) {
        sum += product;
        break;
      }
    }
  }
  printf("%d\n", sum);

  return 0;
}

static int compare(const void *a, const void *b)
{
  return *(const char *)a - *(const char *)b;
}

static int is_pandigital(char *buf)
{
  qsort(buf, 9, 1, compare);
  return memcmp(buf, "123456789", 9) == 0;
}

