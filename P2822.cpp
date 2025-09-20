#include <bits/stdc++.h>
using namespace std;

int C[2005][2005];
int anss[2005][2005];
int ns[2005], ms[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k;
    cin >> t >> k;
    int maxn = 0;
    for (int i = 0; i < t;i++) {
        cin >> ns[i] >> ms[i];
        maxn = max(maxn, ns[i]);
    }
    for (int i = 0; i <= maxn;i++) {
        for (int j = 0; j <= i;j++) {
            if (i == 0 || j == 0 || i == j) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
            }
        }
    }
    for (int i = 0; i <= maxn;i++) {
        for (int j = 0; j <= i;j++) {
            anss[i][j] = anss[i - 1][j] + anss[i][j - 1] - anss[i - 1][j - 1] + (!C[i][j]);
        }
        anss[i][i + 1] = anss[i][i];
    }
    for (int i = 0; i < t;i++) {
        cout << anss[ns[i]][min(ns[i], ms[i])] << '\n';
    }
    return 0;
}