#include <bits/stdc++.h>
using namespace std;

string str;

int get_ans(int l, int r, char c) {
    if (l == r) {
        return str[l] != c;
    }
    int cnt1 = 0, cnt2 = 0;
    int mid = (l + r) / 2;
    for (int i = l;i <= mid;i++) {
        cnt1 += str[i] != c;
    }
    for (int i = mid + 1;i <= r;i++) {
        cnt2 += str[i] != c;
    }
    cnt1 += get_ans(mid + 1, r, c + 1);
    cnt2 += get_ans(l, mid, c + 1);
    return min(cnt1, cnt2);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n >> str;
        str = " " + str;
        cout << get_ans(1, n, 'a') << '\n';
    }
}