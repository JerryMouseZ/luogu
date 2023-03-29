#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct Node {
  int l, r;
  int val;
  bool change;
} t[maxn * 4];

char a[maxn];

void build(int p, int l, int r) {
  t[p].l = l; t[p].r = r;
  if (t[p].l == t[p].r) {
    t[p].val = a[l] - '0';
    return;
  }

  int mid = (l + r) / 2;
  build(2 * p, l, mid);
  build(2 * p + 1, mid + 1, r);
  t[p].val = t[2 * p].val + t[2 * p + 1].val;
}

void push_down(int p) {
  if (!t[p].change)
    return;

  t[2 * p].change = !t[2 * p].change;
  t[2 * p + 1].change = !t[2 * p + 1].change;
  t[2 * p].val = (t[2 * p].r - t[2 * p].l + 1 - t[2 * p].val);
  t[2 * p + 1].val = (t[2 * p + 1].r - t[2 * p + 1].l + 1 - t[2 * p + 1].val);
  t[p].change = false;
}

void change(int p, int l, int r) {
  if (l <= t[p].l && t[p].r <= r) {
    t[p].change = !t[p].change;
    t[p].val = (t[p].r - t[p].l + 1 - t[p].val);
    return;
  }

  push_down(p);
  int mid = (t[p].l + t[p].r) / 2;
  if (mid >= l)
    change(2 * p, l, r);
  if (mid < r)
    change(2 * p + 1, l, r);
  t[p].val = t[2 * p].val + t[2 * p + 1].val;
}

int query(int p, int l, int r) {
  if (l <= t[p].l && t[p].r <= r) {
    return t[p].val;
  }

  push_down(p);
  int mid = (t[p].l + t[p].r) / 2;
  int ans = 0;
  if (mid >= l)
    ans += query(2 * p, l, r);
  if (mid < r)
    ans += query(2 * p + 1, l, r);
  return ans;
}

int n, m;
int main()
{
  cin >> n >> m;
  cin >> &a[1];

  build(1, 1, n);

  int op, l, r;
  for (int i = 0; i < m; ++i) {
    cin >> op >> l >> r;
    if (op == 0)
      change(1, l, r);
    else
      cout << query(1, l, r) << endl;
  }

  return 0;
}
