#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int maxn = 100001;
int n, m;
int a[maxn];
struct Node{
  long long sum, added;
  int left;
  int right;
} tree[4 * maxn + 2];

void build(int p, int left, int right) {
  tree[p].left = left; tree[p].right = right;
  if (left == right) {
    tree[p].sum = a[left];
    return;
  }
  
  int mid = (left + right) / 2;
  build(2 * p, left, mid);
  build(2 * p + 1, mid + 1, right);
  tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
}


void push_down(int p) {
  if (tree[p].added == 0)
    return;

  long long num = tree[p].added;
  tree[2 * p].added += num;
  tree[2 * p + 1].added += num;
  
  tree[2 * p].sum += (tree[2 * p].right - tree[2 * p].left + 1) * num;
  tree[2 * p + 1].sum += (tree[2 * p + 1].right - tree[2 * p + 1].left + 1) * num;
  tree[p].added = 0;
}


void ADD(int p, int left, int right, int k) {
  if (left <= tree[p].left && right >= tree[p].right) {
    tree[p].sum += (tree[p].right - tree[p].left + 1) * k;
    tree[p].added += k;
    return;
  }

  push_down(p);
  int mid = (tree[p].left + tree[p].right) / 2;
  if (mid >= left) 
    ADD(2 * p, left, right, k);
  if (mid < right)
    ADD(2 * p + 1, left, right, k);

  tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
}


long long SUM(int p, int left, int right) {
  if (left <= tree[p].left && right >= tree[p].right) {
    return tree[p].sum;
  }

  push_down(p);
  long long ans = 0;
  int mid = (tree[p].left + tree[p].right) / 2;
  if (mid >= left)
    ans += SUM(2 * p, left, right);
  if (mid < right)
    ans += SUM(2 * p + 1, left, right);
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  build(1, 1, n);

  int op, x, y, k;
  for (int i = 0; i < m; ++i) {
    cin >> op >> x >> y;
    if (op == 1) {
      cin >> k;
      ADD(1, x, y, k);
    } else {
      cout << SUM(1, x, y) << endl;
    }
  }
  return 0;
}
