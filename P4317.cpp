/**
 * problem: 花神的数论题
 * link: https://www.luogu.com.cn/problem/P4317
 * contest: 集训测试题 (2025/11/22) T2
 * difficult: blue
 * date: 2025/11/22 周六 15:05
 * tags: #数学
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 10000007

ll cnts[65], f[65];
ll c[65][65];

ll fpow(ll a, ll b) {
    ll anss = 1;
    while (b) {
        if (b & 1) {
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

int main() {
    ll n;
    cin >> n;
    c[0][0] = 1;
    for (int i = 1;i <= 63;i++) {
        for (int j = 0;j <= i;j++) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    int pre_cnt = 0;
    for (int i = 63;i >= 0;i--) {
        if (!(n & (1ll << i))) {
            continue;
        }
        for (int j = 0;j <= 63 - pre_cnt;j++) {
            cnts[j + pre_cnt] += c[i][j];
        }
        pre_cnt++;
    }
    cnts[__builtin_popcountll(n)]++;
    ll res = 1;
    for (int i = 1;i <= 63;i++) {
        res = (res * fpow(i, cnts[i])) % mod;
    }
    cout << res;
}

//34 560 5951 45849 272832 1304479 5147207 17084092 48375740 118116883 250721100 465571840 759930763 1094206048 1393353106 1571688097 1571666863 1393300174 1094145333 759882643 465543349 250708274 118112528 48374656 17083905 5147187 1304478 272832 45849 5951 560 34 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 647565408
