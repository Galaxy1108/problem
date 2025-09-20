#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    k ^= (k >> 1);
    while (~(--n)) {
        cout << ((k >> n) & 1);
    }
    return 0;
}