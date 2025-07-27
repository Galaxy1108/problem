#include <bits/stdc++.h>
using namespace std;

int sn[105];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> sn[i];
    }
    int num;
    cin >> num;
    for (int i = 1;i<=n;i++){
        if(sn[i]==num){
            cout<<"Yes";
            return 0;
        }
    }
    cout << "No";
}