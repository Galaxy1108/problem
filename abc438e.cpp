#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[200005];
ll nxt[200005][32], cost[200005][32];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        nxt[i][0] = a[i];
        cost[i][0] = i;
    }
    for (int j = 1;j < 32;j++) {
        for (int i = 1;i <= n;i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            cost[i][j] = cost[i][j - 1] + cost[nxt[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        ll t, b;
        cin >> t >> b;
        ll ans = 0;
        for (int j = 0;j < 32;j++) {
            if (t & (1ll << j)) {
                ans += cost[b][j];
                b = nxt[b][j];
            }
        }
        cout << ans << '\n';
    }
}
