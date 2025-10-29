#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long anss = 0;
    for (long long i = 0; i < n;i++) {
        long long a, b;
        cin >> a >> b;
        anss += (b > a);
    }
    cout << anss;
}