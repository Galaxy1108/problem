#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll h[505], b[505], w[505];
ll dp[505][250005];

int main() {
    int n;
    cin >> n;
    ll sumw = 0;
    for (int i = 1;i <= n;i++) {
        cin >> w[i] >> h[i] >> b[i];
        sumw += w[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= sumw;j++) {
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + h[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + b[i]);
        }
    }
    ll ans = 0;
    for (int j = 0;j <= sumw / 2;j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans;
}
