#include <bits/stdc++.h>
using namespace std;

map<long long, long long> s;

int main() {
    long long sn[7];
    for (long long i = 0; i < 7;i++) {
        cin >> sn[i];
        s[sn[i]]++;
    }
    bool t2 = false, t3 = false;
    for (auto its : s) {
        if ((t3 && its.second >= 2) || its.second == 2) {
            t2 = true;
        }
        if (its.second >= 3) {
            t3 = true;
        }
    }
    cout << ((t2 && t3) ? "Yes" : "No");
}