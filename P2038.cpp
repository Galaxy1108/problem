#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int a[200][200];
ll sum[200][200];

int main() {
    int d;
    cin >> d;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x, y, k;
        cin >> x >> y >> k;
        a[x + 1][y + 1] = k;
    }
    for (int i = 1;i <= 129;i++) {
        for (int j = 1;j <= 129;j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    ll maxs = 0, cnts = 0;
    for (int i = 1;i <= 129;i++) {
        for (int j = 1;j <= 129;j++) {
            int x1 = max(1, i - d), y1 = max(1, j - d);
            int x2 = min(129, i + d), y2 = min(129, j + d);
            ll s = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
            if (s > maxs) {
                maxs = s;
                cnts = 1;
            } else if (s == maxs) {
                cnts++;
            }
        }
    }
    cout << cnts << " " << maxs << '\n';
}