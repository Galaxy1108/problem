#include <bits/stdc++.h>
using namespace std;

long long main(){
    string str;
    cin >> str;
    size_t sizes = str.size();
    long long anss = -1;
    for (long long i = 0; i < sizes;i++){
        anss = i;
        for (long long l = i, r = sizes - 1; l <= r;l++,r--){
            if(str[l]!=str[r]){
                anss = -1;
                break;
            }
        }
        if(anss!=-1){
            break;
        }
    }
    cout << str;
    for (long long i = anss - 1; i >= 0;i--){
        cout << str[i];
    }
}