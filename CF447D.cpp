#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sumx[1005], sumy[1005];
ll a[1005][1005];
ll part_x[1000005], part_y[1000005];
priority_queue<ll> pqx, pqy;

int main() {
    ll n, m, k, p;
    cin >> n >> m >> k >> p;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            sumx[i] += a[i][j];
            sumy[j] += a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        pqx.push(sumx[i]);
    }
    for (int i = 1;i <= m;i++) {
        pqy.push(sumy[i]);
    }
    for (int i = 1;i <= k;i++) {
        ll x = pqx.top();
        ll y = pqy.top();
        pqx.pop();
        pqy.pop();
        part_x[i] = part_x[i - 1] + x;
        part_y[i] = part_y[i - 1] + y;
        x -= p * m;
        y -= p * n;
        pqx.push(x);
        pqy.push(y);
    }
    ll anss = LLONG_MIN;
    for (ll i = 0;i <= k;i++) {
        ll ans = part_x[i] + part_y[k - i];
        anss = max(anss, ans - (k - i) * i * p);
    }
    cout << anss;
}
