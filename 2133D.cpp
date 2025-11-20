/**
 * problem: Chicken Jockey
 * link: https://codeforces.com/problemset/problem/2133/D 
 * contest: https://vjudge.net/contest/768289 (强化训练VP 1)
 * difficult: *1900 (green)
 * date: 2025/11/20 周四 19:32
 * tags: #DP #贪心
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll h[200005];
ll dp[200005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> h[i];
        }
        dp[1] = h[1];
        for (int i = 2;i <= n;i++) {
            dp[i] = min(dp[i - 1] + h[i] - 1, dp[i - 2] + h[i - 1] + max(0ll, h[i] - (i - 1)));
        }
        cout << dp[n] << '\n';
    }
}
