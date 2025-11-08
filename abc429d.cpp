#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[1000005], pos[1000005], cnt[1000005], l[1000005], cnt2[2000005];

int main() {
    ll n, m;
    int c;
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        pos[k] = a[i];
        cnt[k] = j - i;
        k++;
        i = j;
    }
    if (k == 0) {
        cout << 0;
        return 0;
    }
    for (int j = 0; j < k; j++) {
        int pe = (j - 1 + k) % k;
        ll g = (pos[j] - pos[pe] + m) % m;
        if (g == 0) {
            g = m;
        }
        l[j] = g;
    }
    for (int i = 0; i < k; i++) {
        cnt2[i] = cnt[i];
        cnt2[i + k] = cnt[i];
    }
    int r = 0;
    ll cur = 0, ans = 0;
    for (int j = 0; j < k; j++) {
        if (r < j) {
            r = j;
            cur = 0;
        }
        while (cur < c) {
            if (r >= j + k) {
                break;
            }
            cur += cnt2[r++];
        }
        ans += cur * l[j];
        cur -= cnt2[j];
    }
    cout << ans;
    return 0;
}
