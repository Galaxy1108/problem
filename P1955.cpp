#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fat[1000005];
ll u[1000005], v[1000005];
ll nums[2000005], numt;
ll x[200005], y[200005], e[200005];

ll get_fat(ll a){
    return (a == fat[a] ? a : fat[a] = get_fat(fat[a]));
}

unordered_map<int, int> m;

int main(){
    ll T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        for (ll i = 0; i <= n;i++){
            fat[i] = i;
        }
        ll cnts = 0;
        numt = 0;
        for (ll i = 1; i <= n;i++){
            cin >> x[i] >> y[i] >> e[i];
            nums[++numt] = x[i], nums[++numt] = y[i];
        }
        sort(nums + 1, nums + 1 + numt);
        numt = unique(nums + 1, nums + 1 + numt) - nums - 1;
        m.clear();
        for (int i = 1; i <= numt;i++){
            m[nums[i]] = i;
        }
        for (int i = 1; i <= n;i++){
            int X = m[x[i]], Y = m[y[i]];
            if(e[i] == 1){
                ll fat_x = get_fat(X), fat_y = get_fat(Y);
                if (fat_x != fat_y){
                    fat[fat_x] = fat_y;
                }
            }else{
                u[++cnts] = X, v[cnts] = Y;
            }
        }
        bool flag = true;
        for (ll i = 1; i <= cnts;i++){
            ll fat_x = get_fat(u[i]), fat_y = get_fat(v[i]);
            if(fat_x == fat_y){
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}