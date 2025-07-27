#include <bits/stdc++.h>
using namespace std;

long long main(){
    string s;
    cin >> s;
    long long anss = 0;
    for (long long i = 0; i < s.size();i++){
        for (long long p = 1; i + 2 * p < s.size();p++){
            if(s[i]=='A' && s[i+p]=='B' && s[i+2*p]=='C'){
                anss++;
            }
        }
    }
    cout << anss;
}