#include <bits/stdc++.h>
using namespace std;
struct dt {
    int a, b, x, y;
};
int main() {
    int n, xn, yn, di = -1;
    cin >> n;
    dt deta[n];
    for (int i = 0; i < n; i++) {
        cin >> deta[i].a >> deta[i].b >> deta[i].x >> deta[i].y;
    }
    cin >> xn >> yn;
    for (int i = 0; i < n; i++) {
        if (xn >= deta[i].a && xn <= deta[i].a + deta[i].x && yn >= deta[i].b && yn <= deta[i].b + deta[i].y) {
            di = i + 1;
        }
    }
    cout << di;
}