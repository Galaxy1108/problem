#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int cnts[5005], as[100005];

long long get_c(int a,int k){
    if(k==1){
        return a;
    }
    return (a * 1ll * (a - 1) / 2) % mod;
}

int main(){
    int n;
    cin >> n;
    int maxs = 0;
    for (int i = 1; i <= n;i++){
        cin >> as[i];
        maxs = max(as[i], maxs);
        cnts[as[i]]++;
    }
    long long anss = 0;
    for (int i = 2; i <= maxs;i++){
        if(cnts[i]<2){
            continue;
        }
        int part_1 = get_c(cnts[i], 2);
        for (int j = 1; j <= i / 2;j++){
            if(j==i-j && cnts[j]>=2){
                anss += (part_1 * get_c(cnts[j], 2)) % mod;
                anss %= mod;
            }
            if(j!=i-j && cnts[j]>=1 && cnts[i-j]>=1){
                anss += (((part_1 * get_c(cnts[j], 1)) % mod) * get_c(cnts[i - j], 1)) % mod;
                anss %= mod;
            }
        }
    }
    cout << anss;
    return 0;
}