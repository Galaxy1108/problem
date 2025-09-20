#include <bits/stdc++.h>
using namespace std;

struct f {
    int x, y;
    friend bool operator>(f a, f b) {
        return (a.x == b.x) ? (a.y > b.y) : (a.x > b.x);
    }
};

priority_queue<f, vector<f>, greater<f>> q1;
priority_queue<int, vector<int>, greater<int>> q2;
long long cnt1[1000005], cnt2[1000005];

bool cmp(f a, f b) {
    return a.x < b.x;
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    f a[m1 + 1] = {}, b[m2 + 1] = {};
    for (int i = 1; i <= m1; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= m2; i++) {
        cin >> b[i].x >> b[i].y;
    }
    sort(a + 1, a + m1 + 1, cmp);
    sort(b + 1, b + m2 + 1, cmp);
    for (int i = 1; i <= n; i++) {
        q2.push(i);
    }
    for (int i = 1; i <= m1; i++) {
        while (!q1.empty() && a[i].x >= q1.top().x) {
            q2.push(q1.top().y);
            q1.pop();
        }
        if (!q2.empty()) {
            int u = q2.top();
            q2.pop();
            cnt1[u]++;
            q1.push({ a[i].y, u });
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt1[i] += cnt1[i - 1];
    }
    while (!q1.empty()) {
        q1.pop();
    }
    while (!q2.empty()) {
        q2.pop();
    }
    for (int i = 1; i <= n; i++) {
        q2.push(i);
    }
    for (int i = 1; i <= m2; i++) {
        while (!q1.empty() && b[i].x >= q1.top().x) {
            q2.push(q1.top().y);
            q1.pop();
        }
        if (!q2.empty()) {
            int u = q2.top();
            q2.pop();
            cnt2[u]++;
            q1.push({ b[i].y, u });
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt2[i] += cnt2[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, cnt1[i] + cnt2[n - i]);
    }
    cout << ans;
    return 0;
}