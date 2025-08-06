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
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    while (m--) {
        ll opt, x, y, k;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> k;
            add(x, k), add(y + 1, -k);
        } else {
            cin >> x >> y;
            cout << query(y) - query(x - 1) << '\n';
        }
    }
    return 0;
}