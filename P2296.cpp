#include <bits/stdc++.h>
using namespace std;

vector<int> a[10005];
vector<int> a_[10005];

bool can_to[10005];
queue<int> q;

bool vis[10005];

void dfs(int this_node) {
    if (vis[this_node]) {
        return;
    }
    vis[this_node] = true;
    for (auto next_node : a_[this_node]) {
        dfs(next_node);
    }
}

int dis[10005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a_[v].emplace_back(u);
    }
    int s, t;
    cin >> s >> t;
    dfs(t);
    for (int i = 1; i <= n;i++) {
        can_to[i] = true;
        for (auto outs : a[i]) {
            if (!vis[outs]) {
                can_to[i] = false;
            }
        }
    }
    fill(dis, dis + n + 1, INT_MAX / 2);
    dis[s] = 0;
    q.push(s);
    if (!can_to[s]) {
        cout << -1;
        return 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : a[u]) {
            if (!can_to[v] || dis[u] + 1 >= dis[v]) {
                continue;
            }
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    cout << (dis[t] == INT_MAX / 2 ? -1 : dis[t]);
    return 0;
}