#include <bits/stdc++.h>
using namespace std;

bool valid(const vector<long long>& trees, long long height, long long target) {
  long long res = 0;
  for (int i = 0; i < trees.size(); ++i) {
    if (trees[i] > height) {
      res += trees[i] - height;
    }
  }
  return res >= target;
}

int main()
{
  long long n, m;
  cin >> n >> m;
  vector<long long> trees(n);
  for (int i = 0; i < n; ++i) {
    cin >> trees[i];
  }
  
  long long right = *max_element(trees.begin(), trees.end());
  long long left = 0;
  long long res = 0;
  
  while (left <= right) {
    int mid = (left + right) / 2;
    if (valid(trees, mid, m)) {
      res = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << res << endl;
  return 0;
}

