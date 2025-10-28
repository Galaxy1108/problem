/**
 * problem: Arena
 * link: https://codeforces.com/problemset/problem/1606/E
 * contest: 2025/10/28 DP T1 (arena)
 * difficult: *2100 (green)
 * date: 2025/10/28 周二 15:35
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[505][505];

#define mod 998244353

ll C[505][505];
ll POW[505][505];

ll fpow(ll a, ll b) {
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

int main() {
    int n, x;
    cin >> n >> x;
    if (n > x) {
        cout << fpow(x, n);
        return 0;
    }
    for (int j = 1;j <= x;j++) {
        dp[1][j] = 1;
    }
    ll sums = 1;
    for (int i = 1;i <= n;i++) {
        POW[i][0] = 1;
        sums = (sums * x) % mod;
        for (int j = 1;j <= n;j++) {
            POW[i][j] = (POW[i][j - 1] * i) % mod;
        }
    }
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= i;j++) {
            if (!j) {
                C[j][i] = 1;
            } else {
                C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % mod;
            }
        }
    }
    for (int i = 2;i <= n;i++) {
        for (int j = i;j <= x;j++) {
            for (int k = 1;k <= i;k++) {
                dp[i][j] = (dp[i][j] + ((dp[k][j - i + 1] * C[k][i]) % mod) * POW[i - 1][i - k] % mod) % mod;
            }
        }
    }
    ll res = 0;
    for (int j = 1;j <= x;j++) {
        res = (res + dp[n][j]) % mod;
    }
    cout << (sums - res + mod) % mod;
    return 0;
}
