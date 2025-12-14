#include <bits/stdc++.h>
using namespace std;

int minl[1005][1005];
bool isused[26];

struct idx_t {
    int i, j;
};

queue<idx_t> que;
char maps[1005][1005];
idx_t warp[26][1000005];
int f[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int warpcnt[26];

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 1;i <= h;i++) {
        for (int j = 1;j <= w;j++) {
            cin >> maps[i][j];
            minl[i][j] = INT_MAX;
            if(maps[i][j] >= 'a' && maps[i][j] <= 'z') {
                int cidx = maps[i][j] - 'a';
                warp[cidx][warpcnt[cidx]].i = i;
                warp[cidx][warpcnt[cidx]].j = j;
                warpcnt[cidx]++;
            }
        }
    }
    minl[1][1] = 0;
    que.push({ 1, 1 });
    while (!que.empty()) {
        idx_t u = que.front();
        que.pop();
        int ni, nj;
        for (int d = 0;d < 4;d++) {
            ni = u.i + f[d][0];
            nj = u.j + f[d][1];
            if (ni >= 1 && ni <= h && nj >= 1 && nj <= w && maps[ni][nj] != '#') {
                if (minl[ni][nj] > minl[u.i][u.j] + 1) {
                    minl[ni][nj] = minl[u.i][u.j] + 1;
                    que.push({ ni, nj });
                }
            }
        }
        if (maps[u.i][u.j] >= 'a' && maps[u.i][u.j] <= 'z') {
            int cidx = maps[u.i][u.j] - 'a';
            if (!isused[cidx]) {
                isused[cidx] = true;
                for (int k = 0;k < warpcnt[cidx];k++) {
                    ni = warp[cidx][k].i;
                    nj = warp[cidx][k].j;
                    if (minl[ni][nj] > minl[u.i][u.j] + 1) {
                        minl[ni][nj] = minl[u.i][u.j] + 1;
                        que.push({ ni, nj });
                    }
                }
            }
        }
    }
    if (minl[h][w] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << minl[h][w] << '\n';
    }
}
