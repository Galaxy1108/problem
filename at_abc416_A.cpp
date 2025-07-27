#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    string str;
    cin >> str;
    for (int i = l;i <= r;i++) {
        if (str[i - 1] != 'o') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}