#include <bits/stdc++.h>
using namespace std;

long long gz[1000005];
long long n;
long long gc[1000005];
long long gc_p[1000005];

long long lowbit(long long a) {
    return (a & (-a));
}

long long read(long long a) {
    long long sums = 0;
    for (long long i = a; i > 0;i -= lowbit(i)) {
        sums += gc[i];
    }
    return sums;
}

void add(long long a, long long k) {
    for (long long i = a; i <= n;i += lowbit(i)) {
        gc[i] += k;
    }
}

int main() {
    long long q;
    cin >> n >> q;
    for (long long i = 1; i <= n;i++) {
        gz[i] = i;
        gc_p[i] = 1;
    }
    while (q--) {
        long long opt;
        cin >> opt;
        if (opt == 1) {
            long long p, h;
            cin >> p >> h;
            gc_p[gz[p]]--;
            if (gc_p[gz[p]] == 1) {
                add(gz[p], -1);
            }
            gc_p[h]++;
            if (gc_p[h] == 2) {
                add(h, 1);
            }
            gz[p] = h;
        } else {
            cout << read(n) << '\n';
        }
    }
}