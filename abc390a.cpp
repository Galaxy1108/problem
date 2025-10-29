#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    if(s=="2 1 3 4 5" || s=="1 3 2 4 5" || s=="1 2 4 3 5" || s=="1 2 3 5 4"){
        cout << "Yes";
    }else{
        cout << "No";
    }
}