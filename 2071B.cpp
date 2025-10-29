#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long sums = n * (n + 1) / 2;
        long long sq = sqrt(sums);
        if (sq * sq == sums) {
            cout << -1 << '\n';
            continue;
        }
        cout << 2 << ' ' << 1 << ' ';
        sums = 3;
        for (int i = 3;i <= n;i++) {
            sums += i;
            sq = sqrt(sums);
            if (sq * sq == sums) {
                cout << i + 1 << ' ' << i << ' ';
                i++;
                sums += i;
            } else {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}