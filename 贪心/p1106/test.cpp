#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int k;
char num[251];
int main()
{
  scanf("%s", num);
  scanf("%d", &k);
  int left = 0, right = 0;
  for (int i = 0; i < 251; ++i) {
    if (num[i] == '\0')
      break;
    if (k > 0 && num[i] > num[i + 1]) {
      --k;
    } else {
      printf("%c", num[i]);
    }
  }
  printf("\n");
  return 0;
}
