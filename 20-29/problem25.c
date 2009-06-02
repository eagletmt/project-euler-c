/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(void)
{
  mpz_t n;
  int i = 1;

  mpz_init(n);

  for (i = 1;; i++) {
    char *str;
    size_t len;

    mpz_fib_ui(n, i);
    str = mpz_get_str(NULL, 10, n);
    len = strlen(str);
    free(str);
    if (len == 1000) {
      printf("%d\n", i);
      break;
    }
  }

  mpz_clear(n);

  return 0;
}

