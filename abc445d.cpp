#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define MAXN 200005

struct xyhw {
    ll x, y, h, w;
};

ll w[MAXN], h[MAXN];
char used[MAXN];
ll ansx[MAXN],ansy[MAXN];

xyhw st[MAXN];
int top = 0;

unordered_map<ll, vector<int>> um_h;
unordered_map<ll, vector<int>> um_w;

int main() {
    ll x, y, n;
    cin >> x >> y >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i] >> w[i];
    }
    um_h.reserve(n * 2);
    um_w.reserve(n * 2);
    for (int i = 1; i <= n; ++i) {
        um_h[h[i]].push_back(i);
        um_w[w[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        used[i] = 0;
    }
    top = 0;
    st[top] = { 1,1,x,y };
    top++;
    while (top > 0) {
        --top;
        xyhw r = st[top];
        int idx = -1;
        auto ith = um_h.find(r.h);
        if (ith != um_h.end()) {
            auto& vec = ith->second;
            while (!vec.empty() && used[vec.back()]) {
                vec.pop_back();
            }
            if (!vec.empty()) {
                idx = vec.back();
                vec.pop_back();
            }
        }
        if (idx == -1) {
            auto itw = um_w.find(r.w);
            if (itw != um_w.end()) {
                auto& vec = itw->second;
                while (!vec.empty() && used[vec.back()]) {
                    vec.pop_back();
                }
                if (!vec.empty()) {
                    idx = vec.back();
                    vec.pop_back();
                }
            }
        }
        if (idx == -1) {
            cout << "-1\n";
            return 0;
        }
        used[idx] = 1;
        ansx[idx] = r.x;
        ansy[idx] = r.y;
        if (h[idx] == r.h) {
            ll rm = r.w - w[idx];
            if (rm > 0) {
                st[top].x = r.x;
                st[top].y = r.y + w[idx];
                st[top].h = r.h;
                st[top].w = rm;
                top++;
            }
        } else {
            ll rh = r.h - h[idx];
            if (rh > 0) {
                st[top].x = r.x + h[idx];
                st[top].y = r.y;
                st[top].h = rh;
                st[top].w = r.w;
                top++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ansx[i] << ' ' << ansy[i] << '\n';
    }
    return 0;
}
