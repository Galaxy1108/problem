#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct s {
    ll a, b;
};
s sn[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 1;i <= n;i++) {
            cin >> sn[i].a;
        }
        for (ll i = 1;i <= n;i++) {
            cin >> sn[i].b;
        }
        for (ll i = 1;i <= n;i++) {
            if (sn[i].a > sn[i].b) {
                swap(sn[i].a, sn[i].b);
            }
        }
        sort(sn + 1, sn + 1 + n, [](s a, s b) {
            return (a.a == b.a ? a.b > b.b : a.a < b.a);
        });
        ll anss = 0;
        for (ll i = 1;i <= n;i++) {
            anss += abs(sn[i].a - sn[i].b);
        }
        bool flag = true;
        ll mas = LLONG_MAX;
        for (ll i = 1;i < n;i++) {
            ll a = sn[i].a, b = sn[i].b, c = sn[i + 1].a, d = sn[i + 1].b;
            ll max = (abs(a - b) + abs(c - d), abs(a - c) + abs(b - d), abs(a - d) + abs(b - c));
            ll res = (abs(a - b) + abs(c - d));
            if (max == res) {
                cout << anss << '\n';
                flag = false;
                break;
            }
            mas = min(mas, max - res);
        }
        if (flag) {
            cout << anss + mas << '\n';
        }
    }
}