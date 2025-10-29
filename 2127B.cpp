#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        string str;
        cin >> str;
        str = " " + str;
        int lidx = 0, ridx = str.size();
        for (int i = x;i <= n;i++) {
            if (str[i] == '#') {
                ridx = i;
                break;
            }
        }
        for (int i = x;i >= 1;i--) {
            if (str[i] == '#') {
                lidx = i;
                break;
            }
        }
        ridx = n - ridx + 1;
        cout << max(min(x - 1, ridx), min(n - x, lidx)) + 1 << '\n';
    }
}


