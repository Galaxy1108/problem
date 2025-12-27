#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += (s[i + j] - t[j] + 10) % 10;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}
