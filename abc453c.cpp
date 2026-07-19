#include <bits/stdc++.h>
using namespace std;

long long l[25];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        double pos = 0.5;
        int res = 0;
        for (int i = 0; i < n; i++) {
            double prepos = pos;
            if (bit & (1 << i)) {
                pos += l[i];
            } else {
                pos -= l[i];
            }
            if ((prepos < 0 && pos > 0) || (prepos > 0 && pos < 0)) {
                res++;
            }
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}
