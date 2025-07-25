#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct trees {
    ll cnts, dep;
    friend bool operator>(trees a, trees b) {
        return (a.cnts == b.cnts ? a.dep < b.dep : a.cnts < b.cnts);
    }
};

priority_queue<trees> pq;

int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        
    }
}