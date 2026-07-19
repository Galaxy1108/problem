#include <bits/stdc++.h>
using namespace std;

int r[300005], c[300005];
bool a[300005], b[300005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> r[i] >> c[i];
    }
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        if (!a[r[i]] && !b[c[i]]) {
            ans++;
        }
        a[r[i]] = true;
        b[c[i]] = true;
    }
    cout << ans;
    return 0;
}
