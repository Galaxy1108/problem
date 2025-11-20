/**
 * problem: I Yearned For The Mines
 * link: https://codeforces.com/problemset/problem/2133/E
 * contest: https://vjudge.net/contest/768289 (强化训练VP 1) 
 * difficult: *2500 (blue)
 * date: 2025/11/20 周四 19:33
 * tags: #构造 #贪心
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> trr[200005];
int siz[200005];
bool del[200005];
int nxt[200005], fat[200005], tag[200005];
int st[200005], stcnt;
int in[200005];

int k;

void dfs1(int u, int f) {
    siz[u] = 1;
    int a1 = 0, a2 = 0;
    for (int v : trr[u]) {
        if (v == f) {
            continue;
        }
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[u] >= 4) {
            del[u] = true;
            siz[u] = 0;
        }
        if (!del[v]) {
            a2 = (a1 ? v : 0);
            a1 = (a1 ? a1 : v);
        } else {
            in[u]--;
        }
        fat[v] = u;
    }
    if (in[u] <= 1 && !del[u]) {
        st[++stcnt] = u;
    }
    nxt[a1] = a2;
    nxt[a2] = a1;
    if (del[u]) {
        k++;
        for (int v : trr[u]) {
            if (v == f) {
                continue;
            }
            in[v]--;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            trr[i].clear();
            siz[i] = nxt[i] = fat[i] = st[i] = in[i] = tag[i] = 0;
            del[i] = false;
        }
        stcnt = 0;
        k = 0;
        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            trr[u].push_back(v);
            trr[v].push_back(u);
            in[u]++;
            in[v]++;
        }
        dfs1(1, 0);
        cout << n + k << '\n';
        for (int i = 1;i <= n;i++) {
            if (del[i]) {
                cout << 2 << ' ' << i << '\n';
            }
        }
        for (int i = 1;i <= n;i++) {
            if (del[i]) {
                cout << 1 << ' ' << i << '\n';
            }
        }
        for (int u = 1;u <= stcnt;u++) {
            int i = st[u];
            if (tag[i]) {
                continue;
            }
            cout << 1 << ' ' << i << '\n';
            tag[i] = true;
            if (del[fat[i]] || !fat[i]) {
                continue;
            }
            cout << 1 << ' ' << fat[i] << '\n';
            tag[fat[i]] = true;
            if (del[fat[fat[i]]] || !fat[fat[i]]) {
                if (del[nxt[i]] || !nxt[i]) {
                    continue;
                }
                cout << 1 << ' ' << nxt[i] << '\n';
                tag[nxt[i]] = true;
            } else {
                cout << 1 << ' ' << fat[fat[i]] << '\n';
                tag[fat[fat[i]]] = true;
            }
        }
    }
}
