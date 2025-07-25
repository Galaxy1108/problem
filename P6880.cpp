#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edges {
    ll v, w, idx;
};

ll s[205][7];
ll last_edge[205];
ll n, m;
vector<edges> mapp[205], f_mapp[205];
bool tags[205], is_key[50005];
ll mapp_l[205][205];
ll mapp_l2[205][205];
ll f_mapp_l[205][205];
int mapp_l_cnt[205][205], f_mapp_l_cnt[205][205];

struct edgess {
    ll u, v, c, d;
};

edgess edge[50005];
bool vis[5005][5005];

void run_dij(ll S, ll maps_l[205][205], ll idx){
    for (int i = 0;i <= n;i++) {
        s[i][idx] = INT_MAX;
    }
    fill(tags, tags + 1 + n, false);
    s[S][idx] = 0;
    ll cnts = n;
    while (cnts--) {
        ll min_node = 0;
        for (int i = 1;i <= n;i++) {
            if (tags[i]) {
                continue;
            }
            if (s[min_node][idx] > s[i][idx]) {
                min_node = i;
            }
        }
        tags[min_node] = true;
        for (int i = 1;i <= n;i++) {
            if (maps_l[min_node][i]==INT_MAX) {
                continue;
            }
            if (s[min_node][idx] + maps_l[min_node][i] < s[i][idx]) {
                s[i][idx] = s[min_node][idx] + maps_l[min_node][i];
            }
        }
    }
}

void build_dij(ll S, vector<edges> maps[205], ll idx) {
    for (int i = 0;i <= n;i++) {
        s[i][idx] = INT_MAX;
    }
    fill(tags, tags + 1 + n, false);
    fill(last_edge, last_edge + 1 + n, 0);
    s[S][idx] = 0;
    ll cnts = n;
    while (cnts--) {
        ll min_node = 0;
        for (int i = 1;i <= n;i++) {
            if (tags[i]) {
                continue;
            }
            if (s[min_node][idx] > s[i][idx]) {
                min_node = i;
            }
        }
        tags[min_node] = true;
        for (auto v : maps[min_node]) {
            if (s[min_node][idx] + v.w < s[v.v][idx]) {
                s[v.v][idx] = s[min_node][idx] + v.w;
                last_edge[v.v] = v.idx;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        is_key[last_edge[i]] = true;
    }
}

int main() {
    // freopen("P6880_5.in", "r", stdin);
    // freopen("P6880.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= n;j++) {
            mapp_l[i][j] = f_mapp_l[i][j] = INT_MAX;
            mapp_l2[i][j] = INT_MAX;
        }
    }
    ll max_idx = 0;
    for (int i = 1;i <= m;i++) {
        ll u, v, c, d;
        cin >> u >> v >> c >> d;
        mapp[u].push_back({ v,c,++max_idx });
        f_mapp[v].push_back({ u,c,max_idx });
        mapp_l_cnt[u][v]++;
        f_mapp_l_cnt[v][u]++;
        if (c < mapp_l[u][v]) {
            mapp_l2[u][v] = mapp_l[u][v];
            mapp_l[u][v] = c;
        } else if (c < mapp_l2[u][v]) {
            mapp_l2[u][v] = c;
        }
        f_mapp_l[v][u] = min(f_mapp_l[v][u], c);
        edge[max_idx] = { u,v,c,d };
    }
    build_dij(1, mapp, 1);
    build_dij(n, mapp, 2);
    build_dij(1, f_mapp, 3);
    build_dij(n, f_mapp, 4);
    // for (int i = 1;i <= max_idx;i++) {
    //     cout << is_key[i] << ' ';
    // }
    // cout << endl;
    ll anss = (s[n][1] != INT_MAX && s[1][2] != INT_MAX ? s[n][1] + s[1][2] : LLONG_MAX);
    for (int i = 1;i <= max_idx;i++) {
        edgess e = edge[i];
        if (is_key[i] && e.c == mapp_l[e.u][e.v] &&!vis[e.u][e.v]) {
            int sx = mapp_l[e.u][e.v], sy = mapp_l[e.v][e.u];
            mapp_l[e.v][e.u] = min(e.c, mapp_l[e.v][e.u]);
            mapp_l[e.u][e.v] = (mapp_l[e.u][e.v] == e.c ? mapp_l2[e.u][e.v] : mapp_l[e.u][e.v]);
            run_dij(1, mapp_l, 5);
            run_dij(n, mapp_l, 6);
            anss = min(anss, (s[n][5] != INT_MAX && s[1][6] != INT_MAX ? s[n][5] + s[1][6] + e.d : LLONG_MAX));
            // cout << (s[n][5] != INT_MAX && s[1][6] != INT_MAX ? s[n][5] + s[1][6] + e.d : LLONG_MAX) <<' '<<1 << '\n';
            mapp_l[e.u][e.v] = sx, mapp_l[e.v][e.u] = sy;
            vis[e.u][e.v] = true;
        } else {
            ll part_1 = min(s[n][1], s[e.v][1] + e.c + s[e.u][4]);
            ll part_2 = min(s[1][2], s[e.v][2] + e.c + s[e.u][3]);
            anss = min(anss, (part_1 != INT_MAX && part_2 != INT_MAX ? e.d + part_1 + part_2 : LLONG_MAX));
            // cout << (part_1 != INT_MAX && part_2 != INT_MAX ? e.d + part_1 + part_2 : LLONG_MAX) << ' '<<2 << '\n';
        }
    }
    cout << (anss == LLONG_MAX ? -1 : anss);
    return 0;
}