#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_lost[200005];
ll sn[200005], n, k;

ll check() {
    ll maxs = LLONG_MIN, res = 0;
    for (int i = 1;i <= n;i++) {
        if (sn[i] == -1e18) {
            res = 0;
            continue;
        }
        res = max(0ll, res + sn[i]);
        maxs = max(maxs, res);
    }
    return maxs;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1;i <= n;i++) {
            char c;
            cin >> c;
            is_lost[i] = !(c - '0');
        }
        for (int i = 1;i <= n;i++) {
            cin >> sn[i];
            if (is_lost[i]) {
                sn[i] = -1e18;
            }
        }
        int lost_idx = 0;
        for (int i = 1;i <= n;i++) {
            if (is_lost[i]) {
                lost_idx = i;
                break;
            }
        }
        ll l = -1e12, r = 1e12;
        bool flag = true;
        while (l <= r) {
            ll mid = (l + r) / 2;
            sn[lost_idx] = mid;
            ll nums = check();
            if (nums > k) {
                r = mid - 1;
            } else if(nums < k){
                l = mid + 1;
            } else {
                flag = false;
                cout << "Yes\n";
                for (int i = 1;i <= n;i++) {
                    cout << sn[i] << ' ';
                }
                cout << '\n';
                break;
            }
        }
        if (flag) {
            cout << "No\n";
        }
    }
}