#include <bits/stdc++.h>
using namespace std;

long double dp[1005][1005];

int main() {
	int maxw, maxb;
	cin >> maxw >> maxb;
	for (int w = 1;w <= maxw;w++) {
		dp[w][0] = 1;
	}
	for (int w = 1;w <= maxw;w++) {
		for (int b = 1;b <= maxb;b++) {
			dp[w][b] += 1.0l * w / (w + b);
			if (b >= 3) {
				dp[w][b] += 1.0l * b / (w + b) * (b - 1) / (w + b - 1) * (b - 2) / (w + b - 2) * dp[w][b - 3];
			}
			if (w >= 1 && b >= 2) {
				dp[w][b] += 1.0l * b / (w + b) * (b - 1) / (w + b - 1) * w / (w + b - 2) * dp[w - 1][b - 2];
			}
		}
	}
	printf("%.9Lf", dp[maxw][maxb]);
}