#include <bits/stdc++.h>
using namespace std;

int ans=0;

struct tree{
    int l,r;
};

void DFS(int s,int c,tree* g){
    ans=max(ans,c);
    if(g[s].l==0 && g[s].r==0){
        return;
    }
    if(g[s].l){
        DFS(g[s].l,c+1,g);
    }
    if(g[s].r){
        DFS(g[s].r,c+1,g);
    }
}

int main(){
    int n;
    cin>>n;
    tree t[n+1];
    for(int i=1;i<=n;i++){
        cin>>t[i].l>>t[i].r;
    }
    DFS(1,1,t);
    cout<<ans;
    return 0;
}
