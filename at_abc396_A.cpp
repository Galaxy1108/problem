#include <bits/stdc++.h>
using namespace std;

long long sn[105];

int main() {
    long long n;
    cin >> n;
    long long thiss = -1, cnts = 0;
    for (long long i = 0;i < n;i++) {
        cin >> sn[i];
        if (sn[i] == thiss) {
            cnts++;
        }
        if (cnts == 3) {
            cout << "Yes";
            return 0;
        }
        if (sn[i] != thiss) {
            thiss = sn[i];
            cnts = 1;
        }
    }
    cout << "No";
    return 0;
}