#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll trr1[500005], trr2[500005];

ll query1(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ans += trr1[i];
    }
    return ans;
}

ll query2(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ans += trr2[i];
    }
    return ans;
}

void add1(int x, ll v) {
    for (int i = x; i <= 500001; i += i & -i) {
        trr1[i] += v;
    }
}

void add2(int x, ll v) {
    for (int i = x; i <= 500001; i += i & -i) {
        trr2[i] += v;
    }
}

int a[500005];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add1(a[i] + 1, 1);
        add2(a[i] + 1, a[i]);
    }
    for (int i = 0;i < q;i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            add1(a[x] + 1, -1);
            add2(a[x] + 1, -a[x]);
            a[x] = y;
            add1(a[x] + 1, 1);
            add2(a[x] + 1, a[x]);
        } else {
            int l, r;
            cin >> l >> r;
            if (l > r) {
                cout << 1ll * l * n << '\n';
                continue;
            }
            ll ans = query2(r + 1) - query2(l) + (ll)l * query1(l) + (ll)(n - query1(r + 1)) * r;
            cout << ans << '\n';
        }
    }
}
