#include<bits/stdc++.h>
using namespace std;

struct g{
    int xd=0,nlj=0;
}t[2];

int main(){
    int n;
    cin>>n;
    n=1<<n;
    int tmp;
    for(int i=0;i<n/2;i++){
        cin>>tmp;
        if(tmp>t[0].nlj){
            t[0].nlj=tmp;
            t[0].xd=i+1;
        }
    }
    for(int i=n/2;i<n;i++){
        cin>>tmp;
        if(tmp>t[1].nlj){
            t[1].nlj=tmp;
            t[1].xd=i+1;
        }
    }
    if(t[0].nlj>t[1].nlj){
        cout<<t[1].xd;
    }else{
        cout<<t[0].xd;
    }
    return 0;
}
