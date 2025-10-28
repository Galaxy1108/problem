#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

bitset<1005> to[1005], from[1005], ans, res;
vector<int> p1[1005], p2[1005];
int in_p1[1005], in_p2[1005];
queue<int> q;

int main() {
    int d, m, n;
    cin >> d >> m >> n;
    for (int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        p1[a].emplace_back(b);
        p2[b].emplace_back(a);
        in_p1[b]++, in_p2[a]++;
    }
    for (int i = 1;i <= n;i++) {
        int s;
        cin >> s;
        ans.set(s);
    }
    for (int i = 1;i <= d;i++) {
        to[i].set(i);
        from[i].set(i);
        if (!in_p1[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : p1[u]) {
            from[v] &= from[u];
            if (!--in_p1[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 1;i <= d;i++) {
        if (!in_p2[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();

        q.pop();
        for (auto v : p2[u]) {
            to[v] |= to[u];
            if (!--in_p2[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 1;i <= d;i++) {
        to[i] |= from[i];
    }
    while () {
        ans |= res;
        res.reset();

    }
}
