/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <math.h>

int is_triangle(unsigned long long n);
int is_pentagonal(unsigned long long n);
unsigned long long hexagonal(unsigned long long n);

int main(void)
{
  unsigned long long h, i;
  for (i = 144; !(is_pentagonal(h = hexagonal(i)) && is_triangle(h)); i++)
    ;
  printf("%llu\n", h);
  return 0;
}

int is_triangle(unsigned long long n)
{
  unsigned long long sq = sqrt(1+8*n);
  return sq*sq == 1+8*n && (sq-1) % 2 == 0;
}

int is_pentagonal(unsigned long long n)
{
  unsigned long long sq = sqrt(1+24*n);
  return sq*sq == 1+24*n && (1+sq) % 6 == 0;
}

unsigned long long hexagonal(unsigned long long n)
{
  return n*(2*n-1);
}

