#include <bits/stdc++.h>
using namespace std;

bool is_st[2000000], vis[2000000];
int s, t;

long long anss[2000000];

long long dfs(int i) {
    if (i < 0) {
        return LLONG_MAX;
    }
    if (i == 0) {
        return 0;
    }
    if (vis[i]) {
        //  cout << i << " " << anss[i] << endl;
        return anss[i];
    }
    // cout << i < << anss[i] << '\n';
    int cnt = 0;
    if (is_st[i]) {
        cnt++;
    }
    long long misd = LLONG_MAX;
    for (int j = s; j <= t;j++) {
        misd = min(dfs(i - j), misd);
    }
    if (misd == LLONG_MAX) {
        anss[i] = LLONG_MAX;
        vis[i] = true;
        return anss[i];
    }
    cnt += misd;
    vis[i] = true;
    return anss[i] = cnt;
}

int main() {
    //   freopen("river.in", "r", stdin);
     ///  freopen("river.out", "w", stdout);
    int l;
    cin >> l;
    int m;
    cin >> s >> t >> m;
    int tmp;
    for (int i = 0; i < m;i++) {
        cin >> tmp;
        is_st[tmp] = true;
    }
    //  cout<<dfs(15);
    long long anss = LLONG_MAX;
    for (int i = l; i <= l - 1 + m;i++) {
        anss = min(dfs(i), anss);
    }
    cout << anss;
    return 0;
}
