#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long adds = 1;
    for (long long i = 0; i < s.size();i++) {
        if ((i + adds) % 2 && s[i] != 'i') {
            adds++;
        } else
            if (!((i + adds) % 2) && s[i] != 'o') {
                adds++;
            }
    }
    adds += (s.size() + adds - 1) % 2;
    cout << adds;
}