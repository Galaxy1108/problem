#include <bits/stdc++.h>
using namespace std;

map<string , vector<int> > ns;

int main(){
    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        int n2;
        cin>>n2;
        for(int j=0;j<n2;j++){
            string a1;
            cin>>a1;
            ns[a1].push_back(i+1);
        }
    }
    int n3;
    cin>>n3;

    for(int i=0;i<n3;i++){
        string a2;
        cin>>a2;
        bool cnt[n1]={0};
        for(int j=0;j<ns[a2].size();j++){
            if(!cnt[ns[a2][j]-1]){
                if(j==ns[a2].size()-1){
                    cout<<ns[a2][j];
                    cnt[ns[a2][j]-1]=true;
                }else{
                    cout<<ns[a2][j]<<" ";
                    cnt[ns[a2][j]-1]=true;
                }
            }
        }
        puts("");
    }
    return 0;
}
