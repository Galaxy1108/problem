#include <bits/stdc++.h>
using namespace std;

long long as[400005];
long long p[400005];
long long dp[400005];

long long h, w;

long long idx(long long i,long long j){
    return (i - 1) * w + j;
}

bool check(long long a){
    for (long long i = 0; i <= w;i++){
        dp[i] = -1;
    }
    dp[1] = a;
    for (long long i = 1; i <= h;i++){
        for (long long j = 1; j <= w;j++){
            dp[j] = max(dp[j - 1], dp[j]);
            if(dp[j]==-1 || dp[j]+as[idx(i,j)]-p[i+j-1]<0){
                dp[j] = -1;
            }else{
                dp[j] = dp[j] + as[idx(i, j)] - p[i + j - 1];
            }
        }
    }
    return dp[w] != -1;
}

int main(){
    cin >> h >> w;
    for (long long i = 1; i <= h;i++){
        for (long long j = 1; j <= w;j++){
            cin >> as[idx(i, j)];
        }
    }
    long long max_p = LLONG_MIN;
    for (long long i = 1; i < h + w;i++){
        cin >> p[i];
        max_p = max(max_p, p[i]);
    }
    long long l = 0, r = 2* (h + w) * max_p;
    while(l<r){
        long long mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}