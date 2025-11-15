/**
 * problem: Tree Painting
 * link: https://codeforces.com/problemset/problem/1187/E 
 * difficult: *2100 (blue)
 * date: 2025/11/15 周六 10:53
 * tags: #换根DP
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> t[200005];

int siz[200005], n;
ll res[200005];

void get_siz(int u, int f) {
    siz[u] = 1;
    for (auto v : t[u]) {
        if (v == f) {
            continue;
        }
        get_siz(v, u);
        siz[u] += siz[v];
        res[u] += res[v];
    }
    res[u] += siz[u];
}

void get_dp(int u, int f) {
    for (auto v : t[u]) {
        if (v == f) {
            continue;
        }
        res[v] = res[u] - 2 * siz[v] + n;
        get_dp(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        t[u].emplace_back(v);
        t[v].emplace_back(u);
    }
    get_siz(1, 0);
    get_dp(1, 0);
    ll ans = 0;
    for (int i = 1;i <= n;i++) {
        ans = max(ans, res[i]);
    }
    cout << ans;
    return 0;
}
