#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> s;
long long sn[300005];

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n;i++) {
        cin >> sn[i];
        s[sn[i]]++;
    }
    long long maxs = -1, anss = -1;
    for (long long i = n - 1; i >= 0;i--) {
        if (s[sn[i]] == 1) {
            if (sn[i] > maxs) {
                maxs = sn[i];
                anss = i + 1;
            }
            //return 0;
        }
    }
    cout << anss;
    return 0;
}