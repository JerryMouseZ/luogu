#include <bits/stdc++.h>
#include <vector>
using namespace std;
int nums[20];
int a[10];
int b[10];
bool cmp(int left, int right) {
  int counta = 0, countb = 0;
  while (left > 0) {
    a[counta++] = left % 10;
    left /= 10;
  }
  while (right) {
    b[countb++] = right % 10;
    right /= 10;
  }
  int ca = counta, cb = countb;
  while (counta && countb) {
    if (a[counta - 1] == b[countb - 1]) {
      --counta;
      --countb;
    } else {
      return a[counta - 1] < b[countb - 1];
    }
  }
  if (counta)
    return a[counta - 1] < b[cb - 1];
  if (countb)
    return a[ca - 1] < b[countb - 1];
  return false;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  
  sort(nums, nums + n, cmp);
  for (int i = n - 1; i >= 0; --i)
    cout << nums[i];
  cout << endl;
  return 0;
}

