#include <bits/stdc++.h>
using namespace std;

int cnts[400005];
int x[200005], r[200005];
bool vis[400005];
unordered_map<int, int> mp;

vector<int> g[400005];

queue<int> q;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x[i] >> r[i];
        cnts[(i - 1) * 2 + 1] = x[i] - r[i];
        cnts[(i - 1) * 2 + 2] = x[i] + r[i];
    }
    sort(cnts + 1, cnts + 2 * n + 1);
    int sn = unique(cnts + 1, cnts + 2 * n + 1) - (cnts + 1);
    for (int i = 1;i <= sn;i++) {
        mp[cnts[i]] = i;
    }
    for (int i = 1;i <= n;i++) {
        int u = mp[x[i] - r[i]];
        int v = mp[x[i] + r[i]];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1;i <= sn;i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        int V = 1, E = 0;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                E++;
                if (vis[v]) {
                    continue;
                }
                vis[v] = true;
                V++;
                q.push(v);
            }
        }
        E /= 2;
        ans += min(E, V);
    }
    cout << ans << '\n';
}
