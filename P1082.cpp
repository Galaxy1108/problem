#include <bits/stdc++.h>
using namespace std;

int x, y;

void exgcd(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b);
    int _x = x;
    x = y, y = _x - a / b * y;
}


int main() {
    int a, MOD;
    cin >> a >> MOD;
    exgcd(a, MOD);
    cout << (x % MOD + MOD) % MOD;
    return 0;
}