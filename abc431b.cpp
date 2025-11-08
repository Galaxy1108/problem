#include <bits/stdc++.h>
using namespace std;

bool vis[105];
int w[105];

int main() {
    int x;
    cin >> x;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        if (vis[p]) {
            vis[p] = false;
            x -= w[p];
        } else {    
            vis[p] = true;
            x += w[p];
        }
        cout << x << '\n';
    }
}
