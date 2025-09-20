#include <bits/stdc++.h>
using namespace std;

long long sn[200005];
long long lasts[200005];
long long dp[200005];
long long lastn[1000005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        dp[0] = 0;
        memset(lastn, 0, sizeof(lastn));
        for (int i = 1;i <= n;i++) {
            cin >> sn[i];
            lasts[i] = (lasts[i - 1] + sn[i] * (sn[i] == sn[i - 1]));
        }
        for (int i = 1;i <= n;i++) {
            dp[i] = dp[i - 1];
            if (lastn[sn[i]]) {
                dp[i] = max(dp[i], sn[i] + dp[lastn[sn[i]] + 1] + lasts[i] - lasts[lastn[sn[i]] + 1]);
            }
            lastn[sn[i]] = i;
        }
        cout << dp[n] << '\n';
    }
}
