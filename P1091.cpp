#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio (false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sn[n];
    int f1[n], f2[n], k = -1, tmp;
    for (int i = 0;i < n;i++) {
        cin >> sn[i];
        f1[i] = 1;
        f2[i] = 1;
    }
    for (int i = n - 2;i >= 0;i--) {
        for (int j = i + 1;j < n;j++) {
            if (sn[i] > sn[j] && f1[i] <= f1[j] + 1) {
                f1[i] = f1[j] + 1;
            }
        }
    }
    for (int i = 1;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (sn[i] > sn[j] && f2[i] <= f2[j] + 1) {
                f2[i] = f2[j] + 1;
            }
        }
        tmp = f1[i] + f2[i] - 1;
        if (tmp > k) {
            k = tmp;
        }
    }
    cout << n - k;
    return 0;
}
