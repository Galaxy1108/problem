#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll s1[200005], w1[200005];
ll s2[200005], w2[200005];
vector<ll> g[200005];
queue<ll> q, q1, q2;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        s1[i] = s2[i] = -1;
        w1[i] = w2[i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'S') {
            s1[i] = i;
            w1[i] = 0;
            q.push(i);
            q1.push(i);
            q2.push(0);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        int q1u = q1.front();
        int q2u = q2.front();
        q.pop(), q1.pop(), q2.pop();
        if (!((s1[u] == q1u && w1[u] == q2u) || (s2[u] == q1u && w2[u] == q2u))) {
            continue;
        }
        for (int v : g[u]) {
            bool flag = 0;
            if (s1[v] == q1u) {
                if (q2u + 1 < w1[v]) {
                    w1[v] = q2u + 1;
                    flag = 1;
                }
            } else if (s2[v] == q1u) {
                if (q2u + 1 < w2[v]) {
                    w2[v] = q2u + 1;
                    flag = 1;
                }
            } else if (w1[v] > q2u + 1) {
                s2[v] = s1[v];
                w2[v] = w1[v];
                s1[v] = q1u;
                w1[v] = q2u + 1;
                flag = 1;
            } else if (w2[v] > q2u + 1) {
                s2[v] = q1u;
                w2[v] = q2u + 1;
                flag = 1;
            }
            if (flag) {
                q.push(v);
                q1.push(q1u);
                q2.push(q2u + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'D') {
            cout << w1[i] + w2[i] << '\n';
        }
    }
    return 0;
}
