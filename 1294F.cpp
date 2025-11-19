/**
 * problem: Three Paths on a Tree
 * link: https://codeforces.com/problemset/problem/1294/F 
 * contest: https://vjudge.net/contest/765472 (NOIP2025—基本功提升训练 2)
 * difficult: *2000 (blue)
 * date: 2025/11/19 周三 14:19
 * tags: #DP #贪心
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector<int> trr[MAXN];
int n, ln_idx, rn_idx;
int maxx[MAXN], maxn[MAXN];
int fat[MAXN];

void dfs(int u, int f) {
    maxx[u] = 0, maxn[u] = u;
    for (int v : trr[u]) {
        if (v == f) {
            continue;
        }
        fat[v] = u;
        dfs(v, u);
        if (maxx[v] + 1 > maxx[u]) {
            maxx[u] = maxx[v] + 1;
            maxn[u] = maxn[v];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        trr[u].emplace_back(v);
        trr[v].emplace_back(u);
    }

    dfs(1, 0);
    ln_idx = maxn[1];
    dfs(ln_idx, 0);
    rn_idx = maxn[ln_idx];

    int resx = 0, resn = fat[rn_idx], its = rn_idx;
    while (its != ln_idx) {
        int u = fat[its];
        for (int v : trr[u]) {
            if (v == its || v == fat[u]) {
                continue;
            }
            if (maxx[v] + 1 > resx) {
                resx = maxx[v] + 1;
                resn = maxn[v];
            }
        }
        its = u;
    }

    cout << resx + maxx[ln_idx] << '\n';
    cout << ln_idx << ' ' << rn_idx << ' ' << resn;

    return 0;
}
