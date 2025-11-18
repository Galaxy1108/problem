#include <bits/stdc++.h>
using namespace std;

vector<int> tr[200005];

template <int _N>
struct node_t {
    int w;
    int idx[_N];
    node_t() {};
    node_t(int _w, initializer_list<int> _idx) {
        w = _w;
        copy(_idx.begin(), _idx.end(), idx);
    }
    inline friend bool operator>(node_t a, node_t b) {
        return a.w >= b.w;
    }
    inline friend node_t operator+(node_t& a, int w) {
        a.w += w;
        return a;
    }
    inline void operator=(node_t a) {
        w = a.w;
        copy(begin(idx), end(idx), a.idx);
    }
};

node_t<1> n1[200005];
node_t<2> n2[200005];
node_t<3> n3[200005];

template <int _N>
inline void updata(node_t<_N>& max1, node_t<_N>& max2, node_t<_N> value) {
    if (value > max1) {
        max2 = max1;
        max1 = value;
        return;
    }
    max2 = (max2 > value ? max2 : value);
}

template <int _A,int _B>
inline node_t<_A + _B> merge(node_t<_A> a, node_t<_B> b) {
    node_t<_A + _B> value(a.w + b.w, { a.idx + b.idx });
}

void dfs(int u, int f) {
    // 1 node
    node_t<1> n1max1(0, { u }), n1max2(0, { u });
    for (int v : tr[u]) {
        if (v == u) {
            continue;
        }
        updata(n1max1, n1max2, n1[v] + 1);
    }
    node_t<2> n2max1()
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a, b;
        cin >> a >> b;
        tr[a].emplace_back(b);
        tr[b].emplace_back(a);
    }

}
