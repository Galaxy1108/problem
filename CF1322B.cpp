/**
 * @name Present
 * @link https://codeforces.com/problemset/problem/1322/B 
 * @class blue *2100
 * @date 2025/10/18 周六 08:26
 * @par tags
 * #二分
 */

#include <bits/stdc++.h>
using namespace std;

int a[400005];
int b[400005];
int n;

bool calc(int idx) {
    int anss = 0;
    for (int i = 1;i <= n;i++) {
        b[i] = a[i] & ((1 << (idx + 1)) - 1);
    }
    sort(b + 1, b + 1 + n);
    int cnts = 0;
    int l = 1, r = 1, L = (1 << idx), R = (1 << (idx + 1)) - 1;
    for (int i = n;i >= 1;i--) {
        while (l <= n && b[i] + b[l] < L) {
            l++;
        }
        while (r <= n && b[i] + b[r] <= R) {
            r++;
        }
        cnts += max(0, r - l - (l <= i && i < r));
    }
    anss = (cnts >> 1) & 1;
    cnts = 0;
    l = 1, r = 1, L = (1 << (idx + 1)) + (1 << idx), R = (1 << (idx + 2)) - 2;
    for (int i = n;i >= 1;i--) {
        while (l <= n && b[i] + b[l] < L) {
            l++;
        }
        while (r <= n && b[i] + b[r] <= R) {
            r++;
        }
        cnts += max(0, r - l - (l <= i && i < r));
    }
    return anss ^ ((cnts >> 1) & 1);
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int anss = 0;
    for (int i = 0;i <= 30;i++) {
        anss |= (calc(i) << i);
    }
    cout << anss;
}