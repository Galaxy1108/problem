/**
 * @name 绿豆蛙的归宿
 * @link https://www.luogu.com.cn/problem/P4316 
 * @par tags
 * #DP #期望DP #拓扑排序
 */

#include <bits/stdc++.h>
using namespace std;

struct s {
    int v, w;
};
vector<s> a[100005];
int in[100005], deg[100005];
queue<int> q;
long double dp[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        cin >> v >> u >> w;
        a[u].emplace_back((s) { v, w });
        in[v]++, deg[v]++;
    }
    dp[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v_node : a[u]) {
            int v = v_node.v, w = v_node.w;
            dp[v] += (dp[u] + w) * (1.0l / deg[v]);
            if (!--in[v]) {
                q.push(v);
            }
        }
    }
    printf("%.2Lf", dp[1]);
    return 0;
}