#include <bits/stdc++.h>
using namespace std;

long long main(){
    double a;
    cin >> a;
    long long ks = a * 10;
    if(ks>=380){
        cout << 1;
    }else if(ks>=375){
        cout << 2;
    }else{
        cout << 3;
    }
}