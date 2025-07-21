#include <bits/stdc++.h>
using namespace std;

#define mod 9999973
long long dp[105][205][205];
int n, m;

long long c_2(long long a){
    return ((a * (a - 1)) / 2) % mod;
}

long long k1(long long k,long long k2){
    return k - k2 * 2;
}

long long k0(long long k,long long k2){
    return n - k1(k, k2) - k2;
}

int main(){
    // freopen("chess.in", "r", stdin);
    // freopen("chess.out", "w", stdout);
    cin >> n >> m;
    dp[0][0][0] = 1;
    for (int i = 1; i <= m;i++){
        for (int k = 0; k <= 2 * i;k++){
            for (int k2 = 0; k2 <= k/2;k2++){
                // if(k2!=0){
                //     cout << dp[i][k][k2] << ' ' << i << ' ' << k << ' ' << k2 << '\n';
                // }
                dp[i][k][k2] = dp[i - 1][k][k2]; // 0
                if(k0(k - 1,k2) > 0 && k>=1){
                    dp[i][k][k2] += dp[i - 1][k - 1][k2] * k0(k - 1, k2) % mod; // 1
                    dp[i][k][k2] %= mod;
                }
                if(k1(k - 1, k2 - 1) > 0 && k>=1 && k2>=1){
                    dp[i][k][k2] += dp[i - 1][k - 1][k2 - 1] * k1(k - 1, k2 - 1) % mod; // 2
                    dp[i][k][k2] %= mod;
                }
                if(k0(k - 2, k2) > 0 && k>=2){
                    dp[i][k][k2] += dp[i - 1][k - 2][k2] * c_2(k0(k - 2, k2)) % mod; // 1 1
                    dp[i][k][k2] %= mod;
                }
                if(k0(k-2,k2-1) > 0 && k1(k-2,k2-1) > 0 && k>=2 && k2>=1){
                    dp[i][k][k2] += (dp[i - 1][k - 2][k2 - 1] * k1(k - 2, k2 - 1) % mod) * k0(k - 2, k2 - 1) % mod; // 1 2
                    dp[i][k][k2] %= mod;
                }
                if(k1(k-2,k2-2) > 0 && k>=2 && k2>=2){
                    dp[i][k][k2] += dp[i - 1][k - 2][k2 - 2] * c_2(k1(k - 2, k2 - 2)) % mod; // 2 2
                    dp[i][k][k2] %= mod;
                }
            }
            // cout << dp[i][k][k/2] << ' ' << i << ' ' << k << ' ' << k/2 << '\n';
        }
    }
    long long anss = 0;
    for (int k = 0; k <= 2 * n;k++){
        for (int k2 = 0; k2 <= k/2;k2++){
            anss = (anss + dp[m][k][k2]) % mod;
        }
    }
    cout << anss;
    return 0;
}