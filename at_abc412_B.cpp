#include <bits/stdc++.h>
using namespace std;

map<char, bool> m;

long long main(){
    string a,b;
    cin>>a>>b;
    for(long long i=0;i<b.size();i++){
        m[b[i]] = true;
    }
    bool flag = true;
    for (long long i = 1; i < a.size();i++){
        if(a[i]<='Z' && a[i]>='A'){
            if(!m[a[i-1]]){
                flag=false;
                cout << "No";
                break;
            }
        }
    }
    if(flag){
        cout << "Yes";
    }
}