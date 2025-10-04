#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 sn[50005];
i64 ans[50005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        i64 sum1 = 0, sum2 = 0;
        for (int i = 1;i <= n;i++) {
            cin >> sn[i];
            sum2 += sn[i];
            ans[i] = 0;
        }
        i64 idx1 = 0, sum = LLONG_MAX;
        i64 ssum1, ssum2;
        for (int i = 1;i < n;i++) {
            sum1 += sn[i], sum2 -= sn[i];
            i64 s = abs(sum1 - sum2);
            if (!(s % 2) && s < sum) {
                sum = s, idx1 = i;
                ssum1 = sum1, ssum2 = sum2;
            }
        }
        if (sum == LLONG_MAX) {
            cout << -1 << '\n';
            continue;
        }
        if (sum == 0) {
            cout << 1 << '\n';
            for (int i = 1;i <= n;i++) {
                cout << sn[i] << ' ';
            }
            cout << '\n';
            continue;
        }
        bool is_first = true;
        i64 nums = sum / 2;
        if (ssum1 > ssum2) {
            for (int i = 1;i <= idx1;i++) {
                i64 p = min(nums, sn[i]);
                sn[i] -= p;
                ans[i] += p;
                nums -= p;
                if (nums == 0 && is_first) {
                    nums = sum / 2;
                    is_first = false;
                }
            }
        } else {
            for (int i = idx1 + 1;i <= n;i++) {
                i64 p = min(nums, sn[i]);
                sn[i] -= p;
                ans[i] += p;
                nums -= p;
                if (nums == 0 && is_first) {
                    nums = sum / 2;
                    is_first = false;
                }
            }
        }
        if (is_first || nums != 0) {
            cout << -1 << '\n';
            continue;
        }
        cout << 2 << '\n';
        for (int i = 1;i <= n;i++) {
            cout << sn[i] << ' ';
        }
        cout << '\n';
        for (int i = 1;i <= n;i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';     
    }
}