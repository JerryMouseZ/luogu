#include <bits/stdc++.h>
using namespace std;
static bool first = true;
void fn() {
  unsigned n;
  cin >> n;
  if (n == 0)
    return;
  fn();
  if (first) {
    first = false;
  } else {
    cout << " ";
  }
  cout << n;
}

int main()
{
  fn();
  cout << endl;
  return 0;
}

