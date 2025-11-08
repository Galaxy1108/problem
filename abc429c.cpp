#include <bits/stdc++.h>
using namespace std;

int cnt[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] >= 2) {
            long long c = cnt[i];
            ans += c * (c - 1) / 2 * (n - c);
        }
    }
    cout << ans;
    return 0;
}
