#include <bits/stdc++.h>
using namespace std;

struct t {
    int val, idx;
}a[300005];

int b[300005];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1,[](t x, t y) {
        return x.val < y.val;
    });
    while (q--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 1; j <= k; j++) {
                if (a[i].idx == b[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = a[i].val;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
