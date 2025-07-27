#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,ans[10]={0};
    cin>>m>>n;
    for(int i=m;i<=n;i++){
        for(int j=i;j;j/=10){
            ans[j%10]++;
        }
    }
    for(int i=0;i<10;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
