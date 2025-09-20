#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs(int n, int s, int uo) {
    if (s == 1) {
        ans++;
        return;
    }
    for (int i = n; i <= uo / s;i++) {
        dfs(i, s - 1, uo - i);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    dfs(1, k, n);
    cout << ans;
    return 0;
}