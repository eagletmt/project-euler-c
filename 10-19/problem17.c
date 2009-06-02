/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  /* * one two three four five six seven eight nine */
  unsigned s1[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
  /* ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen */
  unsigned s2[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
  /* * * twenty thirty forty fifty sixty seventy eighty ninety */
  unsigned s3[] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };

  unsigned hundred = 7;
  unsigned and = 3;
  unsigned thousand = 8;

  unsigned i;
  unsigned sum = 0;

  /* from 1 to 9 */
  for (i = 1; i < 10; i++) {
    sum += s1[i];
  }
  /* from 10 to 19 */
  for (i = 0; i < 10; i++) {
    sum += s2[i];
  }
  /* from 20 to 99 */
  for (i = 20; i < 100; i++) {
    sum += s3[i/10] + s1[i%10];
  }
  /* from 100 to 999 */
  for (i = 1; i < 10; i++) {
    int j;

    /* just i hundred */
    sum += s1[i] + hundred;
    /* from i hundred and one to i hundred and nine */
    for (j = 1; j < 10; j++) {
      sum += s1[i] + hundred + and + s1[j];
    }
    /* from i hundred and ten to i hundred and nineteen */
    for (j = 0; j < 10; j++) {
      sum += s1[i] + hundred + and + s2[j];
    }
    /* from i hundred and twenty to i hundred and ninety-nine */
    for (j = 20; j < 100; j++) {
      sum += s1[i] + hundred + and + s3[j/10] + s1[j%10];
    }
  }
  /* just 1000 */
  sum += s1[1] + thousand;

  printf("%u\n", sum);

  return 0;
}

