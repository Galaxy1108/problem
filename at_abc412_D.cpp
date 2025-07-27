#include <bits/stdc++.h>
using namespace std;

long long g[9][9];
long long cyc[1 << 9];
long long dp[1 << 9];

vector<long long> perm;
vector<long long> verts;
vector<long long> rest;

long long main() {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    fill(cyc, cyc + (1 << n), -1);
    for (long long mask = 0; mask < (1 << n); mask++) {
        long long bin_cnt = __builtin_popcount(mask);
        if (bin_cnt < 3){
            continue;
        }
        verts.clear();
        for (long long i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                verts.push_back(i);
            }
        }
        long long verts_min = verts[0];
        for (long long v : verts) {
            if (v < verts_min){
                verts_min = v;
            }
        }
        rest.clear();
        for (long long v : verts) {
            if (v != verts_min){
                rest.push_back(v);
            }
        }
        sort(rest.begin(), rest.end());
        do{
            perm.clear();
            perm.push_back(verts_min);
            for (long long v : rest){
                perm.push_back(v);
            }
            long long com = 0;
            long long k = perm.size();
            for (long long i = 0; i < k; i++) {
                long long u = perm[i];
                long long v = perm[(i + 1) % k];
                if (g[u][v]){
                    com++;
                }
            }
            if (com > cyc[mask]){
                cyc[mask] = com;
            }
        } while (next_permutation(rest.begin(), rest.end()));
    }
    fill(dp, dp + (1 << n), LLONG_MIN);
    dp[0] = 0;
    for (long long i = 1; i < (1 << n); i++) {
        for (long long sub = i; sub > 0; sub = (sub - 1) & i) {
            if (cyc[sub] < 0){
                continue;
            }
            long long prev = i ^ sub;
            if (dp[prev] == LLONG_MIN){
                continue;
            }
            if (dp[prev] + cyc[sub] > dp[i]) {
                dp[i] = dp[prev] + cyc[sub];
            }
        }
    }
    cout << m + n - 2 * dp[(1 << n) - 1] << endl;
    return 0;
}