/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-05 15:03:04
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-05 19:08:38
 * @FilePath: \problem\P2979.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll v[105], h[105];
ll dp[2005];

int main() {
    ll n, t, k;
    cin >> n >> t >> k;
    for (int i = 1;i <= n;i++) {
        cin >> v[i] >> h[i];
        for (int j = h[i];j <= t * 5 / 4;j++) {
            dp[j] = max(dp[j], dp[j - h[i]] + v[i]);
        }
    }
    ll anss = dp[t];
    for (int i = 1;i <= n;i++) {
        if (h[i] >= k) {
            anss = max(anss, dp[(t - h[i]) * 5 / 4] + v[i]);
        }
    }
    cout << anss;
    return 0;
}
