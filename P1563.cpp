#include <bits/stdc++.h>
using namespace std;

bool is_out[100005];
string names[100005];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n;i++) {
        cin >> is_out[i] >> names[i];
    }
    int a = 0;
    for (int i = 0; i < m;i++) {
        int t, k;
        cin >> t >> k;
        a = (t == 0) ? ((!is_out[a]) ? (a >= k ? a - k : n + a - k) : (a + k < n ? a + k : a + k - n)) : ((!is_out[a]) ? (a + k < n ? a + k : a + k - n) : (a >= k ? a - k : n + a - k));
    }
    cout << names[a];
    return 0;
}