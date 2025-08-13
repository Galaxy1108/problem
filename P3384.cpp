#include <bits/stdc++.h>
using namespace std;

vector<int> a[100005];

struct node {
    int weight;        // 子树大小
    int father;        // 父节点
    int deep;          // 节点深度
    int heavy_chil;    // 重儿子节点
    int chain_top;     // 链顶节点
    int dfso;          // 节点的DFS序（节点子树的dfs序左端点）
    int dfso_end;      // 节点子树的dfs序右端点
} nodes[100005];       // 全局节点数组

int dfso_node[100005];

long long snt[100005], sn[100005], d[400005], seg_tree[400005];
int n, m, r, p;

enum class seg_rel{
    inc,
    past_inc,
    non_inc
};

struct seg{
    long long l, r;
    bool is_node(){
        return l == r;
    }
    long long size(){
        return r - l + 1;
    }
    seg l_seg(){
        return {l, (l + r) / 2};
    }
    seg r_seg(){
        return {(l + r) / 2 + 1, r};
    }
};

long long l_idx(long long idx){
    return 2 * idx;
}

long long r_idx(long long idx){
    return 2 * idx + 1;
}

seg_rel rela_b(seg a,seg b){
    if(a.l<=b.l && a.r>=b.r){
        return seg_rel::inc;
    }
    if(a.r<b.l || a.l>b.r){
        return seg_rel::non_inc;
    }
    return seg_rel::past_inc;
}

void cout_trees(seg this_seg,long long idx){
    cout << seg_tree[idx] << ' ' << d[idx] << " [" << this_seg.l << ',' << this_seg.r << "]-" << idx << '\n';
    if(this_seg.is_node()){
        return;
    }
    cout_trees(this_seg.l_seg(), l_idx(idx));
    cout_trees(this_seg.r_seg(), r_idx(idx));
}

void add(seg add_seg,long long add_num,long long idx){
    seg_tree[idx] += add_seg.size() * add_num;
    d[idx] += add_num;
}

void push_up(long long idx){
    seg_tree[idx] = seg_tree[l_idx(idx)] + seg_tree[r_idx(idx)];
}

void push_down(seg down_seg,long long idx){
    add(down_seg.l_seg(), d[idx], l_idx(idx));
    add(down_seg.r_seg(), d[idx], r_idx(idx));
    d[idx] = 0;
}

void build(seg this_seg={1,n},long long idx=1){
    if(this_seg.is_node()){
        seg_tree[idx] = sn[this_seg.l];
        return;
    }
    build(this_seg.l_seg(), l_idx(idx));
    build(this_seg.r_seg(), r_idx(idx));
    push_up(idx);
}

long long seg_query(seg query_seg,seg this_seg={1,n},long long idx=1){
    // cout_trees({1, n}, 1);
    seg_rel rel = rela_b(query_seg, this_seg);
    switch(rel){
        case seg_rel::inc:
            return seg_tree[idx];
        case seg_rel::non_inc:
            return 0;
        case seg_rel::past_inc:
            push_down(this_seg, idx);
            return seg_query(query_seg, this_seg.l_seg(), l_idx(idx))+ 
                   seg_query(query_seg, this_seg.r_seg(), r_idx(idx));
    }
    exit(-1);
    return 0;
}

void seg_add(seg add_seg,long long add_num,seg this_seg={1,n},long long idx=1){
    seg_rel rel = rela_b(add_seg, this_seg);
    switch(rel){
        case seg_rel::inc:
            add(this_seg, add_num, idx);
            return;
        case seg_rel::non_inc:
            return;
        case seg_rel::past_inc:
            push_down(this_seg, idx);
            seg_add(add_seg, add_num, this_seg.l_seg(), l_idx(idx));
            seg_add(add_seg, add_num, this_seg.r_seg(), r_idx(idx));
            push_up(idx);
            return;
    }
}

bool updata_big(int& comp_old, int comp_new, int& cond_old, int cond_new) {
    if (comp_new <= comp_old) {
        return false;
    }
    comp_old = comp_new;
    cond_old = cond_new;
    return true;
}

