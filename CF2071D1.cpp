#include <bits/stdc++.h>
using namespace std;

bool a[200005];
long long n, l, r;

bool get_ans(long long k) {
    if (k <= n) {
        return a[k];
    }
    long long s = k / 2;
    bool ans = false;
    if (s <= n) {
        for (int i = 1;i <= s;i++) {
            ans ^= a[i];
        }
        return ans;
    }
    for (int i = 1;i <= n;i++) {
        ans ^= a[i];
    }
    if (!(n % 2)) {
        ans ^= get_ans(n + 1);
    }
    if (!(s % 2) && (!(s == n + 1 && !(n % 2)))) {
        ans ^= get_ans(s);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> l >> r;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        cout << get_ans(l) << '\n';
    }
}