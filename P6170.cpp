#include <bits/stdc++.h>
using namespace std;

int c[100005];
int a[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    for (int I = 1, i = 1;I <= 2 * n;I++, i = (i == n ? 1 : i + 1)) {
        int next_i = (i == n ? 1 : i + 1);
        c[next_i] += max(c[i] - 1, 0);
        a[next_i] += max(c[i] - 1, 0);
        c[i] = min(c[i], 1);
    }
    long long ans = 0;
    for (int i = 1;i <= n;i++) {
        ans += a[i] * a[i];
    }
    cout << ans;
    return 0;
}