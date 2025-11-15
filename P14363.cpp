/**
 * problem: [CSP-S 2025] 谐音替换
 * link: https://www.luogu.com.cn/problem/P14363 
 * difficult: purple
 * date: 2025/11/15 周六 14:36
 * tags: #AC自动机
 */

#include <bits/stdc++.h>
using namespace std;

int add_cnt[5000005];

struct trie_node {
    int son[30], fail;
    int vis;
    int cnt;
};

trie_node node[5000005];
vector<int> fail[5000005];

struct trie {

#define son_idx(_node,_c)   (node[_node].son[_c])
#define son(_node,_c)       (node[son_idx(_node, _c)])
#define fail_idx(_node)     (node[_node].fail)
#define fail(_node)         (node[fail_idx(_node)])
#define end(_node)          (node[_node].end)
#define vis(_node)          (node[_node].vis)
#define root                (node[0])

    int strs_cnt = 0;
    int node_cnt = 0;

    void insert(string _str) {
        int its = 0;
        for (char c : _str) {
            int idx = c - 'a';
            if (!son_idx(its, idx)) {
                son_idx(its, idx) = ++node_cnt;
            }
            its = son_idx(its, idx);
        }
        node[its].cnt++;
    }

    void build_acam() {
        queue<int> q;

        for (int i = 0;i <= '{' - 'a';i++) {
            if (root.son[i]) {
                q.push(root.son[i]);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0;i <= '{' - 'a';i++) {
                if (son_idx(u, i)) {
                    son(u, i).fail = fail(u).son[i];
                    q.push(son_idx(u, i));
                } else {
                    son_idx(u, i) = fail(u).son[i];
                }
            }
        }

        for (int i = 0;i <= node_cnt;i++) {
            fail[fail_idx(i)].emplace_back(i);
        }

        auto get_cnt = [](auto&& get_cnt, int u, int f) -> void {
            add_cnt[u] = node[u].cnt + add_cnt[f];
            for (auto v : fail[u]) {
                if (v == f) {
                    continue;
                }
                get_cnt(get_cnt, v, u);
            }
        };

        get_cnt(get_cnt, 0, 0);
    }

    int run_acam(string _t) {
        int ans = 0;
        int its = 0;
        for (int c : _t) {
            int idx = c - 'a';
            its = son_idx(its, idx);
            ans += add_cnt[its];
        }
        return ans;
    }
};

string _merge(string s1, string s2) {
    int s = s1.size();
    string str;
    int l = -1, r = -1;
    for (int i = 0;i < s;i++) {
        if (s1[i] != s2[i]) {
            l = (l == -1 ? i : l);
            r = i;
        }
    }
    for (int i = 0;i < l;i++) {
        str.push_back(s1[i]);
    }
    str.push_back('{');
    for (int i = l;i <= r;i++) {
        str.push_back(s1[i]);
    }
    for (int i = l;i <= r;i++) {
        str.push_back(s2[i]);
    }
    str.push_back('{');
    for (int i = r + 1;i < s;i++) {
        str.push_back(s1[i]);
    }
    return str;
}

trie tri;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2) {
            continue;
        }
        tri.insert(_merge(s1, s2));
    }
    tri.build_acam();
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        cout << tri.run_acam(_merge(t1, t2)) << '\n';
    }
    return 0;
}
