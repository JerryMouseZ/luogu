#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdint>
#include <vector>
using namespace std;
int main()
{
  size_t n, c;
  cin >> n >> c;
  vector<size_t> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  
  unsigned res = 0;
  for (int i = 0; i < n; ++i) {
    res += upper_bound(nums.begin(), nums.end(), nums[i] + c) - lower_bound(nums.begin(), nums.end(), nums[i] + c);
  }
  cout << res << endl;
  return 0;
}

