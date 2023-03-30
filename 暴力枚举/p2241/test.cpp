#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  unsigned long long a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    a *= 2;
    b *= 2;
    if (i == 0)
      a += 1;
  }
  for (int j = 1; j < m; ++j) {
    a *= 2;
    b *= 2;
    unsigned long long tmpa = 0, tmpb = 0;
    for (int i = 0; i < n; ++i) {
      tmpa *= 2;
      tmpb *= 2;
      if (i == j)
        tmpa += 1;
      else
        tmpb += 1;
    }
    a += tmpa;
    b += tmpb;
  }

  cout << a << " " << b << endl;
  return 0;
}

