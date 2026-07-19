// 【模板】可持久化线段树
#include <bits/stdc++.h>
using namespace std;

int roots[200005];

struct node{
    int l, r;
    long long var;
} trees[40000005];

int cnt;

void get_node_var(int this_node) {
    trees[this_node].var = trees[trees[this_node].l].var + trees[trees[this_node].r].var;
}

int build(int l, int r) {
    if (l == r) {
        ++cnt;
        trees[cnt].var = 0;
        return cnt;
    }
    int mid = (l + r) / 2, this_cnt = ++cnt;
    trees[this_cnt].l = build(l, mid);
    trees[this_cnt].r = build(mid + 1, r);
    trees[this_cnt].var = 0;
    return this_cnt;
}

int copy_node(int copy_nodes) {
    int this_cnt = ++cnt;
    trees[this_cnt] = trees[copy_nodes];
    return this_cnt;
}

int new_node(int l,int r,long long var){
    trees[++cnt] = { l, r, var };
    return cnt;
}

int upd_data(int pos, long long val, int this_node, int l, int r) {
    if (l == r) {
        return new_node(-1, -1, val);
    }
    int c_node_cnt = copy_node(this_node);
    int mid = (l + r) / 2;
    if (mid >= pos) {
        trees[c_node_cnt].l = upd_data(pos, val, trees[this_node].l, l, mid);
    } else {
        trees[c_node_cnt].r = upd_data(pos, val, trees[this_node].r, mid + 1, r);
    }
    get_node_var(c_node_cnt);
    return c_node_cnt;
}

long long query_data(int this_node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return trees[this_node].var;
    }
    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid) {
        res += query_data(trees[this_node].l, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query_data(trees[this_node].r, mid + 1, r, ql, qr);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int root0 = build(1, m);
    for (int i = 1;i <= n;i++) {
        roots[i] = root0;
    }
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int x, y;
            cin >> x >> y;
            roots[x] = roots[y];
        }
        if(op==2){
            int x, y;
            long long z;
            cin >> x >> y >> z;
            roots[x] = upd_data(y, z, roots[x], 1, m);
        }
        if(op==3){
            int x, l, r;
            cin >> x >> l >> r;
            cout << query_data(roots[x], 1, m, l, r) << '\n';
        }
    }
    return 0;
}
