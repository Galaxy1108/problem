#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct rock_t {
    ull w, v;
};

struct line_t {
    int l, r;
};

rock_t rock[200005];
line_t line[200005];
int n, m;
ull s;

int cnts[200005];
ull sumv[200005];

ull check(ull W) {
    for (ull i = 1; i <= n;i++) {
        cnts[i] = cnts[i - 1] + (rock[i].w >= W);
        sumv[i] = sumv[i - 1] + rock[i].v * (rock[i].w >= W);
    }
    ull sums = 0;
    for (ull i = 1; i <= m;i++) {
        sums += (cnts[line[i].r] - cnts[line[i].l - 1]) * (sumv[line[i].r] - sumv[line[i].l - 1]);
    }
    return sums;
}

int main() {
    cin >> n >> m >> s;
    ull max_v = 0;
    for (ull i = 1; i <= n;i++) {
        cin >> rock[i].w >> rock[i].v;
        max_v = max(max_v, rock[i].v);
    }
    for (ull i = 1; i <= m;i++) {
        cin >> line[i].l >> line[i].r;
    }
    ull l = 0, r = max_v;
    while (l + 1 < r) {
        ull mid = (l + r) / 2;
        if (check(mid) >= s) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << min(labs(check(l) - s), labs(check(r) - s));
}