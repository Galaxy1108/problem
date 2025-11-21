/**
 * problem: Flint and Steel
 * link: https://codeforces.com/problemset/problem/2133/F 
 * contest: https://vjudge.net/contest/768289 (强化训练VP 1)
 * difficult: *3000 (purple)
 * date: 2025/11/21 周五 16:01
 * tags: #线段树 #DP #线段树优化DP
 */

#include <bits/stdc++.h>
using namespace std;

int e[500005];
vector<int> q[500005];

struct vi {
    int val, idx;
    friend bool operator<(vi a, vi b) {
        return a.val < b.val;
    }
};

struct smt {
    vi _data[4 * 500005];

    void clear(int idx, int l, int r) {
        _data[idx] = { INT_MAX,0 };
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        clear(2 * idx, l, mid);
        clear(2 * idx + 1, mid + 1, r);
    }
    void upd(int idx, int l, int r, int goal, vi new_data) {
        if (l > goal || r < goal) {
            return;
        }
        _data[idx] = min(_data[idx], new_data);
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        upd(2 * idx, l, mid, goal, new_data);
        upd(2 * idx + 1, mid + 1, r, goal, new_data);
    }
    vi query(int idx, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return { INT_MAX,0 };
        }
        if (L <= l && r <= R) {
            return _data[idx];
        }
        int mid = (l + r) / 2;
        return min(query(idx * 2, l, mid, L, R), query(idx * 2 + 1, mid + 1, r, L, R));
    }
};

smt trr;
vi dp[500005];
int ans[500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0;i <= n;i++) {
            q[i].clear();
            dp[i] = { INT_MAX,0 };
        }
        trr.clear(1, 1, n);
        for (int i = 1;i <= n;i++) {
            cin >> e[i];
            if (e[i]) {
                if (i - e[i] >= 1) {
                    q[i - e[i]].emplace_back(i);
                }
            }
        }
        for (int i = 1;i <= n;i++) {
            if (i - e[i] + 1 <= 1) {
                dp[i] = { 1,0 };
            }
            trr.upd(1, 1, n, min(i + e[i] - 1, n), (vi) { dp[i].val, i });
            if (e[i]) {
                vi ndata = trr.query(1, 1, n, max(1, i - e[i]), i - 1);
                if (ndata.val != INT_MAX) {
                    dp[i] = min(dp[i], { ndata.val + 1,ndata.idx });
                    trr.upd(1, 1, n, min(i + e[i] - 1, n), (vi) { dp[i].val, i });
                }
            }
            for (int j : q[i]) {
                vi ndata = trr.query(1, 1, n, max(1, j - e[j]), min(j + e[j] - 1, n));
                if (ndata.val != INT_MAX) {
                    dp[j] = min(dp[j], { ndata.val + 1,ndata.idx });
                }
            }
        }
        vi res = trr.query(1, 1, n, n, n);
        if (res.val == INT_MAX) {
            cout << -1 << '\n';
            continue;
        }
        int cnt = 0, its = res.idx;
        while (its) {
            ans[++cnt] = its;
            its = dp[its].idx;
        }
        sort(ans + 1, ans + 1 + cnt, [&](int a, int b) {
            return e[a] < e[b];
        });
        cout << cnt << '\n';
        for (int i = 1;i <= cnt;i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
