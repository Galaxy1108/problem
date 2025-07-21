#include <bits/stdc++.h>
using namespace std;

long long as[1005], c[1005][1005];
#define mod 1000000007



int main(){
    for (int i = 0; i <= 1000;i++){
        for (int j = 0; j <= i;j++){
            if(j==0){
                c[i][j] = 1;
            }else{
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        long long sums = 0;
        for (int i = 1; i <= m;i++){
            cin >> as[i];
            sums += as[i];
        }
        long long anss = 1, d = sums;
        for (int i = 1; i <= m;i++){
            anss = (anss * c[d][as[i]]) % mod;
            d -= as[i];
        }
        cout << anss << '\n';
    }
}