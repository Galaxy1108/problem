/*
### Problem Statement

Takahashi is playing a game. This game has $N$ skills numbered $1$ through $N$.

You are given $N$ pairs of integers $(A_1,B_1), \dots,(A_N,B_N)$.  
If $(A_i,B_i)=(0,0)$, then Takahashi has already learned skill $i$.  
Otherwise, Takahashi can learn skill $i$ if and only if at least one of skills $A_i$ and $B_i$ has already been learned.

Including the skills already learned, find the number of skills that Takahashi can ultimately learn.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> learn[200005];
queue<int> q;
bool is_learned[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            learn[a].push_back(i);
            continue;
        }
        learn[a].push_back(i);
        learn[b].push_back(i);
    }
    int anss = 0;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i : learn[x]) {
            if (is_learned[i]) {
                continue;
            }
            is_learned[i] = true;
            anss++;
            q.push(i);
        }
    }
    cout << anss;
    return 0;
}