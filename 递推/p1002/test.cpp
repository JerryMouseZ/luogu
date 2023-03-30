#include <cstdarg>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unsigned long long dp[21][21];
int main()
{
  int n, m;
  int c1, c2;
  cin >> n >> m >> c1 >> c2;
  unordered_map<int, unordered_set<int>> invalid_location;
  invalid_location[c1].insert(c2);
  invalid_location[c1 - 1].insert(c2 - 2);
  invalid_location[c1 - 1].insert(c2 + 2);
  invalid_location[c1 + 1].insert(c2 - 2);
  invalid_location[c1 + 1].insert(c2 + 2);
  invalid_location[c1 - 2].insert(c2 - 1);
  invalid_location[c1 - 2].insert(c2 + 1);
  invalid_location[c1 + 2].insert(c2 - 1);
  invalid_location[c1 + 2].insert(c2 + 1);
  if (invalid_location[0].count(0)) {
    cout << 0 << endl;
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (!invalid_location[i].count(0))
      dp[i][0] = dp[i - 1][0];
  }
  for (int i = 1; i <= m; ++i) {
    if (!invalid_location[0].count(i))
      dp[0][i] = dp[0][i - 1];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!invalid_location[i].count(j)) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}

