#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int num[1000005], cnt[1000005];

int main() {
    string str;
    cin >> str;
    ll ans = 0;
    int len = str.size();
    int cnts = 0;
    for (int i = 0; i < len; i++) {
        if (i == 0 || str[i] != str[i - 1]) {
            num[++cnts] = str[i] - '0';
            cnt[cnts] = 1;
        } else {
            cnt[cnts]++;
        }
    }
    for (int i = 1; i < cnts; i++) {
        if (num[i] + 1 == num[i + 1]) {
            ans += min(cnt[i], cnt[i + 1]);
        }
    }
    cout << ans;
}
