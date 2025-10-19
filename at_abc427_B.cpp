#include <bits/stdc++.h>
using namespace std;

long long a[105];

long long dig_sum(long long n) {
    long long res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            a[i] += dig_sum(a[j]);
        }
    }
    cout << a[n];
}