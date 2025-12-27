#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll v[4];
    node() {
        for (int i = 0; i < 4; i++) {
            v[i] = -INT_MIN;
        }
    }
};

pair<ll, ll> a[200005];

node seg[800005];

node merge_node(node a, node b) {
    node c;
    for (int i = 0; i < 4; i++) {
        c.v[i] = max(a.v[i], b.v[i]);
    }
    return c;
}

void build(int idx, int l, int r) {
    if (l == r) {
        node no;
        ll x = a[l].first, y = a[l].second;
        no.v[0] = x + y;
        no.v[1] = x - y;
        no.v[2] = -x + y;
        no.v[3] = -x - y;
        seg[idx] = no;
        return;
    }
    int mid = (l + r) >> 1;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    seg[idx] = merge_node(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int idx, int l, int r, int pos, ll x, ll y) {
    if (l == r) {
        node tnode;
        tnode.v[0] = x + y;
        tnode.v[1] = x - y;
        tnode.v[2] = -x + y;
        tnode.v[3] = -x - y;
        seg[idx] = tnode;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(idx * 2, l, mid, pos, x, y);
    } else {
        update(idx * 2 + 1, mid + 1, r, pos, x, y);
    }
    seg[idx] = merge_node(seg[idx * 2], seg[idx * 2 + 1]);
}

node query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[idx];
    }
    int mid = (l + r) / 2;
    if (qr <= mid) {
        return query(idx * 2, l, mid, ql, qr);
    }
    if (ql > mid) {
        return query(idx * 2 + 1, mid + 1, r, ql, qr);
    }
    node left = query(idx * 2, l, mid, ql, qr);
    node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
    return merge_node(left, right);
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        a[i] = { xi, yi };
    }
    for (int i = 1;i <= 4 * n + 5;i++) {
        seg[i] = node();
    }
    build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            ll x, y;
            cin >> i >> x >> y;
            a[i] = { x, y };
            update(1, 1, n, i, x, y);
        } else if (type == 2) {
            int l, r;
            ll x, y;
            cin >> l >> r >> x >> y;
            node res = query(1, 1, n, l, r);
            ll t[4];
            t[0] = x + y;
            t[1] = x - y;
            t[2] = -x + y;
            t[3] = -x - y;
            ll ans = INT_MIN;
            for (int k = 0; k < 4; k++) {
                ans = max(ans, res.v[k] - t[k]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
