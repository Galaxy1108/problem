#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct S {
    ll dx, dy;
    ll len;
};

S a[200005], b[200005];

int main() {
    ll rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;
    ll n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < m; i++) {
        char ch;
        ll cnt;
        cin >> ch >> cnt;
        switch (ch) {
            case 'U':
                a[i] = {-1, 0, cnt};
                break;
            case 'D':
                a[i] = {1, 0, cnt};
                break;
            case 'L':
                a[i] = {0, -1, cnt};
                break;
            case 'R':
                a[i] = {0, 1, cnt};
                break;
        }
    }
    for (int i = 0; i < l; i++) {
        char ch;
        ll cnt;
        cin >> ch >> cnt;
        switch (ch) {
            case 'U':
                b[i] = {1, 0, cnt};
                break;
            case 'D':
                b[i] = {-1, 0, cnt};
                break;
            case 'L':
                b[i] = {0, 1, cnt};
                break;
            case 'R':
                b[i] = {0, -1, cnt};
                break;
        }
    }
    
    ll idx = rt - ra;
    ll idy = ct - ca;
    ll ans = 0;
    int i = 0, j = 0;
    ll len1 = 0, len2 = 0;
    ll dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
    while (i < m || j < l) {
        if (len1 == 0 && i < m) {
            dx1 = a[i].dx;
            dy1 = a[i].dy;
            len1 = a[i].len;
            i++;
        }
        if (len2 == 0 && j < l) {
            dx2 = b[j].dx;
            dy2 = b[j].dy;
            len2 = b[j].len;
            j++;
        }
        ll len = min(len1, len2);
        ll dx = dx1 + dx2;
        ll dy = dy1 + dy2;
        if (dx == 0 && dy == 0) {
            if (idx == 0 && idy == 0) {
                ans += len;
            }
        } else if (dx == 0) {
            if (idx == 0) {
                if (dy != 0 && idy % dy == 0) {
                    ll k = -idy / dy;
                    if (k >= 1 && k <= len) {
                        ans++;
                    }
                }
            }
        } else if (dy == 0) {
            if (idy == 0) {
                if (dx != 0 && idx % dx == 0) {
                    ll k = -idx / dx;
                    if (k >= 1 && k <= len) {
                        ans++;
                    }
                }
            }
        } else {
            if (idx % dx == 0 && idy % dy == 0) {
                ll k1 = -idx / dx;
                ll k2 = -idy / dy;
                if (k1 == k2 && k1 >= 1 && k1 <= len) {
                    ans++;
                }
            }
        }
        idx += dx * len;
        idy += dy * len;
        len1 -= len;
        len2 -= len;
    }
    cout << ans;
    return 0;
}