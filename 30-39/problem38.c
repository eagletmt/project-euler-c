/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000

static int is_pandigital(const char *s);
static int compare(const void *a, const void *b);

int main(void)
{
  unsigned max = 0;
  unsigned i;

  for (i = 1; i < N; i++) {
    char s[10] = {0};
    unsigned j;

    snprintf(s, sizeof s, "%u", i);
    for (j = 2; ; j++) {
      char t[10] = {0};

      snprintf(t, sizeof t, "%u", i*j);
      if (strlen(s) + strlen(t) > 9) {
        break;
      }
      strncat(s, t, sizeof s - strlen(s));
    }
    if (is_pandigital(s)) {
      unsigned l = strtoul(s, NULL, 10);
      if (l > max) {
        max = l;
      }
    }
  }
  printf("%u\n", max);

  return 0;
}

int compare(const void *a, const void *b)
{
  return *(const char *)a - *(const char *)b;
}

int is_pandigital(const char *s)
{
  size_t l;
  char t[10];
  size_t i;

  l = strlen(s);
  if (l != 9) {
    return 0;
  }
  strncpy(t, s, sizeof t);
  qsort(t, l, sizeof *t, compare);
  for (i = 0; i < l; i++) {
    if (t[i] != i+'1') {
      return 0;
    }
  }
  return 1;
}

