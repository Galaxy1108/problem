#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x + y <= 12) {
        cout << x + y;
    } else {
        cout << x + y - 12;
    }
}