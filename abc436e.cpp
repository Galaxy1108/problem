#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int p[300005];
bool vis[300005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int u = i;
            int len = 0;
            while (!vis[u]) {
                vis[u] = 1;
                ++len;
                u = p[u];
            }
            if (len >= 2) {
                ans += (ll)len * (len - 1) / 2;
            }
        }
    }
    cout << ans;
    return 0;
}
