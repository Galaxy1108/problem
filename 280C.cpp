/**
 * @name Game on Tree
 * @link https://codeforces.com/problemset/problem/280/C 
 * @class blue *2200
 * @date 2025/10/10 周五 14:15
 * @par tags
 * #期望
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> a[100005];
int dep[100005];
long double anss;

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    anss += 1.0 / dep[u];
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        dfs(v, u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    dfs(1, 0);
    printf("%.6Lf", anss);
    return 0;
}