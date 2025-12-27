#include <bits/stdc++.h>
using namespace std;

int a[200005];

struct p {
    int val, cnt;
};

p st[200005];
int top;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res++;
        if (top == 0 || st[top].val != a[i]) {
            st[++top] = { a[i], 1 };
        } else {
            st[top].cnt++;
            if (st[top].cnt == 4) {
                top--;
                res -= 4;
            }
        }
    }
    cout << res;
    return 0;
}
