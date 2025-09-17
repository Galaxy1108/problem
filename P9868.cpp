#include <bits/stdc++.h>
using namespace std;

string str[3005];
char maxs[3005], mins[3005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> str[i];
        str[i] = " " + str[i];
        maxs[i] = CHAR_MIN, mins[i] = CHAR_MAX;
        for (int j = 1;j <= m;j++) {
            maxs[i] = max(maxs[i], str[i][j]);
            mins[i] = min(mins[i], str[i][j]);
        }
    }
    for (int i = 1;i <= n;i++) {
        bool flag = true;
        for (int j = 1;j <= n;j++) {
            if (i != j && mins[i] >= maxs[j]) {
                flag = false;
                break;
            }
        }
        cout << (flag ? 1 : 0);
    }
    return 0;
}