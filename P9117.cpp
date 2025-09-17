#include <bits/stdc++.h>
using namespace std;

int color[100005][2];
int idx[100005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            color[i][0] = idx[i][0] = 0;
        }
        for (int i = 1;i <= m;i++) {
            color[i][1] = idx[i][1] = 0;
        }
        while (q--) {
            int opt, x, c;
            cin >> opt >> x >> color[x][opt];
            idx[x][opt] = ++cnt;
        }
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                cout << ((idx[i][0] > idx[j][1]) ? color[i][0] : color[j][1]) << " \n"[j == m];
            }
        }
    }
}