#include <bits/stdc++.h>
using namespace std;

bool is_vis[1005][1005][5];
char maps[1005][1005];
tuple<int, int, int> pres[1005][1005][5];

int main() {
    int h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 'S') {
                sx = i;
                sy = j; 
            }
            if (maps[i][j] == 'G') {
                gx = i;
                gy = j; 
            }
        }
    }
    queue<tuple<int, int, int>> que;
    que.emplace(sx, sy, 4);
    is_vis[sx][sy][4] = true;
    while (!que.empty()) {
        auto [x, y, d] = que.front();
        que.pop();
        if (x == gx && y == gy) {
            string ans;
            while (!(x == sx && y == sy && d == 4)) {
                auto [px, py, pd] = pres[x][y][d];
                if (px == x - 1) {
                    ans += 'D';
                } else {
                    if (px == x + 1) {
                        ans += 'U';
                    } else {
                        if (py == y - 1) {
                            ans += 'R';
                        } else {
                            ans += 'L';
                        }
                    }
                }
                tie(x, y, d) = pres[x][y][d];
            }
            reverse(ans.begin(), ans.end());
            cout << "Yes\n" << ans;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x;
            int ny = y;
            if (i == 0) {
                nx--;
            } else {
                if (i == 1) {
                    nx++;
                } else {
                    if (i == 2) {
                        ny--;
                    } else {
                        ny++;
                    }
                }
            }
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                continue;
            }
            if (maps[nx][ny] == '#') {
                continue;
            }
            if (d != 4) {
                if (maps[x][y] == 'o') {
                    if (i != d) {
                        continue;
                    }
                }
                if (maps[x][y] == 'x') {
                    if (i == d) {
                        continue;
                    }
                }
            }
            if (is_vis[nx][ny][i]) {
                continue;
            }
            is_vis[nx][ny][i] = true;
            pres[nx][ny][i] = {x, y, d};
            que.emplace(nx, ny, i);
        }
    }
    cout << "No\n";
    return 0;
}
