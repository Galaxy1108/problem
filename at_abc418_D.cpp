#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    long long cnt0 = 1, cnt1 = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            p ^= 1;
        }
        if (!p) {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    cout << (cnt0 * (cnt0 - 1)) / 2 + (cnt1 * (cnt1 - 1)) / 2 << '\n';
    return 0;
}