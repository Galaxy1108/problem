#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main() {
    int n, q;
    cin >> n >> q;
    long long anss = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
        anss += min(a[i], b[i]);
    }
    while (q--) {
        char opt;
        int idx, num;
        cin >> opt >> idx >> num;
        if (opt == 'A') {
            int temp_s = min(a[idx], b[idx]);
            a[idx] = num;
            anss += (min(a[idx], b[idx]) - temp_s);
        } else {
            int temp_s = min(a[idx], b[idx]);
            b[idx] = num;
            anss += (min(a[idx], b[idx]) - temp_s);
        }
        cout << anss << '\n';
    }
}