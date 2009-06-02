/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  int s3 = 0, s5 = 0, s15 = 0;
  int i;

  for (i = 0; i < 1000; i++) {
    if (i % 3 == 0) {
      s3 += i;
    }
    if (i % 5 == 0) {
      s5 += i;
    }
    if (i % 15 == 0) {
      s15 += i;
    }
  }
  printf("%d\n", s3 + s5 - s15);

  return 0;
}
  
