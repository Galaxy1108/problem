#include <bits/stdc++.h>
using namespace std;

string ans1, m1, m2;
map<char, char> a, b;

int main() {
    cin >> m1 >> ans1 >> m2;
    for (int i = 0; i < m1.size();i++) {
        if ((a.count(m1[i]) && a[m1[i]] != ans1[i]) || (b.count(ans1[i]) && b[ans1[i]] != m1[i])) {
            cout << "Failed";
            return 0;
        } else {
            a[m1[i]] = ans1[i];
            b[ans1[i]] = m1[i];
        }
    }
    for (char i = 'A'; i <= 'Z';i++) {
        if (!b.count(i)) {
            cout << "Failed";
            return 0;
        }
    }
    for (int i = 0; i < m2.size();i++) {
        if (m2[i] == ' ') {
            continue;
        }
        cout << a[m2[i]];
    }
    return 0;
}