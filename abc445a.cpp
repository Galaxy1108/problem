#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] == s.back()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
