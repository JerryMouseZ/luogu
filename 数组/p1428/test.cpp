#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100];
int counter[100];
pair<int, int> tmp[100];

void merge_sort(int begin, int end)
{
  if (end <= begin)
    return;
  int mid = begin + (end - begin) / 2;
  merge_sort(begin, mid);
  merge_sort(mid + 1, end);
  
  int left = begin, right = mid + 1;
  int base = 0;
  while (left <= mid && right <= end) {
    if (a[left].first >= a[right].first) {
      tmp[base] = a[left];
      ++left;
    } else {
      counter[a[right].second] += mid + 1 - left;
      tmp[base] = a[right];
      ++right;
    }
    base++;
  }
  
  while (left <= mid) {
    tmp[base++] = a[left++];
  }

  while (right <= end)  {
    tmp[base++] = a[right++];
  }
  
  for (int i = 0; i < base; ++i) {
    a[i + begin] = tmp[i];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  
  merge_sort(0, n - 1);
  /* for (int i = 0; i < n; ++i) */
  /*   cout << a[i].first << " "; */
  /* cout << endl; */
  for (int i = 0; i < n - 1; ++i)
    cout << counter[i] << " ";
  cout << counter[n - 1] << endl;
  return 0;
}

