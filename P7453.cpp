#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define mod 998244353
#define lch trr[idx * 2]
#define rch trr[idx * 2 + 1]
#define ts trr[idx]

struct mat {
    ll m[5][5];
    mat() {
        m[1][1] = m[1][2] = m[1][3] = m[1][4] = 0;
        m[2][1] = m[2][2] = m[2][3] = m[2][4] = 0;
        m[3][1] = m[3][2] = m[3][3] = m[3][4] = 0;
        m[4][1] = m[4][2] = m[4][3] = m[4][4] = 0;
    }
    void init() {
        m[1][1] = m[2][2] = m[3][3] = m[4][4] = 1;
        m[1][2] = m[1][3] = m[1][4] = 0;
        m[2][1] = m[2][3] = m[2][4] = 0;
        m[3][1] = m[3][2] = m[3][4] = 0;
        m[4][1] = m[4][2] = m[4][3] = 0;
    }
    friend mat operator+(mat a, mat b) {
        mat ans;
        ans.m[1][1] = (a.m[1][1] + b.m[1][1]) % mod;
        ans.m[1][2] = (a.m[1][2] + b.m[1][2]) % mod;
        ans.m[1][3] = (a.m[1][3] + b.m[1][3]) % mod;
        ans.m[1][4] = (a.m[1][4] + b.m[1][4]) % mod;
        //ans.m[2][1] = (a.m[2][1] + b.m[2][1]) % mod;
        //ans.m[2][2] = (a.m[2][2] + b.m[2][2]) % mod;
        //ans.m[2][3] = (a.m[2][3] + b.m[2][3]) % mod;
        //ans.m[2][4] = (a.m[2][4] + b.m[2][4]) % mod;
        //ans.m[3][1] = (a.m[3][1] + b.m[3][1]) % mod;
        //ans.m[3][2] = (a.m[3][2] + b.m[3][2]) % mod;
        //ans.m[3][3] = (a.m[3][3] + b.m[3][3]) % mod;
        //ans.m[3][4] = (a.m[3][4] + b.m[3][4]) % mod;
        //ans.m[4][1] = (a.m[4][1] + b.m[4][1]) % mod;
        //ans.m[4][2] = (a.m[4][2] + b.m[4][2]) % mod;
        //ans.m[4][3] = (a.m[4][3] + b.m[4][3]) % mod;
        //ans.m[4][4] = (a.m[4][4] + b.m[4][4]) % mod;
        return ans;
    }
    friend mat operator*(mat a, mat b) {
        mat ans;
        ans.m[1][1] = (a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1] + a.m[1][4] * b.m[4][1]) % mod;
        ans.m[1][2] = (a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2] + a.m[1][4] * b.m[4][2]) % mod;
        ans.m[1][3] = (a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] + a.m[1][3] * b.m[3][3] + a.m[1][4] * b.m[4][3]) % mod;
        ans.m[1][4] = (a.m[1][1] * b.m[1][4] + a.m[1][2] * b.m[2][4] + a.m[1][3] * b.m[3][4] + a.m[1][4] * b.m[4][4]) % mod;
        ans.m[2][1] = (a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1] + a.m[2][4] * b.m[4][1]) % mod;
        ans.m[2][2] = (a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2] + a.m[2][4] * b.m[4][2]) % mod;
        ans.m[2][3] = (a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] + a.m[2][3] * b.m[3][3] + a.m[2][4] * b.m[4][3]) % mod;
        //ans.m[2][4] = (a.m[2][1] * b.m[1][4] + a.m[2][2] * b.m[2][4] + a.m[2][3] * b.m[3][4] + a.m[2][4] * b.m[4][4]) % mod;
        ans.m[3][1] = (a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] + a.m[3][3] * b.m[3][1] + a.m[3][4] * b.m[4][1]) % mod;
        ans.m[3][2] = (a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] + a.m[3][3] * b.m[3][2] + a.m[3][4] * b.m[4][2]) % mod;
        ans.m[3][3] = (a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] + a.m[3][3] * b.m[3][3] + a.m[3][4] * b.m[4][3]) % mod;
        //ans.m[3][4] = (a.m[3][1] * b.m[1][4] + a.m[3][2] * b.m[2][4] + a.m[3][3] * b.m[3][4] + a.m[3][4] * b.m[4][4]) % mod;
        ans.m[4][1] = (a.m[4][1] * b.m[1][1] + a.m[4][2] * b.m[2][1] + a.m[4][3] * b.m[3][1] + a.m[4][4] * b.m[4][1]) % mod;
        ans.m[4][2] = (a.m[4][1] * b.m[1][2] + a.m[4][2] * b.m[2][2] + a.m[4][3] * b.m[3][2] + a.m[4][4] * b.m[4][2]) % mod;
        ans.m[4][3] = (a.m[4][1] * b.m[1][3] + a.m[4][2] * b.m[2][3] + a.m[4][3] * b.m[3][3] + a.m[4][4] * b.m[4][3]) % mod;
        ans.m[4][4] = (a.m[4][1] * b.m[1][4] + a.m[4][2] * b.m[2][4] + a.m[4][3] * b.m[3][4] + a.m[4][4] * b.m[4][4]) % mod;
        return ans;
    }
};

