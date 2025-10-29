//TODO 答案不正确

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> a[1005];
ll anss[1005], cnts;
ll nums[1005][1005], son_cnt[1005];
ll cant[1005];
ll in[1005];
bool vis[1005], svis[1005];
bool s[1005];
ll n, m, x, y;
queue<ll> q;

void clean(ll n) {
    while (!q.empty()) {
        q.pop();
    }
    cnts = 0;
    for (int i = 1;i <= n;i++) {
        a[i].clear();
        for (int j = 0;j <= n;j++) {
            nums[i][j] = 0;
        }
        vis[i] = false;
        cant[i] = false;
        svis[i] = false;
        son_cnt[i] = 0;
    }
}

void get_s(ll u) {
    for (auto its : a[u]) {
        if(cant[its] || s[its]){
            continue;
        }
        s[its] = true;
        get_s(its);
    }
}

bool search(ll idx) {
    if (idx == y) {
        return true;
    }
    if (!svis[idx]) {
        for (auto its : a[idx]) {
            if (vis[its]) {
                continue;
            }
            nums[idx][++son_cnt[idx]] = its;
        }
        sort(nums[idx] + 1, nums[idx] + 1 + son_cnt[idx]);
        svis[idx] = true;
    }
    for (int i = 1;i <= son_cnt[idx];i++) {
        if (vis[nums[idx][i]] || cant[nums[idx][i]] || !s[nums[idx][i]]) {
            continue;
        }
        vis[nums[idx][i]] = true;
        anss[++cnts] = nums[idx][i];
        if (search(nums[idx][i])) {
            return true;
        }
        cnts--;
        vis[nums[idx][i]] = false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> x >> y;
        clean(n);
        for (int i = 1;i <= m;i++) {
            ll u, v;
            cin >> u >> v;
            a[u].emplace_back(v);
            a[v].emplace_back(u);
            in[u]++, in[v]++;
        }
        for (auto v : a[x]) {
            in[v]--;
        }
        for (int i = 1;i <= n;i++) {
            if (in[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            cant[u] = true;
            // cout << u << "YYY\n";
            for (auto v : a[u]) {
                in[v]--;
                if (in[v] == 1) {
                    q.push(v);
                }
            }
        }
        vis[x] = true;
        anss[++cnts] = x;
        search(x);
        for (int i = 1;i <= cnts;i++) {
            cout << anss[i] << ' ';
        }
        cout << '\n';
    }
}