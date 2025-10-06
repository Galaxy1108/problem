/**
 * @par problem
 * 【模板】动态开点线段树
 */

#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

#define lch(a) a->l_ch
#define rch(a) a->r_ch
#define sum(a) a->sums
#define tag(a) a->tags

#define add_tag(node,l,r,tags) \
    sum(node) += ((r) - (l) + 1) * (tags); \
    tag(node) += (tags)
#define push_up(node) \
    sum(node) = sum(lch(node)) + sum(rch(node))

struct node_t {
    node_t* l_ch = nullptr, * r_ch = nullptr;
    ll sums = 0, tags = 0;
};

node_t root;

void push_down(node_t* node, ll l, ll r) {
    ll mid = (l + r) / 2;
    add_tag(lch(node), l, mid, tag(node));
    add_tag(rch(node), mid + 1, r, tag(node));
    tag(node) = 0;
}

void add(node_t* node, ll tl, ll tr, ll& l, ll& r, ll& num) {
    if (tr < l || tl > r) {
        return;
    }
    if (tl >= l && tr <= r) {
        add_tag(node, tl, tr, num);
        return;
    }
    ll mid = (tl + tr) / 2;
    if (lch(node) == nullptr) lch(node) = new node_t;
    if (rch(node) == nullptr) rch(node) = new node_t;
    push_down(node, tl, tr);
    add(lch(node), tl, mid, l, r, num);
    add(rch(node), mid + 1, tr, l, r, num);
    push_up(node);
}

ll query(node_t* node, ll tl, ll tr, ll& l, ll& r) {
    if (tr < l || tl > r) {
        return 0;
    }
    if (tl >= l && tr <= r) {
        return sum(node);
    }
    ll mid = (tl + tr) / 2;
    if (lch(node) == nullptr) lch(node) = new node_t;
    if (rch(node) == nullptr) rch(node) = new node_t;
    push_down(node, tl, tr);
    return query(lch(node), tl, mid, l, r) + query(rch(node), mid + 1, tr, l, r);
}

int main() {
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll opt;
        cin >> opt;
        if (opt == 1) {
            ll l, r, k;
            cin >> l >> r >> k;
            add(&root, 1, n, l, r, k);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << query(&root, 1, n, l, r) + (ll)(r - l + 1) * (l + r) / 2 << '\n';
        }
    }
}