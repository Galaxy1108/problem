#include <bits/stdc++.h>
using namespace std;

struct s {
    int val, idx;
};

s num[200005];
int num3[200005];
bool is_must[200005];
bool is_s[200005];
int num2[200005];


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1;i <= n;i++) {
            cin >> num[i].val;
            num[i].idx = i;
            is_must[i] = is_s[i] = false;
            num3[i] = num[i].val;
        }
        sort(num + 1, num + 1 + n, [](s a, s b) {
            return (a.val == b.val ? a.idx < b.idx : a.val < b.val);
        });
        int cnts = 0, cnt0 = 0;
        for (int i = 1;i <= n;i++) {
            if (i < k) {
                is_must[num[i].val] = true;
            }
            if (i == k) {
                is_s[num[i].val] = true;
            }
        }
        cnts = 0;
        for (int i = 1;i <= n;i++) {
            if (is_must[num3[i]] || is_s[num3[i]]) {
                num2[++cnts] = num3[i];
            }
        }
        int l = 1, r = cnts;
        bool flag = true;
        while (l < r) {
            if (num2[l] == num2[r]) {
                l++, r--;
                continue;
            }
            if (is_s[num2[l]]) {
                l++;
                cnts--;
                continue;
            }
            if (is_s[num2[r]]) {
                r--;
                cnts--;
                continue;
            }
            flag = false;
            break;
        }
        cout << ((flag && cnts >= k - 1) ? "YES\n" : "NO\n");
    }
}