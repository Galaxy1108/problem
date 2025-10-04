#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int maxs = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            maxs = max(maxs, a[i]);
        }
        bool flag = false;
        for (int i = 1;i <= n;i++) {
            if (a[i] != maxs) {
                flag = true;
            }
        }
        if (!flag) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        for (int i = 1;i <= n;i++) {
            cout << 1 + (a[i] == maxs) << ' ';
        }
        cout << '\n';
    }
}