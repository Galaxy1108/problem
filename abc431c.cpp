#include <bits/stdc++.h>
using namespace std;

int h[200005], b[200005];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    sort(h + 1, h + n + 1);
    sort(b + 1, b + m + 1);
    int cnt = 0;
    int j = 1;
    for (int i = 1;i <= n;i++) {
        while (j <= m && b[j] < h[i]) {
            j++;
        }
        if (j == m + 1) {
            break;
        }
        cnt++;
        j++;
    }
    if (cnt >= k) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
