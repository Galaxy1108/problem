#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll r[300005], h[300005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> r[i];
            h[i] = r[i];
        }
        for (int i = 2;i <= n;i++) {
            h[i] = min(h[i], h[i - 1] + 1);
        }
        for (int i = n - 1;i >= 1;i--) {
            h[i] = min(h[i], h[i + 1] + 1);
        }
        ll ans = 0;
        for (int i = 1;i <= n;i++) {
            ans += r[i] - h[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
