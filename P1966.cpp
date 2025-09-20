#include<bits/stdc++.h>
using namespace std;

long long ssn[(long long)1e5 + 5], p[(long long)1e5 + 5], ans = 0;

struct f {
    long long a, n;
};

bool cmp(f a, f b) {
    return a.a < b.a;
}

void msort(long long s, long long t, long long a[]) {
    if (s == t) {
        return;
    }
    long long mid = (s + t) >> 1;
    msort(s, mid, a);
    msort(mid + 1, t, a);
    long long i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) {
        if (a[i] <= a[j]) {
            p[k++] = a[i++];
        } else {
            p[k++] = a[j++];
            ans += ((long long)mid - i + 1) % 99999997;
        }
    }
    for (; i <= mid; k++, i++) {
        p[k] = a[i];
    }
    for (; j <= t; k++, j++) {
        p[k] = a[j];
    }
    for (long long i = s; i <= t; i++) {
        a[i] = p[i];
    }
}
int main() {
    long long n;
    cin >> n;
    f sn[2][n];
    for (long long i = 0; i < n; i++) {
        cin >> sn[0][i].a;
        sn[0][i].n = i;
    }
    for (long long i = 0; i < n; i++) {
        cin >> sn[1][i].a;
        sn[1][i].n = i;
    }
    sort(sn[0], sn[0] + n, cmp);
    sort(sn[1], sn[1] + n, cmp);
    for (long long i = 0; i < n; i++) {
        ssn[sn[1][i].n] = sn[0][i].n;
    }
    msort(0, n - 1, ssn);
    cout << ans % 99999997 << endl;
    return 0;
}