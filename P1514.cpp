/**
 * @name 引水入城
 * @link https://www.luogu.com.cn/problem/P1514
 * @class blue
 * @date 2025/10/17 周五 16:02
 * @par tags
 * #搜索 #贪心
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

int h[505][505];
bitset<505> vis;

struct s {
    int l = INT_MAX, r = INT_MIN;
};

s ls[505];
bitset<505> mem2[505][505];
bool is_mem[505][505];

int n, m, lcnt;

void get_s(int x, int y, int& idx) {
    if (is_mem[x][y]) {
        vis |= mem2[x][y];
        return;
    }
    if (x == n) {
        vis[y] = idx;
        mem2[x][y].set(y);
    }
    if (x + 1 <= n && h[x][y] > h[x + 1][y]) {
        get_s(x + 1, y, idx);
        mem2[x][y] |= mem2[x + 1][y];
    }
    if (x - 1 >= 1 && h[x][y] > h[x - 1][y]) {
        get_s(x - 1, y, idx);
        mem2[x][y] |= mem2[x - 1][y];
    }
    if (y + 1 <= m && h[x][y] > h[x][y + 1]) {
        get_s(x, y + 1, idx);
        mem2[x][y] |= mem2[x][y + 1];
    }
    if (y - 1 >= 1 && h[x][y] > h[x][y - 1]) {
        get_s(x, y - 1, idx);
        mem2[x][y] |= mem2[x][y - 1];
    }
    is_mem[x][y] = true;
}

int main() {
    read(n), read(m);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            read(h[i][j]);
        }
    }
    for (int i = 1;i <= m;i++) {
        get_s(1, i, i);
        ls[++lcnt].l = mem2[1][i]._Find_first();
        ls[lcnt].l = (ls[lcnt].l == (int)mem2[1][i].size() ? INT_MAX : ls[lcnt].l);
        for (int j = m;j >= 1;j--) {
            if (mem2[1][i][j]) {
                ls[lcnt].r = j;
                break;
            }
        }
        if (ls[lcnt].l == INT_MAX || ls[lcnt].r == INT_MIN) {
            lcnt--;
        }
    }
    int cnts = m - vis.count();
    if (cnts) {
        write(0), write(cnts);
        return 0;
    }
    sort(ls + 1, ls + 1 + lcnt, [](s a, s b) {
        return a.l < b.l;
    });
    int max_r = 0, idx = 1, anss = 0;
    while (max_r < m) {
        int num = max_r;
        while (idx <= lcnt && ls[idx].l <= max_r + 1) {
            num = (num > ls[idx].r ? num : ls[idx].r);
            idx++;
        }
        max_r = num;
        anss++;
    }
    write(1), write(anss);
    return 0;
}