#include <bits/stdc++.h>
using namespace std;

int p[200005];
bool vis[200005];
long long dp[200005];

int l[200005], r[200005], f[200005];

int st[200005], top;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> p[i];
        l[i] = r[i] = f[i] = -1;
    }
    for (int i = 1;i <= n;i++) {
        int last = -1;
        while (top > 0 && p[st[top]] < p[i]) {
            last = st[top];
            top--;
        }
        if (top > 0) {
            f[i] = st[top];
            r[st[top]] = i;
        }
        if (last != -1) {
            f[last] = i;
            l[i] = last;
        }
        st[++top] = i;
    }
    int root = -1;
    for (int i = 1;i <= n;i++) {
        if (p[i] == n) {
            root = i;
            break;
        }
    }
    top = 0;
    st[++top] = root;
    while (top > 0) {
        int u = st[top];
        if (!vis[u]) {
            vis[u] = 1;
            if (l[u] != -1) {
                st[++top] = l[u];
            }
            if (r[u] != -1) {
                st[++top] = r[u];
            }
        } else {
            top--;
            long long res = 0;
            if (l[u] != -1) {
                res = max(res, dp[l[u]] + abs(u - l[u]));
            }
            if (r[u] != -1) {
                res = max(res, dp[r[u]] + abs(u - r[u]));
            }
            dp[u] = res;
        }
    }
    cout << dp[root];
    return 0;
}
