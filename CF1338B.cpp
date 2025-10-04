#include <bits/stdc++.h>
using namespace std;

vector<int> s[100005];

int ans_min, ans_max;
int dep[100005];
bool cnts[2];

void search(int u, int f) {
    int son_cnt = 0;
    for (auto v : s[u]) {
        if (v == f) {
            continue;
        }
        dep[v] = dep[u] + 1;
        if (s[v].size() == 1) {
            cnts[dep[v] % 2] = true;
            son_cnt++;
        }
        search(v, u);
    }
    ans_max -= max(son_cnt - 1, 0);
    return;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;
        s[a].emplace_back(b);
        s[b].emplace_back(a);
    }
    ans_max = n - 1;
    for (int i = 1;i <= n;i++) {
        if (s[i].size() != 1) {
            search(i, 0);
            break;
        }
    }
    ans_min = ((cnts[0] && !cnts[1]) || (cnts[1] && !cnts[0])) ? 1 : 3;
    cout << ans_min << ' ' << ans_max;
    return 0;
}