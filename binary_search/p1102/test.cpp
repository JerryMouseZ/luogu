#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>
using namespace std;

int a[200001];
int main()
{
  size_t n, c;
  cin >> n >> c;
  unordered_map<int ,int> counter;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    counter[a[i]]++;
  }
  
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int target = a[i] - c;
    if (counter.count(target)) {
      ans += counter[target];
    }
  }

  cout << ans << endl;
  return 0;
}
