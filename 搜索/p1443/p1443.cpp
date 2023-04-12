#include <iostream>
#include <vector>
using namespace std;

int n, a, b;
int steps[205];
bool access[205];
int sum = 0x7fffffff;

void dfs(int cur, int k) {
    if (cur == b) {
        sum = min(k, sum);
        return;
    }
    if (k >= sum) {
        return;
    }

    access[cur] = true;
    if (cur + steps[cur] < n && !access[cur + steps[cur]]) {
        dfs(cur + steps[cur], k + 1);
    }
    if (cur >= steps[cur] && !access[cur - steps[cur]]) {
        dfs(cur - steps[cur], k + 1);
    }
    access[cur] = false;
}

int main() {
    cin >> n >> a >> b;
    --b;
    for (int i = 0; i < n; i++) {
        cin >> steps[i];
    }
    access[a - 1] = true;
    dfs(a - 1, 0);
    if (sum != 0x7fffffff)
        cout << sum << endl;
    else
        cout << -1 << endl;
    return 0;
}
