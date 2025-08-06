/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-06 20:52:06
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-06 21:42:00
 * @FilePath: \problem\P5852.cpp
 * @Description: 2025 暑期提高级巩固提升训练
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll d[100005], di[100005];
vector<ll> a[100005];
set<ll> s[100005];
ll dfsn[100005], dfsn_num, re_dfsn[100005];
ll subc[100005];
ll n, q;

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

void process(ll u, ll f) {
    dfsn[u] = ++dfsn_num;
    re_dfsn[dfsn_num] = u;
    subc[u] = 1;
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        process(v, u);
        subc[u] += subc[v];
    }
}

bool is_chil(ll u, ll v) {
    return (dfsn[v] >= dfsn[u] && dfsn[v] < (dfsn[u] + subc[u]));
}

int main() {
    cin >> n >> q;
    for (int i = 1;i < n;i++) {
        ll u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    process(1, 0);
    while (q--) {
        ll opt, x, c;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> c;
            ll dx = dfsn[x];
            auto idx = s[c].upper_bound(dx);
            if (idx != s[c].begin() && is_chil(re_dfsn[*(prev(idx))], x)) {
                continue;
            }
            for (auto i = idx;i != s[c].end() && is_chil(x, re_dfsn[*i]);add(*i, -1), add(*i + subc[re_dfsn[*i]], 1), i = s[c].erase(i));
            s[c].insert(dx);
            add(dx, 1), add(dx + subc[x], -1);
        } else {
            cin >> x;
            ll dx = dfsn[x];
            cout << query(dx + subc[x] - 1) - query(dx - 1) << '\n';
        }
    }
    return 0;
}