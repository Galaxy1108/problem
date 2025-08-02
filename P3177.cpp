#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct edges {
    ll v, w;
};
vector<edges> a[2005];
ll dp[2005][2005];
ll sub[2005], n, k;

void DP(ll u, ll f) {
    sub[u] = 1;
    dp[u][0] = dp[u][1] = 0;
    for (auto its : a[u]) {
        ll v = its.v, w = its.w;
        if (v == f) {
            continue;
        }
        DP(v, u);
        sub[u] += sub[v];
        // cout << min(k, sub[u]) << "\n\n";
        for (int j = min(k, sub[u]);j >= 0;j--) {
            if (dp[u][j] != LLONG_MIN) {
                dp[u][j] += dp[v][0] + (1ll * sub[v] * (n - k - sub[v])) * w;
                // cout << dp[u][j] <<' ' << sub[v] <<' '<<n-k-sub[v]<<' '<<w << " A\n";
                // continue;
            }
            for (int sub_j = min(j * 1ll, sub[v]); sub_j > 0;sub_j--) {
                // cout << j << endl;
                if (dp[u][j - sub_j] == LLONG_MIN / 2) {
                    continue;
                }
                ll tot = 1ll * sub_j * (k - sub_j) + 1ll * (sub[v] - sub_j) * (n - k - sub[v] + sub_j);
                // cout << tot << '\n';
                dp[u][j] = max(dp[u][j], dp[u][j - sub_j] + dp[v][sub_j] + 1ll * tot * w);
                // cout << dp[u][j] << ' ' << dp[v][sub_j] <<' '<<tot*w << '\n';
            }
        }
    }
}

int main() {
    // freopen("P3177.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        // w = (w == 1 ? 2 : 1);
        a[u].emplace_back((edges) { v, w });
        a[v].emplace_back((edges) { u, w });
    }
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= n;j++) {
            dp[i][j] = LLONG_MIN / 2;
        }
    }
    DP(1, -1);
    cout << dp[1][k] << '\n';
    return 0;
}