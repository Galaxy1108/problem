#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[300005], b[300005], c[300005];
ll dp[300005][3];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    for (int i = 1;i <= n;i++) {
        dp[i][0] = dp[i - 1][0] + a[i];
        if (i >= 2) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
        }
        if (i >= 3) {
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
        }
    }
    cout << dp[n][2];
    return 0;
}
