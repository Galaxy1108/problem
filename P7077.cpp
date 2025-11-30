#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 998244353

struct func_call {
    int idx;
    ll k;
};

struct func_mt {
    int opt;
    int idx;
    int call_cnt;
    ll val;
    ll times;
    ll cnt;
    vector<func_call> call;
};

ll a[1000005];
func_mt funcs[1000005];
int in[1000005];
int g[1000005];
int func_cnt;
queue<int> q, q2;
vector<int> s[1000005];
int opt[1000005], p[1000005], v[1000005], c[1000005];
int idx[1000005];
vector<int> gg[1000005];

inline int add_func1(int idx, int val) {
    func_cnt++;
    funcs[func_cnt].opt = 1;
    funcs[func_cnt].idx = idx;
    funcs[func_cnt].val = val;
    funcs[func_cnt].times = 1;
    return func_cnt;
}

inline int add_func2(int times) {
    func_cnt++;
    funcs[func_cnt].opt = 2;
    funcs[func_cnt].times = times;
    return func_cnt;
}

inline int add_func3(int call_cnt, int* call_idx) {
    func_cnt++;

    funcs[func_cnt].opt = 3;
    funcs[func_cnt].call_cnt = call_cnt;

    ll times = 1;
    for (int i = call_cnt - 1;i >= 0;i--) {
        if (funcs[idx[call_idx[i]]].opt != 2) {
            funcs[func_cnt].call.push_back({ idx[call_idx[i]],times });
        }
        times = (times * funcs[idx[call_idx[i]]].times) % mod;
    }

    funcs[func_cnt].times = times;
    return func_cnt;
}

void calc_in(int u) {
    for (auto v : funcs[u].call) {
        if (++in[v.idx] == 1) {
            calc_in(v.idx);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i = 1;i <= m;i++) {
        cin >> opt[i];
        switch (opt[i]) {
        case 1:
            cin >> p[i] >> v[i];
            break;
        case 2:
            cin >> v[i];
            break;
        case 3:
            cin >> c[i];
            for (int j = 1;j <= c[i];j++) {
                int g;
                cin >> g;
                gg[i].push_back(g);
                s[g].push_back(i);
                in[i]++;
            }
            break;
        }
    }

    for (int i = 1;i <= m;i++) {
        if (!in[i]) {
            q2.push(i);
        }
    }

    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();

        switch (opt[u]) {
        case 1:
            idx[u] = add_func1(p[u], v[u]);
            break;
        case 2:
            idx[u] = add_func2(v[u]);
            break;
        case 3:
            idx[u] = add_func3(c[u], gg[u].data());
            break;
        }

        for(auto v : s[u]) {
            if (--in[v] == 0) {
                q2.push(v);
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 1;i <= n;i++) {
        g[i - 1] = add_func1(i, a[i]);
        idx[m + i] = m + i;
        a[i] = 0;
    }

    for (int i = 1;i <= t;i++) {
        int f;
        cin >> f;
        g[i + n - 1] = f;
    }

    int root = add_func3(n + t, g);
    calc_in(root);

    funcs[root].cnt = 1;
    q.push(root);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto v : funcs[u].call) {
            ll nk = (funcs[u].cnt * v.k) % mod;
            if (funcs[v.idx].opt == 1) {
                a[funcs[v.idx].idx] = (a[funcs[v.idx].idx] + nk * funcs[v.idx].val) % mod;
            }
            in[v.idx]--;
            funcs[v.idx].cnt = (funcs[v.idx].cnt + nk) % mod;
            if (in[v.idx] == 0) {
                q.push(v.idx);
            }
        }
    }
    
    for (int i = 1;i <= n;i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
