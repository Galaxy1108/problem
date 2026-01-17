#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge_t{
    ll v, w;
};

struct path_t {
    ll u, w, l;
};

vector<edge_t> g[200005];
queue<path_t> q;

bool tag[200005];

int main() {
    ll n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    for (int i = 1;i <= m;i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    q.push({ 1, 0, 0 });
    while(!q.empty()) {
        path_t p = q.front();
        q.pop();
        if (p.l == l) {
            if (s <= p.w) {
                tag[p.u] = true;
            }
            continue;
        }
        for (auto e : g[p.u]) {
            if (p.w + e.w > t) {
                continue;
            }
            q.push({ e.v, p.w + e.w, p.l + 1 });
        }
    }
    for (int i = 1;i <= n;i++) {
        if (tag[i]) {
            cout << i << ' ';
        }
    }
}
