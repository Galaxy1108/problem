/**
 * problem: Traps
 * link: https://codeforces.com/problemset/problem/1684/D
 * difficult: *1700 (green)
 * date: 2025/10/29 周三 19:52
 * tags: #贪心
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[200005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        ll sums = 0;
        for (int i = 1;i <= n;i++) {
            int num;
            cin >> num;
            sums += num;
            a[i] = (n - i) - num;
        }
        sort(a + 1, a + 1 + n, [](int a, int b) {
            return a < b;
        });
        ll anss = sums;
        for (int pk = 1;pk <= k;pk++) {
            sums += a[pk] - (pk - 1);
            anss = min(anss, sums);
        }
        cout << anss << '\n';
    }
}
