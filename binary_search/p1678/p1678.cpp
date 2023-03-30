#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int64_t m, n;
  cin >> m >> n;
  vector<int64_t> schools(m);
  vector<int64_t> students(n);

  for (int i = 0; i < m; ++i) {
    cin >> schools[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> students[i];
  }

  sort(schools.begin(), schools.end());
  
  int64_t res = 0;
  for (int64_t stu: students) {
    auto right = lower_bound(schools.begin(), schools.end(), stu);
    int64_t rd = 0;
    if (right != schools.end())
      rd = *right;
    else
      rd = *(right - 1);
    int64_t ld = 0;
    if (right != schools.begin())
      ld = *(right - 1);
    else
      ld = *right;
    res += min(abs(rd - stu), abs(ld - stu));

  }
  cout << res << endl;
  return 0;
}
