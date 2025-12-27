#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll scnt[200005], fat[200005];
ll prec[200005], nxtc[200005];
vector<ll> trr[200005];
bool istag[200005];
ll lidx, ridx;

void get_scnt(ll u, ll f) {
    scnt[u] = 1;
    fat[u] = f;
    for (ll v : trr[u]) {
        if (v == f) {
            continue;
        }
        get_scnt(v, u);
        scnt[u] += scnt[v];
    }
}

int main() {
    ll n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        trr[u].push_back(v);
        trr[v].push_back(u);
        prec[i] = nxtc[i] = -1;
    }
    prec[n - 1] = nxtc[n - 1] = -1;
    get_scnt(0, -1);
    ll ans = 1;
    //mex(l) = 1
    ll sumc = 0;
    for(ll v : trr[0]) {
        ans += (ll)scnt[v] * (sumc + 1);
        sumc += scnt[v];
    }
    //mex(l) > 1
    istag[0] = true;
    lidx = 0, ridx = 0;
    for (int i = 1; i < n; i++) {
        ll u = i;
        if (!istag[u]) {
            while (!istag[u]) {
                istag[u] = true;
                prec[fat[u]] = u;
                nxtc[u] = fat[u];
                u = fat[u];
            }
            if (u == lidx) {
                lidx = i;
            } else if (u == ridx) {
                ridx = i;
            } else {
                break;
            }
        }
        ll nxtl = max(prec[lidx], nxtc[lidx]);
        ll prer = max(prec[ridx], nxtc[ridx]);
        ans += (scnt[lidx] - (nxtl != fat[lidx] ? scnt[nxtl] : 0)) * (scnt[ridx] - (prer != fat[ridx] ? scnt[prer] : 0));
    }
    cout << ans;
    return 0;
}
