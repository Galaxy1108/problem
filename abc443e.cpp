#include <bits/stdc++.h>
using namespace std;

char s[3005][3005];
int l[3005];
int dp[3005][3005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        for (int j = 1; j <= n; j++) {
            l[j] = -1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 1; j <= n; j++) {
                s[i][j] = tmp[j - 1];
                if (s[i][j] == '#') {
                    l[j] = i;
                }
            }
        }
        dp[n][c] = 1;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j]) {
                    continue;
                }
                bool flag = false;
                if (dp[i + 1][j]) {
                    flag = true;
                }
                if (j > 1 && dp[i + 1][j - 1]) {
                    flag = true;
                }
                if (j < n && dp[i + 1][j + 1]) {
                    flag = true;
                }
                if (!flag) {
                    continue;
                }
                if (s[i][j] == '.') {
                    dp[i][j] = 1;
                } else {
                    if (l[j] == i) {
                        for (int k = 1; k <= i; k++) {
                            dp[k][j] = 1;
                        }
                    }
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            cout << dp[1][j];
        }
        cout << '\n';
    }
    return 0;
}
