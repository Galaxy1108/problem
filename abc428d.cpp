#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll pow10[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll c, d;
        cin >> c >> d;
        ll ans = 0;
        for (int k = 1; k <= 10; k++) {
            ll l = max(pow10[k - 1], c + 1);
            ll r = min(pow10[k] - 1, c + d);
            if (l > r) {
                continue;
            }
            l = c * pow10[k] + l;
            r = c * pow10[k] + r;
            ll sqrt_l = sqrtl(l);
            if (sqrt_l * sqrt_l < l) {
                sqrt_l++;
            }
            ll sqrt_r = sqrtl(r);
            if (sqrt_l <= sqrt_r) {
                ans += (sqrt_r - sqrt_l + 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
