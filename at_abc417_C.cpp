#include <bits/stdc++.h>
using namespace std;

int a[200005];
unordered_map<int, int> m;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        m[a[i] + i]++;
    }
    long long anss = 0;
    for (int i = 2;i <= n;i++) {
        anss += m[i - a[i]];
    }
    cout << anss;
}