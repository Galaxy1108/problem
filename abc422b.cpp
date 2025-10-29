/*
 * @Author: Galaxy1108
 * @Date: 2025-09-07 12:12:03
 * @LastEditors: Galaxy1108
 * @LastEditTime: 2025-09-07 12:14:34
 * @FilePath: \problem\B_Looped_Rope.cpp
 */
/*
### Problem Statement

There is a grid with $H$ rows and $W$ columns. Let $(i,j)$ denote the cell at the $i$\-th row $(1\le i\le H)$ from the top and the $j$\-th column $(1\le j\le W)$ from the left.

Each cell is painted with one color, white or black. The color painted on the cells is represented by $H$ strings $S _ 1,S _ 2,\ldots,S _ H$. When the $j$\-th character $(1\le j\le W)$ of $S _ i\ (1\le i\le H)$ is `.`, cell $(i,j)$ is painted white, and when the $j$\-th character $(1\le j\le W)$ of $S _ i\ (1\le i\le H)$ is `#`, cell $(i,j)$ is painted black.

Determine whether the grid satisfies the following condition:

-   For every black cell, the number of horizontally or vertically adjacent cells that are painted black is $2$ or $4$.

Here, cells $(i,j)\ (1\le i\le H,1\le j\le W)$ and $(k,l)\ (1\le k\le H,1\le l\le W)$ are horizontally or vertically adjacent if and only if $|i-k|+|j-l|=1$.
*/

#include <bits/stdc++.h>
using namespace std;

char s[25][25];

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w && s[ni][nj] == '#') {
                        cnt++;
                    }
                }
                if (cnt != 2 && cnt != 4) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}