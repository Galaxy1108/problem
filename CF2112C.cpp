#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[5005];

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (ll i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, [](ll a, ll b) {
            return a < b;
        });
        ll anss = 0;
        for (ll i = n;i >= 1;i--) {
            for (ll j = i - 1;j >= 1;j--) {
                ll idx = 0;
                if (a[n] >= 2 * a[i]) {
                    idx = upper_bound(a + 1, a + 1 + n, a[n] - a[i] - a[j]) - a;
                } else {
                    idx = upper_bound(a + 1, a + 1 + n, a[i] - a[j]) - a;
                }
                
                if (idx >= j) {
                    continue;
                }
                // cout << a[i] - a[j] << ' ' << i << ' ' << j << ' ' << idx << ' ' << (idx >= j) << endl;
                anss += j - idx;
            }
        }
        cout << anss << '\n';
    }
}