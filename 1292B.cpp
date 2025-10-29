#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
ll x[80], y[80];

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return max(x1, x2) - min(x1, x2) + max(y1, y2) - min(y1, y2);
}

ll x_0, y_0, ax, ay, bx, by;
ll xs, ys, t;

inline bool try_add(ll& res, ll num) {
    if (res + num > t || res + num < res) {
        return false;
    }
    res += num;
    return true;
}

ll calc(int fnode) {
    ll res = 0, ans = 0;
    ll x_1 = xs, y_1 = ys;
    for (int i = fnode;i >= 0;i--) {
        if (!try_add(res, dist(x_1, y_1, x[i], y[i]))) {
            return ans;
        }
        ans++;
        x_1 = x[i], y_1 = y[i];
    }
    for (int i = fnode + 1;;i++) {
        if (!try_add(res, dist(x_1, y_1, x[i], y[i]))) {
            return ans;
        }
        ans++;
        x_1 = x[i], y_1 = y[i];
    }
    exit(1);
}

int main() {
    cin >> x_0 >> y_0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    x[0] = x_0, y[0] = y_0;
    int tops = 0;
    do {
        tops++;
        x[tops] = ax * x[tops - 1] + bx;
        y[tops] = ay * y[tops - 1] + by;
    } while (x[tops] > x[tops - 1] && y[tops] > y[tops - 1]);
    tops--;
    ll anss = 0;
    for (int i = 0;i <= tops;i++) {
        anss = max(anss, calc(i));
    }
    cout << anss;
}