mat opt[7], a[250005];

struct smt {
    struct node {
        ll l, r;
        mat num, tag;
    };
    node trr[1000005];
    void add(ll idx, mat& opt, ll& l, ll& r) {
        if (ts.l > r || ts.r < l) {
            return;
        }
        if (ts.l >= l && ts.r <= r) {
            ts.num = ts.num * opt;
            ts.tag = ts.tag * opt;
            return;
        }
        lch.num = lch.num * ts.tag;
        rch.num = rch.num * ts.tag;
        lch.tag = lch.tag * ts.tag;
        rch.tag = rch.tag * ts.tag;
        ts.tag.m[1][1] = ts.tag.m[2][2] = ts.tag.m[3][3] = ts.tag.m[4][4] = 1;
        ts.tag.m[1][2] = ts.tag.m[1][3] = ts.tag.m[1][4] = 0;
        ts.tag.m[2][1] = ts.tag.m[2][3] = ts.tag.m[2][4] = 0;
        ts.tag.m[3][1] = ts.tag.m[3][2] = ts.tag.m[3][4] = 0;
        ts.tag.m[4][1] = ts.tag.m[4][2] = ts.tag.m[4][3] = 0;
        ll mid = (l + r) / 2;
        add(2 * idx, opt, l, r);
        add(2 * idx + 1, opt, l, r);
        ts.num = lch.num + rch.num;
    }
    void query(ll idx, ll& l, ll& r, mat& ans) {
        if (ts.l > r || ts.r < l) {
            return;
        }
        if (ts.l >= l && ts.r <= r) {
            ans = ans + ts.num;
            return;
        }
        lch.num = lch.num * ts.tag;
        rch.num = rch.num * ts.tag;
        lch.tag = lch.tag * ts.tag;
        rch.tag = rch.tag * ts.tag;
        ts.tag.m[1][1] = ts.tag.m[2][2] = ts.tag.m[3][3] = ts.tag.m[4][4] = 1;
        ts.tag.m[1][2] = ts.tag.m[1][3] = ts.tag.m[1][4] = 0;
        ts.tag.m[2][1] = ts.tag.m[2][3] = ts.tag.m[2][4] = 0;
        ts.tag.m[3][1] = ts.tag.m[3][2] = ts.tag.m[3][4] = 0;
        ts.tag.m[4][1] = ts.tag.m[4][2] = ts.tag.m[4][3] = 0;
        ll mid = (l + r) / 2;
        query(2 * idx, l, r, ans);
        query(2 * idx + 1, l, r, ans);
        ts.num = lch.num + rch.num;
    }
    void build(ll idx, ll l, ll r) {
        ts.tag.init();
        if (l == r) {
            ts.l = l, ts.r = r;
            ts.num = a[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        ts.l = l, ts.r = r;
        ts.num = lch.num + rch.num;
    }
};

smt trr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    opt[1].init(), opt[2].init(), opt[3].init();
    opt[4].init(), opt[5].init(), opt[6].init();
    opt[1].m[2][1] = opt[2].m[3][2] = opt[3].m[1][3] = 1;
    opt[6].m[3][3] = 0;
    ll n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].m[1][1] >> a[i].m[1][2] >> a[i].m[1][3];
        a[i].m[1][4] = 1;
    }
    trr.build(1, 1, n);
    ll m;
    cin >> m;
    while (m--) {
        ll optt, l, r;
        cin >> optt >> l >> r;
        if (optt < 4) {
            trr.add(1, opt[optt], l, r);
        } else if (optt <= 6) {
            ll v;
            cin >> v;
            opt[4].m[4][1] = opt[5].m[2][2] = opt[6].m[4][3] = v;
            trr.add(1, opt[optt], l, r);
        } else {
            mat ans;
            trr.query(1, l, r, ans);
            cout << ans.m[1][1] << ' ' << ans.m[1][2] << ' ' << ans.m[1][3] << endl;
        }
    }
}
