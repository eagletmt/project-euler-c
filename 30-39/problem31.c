/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

int main(void)
{
  int z = 0;
  int n = 200;
  
  int a, b, c, d, e, f, g;
  for (a = 0; a <= n; a += 200)
    for (b = 0; b <= n; b += 100)
      for (c = 0; c <= n; c += 50)
        for (d = 0; d <= n; d += 20)
          for (e = 0; e <= n; e += 10)
            for (f = 0; f <= n; f += 5)
              for (g = 0; g <= n; g += 2)
                if (a+b+c+d+e+f+g <= 200)
                  z++;
  printf("%d\n", z);

  return 0;
}

