#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[105];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        int ans = -1;
        for (int j = i - 1;j >= 1;j--) {
            if (a[j] > a[i]) {
                ans = j;
                break;
            }
        }
        cout << ans << '\n';
    }
}
