#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
using ll = long long;

ll fast_pow(ll a,ll b){
    ll anss = 1;
    while(b){
        if(b&1){
            anss = (a * anss) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

ll inv(ll a){
    return fast_pow(a, mod - 2);
}

ll sn[405][805];

int main(){
    int n;
    cin >> n;
    int m = 2 * n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> sn[i][j];
            sn[i][n + i] = 1;
        }
    }
    for (int a = 1; a <= n;a++){
        int max_i = a;
        for (int i = a + 1; i <= n;i++){
            if(sn[max_i][a]<sn[i][a]){
                max_i = i;
            }
        }
        swap(sn[a], sn[max_i]);
        if(sn[a][a]==0){
            cout << "No Solution";
            return 0;
        }
        ll div = inv(sn[a][a]);
        for (int i = 1; i <= m;i++){
            sn[a][i] = (sn[a][i] * div) % mod;
        }
        for (int i = 1; i <= n;i++){
            if(i==a){
                continue;
            }
            for (int j = m; j >= a;j--){
                sn[i][j] -= (sn[a][j] * sn[i][a]) % mod;
                sn[i][j] = (sn[i][j] + mod) % mod;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = n + 1; j <= m;j++){
            cout << sn[i][j] << " \n"[j == m];
        }
    }
}