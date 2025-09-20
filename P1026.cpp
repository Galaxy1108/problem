#include <bits/stdc++.h>
using namespace std;

unordered_set<string> t;
long long s[205][205];
bool viss[205];
long long dp[205][45];

int main() {
    int p, g;
    cin >> p >> g;
    string str = "#";
    while (p--) {
        string s;
        cin >> s;
        str += s;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m;i++) {
        string s;
        cin >> s;
        t.insert(s);
    }
    int str_s = str.size() - 1;
    for (int i = 1; i <= str_s;i++) {
        fill(viss + i, viss + str_s, false);
        for (int j = i; j <= str_s;j++) {
            s[i][j] = s[i][j - 1];
            string this_sub;
            for (int l = 1; l <= (j - i + 1);l++) {
                int k = j - l + 1;
                this_sub.insert(this_sub.begin(), str[k]);
                if (viss[k]) {
                    continue;
                }
                if (t.count(this_sub)) {
                    viss[k] = true;
                    s[i][j]++;
                }
            }
        }
    }
    for (int i = 1; i <= str_s;i++) {
        for (int c = 1; c <= g;c++) {
            for (int k = c; k <= i;k++) {
                dp[i][c] = max(dp[i][c], dp[k - 1][c - 1] + s[k][i]);
            }
        }
    }
    cout << dp[str_s][g];
    return 0;
}