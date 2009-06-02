/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void)
{
  mpz_t n;
  char *str;
  size_t len, i;
  unsigned sum = 0;

  mpz_init(n);
  mpz_ui_pow_ui(n, 2, 1000);

  str = mpz_get_str(NULL, 10, n);
  len = mpz_sizeinbase(n, 10);
  for (i = 0; i < len; i++) {
    sum += str[i]-'0';
  }
  printf("%u\n", sum);

  free(str);
  mpz_clear(n);

  return 0;
}

