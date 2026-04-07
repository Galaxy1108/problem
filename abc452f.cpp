#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int p[500005], s[500005];

void add(int x, int num) {
    for (int i = x; i <= n; i += i & -i) {
        s[i] += num;
    }
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        res += s[i];
    }
    return res;
}

ll solve(ll k) {
    if (k < 0) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        s[i] = 0;
    }
    ll inv = 0, res = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        inv += (r - l) - query(p[r]);
        add(p[r], 1);
        while (inv > k) {
            inv -= query(p[l] - 1);
            add(p[l], -1);
            l++;
        }
        res += r - l + 1;   
    }
    return res;
}

int main() {
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << solve(k) - solve(k - 1);
}
