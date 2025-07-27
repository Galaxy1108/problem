#include <iostream>
using namespace std;

int main(){
    int n, m, s = 0;
    cin >> n >> m;
    int sn[n];
    for (int i = 0; i < n;i++){
        sn[i] = 0;
    }
    int j = 1;
    for (int i = 0; i < n;i++){
        if(s==n){
            break;
        }
        if(j==m && !sn[i]){
            j = 1;
            sn[i] = 1;
            s++;
            cout << i + 1 << " ";
            if(i==n-1){
                i = -1;
            }
            continue;
        }
        if(!sn[i]){
            j++;
        }
        if(i==n-1){
            i = -1;
        }
    }
    return 0;
}