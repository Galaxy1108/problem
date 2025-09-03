/*
 * @Author: Galaxy1108
 * @Date: 2025-08-30 20:03:20
 * @LastEditors: Galaxy1108
 * @LastEditTime: 2025-08-30 20:09:37
 * @FilePath: \problem\B_Fibonacci_Reversed.cpp

 ### Problem Statement

For a positive integer $x$, define $f(x)$ as follows:

-   Let $s_x$ be the string obtained by representing $x$ in decimal notation (without leading zeros), and let $\text{rev}(s_x)$ be the string obtained by reversing $s_x$. The value of $f(x)$ is the integer obtained by interpreting $\text{rev}(s_x)$ as a decimal representation of an integer.

For example, when $x=13$, we have $\text{rev}(s_x)=$ `31`, so $f(x)=31$; when $x=10$, we have $\text{rev}(s_x)=$ `01`, so $f(x)=1$. Particularly, for any positive integer $x$, the value of $f(x)$ is a positive integer.

You are given positive integers $X$ and $Y$. Define a sequence of positive integers $A=(a_1,a_2,\dots,a_{10})$ as follows:

-   $a_1 = X$
-   $a_2 = Y$
-   $a_i = f(a_{i-1}+a_{i-2})\ (i\geq 3)$

Find the value of $a_{10}$.
 */
#include <bits/stdc++.h>
using namespace std;

long long a[12];

int main() {
    long long x, y;
    cin >> x >> y;
    a[1] = x;
    a[2] = y;
    for (int i = 3; i <= 10; i++) {
        long long sum = a[i - 1] + a[i - 2];
        string s = to_string(sum);
        reverse(s.begin(), s.end());
        a[i] = stoll(s);
    }
    cout << a[10];
    return 0;
}