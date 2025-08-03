/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-07-27 22:30:11
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-03 22:00:07
 * @FilePath: \problem\AT_arc170_C.cpp
 * @Description: 
 */
/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-07-27 22:30:11
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-03 21:57:50
 * @FilePath: \problem\AT_arc170_C.cpp
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll sn[5005];
ll dp[5005][5005];
#define mod 998244353

int main(){
    // freopen("mex.in", "r", stdin);
    // freopen("mex.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> sn[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = max(0ll,i - m - 1); j < i;j++){
            if(sn[i]==1){
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            ll part_1 = dp[i - 1][j] * (m - (i - 1) + j) % mod;
            ll part_2 = dp[i - 1][j - 1] * (i - j) % mod;
            dp[i][j] = (part_1 + part_2) % mod;
        }
    }
    ll anss = 0;
    for (int j = max(0ll, n - m -1); j < n;j++){
        anss = (anss + dp[n][j]) % mod;
    }
    cout << anss;
}