#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[500005], n, m;

void add(int x, int k) {
    for (int i = x;i <= n;i += (i & (-i))) {
        a[i] += k;
    }
}

ll query(int x) {
    ll anss = 0;
    for (int i = x;i > 0;i -= (i & (-i))) {
        anss += a[i];
    }
    return anss;
}

int main() {
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    for (int i = 1;i <= m;i++) {
        int l, r;
        cin >> l >> r;
        add(l, 1), add(r + 1, -1);
    }
    for (int i = 1;i <= n;i++) {
        int x = query(i) % 2;
        // cout << x << endl;
        cout << (x ? t[i] : s[i]);
    }
    return 0;
}