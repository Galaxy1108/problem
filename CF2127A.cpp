#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int sa = -1, flag = true;
        for (int i = 1;i <= n;i++) {
            int a;
            cin >> a;
            if (a == -1) {
                continue;
            }
            if (a == 0) {
                flag = false;
            }
            if (sa == -1) {
                sa = a;
                continue;
            }
            if (a != sa) {
                flag = false;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}