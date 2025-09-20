/**
 * P11232 [CSP-S 2024] 超速检测
 * 修改后的代码，修复二分查找问题
 */

#include <bits/stdc++.h>
using namespace std;

#define esp 1e-5

struct car_s {
    long long l, r, a2;
    bool lesp, resp;
} cars[100005];

long long css[100005];

struct ncar_s {
    long long l, r;
} ncars[100005];

bool cmp(ncar_s a, ncar_s b) {
    return (a.r == b.r) ? (a.l > b.l) : (a.r < b.r);
}

long long n, m, R, V;

long long car_l(long long i) {
    long long l = cars[i].l, a2 = cars[i].a2;
    long long left = 0, right = m - 1;
    long long ans = m;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (css[mid] * a2 >= l) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

long long car_l_esp(long long i) {
    long long l = cars[i].l, a2 = cars[i].a2;
    long long left = 0, right = m - 1;
    long long ans = m;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (css[mid] * a2 > l) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

long long car_r(long long i) {
    long long r = cars[i].r, a2 = cars[i].a2;
    long long left = 0, right = m - 1;
    long long ans = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (css[mid] * a2 <= r) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

long long car_r_esp(long long i) {
    long long r = cars[i].r, a2 = cars[i].a2;
    long long left = 0, right = m - 1;
    long long ans = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (css[mid] * a2 < r) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> R >> V;
        for (long long i = 0; i < n; i++) {
            long long d, v, a;
            cin >> d >> v >> a;
            long long a2 = abs(2 * a);
            if (a == 0) {
                if (v > V) {
                    cars[i] = {d, R, 1, true, true};
                } else {
                    cars[i] = {-1, -1, a2, false, false};
                }
            } else if (a > 0) {
                if (v > V) {
                    cars[i] = {d * a2, R * a2, a2, true, true};
                } else {
                    long long s = d * a2 + (V * V - v * v);
                    if (s > R * a2) {
                        cars[i] = {-1, -1, a2, false, false};
                    } else {
                        cars[i] = {s, R * a2, a2, false, true};
                    }
                }
            } else {
                if (v < V) {
                    cars[i] = {-1, -1, a2, false, false};
                } else {
                    long long s = d * a2 - (V * V - v * v);
                    if (s > R * a2) {
                        cars[i] = {d * a2, R * a2, a2, true, true};
                    } else {
                        cars[i] = {d * a2, s, a2, true, false};
                    }
                }
            }
        }
        for (long long i = 0; i < m; i++) {
            cin >> css[i];
        }
        sort(css, css + m);
        for (long long i = 0; i < n; i++) {
            if (cars[i].r == -1) {
                ncars[i] = {2, 1};
                continue;
            }
            long long l_pos = cars[i].l;
            long long r_pos = cars[i].r;
            long long a2 = cars[i].a2;
            if (r_pos < css[0] * a2 || l_pos > css[m - 1] * a2) {
                ncars[i] = {2, 1};
                continue;
            }
            long long l = cars[i].lesp ? car_l(i) : car_l_esp(i);
            long long r = cars[i].resp ? car_r(i) : car_r_esp(i);
            if (l >= m || r < 0 || l > r) {
                ncars[i] = {2, 1};
            } else {
                ncars[i] = {l, r};
            }
        }
        sort(ncars, ncars + n, cmp);
        long long anss1 = 0, anss2 = m;
        long long last = -1;
        for (long long i = 0; i < n; i++) {
            if (ncars[i].l > ncars[i].r) continue;
            anss1++;
            if (ncars[i].l > last) {
                anss2--;
                last = ncars[i].r;
            }
        }
        cout << anss1 << ' ' << anss2 << '\n';
    }
}