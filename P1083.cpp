#include <bits/stdc++.h>
using namespace std;

long long n, m, sr[1000000], sd[1000000], ss[1000000], st[1000000];
long long cf[1000000], qz[1000000];

bool check(long long x) {
    //cout<<n<<endl;
    memset(cf, 0, sizeof(cf));
    for (long long i = 0;i < x;i++) {
        cf[ss[i] - 1] += sd[i];
        cf[st[i]] -= sd[i];
    }
    if (cf[0] > sr[0]) {
        return false;
    }
    for (long long i = 1;i < n;i++) {
        cf[i] = cf[i - 1] + cf[i];
        if (cf[i] > sr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (long long i = 0; i < n;i++) {
        cin >> sr[i];
    }
    for (long long i = 0; i < m;i++) {
        cin >> sd[i] >> ss[i] >> st[i];
    }
    long long l = 0, r = m;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        //cout<<l<<" "<<mid<<" "<<r<<endl;
    }
    if (l == m + 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << -1 << endl << l;
    return 0;
}