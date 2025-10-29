#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        bool flag = true;
        for (int i = 2;i <= n;i++) {
            if (a[i] < a[i - 1]) {
                cout << "Yes\n2\n";
                cout << a[i - 1] << ' ' << a[i] << '\n';
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "No\n";
        }
    }
}