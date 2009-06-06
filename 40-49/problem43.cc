/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <iostream>
#include <algorithm>

int main(void)
{
  using namespace std;

  unsigned d[] = {0,1,2,3,4,5,6,7,8,9};
  static const unsigned N = sizeof d/sizeof *d;
  unsigned long long sum = 0;

  do {
    if (   (d[1]*100 + d[2]*10 + d[3]) % 2 == 0
        && (d[2]*100 + d[3]*10 + d[4]) % 3 == 0
        && (d[3]*100 + d[4]*10 + d[5]) % 5 == 0
        && (d[4]*100 + d[5]*10 + d[6]) % 7 == 0
        && (d[5]*100 + d[6]*10 + d[7]) % 11 == 0
        && (d[6]*100 + d[7]*10 + d[8]) % 13 == 0
        && (d[7]*100 + d[8]*10 + d[9]) % 17 == 0) {
      unsigned long long p = 1;
      for (unsigned i = 0; i < N; i++) {
        sum += d[N-i-1]*p;
        p *= 10;
      }
    }
  } while (next_permutation(d, d+N));

  cout << sum << endl;

  return 0;
}
        
