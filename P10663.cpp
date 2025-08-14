#include <bits/stdc++.h>
using namespace std;

long long mu[1000005], p[1000005];
bool flag[1000005];

void getMu(){
    long long tot = 0;
    mu[1] = 1;
    for (int i = 2; i <= 1000000; ++i){
        if (!flag[i]){
            p[++tot] = i, mu[i] = -1;
        }
        for (int j = 1; j <= tot && i * p[j] <= 1000000; ++j){
            flag[i * p[j]] = 1;
            if (i % p[j] == 0){
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
}

long long f[1000005], div_num;

inline long long mu_pow(long long num, long long mu,long long mod) {
    if (mu == -1) {
        return div_num;
    }
    if (mu == 0) {
        return 1;
    }
    if (mu == 1) {
        return num;
    }
    assert(false);
    return -1;
}

long long res[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    getMu();
    while(T--){
        long long n, p;
        cin >> n >> p;
        long long ans = 1, anss = 0;
        f[1] = 1;
        for (int i = 1;i <= n;i++) {
            res[i] = 1;
            f[i + 1] = (2 * f[i] + f[i - 1]) % p;
        }
        for (int k = 1; k <= n;k++) {
            long long b = p - 2, a = f[k];
            div_num = 1;
            while (b) {
                if (b & 1) {
                    div_num = (div_num * a) % p;
                }
                a = (a * a) % p;
                b >>= 1;
            }
            for (int i = k;i <= n;i += k) {
                res[i] *= mu_pow(f[k], mu[i / k], p);
                res[i] %= p;
            }
        }
        for (int i = 1;i <= n;i++) {
            ans = (ans * res[i]) % p;
            anss += (i * ans) % p;
            anss %= p;
        }
        cout << anss << '\n';
    }
}