#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sn[2 * n] = {};
    for (int i = 0; i < n;i++) {
        cin >> sn[i];
        sn[n + i] = sn[i];
    }
    int ans = 0;
    for (int i = 0; i < n;i++) {
        int dp[201][201] = {};
        for (int k = 1; k < n;k++) {
            for (int l = i; l + k < n + i;l++) {
                int r = l + k;
                for (int q = l; q < r;q++) {
                    dp[l][r] = max(dp[l][r], dp[l][q] + dp[q + 1][r] + sn[l] * sn[q + 1] * sn[r + 1]);
                }
            }
        }
        ans = max(ans, dp[i][n + i - 1]);
    }
    cout << ans << endl;
}