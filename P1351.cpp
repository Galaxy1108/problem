#include <bits/stdc++.h>
using namespace std;

#define mod 10007
vector<long long> a[200005];

long long w[200005];

int main() {
    long long n;
    cin >> n;
    for (long long i = 1; i < n;i++) {
        long long u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    for (long long i = 1; i <= n;i++) {
        cin >> w[i];
    }
    long long anss1 = 0, anss2 = 0;
    for (long long i = 1; i <= n;i++) {
        long long sum1 = 0, sum2 = 0;
        long long max1 = INT_MIN, max2 = INT_MIN;
        for (auto its : a[i]) {
            sum1 += w[its];
            sum2 += w[its] * w[its];
            sum1 %= mod;
            sum2 %= mod;
            if (w[its] > max1) {
                max2 = max1;
                max1 = w[its];
            } else if (w[its] > max2) {
                max2 = w[its];
            }
        }
        sum1 *= sum1;
        sum1 %= mod;
        anss1 = (anss1 + sum1 - sum2 + mod) % mod;
        anss2 = max(anss2, max1 * max2);
    }
    cout << anss2 << ' ' << anss1;
    return 0;
}