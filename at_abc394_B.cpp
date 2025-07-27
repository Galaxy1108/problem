#include <bits/stdc++.h>
using namespace std;

string sts[51];

bool cmp(string a,string b){
    return a.size() < b.size();
}

long long main(){
    long long n;
    cin >> n;
    for (long long i = 0; i < n;i++){
        cin >> sts[i];
    }
    sort(sts, sts + n, cmp);
    for (long long i = 0; i < n;i++){
        cout << sts[i];
    }
    return 0;
}