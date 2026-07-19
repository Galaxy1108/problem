
#include <bits/stdc++.h>
using namespace std;

int a[105];

struct _data {
    int t, v;
};
vector<_data> saved;

int main() {
    int t, x;
    cin >> t >> x;
    for (int i = 0; i <= t; i++) {
        cin >> a[i];
    }
    saved.push_back({ 0, a[0] });
    for (int i = 1; i <= t; i++) {
        if (abs(a[i] - saved.back().v) >= x) {
            saved.push_back({ i, a[i] });
        }
    }
    for (auto& d : saved) {
        cout << d.t << ' ' << d.v << '\n';
    }
    return 0;
}////
