#include <bits/stdc++.h>
using namespace std;

void DFS(string s,string d){
    if (s.size()>0){
        char r=d[d.size()-1];
        cout<<r;
        int k=s.find(r);
        DFS(s.substr(0,k),d.substr(0,k));
        DFS(s.substr(k+1),d.substr(k,s.size()-(k+1)));
    }else{
        return;
    }
}

int main(){
    string a,b;
    cin>>a>>b;
    DFS(a,b);
    return 0;
}