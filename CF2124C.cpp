#include <bits/stdc++.h>
using namespace std;

int b[600005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> b[i];
        }
        int anss = 1;
        for (int i = n;i >= 2;i--) {
            int ls = gcd(b[i - 1], b[i]);
            anss = lcm(anss, b[i - 1] / ls);
            b[i - 1] = ls;
        }
        cout << anss << '\n';
    }
}