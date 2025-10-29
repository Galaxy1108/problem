#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int anss = x / (a + b) * s * a;
    if (x % (a + b) < a) {
        anss += s * (x % (a + b));
    } else {
        anss += s * a;
    }
    cout << anss;
    return 0;
}
