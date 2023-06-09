#include <iostream>
#include <vector>
using namespace std;

int n, a, b;
vector<int> steps;
vector<bool> access;
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
    if (cur >= steps[cur] && !access[cur - steps[cur]]) {
        dfs(cur - steps[cur], k + 1);
    }
    if (cur + steps[cur] < n && !access[cur + steps[cur]]) {
        dfs(cur + steps[cur], k + 1);
    }
    access[cur] = false;
}

int main() {
    cin >> n >> a >> b;
    steps.resize(n);
    access.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> steps[i];
    }
    --b;
    dfs(a - 1, 0);
    cout << sum << endl;
    return 0;
}
