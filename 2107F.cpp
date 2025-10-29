#include <bits/stdc++.h>
using namespace std;

long long sn[5005];
long long dp[5005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> sn[i];
            dp[i] = LLONG_MAX;
        }
        dp[0] = 0;
        for (int i = 1;i <= n;i++) {
            long long mins = LLONG_MAX, idx = 0;
            for (int j = i - 1;j >= 0;j--) {
                if (sn[j + 1] < mins) {
                    mins = sn[j + 1];
                    idx = j + 1;
                }
                dp[i] = min(dp[i], dp[j] + (i - j - 1) + (i - idx) + (i - j) * mins);
            }
        }
        cout << dp[n] << '\n';
    }
}