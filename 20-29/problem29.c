/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define N 100

static int compare(const void *a, const void *b);

int main(void)
{
  int a, b;
  int i = 0;
  int count = 0;
  mpz_t *nums;
  mpz_t t;

  mpz_init(t);

  nums = malloc((N-1)*(N-1) * sizeof *nums);
  for (a = 2; a <= N; a++) {
    mpz_set_ui(t, a);
    for (b = 2; b <= N; b++) {
      mpz_mul_ui(t, t, a);
      mpz_init(nums[i]);
      mpz_set(nums[i], t);
      i++;
    }
  }

  qsort(nums, (N-1)*(N-1), sizeof *nums, compare);

  mpz_set_ui(t, 0);
  for (i = 0; i < (N-1)*(N-1); i++) {
    if (mpz_cmp(t, nums[i]) != 0) {
      count++;
    }
    mpz_set(t, nums[i]);
    mpz_clear(nums[i]);
  }
  printf("%d\n", count);

  free(nums);
  mpz_clear(t);

  return 0;
}

int compare(const void *a, const void *b)
{
  return mpz_cmp(*(const mpz_t *)a, *(mpz_t const *)b);
}

