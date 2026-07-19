#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
    ll pos, ver;
};

ll a[200005], b[200005], t[200005];
pt e[200005];

bool cmp(pt a, pt b) {
    return a.pos < b.pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    t[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        t[i + 1] = (b[i] - t[i]) % m;
        if (t[i + 1] < 0) {
            t[i + 1] += m;
        }
    }
    ll res = 0;
    ll ress = 0;
    int cnts = 0;
    for (int i = 0; i < n; i++) {
        ll c = (t[i] - a[i]) % m;
        if (c < 0) {
            c += m;
        }
        res += c;
        if (i % 2 == 0) {
            ress++;
            ll p = m - c;
            if (p < m) {
                e[cnts++] = {p, -m};
            }
        } else {
            ress--;
            ll p = c + 1;
            if (p < m) {
                e[cnts++] = {p, m};
            }
        }
    }
    sort(e, e + cnts, cmp);
    ll ans = res;
    ll x = 0, i = 0;
    while (i < cnts) {
        ll pos = e[i].pos;
        res += ress * (pos - x);
        ll add = 0;
        while (i < cnts && e[i].pos == pos) {
            add += e[i].ver;
            i++;
        }
        res += add;
        x = pos;
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
