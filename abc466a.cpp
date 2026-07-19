#include <bits/stdc++.h>
using namespace std;

int xs[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (xs[i] >= 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
