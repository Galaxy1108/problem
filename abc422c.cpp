#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int sn[10];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        int maxs = min(b, min(a, c));
        int cnts = 0;
        sn[cnts++] = 0;
        sn[cnts++] = maxs;
        int v1 = 2 * a - c;
        int c1 = v1 / 3;
        int c2 = c1 + 1;
        if (c1 >= 0 && c1 <= maxs) {
            sn[cnts++] = c1;
        }
        if (c2 >= 0 && c2 <= maxs) {
            sn[cnts++] = c2;
        }
        int v2 = 2 * c - a;
        int c3 = v2 / 3;
        int c4 = c3 + 1;
        if (c3 >= 0 && c3 <= maxs) {
            sn[cnts++] = c3;
        }
        if (c4 >= 0 && c4 <= maxs) {
            sn[cnts++] = c4;
        }
        int anss = 0;
        for (int i = 0; i < cnts; i++) {
            int x = sn[i];
            int d = a - x;
            int e = c - x;
            int s = min(d, min(e, (d + e) / 3));
            int p = x + s;
            if (p > anss) {
                anss = p;
            }
        }
        cout << anss << '\n';
    }
    return 0;
}