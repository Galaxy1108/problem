/**
 * problem: 【模板】AC 自动机
 * link: https://www.luogu.com.cn/problem/P5357 
 * difficult: blue
 * date: 2025/11/15 周六 14:33
 * tags: #AC自动机 #模板
 */

#include <bits/stdc++.h>
using namespace std;

int vis_cnt[200005];
int vvis_cnt[200005];

struct trie_node {
    int son[30], fail;
    int vis;
    vector<int> end;
};

trie_node node[200005];
vector<int> fail[200005];

struct trie {

#define son_idx(_node,_c)   (node[_node].son[_c])
#define son(_node,_c)       (node[son_idx(_node, _c)])
#define fail_idx(_node)     (node[_node].fail)
#define fail(_node)         (node[fail_idx(_node)])
#define end(_node)          (node[_node].end)
#define vis(_node)          (node[_node].vis)
#define new_node            (++node_cnt, memset(node[node_cnt].son, 0, sizeof(node[node_cnt].son)), fail_idx(node_cnt) = vis(node_cnt) = 0, end(node_cnt).clear(), node_cnt)
#define root                (node[0])

    int strs_cnt = 0;
    int node_cnt = 0;

    inline void clear() {
        strs_cnt = node_cnt = 0;
        memset(node[node_cnt].son, 0, sizeof(node[node_cnt].son)), fail_idx(node_cnt) = vis(node_cnt) = 0, end(node_cnt).clear();
    }

    void insert(string _str) {
        int its = 0;
        for (char c : _str) {
            int idx = c - 'a';
            if (!son_idx(its, idx)) {
                son_idx(its, idx) = new_node;
            }
            its = son_idx(its, idx);
        }
        end(its).emplace_back(++strs_cnt);
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

        for (int i = 0;i <= node_cnt;i++) {
            fail[fail_idx(i)].emplace_back(i);
        }
    }

    void run_acam(string _t) {
        int its = 0;
        node_cnt++;
        for (int c : _t) {
            int idx = c - 'a';
            its = son_idx(its, idx);
            vis_cnt[its]++;
        }

        auto get_sum = [](auto&& self, int u, int f) -> void {
            for (auto v : fail[u]) {
                if (v == f) {
                    continue;
                }
                self(self, v, u);
                vis_cnt[u] += vis_cnt[v];
            }
            for (auto idx : node[u].end) {
                vvis_cnt[idx] = vis_cnt[u];
            }
        };

        get_sum(get_sum, 0, 0);
    }
};

trie tri;
string strs[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
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
    for (int i = 1;i <= n;i++) {
        cout << vvis_cnt[i] << '\n';
    }
    return 0;
}
