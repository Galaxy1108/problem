#include <bits/stdc++.h>
using namespace std;

long long fast_pow(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << ((x % n) + (m % n) * (fast_pow(10, k, n) % n)) % n << endl;
    return 0;
}