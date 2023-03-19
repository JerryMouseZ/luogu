#include <bits/stdc++.h>
using namespace std;
char a[2001];
char b[2001];
int res[4002];
int main()
{
  ios::sync_with_stdio(false);
  cin >> a;
  cin >> b;
  int l1 = strlen(a), l2 = strlen(b);
  for (int i = l2 - 1; i >= 0; --i) {
    for (int j = l1 - 1; j >= 0; --j) {
      int temp = res[i + j + 1] + (a[j] - '0') * (b[i] - '0');
      res[i + j + 1] = temp % 10;
      res[i + j] += temp / 10;
    }
  }
  int i = 0;
  for (; i < l1 + l2 - 1; ++i) {
    if (res[i] != 0)
      break;
  }
  for (; i < l1 + l2; ++i) {
    cout << res[i];
  }
  cout << endl;
  return 0;
}

