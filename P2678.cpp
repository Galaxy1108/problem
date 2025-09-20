#include <bits/stdc++.h>
using namespace std;

int n, m;

bool check(int a, int sn[]) {
    int tmpa = 0, cnt = 0;
    for (int i = 0;i < n;i++) {
        if (sn[i] - tmpa < a) {
            cnt++;
        } else {
            tmpa = sn[i];
        }
    }
    return cnt <= m;
}

int main() {
    int uh;
    cin >> uh >> n >> m;
    int sn[n + 1], l = 0, r = uh;
    for (int i = 0;i < n;i++) {
        cin >> sn[i];
    }
    sn[n] = uh;
    n++;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, sn)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        //	cout<<r<<" "<<l<<endl;
    }
    cout << ans << endl;
    return 0;
}