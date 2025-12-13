#include <bits/stdc++.h>
using namespace std;

vector<int> g[300005];
bool is_black[300005];

queue<int> que;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
    }
    int q;
    cin >> q;
    while (q--) {
        int opt, v;
        cin >> opt >> v;
        if (opt == 2) {
            cout << (is_black[v] ? "Yes\n" : "No\n");
        } else {
            que.push(v);
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                if (is_black[u]) {
                    continue;
                }
                is_black[u] = true;
                for (int to : g[u]) {
                    que.push(to);
                }
            }
        }
    }
}
