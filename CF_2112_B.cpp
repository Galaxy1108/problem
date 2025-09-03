#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        bool flag = false;
        for (int i = 1;i < n;i++) {
            if (abs(a[i] - a[i + 1]) <= 1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << 0 << '\n';
            continue;
        }
        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        flag = false;
        for (int i = 2;i <= n;i++) {
            int mins = min(a[i], a[i - 1]);
            int maxs = max(a[i], a[i - 1]);
            if (i < n) {
                if (a[i + 1] >= mins && a[i + 1] <= maxs) {
                    flag = true;
                    break;
                }
                if (a[i + 1] - 1 >= mins && a[i + 1] - 1 <= maxs) {
                    flag = true;
                    break;
                }
                if (a[i + 1] + 1 >= mins && a[i + 1] + 1 <= maxs) {
                    flag = true;
                    break;
                }
            }
            if (i > 2) {
                if (a[i - 2] >= mins && a[i - 2] <= maxs) {
                    flag = true;
                    break;
                }
                if (a[i - 2] - 1 >= mins && a[i - 2] - 1 <= maxs) {
                    flag = true;
                    break;
                }
                if (a[i - 2] + 1 >= mins && a[i - 2] + 1 <= maxs) {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? 1 : -1) << '\n';
    }
}