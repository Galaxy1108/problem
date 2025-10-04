#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct s {
    ll num, cnt;
};
s cnts[40];


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0;i < 40;i++) {
            cnts[i].cnt = cnts[i].num = 0;
        }
        int cnt = 0, a = n, res = 1;
        for (int i = 2;i * i <= a;i++) {
            if (a % i) {
                continue;
            }
            int t_cnt = ++cnt;
            while (!(a % i)) {
                a /= i;
                cnts[t_cnt].cnt++;
            }
            cnts[t_cnt].num = i;
            res *= i;
        }
        if (a) {
            cnts[++cnt].num = a;
            cnts[cnt].cnt = 1;
            res *= a;
        }
        sort(cnts + 1, cnts + cnt + 1, [](s a, s b) {
            return a.cnt < b.cnt;
        });
        ll anss = 0, last_s = 0;
        for (int i = 1;i <= cnt;i++) {
            if (cnts[i].cnt != last_s) {
                anss += res * (cnts[i].cnt - last_s);
                last_s = cnts[i].cnt;
            }
            res /= cnts[i].num;
        }
        cout << anss << '\n';
    }
}