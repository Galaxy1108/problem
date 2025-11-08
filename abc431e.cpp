#include <bits/stdc++.h>
using namespace std;

int mapa(int d) {
    return d;
}

int mapb(int d) {
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    return 2;
}

int mapc(int d) {
    if (d == 0) return 3;
    if (d == 3) return 0;
    if (d == 1) return 2;
    return 1;
}

int d4node(int i, int j, int d, int W) {
    return ((i * W + j) << 2) | d;
}

string s[200005];
int w[1000010];
deque<int> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int H, W;
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < 4 * H * W; i++) {
            w[i] = INT_MAX;
        }
        int st = d4node(0, 0, 0, W);
        w[st] = 0;
        dq.push_front(st);
        int anss = INT_MAX;
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();
            int wu = w[u];
            int d = u & 3, idx = u >> 2, i = idx / W, j = idx % W;
            for (int k = 0; k < 3; k++) {
                char t = 'A' + k;
                int dc;
                if (t == 'A') {
                    dc = mapa(d);
                } else if (t == 'B') {
                    dc = mapb(d);
                } else {
                    dc = mapc(d);
                }
                int nd = wu + ((s[i][j] == t) ? 0 : 1);
                int ni = i, nj = j;
                if (dc == 0) {
                    nj = j + 1;
                } else if (dc == 1) {
                    ni = i + 1;
                } else if (dc == 2) {
                    nj = j - 1;
                } else {
                    ni = i - 1;
                }
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    if (i == H - 1 && j == W - 1 && dc == 0) {
                        if (nd < anss) {
                            anss = nd;
                        }
                    }
                    continue;
                }
                int v = d4node(ni, nj, dc, W);
                if (nd < w[v]) {
                    w[v] = nd;
                    if (s[i][j] == t) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }
        if (anss == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << anss << '\n';
        }
    }
    return 0;
}
