#include <bits/stdc++.h>
using namespace std;

int x[1000005],p[1000005],c[1000005];
long long dp[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
//    freopen("storage.in", "r", stdin);
//    freopen("storage.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> p[i] >> c[i];
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    int s=100000000/n;
    for (int i = 1; i <= n;i++){
        long long sums = 0;
        for (int k = i - 1; k >= max(0,i - s);k--){
            dp[i] = min(dp[i], dp[k] + sums + c[i]);
            sums += p[k] * (x[i] - x[k]);
        }
    }
    long long anss=dp[n];
    for(int i=n;i>=1;i--){
        if(p[i]==0){
            anss = min(anss,dp[i - 1]);
        }else{
            break;
        }
    }
    cout << anss;
    return 0;
}