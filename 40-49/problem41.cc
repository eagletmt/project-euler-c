/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <iostream>
#include <numeric>
#include <algorithm>

template <typename T>
struct func {
  T operator()(T a, T b) const
  {
    return 10*a + b;
  }
};

static bool is_prime(unsigned n);
  
int main()
{
  using namespace std;

  int a[] = {9,8,7,6,5,4,3,2,1};
  static const size_t N = 9;

  for (unsigned i = 0; i < N; i++) {
    do {
      int n = accumulate(a+i, a+N, 0, func<int>());
      if (is_prime(n)) {
        cout << n << endl;
        goto FINISH;
      }
    } while (prev_permutation(a+i, a+N));
  }

FINISH:
  return 0;
}

bool is_prime(unsigned n)
{
  if (n == 1) {
    return false;
  }
  else if (n % 2 == 0) {
    return n == 2;
  }
  else {
    for (unsigned d = 3; d*d < n; d += 2) {
      if (n % d == 0) {
        return false;
      }
    }
    return true;
  }
}

