/**
 * @name 旅行（trip）
 * @link https://www.luogu.com.cn/problem/P14253
 * @test https://www.luogu.com.cn/contest/281662 T1
 * @class yellow
 * @date 2025/10/20 周一 13:14
 * @par tags
 * #贪心
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[1000005];

unordered_map<ll, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        mp.clear();
        int anss = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            a[i] += a[i - 1];
            anss = max(anss, ++mp[a[i]] - !!a[i]);
        }
        cout << anss << '\n';
    }
}
