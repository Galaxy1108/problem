/**
 * problem: The Nether
 * link: https://codeforces.com/problemset/problem/2133/C
 * contest: https://vjudge.net/contest/768289 (强化训练VP 1)
 * difficult: *1400 (green)
 * date: 2025/11/20 周四 19:32
 * tags: #图论 #交互题
 */

#include <bits/stdc++.h>
using namespace std;

int s[505], ans[505];

inline int query(int st, int k) {
    cout << "? " << st << ' ' << k;
    for (int i = 1;i <= k;i++) {
        cout << ' ' << s[i];
    }
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

vector<int> l[505];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int maxn = 0;
        for (int i = 1;i <= n;i++) {
            s[i] = i;
            l[i].clear();
        }
        for (int i = 1;i <= n;i++) {
            int p = query(i, n);
            l[p].push_back(i);
            maxn = max(maxn, p);
        }
        if (maxn == 1) {
            cout << "! 1 1" << endl;
            cout.flush();
            continue;
        }
        ans[1] = l[maxn][0];
        int p = l[maxn][0];
        for (int i = maxn - 1;i >= 1;i--) {
            for (int v : l[i]) {
                s[1] = p, s[2] = v;
                if (query(p, 2) == 2) {
                    p = v;
                    ans[maxn - i + 1] = p;
                    break;
                }
            }
        }
        cout << "! " << maxn;
        for (int i = 1;i <= maxn;i++) {
            cout << ' ' << ans[i];
        }
        cout << endl;
        cout.flush();
    }
}
/*
? 1 5 1 2 3 4 5
3 
? 2 5 1 2 3 4 5
1
? 3 5 1 2 3 4 5
3
? 4 5 1 2 3 4 5
2
? 5 5 1 2 3 4 5
4
? 5 2 5 1
2
? 1 2 1 4
2
? 4 2 4 2
2
*/
