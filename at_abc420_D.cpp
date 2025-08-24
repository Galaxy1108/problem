#include <bits/stdc++.h>
using namespace std;

// int dp[505][505][2];
char maps[505][505];
bool is_queue[505][505][2];

int f[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int h, w;

bool check(int i, int j) {
    return (i >= 1 && j >= 1 && i <= h && j <= w);
}

struct s {
    int cnt, x, y;
    bool p;
};
queue<s> q;

int main() {
    // memset(dp,0x7f,sizeof(dp));
    cin >> h >> w;
    int sx, sy, ex, ey;
    for (int i = 1;i <= h;i++) {
        for (int j = 1;j <= w;j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (maps[i][j] == 'G') {
                ex = i, ey = j;
            }
        }
    }
    q.push({ 0,sx,sy,false });
    is_queue[sx][sy][0] = true;
    while (!q.empty()) {
        s u = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            int vx = u.x + f[i][0], vy = u.y + f[i][1];
            if (!check(vx, vy) || is_queue[vx][vy][u.p] || maps[vx][vy] == '#' || (u.p && maps[vx][vy] == 'o') || (!u.p && maps[vx][vy] == 'x')) {
                continue;
            }
            is_queue[vx][vy][u.p] = true;
            if (vx == ex && vy == ey) {
                cout << u.cnt + 1;
                return 0;
            }
            bool np = u.p;
            np ^= (maps[vx][vy] == '?');
            q.push({ u.cnt + 1,vx,vy,np });
        }
    }
    cout << -1;
    return 0;
}
