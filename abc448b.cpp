#include <bits/stdc++.h>
using namespace std;

int a[1005], b[1005], c[1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int j = 0; j < m; j++) {
        cin >> c[j];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = a[i];
        int x = min(b[i], c[j]);
        ans += x;
        c[j] -= x;
    }
    cout << ans << '\n';
    return 0;
}
