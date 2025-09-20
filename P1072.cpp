#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        //$居然不会报错？
        int $a_0$, $a_1$, $b_0$, $b_1$;
        cin >> $a_0$ >> $a_1$ >> $b_0$ >> $b_1$;
        int p = $a_0$ / $a_1$, q = $b_1$ / $b_0$, ans = 0;
        for (int x = 1; x * x <= $b_1$; x++) {
            if ($b_1$ % x == 0) {
                if (x % $a_1$ == 0 && __gcd(x / $a_1$, p) == 1 && __gcd(q, $b_1$ / x) == 1) {
                    ans++;
                }
                int y = $b_1$ / x;
                if (x == y) {
                    continue;
                }
                if (y % $a_1$ == 0 && __gcd(y / $a_1$, p) == 1 && __gcd(q, $b_1$ / y) == 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}