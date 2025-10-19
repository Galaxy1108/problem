#include <bits/stdc++.h>
using namespace std;

vector<int> p[500005];
int dis_s[500005], dis_t[500005];
struct sp {
    int u, d;
};
queue<sp> q;

int mx = 0, id = 0;

void dfs(int u, int f, int d) {
    if (d == mx && u > id) {
        id = u;
    }
    if (d > mx) {
        mx = d;
        id = u;
    }
    for (auto v : p[u]) {
        if (v == f) {
            continue;
        }
        dfs(v, u, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    dfs(1, -1, 0);
    int s = id;
    mx = 0, id = 0;
    dfs(s, -1, 0);
    int t = id;
    q.push({ s, 0 });
    dis_s[s] = 0;
    while (!q.empty()) {
        sp u = q.front();
        q.pop();
        for (auto v : p[u.u]) {
            if (dis_s[v] == 0 && v != s) {
                dis_s[v] = u.d + 1;
                q.push({ v, u.d + 1 });
            }
        }
    }
    q.push({ t, 0 });
    dis_t[t] = 0;
    while (!q.empty()) {
        sp u = q.front();
        q.pop();
        for (auto v : p[u.u]) {
            if (dis_t[v] == 0 && v != t) {
                dis_t[v] = u.d + 1;
                q.push({ v, u.d + 1 });
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << (dis_t[i] > dis_s[i] || (dis_t[i] == dis_s[i] && t > s) ? t : s) << '\n';
    }
}
