#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dpl[1005][50005];
ll dpr[1005][50005];
ll p[1005], v[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> p[i] >> v[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int w = 0;w <= m;w++) {
            dpl[i][w] = dpl[i - 1][w];
            if (w >= p[i]) {
                dpl[i][w] = max(dpl[i][w], dpl[i - 1][w - p[i]] + v[i]);
            }
        }
    }
    for (int i = n;i >= 1;i--) {
        for (int w = 0;w <= m;w++) {
            dpr[i][w] = dpr[i + 1][w];
            if (w >= p[i]) {
                dpr[i][w] = max(dpr[i][w], dpr[i + 1][w - p[i]] + v[i]);
            }
        }
    }
    ll maxv = 0;
    for (int w = 0;w <= m;w++) {
        maxv = max(maxv, dpl[n][w]);
    }
    for (int i = 1;i <= n;i++) {
        bool canc = true;
        for (int t = 0;t <= m;t++) {
            if (dpl[i - 1][t] + dpr[i + 1][m - t] == maxv) {
                canc = false;
                break;
            }
        }
        bool cannc = false;
        for (int t = 0;t + p[i] <= m;t++) {
            if (dpl[i - 1][t] + v[i] + dpr[i + 1][m - t - p[i]] == maxv) {
                cannc = true;
                break;
            }
        }
        if (cannc && canc) {
            cout << 'A';
        } else if (cannc && !canc) {
            cout << 'B';
        } else {
            cout << 'C';
        }
    }
}
