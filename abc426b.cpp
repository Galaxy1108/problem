#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int main() {
    string str;
    cin >> str;
    char c1, c2;
    int n1 = 0, n2 = 0;
    for (int i = 0;i < str.size();i++) {
        if (n1 == 0) {
            c1 = str[i];
            n1++;
        }
        if (str[i] != c1) {
            if (n2 == 0) {
                c2 = str[i];
            }
            n2++;
        }
    }
    cout << (n1 < n2 ? c1 : c2);
}