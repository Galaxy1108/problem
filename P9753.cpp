/**
 * problem: [CSP-S 2023] 消消乐
 * link: https://www.luogu.com.cn/problem/P9753 
 * difficult: blue
 * date: 2025/10/28 周二 20:32
 * tags: #DP #预处理
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
string a;
int pre[2000005];

ll ans[2000005];

int main() {
    cin >> n;
    cin >> a;
    a = " " + a;
    for (int i = 1;i <= n;i++) {
        pre[i] = i - 1;
        while (a[pre[i]] != a[i] && pre[i]) {
            pre[i] = max(0, pre[pre[i]] - 1);
        }
    }
    ll anss = 0;
    for (int i = 1;i <= n;i++) {
        if (!pre[i]) {
            continue;
        }
        ans[i] = ans[pre[i] - 1] + 1;
        anss += ans[i];
    }
    cout << anss;
}
