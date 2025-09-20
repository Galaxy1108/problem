#include <bits/stdc++.h>
using namespace std;

int father[400010];

struct f {
    long long u, v, w;
}sn[200005];

int get_father(int a) {
    return (a == father[a] ? a : father[a] = get_father(father[a]));
}

bool cmp(f a, f b) {
    return a.w > b.w;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("prison.in", "r", stdin);
    //freopen("prison.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= 2 * n;i++) {
        father[i] = i;
    }
    for (int i = 0; i < m;i++) {
        cin >> sn[i].u >> sn[i].v >> sn[i].w;
    }
    sort(sn, sn + m, cmp);
    for (int i = 0; i < m;i++) {
        int u = sn[i].u, v = sn[i].v;
        int fu = get_father(u), fnu = get_father(n + u), fv = get_father(v), fnv = get_father(n + v);
        //cout<<u<<" "<<v<<" "<<fu<<" "<<fnv<<" "<<fnu<<" "<<fv<<endl;
        if (fu == fv || fnu == fnv) {
            cout << sn[i].w;
            return 0;
        }
        father[fu] = fnv;
        father[fnu] = fv;
    }
    cout << 0;
    return 0;
}