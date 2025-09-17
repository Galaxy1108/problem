#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
using i64 = long long;

i64 d[1005][1005];
i64 dp[1005][4];
bool maps[1005][1005];

int main() {
    int T, id;
    cin >> T >> id;
    while (T--) {
        int n, m, c, f;
        cin >> n >> m >> c >> f;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                char temp;
                cin >> temp;
                maps[i][j] = temp - '0';
            }
        }
        for (int i = 1;i <= n;i++) {
            d[i][m + 1] = 0;
            for (int j = m;j >= 1;j--) {
                d[i][j] = (maps[i][j] ? 0 : d[i][j + 1] + 1);
            }
        }
        i64 ans1 = 0, ans2 = 0;
        for (int j = 1;j <= m;j++) {
            for (int i = 1;i <= n;i++) {
                if (maps[i][j]) {
                    dp[i][1] = dp[i][2] = dp[i][3] = 0;
                    continue;
                }
                dp[i][1] = (dp[i - 1][1] + max(d[i - 1][j] - 1, 0ll)) % mod;
                dp[i][2] = (dp[i - 1][1] * (d[i][j] - 1)) % mod;
                dp[i][3] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
                ans1 = (ans1 + dp[i][2]) % mod;
                ans2 = (ans2 + dp[i][3]) % mod;
            }
        }
        cout << (c * ans1) % mod << ' ' << (f * ans2) % mod << '\n';
    }
    return 0;
}