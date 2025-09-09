/*
You are given a positive integer sequence $a$ of length $n$. Determine if it is possible to rearrange $a$ such that there exists an integer $i$ ($1 \le i&lt;n$) satisfying

$$
\min([a_1,a_2,\ldots,a_i])=\gcd([a_{i+1},a_{i+2},\ldots,a_n]).
$$

Here $\gcd(c)$ denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of $c$, which is the maximum positive integer that divides all integers in $c$.

**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^{18}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

**Output**

For each test case, output "Yes" if it is possible, and "No" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/

#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long mins = LLONG_MAX;
        int idx = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            if(a[i] < mins){
                mins = a[i];
                idx = i;
            }
        }
        long long num = 0;
        for (int i = 1; i <= n; ++i) {
			if (i != idx && a[i] % a[idx] == 0) {
				num = __gcd(num, a[i]);
			}
		}
		cout << (num == a[idx] ? "Yes\n" : "No\n");
    }
}