/*
### Problem Statement

$N$ people participated in a programming contest consisting of $M$ problems.  
The participants are numbered person $1$, person $2$, $\ldots$, person $N$, and the problems are numbered problem $1$, problem $2$, $\ldots$, problem $M$.

In this contest, $K$ events occurred in order; in the $i$\-th event $(1\leq i\leq K)$, the following happened:

-   Person $A_i$ solved problem $B_i$.

The same event does not occur two or more times. Also, apart from these $K$ events, nobody solves any problem.

Output the numbers of all people who solved all problems.  
If there are multiple such people, output them in ascending order of the time at which they solved all problems.
*/

#include <bits/stdc++.h>
using namespace std;

struct p {
    int cnt, time;
    int idx;
};

p sn[14];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1;i <= k;i++) {
        int a, b;
        cin >> a >> b;
        sn[a].cnt++;
        if (sn[a].cnt == m) {
            sn[a].time = i;
        }
    }
    for (int i = 1;i <= n;i++) {
        sn[i].idx = i;
    }
    sort(sn + 1, sn + n + 1, [](p a, p b) {
        if (a.cnt != b.cnt) return a.cnt > b.cnt;
        return a.time < b.time;
    });
    for (int i = 1;i <= n;i++) {
        if (sn[i].cnt == m) {
            cout << sn[i].idx << ' ';
        }
    }
}