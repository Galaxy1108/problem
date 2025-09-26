#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct shop_t {
    ll p, q;
};

ll negs[1000005];
ll cows[1000005];
shop_t shops[1000005];

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1;i <= n;i++) {
        cin >> cows[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> shops[i].q >> shops[i].p;
    }
    for (int i = 1;i <= r;i++) {
        cin >> negs[i];
    }
    sort(cows + 1, cows + 1 + n, [](int a, int b) {
        return a > b;
    });
    sort(negs + 1, negs + 1 + r, [](int a, int b) {
        return a > b;
    });
    sort(shops + 1, shops + 1 + m, [](shop_t a, shop_t b) {
        return a.p > b.p;
    });
    ll anss = 0, res = 0;
    for (int i = 1;i <= r;i++) {
        negs[i] += negs[i - 1];
    }
    int shop_idx = 1;
    for (int i = 0;i <= n;i++) {
        while (shop_idx <= m) {
            if (cows[i] >= shops[shop_idx].q) {
                cows[i] = cows[i] - shops[shop_idx].q;
                res += shops[shop_idx].q * shops[shop_idx].p;
                shop_idx++;
            } else {
                shops[shop_idx].q -= cows[i];
                res += cows[i] * shops[shop_idx].p;
                break;
            }
        }
        anss = max(anss, res + negs[min(n - i, r)]);
    }
    cout << anss;
}
/*
143409218
98597136
*/