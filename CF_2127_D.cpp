#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> a[200005];
int in[200005], IN[200005];
ll f[200005];

#define mod 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    f[0] = 1;
    for (int i = 1;i <= 200000;i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0;i <= n;i++) {
            a[i].clear();
            in[i] = 0;
        }
        for (int i = 1;i <= m;i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
            in[u]++, in[v]++;
        }
        if (m >= n) {
            cout << 0 << '\n';
            continue;
        }
        if (n == 2) {
            cout << 2 << '\n';
            continue;
        }
        int sta = -1;
        bool flag = false;
        ll anss = 1, cntt = 0;
        for (int u = 1;u <= n;u++) {
            if (in[u] == 1) {
                continue;
            }
            IN[u] = in[u];
            int cnts = 0;
            for (vector<ll>::iterator its = a[u].begin(); its != a[u].end(); its++) {
                if(in[*its]!=1){
                    cnts++;
                } else {
                    IN[u]--;
                }
            }
            if (IN[u] > 2) {
                flag = true;
                cout << 0 << '\n';
                break;
            }
            if (IN[u] <= 2) {
                anss = (anss * f[in[u] - IN[u]]) % mod;
                cntt++;
            }
        }
        if (flag) {
            continue;
        }
        // int its = sta, fat = -1;
        
        // flag = true;
        // while (1) {
        //     anss *= f[in[its] - IN[its]];
        //     anss %= mod;
        //     int nxt = -1;
        //     nxt = (a[its][0] != fat && a[its].size() >= 1 ? a[its][0] : nxt);
        //     nxt = (nxt == -1 && a[its].size() == 2 && a[its][1] != fat ? a[its][1] : nxt);
        //     if (nxt == -1) {
        //         flag = (its != sta);
        //         break;
        //     }
        //     fat = its, its = nxt;
        // }
        cout << (((anss * 2) % mod) * (1 + (cntt > 1))) % mod << '\n';
    }
}