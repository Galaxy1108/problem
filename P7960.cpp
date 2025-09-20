#include <bits/stdc++.h>
using namespace std;

bool not_can[10000005];
int cnts[10000005], cntt;
int stnc[10000005];

bool is_t_ncan(int a) {
    while (a) {
        int p = a % 10;
        if (p == 7) {
            return true;
        }
        a /= 10;
    }
    return false;
}

void calc(int N) {
    for (int i = 1;i <= N;i++) {
        not_can[i] |= is_t_ncan(i);
        if (not_can[i]) {
            for (int j = i;j <= N;j += i) {
                not_can[j] = true;
            }
        } else {
            cnts[++cntt] = i;
            stnc[i] = cntt;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calc(10000005);
    //	cout<<not_can[6];
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        if (not_can[x]) {
            cout << -1 << '\n';
            continue;
        }
        cout << cnts[stnc[x] + 1] << '\n';
    }
}