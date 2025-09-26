#include <bits/stdc++.h>
using namespace std;

long long sn[105];

int main(){
    long long n;
    cin >> n;
    for (long long i = 0; i < n;i++){
        cin >> sn[i];
    }
    long long a, b;
    a = sn[0] / __gcd(sn[0], sn[1]);
    b = sn[1] / __gcd(sn[0], sn[1]);
    for (long long i = 2; i < n;i++){
        if(sn[i-1]/__gcd(sn[i-1],sn[i])!=a || sn[i]/__gcd(sn[i-1],sn[i])!=b){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}