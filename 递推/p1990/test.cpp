#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int res = 1;
  while (n >= 3) {
    res *= 5;
    n -= 3;
    res %= 10000;
  }
  cout << (res * n) % 10000 << endl;
  return 0;
}

