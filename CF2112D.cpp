#include <bits/stdc++.h>
using namespace std;

vector<int> a[200005];
int in[200005];
int s;

void calc2(int u, int f, int d, bool ss) {
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        calc2(v, u, d + 1, (ss | (s == u)));
        bool iis_s = (ss | (s == u));
        if ((d + iis_s) % 2) {
            cout << u << ' ' << v << '\n';
        }
        if ((d + iis_s) % 2 == 0) {
            cout << v << ' ' << u << '\n';
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0;i <= n;i++) {
            a[i].clear();
            in[i] = 0;
        }
        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            a[u].emplace_back(v);
            a[v].emplace_back(u);
            in[u]++, in[v]++;
        }
        s = -1;
        for (int i = 1;i <= n;i++) {
            if (in[i] == 2) {
                s = i;
                break;
            }
        }
        if (s == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (s == 1) {
            calc2(2, 0, 0, false);
        } else {
            calc2(1, 0, 0, false);
        }
    }
}