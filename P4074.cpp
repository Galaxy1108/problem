/**
 * @name 糖果公园
 * @link https://www.luogu.com.cn/problem/P4074
 * @test 2025/10/7 莫队测试 T3
 * @par tags
 * #带修莫队 #LCA
 */

#include <bits/stdc++.h>
using namespace std;

namespace FastIO {
#define il inline
    const int iL = 1 << 25;
    char ibuf[iL], * iS = ibuf + iL, * iT = ibuf + iL;
#define GC() (iS == iT) ? \
 (iT = (iS = ibuf) + fread(ibuf, 1, iL, stdin), (iS == iT) ? EOF : *iS++) : *iS++
    template <class T>il void read(T& x) {
        x = 0;
        char c = GC(); bool flg = false;
        while (!isdigit(c)) { flg |= c == '-'; c = GC(); }
        while (isdigit(c)) { x = (x << 1) + (x << 3) + (c & 15); c = GC(); }
        if (flg) x = -x;
    }
    char Out[iL], * iter = Out;
#define Flush() fwrite(Out, 1, iter - Out, stdout); iter = Out
    template <class T>il void write(T x, char LastChar = '\n') {
        int c[35], len = 0;
        if (x < 0) { *iter++ = '-'; x = -x; }
        do { c[++len] = x % 10; x /= 10; } while (x);
        while (len) *iter++ = c[len--] + '0';
        *iter++ = LastChar; Flush();
    }
}
using namespace FastIO;

using ll = long long;

struct s {
    int l, r;
    int time;
    int cnt;
};

struct c_t {
    int idx;
    int a, b;
};

s opts[100005];
c_t cs[100005];
int cnts[100005];
ll anss[100005];
int v[100005], qn, w[100005], c[100005];
vector<int> tre[100005];

int ia[100005], ib[100005], a[200005];
int fa[100005][20], dep[100005];
int tops;

void build(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1;i < 20;i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    ia[u] = ++tops;
    a[tops] = u;
    for (auto v : tre[u]) {
        if (v != f) {
            build(v, u);
        }
    }
    ib[u] = ++tops;
    a[tops] = u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int dept = dep[u] - dep[v];
    for (int i = 17; i >= 0; i--) {
        if (dept >= (1 << i)) {
            dept -= (1 << i);
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 17; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i], v = fa[v][i];
        }
    }
    return fa[u][0];
}

bool vis[100005];
ll res;

void add(int idx) {
    if (vis[idx]) {
        res -= 1.0l * v[c[idx]] * w[cnts[c[idx]]];
        cnts[c[idx]]--;
    } else {
        cnts[c[idx]]++;
        res += 1.0l * v[c[idx]] * w[cnts[c[idx]]];
    }
    vis[idx] ^= 1;
}

void ct(int idx, int num) {
    if (vis[idx]) {
        add(idx);
        c[idx] = num;
        add(idx);
    } else {
        c[idx] = num;
    }
}

int main() {
    int n, m, q;
    read(n), read(m), read(q);
    for (int i = 1;i <= m;i++) {
        read(v[i]);
    }
    for (int i = 1;i <= n;i++) {
        read(w[i]);
    }
    for (int i = 1;i < n;i++) {
        int a, b;
        read(a), read(b);
        tre[a].emplace_back(b);
        tre[b].emplace_back(a);
    }
    build(1, 0);
    for (int i = 1;i <= n;i++) {
        read(c[i]);
    }
    int time_c = 0, opt_c = 0;
    for (int i = 1;i <= q;i++) {
        int opt;
        read(opt);
        if (!opt) {
            time_c++;
            read(cs[time_c].idx), read(cs[time_c].b);
            cs[time_c].a = c[cs[time_c].idx];
            c[cs[time_c].idx] = cs[time_c].b;
        } else {
            opt_c++;
            int l, r;
            read(l), read(r);
            if (ia[l] > ia[r]) {
                swap(l, r);
            }
            opts[opt_c].l = (lca(l, r) == l ? ia[l] : ib[l]);
            opts[opt_c].r = ia[r];
            opts[opt_c].time = time_c;
            opts[opt_c].cnt = opt_c;
        }
    }
    qn = pow(n, 2.0 / 3);
    sort(opts + 1, opts + 1 + opt_c, [](s a, s b) {
        return ((a.l / qn == b.l / qn) ? ((a.r / qn == b.r / qn) ? (((a.r / qn) & 1) ? (a.time > b.time) : (a.time < b.time)) : (a.r / qn < b.r / qn)) : (a.l / qn < b.l / qn));
    });
    int L = 1, R = 0, T = time_c;
    for (int i = 1;i <= opt_c;i++) {
        int l = opts[i].l, r = opts[i].r, t = opts[i].time;
        while (L > l) {
            add(a[--L]);
        }
        while (L < l) {
            add(a[L++]);
        }
        while (R > r) {
            add(a[R--]);
        }
        while (R < r) {
            add(a[++R]);
        }
        while (T < t) {
            T++;
            ct(cs[T].idx, cs[T].b);
        }
        while (T > t) {
            ct(cs[T].idx, cs[T].a);
            T--;
        }
        int lidx = a[l], ridx = a[r];
        int lcas = lca(lidx, ridx);
        if (lidx != lcas && ridx != lcas) {
            add(lcas);
            anss[opts[i].cnt] = res;
            add(lcas);
        } else {
            anss[opts[i].cnt] = res;
        }
    }
    for (int i = 1;i <= opt_c;i++) {
        write(anss[i]);
    }
}

/*
4 3 5
1 9 2
7 6 5 1
2 3
3 1
3 4
1 2 3 2
1 1 2
1 4 2
0 2 1
1 1 2
1 4 2
*/
