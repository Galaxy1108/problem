#include <bits/stdc++.h>
using namespace std;

int is_can[25005], sn[105];
int is_not[25005];
int T, n;
int cn_t;

bool is_in(int a) {
    if (a <= 0) {
        return false;
    }
    if (a != sn[cn_t] && is_can[a] == T) {
        return true;
    }
    if (a != sn[cn_t] && is_not[a] == T) {
        return false;
    }
    bool can_a = false;
    for (int i = 0;i < n;i++) {
        if (i == cn_t) {
            continue;
        }
        can_a |= is_in(a - sn[i]);
    }
    return (can_a ? (is_can[a] = T, true) : (is_not[a] = T, false));
}

int main() {
    cin >> T;
    do {
        if (T == 0) {
            return 0;
        }
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> sn[i];
            is_can[sn[i]] = T;
        }
        int anss = n;
        for (int i = 0;i < n;i++) {
            cn_t = i;
            anss -= is_in(sn[i]);
        }
        cout << anss << '\n';
    } while (T--);
}