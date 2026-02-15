#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 998244353

int spf[10000001], arr[200005];
int pri_fac[200005][8];
int pri_exp[200005][8];
int fac_cnt[200005];

unordered_map<int, int> max_exp;
unordered_map<int, int> sec_exp;
unordered_map<int, int> max_cnt;

ll mod_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    for (int i = 2; i <= 10000000; i++) {
        if (!spf[i]) {
            for (int j = i; j <= 10000000; j += i) {
                if (!spf[j]) {
                    spf[j] = i;
                }
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        max_exp.clear();
        sec_exp.clear();
        max_cnt.clear();
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            fac_cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int x = arr[i];
            while (x > 1) {
                int p = spf[x];
                int e = 0;
                while (x % p == 0) {
                    x /= p;
                    e++;
                }
                pri_fac[i][fac_cnt[i]] = p;
                pri_exp[i][fac_cnt[i]] = e;
                fac_cnt[i]++;
                if (!max_exp.count(p)) {
                    max_exp[p] = e;
                    sec_exp[p] = 0;
                    max_cnt[p] = 1;
                } else if (max_exp[p] < e) {
                    sec_exp[p] = max_exp[p];
                    max_exp[p] = e;
                    max_cnt[p] = 1;
                } else if (max_exp[p] == e) {
                    max_cnt[p]++;
                } else if (sec_exp[p] < e) {
                    sec_exp[p] = e;
                }
            }
        }
        ll Lcm = 1;
        for (auto it : max_exp) {
            Lcm = Lcm * mod_pow(it.first, it.second) % MOD;
        }
        for (int i = 1; i <= n; i++) {
            ll ans = Lcm;
            for (int j = 0; j < fac_cnt[i]; j++) {
                int p = pri_fac[i][j];
                int e = pri_exp[i][j];
                if (e == max_exp[p] && max_cnt[p] == 1) {
                    int dif = max_exp[p] - sec_exp[p];
                    ans = ans * mod_pow(p, MOD - 1 - dif) % MOD;
                }
            }
            cout << ans << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
