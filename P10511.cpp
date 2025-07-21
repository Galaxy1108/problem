#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll l[200005], r[200005], b[200005];
ll a[200005], aa[200005];

#define mod 998244353


int main(){
    ll n, m, q;
    cin >> n >> m >> q;
    for (ll i = 1; i <= m;i++){
        cin >> l[i] >> r[i] >> b[i];
        b[i] %= mod;
        a[i] = (a[i - 1] + (b[i] * ((r[i] - l[i] + 1 + mod) % mod) % mod)) % mod;
        aa[i] = (aa[i - 1] + ((b[i] * b[i] % mod) * ((r[i] - l[i] + 1 + mod) % mod) % mod)) % mod;
    }
    l[m + 1] = LLONG_MAX;
    while(q--){
        ll x, y;
        cin >> x >> y;
        ll xidx = upper_bound(l, l + m + 1, x) - l - 1;
        ll yidx = lower_bound(r, r + m, y) - r;
        // cout << "1." << aa[yidx] - aa[xidx - 1] << '\n';
        ll part_11 = (aa[yidx] - aa[xidx - 1] + mod) % mod;
        ll part_12 = ((r[yidx] - y + mod) % mod) * (b[yidx] * b[yidx] % mod) % mod;
        ll part_13 = ((x - l[xidx] + mod) % mod) * (b[xidx] * b[xidx] % mod) % mod;
        ll part_1 = (part_11 - part_12 - part_13 + 2 * mod) % mod;
        ll part_21 = (a[yidx] - a[xidx - 1] + mod) % mod;
        ll part_22 = ((r[yidx] - y + mod) % mod) * b[yidx] % mod;
        ll part_23 = ((x - l[xidx] + mod) % mod) * b[xidx] % mod;
        ll part_2 = (part_21 - part_22 - part_23 + 2 * mod) % mod;
        ll part_A = ((y - x + 1 + mod) % mod) * part_1 % mod;
        ll part_B = (part_2 * part_2) % mod;
        cout << (part_A - part_B + mod) % mod << '\n';
    }
}
