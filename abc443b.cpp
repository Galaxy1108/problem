#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int y = 0;
    int ty = 0;
    while (ty < k) {
        ty += n + y;
        y++;
    }
    cout << y - 1;
}
