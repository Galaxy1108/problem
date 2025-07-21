#include <bits/stdc++.h>
using namespace std;

long long get_c(long long p){
    return  p * (p-1) * (p-2) / 6;
}

int main(){
    // for (int i = 0; i <= 1001;i++){
    //     for (int j = 0; j <= i;j++){
    //         if(j==0){
    //             c[i][j] = 1;
    //         }else{
    //             c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    //         }
    //     }
    // }
    int n, m;
    cin >> n >> m;
    unsigned long long anss = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            anss += 2 * (n - i + 1) * (m - j + 1) * (__gcd(i, j) - 1);
        }
    }
    cout << get_c((n + 1) * (m + 1)) - anss - (m + 1) * get_c(n + 1) - (n + 1) * get_c(m + 1);
}