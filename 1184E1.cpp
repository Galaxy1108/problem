/**
 * problem: Daleks' Invasion (easy)
 * link: https://codeforces.com/problemset/problem/11841/E1
 * contest: https://vjudge.net/contest/765472 (NOIP2025—基本功提升训练 2)
 * difficult: *1900 (green)
 * date: 2025/11/19 周三 16:40
 * tags: #最小生成树
 */

#include <bits/stdc++.h>
using namespace std;

struct edge_t {
    int u, v, w;
};

edge_t a[1000005];

int fat[100005];

int getfat(int a) {
    return (fat[a] == a ? a : fat[a] = getfat(fat[a]));
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for (int i = 1;i <= n;i++) {
        fat[i] = i;
    }
    sort(a + 2, a + 1 + m, [](auto a, auto b) {
        return a.w < b.w;
    });
    for (int i = 2, cnt = 0;i <= m && cnt < n - 1;i++) {
        int fatu = getfat(a[i].u), fatv = getfat(a[i].v);
        if (fatu == fatv) {
            continue;
        }
        cnt++;
        fat[fatu] = fatv;
        if (getfat(a[1].u) == getfat(a[1].v)) {
            cout << a[i].w;
            return 0;
        }
    }
    cout << 1000000000;
}
