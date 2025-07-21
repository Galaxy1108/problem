/**
## 题目描述

对于一个 $\tt 01$ 串 $S$（下标从 $1$ 开始），我们定义它的一个区间 $[l,r]$ 是**极长颜色段**，当且仅当它**同时**满足以下条件：
- 如果 $l\neq 1$，$S_{l-1}\neq S_l$；
- 如果 $r\neq \lvert S\rvert$，$S_{r+1}\neq S_r$；
- $\forall i\in[l,r),S_i=S_{i+1}$。

定义 $g(S)$ 为 $S$ 的**不同**极长颜色段数。比如 $g(00)=1$，$g(1110)=2$，$g(001011)=4$。

定义 $f(n,m)$ 的值为所有**恰好包含 $\boldsymbol n$ 个 $\tt 0$ 和 $\boldsymbol m$ 个 $\tt 1$** 的 $\tt 01$ 串 $S$ 的 $g(S)$ 之和。

你需要回答 $T$ 个问题，每次给出 $n,m$ 的值，求 $f(n,m)$ 的值对 $10^9+7$ 取模后的结果。

## 输入格式

第一行输入一个正整数数 $T$，表示问题个数。

接下来 $T$ 行，每行两个非负整数 $n,m$，表示问题的参数。

## 输出格式

输出 $T$ 行，每行为对应问题的答案。
 */

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long f[2000005];

long long fast_pow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return fast_pow(a, mod - 2);
}

long long get_c(long long a,long long b){
    return f[a] * inv(f[b] * f[a - b] % mod) % mod;
}

int main(){
    int T;
    cin >> T;
    f[0] = 1;
    for (int i = 1; i <= 2000000; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    while(T--){
        long long n, m;
        cin >> n >> m;
        if (n == 0 || m == 0) {
            cout << 1 << endl;
            continue;
        }
        cout << (get_c(n + m, n) + ((n + m - 1) * get_c(n + m - 2, n - 1) % mod) * 2 % mod) % mod << '\n';
    }
}