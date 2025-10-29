#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll p[10005], a[10005], b[10005];
ll dp[10005][1005];
ll sums[10005], r[10005];

int main() {
    ll n;
    cin >> n;
    ll max_j = 0;
    for (int i = 1;i <= n;i++) {
        cin >> p[i] >> a[i] >> b[i];
        max_j = max(max_j, p[i] + a[i]);
        sums[i] = sums[i - 1] + b[i];
    }
    for (int j = 0;j <= max_j;j++) {
        dp[n][j] = j;
    }
    for (int i = n - 1;i >= 0;i--) {
        for (int j = 0;j <= max_j;j++) {
            dp[i][j] = ((j <= p[i + 1]) ? dp[i + 1][j + a[i + 1]] : dp[i + 1][max(0ll, j - b[i + 1])]);
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        if (x > max_j) {
            ll down_idx = lower_bound(sums + 1, sums + 1 + n, x - max_j) - sums;
            if (down_idx == n + 1) {
                cout << x - sums[n] << '\n';
                continue;
            }
            x = max(0ll, x - sums[down_idx]);
            cout << dp[down_idx][x] << '\n';
            continue;
        }
        cout << dp[0][x] << '\n';
    }
}