#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n % 2) {
        for (long long i = 0; i < n / 2;i++) {
            cout << '-';
        }
        cout << "=";
        for (long long i = 0; i < n / 2;i++) {
            cout << '-';
        }
    } else {
        for (long long i = 1; i < n / 2;i++) {
            cout << '-';
        }
        cout << "==";
        for (long long i = 1; i < n / 2;i++) {
            cout << '-';
        }
    }
}