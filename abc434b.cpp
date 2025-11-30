#include <bits/stdc++.h>
using namespace std;

int cnt[105], sum[105];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        sum[a] += b;
    }
    for (int i = 1; i <= m; i++) {
        printf("%.10Lf\n", (long double)sum[i] / cnt[i]);
    }
}
