/**
 * problem: 异或序列
 * link: https://www.luogu.com.cn/problem/P3917
 * difficult: green
 * date: 2025/10/28 周二 14:50
 * tags: #异或
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool pxo[100005][40];
bool ab[100005][40];
int a[100005];
int c0[40], c1[40];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        for (int p = 0;p <= 31;p++) {
            ab[i][p] = a[i] & (1 << p);
        }
    }
    ll ans = 0;
    for (int p = 0;p <= 31;p++) {
        ll res = 0;
        c0[p] = 1;
        for (int i = 1;i <= n;i++) {
            pxo[i][p] = pxo[i - 1][p] ^ ab[i][p];
            res += (pxo[i][p] ? c0[p] : c1[p]);
            c0[p] += (pxo[i][p] ? 0 : 1);
            c1[p] += (pxo[i][p] ? 1 : 0);
        }
        ans += res * (1 << p);
    }
    cout << ans;
}
