/**
 * problem: Doremy's IQ
 * link: https://codeforces.com/problemset/problem/1707/A
 * difficult: *1600 (green)
 * date: 2025/10/28 周二 15:28
 * tags: #二分 #贪心
 */

#include <bits/stdc++.h>
using namespace std;

int a[100005], n, q;

bool check(int num) {
    int tq = q;
    for (int i = num + 1;i <= n;i++) {
        if (a[i] > tq) {
            tq--;
        }
    }
    return tq >= 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        for (int i = 1;i <= l;i++) {
            cout << (a[i] <= q);
        }
        for (int i = l + 1;i <= n;i++) {
            cout << 1;
        }
        cout << '\n';
    }
}
