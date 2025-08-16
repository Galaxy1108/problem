#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll x[500005], s[500005];
ll f[500005];
ll n, d, k, tops, begi, its;
struct ss {
    ll idx, num;
};
ss q[500005]; 

bool check(ll g) {
    for (int i = 0;i <= n;i++) {
        f[i] = -1;
    }
    f[0] = 0, x[0] = 0;
    ll l = max(1ll, d - g), r = d + g;
    begi = 1, tops = 0, its = 0;
    for (int i = 1;i <= n;i++) {
        while (x[i] - x[its] >= l) {
            while (tops >= begi && q[tops].num < f[its]) {
                tops--;
            }
            q[++tops].idx = x[its];
            q[tops].num = f[its];
            its++;
        }
        while (begi <= tops && (x[i] - q[begi].idx > r || q[begi].num == -1)) {
            begi++;
        }
        if (begi <= tops) {
            f[i] = q[begi].num + s[i];
        }
        if (f[i] >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> d >> k;
    for (int i = 1;i <= n;i++) {
        cin >> x[i] >> s[i];
    }
    ll l = 0, r = 1e9 + 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << (l == 1e9 + 1 ? -1 : l);
}