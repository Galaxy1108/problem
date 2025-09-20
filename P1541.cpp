#include <bits/stdc++.h>
using namespace std;

long long f[41][41][41][41];
int sn[400], sums[4];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++) {
        cin >> sn[i];

    }
    int tmp;
    for (int i = 1; i <= m;i++) {
        cin >> tmp;
        sums[tmp - 1]++;
    }
    f[0][0][0][0] = sn[1];
    for (int a1 = 0; a1 <= sums[0];a1++) {
        for (int a2 = 0; a2 <= sums[1];a2++) {
            for (int a3 = 0; a3 <= sums[2];a3++) {
                for (int a4 = 0; a4 <= sums[3];a4++) {
                    int thiss = 1 + 1 * a1 + 2 * a2 + 3 * a3 + 4 * a4;
                    if (a1 != 0) {
                        f[a1][a2][a3][a4] = max(f[a1 - 1][a2][a3][a4] + sn[thiss], f[a1][a2][a3][a4]);
                    }
                    if (a2 != 0) {
                        f[a1][a2][a3][a4] = max(f[a1][a2 - 1][a3][a4] + sn[thiss], f[a1][a2][a3][a4]);
                    }
                    if (a3 != 0) {
                        f[a1][a2][a3][a4] = max(f[a1][a2][a3 - 1][a4] + sn[thiss], f[a1][a2][a3][a4]);
                    }
                    if (a4 != 0) {
                        f[a1][a2][a3][a4] = max(f[a1][a2][a3][a4 - 1] + sn[thiss], f[a1][a2][a3][a4]);
                    }
                }
            }
        }
    }
    cout << f[sums[0]][sums[1]][sums[2]][sums[3]];
}