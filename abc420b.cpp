#include <bits/stdc++.h>
using namespace std;

int p[105][105];
int cnt[105];
struct s {
    int num, idx;
};
s ans[105];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        ans[i].idx = i;
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            p[i][j] = c - '0';
            if (p[i][j]) {
                cnt[j]++;
            }
        }
    }
    for (int i = 1;i <= m;i++) {
        if (cnt[i] == 0 || cnt[i] == n) {
            for (int j = 1;j <= n;j++) {
                ans[j].num++;
            }
        }else if (cnt[i] < n - cnt[i]) {
            for (int j = 1;j <= n;j++) {
                if (p[j][i]) {
                    ans[j].num++;
                }
            }
        } else {
            for (int j = 1;j <= n;j++) {
                if (!p[j][i]) {
                    ans[j].num++;
                }
            }
        }
    }
    sort(ans + 1, ans + 1 + n, [](s a, s b) {
        return (a.num == b.num ? a.idx<b.idx : a.num>b.num);
        });
    int max_n = ans[1].num;
    for (int i = 1;i <= n;i++) {
        if (ans[i].num == max_n) {
            cout << ans[i].idx << ' ';
        }
    }
    return 0;
}