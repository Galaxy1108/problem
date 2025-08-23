#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m, mod = 1000000007;
ll fast_pow(ll a, ll b) {
    ll anss = 1;
    while (b) {
        if (b & 1) {
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}
ll dp[3005][3005][2];

int main() {
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        dp[0][i][0] = 1;
    }
    dp[0][0][1] = 1;
    for (int i = 1;i <= m;i++) {
        for (int j = 0;j <= n;j++) {
            if (j != n) {
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j + 1][1]) % mod;
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % mod;
                if (!j) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j + 1][0]) % mod;
                } else {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j + 1][0]) % mod;
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % mod;
                }
            }
            if (j) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][0]) % mod;
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 1][1]) % mod;
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % mod;
                if (j == 1) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % mod;
                } else {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0]) % mod;
                }
            }
        }
    }
    ll anss = 0;
    for (int j = 0;j <= n;j++) {
        anss = (anss + dp[m][j][1]) % mod;
    }
    cout << anss;
    return 0;
}