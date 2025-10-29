/**
 * problem: Fake Plastic Trees
 * link: https://codeforces.com/problemset/problem/1693/B
 * difficult: *1700 (green)
 * date: 2025/10/29 周三 19:50
 * tags: #贪心
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> trr[200005];
ll l[200005], r[200005];
ll num[200005], cnts;

void dfs(int u) {
    for (auto v : trr[u]) {
        dfs(v);
        num[u] += num[v];
    }
    if (num[u] < l[u]) {
        num[u] = r[u];
        cnts++;
    }
    num[u] = min(num[u], r[u]);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cnts = 0;
        for (int i = 1;i <= n;i++) {
            trr[i].clear();
            num[i] = 0;
        }
        for (int i = 2;i <= n;i++) {
            int p;
            cin >> p;
            trr[p].emplace_back(i);
        }
        for (int i = 1;i <= n;i++) {
            cin >> l[i] >> r[i];
        }
        dfs(1);
        cout << cnts << '\n';
    }
}
