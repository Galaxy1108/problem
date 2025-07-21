#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
unsigned long long j[2005];

unsigned long long fast_pow(unsigned long long a,unsigned long long b){
    unsigned long long anss = 1;
    while(b){
        if(b&1){
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

unsigned long long inv(unsigned long long a){
    return fast_pow(a, mod - 2);
}

unsigned long long get_c(unsigned long long a,unsigned long long b){
    // cout << j[a]*inv(j[b] * j[a - b]) << endl;
    return (j[a] * inv(j[b] * j[a - b])) % mod;
}

int C[1003][1003];

int main(){
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= i; j++){
            C[i][j] = (j == 0 || j == i ? 1 : C[i - 1][j] + C[i - 1][j - 1]);
            C[i][j] %= mod;
        }
    }
    j[0] = 1;
    for (int i = 1; i <= 2000;i++){
        j[i] = (j[i - 1] * i) % mod;
    }
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        if(m-2*k<0 || m-2*k>n-k){
            cout << 0 << '\n';
        }else{
            cout << (((C[n][k] * fast_pow(2, m - 2 * k)) % mod) * C[n - k][m - 2 * k]) % mod << '\n';
            // cout << get_c(n, k) << ' ' << fast_pow(2, m - 2 * k) << ' ' << get_c(n - k, m - 2 * k) << '\n';
        }
    }
}