/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-10 15:51:07
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-10 17:21:25
 * @FilePath: \problem\at_abc418_E.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll xs[2005], ys[2005];
unordered_map<double, ll> m;
map < pair<double, ll>, ll> ms;

#define inf 1e9

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> xs[i] >> ys[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            ll a = ys[i] - ys[j], b = xs[i] - xs[j];
            if (b == 0) {
                m[inf]++;
                ms[{inf, a * a + b * b}]++;
                continue;
            }
            m[a * 1.0 / b]++;
            ms[{a * 1.0 / b, a * a + b * b}]++;
        }
    }
    ll anss = 0;
    for (auto its : m) {
        ll ns = its.second;
        anss += (ns * (ns - 1)) / 2;
    }
    // cout << anss << endl;
    ll res = 0;
    for (auto its : ms) {
        ll ns = its.second;
        res += (ns * (ns - 1)) / 2;
    }
    cout << anss - res / 2;
}