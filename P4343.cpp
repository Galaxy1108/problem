#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll sn[100005];
ll l, k;

ll check(ll n){
    ll lines = 0, cnts = 0;
    for (int i = 1; i <= l;i++){
        lines = max(0ll, lines + sn[i]);
        if(lines>=n){
            lines = 0;
            cnts++;
        }
    }
    return cnts;
}

int main(){
    cin >> l >> k;
    ll L = 1, R = LLONG_MAX - 1;
    for (int i = 1; i <= l;i++){
        cin >> sn[i];
    }
    ll anss1 = -1;
    while(L<R){
        ll mid = (L + R) / 2;
        if(check(mid)>k){
            L = mid + 1;
        }else{
            if(check(mid)==k){
                anss1 = mid;
            }
            R = mid;
        }
    }
    L = 1, R = LLONG_MAX - 1;
    ll anss2 = -1;
    while(L<R){
        ll mid = (L + R + 1) / 2;
        if(check(mid)<k){
            R = mid - 1;
        }else{
            if(check(mid)==k){
                anss2 = mid;
            }
            L = mid;
        }
    }
    if(anss1==-1){
        cout << -1;
        return 0;
    }
    cout << anss1 << ' ' << anss2;
    return 0;
}