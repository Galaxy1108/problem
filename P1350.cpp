#include <bits/stdc++.h>
using namespace std;

#define mod 100003

long long dp[2005][1005];
int a, b, c, d, k;

int get_l(int s){
    return (s <= c ? d : b + d);
}

int main(){
    cin >> a >> b >> c >> d >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= a + c;i++){
        dp[i][0] = 1;
        for (int j = 1; j <= min(k,i);j++){
            dp[i][j] = (dp[i - 1][j] + (dp[i - 1][j - 1] * (get_l(i) - j + 1)) % mod) % mod;
        }
    }
    cout << dp[a + c][k];
}