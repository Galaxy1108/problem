#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}
int main() {
    double m, x1, x2;
    int s = 0;
    cin >> a >> b >> c >> d;
    for (int i = -100;i < 100;i++) {
        double l, r;
        l = i;
        r = i + 1;
        x1 = f(l);
        x2 = f(r);
        if (!x1) {
            printf("%.2lf ", l);
            s++;
        }
        if (x1 * x2 < 0) {
            while (r - l >= 1e-3) {
                m = (l + r) / 2;
                if (f(m) * f(r) <= 0) {
                    l = m;
                } else {
                    r = m;
                }
            }
            printf("%.2lf ", r);
            s++;
            if (s == 3)
                break;
        }
    }
    return 0;
}