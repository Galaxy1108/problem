#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << ((k % 3 == 1) ? "Yes\n" : "No\n");
    }
    return 0;
}