#include <iostream>
using namespace std;

int main() {
    int mony = 0;
    int mmony = 0;
    int on = 0;
    int f[12];
    for (int i = 0; i < 12;i++) {
        cin >> f[i];
    }
    for (int i = 0; i < 12;i++) {
        mony += 300;
        mony -= f[i];
        if (mony < 0) {
            cout << "-" << i + 1;
            return 0;
        }
        mmony += mony / 100 * 100;
        mony -= mony / 100 * 100;
    }
    mony += mmony * 1.2;
    cout << mony;
    return 0;
}