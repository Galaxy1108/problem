#include <bits/stdc++.h>
using namespace std;

int a[100][100];

int main() {
    int n;
    cin >> n;
    int r = 0, c = n / 2;
    for (int k = 1; k <= n * n; k++) {
        a[r][c] = k;
        int nr = (r - 1 + n) % n;
        int nc = (c + 1) % n;
        if (a[nr][nc] == 0) {
            r = nr;
            c = nc;
        } else {
            r = (r + 1) % n;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
