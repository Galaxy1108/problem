#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool vis[3000005][10];

struct node_t {
    int r, l;
    string s;
};

queue<node_t> q;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            vis[i][j] = false;
        }
    }
    for (int d = 1; d <= 9; d++) {
        int r = d % n;
        string s;
        s += '0' + d;
        if (r == 0) {
            cout << s;
            return 0;
        }
        vis[r][d] = true;
        q.push({ r, d, s });
    }
    while (!q.empty()) {
        node_t u = q.front();
        q.pop();
        int r = u.r;
        int last = u.l;
        string s = u.s;
        for (int d = last; d <= 9; d++) {
            int nr = (r * 10ll + d) % n;
            if (vis[nr][d]) {
                continue;
            }
            vis[nr][d] = true;
            string ns = s;
            ns += '0' + d;
            if (nr == 0) {
                cout << ns;
                return 0;
            }
            q.push({ nr, d, ns });
        }
    }
    cout << -1;
    return 0;
}
