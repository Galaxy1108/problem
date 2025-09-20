#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    unsigned long long bi = 0, tmpa = 0;
    for (int i = 1;i <= n;++i) {
        cin >> bi;
        tmpa |= bi;
    }
    unsigned long long tmpb = 0, q = 0, p = 0;
    for (int x, i = 1; i <= m; ++i) {
        cin >> p >> q;
        tmpb |= 1ULL << p;
    }
    tmpa |= ~tmpb;
    unsigned long long ans = 1;
    for (int i = 0; i < k; ++i) {
        ans <<= (tmpa >> i & 1);
    }
    if (ans == 0 && n == 0) {
        cout << "18446744073709551616";
        return 0;
    }
    cout << ans - n;
}