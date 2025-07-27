#include <bits/stdc++.h>
using namespace std;

struct mf{
    int t=0,b=0;
    bool operator==(mf a){
        return (b==a.b) && (t==a.t);
    }
};

bool cmp(mf a,mf c){
    return (a.t+a.b)>(c.t+c.b);
}

int n,t;

int main(){
    //freopen("P3619_2.in","r",stdin);
    int nn;
    cin>>nn;
    while(nn--){
        bool e=false;
        cin>>n>>t;
        mf r[n]={{0,0}};
        if(t<=0){
            cout<<"-1s\n";
            continue;
        }
        for(int i=0;i<n;i++){
            cin>>r[i].t>>r[i].b;
        }
        sort(r,r+n,cmp);
        for(int i=0;i<n;i++){
            if(t>r[i].t){
                t+=r[i].b;
            }else{
                cout<<"-1s\n";
                e=true;
                break;
            }
            if(t<=0){
                cout<<"-1s\n";
                e=true;
                break;
            }
        }
        if(!e && t>0){
            cout<<"+1s\n";
        }
    }
    return 0;
}
