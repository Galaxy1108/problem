#include <bits/stdc++.h>
using namespace std;

int a[200005];
vector<int> g[200005];
bool vis[200005];

int double_cnt;
unordered_map<int, int> cnt;
bool is_double[200005];

void dfs(int u) {
    vis[u] = true;
    cnt[a[u]]++;
    if (cnt[a[u]] == 2) {
        double_cnt++;
    }
    is_double[u] = (double_cnt > 0);
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    cnt[a[u]]--;
    if (cnt[a[u]] == 1) {
        double_cnt--;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << (is_double[i] ? "Yes" : "No") << '\n';
    }    
    return 0;
}
