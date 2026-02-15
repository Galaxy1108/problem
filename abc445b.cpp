#include <bits/stdc++.h>
using namespace std;

string str[105];

int main() {
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        m = max(m, (int)str[i].size());
    }
    for (int i = 0; i < n; i++) {
        int k = (m - (int)str[i].size()) / 2;
        string t;
        for (int j = 0; j < k; j++) {
            t += '.';
        }
        t += str[i];
        for (int j = 0; j < k; j++) {
            t += '.';
        }
        cout << t << "\n";
    }
    return 0;
}