void pre_process(int this_node) {
    int this_heavy_chil = 0, max_weight = numeric_limits<int>::min();
    nodes[this_node].weight = 1;
    nodes[this_node].deep = nodes[nodes[this_node].father].deep + 1;
    for (auto this_chil : a[this_node]) {
        if (this_chil == nodes[this_node].father) {
            continue;
        }
        nodes[this_chil].father = this_node;
        pre_process(this_chil);
        nodes[this_node].weight += nodes[this_chil].weight;
        updata_big(max_weight, nodes[this_chil].weight, this_heavy_chil, this_chil);
    }
    nodes[this_node].heavy_chil = this_heavy_chil;
}

void build_chain(int this_node, int this_top, int& dfs_order) {
    nodes[this_node].chain_top = this_top;
    dfso_node[dfs_order] = this_node;
    nodes[this_node].dfso = dfs_order;
    dfs_order++;
    if (nodes[this_node].heavy_chil) {
        build_chain(nodes[this_node].heavy_chil, this_top, dfs_order);
    }
    for (auto this_chil : a[this_node]) {
        if (this_chil == nodes[this_node].father || this_chil == nodes[this_node].heavy_chil) {
            continue;
        }
        build_chain(this_chil, this_chil, dfs_order);
    }
    nodes[this_node].dfso_end = dfs_order - 1;
}

int lca(int node_a, int node_b) {
    while (nodes[node_a].chain_top != nodes[node_b].chain_top) {
        if(nodes[nodes[node_a].chain_top].deep < nodes[nodes[node_b].chain_top].deep){
            swap(node_a, node_b);
        }
        node_a = nodes[nodes[node_a].chain_top].father;
    }
    return (nodes[node_a].deep < nodes[node_b].deep ? node_a : node_b);
}

void line_add(int node_a,int node_b,int add_num){
    while(nodes[node_a].chain_top != nodes[node_b].chain_top){
        if(nodes[nodes[node_a].chain_top].deep < nodes[nodes[node_b].chain_top].deep){
            swap(node_a, node_b);
        }
        seg_add({nodes[nodes[node_a].chain_top].dfso, nodes[node_a].dfso}, add_num, {1, n}, 1);
        node_a = nodes[nodes[node_a].chain_top].father;
    }
    if(nodes[node_a].deep>nodes[node_b].deep){
        swap(node_a, node_b);
    }
    seg_add({nodes[node_a].dfso, nodes[node_b].dfso}, add_num, {1, n}, 1);
}

int line_query(int node_a,int node_b){
    long long anss = 0;
    while(nodes[node_a].chain_top != nodes[node_b].chain_top){
        if(nodes[nodes[node_a].chain_top].deep < nodes[nodes[node_b].chain_top].deep){
            swap(node_a, node_b);
        }
        anss += seg_query({nodes[nodes[node_a].chain_top].dfso, nodes[node_a].dfso}, {1, n}, 1);
        anss %= p;
        node_a = nodes[nodes[node_a].chain_top].father;
    }
    if(nodes[node_a].deep>nodes[node_b].deep){
        swap(node_a, node_b);
    }
    anss += seg_query({nodes[node_a].dfso, nodes[node_b].dfso}, {1, n}, 1);
    return anss % p;
}

void subtree_add(int this_node,int add_num){
    seg_add({nodes[this_node].dfso, nodes[this_node].dfso_end}, add_num, {1, n}, 1);
}

long long subtree_query(int this_node){
    return seg_query({nodes[this_node].dfso, nodes[this_node].dfso_end}, {1, n}, 1) % p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n;i++){
        cin >> snt[i];
    }
    for (int i = 1; i < n;i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    pre_process(r);
    int tree_weight = 1;
    build_chain(r, r, tree_weight);
    for(int i = 1; i <= n;i++){
        sn[nodes[i].dfso] = snt[i];
    }
    build({1, n}, 1);
    for (int i = 1; i <= m;i++) {
        int opt;
        int x, y, z;
        cin >> opt;
        switch(opt){
            case 1:
                cin >> x >> y >> z;
                line_add(x, y, z);
                break;
            case 2:
                cin >> x >> y;
                cout << line_query(x, y) << '\n';
                break;
            case 3:
                cin >> x >> z;
                subtree_add(x, z);
                break;
            case 4:
                cin >> x;
                cout << subtree_query(x) << '\n';
                break;
        }
    }
}