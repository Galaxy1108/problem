#include <bits/stdc++.h>
using namespace std;

int powx(int p, int q) {
    if (q == 0) {
        return 1;
    }
    long long ans = 1;
    for (int i = 1;i <= q;i++) {
        ans *= p;ans %= 10007;
    }
    return ans;
}

int C[1005][1005];

int main() {
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    for (int i = 0;i <= k;i++) {
        C[i][0] = C[i][i] = 1;
    }
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j < i;j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
        }
    }
    cout << C[k][m] * (powx(b, m) * powx(a, n) % 10007) % 10007;
}