#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
using namespace std;
int k;
char num[251];
int net[251];
int prv[251];
int main()
{
  scanf("%s", num);
  scanf("%d", &k);
  int length = strlen(num);
  for (int i = 0; i < length; ++i) {
    net[i] = i + 1;
    prv[i] = i - 1;
  }

  int cur = 0;
  while (cur < length && k > 0) {
    // 删掉前面
    if (prv[cur] >= 0 && num[cur] < num[prv[cur]]) {
      num[prv[cur]] = 0;
      prv[cur] = prv[prv[cur]];
      --k;
      continue;
    }
    
    // 删掉自己
    if (net[cur] < length && num[cur] > num[net[cur]]) {
      num[cur] = 0;
      if (prv[cur] >= 0) {
        net[prv[cur]] = net[cur];
      }
      if (net[cur] < length) {
        prv[net[cur]] = prv[cur];
      }
      cur = net[cur];
      --k;
      continue;
    }

    cur = net[cur];
  }
  
  string res;
  for (int i = 0; i < length; ++i) {
    if (num[i]) {
      res.push_back(num[i]);
    }
  }
  while (k > 0) {
    res.pop_back();
    --k;
  }
  int i = 0;
  while (res[i] == '0')
    ++i;
  if (i == res.length())
    cout << 0 << endl;
  else
    cout << res.c_str() + i << endl;
  return 0;
}
