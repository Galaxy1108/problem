//i'm *b.

#include <bits/stdc++.h>
using namespace std;

vector<int> a[150005];

int n;

struct s {
    int d, u, v;
};

s anss[150005];
int tops;
int fat[150005];
bool is_used[150005];

struct r {
    int d, u;
    friend bool operator<(r a, r b) {
        return (a.d == b.d ? a.u < b.u : a.d < b.d);
    }
};

r d[150005];

void dfs(int u, int f) {
    fat[u] = f;
    d[u] = { 1,u };
    for (auto v : a[u]) {
        if (v == f || is_used[v]) {
            continue;
        }
        dfs(v, u);
        d[u] = max(d[u], { d[v].d + 1,d[v].u });
    }
}

int roots[150005];

void get_ans(int root) {
    vector<int> p;
    dfs(root, 0);
    s ans;
    ans.u = d[root].u;
    dfs(d[root].u, 0);
    ans.v = d[ans.u].u;
    ans.d = d[ans.u].d;
    int i = ans.v;
    while (i != ans.u) {
        is_used[i] = true;
        i = fat[i];
    }
    is_used[ans.u] = true;
    i = ans.v;
    while (i != ans.u) {
        int heavy_i = i;
        i = fat[i];
        for (auto v : a[i]) {
            if (v == fat[i] || v == heavy_i) {
                continue;
            }
            p.push_back(v);
        }
    }
    if (ans.u < ans.v) {
        swap(ans.u, ans.v);
    }
    anss[++tops] = ans;
    for (auto its : p) {
        get_ans(its);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1;i <= n;i++) {
            a[i].clear();
            is_used[i] = false;
        }
        tops = 0;
        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        get_ans(1);
        sort(anss + 1, anss + 1 + tops, [](s a, s b) {
            return (a.d == b.d ? (a.u == b.u ? a.v > b.v : a.u > b.u) : a.d > b.d);
        });
        for (int i = 1;i <= tops;i++) {
            cout << anss[i].d << " " << anss[i].u << " " << anss[i].v << " ";
        }
        cout << '\n';
    }
}