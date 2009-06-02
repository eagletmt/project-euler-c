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
  int i;
  int sum = 0;

  mpz_init(n);
  mpz_fac_ui(n, 100);
  str = mpz_get_str(NULL, 10, n);
  for (i = 0; str[i]; i++) {
    sum += str[i]-'0';
  }
  printf("%d\n", sum);

  free(str);
  mpz_clear(n);

  return 0;
}

