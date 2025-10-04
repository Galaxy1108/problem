#include <bits/stdc++.h>
using namespace std;

int n, st, en;
vector<int> a[100005];
// int dfsn[100005], ndfs[100005], cnt, rdfsn[100005],is_key[100005];
int dep[100005], maxdep;
vector<int> s[100005];

void build(int u, int f) {
    // dfsn[u] = ++cnt;
    // ndfs[cnt] = u;
    dep[u] = dep[f] + 1;
    maxdep = max(maxdep, dep[u]);
    s[dep[u]].emplace_back(u);
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        build(v, u);
    }
    // rdfsn[u] = cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> st >> en;
        maxdep = 0;
        for (int i = 0;i <= n;i++) {
            a[i].clear();
            s[i].clear();
            // is_key[i] = false;
            // dfsn[i] = ndfs[i] = rdfsn[i] = fat[i] = 0;
        }
        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        build(en, 0);
        // int its_n = en;
        // while (its_n != st) {
        //     is_key[its_n] = true;
        //     its_n = fat[its_n];
        // }
        // int su = 0;
        // for (auto u : a[st]) {
        //     if (is_key[u]) {
        //         su = u;
        //         break;
        //     }
        // }
        for (int i = maxdep;i >= 1;i--) {
            for (auto u : s[i]) {
                cout << u << ' ';
            }
        }
        cout << '\n';
    }
}