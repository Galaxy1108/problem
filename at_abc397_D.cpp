#include <bits/stdc++.h>
using namespace std;

long long is_xx(long long ver) {
    long long ver_q = sqrt(ver);
    return (ver_q * ver_q == ver) ? ver_q : -1;
}

int main() {
    long long n;
    cin >> n;
    for (long long xly = 1; xly * xly * xly <= n;xly++) {
        if (n % xly) {
            continue;
        }
        long long xy = (n / xly) - xly * xly;
        if (xy % 3 || xy == 0) {
            continue;
        }
        xy /= 3;
        long long xdy = xly * xly + 4 * xy;
        xdy = is_xx(xdy);
        long long delta = xdy * xdy - 4 * xy;
        if (delta < 0) {
            continue;
        }
        long long delta_sqrt = is_xx(delta);
        if (delta_sqrt == -1 || (xdy + delta_sqrt) % 2 || (xdy - delta_sqrt) % 2) {
            continue;
        }
        cout << (xdy + delta_sqrt) / 2 << " " << (xdy - delta_sqrt) / 2;
        return 0;
    }
    cout << -1;
    return 0;
}