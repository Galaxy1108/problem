#include <bits/stdc++.h>
using namespace std;

struct s{
    int times, ver;
};

int dp[200005], a[200005], tops, begins;
s que[200005];

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n;i++){
        cin >> a[i];
    }
    begins = 1;
    for (int i = 0; i <= n;i++){
        if(i>=l && dp[i-l]!=INT_MIN){
            while(tops>=begins && que[tops].ver<=dp[i-l]){
                tops--;
            }
            que[++tops] = {i - l, dp[i - l]};
        }
        while(begins<=tops && que[begins].times<i-r){
            begins++;
        }
        dp[i] = a[i] + que[begins].ver;
        if(begins>tops && i!=0){
            dp[i] = INT_MIN;
        }
    }
    int anss = INT_MIN;
    for (int i = 0; i < r;i++){
        anss = max(anss, dp[n - i]);
    }
    cout << anss;
}