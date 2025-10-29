/**
 * problem: Fibonacci Strings
 * link: https://codeforces.com/problemset/problem/1718/B
 * difficult: *2000 (green)
 * date: 2025/10/29 周三 19:51
 * tags: #贪心
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int c[105];

struct s {
    int idx, num;
    friend bool operator<(s a, s b) {
        return a.num < b.num;
    }
};

priority_queue<s> pq;
unordered_map<ll, int> fibsid;

ll fib[100];

int main() {
    fib[1] = fib[2] = 1;
    fibsid[1] = 1;
    fibsid[2] = 2;
    ll sums = 2;
    for (int i = 3;sums <= 100000000000;i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        sums += fib[i];
        fibsid[sums] = i;
    }
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        sums = 0;
        for (int i = 1;i <= k;i++) {
            cin >> c[i];
            pq.push({ i,c[i] });
            sums += c[i];
        }
        int mxid = fibsid[sums];
        if (!mxid) {
            cout << "NO\n";
            while (!pq.empty()) pq.pop();
            continue;
        }
        bool flag = true;
        int laidx = 0;
        for (int i = mxid;i >= 1;i--) {
            s u = pq.top();
            pq.pop();
            if (u.num < fib[i]) {
                cout << "NO\n";
                flag = false;
                break;
            }
            if (u.idx == laidx) {
                if (pq.empty()) {
                    cout << "NO\n";
                    flag = false;
                    break;
                }
                s u2 = pq.top();
                pq.pop();
                if (u2.num < fib[i]) {
                    cout << "NO\n";
                    flag = false;
                    break;
                }
                laidx = u2.idx;
                if (u2.num - fib[i] > 0) {
                    pq.push((s) { u2.idx, u2.num - (int)fib[i] });
                }
                pq.push(u);
                continue;
            }
            laidx = u.idx;
            if (u.num - fib[i] > 0) {
                pq.push((s) { u.idx, u.num - (int)fib[i] });
            }
        }
        if (flag && pq.empty()) {
            cout << "YES\n";
        }
        while (!pq.empty()) pq.pop();
    }
}
