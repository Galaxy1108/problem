#include <bits/stdc++.h>
using namespace std;

int as[26]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,};

int main(){
    int n;
    cin>>n;

    if(n%2==1){ cout << "-1"; return 0; }

    for(int i=25;i>=0;i--){
        if(n>=as[i]){
            n-=as[i];
            cout<<as[i]<<" ";
        }
    }
    return 0;
}