#include <bits/stdc++.h>
using namespace std;

int a[505], dp[505], dp2[505];

int main() {
	int n, m, l;
	cin >> n >> m >> l;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i <= m;i++) {
        dp[i] = INT_MAX / 2;
    }
	dp[0] = 0;
	for (int i = 0;i < l;i++) {
        for (int j = 0;j < m;j++) {
            dp2[j] = INT_MAX / 2;
        }
        for (int j = 0;j < m;j++) {
            int c = 0;
            for (int k = i;k < n;k += l) {
                if (j >= a[k]) {
                    c += j - a[k];
                } else {
                    c += j - a[k] + m;
                }
            }
            for (int k = 0;k < m;k++) {
                dp2[(k + j) % m] = min(dp2[(k + j) % m], dp[k] + c);
            }
        }
        for (int j = 0;j < m;j++) {
            dp[j] = dp2[j];
        }
	}
    cout << dp[0];
}