#include <bits/stdc++.h>
using namespace std;

int main() {
    long long p, q, x, y;
    cin >> p >> q >> x >> y;
    if (p <= x && x < p + 100 && q <= y && y < q + 100) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

