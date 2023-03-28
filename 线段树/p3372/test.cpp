#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n, m;
int a[100000];
struct Node{
  long long sum;
  long long added;
  int left;
  int right;
  Node *left_child;
  Node *right_child;
  Node(int val, int left, int right) : sum(val), left(left), right(right), left_child(nullptr), right_child(nullptr) {}
};

Node *root;

Node *build(int left, int right) {
  if (left == right) {
    return new Node(a[left], left, right);
  }

  Node *res = new Node(0, left, right);
  int mid = (left + right) / 2;
  res->left_child = build(left, mid);
  res->right_child = build(mid + 1, right);
  res->sum = res->left_child->sum + res->right_child->sum;
  return res;
}

void push_down(Node *node) {
  if (node->added == 0 || node->left == node->right)
    return;

  long long num = node->added;
  node->left_child->added += num;
  node->right_child->added += num;
  
  Node *change = node->left_child;
  change->sum += (change->right - change->left + 1) * num;
  change = node->right_child;
  change->sum += (change->right - change->left + 1) * num;

  node->added = 0;
}


void ADD(Node *node, int left, int right, int k) {
  if (left <= node->left && right >= node->right) {
    node->sum += (node->right - node->left + 1) * k;
    node->added += k;
    return;
  }

  push_down(node);
  int mid = (node->left + node->right) / 2;
  if (mid >= left) {
    ADD(node->left_child, left, right, k);
  }
  if (mid < right) {
    ADD(node->right_child, left, right, k);
  }
  node->sum = node->left_child->sum + node->right_child->sum;
}


long long SUM(Node *node, int left, int right) {
  if (left <= node->left && right >= node->right) {
    return node->sum;
  }

  push_down(node);
  long long ans = 0;
  int mid = (node->left + node->right) / 2;
  if (mid >= left)
    ans += SUM(node->left_child, left, right);
  if (mid < right)
    ans += SUM(node->right_child, left, right);

  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  root = build(0, n - 1);

  int op, x, y, k;
  for (int i = 0; i < m; ++i) {
    cin >> op >> x >> y;
    if (op == 1) {
      cin >> k;
      ADD(root, x - 1, y - 1, k);
    } else {
      cout << SUM(root, x - 1, y - 1) << endl;
    }
  }
  return 0;
}
