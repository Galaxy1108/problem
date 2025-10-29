/*
### Problem Statement

Let $N$ be a positive integer. Define the **imbalance** of a sequence $A=(A_1, A_2, \dots, A_{2^N})$ of non-negative integers of length $2^N$ as the non-negative integer value obtained by the following operation:

-   Initially, set $X=0$.
-   Perform the following series of operations $N$ times:
    -   Update $X$ to $\max(X, \max(A) - \min(A))$, where $\max(A)$ and $\min(A)$ denote the maximum and minimum values of sequence $A$, respectively.
    -   Form a new sequence of half the length by pairing elements from the beginning two by two and arranging their sums. That is, set $A \gets (A_1 + A_2, A_3 + A_4, \dots, A_{\vert A \vert - 1} + A_{\vert A \vert})$.
-   The final value of $X$ is the imbalance.

For example, when $N=2, A=(6, 8, 3, 5)$, the imbalance is $6$ through the following steps:

-   Initially, $X=0$.
-   The first series of operations is as follows:
    -   Update $X$ to $\max(X, \max(A) - \min(A)) = \max(0, 8 - 3) = 5$.
    -   Set $A$ to $(6+8, 3+5) = (14, 8)$.
-   The second series of operations is as follows:
    -   Update $X$ to $\max(X, \max(A) - \min(A)) = \max(5, 14 - 8) = 6$.
    -   Set $A$ to $(14 + 8) = (22)$.
-   Finally, $X=6$.

You are given a non-negative integer $K$. Among all sequences of non-negative integers of length $2^N$ with sum $K$, construct a sequence that minimizes the imbalance.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll anss[1 << 21];

void get(int l, int r, int num) {
    if (num == 0) {
        return;
    }
    if (l == r) {
        anss[l] += num;
        return;
    }
    int mid = (l + r) / 2;
    get(l, mid, num / 2);
    get(mid + 1, r, num - (num / 2));
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll num = k / (1 << n);
    ll len = (1 << n);
    for (int i = 1; i <= len; i++) {
        anss[i] = num;
    }
    get(1, len, k % (1 << n));
    cout << !!(k % (1 << n)) << '\n';
    for (int i = 1; i <= len; i++) {
        cout << anss[i] << ' ';
    }
}