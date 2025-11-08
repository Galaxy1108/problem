#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
    int n, m;
    cin >> n >> m;
    int sums = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sums += a[i];
    }
    for (int i = 1;i <= n;i++) {
        if (sums - a[i] == m) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No\n";
}
