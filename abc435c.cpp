#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int maxl = 1;
    for (int i = 1;i <= n;i++) {
        if (i <= maxl) {
            maxl = max(maxl, i + a[i] - 1);
        }
    }
    cout << min(maxl, n);
    return 0;
}
