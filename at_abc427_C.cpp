#include <bits/stdc++.h>
using namespace std;

vector<int> a[15];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    int anss = INT_MAX;
    for (int i = 0;i < (1 << n);i++) {
        int res = 0;
        for (int u = 1;u <= n;u++) {
            for (auto v : a[u]) {
                if (((i >> (u - 1)) & 1) == ((i >> (v - 1)) & 1)) {
                    res++;
                }
            }
        }
        anss = min(anss, res);
    }
    cout << anss / 2;
    return 0;
}