/*
You are given an integer $n$. Find any permutation $p$ of length $n$$^{\text{∗}}$ such that:

-   For all $2 \le i \le n$, $\max(p_{i - 1}, p_i) \bmod i$ $^{\text{†}}$ $= i - 1$ is satisfied.

If it is impossible to find such a permutation $p$, output $-1$.

$^{\text{∗}}$A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

$^{\text{†}}$$x \bmod y$ denotes the remainder from dividing $x$ by $y$.

**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 99$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 100$).

**Output**

For each test case:

-   If such a permutation $p$ doesn't exist, output a single integer $-1$.
-   Otherwise, output $n$ integers $p_1, p_2, \ldots, p_n$ — the permutation $p$ you've found. If there are multiple answers, output any of them.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (!(n % 2)) {
            cout << -1 << '\n';
            continue;
        }
        cout << n << ' ';
        for (int i = 1;i < n;i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}