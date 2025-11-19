/**
 * problem: Minimum Path
 * link: https://codeforces.com/problemset/problem/1473/E
 * contest: https://vjudge.net/contest/765472 (NOIP2025—基本功提升训练 2)
 * difficult: *2400 (blue)
 * date: 2025/11/19 周三 16:34
 * tags: #最短路
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

#define node(_k,_n) (((_k)-1) * n + _n)

struct node_t {
    ll v, w;
    friend bool operator>(node_t a, node_t b) {
        return a.w > b.w;
    }
};

priority_queue<node_t, vector<node_t>, greater<node_t>> pq;
vector<node_t> mp[900000];
ll res[900000];

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[node(1, u)].push_back({ node(1,v),w });
        mp[node(1, v)].push_back({ node(1,u),w });
        mp[node(1, u)].push_back({ node(2,v),0 });
        mp[node(1, v)].push_back({ node(2,u),0 });
        mp[node(1, u)].push_back({ node(3,v),2 * w });
        mp[node(1, v)].push_back({ node(3,u),2 * w });
        mp[node(1, u)].push_back({ node(4,v),w });
        mp[node(1, v)].push_back({ node(4,u),w });
    
        mp[node(2, u)].push_back({ node(2,v),w });
        mp[node(2, v)].push_back({ node(2,u),w });
        mp[node(2, u)].push_back({ node(4,v),2 * w });
        mp[node(2, v)].push_back({ node(4,u),2 * w });
    
        mp[node(3, u)].push_back({ node(3,v),w });
        mp[node(3, v)].push_back({ node(3,u),w });
        mp[node(3, u)].push_back({ node(4,v),0 });
        mp[node(3, v)].push_back({ node(4,u),0 });
    
        mp[node(4, u)].push_back({ node(4,v),w });
        mp[node(4, v)].push_back({ node(4,u),w });
    }

    for (int i = 1;i <= n;i++) {
        res[node(1, i)] = LLONG_MAX;
        res[node(2, i)] = LLONG_MAX;
        res[node(3, i)] = LLONG_MAX;
        res[node(4, i)] = LLONG_MAX;
    }

    pq.push({ node(1,1),0 });
    res[node(1, 1)] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (res[u.v] < u.w) {
            continue;
        }
        for (auto v : mp[u.v]) {
            if (u.w + v.w >= res[v.v]) {
                continue;
            }
            res[v.v] = u.w + v.w;
            pq.push({ v.v,res[v.v] });
        }
    }

    for (int i = 2;i <= n;i++) {
        cout << res[node(4, i)] << ' ';
    }

    return 0;
}
