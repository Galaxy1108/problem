#include <bits/stdc++.h>
using namespace std;

bool is_can[1 << 18];
bool dp[19][1 << 18];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i < (1 << n);i++){
            char a;
            cin >> a;
            if(a=='1'){
                is_can[i] = false;
            }else{
                is_can[i] = true;
            }
        }
        dp[0][0] = true;
        for (int i = 1; i <= n;i++){
            for (int j = 1; j < (1 << n);j++){
                if(__builtin_popcount(j)!=i){
                    continue;
                }
                dp[i][j] = false;
                for (int k = 0; k < n;k++){
                    if(j&(1<<k)){
                        dp[i][j] |= (is_can[j] & dp[i - 1][j - (1 << k)]);
                    }
                }
            }
        }
        cout << (dp[n][(1 << n) - 1] ? "Yes\n" : "No\n");
    }
}