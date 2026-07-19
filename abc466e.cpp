#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll c[200005], dp[11][2];

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        ans += a;
        c[i] = b - a;
    }
    for (int j = 0; j <= k; j++) {
        dp[j][0] = dp[j][1] = -LLONG_MAX + INT_MAX;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 0; j--) {
            ll res = dp[j][1];
            dp[j][0] = max(dp[j][0], res);
            if (j >= 1) {
                dp[j][1] = c[i] + max({res, dp[j - 1][0], dp[j - 1][1]});
            } else {
                dp[j][1] = -LLONG_MAX + INT_MAX;
            }
        }
    }
    ll anss = ans;
    for (int j = 0; j <= k; j++) {
        anss = max({ anss, ans + dp[j][0], ans + dp[j][1] });
    }
    cout << anss << endl;
}
