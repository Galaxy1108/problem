/**
 * @name 概率充电器
 * @link https://www.luogu.com.cn/problem/P4284 
 * @class purple
 * @date 2025/10/10 周五 16:59
 * @par tags
 * #期望
 */

#include <bits/stdc++.h>
using namespace std;

struct line_t {
    int v;
    long double p;
};

long double q[500005];
vector<line_t> l[500005];

long double dp(int u, int f) {
    long double anss = q[u], res = 1;
    for (auto v_node : l[u]) {
        int v = v_node.v;
        long double p = v_node.p;
        if (v == f) {
            continue;
        }
        res *= (1 - dp(v, u) * p);
    }
    return anss + (1 - q[u]) * res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v, p;
        cin >> u >> v >> p;
        l[u].emplace_back((line_t) { v, p / 100.0 });
        l[v].emplace_back((line_t) { u, p / 100.0 });
    }
    for (int i = 1;i <= n;i++) {
        int num;
        cin >> num;
        q[i] = num / 100.0;
    }
    long double anss = 0;
    for (int root = 1;root <= n;root++) {
        anss += dp(root, 0);
    }
    printf("%.6Lf", anss);
}