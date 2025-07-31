#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define DEBUG 1

ll dp[10005][1005];
ll up[10005], down[10005];
ll l[10005], r[10005];

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    fill(r + 1, r + 1 + n, m + 1);
    for (int i = 1;i <= n;i++) {
        cin >> up[i - 1] >> down[i - 1];
    }
    for (int i = 1;i <= k;i++) {
        ll p;
        cin >> p >> l[p] >> r[p];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = INT_MAX;
    ll run_cnt = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j < m;j++) {
            ll up_part = ((j - up[i - 1] <= 0) ? INT_MAX : min(dp[i - 1][j - up[i - 1]], dp[i][j - up[i - 1]]) + 1);
            dp[i][j] = min({ dp[i][j], up_part });
            dp[i][j] = (dp[i][j] >= INT_MAX ? INT_MAX : dp[i][j]);
        }
        for (int j = 1;j <= m;j++) {
            dp[i][m] = min(dp[i][m], dp[i - 1][j] + (m - j) / up[i - 1] + !!((m - j) % up[i - 1]) + (m == j));
            ll down_part = ((j + down[i - 1] > m) ? INT_MAX : dp[i - 1][j + down[i - 1]]);
            dp[i][j] = min({ dp[i][j],down_part });
        }
        for (int j = 1;j <= l[i];j++) {
            dp[i][j] = INT_MAX;
        }
        for (int j = r[i];j <= m;j++) {
            dp[i][j] = INT_MAX;
        }
        if (l[i] != 0 || r[i] != m + 1) {
            bool flag = true;
            for (int j = 1;j <= m;j++) {
                if (dp[i][j] != INT_MAX) {
                    run_cnt++;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << 0 << '\n' << run_cnt;
                // return 0;
            }
        }
    }
    ll anss = INT_MAX;
    for (int i = 1;i <= m;i++) {
        anss = min(anss, dp[n][i]);
    }
    cout << 1 << '\n' << anss;
#if DEBUG
    cout << '\n';
    for (int j = m;j >= 1;j--) {
        for (int i = 1;i <= n;i++) {
            if (dp[i][j] == INT_MAX) {
                cout << 'X';
            } else { 
                cout << dp[i][j];
            }
            cout << "\t\n"[i == n];
        }
    }
#endif
}