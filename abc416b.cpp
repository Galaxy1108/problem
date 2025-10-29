#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    bool is_can = true;
    for (int i = 0;i < str.size();i++) {
        if(is_can && str[i]=='.'){
            str[i] = 'o';
            is_can = false;
        }
        if(str[i]=='#'){
            is_can = true;
        }
    }
    cout << str;
    return 0;
}