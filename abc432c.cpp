#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200005], d[200005];

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll mod = (y - x) / __gcd(x, y - x);
    for (int i = 1; i < n; i++) {
        if (a[i] % mod != a[0] % mod) {
            cout << -1;
            return 0;
        }
    }
    ll r = (a[0] * x) % (y - x);
    if (r < 0) {
        r += y - x;
    }
    for (int i = 0; i < n; i++) {
        d[i] = (a[i] * x - r) / (y - x);
    }
    ll l = d[0], u = d[0] + a[0];
    for (int i = 1; i < n; i++) {
        if (d[i] > l) {
            l = d[i];
        }
        if (d[i] + a[i] < u) {
            u = d[i] + a[i];
        }
    }
    if (l > u) {
        cout << -1;
        return 0;
    }
    ll anss = 0;
    for (int i = 0; i < n; i++) {
        anss += (u - d[i]);
    }
    cout << anss;
    return 0;
}
