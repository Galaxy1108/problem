/*
### Problem Statement

There is a grid with $H$ rows and $W$ columns, and each cell is painted white or black.  
Let us denote the cell at the $i$\-th row from the top $(1\leq i\leq H)$ and the $j$\-th column from the left $(1\leq j\leq W)$ by cell $(i,j)$.  
The state of the grid is given by $H$ strings $S_1,S_2,\ldots,S_H$ of length $W$ consisting of `.` and `#`.  
If the $j$\-th character of $S_i$ is `.`, then cell $(i,j)$ is white; if it is `#`, then cell $(i,j)$ is black.

By repainting some black cells (possibly zero) to white, Takahashi wants to make the grid have no $2\times 2$ subgrid consisting only of black cells. More precisely, he wants to satisfy the following condition.

> For any integer pair $(i,j)$ with $1\leq i\leq H-1$ and $1\leq j\leq W-1$, among cells $(i,j)$, $(i,j+1)$, $(i+1,j)$, and $(i+1,j+1)$, **at least one is white**.

Find the minimum number of cells that need to be repainted white in order for Takahashi to achieve his goal.

You are given $T$ test cases; answer each of them.

### Constraints

-   $1\leq T\leq 100$
-   $2\leq H\leq 7$
-   $2\leq W\leq 7$
-   Each $S_i$ is a string of length $W$ consisting of `.` and `#`.
-   $T,H,W$ are integers.
*/

#include <bits/stdc++.h>
using namespace std;

bool maps[10][10];
int dp[10][1 << 7];
int num[10];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int h, w;
        cin >> h >> w;
        for (int i = 1;i <= h;i++) {
            num[i] = 0;
            for (int j = 1;j <= w;j++) {
                char c;
                cin >> c;
                maps[i][j] = (c == '#');
                num[i] = (num[i] << 1) + maps[i][j];
            }
        }
        for (int i = 0;i < (1 << w);i++) {
            if((i & num[1]) == i) {
                dp[1][i] = __builtin_popcount(i ^ num[1]);
            } else {
                dp[1][i] = 1e9;
            }
        }
        for (int i = 2;i <= h;i++) {
            for (int j = 0;j < (1 << w);j++) {
                if((j & num[i]) != j) {
                    dp[i][j] = 1e9;
                    continue;
                }
                dp[i][j] = 1e9;
                for (int k = 0;k < (1 << w);k++) {
                    if (dp[i - 1][k] == 1e9) {
                        continue;
                    }
                    bool flag = true;
                    for (int l = 1;l < w;l++) {
                        if (((j >> l) & 1) && ((j >> (l - 1)) & 1) && ((k >> l) & 1) && ((k >> (l - 1)) & 1)) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + __builtin_popcount(j ^ num[i]));
                    }
                }
            }
        }
        int anss = 1e9;
        for (int i = 0;i < (1 << w);i++) {
            if(dp[h][i] == 1e9) {
                continue;
            }
            anss = min(anss, dp[h][i]);
        }
        cout << anss << '\n';
    }

}