#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;

vector<i128> a[100005];
int in[100005];

void print_i128(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x == 0) {
        putchar('0');
        return;
    }
    int len = 0;
    char buf[50];
    while (x) {
        buf[len++] = x % 10 + '0';
        x /= 10;
    }
    while (len--) {
        putchar(buf[len]);
    }
}

struct frac {
    i128 x, y;
    frac(i128 x = 0, i128 y = 0) : x(x), y(y) {}
    void operator=(frac b) {
        x = b.x;
        y = b.y;
    }
    friend frac operator+(frac a, frac b) {
        if(a.x == 0 && a.y == 0) {
            return b;
        }
        if(b.x == 0 && b.y == 0) {
            return a;
        }
        frac ans;
        i128 new_y = a.y * b.y;
        i128 new_x = a.x * b.y + b.x * a.y;
        ans.x = new_x;
        ans.y = new_y;
        i128 g = __gcd(ans.x, ans.y);
        ans.x /= g;
        ans.y /= g;
        return ans;
    }
    friend frac operator/(frac a, i128 b) {
        if(a.x == 0 && a.y == 0) {
            return a;
        }
        frac ans;
        ans.x = a.x;
        ans.y = a.y * b;
        i128 g = __gcd(ans.x, ans.y);
        ans.x /= g;
        ans.y /= g;
        return ans;
    }
    friend ostream& operator<<(ostream& os, frac p) {
        print_i128(p.x);
        os << ' ';
        print_i128(p.y);
        return os;
    }
};

queue<int> q;
frac anss[100005];

int main() {
    string s;
    s = " " + s;
    int n, m;
    cin >> n >> m;
    for (int u = 1;u <= n;u++) {
        int d;
        cin >> d;
        for (int i = 1;i <= d;i++) {
            int v;
            cin >> v;
            a[u].emplace_back(v);
            in[v]++;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 1;i <= m;i++) {
        anss[i] = frac(1, 1);
    }
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        size_t out = a[idx].size();
        for(auto v: a[idx]) {
            in[v]--;
            anss[v] = anss[v] + anss[idx] / out;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        if (a[i].size() == 0) {
            cout << anss[i] << '\n';
        }
    }
}