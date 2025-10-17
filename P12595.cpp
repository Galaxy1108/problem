/**
 * @name 出生于驾校
 * @link https://www.luogu.com.cn/problem/P12595 
 * @class green
 * @date 2025/10/16 周四 15:41
 * @par tags
 * #诈骗
 */

#include <bits/stdc++.h>
using namespace std;

typedef uint32_t ui;
typedef int64_t ll;
#define lim 998'244'353

int n, q, minK, maxK;
ui X, Y, Z;

ui nextInt(ui& x = X, ui& y = Y, ui& z = Z) {
    x ^= y << (z & 31);
    y ^= z >> (x & 31);
    z ^= x << (y & 31);
    x ^= x >> 5; y ^= y << 17; z ^= z >> 6;
    return x;
}

vector<int> genArr(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = nextInt() % lim;
    return ret;
}

ll sum[30][40000005];
ll len[30][40000005];

int main() {
    cin >> n >> q >> minK >> maxK;
    cin >> X >> Y >> Z;
    vector<int> a = genArr(n);
    int max_k = log2(n);
    for (int i = 0;i < n;i++) {
        sum[max_k][i % (1 << max_k)] += a[i];
        len[max_k][i % (1 << max_k)]++;
    }
    for (int k = max_k - 1;k >= 0; k--) {
        for (int p = 0;p < (1 << k);p++) {
            sum[k][p] = (sum[k + 1][p] + sum[k + 1][p + (1 << k)]) % lim;
            len[k][p] = (len[k + 1][p] + len[k + 1][p + (1 << k)]) % lim;
        }
    }
    ll add = 0, times = 1, anss = 0;
    for (int _ = 1; _ <= q; ++_) {
        int op = nextInt() % 3 + 1;
        if (op == 1) {
            int x = nextInt() % lim;
            add = (add + x) % lim;
        } else if (op == 2) {
            int x = nextInt() % lim;
            add = (add * x) % lim;
            times = (times * x) % lim;
        } else {
            int k = nextInt() % (maxK - minK + 1) + minK;
            int p = nextInt() % (1 << k);
            anss = (anss ^ ((((sum[k][p] * times) % lim) + ((add * len[k][p]) % lim)) % lim));
        }
    }
    cout << anss;
    return 0;
}
