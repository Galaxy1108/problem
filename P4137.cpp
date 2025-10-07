/**
 * @name Rmq Problem / mex
 * @link https://www.luogu.com.cn/problem/P4137
 * @test 2025/10/7 莫队测试 T4
 * @par tags
 * #莫队 #bitset
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

#define bl(a) a / qn

int a[200005];
bitset<200005> b;

struct opt_T {
    int l, r, idx;
};

opt_T opts[200005];
int cnts[200005];
int anss[200005];
int qn;

int main() {
    b.set();
    int n, m;
    read(n), read(m);
    for (int i = 1;i <= n;i++) {
        read(a[i]);
    }
    for (int i = 1;i <= m;i++) {
        read(opts[i].l), read(opts[i].r);
        opts[i].idx = i;
    }
    qn = sqrt(n);
    sort(opts + 1, opts + 1 + m, [](opt_T a, opt_T b) {
        return (bl(a.l) == bl(b.l) ? ((bl(a.l) & 1) ? (a.r > b.r) : (a.r < b.r)) : (bl(a.l) < bl(b.l)));
    });
    int L = 1, R = 0;
    for (int i = 1;i <= m;i++) {
        int l = opts[i].l, r = opts[i].r;
        while (L < l) {
            if (!--cnts[a[L++]]) {
                b.set(a[L - 1]);
            }
        }
        while (L > l) {
            if (!cnts[a[--L]]++) {
                b.reset(a[L]);
            }
        }
        while (R < r) {
            if (!cnts[a[++R]]++) {
                b.reset(a[R]);
            }
        }
        while (R > r) {
            if (!--cnts[a[R--]]) {
                b.set(a[R + 1]);
            }
        }
        anss[opts[i].idx] = b._Find_first();
    }
    for (int i = 1;i <= m;i++) {
        write(anss[i]);
    }
}