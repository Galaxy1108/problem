#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mod 998244353
int sn[1005];
ll dp[1005][1005];
ll f[1005][1005];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> sn[i];
    }
    sn[0] = INT_MIN;
    sort(sn + 1, sn + 1 + n);
    ll anss = 0;
    for (int var = 1; var <= sn[n] / (k - 1);var++){
        int mlast_i = 0;
        ll res = 0;
        dp[0][0] = f[0][0] = 1;
        for (int i = 1; i <= n;i++){
            while(sn[i]-var>=sn[mlast_i]){
                mlast_i++;
            }
            for (int p = 0; p <= k;p++){
                if(p){
                    dp[i][p] = f[mlast_i - 1][p - 1];
                }
                f[i][p] = (f[i - 1][p] + dp[i][p]) % mod;
            }
            res = (res + dp[i][k]) % mod;
        }
        anss = (anss + res) % mod;
    }
    cout << anss;
}