#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a[300005];

int main() {
    ll n, t;
    cin >> n >> t;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 0, ans = 0;
    for (ll i = 0; i < n; i++) {
        ll t = a[i];
        if (t < res) {
            continue;
        }
        ans += t - res;
        res = t + 100;
    }
    if (res < t) {
        ans += t - res;
    }
    cout << ans;
    return 0;
}
