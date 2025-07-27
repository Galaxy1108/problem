#include <bits/stdc++.h>
using namespace std;

long long main(){
    string s;
    cin >> s;
    for (long long i = 0; i < (long long)s.size(); i++) {
        if (i + 1 < s.size() && i>=0 && s[i] == 'W' && s[i + 1] == 'A') {
            s[i]='A', s[i+1]='C';
            i -= 2;
        }
    }
    cout << s;
    return 0;
}