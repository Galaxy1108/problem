#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[3] = { 0,1,1 };
int b[3] = { -1,-1,0 };
int c[3] = { 0,-1,1 };

bool flag = false;

int ans[1000005];

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n, x, y;
        cin >> n >> x >> y;
        if (n == 1 && x == 0 && y == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (n == 2 && x == 0 && y == 0) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        if (x + y > n - 2) {
            cout << -2 << '\n';
            continue;
        }
        int p = 2 - (x % 3);
        for (int i = 0;i <= x;i++) {
            cout << a[p] << ' ';
            ans[i] = a[p];
            p = (p + 1) % 3;
        }
        p = 0;
        for (int i = x + 1;i - x <= y;i++) {
            cout << b[p] << ' ';
            ans[i] = b[p];
            p = (p + 1) % 3;
        }
        int s = 0;
        flag = false;
        s = ans[x + y];
        if (ans[x + y - 1] == -1 && ans[x + y] == -1) {
            cout << 1 << ' ';
            y++;
            flag = true;
        }
        if (ans[x + y - 1] == 1 && ans[x + y] == 1) {
            flag = true;
        }
        if (flag) {
            p = 0;
            for (int i = y + x + 1;i < n;i++) {
                cout << c[p] << ' ';
                p = (p + 1) % 3;
            }
        } else {
            for (int i = y + x + 1;i < n;i++) {
                cout << s << ' ';
            }
        }
        cout << '\n';
    }
}