#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s[3];
    cin >> s[0] >> s[1] >> s[2];
    sort(s, s + 3);
    cout << ((s[0] * s[1] == s[2]) ? "Yes" : "No");
    return 0;
}