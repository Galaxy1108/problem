/*
 * @Author: Galaxy_1108 int_256t@outlook.com
 * @Date: 2025-08-16 19:12:36
 * @LastEditors: Galaxy_1108 int_256t@outlook.com
 * @LastEditTime: 2025-08-16 20:20:39
 * @FilePath: \problem\at_abc419_C.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005], c[200005], d[200005];

int main() {
    int n;
    cin >> n;
    int max_a = 0, min_a = INT_MAX, max_b = 0, min_b = INT_MAX;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        max_a = max(max_a, a[i]);
        min_a = min(min_a, a[i]);
        max_b = max(max_b, b[i]);
        min_b = min(min_b, b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int x = (max_a + min_a) / 2, y = (max_b + min_b) / 2;
    int anss = 0;
    for (int i = 1;i <= n;i++) {
        int x1 = abs(a[i] - x), x2 = abs(b[i] - y);
        anss = max(anss, max(x1, x2));
    }
    cout << anss;
}