#include <bits/stdc++.h>
using namespace std;

int nums[10005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        nums[i] += 2 * k;
    }
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        nums[u] += w, nums[v] += w;
    }
    sort(nums + 1, nums + 1 + n, [](int a, int b) {
        return a > b;
    });
    int a[2] = {};
    for (int i = 1;i <= n;i++) {
        a[i & 1] += nums[i];
    }
    cout << (a[1] - a[0]) / 2;
}