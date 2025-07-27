#include <bits/stdc++.h>
using namespace std;

map<pair<long long, long long>, bool> s;

long long main(){
    long long n, m;
    cin >> n >> m;
    long long anss = 0;
    for (long long i = 0; i < m;i++){
        long long u, v;
        cin >> u >> v;
        if(u==v){
            anss++;
        }else if(s[{u,v}] || s[{v,u}]){
            anss++;
        }else{
            s[{u, v}] = true;
        }
    }
    cout << anss;
}