#include <bits/stdc++.h>
using namespace std;

int sn[105][105];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> sn[i][j];
        }
    }
    for (int a = 1; a <= n - 2; a++) {
        for (int b = a + 1; b <= n - 1; b++) {
            for (int c = b + 1; c <= n; c++) {
                if (sn[a][b] + sn[b][c] < sn[a][c]) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}
