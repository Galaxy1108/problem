#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0;i < str.size();i++) {
        if (i == str.size() / 2) {
            continue;
        }
        cout << str[i];
    }
}