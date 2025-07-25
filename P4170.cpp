#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[55][55];

int main() {
    string str;
    cin >> str;
    int n = str.size();
    for (int i = n - 1;i >= 0;i--) {
        dp[i][i] = 1;
        for (int j = i + 1;j < n;j++) {
            if (str[i] == str[j]) {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            dp[i][j] = INT_MAX;
            for (int k = i;k < j;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}