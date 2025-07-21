#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sn[55], p[55];

void insert(ll num){
    for (int i = 50; i >= 0;i--){
        if(num&(1ull<<i)){
            if(!p[i]){
                p[i] = num;
                return;
            }else{
                num ^= p[i];
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> sn[i];
        insert(sn[i]);
    }
    ll anss = 0;
    for (int i = 50; i >= 0;i--){
        anss = max(anss, anss ^ p[i]);
    }
    cout << anss;
}