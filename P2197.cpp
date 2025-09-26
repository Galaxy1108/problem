#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long xors = 0, tmp;
        for (long long i = 0; i < n;i++) {
            cin >> tmp;
            xors ^= tmp;
        }
        cout << (xors ? "Yes\n" : "No\n");
    }
}