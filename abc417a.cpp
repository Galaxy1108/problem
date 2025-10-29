#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string str;
    cin >> str;
    for (int i = b;i < str.size() - c;i++) {
        cout << str[i];
    }
}