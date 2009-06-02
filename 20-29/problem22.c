/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static int compare(const void *x, const void *y);

int main(void)
{
  int count = 0;
  FILE *fp;
  char path[] = "names.txt";
  char **names;
  int i;
  int sum = 0;

  fp = fopen(path, "r");
  if (!fp) {
    perror(path);
    return 1;
  }

  /* parse names.txt */
  names = malloc(8192 * sizeof *names);
  names[count] = malloc(16);
  while (fscanf(fp, "\"%[^\"]\",", names[count]) != EOF) {
    names[++count] = malloc(16);
  }
  free(names[count]);
  fclose(fp);

  qsort(names, count, sizeof *names, compare);

  for (i = 0; i < count; i++) {
    int j, s = 0;
    for (j = 0; names[i][j] != 0; j++) {
      s += names[i][j]-'A'+1;
    }
    sum += s * (i+1);

    free(names[i]);
  }
  free(names);

  printf("%d\n", sum);

  return 0;
}

int compare(const void *x, const void *y)
{
  return strcmp(*(char * const *)x, *(char * const *)y);
}

