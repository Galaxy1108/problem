#include <bits/stdc++.h>
using namespace std;

long long a[100005];
long long b[100005];
long long n, m, w;

bool check(long long min_num) {
    for (int i = 1;i <= n;i++) {
        b[i] = 0;
    }
    long long res = 0;
    for (int i = 1;i <= n;i++) {
        b[i] = b[i] + b[i - 1];
        long long num = a[i] + b[i];
        if (num < min_num) {
            long long add_num = min_num - num;
            b[i] += add_num;
            b[min(i + w, n + 1)] -= add_num;
            res += add_num;
        }
    }
    return res <= m;
}

int main() {
    cin >> n >> m >> w;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    long long l = 0, r = 1002000000;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
        // cout << l << ' ' << r << '\n';
    }
    cout << l;
    return 0;
}