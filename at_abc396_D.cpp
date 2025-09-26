/*
#### 问题陈述

给你一个简单相连的无向图，图中有 $N$ 个顶点，编号为 $1$ 到 $N$ ；有 $M$ 条边，编号为 $1$ 到 $M$ 。边 $i$ 连接顶点 $u_i$ 和 $v_i$ ，其标签为 $w_i$ 。

在从顶点 $1$ 到顶点 $N$ 的所有简单路径（不经过同一顶点多次的路径）中，求路径上边的标签的最小 XOR。

关于 XOR 的说明 对于非负整数 $A$ 和 $B$ ，它们的 XOR $A \oplus B$ 定义如下：

- 在 $A \oplus B$ 的二进制表示中，当且仅当 $A$ 和 $B$ 的相同数位中恰好有一位是 $1$ 时， $2^k \,(k \ge 0)$ 对应数位上的数字是 $1$ ；否则，它是 $0$ 。

例如， $3 \oplus 5 = 6$ （二进制： $011 \oplus 101 = 110$ ）。
一般来说， $k$ 个整数 $p_1, \dots, p_k$ 的 XOR 定义为 $(\cdots ((p_1 \oplus p_2) \oplus p_3) \oplus \cdots \oplus p_k)$ 。可以证明它与 $p_1, \dots, p_k$ 的阶数无关。
*/

#include <bits/stdc++.h>
using namespace std;

struct edges {
    long long v, w;
};

vector<edges> a[15];

long long is_in;
long long this_v;
long long anss;

long long n, m;

void dfs(long long v) {
    is_in ^= (1 << v);
    if (v == n) {
        anss = min(anss, this_v);
        is_in ^= (1 << v);
        return;
    }
    for (auto i : a[v]) {
        if (!(is_in & (1 << i.v))) {
            this_v ^= i.w;
            dfs(i.v);
            this_v ^= i.w;
        }
    }
    is_in ^= (1 << v);
}

int main() {
    cin >> n >> m;
    for (long long i = 0; i < m;i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({ v, w });
        a[v].push_back({ u, w });
    }
    anss = LLONG_MAX;
    dfs(1);
    cout << anss;
    return 0;
}