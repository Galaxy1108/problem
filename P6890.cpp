/*
P6890 [CEOI 2006] Link
场上一分没有
这题是 shit 吗...
多测没清空，校内 OJ 只有 60
这下老实了
*/

#include <bits/stdc++.h>
using namespace std;

#define cyci(a) cyc_s[p][cyc_size - a]

bool is_cyc[500005];
int vis[500005];
int in[500005], nxt[500005];
int dis[500005];
int cyc_top;
int is_canto[500005];
int cantto[500005];
vector<int> cyc_s[500005];

queue<int> q;

int I;
bool is_found;

void find_cyc(int x) {
    if (vis[x] == I) {
        is_cyc[x] = true;
        cyc_s[++cyc_top].emplace_back(x);
        return;
    }
    vis[x] = I;
    int y = nxt[x];
    if (vis[y] != 0 && vis[y] != I) {
        return;
    }
    find_cyc(y);
    if (is_cyc[x]) {
        is_found = true;
        return;
    }
    if (is_cyc[y] && !is_found) {
        is_cyc[x] = true;
        cyc_s[cyc_top].emplace_back(x);
        return;
    }
}

int main() {
    // int id;
    // cin >> id;
    // int T;
    // cin >> T;
    // while (T--) {
        int n, k;
        cin >> n >> k;
        // for (int i = 1;i <= cyc_top;i++) {
        //     cyc_s[i].clear();
        // }
        // cyc_top = 0;
        // I = 0;
        // for (int i = 1;i <= n;i++) {
        //     in[i] = 0;
        //     vis[i] = 0;
        //     is_cyc[i] = false;
        //     nxt[i] = 0;
        // }
        for (int i = 1;i <= n;i++) {
            int x, y;
            cin >> x >> y;
            nxt[x] = y;
            in[y] += (x != y);
        }
        for (int i = 1;i <= n;i++) {
            if (vis[i]) {
                continue;
            }
            I++;
            is_found = false;
            find_cyc(i);
        }
        for (int i = 1;i <= n;i++) {
            dis[i] = k + 1;
        }
        int anss = 0;
        for (int i = 1;i <= n;i++) {
            if (in[i] == 0 || i == 1) {
                dis[i] = (i != 1);
                anss += (i != 1);
                q.push(i);
            }
        }
        while (!q.empty()) { //处理非环
            int u = q.front();
            q.pop();
            if (dis[u] > k) {
                dis[u] = 1;
                anss++;
            }
            int v = nxt[u];
            dis[v] = min(dis[v], dis[u] + 1);
            in[v]--;
            if (!in[v] && v != 1) {
                q.push(v);
            }
        }
        for (int p = 1;p <= cyc_top;p++) { //分别处理环
            int cyc_size = cyc_s[p].size();
            for (int i = 1;i <= cyc_size;i++) {
                is_canto[i] = 0;
            }
            for (int i = 1;i <= cyc_size;i++) { //处理 K-可达
                int last_n = i + (k - dis[cyci(i)]);
                // cout << dis[cyci(i)] << ' ';
                if (last_n <= cyc_size) {
                    is_canto[i]++;
                    is_canto[last_n + 1]--;
                } else {
                    is_canto[i]++, is_canto[1]++;
                    is_canto[last_n - cyc_size + 1]--;
                }
            }
            for (int i = 1;i <= cyc_size;i++) {
                is_canto[i] = is_canto[i - 1] + is_canto[i];
                // cout << is_canto[i] << ' ';
            }
            int cnt_cntto = 0;
            for (int i = 1;i <= cyc_size;i++) {
                if (!is_canto[i]) {
                    cantto[++cnt_cntto] = i;
                }
            }
            int maxs = min(k, cnt_cntto);
            int cyc_ans = cnt_cntto;
            // cout << anss << ' ' << cnt_cntto << '\n';
            for (int i = 1;i <= maxs;i++) {
                int res = 0;
                for (int j = cantto[i];j < cantto[i] + cyc_size;j++) {
                    int j_mod = (j > cyc_size) ? (j - cyc_size) : j;
                    if (!is_canto[j_mod]) {
                        res++;
                        j += k - 1;
                    }
                }
                cyc_ans = min(cyc_ans, res);
            }
            anss += cyc_ans;
        }
        cout << anss << '\n';
    // }
    return 0;
}