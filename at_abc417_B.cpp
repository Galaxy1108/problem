#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];
bool tag[105];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
        for (int j = 1;j <= n;j++) {
            if (tag[j]) {
                continue;
            }
            if (a[j] == b[i]) {
                tag[j] = true;
                break;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        if (!tag[i]) {
            cout << a[i] << ' ';
        }
    }
}