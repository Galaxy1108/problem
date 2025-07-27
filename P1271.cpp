#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>m>>n;
    int sn[n];
    for(int i=0;i<n;i++){
        cin>>sn[i];
    }
    sort(sn,sn+n);
    for(int i=0;i<n;i++){
        cout<<sn[i]<<" ";
    }
    return 0;
}
