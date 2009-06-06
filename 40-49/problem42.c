/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <math.h>

static int is_triangle(int c);

int main(void)
{
  FILE *fp;
  int cnt = 0;
  char buf[32];

  fp = fopen("words.txt", "r");
  if (!fp) {
    perror("words.txt");
    return 1;
  }

  while (fscanf(fp, "\"%[^\"]\",", buf) != EOF) {
    int i, sum = 0;
    for (i = 0; buf[i] != '\0'; i++) {
      sum += buf[i]-'A'+1;
    }
    cnt += is_triangle(sum);
  }
  fclose(fp);

  printf("%d\n", cnt);

  return 0;
}

int is_triangle(int c)
{
  /*
   * if c is a triangle number, c = 1/2*n*(n+1) thus n = (-1 + sqrt(1+8*c))/2 .
   * so c is a triangle number if 1+8*c is a square number and sqrt(1+8*c) is odd.
   */
  int sq = sqrt(1+8*c);
  return (sq*sq == 1+8*c && (sq & 1) == 1);
}

