#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
vector<pair<int, int>> addl;

long long anss;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    s.insert({ 1, n });
    anss = n;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it = s.lower_bound({ l, -1 });
        if (it != s.begin()) {
            --it;
        }
        addl.clear();
        while (it != s.end()) {
            int sl = it->first, sr = it->second;
            if (sr < l) {
                ++it;
                continue;
            }
            if (sl > r) {
                break;
            }
            if (sl < l) {
                addl.push_back({ sl, l - 1 });
            }
            if (sr > r) {
                addl.push_back({ r + 1, sr });
            }
            it = s.erase(it);
            anss -= min(sr, r) - max(sl, l) + 1;
        }
        for (auto p : addl) {
            s.insert(p);
        }
        cout << anss << '\n';
    }
    return 0;
}
