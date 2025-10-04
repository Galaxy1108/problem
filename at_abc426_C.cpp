#include <bits/stdc++.h>
using namespace std;

int lows;

int lowbit(int num) {
    return num & (-num);
}

int a[1000005], n, q;

void add(int idx, int num) {
    for (int i = idx;i <= n;i += lowbit(i)) {
        a[i] += num;
    }
}

int query(int idx) {
    int res = 0;
    for (int i = idx;i > 0;i -= lowbit(i)) {
        res += a[i];
    }
    return res;
}

int main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        add(i, 1);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x <= lows) {
            cout << 0 << '\n';
            continue;
        }
        int adds = query(x);
        cout << adds << '\n';
        add(y, adds);
        while (lows < x) {
            lows++;
            add(lows, -query(lows));
        }
    }
}