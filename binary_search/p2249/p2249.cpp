#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  int m, n;
  cin >> n >> m;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  
  int num;
  for (int i = 0; i < m; ++i) {
    cin >> num;
    auto it = lower_bound(nums.begin(), nums.end(), num);
    if (it == nums.end() || *it != num)
      cout << -1;
    else
      cout << it - nums.begin() + 1;
    if (i != m - 1)
      cout << " ";
    else
      cout << endl;
  }

  return 0;
}

