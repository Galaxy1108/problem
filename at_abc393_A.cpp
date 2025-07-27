#include <bits/stdc++.h>
using namespace std;

long long main(){
    string a, b;
    cin>>a>>b;
    if(a=="sick" && b=="sick"){
        cout << 1;
    }else if(a=="sick" && b!="sick"){
        cout << 2;
    }else if(a!="sick" && b=="sick"){
        cout << 3;
    }else{
        cout << 4;
    }
}