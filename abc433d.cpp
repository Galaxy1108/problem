#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[200005];
unordered_map<ll, ll> mp[11];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        int dig = 0, tmp = a[i];
        while (tmp) {
            dig++;
            tmp /= 10;
        }
        mp[dig][a[i] % m]++;
    }
    ll ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int jdig = 1;jdig <= 10;jdig++) {
            ll di = a[i];
            for (int k = 1;k <= jdig;k++) {
                di = (di * 10) % m;
            }
            ans += mp[jdig][(m - di) % m];
        }
    }
    cout << ans;
}
