#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int maxs = INT_MIN, mins = INT_MAX;
        int last_maxs = INT_MIN;
        long long sums = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if (a[i] > maxs) {
                last_maxs = maxs;
                maxs = a[i];
            } else if (a[i] > last_maxs) {
                last_maxs = a[i];
            }
            mins = min(mins, a[i]);
            sums += a[i];
        }
        if (max(maxs - 1 - mins, last_maxs - mins) > k) {
            cout << "Jerry\n";
            continue;
        }
        cout << ((sums % 2) ? "Tom\n" : "Jerry\n");
    }
}