#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0;; i++) {
        if (x + i == z * (y + i)) {
            cout << "Yes\n";
            return 0;
        }
        if (x + i < z * (y + i)) {
            cout << "No\n";
            return 0;
        }
    }
}
