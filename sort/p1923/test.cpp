#include <ios>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int nums[5000000];

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


int main()
{
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  
  int left = 0, right = n - 1;
  while (left < right) {
    int mid = partition(left, right);
    if (mid == k)
      break;
    if (k < mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << nums[k] << endl;
  return 0;
}
