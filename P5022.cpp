#include <bits/stdc++.h>
using namespace std;

set<int> a[5005];
bool vis[5005];
int tops;
int ans[5005], anss[5005];

int c, d;

void dfs(int u) {
    ans[++tops] = u;
    for (auto v : a[u]) {
        if (vis[v] || (u == c && v == d) || (u == d && v == c)) {
            continue;
        }
        vis[v] = true;
        dfs(v);
    }
}

int us[5005], vs[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
        us[i] = u, vs[i] = v;
    }
    c = 0, d = 0;
    if (m == n - 1) {
        vis[1] = true;
        dfs(1);
        for (int i = 1;i <= n;i++) {
            cout << ans[i] << ' ';
        }
        return 0;
    }
    anss[1] = INT_MAX;
    for (int i = 1;i <= m;i++) {
        c = us[i], d = vs[i];
        tops = 0;
        for (int j = 1;j <= n;j++) {
            vis[j] = false;
        }
        vis[1] = true;
        dfs(1);
        if (tops != n) {
            continue;
        }
        bool flag = false;
        for (int j = 1;j <= n;j++) {
            if (anss[j] < ans[j]) {
                flag = false;
                break;
            }
            if (anss[j] > ans[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        for (int j = 1;j <= n;j++) {
            anss[j] = ans[j];
        }
    }
    for (int i = 1;i <= n;i++) {
        cout << anss[i] << ' ';
    }
    return 0;
}