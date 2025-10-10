/**
 * @name 列队春游
 * @link https://www.luogu.com.cn/problem/P10668 
 * @class green
 * @date 2025/10/10 周五 15:34
 * @par tags
 * #期望
 */

#include <bits/stdc++.h>
using namespace std;

int p[1000005];
int h[1000005];
long double anss;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int maxs = 0;
    for (int i = 1;i <= n;i++) {
        cin >> h[i];
        p[h[i]]++;
        maxs = max(maxs, h[i]);
    }
    for (int i = 1;i <= maxs;i++) {
        if (p[i]) {
            long double res = 1.0 * p[i - 1] / (n - p[i - 1] + 1) + 1;
            anss += p[i] * res;
        }
        p[i] = p[i - 1] + p[i];
    }
    printf("%.2Lf", anss);
}