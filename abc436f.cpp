#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int trr1[500005], trr2[500005];
int b[500005], n;

int query1(int x) {
    int res = 0;
    for (int i = x;i > 0;i -= (i & -i)) {
        res += trr1[i];
    }
    return res;
}

int query2(int x) {
    int res = 0;
    for (int i = x;i > 0;i -= (i & -i)) {
        res += trr2[i];
    }
    return res;
}

void add1(int x) {
    for (int i = x;i <= n;i += (i & -i)) {
        trr1[i]++;
    }
}

void add2(int x) {
    for (int i = x;i <= n;i += (i & -i)) {
        trr2[i]++;
    }
}

int bigl[500005], bigr[500005];

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= n;i++) {
        bigl[i] = query1(b[i]);
        add1(b[i]);
    }
    for (int i = n;i >= 1;i--) {
        bigr[i] = query2(b[i]);
        add2(b[i]);
    }
    ll res = 0;
    for (int i = 1;i <= n;i++) {
        res += (ll)(bigl[i] + 1) * (bigr[i] + 1);
    }
    cout << res;
    return 0;
}
