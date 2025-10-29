/**
 * @name Jon and Orbs
 * @link https://codeforces.com/problemset/problem/768/D 
 * @par tags
 * #DP #概率DP
 */

#include <bits/stdc++.h>
using namespace std;

#define maxd 10000
long double dp[maxd + 5][1005];

int main() {
    int k, q;
    cin >> k >> q;
    dp[0][0] = 1;
    for (int i = 1;i <= maxd;i++) {
        for (int j = 1;j <= k;j++) {
            dp[i][j] = dp[i - 1][j] * 1.0l * j / k + dp[i - 1][j - 1] * 1.0l * (k - j + 1) / k;
        }
    }
    while (q--) {
        int p;
        cin >> p;
        for (int i = 1;i <= maxd;i++) {
            if (dp[i][k] >= p * 0.0005) {
                cout << i << '\n';
                break;
            }
        }
    }
}