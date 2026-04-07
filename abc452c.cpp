#include <bits/stdc++.h>
using namespace std;

bool is_ok[11][11][26];
int a[11], b[11];

string s[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0;i < m;i++) {
        string t = s[i];
        int len = t.size();
        for (int i = 0; i < len; i++) {
            is_ok[len][i + 1][t[i] - 'a'] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        string t = s[i];
        if (t.size() != n) {
            cout << "No\n";
            continue;
        }
        bool f = 1;
        for (int i = 1; i <= n; i++) {
            if (!is_ok[a[i]][b[i]][t[i - 1] - 'a']) {
                f = 0;
                break;
            }
        }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}
