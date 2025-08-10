#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a[300005];
ll ans[1000005];

int main() {
    ll n, q;
    cin >> n >> q;
    ll max_b = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        max_b = max(max_b, a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll this_idx = 1;
    for (int i = 1;i <= max_b;i++) {
        ans[i] = ans[i - 1] + (n - this_idx + 1);
        while (this_idx <= n && a[this_idx] <= i) {
            this_idx++;
        }
    }
    while (q--) {
        ll b;
        cin >> b;
        cout << (b > max_b ? -1 : ans[b - 1] + 1) << '\n';
    }
}