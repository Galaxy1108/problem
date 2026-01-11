#include <bits/stdc++.h>
using namespace std;

struct ho {
    int n, t;
};

ho hos[40];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> hos[i].t;
        hos[i].n = i;
    }
    sort(hos + 1, hos + n + 1, [](ho a, ho b) { return a.t < b.t; });
    cout << hos[1].n << ' ' << hos[2].n << ' ' << hos[3].n;
    return 0;
}
