#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll c[200005];
ll sum1[400005], sum2[400005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, w;
        cin >> n >> w;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        fill(sum1, sum1 + 2 * w + 1, 0);
        fill(sum2, sum2 + 2 * w + 1, 0);
        int w2 = 2 * w;
        for (int i = 1; i <= n; i++) {
            sum1[i % w2] += c[i];
        }
        for (int i = 0; i < 2 * w2; i++) {
            sum2[i] = sum1[i % w2];
        }
        ll res = 0;
        for (int i = 0; i < w; i++) {
            res += sum2[i];
        }
        ll ans = res;
        for (int s = 1; s < w2; s++) {
            res += sum2[s + w - 1];
            res -= sum2[s - 1];
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
    return 0;
}
