#include <bits/stdc++.h>
using namespace std;

long long cnts1[300005], cnts2[300005];
long long cntt1, cntt2;
long long sn[300005];

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n;i++) {
        cin >> sn[i];
        if (!cnts2[sn[i]]) {
            cntt2++;
        }
        cnts2[sn[i]]++;
    }
    long long anss = 0;
    for (long long i = 0; i < n;i++) {
        if (!cnts1[sn[i]]) {
            cntt1++;
        }
        cnts2[sn[i]]--;
        cnts1[sn[i]]++;
        if (!cnts2[sn[i]]) {
            cntt2--;
        }
        anss = max(anss, cntt1 + cntt2);
    }
    cout << anss;
    return 0;
}
/*
#### 问题陈述

给你一个正整数 $N$ 。判断是否存在一对正整数 $(x,y)$ ，使得 $x^3 - y^3 = N$ .如果存在这样的一对，请打印这样的一对 $(x,y)$ 。
*/