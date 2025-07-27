#include <bits/stdc++.h>
using namespace std;

long long st[300],tops;
long long cnts;

bool i_empty(){
    return !tops;
}

void push(long long x){
    st[++tops] = x;
}

long long top(){
    if(i_empty()){
        cnts--;
        return 0;
    }
    return st[tops--];
}

long long main(){
    cnts = 100;
    long long q;
    cin >> q;
    while(q--){
        long long opt;
        cin>>opt;
        if(opt==1){
            long long x;
            cin>>x;
            push(x);
        }else{
            cout << top() << '\n';
        }
    }
}