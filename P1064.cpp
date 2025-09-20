#include <bits/stdc++.h>
using namespace std;

struct baf {
    int jg, jz;
    int fjg[2], fjz[2];
    int fcnt;
} sn[30005];

int cnt = 0;
long long fss[30005][65];

long long dfs(int n, int m) {
    if (m <= 0 || n <= 0) {
        return 0;
    }
    if (fss[n][m]) {
        return fss[n][m];
    }
    long long maxs = 0;
    maxs = max(maxs, dfs(n, m - 1));
    if (sn[m].jg <= n) {
        maxs = max(maxs, dfs(n - sn[m].jg, m - 1) + sn[m].jz);
    }
    if (sn[m].fcnt >= 1 && sn[m].jg + sn[m].fjg[0] <= n) {
        maxs = max(maxs, dfs(n - sn[m].jg - sn[m].fjg[0], m - 1) + sn[m].jz + sn[m].fjz[0]);
    }
    if (sn[m].fcnt >= 2 && sn[m].jg + sn[m].fjg[0] + sn[m].fjg[1] <= n) {
        maxs = max(maxs, dfs(n - sn[m].jg - sn[m].fjg[0] - sn[m].fjg[0], m - 1) + sn[m].jz + sn[m].fjz[0] + sn[m].fjz[1]);
    }
    return fss[n][m] = maxs;
}

int main() {
    //    freopen("budget.in", "r", stdin);
        //freopen("budget.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int v, p, q;
    for (int i = 0; i < m;i++) {
        cin >> v >> p >> q;
        if (q == 0) {
            sn[cnt].jg = v;
            sn[cnt++].jz = v * p;
        }
        if (q == 1) {
            sn[q - 1].fjg[sn[q - 1].fcnt] = v;
            sn[q - 1].fjz[sn[q - 1].fcnt++] = v * p;
        }
    }
    cout << dfs(n, cnt - 1);
}