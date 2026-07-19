#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll px, py, qx, qy;
        ll rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        ll a1 = qx - px;
        ll b1 = qy - py;
        ll a2 = sx - rx;
        ll b2 = sy - ry;
        i128 c1 = (i128)qx * qx + (i128)qy * qy - (i128)px * px - (i128)py * py;
        i128 c2 = (i128)sx * sx + (i128)sy * sy - (i128)rx * rx - (i128)ry * ry;
        i128 det = (i128)a1 * b2 - (i128)b1 * a2;
        if (det != 0) {
            cout << "Yes\n";
        } else {
            if ((i128)a1 * c2 == (i128)a2 * c1 && (i128)b1 * c2 == (i128)b2 * c1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
