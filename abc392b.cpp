#include <bits/stdc++.h>
using namespace std;

long long sn[1005];

int main() {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m;i++) {
        cin >> sn[i];
    }
    sort(sn, sn + m);
    cout << n - m << '\n';
    long long its = 0;
    for (long long i = 0; i < m;i++) {
        while (its + 1 <= n && its + 1 != sn[i]) {
            cout << (++its) << ' ';
        }
        its++;
    }
    while (its + 1 <= n) {
        cout << (++its) << ' ';
    }
}