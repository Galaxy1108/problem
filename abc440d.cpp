#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[300005];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll l = x, r = x + y + n;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll cntl = lower_bound(a + 1, a + n + 1, x) - a - 1;
            ll cntm = upper_bound(a + 1, a + n + 1, mid) - a - 1;
            if ((mid - x + 1) - (cntm - cntl) >= y) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}
