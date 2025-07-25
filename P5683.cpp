#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct citys{
    ll idx, cnt;
};
queue<citys> q;
ll l1[3005], ls1[3005], ls2[3005];
vector<ll> a[3005];

int main(){
    ll n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++){
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll s1, t1, s2, t2;
    cin >> s1 >> t1 >> s2 >> t2;
    fill(l1, l1 + 1 + n, -1);
    fill(ls1, ls1 + 1 + n, -1);
    fill(ls2, ls2 + 1 + n, -1);
    q.push({ 1,0 });
    l1[1] = 0;
    while (!q.empty()){
        citys u = q.front();
        q.pop();
        for (auto v : a[u.idx]){
            if (l1[v] != -1){
                continue;
            }
            l1[v] = u.cnt + 1;
            q.push({ v,l1[v] });
        }
    }
    q.push({ s1,0 });
    ls1[s1] = 0;
    while (!q.empty()){
        citys u = q.front();
        q.pop();
        for (auto v : a[u.idx]){
            if (ls1[v] != -1){
                continue;
            }
            ls1[v] = u.cnt + 1;
            q.push({ v,ls1[v] });
        }
    }
    q.push({ s2,0 });
    ls2[s2] = 0;
    while (!q.empty()){
        citys u = q.front();
        q.pop();
        for (auto v : a[u.idx]){
            if (ls2[v] != -1){
                continue;
            }
            ls2[v] = u.cnt + 1;
            q.push({ v,ls2[v] });
        }
    }
    ll min_cnt = numeric_limits<ll>::max();
    for (int idx_a = 1;idx_a <= n;idx_a++){
        if (l1[idx_a] == -1 || ls1[idx_a] == -1 || ls2[idx_a] == -1){
            continue;
        }
        if (l1[idx_a] + ls1[idx_a] > t1){
            continue;
        }
        if (l1[idx_a] + ls2[idx_a] > t2){
            continue;
        }
        ll t = l1[idx_a] + ls1[idx_a] + ls2[idx_a];
        min_cnt = min(min_cnt, t);
    }
    cout << (min_cnt == numeric_limits<ll>::max() ? -1 : m - min_cnt);
    return 0;
}
