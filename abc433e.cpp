#include <bits/stdc++.h>
using namespace std;

int n, m;
int ma[200005];

inline void writema(int x, int y, int val) {
    ma[(x - 1) * m + y] = val;
}

struct data_t {
    int val, idx;
};

struct idx_t {
    int i, j;
};

data_t x[200005], y[200005];
bool isusedx[200005], isusedy[200005];

queue<idx_t> q;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> x[i].val;
            x[i].idx = i;
            isusedx[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            cin >> y[i].val;
            y[i].idx = i;
            isusedy[i] = false;
        }
        sort(x + 1, x + n + 1, [](data_t a, data_t b) {
            return a.val > b.val;
        });
        sort(y + 1, y + m + 1, [](data_t a, data_t b) {
            return a.val > b.val;
        });
        int usedx = 0, usedy = 0;
        bool flag = true;
        for (int num = n * m; num >= 1; num--) {
            data_t thisx = (usedx == n ? (data_t){-1, -1} : x[usedx + 1]), thisy = (usedy == m ? (data_t){-1, -1} : y[usedy + 1]);
            if (thisx.val == num && thisy.val == num) {
                writema(thisx.idx, thisy.idx, num);
                usedx++;
                usedy++;
                for (int j = 1;j <= m;j++) {
                    if (j == thisy.idx || !isusedy[j]) {
                        continue;
                    }
                    q.push({ thisx.idx,j });
                }
                for (int i = 1;i <= n;i++) {
                    if (i == thisx.idx || !isusedx[i]) {
                        continue;
                    }
                    q.push({ i,thisy.idx });
                }
                isusedx[thisx.idx] = true;
                isusedy[thisy.idx] = true;
            } else if (thisx.val == num) {
                if(usedy == 0) {
                    flag = false;
                    break;
                }
                writema(thisx.idx, y[usedy].idx, num);
                usedx++;
                for (int j = 1;j <= m;j++) {
                    if (j == y[usedy].idx || !isusedy[j]) {
                        continue;
                    }
                    q.push({ thisx.idx,j });
                }
                isusedx[thisx.idx] = true;
            } else if (thisy.val == num) {
                if (usedx == 0) {
                    flag = false;
                    break;
                }
                writema(x[usedx].idx, thisy.idx, num);
                usedy++;
                for (int i = 1; i <= n; i++) {
                    if (i == x[usedx].idx || !isusedx[i]) {
                        continue;
                    }
                    q.push({ i,thisy.idx });
                }
                isusedy[thisy.idx] = true;
            } else {
                if (q.empty()) {
                    flag = false;
                    break;
                }
                idx_t thisidx = q.front();
                q.pop();
                writema(thisidx.i, thisidx.j, num);
            }
        }
        if (flag) {
            cout << "Yes\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << ma[(i - 1) * m + j] << ' ';
                }
                cout << '\n';
            }
        } else {
            while (!q.empty()) {
                q.pop();
            }
            cout << "No\n";
        }
    }
}
