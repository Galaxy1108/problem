#include <bits/stdc++.h>
using namespace std;

int nxt[200005][26];
string s, t;

int main() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int c = 0; c < 26; c++) {
        nxt[n][c] = -1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    long long res = 0;
    for (int l = 0; l < n; l++) {
        int p = l;
        bool ok = 1;
        for (int i = 0; i < m; i++) {
            if (p > n) {
                ok = 0;
                break;
            }
            p = nxt[p][t[i] - 'a'];
            if (p == -1) {
                ok = 0;
                break;
            }
            p++;
        }
        if (ok) {
            res += (n - (p - 1));
        }
    }
    long long sum = 1ll * n * (n + 1) / 2;
    cout << sum - res;
    return 0;
}
