/**
 * problem: [BalticOI 2018] 路径
 * link: https://www.luogu.com.cn/problem/P4796
 * contest: 集训测试题 (2025/11/22) T1
 * difficult: blue
 * date: 2025/11/22 周六 15:04
 * tags: #DP
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> mp[300005];
int col[300005];
ll dp[300005][1 << 5];

int main() {
    // freopen("path.in", "r", stdin);
    // freopen("path.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) {
        cin >> col[i];
        dp[i][1 << (col[i] - 1)] = 1;
    }
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        mp[u].emplace_back(v);
        mp[v].emplace_back(u);
    }
    for (int s = 0;s < (1 << k);s++) {
        for (int u = 1;u <= n;u++) {
            for (int v : mp[u]) {
                if (s & (1 << (col[v] - 1))) {
                    continue;
                }
                dp[v][s | (1 << col[v] - 1)] += dp[u][s];
            }
        }
    }
    ll res = 0;
    for (int s = 0;s < (1 << k);s++) {
        if (__builtin_popcount(s) < 2) {
            continue;
        }
        for (int i = 1;i <= n;i++) {
            res += dp[i][s];
        }
    }
    cout << res;
    return 0;
}
