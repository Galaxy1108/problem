#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

using ll = long long;

ll a[300005], b[300005];
ll pa[300005], pb[300005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++) {
        pa[i] = (pa[i - 1] + a[i]) % mod;
    }
    for (int i = 1; i <= m; i++) {
        pb[i] = (pb[i - 1] + b[i]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int idx = upper_bound(b + 1, b + m + 1, a[i]) - b - 1;
        ans = (ans + (a[i] * idx - pb[idx]) % mod + (pb[m] - pb[idx] - a[i] * (m - idx)) % mod) % mod;
    }
    cout << (ans + mod) % mod;
    return 0;
}
