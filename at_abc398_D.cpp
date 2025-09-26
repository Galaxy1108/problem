#include <bits/stdc++.h>
using namespace std;

struct s {
    long long x, y;
    bool friend operator<(s a, s b) {
        return (a.x == b.x ? a.y < b.y : a.x < b.x);
    }
};

set<s> t;
long long ip = 0, jp = 0;

int main() {
    long long n, r, c;
    cin >> n >> r >> c;
    t.insert({ 0, 0 });
    for (long long i = 0; i < n;i++) {
        char s;
        cin >> s;
        switch (s) {
        case 'N':
            ip--;
            break;
        case 'W':
            jp--;
            break;
        case 'S':
            ip++;
            break;
        case 'E':
            jp++;
            break;
        }
        t.insert({ -ip, -jp });
        cout << t.count({ r - ip, c - jp });
    }
}