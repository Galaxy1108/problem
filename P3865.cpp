#include <bits/stdc++.h>
using namespace std;


using idx_t = unsigned int;



ST<int, 100005> st;

int sn[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> sn[i];
    }
    st.set(sn, n, [](int a, int b) {
        return max(a, b);
    });
    st.init();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}