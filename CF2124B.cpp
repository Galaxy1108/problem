#include <bits/stdc++.h>
using namespace std;

long long a[200005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sums = 0;
        long long mins = INT_MAX;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            mins = min(mins, a[i]);
            sums += mins;
        }
        sums = min(sums, a[1] + a[2]);
        if (n >= 3) {
            sums = min(sums, a[1] + min(a[1], a[2] + a[3]));
        }
        cout << sums << '\n';
    }
}