#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int sn[500005], ans[500005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sn[i];
    }
    for (int i = n; i >= 1; i--) {
        if (sn[i] == i) {
            ans[i] = i;
        } else {
            ans[i] = ans[sn[i]];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
