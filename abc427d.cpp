#include <bits/stdc++.h>
using namespace std;

vector<int> a[200005];
bool dp[25][200005];

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        for (int i = 1;i <= n;i++) {
            a[i].clear();
        }
        for (int i = 0;i < m;i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        for (int u = 1; u <= n; u++) {
            dp[2 * k][u] = (s[u - 1] == 'A');
        }
        for (int d = 2 * k - 1; d >= 0; d--) {
            bool is_a = (d % 2 == 0);
            if (is_a) {
                for (int u = 1; u <= n; u++) {
                    bool res = false;
                    for (int v : a[u]) {
                        if (dp[d + 1][v]) {
                            res = 1;
                            break;
                        }
                    }
                    dp[d][u] = res;
                }
            } else {
                for (int u = 1; u <= n; u++) {
                    bool res = true;
                    for (int v : a[u]) {
                        if (!dp[d + 1][v]) {
                            res = 0;
                            break;
                        }
                    }
                    dp[d][u] = res;
                }
            }
        }
        cout << (dp[0][1] ?  "Alice\n" : "Bob\n");
    }
    return 0;
}
