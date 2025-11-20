/**
 * problem: Villagers
 * link: https://codeforces.com/problemset/problem/2133/B 
 * contest: https://vjudge.net/contest/768289 (强化训练VP 1)
 * difficult: *800 (orange)
 * date: 2025/11/20 周四 19:30
 * tags: #贪心
 */

#include <bits/stdc++.h>
using namespace std;

int g[200005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> g[i];
        }
        sort(g + 1, g + 1 + n, [](int a, int b) {
            return a > b;
        });
        long long ans = 0;
        for (int i = 1;i <= n;i += 2) {
            ans += g[i];
        }
        cout << ans << '\n';
    }
}
