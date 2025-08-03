/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-03 19:38:09
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-03 20:47:37
 * @FilePath: \problem\P5658.cpp
 * @Description: 
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
string str;
ll fat[500005], ans[500005], anss[500005];
ll sta[500005], tops;
vector<ll> a[500005];

void dfs(ll u) {
    ll last_sta = 0;
    if (str[u] == ')' && tops) {
        ans[u] = ans[fat[last_sta = sta[tops--]]] + 1;
    } else if (str[u] == '(') {
        sta[++tops] = u;
    }
    anss[u] = anss[fat[u]] + ans[u];
    for (auto v : a[u]) {
        dfs(v);
    }
    if (last_sta) {
        sta[++tops] = last_sta;
    } else if (tops) {
        tops--;
    }
}

int main() {
    cin >> n;
    cin >> str;
    str = " " + str;
    for (int i = 2;i <= n;i++) {
        cin >> fat[i];
        a[fat[i]].emplace_back(i);
    }
    fat[1] = 0;
    // ans[0] = -1;
    dfs(1);
    ll ansss = 0;
    for (ll i = 1;i <= n;i++) {
        ansss ^= anss[i] * i;
        // cout << anss[i] << ' ';
    }
    // cout << '\n';
    cout << ansss;
    return 0;
}