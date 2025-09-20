#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll father[1005];

ll get_father(ll a) {
    return (father[a] == a ? a : father[a] = get_father(father[a]));
}

ll in_low[1005], low_cnt;
ll in_top[1005], top_cnt;

struct coord {
    ll x, y, z;
    friend long long operator-(coord a, coord b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
    }
};

coord sn[1005];

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll n, h, r;
        cin >> n >> h >> r;
        for (ll i = 0;i <= n;i++) {
            father[i] = i;
        }
        top_cnt = 0;
        low_cnt = 0;
        for (ll i = 1;i <= n;i++) {
            cin >> sn[i].x >> sn[i].y >> sn[i].z;
            if (h - sn[i].z <= r) {
                in_top[top_cnt++] = i;
            }
            if (sn[i].z <= r) {
                in_low[low_cnt++] = i;
            }
            for (ll j = 1;j < i;j++) {
                coord a = sn[i], b = sn[j];
                ll father_a = get_father(i), father_b = get_father(j);
                if (father_a == father_b) {
                    continue;
                }
                if (a - b <= 4 * r * r) {
                    father[father_a] = father_b;
                }
            }
        }
        bool flag = true;
        for (ll i = 0;i < top_cnt && flag;i++) {
            for (ll j = 0;j < low_cnt;j++) {
                if (get_father(in_top[i]) == get_father(in_low[j])) {
                    cout << "Yes\n";
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "No\n";
        }
    }
} 