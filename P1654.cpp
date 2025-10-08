/**
 * @name OSU!
 * @link https://www.luogu.com.cn/problem/P1654 
 * @par tags
 * #DP #期望DP
 */

#include <bits/stdc++.h>
using namespace std;

long double p[100005];
long double e1[100005], e2[100005], e3[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> p[i];
    }
    for (int i = 1;i <= n;i++) {
        e1[i] = (e1[i - 1] + 1) * p[i];
        e2[i] = (e2[i - 1] + 2 * e1[i - 1] + 1) * p[i];
        e3[i] = e3[i - 1] + (3 * e2[i - 1] + 3 * e1[i - 1] + 1) * p[i];
    }
    printf("%.1Lf", e3[n]);
    return 0;
}