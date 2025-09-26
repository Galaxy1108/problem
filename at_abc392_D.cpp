#include <bits/stdc++.h>
using namespace std;

long long ks[105];
long long ps[105][100005];
long long pps[105][100005];
long long m[105];

int main() {
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
    printf("%.15f", anss);
    return 0;
}