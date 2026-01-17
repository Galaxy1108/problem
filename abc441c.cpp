#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll sum = 0;
    for (int i = k;i >= 1;i--) {
        sum += a[i];
        if(sum >= x) {
            cout << n - i + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}
