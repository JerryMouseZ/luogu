#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, mod;
int a[maxn];


struct Node{
  int left, right;
  long long add, mul;
  long long sum;
} tree[4 * maxn];


void build(int p, int left, int right) {
  tree[p].left = left; tree[p].right = right;
  tree[p].mul = 1;
  if (left == right) {
    tree[p].sum = a[left] % mod;
    return;
  }
  
  int mid = (left + right) >> 1;
  build(2 * p, left, mid);
  build(2 * p + 1, mid + 1, right);
  tree[p].sum = (tree[2 * p].sum + tree[2 * p + 1].sum) % mod;
}

void push_down(int p) {
  if (tree[p].mul > 1) {
    long long k = tree[p].mul;
    tree[2 * p].add = tree[2 * p].add * k % mod;
    tree[2 * p].mul = k * tree[2 * p].mul % mod;
    tree[2 * p].sum = k * tree[2 * p].sum % mod;

    tree[2 * p + 1].add = tree[2 * p + 1].add * k % mod;
    tree[2 * p + 1].mul = k * tree[2 * p + 1].mul % mod;
    tree[2 * p + 1].sum = k * tree[2 * p + 1].sum % mod;
    tree[p].mul = 1;
  }

  if (tree[p].add) {
    long long k = tree[p].add;
    tree[2 * p].add += k;
    tree[2 * p + 1].add += k;
    tree[2 * p].add %= mod;
    tree[2 * p + 1].add %= mod;

    tree[2 * p].sum += k * (tree[2 * p].right - tree[2 * p].left + 1);
    tree[2 * p + 1].sum += k * (tree[2 * p + 1].right - tree[2 * p + 1].left + 1);
    tree[2 * p].sum %= mod;
    tree[2 * p + 1].sum %= mod;
    tree[p].add = 0;
  }
}

void ad(int p, int left, int right, int k) {
  if (left <= tree[p].left && right >= tree[p].right) {
    tree[p].add += k;
    tree[p].add %= mod;
    tree[p].sum += (tree[p].right - tree[p].left + 1) * k;
    tree[p].sum %= mod;
    return;
  }
  
  push_down(p);
  int mid = (tree[p].left + tree[p].right) / 2;
  if (mid >= left)
    ad(2 * p, left, right, k);
  if (mid < right)
    ad(2 * p + 1, left, right, k);
  tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
  tree[p].sum %= mod;
}

void mul(int p, int left, int right, int k) {
  if (left <= tree[p].left && right >= tree[p].right) {
    tree[p].add *= k;
    tree[p].mul *= k;
    tree[p].sum *= k;
    tree[p].add %= mod;
    tree[p].mul %= mod;
    tree[p].sum %= mod;
    return;
  }
  
  push_down(p);
  int mid = (tree[p].left + tree[p].right) / 2;
  if (mid >= left)
    mul(2 * p, left, right, k);
  if (mid < right)
    mul(2 * p + 1, left, right, k);
  tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
  tree[p].sum %= mod;
}


long long query(int p, int left, int right) {
  if (left <= tree[p].left && right >= tree[p].right) {
    return tree[p].sum;
  }
  
  push_down(p);
  long long ans = 0;
  int mid = (tree[p].left + tree[p].right) / 2;
  if (mid >= left)
    ans = query(2 * p, left, right) % mod;
  if (mid < right)
    ans = (ans + query(2 * p + 1, left, right)) % mod;
  return ans;
}


int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m >> mod;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  
  build(1, 1, n);

  int op, x, y, k;
  for (int i = 0; i < m; ++i) {
    cin >> op >> x >> y;
    if (op != 3)
      cin >> k;
    
    if (op == 1)
      mul(1, x, y, k);
    else if (op == 2)
      ad(1, x, y, k);
    else
      cout << query(1, x, y) << endl;
  }
  return 0;
}

