#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll trr[1000005];

void add(int x, int v) {
    for (int i = x;i <= 1000000;i += i & -i) {
        trr[i] += v;
    }
}

ll query(int x) {
    ll res = 0;
    for (int i = x;i > 0;i -= i & -i) {
        res += trr[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    int cur = 500000;
    add(cur + 1, 1);
    for (int i = 0;i < n;i++) {
        if (s[i] == 'A') {
            cur++;
        } else if (s[i] == 'B') {
            cur--;
        }
        ans += query(cur);
        add(cur + 1, 1);
    }
    cout << ans << "\n";
}
