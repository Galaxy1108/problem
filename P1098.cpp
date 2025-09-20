#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int p1, p2, p3;
string str, anss;

//32

void unpack(char a, char b) {
    if (a >= b || !(('a' <= a && 'z' >= a && 'a' <= b && 'z' >= b) || ('0' <= b && '9' >= b && '0' <= a && '9' >= a))) {
        anss.push_back('-');
        //cout<<"c_unpack\n";
        return;
    }
    char c_begin = (p1 == 3 ? '*' : ((p3 == 2 ? b - 1 : a + 1) - (p1 - 1) * 32 * !('0' <= b && '9' >= b && '0' <= a && '9' >= a))),
        c_end = (p1 == 3 ? '*' : ((p3 == 2 ? a + 1 : b - 1) - (p1 - 1) * 32 * !('0' <= b && '9' >= b && '0' <= a && '9' >= a)));
    int  c_add = (p1 == 3 ? 0 : ((p3 == 2 ? -1 : 1)));
    int cnts = 1;
    //cout<<"unpack:"<<c_begin<<' '<<c_end<<' '<<c_add<<'\n';
    for (char outs = c_begin;(p3 == 1 ? outs <= c_end : outs >= c_end) && cnts <= (b - a - 1);outs += c_add) {
        for (int i = 0;i < p2;i++) {
            anss.push_back(outs);
        }
        cnts++;
    }
    return;
}

int main() {
    cin >> p1 >> p2 >> p3;
    cin >> str;
    for (int i = 0;i < str.size();i++) {
        if (str[i] != '-' || i == 0 || i == str.size() - 1) {
            anss.push_back(str[i]);
            continue;
        }
        //cout<<i<<' '<<str[i]<<'\n';
        unpack(str[i - 1], str[i + 1]);
    }
    cout << anss;
    return 0;
}
