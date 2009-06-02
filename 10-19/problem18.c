/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>

#define N 15

static int findmax(const char triangle[][N], int row, int col);

int main(void)
{
  const char triangle[N][N] = {
    {75},
    {95,64},
    {17,47,82},
    {18,35,87,10},
    {20, 4,82,47,65},
    {19, 1,23,75, 3,34},
    {88, 2,77,73, 7,63,67},
    {99,65, 4,28, 6,16,70,92},
    {41,41,26,56,83,40,80,70,33},
    {41,48,72,33,47,32,37,16,94,29},
    {53,71,44,65,25,43,91,52,97,51,14},
    {70,11,33,28,77,73,17,78,39,68,17,57},
    {91,71,52,38,17,14,91,43,58,50,27,29,48},
    {63,66, 4,68,89,53,67,30,73,16,69,87,40,31},
    { 4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23},
  };

  printf("%d\n", findmax(triangle, 0, 0));

  return 0;
}

/* recursive version. more elaborated version is found in problem67.c */
int findmax(const char triangle[][N], int row, int col)
{
  int left, right;

  if (row == N) {
    return triangle[row][col];
  }
  left = findmax(triangle, row+1, col);
  right = findmax(triangle, row+1, col+1);

  return triangle[row][col] + (left > right ? left : right);
}

