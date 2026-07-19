#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    int ans = n;
    for (int o = 0; o < 2; o++) {
        int cost = 0;
        int res = o;
        if (res != a[0]) {
            cost++;
        }
        for (int i = 0; i < n - 1; i++) {
            res ^= b[i];
            if (res != a[i + 1]) {
                cost++;
            }
        }
        ans = min(ans, cost);
    }
    cout << ans;
    return 0;
}
