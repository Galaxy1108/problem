#include <bits/stdc++.h>
using namespace std;

long long ks[105];
long long ps[105][100005];
long long pps[105][100005];
long long m[105];

long long main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> ks[i];
        for (long long j = 0; j < ks[i]; j++) {
            cin >> pps[i][j];
            ps[i][pps[i][j]]++;
        }
        sort(pps[i], pps[i] + ks[i]);
        auto end = unique(pps[i], pps[i] + ks[i]);
        m[i] = end - pps[i];
    }

    double anss = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            double panss = 0;
            if (m[i] <= m[j]) {
                for (long long p = 0; p < m[i]; p++) {
                    long long x = pps[i][p];
                    if (binary_search(pps[j], pps[j] + m[j], x)) {
                        panss += (ps[i][x] * 1.0 / ks[i]) * (ps[j][x] * 1.0 / ks[j]);
                    }
                }
            } else {
                for (long long p = 0; p < m[j]; p++) {
                    long long x = pps[j][p];
                    if (binary_search(pps[i], pps[i] + m[i], x)) {
                        panss += (ps[i][x] * 1.0 / ks[i]) * (ps[j][x] * 1.0 / ks[j]);
                    }
                }
            }
            anss = max(anss, panss);
        }
    }
    prlong longf("%.15f", anss);
    return 0;
}

/*
有编号从 1 到 N 的 N 个点和编号从 1 到 M 的 M 条边。
第 i 条边双向连接点 A_i 和 B_i

执行以下操作若干次(可能为零)，使所有点相互连通。

操作：选择一条边，将其一端重新连接到另一点。

找出所需的最少操作次数，并输出实现该最少操作次数的操作序列。

2<=n<=2*10^5
n-1<=m<=2*10^5
1<=a_i,b_i<=n

读入：
n m
a_i b_i
...
a_m b_m

时间限制：2秒，空间限制：1GB
*/