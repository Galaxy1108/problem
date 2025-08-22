#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll l[10000005], r[10000005];
ll sl[10000005], sr[10000005];
ll ssl[10000005], ssr[10000005];

int main(){
    int n, m, mod;
    cin >> n >> m >> mod;
    for (int i = 1;i <= m;i++) {
        l[i] = i % mod;
        r[i] = (m - i + 1) % mod;
    }
    for (int k = 2;k <= n;k++) {
        for (int i = 1;i <= m;i++){
            sl[i] = (sl[i - 1] + l[i]) % mod;
            ssl[i] = (ssl[i - 1] + sl[i]) % mod;
        }
        for (int i = m;i >= 1;i--) {
            sr[i] = (sr[i + 1] + r[i]) % mod;
            ssr[i] = (ssr[i + 1] + sr[i]) % mod;
        }
        for (int i = 1;i <= m;i++) {
            l[i] = (i * (sl[m] - sr[i + 1]) - ssl[i - 1] + mod) % mod;
            r[i] = ((m - i + 1) * (sl[m] - sl[i - 1]) - ssr[i + 1] + mod) % mod;
        }
    }
    ll anss = 0;
    for (int i = 1;i <= m;i++) {
        anss = (anss + l[i]) % mod;
    }
    cout << anss;
    return 0;
}