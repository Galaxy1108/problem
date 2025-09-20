#include <bits/stdc++.h>
using namespace std;

long double pigsx[20], pigsy[20];
int dp[(1 << 18) + 5];
int p[405], top_p;

bool ld_eq(long double a, long double b) {
    return abs(a - b) <= 1e-6;
}

long double F(long double x, long double a, long double b) {
    return a * x * x + b * x;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n;i++) {
            cin >> pigsx[i] >> pigsy[i];
        }
        top_p = 0;
        for (int i = 0; i < n;i++) {
            for (int j = i + 1; j < n;j++) {
                if (pigsx[i] == pigsx[j]) {
                    continue;
                }
                long double a = (pigsy[i] - (pigsy[j] * pigsx[i]) / pigsx[j]) / (pigsx[i] * (pigsx[i] - pigsx[j]));
                long double b = (pigsy[i] - a * pigsx[i] * pigsx[i]) / pigsx[i];
                //long double b = (pigsy[i] * pigsx[j] * pigsx[j] / pigsx[i] / pigsx[i] - pigsy[j]) / (pigsx[j] * pigsx[j] / pigsx[i] - pigsx[j]);
                if (a >= 0) {
                    continue;
                }
                p[top_p] = 0;
                for (int k = 0; k < n;k++) {
                    if (ld_eq(pigsy[k], F(pigsx[k], a, b))) {
                        p[top_p] |= (1 << k);
                    }
                }
                top_p++;
            }
        }
        for (int i = 0; i < (1 << n);i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for (int i = 0; i < (1 << n);i++) {
            if (dp[i] == INT_MAX) {
                continue;
            }
            for (int j = 0; j < top_p;j++) {
                dp[i | p[j]] = min(dp[i | p[j]], dp[i] + 1);
            }
            for (int j = 0; j < n;j++) {
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + 1);
            }
        }
        cout << dp[(1 << n) - 1] << '\n';
    }
}