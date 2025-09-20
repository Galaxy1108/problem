#include <bits/stdc++.h>
using namespace std;

int n, g[25][25], r[25];
string w[25];
int ans;

void __dfs(string a, int l) {
    ans = max((int)a.size(), ans);
    r[l]++;
    for (int i = 0; i < n; i++) {
        if (g[l][i] && r[i] < 2) {
            __dfs(a + w[i].substr(g[l][i]), i);
        }
    }
    r[l]--;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    char s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string a = w[i], b = w[j];
            for (int k = 1; k < min(a.size(), b.size()); k++) {
                if (a.substr(a.size() - k, k) == b.substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (w[i][0] == s) {
            __dfs(w[i], i);
        }
    }
    cout << ans << endl;
    return 0;
}
