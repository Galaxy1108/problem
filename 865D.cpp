/**
 * problem: Buy Low Sell High
 * link: https://codeforces.com/problemset/problem/865/D
 * difficult: *2400 (blue)
 * date: 2025/11/14 周五 18:44
 * tags: #构造 #数据结构 #贪心
 */

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n;
    cin >> n;
    long long anss = 0;
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        if (!pq.empty() && pq.top() < a) {
            anss += a - pq.top();
            pq.pop();
            pq.push(a);
        }
        pq.push(a);
    }
    cout << anss;
}
