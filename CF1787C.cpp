#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[200005][2], a[200005], minx[200005], maxx[200005];

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n, s;
        cin >> n >> s;
        for (int i = 0;i <= n;i++) {
            f[i][0] = f[i][1] = 0;
        }
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (i == 1 || i == n) {
                continue;
            }
            if (2 * s <= a[i]) {
                minx[i] = s;
                maxx[i] = a[i] - s;
            } else {
                minx[i] = min(a[i], s);
                maxx[i] = a[i] - min(a[i], s);
            }
        }
        maxx[1] = minx[1] = a[1];
        maxx[n] = minx[n] = a[n];
        for (int i = 2;i <= n;i++) {
            f[i][0] = min(f[i - 1][0] + minx[i - 1] * maxx[i], f[i - 1][1] + maxx[i - 1] * maxx[i]);
            f[i][1] = min(f[i - 1][0] + minx[i - 1] * minx[i], f[i - 1][1] + maxx[i - 1] * minx[i]);
        }
        cout << min(f[n][0], f[n][1]) << '\n';
    }
}