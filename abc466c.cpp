#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (r < i) {
            r = i;
        }
        while (r < n) {
            cout << "? " << i << ' ' << r + 1 << endl;
            string s;
            cin >> s;
            if (s == "Yes"){
                r++;
            } else {
                break;
            }
        }
        ans += r - i;
    }
    cout << "! " << ans << endl;
}
