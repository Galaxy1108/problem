/**
 * @name Broken robot
 * @link https://codeforces.com/problemset/problem/24/D 
 * @class purple
 * @date 2025/10/08 周三 14:41
 * @par tags
 * #DP #期望DP
 */

#include <bits/stdc++.h>
using namespace std;

long double dp[1005][1005];

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int run_cnt = 40;    
    for (int i = n - 1;i >= x;i--) {
        for (int k = 1;k <= run_cnt;k++) {
            for (int j = 1;j <= m;j++) {
                if (m == 1) {
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) / 2 + 1;
                } else if (j == 1) {
                    dp[i][j] = (dp[i][j] + dp[i][j + 1] + dp[i + 1][j]) / 3 + 1;
                } else if (j == m) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i + 1][j]) / 3 + 1;
                } else {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1] + dp[i][j + 1] + dp[i + 1][j]) / 4 + 1;
                }
            }
        }
    }
    printf("%.10Lf", dp[x][y]);
}