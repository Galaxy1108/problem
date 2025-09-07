#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, x, y;
        cin >> a >> x >> y;
        bool flag = false;
        for (int i = -100;i <= 200;i++) {
            if (abs(i - x) < abs(a - x) && abs(i - y) < abs(a - y)) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}