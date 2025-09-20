#include <iostream>
using namespace std;

char Rs(char b, char c) {
    char b_, c_;
    b_ = b - '@';
    c_ = c - '@';
    char a_;
    a_ = c_ - b_ + 1;
    if (a_ < 0) {
        a_ = a_ - (0 - 26);
    }
    if (a_ == 0) {
        a_ = 26;
    }
    a_ += '@';
    return a_;
}

void becomeUpper(string& str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    string b, c;
    cin >> b >> c;
    bool cs[c.size()] = { false };
    for (int i = 0; i < c.size();i++) {
        if (c[i] < '[') {
            cs[i] = true;
        }
    }
    becomeUpper(c);
    becomeUpper(b);
    char a[c.size()];
    for (int i = 0, j = 0; i < c.size();i++, j++) {
        a[i] = Rs(b[j], c[i]);
        if (j == b.size() - 1)
            j = -1;
    }
    for (int i = 0; i < c.size();i++) {
        if (cs[i] == false) {
            a[i] += ' ';
        }
    }
    for (int i = 0; i < c.size();i++) {
        cout << a[i];
    }
    return 0;
}