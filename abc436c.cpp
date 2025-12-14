#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> bs;

int main() {
    int n, m;
    cin >> n >> m;
    for (int k = 0; k < m; k++) {
        int r, c;
        cin >> r >> c;
        if (bs.count({r, c}) == 0 && bs.count({r + 1, c}) == 0 && bs.count({r, c + 1}) == 0 && bs.count({r + 1, c + 1}) == 0) {
            bs.insert({ r, c });
            bs.insert({ r + 1, c });
            bs.insert({ r, c + 1 });
            bs.insert({ r + 1, c + 1 });
        }
    }
    cout << bs.size() / 4;
    return 0;
}
