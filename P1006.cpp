#include <bits/stdc++.h>
using namespace std;

int sn[105][105];
long long anss[51][51][51][51];

long long dfs(int a1, int a2, int b1, int b2) {
    if (anss[a1][a2][b1][b2]) {
        return anss[a1][a2][b1][b2];
    }
    if (a1 == 0 && a1 == a2 && a2 == b1 && b1 == b2) {
        return 0;
    }
    if ((a1 == b1 && a2 == b2) || (a1 < 0 || a2 < 0 || b1 < 0 || b2 < 0)) {
        return LLONG_MIN;
    }
    return anss[a1][a2][b1][b2] = max({ dfs(a1 - 1, a2, b1 - 1, b2), dfs(a1 - 1, a2, b1, b2 - 1), dfs(a1, a2 - 1, b1 - 1, b2), dfs(a1, a2 - 1, b1, b2 - 1) }) + sn[a1][a2] + sn[b1][b2];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m;j++) {
            cin >> sn[i][j];
        }
    }
    cout << dfs(n, m - 1, n - 1, m);
}