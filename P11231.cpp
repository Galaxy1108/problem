#include <bits/stdc++.h>
using namespace std;

int sn[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> sn[i];
    }
    sort(sn + 1, sn + 1 + n);
    int can_eraser = 0, un_eraser = 1;
    for (int i = 2;i <= n;i++) {
        if (sn[i - 1] < sn[i]) {
            can_eraser += un_eraser;
            un_eraser = 0;
        }
        if (can_eraser) {
            can_eraser--;
        }
        un_eraser++;
    }
    cout << can_eraser + un_eraser;
    return 0;
}