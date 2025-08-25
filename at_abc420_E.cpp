#include <bits/stdc++.h>
using namespace std;

int fat[200005];
int get_fat(int a) {
    return (fat[a] == a ? a : fat[a] = get_fat(fat[a]));
}

int bcnt[200005];
bool is_black[200005];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0;i <= n;i++) {
        fat[i] = i;
    }
    while (q--) {
        int opt, u, v;
        cin >> opt;
        if (opt == 1) {
            cin >> u >> v;
            int fu = get_fat(u), fv = get_fat(v);
            if (fu != fv) {
                fat[fu] = fv;
                bcnt[fv] += bcnt[fu];
                bcnt[fu] = 0;
            }
        } else if (opt == 2) {
            cin >> u;
            is_black[u] ^= 1;
            if (is_black[u]) {
                bcnt[get_fat(u)]++;
            } else {
                bcnt[get_fat(u)]--;
            }
        } else {
            cin >> u;
            cout << (bcnt[get_fat(u)] ? "Yes\n" : "No\n");
        }
    }
}