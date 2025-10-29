#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    bool iss = true;
    for(int i=0;i<str.size();i++){
        if(str[i]=='#'){
            if(iss){
                cout << i+1 << ',';
                iss = false;
            }else{
                cout << i + 1 << '\n';
                iss = true;
            }
        }
    }
}