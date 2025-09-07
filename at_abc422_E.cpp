/*
 * @Author: Galaxy1108
 * @Date: 2025-09-07 12:33:37
 * @LastEditors: Galaxy1108
 * @LastEditTime: 2025-09-07 13:35:37
 * @FilePath: \problem\E_Colinear.cpp
 */
/*
### Problem Statement

There are $N$ points on a two-dimensional plane. $N$ is odd. The $i$\-th point is at $(x_i, y_i)$. All point coordinates are distinct.  
Determine whether there exists a line passing through more than half of the $N$ points, and if so, output it.  
For any input satisfying the constraints, if a line satisfying the condition exists, it can be expressed as $ax+by+c=0$ using integers $a,b,c$ with $-10^{18} \leq a,b,c \leq 10^{18}$ (where $(a,b,c) \neq (0,0,0)$). Output these $a,b,c$.
*/

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long x[500005], y[500005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << max({ 1,2,3 });
    int T = 100;
    while (T--) {
        int i = rng() % n;
        int j = rng() % n;
        while (i == j) {
            j = rng() % n;
        }
        long long a = y[j] - y[i];
        long long b = x[i] - x[j];
        long long c = 1ll * x[j] * y[i] - 1ll * x[i] * y[j];
        if (a == 0 && b == 0) {
            continue;
        }
        long long g = 0;
        if (a != 0) {
            g = __gcd(g, abs(a));
        }
        if (b != 0) {
            g = __gcd(g, abs(b));
        }
        if (c != 0) {
            g = __gcd(g, abs(c));
        }
        if (g == 0) {
            continue;
        }
        a /= g;
        b /= g;
        c /= g;
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        } else if (a == 0 && b < 0) {
            b = -b;
            c = -c;
        }
        int cnt = 0;
        for (int k = 0; k < n; k++) {
            if (a * x[k] + b * y[k] + c == 0) {
                cnt++;
            }
        }
        if (cnt > n / 2) {
            cout << "Yes\n";
            cout << a << ' ' << b << ' ' << c << '\n';
            return 0;
        }
    }
    cout << "No\n";
}