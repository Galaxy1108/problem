#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a % 2) {
            cout << -1 << '\n';
        } else {
            cout << 1 << ' ' << a / 2 << '\n';
        }
    }
}