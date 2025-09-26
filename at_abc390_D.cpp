#include <bits/stdc++.h>
using namespace std;

long long sn[13];
long long ps[13];
long long sts[13];
long long n, cnts, anss;
unordered_map<long long, bool> p;

void get_cnt(long long n) {
    if (n == 1) {
        for (long long i = 1; i <= 12;i++) {
            sts[i] = 0;
        }
        for (long long i = 0; i < cnts;i++) {
            sts[ps[i]] += sn[i];
        }
        for (long long i = 1; i <= ps[cnts - 1] + 1;i++) {
            sts[i] += sn[cnts];
            long long ans = 0;
            for (long long j = 1; j <= 12;j++) {
                ans ^= sts[j];
            }
            // cout << ans << ' ';
            if (!p[ans]) {

                p[ans] = true;
                anss++;
            }
            sts[i] -= sn[cnts];
        }
        return;
    }
    // long long anss = 0;
    for (long long i = 1; i <= ps[cnts - 1] + 1;i++) {
        ps[cnts++] = i;
        get_cnt(n - 1);
        cnts--;
    }
}

int main() {
    cin >> n;
    for (long long i = 0; i < n;i++) {
        cin >> sn[i];
    }
    get_cnt(n);
    cout << anss;
}