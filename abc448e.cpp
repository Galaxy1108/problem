#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define MOD 10007

struct node_t {
    int r, a, b;
};

node_t mp[10][31][100005];

int c[100005];
ll l[100005];

int main() {
    int K, M;
    cin >> K >> M;
    for (int i = 1; i <= K; i++) {
        cin >> c[i] >> l[i];
    }
    for (int d = 0; d <= 9; d++) {
        for (int r = 0; r < M; r++) {
            long long x = 1ll * r * 10 + d;
            mp[d][0][r] = { (int)x % M, 10 % MOD, (int)(x / M) % MOD };
        }
        for (int k = 1; k < 31; k++) {
            for (int r = 0; r < M; r++) {
                node_t a = mp[d][k - 1][r];
                node_t b = mp[d][k - 1][a.r];
                mp[d][k][r] = { b.r,(int)(1ll * a.a * b.a % MOD), (int)((1ll * a.b * b.a + b.b) % MOD) };
            }
        }
    }
    int ans = 0, r = 0;
    for (int i = 1; i <= K; i++) {
        int d = c[i];
        ll len = l[i];
        for (int k = 0; k < 31; k++) {
            if (len & (1ll << k)) {
                node_t t = mp[d][k][r];
                ans = ((1ll * ans * t.a + t.b) % MOD);
                r = t.r;
            }
        }
    }
    cout << ans;
    return 0;
}
