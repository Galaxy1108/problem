#include <bits/stdc++.h>
using namespace std;

#define mod 1000000009

long long a[2005], b[2005];
long long cnt[2005], j[2005], g[2005];
long long c[2005][2005];
long long dp[2005][2005];

// long long fast_pow(long long a,long long b){
//     long long anss = 1;
//     while(b){
//         if(b&1){
//             anss = (anss * a) % mod;
//         }
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return anss;
// }

// long long inv(long long a){
//     return fast_pow(a, mod - 2);
// }

int main(){
    for (int i = 0; i <= 2001;i++){
        for (int j = 0; j <= i;j++){
            if(j==0){
                c[i][j] = 1;
            }else{
                c[i][j] += (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
    int n, k;
    cin >> n >> k;
    if((n-k)&1){
        cout << 0;
        return 0;
    }
    k = (n + k) / 2;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    sort(b + 1, b + 1 + n);
    int a_i = 1, b_i = 0;
    for (int i = 1; i <= n;i++){
        while (b_i < n && b[b_i + 1] < a[i]){
            b_i++;
        }
        cnt[i] = b_i;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n;i++){
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j <= i;j++){
            dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - 1] * max(0ll, cnt[i] - j + 1)) % mod;
            dp[i][j] %= mod;
        }
    }
    j[0] = 1;
    for (int i = 1; i <= n;i++){
        j[i] = (j[i - 1] * i) % mod;
    }
    for (int i = 0; i <= n;i++){
        g[i] = (dp[n][i] * j[n - i]) % mod;
        // cout << g[i] << " ";
    }
    // long long anss = 0;
    // for (int i = k; i <= n;i++){
    //     if((i-k)&1){
    //         anss -= (c[i][k] * g[i]) % mod;
    //         anss = (anss + mod) % mod;
    //     }else{
    //         anss += (c[i][k] * g[i]) % mod;
    //         anss %= mod;
    //     }
    //     // cout << anss << endl;
    // }
    long long anss = 0;
    for (int i = 1; i <= n;i++){
        
    }
        cout << (anss + mod) % mod;
}