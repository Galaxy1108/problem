#include <bits/stdc++.h>
using namespace std;

int sn[100005];

int main() {
    int n;
    cin >> n;
    int anss = 0;
    for (int i = 1; i <= n;i++) {
        cin >> sn[i];
        if (sn[i] > sn[i - 1]) {
            anss += sn[i] - sn[i - 1];
        }
    }
    cout << anss;
    return 0;
}