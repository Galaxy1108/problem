/**
 * @name [国家集训队] 数颜色 / 维护队列
 * @link https://www.luogu.com.cn/problem/P1903
 * @test 2025/10/7 莫队测试 T2
 * @par tags
 * #【模板】 #带修莫队
 */
#include <bits/stdc++.h>
using namespace std;

struct s {
    int l, r;
    int time;
    int cnt;
};

struct c {
    int idx;
    int a, b;
};

s opts[150005];
c cs[150005];
int cnts[1000005];
int anss[150005];
int a[150005], qn;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int time_c = 0, opt_c = 0;
    for (int i = 1;i <= m;i++) {
        char opt;
        cin >> opt;
        if (opt == 'R') {
            cin >> cs[++time_c].idx >> cs[time_c].b;
            cs[time_c].a = a[cs[time_c].idx];
            a[cs[time_c].idx] = cs[time_c].b;
        } else {
            cin >> opts[++opt_c].l >> opts[opt_c].r;
            opts[opt_c].time = time_c;
            opts[opt_c].cnt = opt_c;
        }
    }
    qn = pow(n, 2.0 / 3);
    sort(opts + 1, opts + 1 + opt_c, [](s a, s b) {
        return ((a.l / qn == b.l / qn) ? ((a.r / qn == b.r / qn) ? (a.time < b.time) : (a.r / qn < b.r / qn)) : (a.l / qn < b.l / qn));
    });
    int L = 1, R = 0, T = time_c, res = 0;
    for (int i = 1;i <= opt_c;i++) {
        int l = opts[i].l, r = opts[i].r, t = opts[i].time;
        while (L < l) {
            res -= !--cnts[a[L++]];
        }
        while (L > l) {
            res += !cnts[a[--L]]++;
        }
        while (R < r) {
            res += !cnts[a[++R]]++;
        }
        while (R > r) {
            res -= !--cnts[a[R--]];
        }
        while (T < t) {
            a[cs[++T].idx] = cs[T].b;
            if (cs[T].idx >= l && cs[T].idx <= r) {
                res -= !--cnts[cs[T].a];
                res += !cnts[cs[T].b]++;
            }
        }
        while (T > t) {
            a[cs[T].idx] = cs[T].a;
            if (cs[T].idx >= l && cs[T].idx <= r) {
                res += !cnts[cs[T].a]++;
                res -= !--cnts[cs[T].b];
            }
            T--;
        }
        anss[opts[i].cnt] = res;
    }
    for (int i = 1;i <= opt_c;i++) {
        cout << anss[i] << '\n';
    }
}