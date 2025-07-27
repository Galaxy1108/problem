#include <bits/stdc++.h>
using namespace std;

int rr[10100][10100];

struct coordinate{
    int x=0,y=0,z=0,t=0;
};

int main(){
    int n;
    cin>>n;
    //int rr[n+1][n+1]={0};
    rr[1][n/2+1]=1;
    coordinate times;
    times.y=1;
    times.x=n/2+1;
    for(int i=2;i<=n*n;i++){
        if(times.y==1 && times.x!=n){
            //cout<<i<<endl;
            rr[n][times.x+1]=i;
            times.y=n;
            times.x=times.x+1;
        }else if(times.x==n && times.y!=1){
            rr[times.y-1][1]=i;
            times.y=times.y-1;
            times.x=1;
        }else if(times.y==1 && times.x==n){
            rr[times.y+1][times.x]=i;
            times.y=times.y+1;
        }else if(rr[times.y-1][times.x+1]==0){
            rr[times.y-1][times.x+1]=i;
            times.y=times.y-1;
            times.x=times.x+1;
        }else{
            rr[times.y+1][times.x]=i;
            times.y=times.y+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<rr[i][j]<<" ";
        }
        puts("");
    }
    return 0;
}
