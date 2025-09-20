#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[2][205][205][2];

#define mod 1000000007

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    string str_a, str_b;
    cin >> str_a >> str_b;
    dp[1][0][0][0] = 1;
    dp[0][0][0][0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            for (int p = 1;p <= k;p++) {
                dp[i % 2][j][p][0] = (dp[(i - 1) % 2][j][p][0] + dp[(i - 1) % 2][j][p][1]) % mod;
                dp[i % 2][j][p][1] = ((str_a[i - 1] == str_b[j - 1])
                    ? (dp[(i - 1) % 2][j - 1][p][1] + dp[(i - 1) % 2][j - 1][p - 1][1] + dp[(i - 1) % 2][j - 1][p - 1][0]) % mod
                    : (0));
            }
        }
    }
    cout << (dp[n % 2][m][k][0] + dp[n % 2][m][k][1]) % mod;
}