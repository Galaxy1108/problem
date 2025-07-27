#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int size, bian;
        cin >> size >> bian;
        char sn1[size];
        string sn2(size, '.');
        int ans=0;
        int s1 = 0, s2 = 0;
        int size1 = size-1;
        for (int i = 0; i < size;i++){
            if(s1>0){
                s1--;
            }
            if(s2>0){
                s2--;
            }
            cin >> sn1[i];
            if(sn1[i]=='G' && (!s1)){
                if(i+bian<size-1){
                    sn2[i + bian] = 'G';
                    ans++;
                    s1 = 2 * bian + 1;
                }else{
                    sn2[size1] = 'G';
                    ans++;
                    s1 = 2 * bian + 1;
                    size1--;
                }
            }
            if(sn1[i]=='H' && (!s2)){
                if(i+bian<size-1){
                    sn2[i + bian] = 'H';
                    s2 = 2 * bian + 1;
                    ans++;
                }else{
                    sn2[size1] = 'H';
                    size1--;
                    s2 = 2 * bian + 1;
                    ans++;
                }
            }
        }
        cout << ans << endl
             << sn2 << endl;
    }
}