/*
 * @Author: Galaxy1108
 * @Date: 2025-09-07 13:06:12
 * @LastEditors: Galaxy1108
 * @LastEditTime: 2025-09-07 13:25:13
 * @FilePath: \problem\F_Eat_and_Ride.cpp
 */
/*
### Problem Statement

There is a connected undirected graph with $N$ vertices and $M$ edges. The vertices are numbered vertex $1,$ vertex $2,\ldots,$ vertex $N$, and the $i$\-th edge $(1\le i\le M)$ connects vertices $u _ i$ and $v _ i$.

For $i=1,2,\ldots,N$, solve the following problem:

Initially, Takahashi's weight is $0$.

He travels by car to visit vertex $1$ and moves toward vertex $i$. When he visits vertex $v\ (1\le v\le N)$, his weight increases by $W _ v$.

The car he is riding can move along the edges. When he passes through an edge, letting $X$ be his weight at that time, the car consumes $X$ fuel.

Find the minimum amount of fuel consumed for him to reach vertex $i$.
*/

#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> a[5005];
unsigned long long w[5005];

struct s {
    unsigned long long id, w, p;
};

queue<s> q;

unsigned long long anss[5005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
        anss[i] = -1;
    }
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    q.push({ 1,0,0 });
    anss[1] = 0;
    while (!q.empty()) {
        s u = q.front();
        q.pop();
        if(u.w > anss[u.id] && anss[u.id] != -1) {
            continue;
        }
        for (auto v : a[u.id]) {
            if (anss[v] == -1 || anss[v] > anss[u.id] + (w[u.id] + u.p)) {
                anss[v] = anss[u.id] + (w[u.id] + u.p);
                q.push({ v,anss[v],u.p + w[u.id] });
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        cout << anss[i] << '\n';
    }
}

