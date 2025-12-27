#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int b[100];

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 1; i <= h; i++) {
        int cnt = 0;
        for (int j = 1; j <= w; j++) {
            for (int k = 1; k <= n; k++) {
                if (a[i][j] == b[k]) {
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
