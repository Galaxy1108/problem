#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    if (str[0] == '0') {
        for (int i = 1; i < str.size(); i++) {
            if (str[i] != '0') {
                swap(str[0], str[i]);
                break;
            }
        }
    }
    cout << str;
}
