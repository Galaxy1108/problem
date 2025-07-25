#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct trees {
    ll cnts, dep;
    friend bool operator<(trees a, trees b) {
        return (a.cnts == b.cnts ? a.dep > b.dep : a.cnts > b.cnts);
    }
};

priority_queue<trees> pq;

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        ll w;
        cin >> w;
        pq.push({ w,0 });
    }
    while ((n - 1) % (k - 1)) {
        pq.push({ 0,0 });
        n++;
    }
    ll anss = 0;
    while (pq.size() > 1) {
        trees new_tre = { 0,1 };
        for (int i = 1;i <= k;i++) {
            trees v = pq.top();
            pq.pop();
            new_tre.cnts += v.cnts;
            new_tre.dep = max(new_tre.dep, v.dep + 1);
        }
        anss += new_tre.cnts;
        pq.push(new_tre);
    }
    cout << anss << '\n' << pq.top().dep;
}