#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  int low = 0, high = 0;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    high = max(high, nums[i]);
  }
  
  sort(nums.begin(), nums.end());
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int tmp = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < mid)
        break;
      tmp += nums[i] / mid;
      if (tmp >= k)
        break;
    }
    if (tmp >= k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << low - 1 << endl;
  return 0;
}

