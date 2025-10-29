#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct s{
    ll a, b;
};

s sn[200005];
s p[10000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll min_a = LLONG_MAX;
    for (int i = 1; i <= m;i++){
        cin >> sn[i].a >> sn[i].b;
        min_a = min(min_a, sn[i].a);
    }
    sort(sn + 1, sn + 1 + m, [](s a, s b)
         { return (a.a == b.a ? (a.a - a.b < b.a - b.b) : (a.a < b.a)); });
    ll maxs = LLONG_MAX, tops = 0;
    for (int i = 1; i <= m;i++){
        if(sn[i].a-sn[i].b<maxs){
            p[++tops] = {sn[i].a, sn[i].a - sn[i].b};
            maxs = sn[i].a - sn[i].b;
        }
    }
    long long anss = 0;
    while(n>=min_a){
        int l = 1, r = tops;
        while(l<r){
            int mid = (l + r + 1) / 2;
            if(p[mid].a<=n){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        long long cnts = ((n - p[l].a) / p[l].b) + 1;
        anss += cnts;
        n -= cnts * p[l].b;
        // cout << cnts << ' ' << p[l].b << ' ' << n << endl;
    }
    cout << anss;
}