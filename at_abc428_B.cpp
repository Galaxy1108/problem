#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0;i <= n - k;i++) {
        string t = s.substr(i, k);
        mp[t]++;
    }
    int max_cnt = 0;
    for (auto p : mp) {
        max_cnt = max(max_cnt, p.second);
    }
    cout << max_cnt << '\n';
    for (auto p : mp) {
        if (p.second == max_cnt) {
            cout << p.first << ' ';
        }
    }
    return 0;
}
