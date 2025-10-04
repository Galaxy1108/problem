#include <bits/stdc++.h>
using namespace std;

int a[400005];
int b[400005];
int n;

bool calc(int idx) {
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
    cout << cnts << '\n';
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
    return cnts & 1;
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