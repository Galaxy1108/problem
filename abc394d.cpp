#include <bits/stdc++.h>
using namespace std;

stack<char> ks;

int main() {
    string s;
    cin >> s;
    for (long long i = 0; i < s.size();i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<') {
            ks.push(s[i]);
        } else {
            if (ks.empty()) {
                cout << "No";
                return 0;
            }
            if (s[i] == ')' && ks.top() == '(') {
                ks.pop();
            } else if (s[i] == ']' && ks.top() == '[') {
                ks.pop();
            } else if (s[i] == '>' && ks.top() == '<') {
                ks.pop();
            } else {
                cout << "No";
                return 0;
            }
        }
    }
    if (ks.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}