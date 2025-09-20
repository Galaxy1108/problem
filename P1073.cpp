#include <bits/stdc++.h>
using namespace std;

#define tpop(a) \
    front();    \
    a.pop();

int a[50005], bayb[50005], baya[50005];
vector<int> bay[50005];
vector<int> bayf[50005];

void spfa(queue<int>& q, int* _t, vector<int>* _bay, bool j) {
    while (!q.empty()) {
        int t = q.tpop(q);
        if (j) {
            _t[t] = max(_t[t], a[t]);
        } else {
            _t[t] = min(_t[t], a[t]);
        }
        int l = _bay[t].size();
        for (int i = 0; i < l; i++) {
            if (j) {
                if (_t[t] > _t[_bay[t][i]]) {
                    _t[_bay[t][i]] = _t[t];
                    q.push(_bay[t][i]);
                }
            } else {
                if (_t[t] < _t[_bay[t][i]]) {
                    _t[_bay[t][i]] = _t[t];
                    q.push(_bay[t][i]);
                }
            }
        }
    }
}

void spfas(int& ans, int n) {
    queue<int> q;
    q.push(1);
    memset(baya, 0x7f, sizeof(baya));
    baya[1] = INT_MAX;
    spfa(q, baya, bay, 0);
    q.push(n);
    spfa(q, bayb, bayf, 1);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, bayb[i] - baya[i]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        bay[x].push_back(y);
        bayf[y].push_back(x);
        if (z == 2) {
            bay[y].push_back(x);
            bayf[x].push_back(y);
        }
    }
    int ans = 0;
    spfas(ans, n);
    cout << ans;
    //system("pause");
    return 0;
}
