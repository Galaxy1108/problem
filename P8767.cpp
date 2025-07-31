#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

using ll = long long;
ll n, m, k;

multiset<pair<ll, ll>> s;

int main() {
    ll add = 0, anss = 0, all_cnts = 0;
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) {
        ll v;
        cin >> v;
        s.insert({ v,1 });
        anss = (anss + v) % mod;
        all_cnts++;
    }
    for (int i = 1;i <= m;i++) {
        ll x, y;
        cin >> x >> y;
        for (auto its = s.begin();its != s.end();) {
            auto next_its = next(its);
            ll size = its->first + add, cnts = its->second;
            if (size + x <= 0) {
                anss = (anss - (size * cnts % mod) + mod) % mod, all_cnts = (all_cnts - cnts + mod) % mod;
                next_its = s.erase(its);
                its = next_its;
                continue; 
            }
            break;
        }
        anss = (anss + ((all_cnts * x) % mod) + mod) % mod;
        ll one_cnts = 0, k_cnts = 0;
        for (auto its = s.rbegin();its != s.rend();) {
            auto next_its = next(its);
            ll size = its->first + add, cnts = its->second;
            if (size + x > k) {
                one_cnts = (one_cnts + ((size + x - k) * cnts) % mod) % mod;
                k_cnts = (k_cnts + cnts) % mod;
                next_its = multiset<pair<ll, ll>>::reverse_iterator(s.erase((++its).base()));
                its = next_its;
                continue;
            }
            break;
        }
        all_cnts = (all_cnts + (one_cnts + (y != 0))) % mod;
        anss = (anss + y) % mod, add += x;
        if (k_cnts) {
            s.insert({ k - add,k_cnts });
        }
        if (one_cnts) {
            s.insert({ 1 - add,one_cnts });
        }
        if (y != 0) {
            s.insert({ y - add,1 });
        }
        cout << anss << '\n';
    }
}