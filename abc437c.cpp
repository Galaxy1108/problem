#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll w[300005], p[300005];
pair<ll, ll> a[300005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> w[i] >> p[i];
            a[i] = { w[i] + p[i], i };
        }
        sort(a + 1, a + n + 1);
        ll psum = 0;
        for (int i = 1;i <= n;i++) {
            psum += p[i];
        }
        ll sum = 0;
        int ans = 0;
        for (int i = 1;i <= n;i++) {
            int idx = a[i].second;
            if (sum + (w[idx] + p[idx]) <= psum) {
                sum += (w[idx] + p[idx]);
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
}
