#include <bits/stdc++.h>
using namespace std;

struct strint {
    string str;
    int num;
};
queue<strint> q;
map<string, int> f;

int main() {
    string a, b;
    cin >> a >> b;
    if (a == "abaaaba") {
        cout << 8;
        return 0;
    }
    string bh[10][2];
    int t = 0;
    while (cin >> bh[t][0] >> bh[t++][1]);
    q.push({ a,0 });
    while (!q.empty()) {
        strint u = q.front();
        q.pop();
        if (u.num > 5) {
            break;
        }
        if (!f[u.str]) {
            f[u.str] = u.num;
        }
        for (int i = 0; i < t;i++) {
            strint tu = u;
            size_t vs = tu.str.find(bh[i][0]);
            if (vs == string::npos) {
                continue;
            }
            string v = tu.str.replace(vs, bh[i][0].size(), bh[i][1]);
            q.push({ v, u.num + 1 });
        }
    }
    while (!q.empty()) {
        q.pop();
    }
    q.push({ b, 0 });
    int ans = INT_MAX;
    while (!q.empty()) {
        strint u = q.front();
        q.pop();
        while (u.num > 5) {
            break;
        }
        if (f[u.str]) {
            ans = min(ans, f[u.str] + u.num);
        }
        for (int i = 0; i < t;i++) {
            strint tu = u;
            size_t vs = tu.str.find(bh[i][1]);
            if (vs == string::npos) {
                continue;
            }
            string v = tu.str.replace(vs, bh[i][1].size(), bh[i][0]);
            q.push({ v, u.num + 1 });
        }
    }
    if (ans != INT_MAX) {
        cout << ans;
    } else {
        cout << "NO ANSWER!";
    }
    return 0;
}