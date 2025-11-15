/**
 * problem: AC 自动机（简单版 II）
 * link: https://www.luogu.com.cn/problem/P3796 
 * difficult: blue
 * date: 2025/11/15 周六 14:32
 * tags: #AC自动机
 */

#include <bits/stdc++.h>
using namespace std;

int vis_cnt[155];

struct trie {

#define son_idx(_node,_c)   (node[_node].son[_c])
#define son(_node,_c)       (node[son_idx(_node, _c)])
#define fail_idx(_node)     (node[_node].fail)
#define fail(_node)         (node[fail_idx(_node)])
#define end(_node)          (node[_node].end)
#define vis(_node)          (node[_node].vis)
#define new_node            (++t_cnt, memset(node[t_cnt].son, 0, sizeof(node[t_cnt].son)), fail_idx(t_cnt) = vis(t_cnt) = 0, end(t_cnt).clear(), t_cnt)
#define root                (node[0])

    struct trie_node {
        int son[30], fail;
        int vis;
        vector<int> end;
    };

    string strs[155];
    trie_node node[11000];
    int strs_cnt = 0;
    int node_cnt = 0;
    int t_cnt = 0;

    inline void clear() {
        strs_cnt = node_cnt = t_cnt = 0;
        memset(node[t_cnt].son, 0, sizeof(node[t_cnt].son)), fail_idx(t_cnt) = vis(t_cnt) = 0, end(t_cnt).clear();
    }

    void insert(string _str) {
        strs[++strs_cnt] = _str;
        int its = 0;
        for (char c : _str) {
            int idx = c - 'a';
            if (!son_idx(its, idx)) {
                son_idx(its, idx) = new_node;
            }
            its = son_idx(its, idx);
        }
        end(its).emplace_back(strs_cnt);
    }

    void build_acam() {
        queue<int> q;

        for (int i = 0;i <= 'z' - 'a';i++) {
            if (root.son[i]) {
                q.push(root.son[i]);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0;i <= 'z' - 'a';i++) {
                if (son_idx(u, i)) {
                    son(u, i).fail = fail(u).son[i];
                    q.push(son_idx(u, i));
                } else {
                    son_idx(u, i) = fail(u).son[i];
                }
            }
        }
    }

    void run_acam(string _t) {
        int its = 0;
        t_cnt++;
        for (int c : _t) {
            int idx = c - 'a';
            its = son_idx(its, idx);
            for (int f = its;f != 0;f = fail_idx(f)) {
                for (int end_idx : end(f)) {
                    vis_cnt[end_idx]++;
                }
            }
        }
    }
};

trie tri;
string strs[155];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n) {
        if (!n) {
            break;
        }
        tri.clear();
        for (int i = 1;i <= n;i++) {
            cin >> strs[i];
            vis_cnt[i] = 0;
            tri.insert(strs[i]);
        }
        tri.build_acam();
        string t;
        cin >> t;
        tri.run_acam(t);
        int max_cnt = 0;
        for (int i = 1;i <= n;i++) {
            max_cnt = max(max_cnt, vis_cnt[i]);
        }
        cout << max_cnt << '\n';
        for (int i = 1;i <= n;i++) {
            if (vis_cnt[i] == max_cnt) {
                cout << strs[i] << '\n';
            }
        }
    }
    return 0;
}
