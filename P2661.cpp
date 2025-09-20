#include <bits/stdc++.h>
using namespace std;

int fat[200005], cnt;

int find(int x) {
    return (fat[x] == x ? (cnt++, x) : (cnt++, find(fat[x])));
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        fat[i] = i;
    }
    int anss = INT_MAX;
    for (int i = 1; i <= n;i++) {
        int to;
        cin >> to;
        cnt = 0;
        if (find(to) == i) {
            anss = min(anss, cnt);
        } else {
            fat[i] = to;
        }
    }
    cout << anss;
    return 0;
}