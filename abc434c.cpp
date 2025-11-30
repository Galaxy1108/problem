#include <bits/stdc++.h>
using namespace std;

struct goal_t {
    int t, l, u;
};

goal_t goals[100005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, h;
        cin >> n >> h;
        for (int i = 1; i <= n; i++) {
            cin >> goals[i].t >> goals[i].l >> goals[i].u;
        }
        int l = h, r = h;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int dt = goals[i].t - goals[i - 1].t;
            l -= dt;
            r += dt;
            l = max(l, goals[i].l);
            r = min(r, goals[i].u);
            if (l > r) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }
}
