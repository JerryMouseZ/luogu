#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> datas(n);
  for (int i = 0; i < n; ++i)
    cin >> datas[i].first >> datas[i].second;
  sort(datas.begin(), datas.end(), [](const pair<int,int> &left, const pair<int,int> &right){
       if (left.second == right.second)
          return left.first < right.first;
       return left.second > right.second;
       });
  k = k + k / 2;
  while (k < n && datas[k - 1].second == datas[k].second)
    ++k;
  cout << datas[k - 1].second << " " << k << endl;
  for (int i = 0; i < k; ++i)
    cout << datas[i].first << " " << datas[i].second << endl;
  return 0;
}

