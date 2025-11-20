/**
 * problem: Redstone?
 * link: https://codeforces.com/problemset/problem/2133/A 
 * contest: https://vjudge.net/contest/768289 (强化训练VP 1)
 * difficult: *800 (orange)
 * date: 2025/11/20 周四 19:30
 * tags: #数学
 */

#include <bits/stdc++.h>
using namespace std;

int a[105];
int p[105];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag = false;
        for (int i = 1;i <= 100;i++) {
            p[i] = 0;
        }
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (p[a[i]]) {
                flag = true;
            }
            p[a[i]]++;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}
