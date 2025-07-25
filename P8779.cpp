#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fat[10005], var[10005];
ll tmp;

ll get_father(ll a) {
    return (fat[a] == a ? a : (tmp = get_father(fat[a]), var[a] += var[fat[a]], fat[a] = tmp));
}

int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    for (int i = 0;i <= n;i++) {
        fat[i] = i;
        var[i] = 0;
    }
    for (int i = 1;i <= m;i++) {
        ll l, r, s;
        cin >> l >> r >> s;
        l--;
        ll fat_l = get_father(l), fat_r = get_father(r);
        if (fat_l != fat_r) {
            fat[fat_r] = fat_l;
            var[fat_r] = s + var[l] - var[r];
        }
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--;
        ll fat_l = get_father(l), fat_r = get_father(r);
        if (fat_l != fat_r) {
            cout << "UNKNOWN\n";
        } else {
            cout << var[r] - var[l] << '\n';
        }
    }
}