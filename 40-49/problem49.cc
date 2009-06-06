/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
struct func {
  T operator()(T a, T b) const
  {
    return 10*a + b;
  }
};

static bool is_prime(int n);

int main()
{
  using namespace std;

  bool seen[10000];
  fill(seen, seen+10000, false);

  for (int i = 1000; i < 10000; i++) {
    /* int->vector e.g. 1234 -> [1,2,3,4] */
    vector<int> a(4);
    for (int j = 0, t = i; j < 4; j++, t /= 10) {
      a[3-j] = t % 10;
    }

    vector<int> s;
    do {
      /* vector->int */
      int n = accumulate(a.begin(), a.end(), 0, func<int>());

      if (!seen[n] && is_prime(n)) {
        s.push_back(n);
        seen[n] = true;
      }
    } while (next_permutation(a.begin(), a.end()));

    for (int j = 0; j < s.size(); j++) {
      for (int k = j+1; k < s.size(); k++) {
        for (int l = k+1; l < s.size(); l++) {
          if (s[j] != 1487 && s[l] - s[k] == s[k] - s[j]) {
            cout << s[j] << s[k] << s[l] << endl;
          }
        }
      }
    }
  }

  return 0;
}

bool is_prime(int n)
{
  if (n < 2) {
    return false;
  }
  else if (n % 2 == 0) {
    return n == 2;
  }
  else {
    for (int d = 3; d*d <= n; d += 2) {
      if (n % d == 0) {
        return false;
      }
    }
    return true;
  }
}

