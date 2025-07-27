#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll min_l[505][505];
ll airports[505];
ll near_airport[505];

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            min_l[i][j] = LLONG_MAX;
        }
    }
    for (int i = 1;i <= m;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        min_l[a][b] = min(c, min_l[a][b]);
        min_l[b][a] = min(c, min_l[b][a]);
    }
    for (int i = 1;i <= n;i++) {
        min_l[i][i] = 0;
    }
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                min_l[i][j] = min(min_l[i][j], ((min_l[i][k] == LLONG_MAX || min_l[k][j] == LLONG_MAX) ? LLONG_MAX : min_l[i][k] + min_l[k][j]));
            }
        }
    }
    ll k, t;
    cin >> k >> t;
    for (int i = 1;i <= k;i++) {
        cin >> airports[i];
    }
    for (int i = 1;i <= n;i++) {
        near_airport[i] = LLONG_MAX;
        for (int j = 1;j <= k;j++) {
            near_airport[i] = min(near_airport[i], min_l[i][airports[j]]);
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll opt, a, b, c;
        cin >> opt;
        switch(opt) {
            case 1:
                cin >> a >> b >> c;
                for (int i = 1;i <= n;i++) {
                    for (int j = 1;j <= n;j++) {
                        min_l[i][j] = min({ min_l[i][j],
                                          ((min_l[i][a] == LLONG_MAX || min_l[b][j] == LLONG_MAX) ? LLONG_MAX : min_l[i][a] + c + min_l[b][j]),
                                          ((min_l[i][b] == LLONG_MAX || min_l[a][j] == LLONG_MAX) ? LLONG_MAX : min_l[i][b] + c + min_l[a][j]) });
                        }
                }
                for (int i = 1;i <= n;i++) {
                    near_airport[i] = LLONG_MAX;
                    for (int j = 1;j <= k;j++) {
                        near_airport[i] = min(near_airport[i], min_l[i][airports[j]]);
                    }
                }
                break;
            case 2:
                cin >> a;
                airports[++k] = a;
                for (int i = 1;i <= n;i++) {
                    near_airport[i] = min(near_airport[i], min_l[i][airports[k]]);
                }
                break;
            case 3:
                ll anss = 0;
                for (int i = 1;i <= n;i++) {
                    for (int j = 1;j <= n;j++) {
                        ll res = min(min_l[i][j],
                            ((near_airport[i] == LLONG_MAX || near_airport[j] == LLONG_MAX) ? LLONG_MAX : near_airport[i] + t + near_airport[j]));
                        anss += (res == LLONG_MAX ? 0 : res);
                    }
                }
                cout << anss << '\n';
        }
    }
}