#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    string str;
    cin >> str;
    int i = 0;
    while (i < str.size() && str[i] == 'o') {
        i++;
    }
    cout << str.substr(i) << endl;
    return 0;
}
