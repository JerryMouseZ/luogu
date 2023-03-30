#include <algorithm>
#include <bits/stdc++.h>
#include <regex>
using namespace std;
int nums[100000];

int partition(int left, int right)
{
  int privot = nums[left];
  while (left < right) {
    while (nums[right] > privot && left < right)
      --right;
    if (left < right)
      nums[left] = nums[right];
    while (nums[left] <= privot && left < right)
      ++left;
    if (left < right)
      nums[right] = nums[left];
  }
  nums[left] = privot;
  return left;
}

void quick_sort(int left, int right)
{
  if (left >= right)
    return;
  int mid = partition(left, right);
  quick_sort(left, mid - 1);
  quick_sort(mid + 1, right);
}

int main()
{
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  
  quick_sort(0, n - 1);
  for (int i = 0; i < n - 1; ++i)
    cout << nums[i] << " ";
  cout << nums[n - 1] << endl;
  return 0;
}

