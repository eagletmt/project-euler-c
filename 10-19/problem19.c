/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

static int days(int y, int m);

int main(void)
{
  int year, wday = 0, sun = 0, mon;

  for (year = 1901; year <= 2000; year++) {
    for (mon = 1; mon <= 12; mon++) {
      if (wday == 5) {
        /* 1901-01-01 is Tuesday, so wday == 5 means Sunday */
        sun++;
      }
      wday = (wday + days(year, mon))%7;
    }
  }
  printf("%d\n", sun);

  return 0;
}

int days(int y, int m)
{
  switch (m) {
    case 2:
      if ((y%4 == 0 && y%100 != 0) || y%400 == 0) {
        /* leap year */
        return 29;
      }
      else {
        return 28;
      }
      
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;

    default:
      return 31;
  }
}

