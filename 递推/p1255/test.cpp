#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a1[5000], a2[5000], res[5000];
int thresholds = 100000000;
int ns = 1;
int main()
{
  int n;
  scanf("%d", &n);
  if (n < 3) {
    printf("%d\n", n);
    return 0;
  }
  
  a1[0] = 1;
  a2[0] = 2;
  for (int i = 3; i <= n; ++i) {
    // 提前进位
    for (int j = 0; j < ns; ++j) {
      res[j] = a1[j] + a2[j];
    }
    for (int j = 0; j < ns; ++j) {
      if (res[j] >= thresholds) {
        res[j] -= thresholds;
        res[j + 1] += 1;
      }
    }
    if (res[ns] > 0)
      ns += 1;
    for (int j = 0; j < ns; ++j) {
      a1[j] = a2[j];
      a2[j] = res[j];
    }
  }
  
  printf("%d", res[ns - 1]);
  for (int i = ns - 2; i >= 0; --i) {
    printf("%08d", res[i]);
  }
  printf("\n");
  return 0;
}

