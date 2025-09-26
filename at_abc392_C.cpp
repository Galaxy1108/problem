#include <bits/stdc++.h>
using namespace std;

long long idx_look[300005], idx_bib[300005], bib_idx[300005];

int main() {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n;i++) {
        cin >> idx_look[i];
    }
    for (long long i = 1; i <= n;i++) {
        cin >> idx_bib[i];
        bib_idx[idx_bib[i]] = i;
    }
    for (long long i = 1; i <= n;i++) {
        cout << idx_bib[idx_look[bib_idx[i]]] << ' ';
    }
    return 0;
}