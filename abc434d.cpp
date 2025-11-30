#include <bits/stdc++.h>
using namespace std;

int cnt[2002][2002];
int cnt1[2002][2002];
int u[200005], d[200005], l[200005], r[200005];
int cnt0;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> u[i] >> d[i] >> l[i] >> r[i];
        cnt[u[i]][l[i]]++;
        cnt[u[i]][r[i] + 1]--;
        cnt[d[i] + 1][l[i]]--;
        cnt[d[i] + 1][r[i] + 1]++;
    }
    for (int i = 1;i <= 2000;i++) {
        for (int j = 1;j <= 2000;j++) {
            cnt[i][j] = (cnt[i][j] + cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1]);
            if (cnt[i][j] == 1) {
                cnt1[i][j] = 1;
            }
            if (cnt[i][j] == 0) {
                cnt0++;
            }
        }
    }
    for (int i = 1;i <= 2000;i++) {
        for (int j = 1;j <= 2000;j++) {
            cnt1[i][j] = (cnt1[i][j] + cnt1[i][j - 1] + cnt1[i - 1][j] - cnt1[i - 1][j - 1]);
        }
    }
    for (int k = 1;k <= n;k++) {
        int ans = cnt0 + cnt1[d[k]][r[k]] - cnt1[u[k] - 1][r[k]] - cnt1[d[k]][l[k] - 1] + cnt1[u[k] - 1][l[k] - 1];
        cout << ans << '\n';
    }
}
