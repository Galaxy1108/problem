#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define T 100001
#define F -100001
#define U 0

ll fat[200005];
bool vis[200005];

ll n, m;

ll find_father(ll a) {
    // cout << a << endl;
    if (a == T || a == F) {
        return a;
    }
    if (vis[n-a] || a == U) {
        return U;
    }
    if (vis[n+a]){
        return T;
    }
    if (a < 0) {
        if (a == -fat[-a]) {
            return a;
        }
        vis[n + a] = true;
        ll res = find_father(-fat[-a]);
        vis[n + a] = false;
        return res;
    }
    if (a == fat[a]) {
        return a;
    }
    vis[n+a] = true;
    fat[a] = find_father(fat[a]);
    vis[n+a] = false;
    return fat[a];
}

int main(){
    ll c, t;
    cin >> c >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1;i <= n;i++) {
            fat[i] = i;
        }
        for (int i = 1;i <= m;i++) {
            char opt;
            ll a, b;
            cin >> opt;
            switch (opt){
            case 'T':
                cin >> a;
                fat[a] = T;
                break;
            case 'F':
                cin >> a;
                fat[a] = F;
                break;
            case 'U':
                cin >> a;
                fat[a] = U;
                break;
            case '+':
                cin >> a >> b;
                fat[a] = fat[b];
                break;
            case '-':
                cin >> a >> b;
                fat[a] = -fat[b];
                break;
            }
            // cout << i << endl;
        }
        ll anss = 0;
        for (int i = 1;i <= n;i++) {
            if (find_father(i) == U) {
                anss++;
            }
        }
        cout << anss << '\n';
    }
}