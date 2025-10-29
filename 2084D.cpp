/*
You are given three integers $n$, $m$, and $k$, where $m \cdot k &lt; n$.

For a sequence $b$ consisting of non-negative integers, define $f(b)$ as follows:

-   You may perform the following operation on $b$:
    -   Let $l$ denote the current length of $b$. Choose a positive integer $1 \leq i \leq l - k + 1$, remove the subarray from index $i$ to $i + k - 1$ and concatenate the remaining parts. In other words, replace $b$ with
        $$
        [b_1, b_2, \ldots, b_{i - 1}, b_{i + k}, b_{i + k + 1}, \ldots, b_l].
        $$
        
-   $f(b)$ is defined as the **minimum** possible value of $\operatorname{mex}(b)$$^{\text{∗}}$ after performing the above operation **at most $m$ times** (possibly zero).

You need to construct a sequence $a$ of length $n$ consisting of non-negative integers, such that:

-   For all $1 \le i \le n$, $0 \le a_i \le 10^9$.
-   Over all such sequences $a$, $f(a)$ is **maximized**.

$^{\text{∗}}$The minimum excluded (MEX) of a collection of integers $c_1, c_2, \ldots, c_k$ is defined as the smallest non-negative integer $x$ which does not occur in the collection $c$.

**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains three integers $n$, $m$, and $k$ ($2 \le n \le 2 \cdot 10^5$, $1 \le m &lt; n$, $1 \le k &lt; n$, $1 \le m \cdot k &lt; n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

**Output**

For each test case, output $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$).

If there are multiple answers, print any of them.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int s = 0;
        if (n < (m + 1) * k) {
            s = k;
        } else {
            s = n / (m + 1);
        }
        for (int i = 1;i <= n;i++) {
            cout << (i - 1) % s << ' ';
        }
        cout << '\n';
    }
}