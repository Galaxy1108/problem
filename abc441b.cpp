#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;
    while (q--) {
        string w;
        cin >> w;
        bool in_s = true, in_t = true;
        for (char c : w) {
            if (s.find(c) == string::npos) {
                in_s = false;
            }
            if (t.find(c) == string::npos) {
                in_t = false;
            }
        }
        if (in_s && !in_t) {
            cout << "Takahashi\n";
        } else if (!in_s && in_t) {
            cout << "Aoki\n";
        } else {
            cout << "Unknown\n";
        }
    }
}
