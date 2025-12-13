#include <bits/stdc++.h>
using namespace std;

int a[55], sums[55];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sums[i] = sums[i - 1] + a[i];
    }
    int cnt = 0;
    for (int l = 1;l <= n;l++) {
        for (int r = l;r <= n;r++) {
            int sum = sums[r] - sums[l - 1];
            bool flag = true;
            for (int i = l;i <= r;i++) {
                if (sum % a[i] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
