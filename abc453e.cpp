#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int MAXN = 200005;

int n;
int ls[MAXN], rs[MAXN];
int d1[MAXN], d2[MAXN], d3[MAXN];
int c1[MAXN], c2[MAXN], c3[MAXN];
long long fac[MAXN], inv[MAXN];

long long fast_pow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) {
            r = r * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

long long calc_c(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ls[i] >> rs[i];
    }
    for (int i = 0; i < n; i++) {
        d1[ls[i]]++;
        d1[rs[i] + 1]--;
        int l = n - rs[i];
        int r = n - ls[i];
        d2[l]++;
        d2[r + 1]--;
        int ll = max(ls[i], n - rs[i]);
        int rr = min(rs[i], n - ls[i]);
        if (ll <= rr) {
            d3[ll]++;
            d3[rr + 1]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        c1[i] = c1[i - 1] + d1[i];
        c2[i] = c2[i - 1] + d2[i];
        c3[i] = c3[i - 1] + d3[i];
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[n] = fast_pow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    long long ans = 0;
    for (int k = 1; k <= n - 1; k++) {
        int res_a = c1[k];
        int both = c3[k];
        int must_a = res_a - both;
        if (must_a <= k) {
            if (k <= must_a + both) {
                ans += calc_c(both, k - must_a);
                ans %= mod;
            }
        }
    }
    cout << ans;
    return 0;
}
