#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define maxn 200000
ll p[maxn + 5], w[maxn + 5], c[maxn + 5], fat[maxn + 5];
long double anss[maxn + 5];

ll get_father(ll idx) {
    return (idx == fat[idx] ? idx : fat[idx] = get_father(fat[idx]));
}

struct sub {
    ll sum, cnt, idx;
    friend bool operator <(sub a, sub b) {
        return (__int128)a.sum * b.cnt < (__int128)b.sum * a.cnt;
    }
};

priority_queue<sub> pq;

int main() {
    ll n;
    cin >> n;
    for (int i = 2;i <= n;i++) {
        cin >> p[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
        fat[i] = i, c[i] = 1;
        pq.push({ w[i],1,i });
    }
    while (!pq.empty()) {
        sub u = pq.top();
        pq.pop();
        if (fat[u.idx] != u.idx) {
            continue;
        }
        anss[u.idx] = u.sum / (long double)u.cnt;
        fat[u.idx] = get_father(p[u.idx]);
        if (fat[u.idx]) {
            w[fat[u.idx]] += w[u.idx];
            c[fat[u.idx]] += c[u.idx];
            pq.push({ w[fat[u.idx]],c[fat[u.idx]],fat[u.idx] });
        }
    }
    for (int i = 1;i <= n;i++) {
        printf("%.10Lf\n", anss[i]);
    }
    return 0;
}