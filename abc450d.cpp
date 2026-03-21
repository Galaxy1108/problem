#include <bits/stdc++.h>
using namespace std;

long long sn[200005];
long long b[400010];

int main() {
    int n;
    long long k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        sn[i] = a % k;
    }
    sort(sn, sn + n);
    for (int i = 0; i < n; ++i) {
        b[i] = sn[i];
        b[i + n] = sn[i] + k;
    }
    long long ans = k;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, b[i + n - 1] - b[i]);
    }
    cout << ans;
    return 0;
}
