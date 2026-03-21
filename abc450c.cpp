#include <bits/stdc++.h>
using namespace std;

string str[1005];
bool vis[1005][1005];
queue<pair<int, int>> q;

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> str[i];
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (str[i][j] == '#' || vis[i][j]) {
                continue;
            }
            bool is_s = true;
            q.emplace(i, j);
            vis[i][j] = true;
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                if (r == 0 || r == h - 1 || c == 0 || c == w - 1) {
                    is_s = false;
                }
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (abs(dr) + abs(dc) != 1) {
                            continue;
                        }
                        int nr = r + dr, nc = c + dc;
                        if (nr < 0 || nr >= h || nc < 0 || nc >= w) {
                            continue;
                        }
                        if (str[nr][nc] == '#' || vis[nr][nc]) {
                            continue;
                        }
                        q.emplace(nr, nc);
                        vis[nr][nc] = true;
                    }
                }
            }
            if (is_s) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
