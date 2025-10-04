#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a, c;
int b[2000005], tops;

int main() {
    int t;
    cin >> t;
    while (t--) {
        a.clear(), c.clear(), tops = 0;
        int n, k, x;
        cin >> n >> k >> x;
        int num = 0;
        for (int i = 1;i <= n;i++) {
            num ^= i;
            if (i == x) {
                a.push_back({ x });
            } else if ((x ^ i) > n) {
                b[++tops] = i;
            } else if ((x ^ i) < i) {
                a.push_back({ x ^ i, i });
            }
        }
        if (num ^ ((k % 2) * x) || a.size() < k) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0;i < k;i++) {
            c.push_back(a[i]);
        }
        for (int i = k;i < a.size();i++) {
            for (int j = 0;j < a[i].size();j++) {
                c[0].push_back(a[i][j]);
            }
        }
        for (int i = 1;i <= tops;i++) {
            c[0].push_back(b[i]);
        }
        cout << "YES\n";
        for (int i = 0;i < k;i++) {
            cout << c[i].size() << ' ';
            for (int j = 0;j < c[i].size();j++) {
                cout << c[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}