#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x, y, a, b, c, d;
        cin >> x >> y >> a >> b >> c >> d;
        long long anss = LLONG_MAX;
        if (x == y) {
            anss = min(anss, 0ll);
        }
        if ((x & a) == y) {
            anss = min(anss, c);
        }
        if ((x | b) == y) {
            anss = min(anss, d);
        }
        if ((((x & a) | b) == y) || (((x | b) & a) == y)) {
            anss = min(anss, c + d);
        }
        cout << (anss == LLONG_MAX ? -1 : anss) << '\n';
    }
}