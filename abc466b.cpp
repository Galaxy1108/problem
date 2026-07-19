#include <bits/stdc++.h>
using namespace std;

int sn[105];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        sn[c] = max(sn[c], s);
    }
    for (int i = 1; i <= m; i++) {
        if (sn[i] == 0) {
            cout << -1 << ' ';
        } else {
            cout << sn[i] << ' ';
        }
    }
    return 0;
}
