#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct p {
    int x, y, idx;
};

p a[300005];

struct trie_node {
    map<int, int> chil;
    vector<int> idx;
};

trie_node ts[300005];
int findi[300005];
int node_cnt;

void get_ans(int u) {
    for (int i : ts[u].idx) {
        cout << i << ' ';
    }
    for (auto v : ts[u].chil) {
        get_ans(v.second);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x, y;
        cin >> x >> y;
        if (!ts[findi[x]].chil[y]) {
            ts[findi[x]].chil[y] = ++node_cnt;
            ts[node_cnt].idx.push_back(i);
            findi[i] = node_cnt;
        } else {
            ts[ts[findi[x]].chil[y]].idx.push_back(i);
            findi[i] = ts[findi[x]].chil[y];
        }
    }
    get_ans(0);
}
