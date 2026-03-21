#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull MAXL = 1000000000000000000ULL;

ull len[100];
ull cnt[100][26];

int prex[10005][26];
int prey[10005][26];

int kcnt;

ull getans(ull p, int ch) {
    if (p == 0) {
        return 0;
    }
    ull ans = 0;
    int i = kcnt;
    while (i > 2) {
        if (p <= len[i - 1]) {
            i = i - 1;
        } else {
            ans += cnt[i - 1][ch];
            p -= len[i - 1];
            i = i - 2;
        }
    }
    if (i == 1) {
        ans += prex[p][ch];
    } else {
        ans += prey[p][ch];
    }
    return ans;
}

int main() {
    string strx, stry;
    int q;
    cin >> strx >> stry;
    cin >> q;
    int n = strx.size();
    int m = stry.size();
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            prex[i + 1][c] = prex[i][c];
        }
        prex[i + 1][strx[i] - 'a']++;
    }
    for (int i = 0; i < m; i++) {
        for (int c = 0; c < 26; c++) {
            prey[i + 1][c] = prey[i][c];
        }
        prey[i + 1][stry[i] - 'a']++;
    }
    len[1] = n;
    len[2] = m;
    for (int c = 0; c < 26; c++) {
        cnt[1][c] = prex[n][c];
        cnt[2][c] = prey[m][c];
    }
    kcnt = 2;
    while (len[kcnt] < MAXL) {
        kcnt++;
        len[kcnt] = min(MAXL, len[kcnt - 1] + len[kcnt - 2]);
        for (int c = 0; c < 26; c++) {
            cnt[kcnt][c] = cnt[kcnt - 1][c] + cnt[kcnt - 2][c];
        }
    }
    while (q--) {
        ull l, r;
        char cha;
        cin >> l >> r >> cha;
        int ch = cha - 'a';
        ull ans = getans(r, ch) - getans(l - 1, ch);
        cout << ans << '\n';
    }
    return 0;
}
