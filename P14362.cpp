#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge_t {
    int u, v, w;
};
edge_t ts[1000005], as[1000005];
int c[15], a[15][1000005];

int f[1000005];

int fat(int a) {
    return (a == f[a] ? a : f[a] = fat(f[a]));
}

int main() {
    auto cmp = [](edge_t a, edge_t b) {
        return a.w < b.w;
    };
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        cin >> ts[i].u >> ts[i].v >> ts[i].w;
    }
    sort(ts + 1, ts + 1 + m, cmp);
    for (int i = 1;i <= n;i++) {
        f[i] = i;
    }
    int nsum = 0;
    for (int i = 1;nsum < n - 1 && i <= m;i++) {
        int fata = fat(ts[i].u), fatb = fat(ts[i].v);
        if (fata != fatb) {
            f[fata] = fatb;
            as[++nsum] = ts[i];
        }
    }
    for (int i = 1;i <= k;i++) {
        cin >> c[i];
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
            as[++nsum] = { n + i,j,a[i][j] };
        }
    }
    sort(as + 1, as + 1 + nsum, cmp);
    ll ans = LLONG_MAX;
    for (int s = 0;s < (1 << k);s++) {
        int np = n + __builtin_popcount(s);
        ll res = 0;
        for (int i = 1;i <= k;i++) {
            res += !!(s & (1 << (i - 1))) * c[i];
        }
        for (int i = 1;i <= n + k;i++) {
            f[i] = i;
        }
        for (int i = 1, cnt = 0;cnt < np - 1 && i <= nsum;i++) {
            if (as[i].u >= n + 1 && !(s & (1 << (as[i].u - n - 1)))) {
                continue;
            }
            int fata = fat(as[i].u), fatb = fat(as[i].v);
            if (fata != fatb) {
                f[fata] = fatb;
                res += as[i].w;
                cnt++;
            }
        }
        ans = min(ans, res);
    }
    cout << ans;
}
