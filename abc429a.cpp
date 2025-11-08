#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cout << (i <= m ? "OK\n" : "Too Many Requests\n");
    }
}
