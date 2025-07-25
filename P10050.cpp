#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll sn[3005], in[3005];
ll max_R[3005];
ll n, k, q;

vector<ll> a[3005];
queue<ll> qu;

bool check(ll L, ll R) {
    if (L == R) {
        return true;
    }
    for (int i = 1;i <= k;i++) {
        a[i].clear();
        in[i] = 0;
    }
    for (int i = L;i < R;i++) {
        if ((i - L) % 2) {
            a[sn[i + 1]].push_back(sn[i]);
            in[sn[i]]++;
        } else {
            a[sn[i]].push_back(sn[i + 1]);
            in[sn[i + 1]]++;
        }
    }
    for (int i = 1;i <= k;i++) {
        if (!in[i]) {
            qu.push(i);
        }
        // cout << in[i] << ' ';
    }
    // cout << '\n';
    ll cnts = 0;
    while (!qu.empty()) {
        ll u = qu.front();
        qu.pop();
        cnts++;
        for (auto v : a[u]) {
            in[v]--;
            if(!in[v]){
                qu.push(v);
            }
        }
    }
    return (cnts == k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> q;
    for (int i = 1;i <= n;i++) {
        cin >> sn[i];
    }
    for (int L = 1;L <= n;L++) {
        ll l = 1, r = n;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (check(L, mid)) {
                l = mid;
                // cout << L << '+' << mid << '\n';
            } else {
                r = mid - 1;
                // cout << L << '-' << mid << '\n';
            }
        }
        max_R[L] = r;
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        cout << ((y <= max_R[x] ? "YES\n" : "NO\n"));
    }
}