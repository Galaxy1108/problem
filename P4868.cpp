/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-06 20:31:36
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-06 20:41:16
 * @FilePath: \problem\P3372.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll d[100005], di[100005];
ll a[100005];
ll n, m;

ll lowbit(ll a){
    return (a & (-a));
}

void add(ll idx, ll num) {
    for (ll i = idx;i <= n;i += lowbit(i)) {
        d[i] += num, di[i] += num * idx;
    }
}

ll query(ll idx) {
    ll anss = 0;
    for (ll i = idx;i > 0;i -= lowbit(i)) {
        anss += (d[i] * (idx + 1) - di[i]);
    }
    return anss;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (m--) {
        string opt;
        cin >> opt;
        ll x, k;
        if (opt == "Modify") {
            cin >> x >> k;
            add(x, -a[x]);
            add(x, k);
            a[x] = k;
        } else {
            cin >> x;
            cout << query(x) << '\n';
        }
    }
    return 0;
}