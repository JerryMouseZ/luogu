#include <bits/stdc++.h>
using namespace std;
int vals[401][401];
bool flags[401][401];
queue<pair<int, int>> q;
int n, m, x, y;

bool valid(int x, int y) {
  return x >= 1 && x <= n &&
    y >= 1 && y <= m && !flags[x][y];
}

int nextx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int nexty[] = {-2, 2, -2, 2, -1, 1, -1, 1};

void bfs(int x, int y) {
  for (int i = 0; i < 8; ++i) {
    int u = x + nextx[i];
    int v = y + nexty[i];
    if (valid(u, v)) {
      vals[u][v] = vals[x][y] + 1;
      q.push(pair<int, int> (u, v));
      flags[u][v] = true;
    }
  }
}


int main()
{
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      vals[i][j] = -1;
    }
  }

  vals[x][y] = 0;
  flags[x][y] = true;
  bfs(x, y);
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    bfs(node.first, node.second);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m - 1; ++j) {
      cout << vals[i][j] << " ";
    }
    cout << vals[i][m] << endl;
  }
  return 0;
}

