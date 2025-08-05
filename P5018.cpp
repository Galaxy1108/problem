/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-04 18:05:19
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-04 19:56:46
 * @FilePath: \problem\P5018.cpp
 * @Description: 2025 暑期提高级巩固提升训练
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define MAXN 1000005
ll v[MAXN];
ll l_chil[MAXN], r_chil[MAXN];
ll chil_cnt[MAXN];

void get_cnt(ll u) {
    if (u == -1) {
        return;
    }
    get_cnt(l_chil[u]), get_cnt(r_chil[u]);
    chil_cnt[u] = chil_cnt[l_chil[u]] + chil_cnt[r_chil[u]] + 1;
}

bool check(ll l, ll r) {
    if (l == -1 && r == -1) {
        return true;
    }
    if (l == -1 || r == -1 || v[l] != v[r]) {
        return false;
    }
    return (check(l_chil[l], r_chil[r]) && check(r_chil[l], l_chil[r]));
}

int main() {
    ll n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> v[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> l_chil[i] >> r_chil[i];
    }
    get_cnt(1);
    ll anss = 0;
    for (int i = 1;i <= n;i++) {
        if (check(l_chil[i], r_chil[i])) {
            anss = max(anss, chil_cnt[i]);
        }
    }
    cout << anss; 
    return 0;
}