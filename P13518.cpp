/**
 * @name 镜子
 * @link https://www.luogu.com.cn/problem/P13518
 * @test 2025/10/18 T1
 * @class orange
 * @date 2025/10/18 周六 11:52
 * @par tags
 * #贪心
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n, s;
    cin >> n >> s;
    ll anss = 0;
    for (int i = 1; i <= n;i++){
        ll num;
        cin >> num;
        anss += (i <= n / 2 ? -2 * num : 2 * num);
    }
    anss += (n % 2 ? -s : s);
    cout << anss;
    return 0;
}