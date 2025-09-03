#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int na[1000000], nb[1000000];
int tmp[1000000];

ll merge_count(int* a, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int mid = (l + r) / 2;
    ll cnt = merge_count(a, l, mid) + merge_count(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            cnt += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (i = l, k = 0; i <= r; i++, k++) {
        a[i] = tmp[k];
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            na[i] = 2 * cntA;
            nb[i] = 2 * cntA + 1;
            cntA++;
        } else {
            na[i] = 2 * cntB + 1;
            nb[i] = 2 * cntB;
            cntB++;
        }
    }
    ll inv1 = merge_count(na, 0, n - 1);
    ll inv2 = merge_count(nb, 0, n - 1);
    cout << min(inv1, inv2);
    return 0;
}